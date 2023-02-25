//Room: /d/foshan/huiguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
int sos(int,int);
void fresh(object ob);
void create()
{
	set("short","英雄会馆");
	set("long",@LONG
英雄会馆也是凤老爷的家业。来这里赌钱的，都是有能耐有来
头的。赌场里围着黑压压的一群人，正在掷(gamble)骰子押大小。
门边立着一个牌子(paizi)。
LONG);
	set("objects", ([
	   __DIR__"npc/fengyiming": 1,
	]));
	set("no_fight", "1");
	set("item_desc", ([
		"【牌子】" :
"「大小」赌法：\n"
"共用三粒色子撒在一只碗里，色子点数总和：\n"
"       四 至 十 为「小」，\n"
"       十一 至 十七 为「大」，\n"
"       三粒色子点数相同，则大小通吃。\n"
"\n开大赔大，开小赔小，一赔一。\n"
"\n本赌场接受各种货币赌注。\n"
"\n赌注为五十到五百。\n",
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"street2",
	]));
	setup();
}
void init()
{
	add_action("do_gamble", "gamble");
}

int do_gamble(string arg)
{
	int a,b,c;
	int wager, skill, lpoint, tpoint;
	string wtype1, wtype2, wtype0, status;
	object mtype, me;
	mapping lrn;

	int min, max;
	min = 50;
	max = 500;

	me = this_player();

	if (me->query_temp("casino/mark"))
		return notify_fail("你这么着急啊? 还是再多休息一会儿吧 -:)\n");

    	if (! arg || sscanf(arg, "%s %s %s %d", wtype0, wtype1, wtype2, wager) !=4)
		return notify_fail("gamble big|small money\n"
"eg. gamble big money silver 3");

	if (wtype1 == "money")
	{
		mtype = present(wtype2 + "_money", me);
		if( !mtype)	  return notify_fail("你身上没有这种货币。\n");
		if( wager < 1 )	return notify_fail("你要压多少啊?\n");
		if( (int)mtype->query_amount() < wager)
			return notify_fail("你身上没有那么多" + mtype->query("name") + "。\n");
		if( wager*(mtype->query("base_value")) < min ||
		    wager*(mtype->query("base_value")) > max )
			return notify_fail("你的赌注不在限额之内!\n"
			"这里的限额是" + chinese_number(min) + "至" + chinese_number(max) + "。\n");
	}
	else    return notify_fail("本赌场不接受这种赌注。\n");

	if ((wtype0 != "big") && (wtype0 != "small"))
		return notify_fail("你要赌大还是赌小?\n");

	me->set_temp("gamb_t",(me->query_temp("gamb_t") +1));
	if (me->query_temp("gamb_t") > 50)
	{
		call_out("fresh", 300, me);
		me->set_temp("casino/mark", 1);
		return notify_fail(
"这位" + RANK_D->query_respect(me) + "，你已经赌了很久了，还是先休息一会儿吧。\n");
	}

	a = random(6) + 1;
	b = random(6) + 1;
	c = random(6) + 1;

	message_vision("开：" + a + "   " + b + "   " + c + "   ，", me);

	if ((a == b) && (b == c) )
		message_vision("大小通杀。\n", me);
	else if ( (a+b+c) > 10 )
		message_vision("吃小赔大。\n",me);
	else if ( (a+b+c) < 11 )
		message_vision("吃大赔小。\n",me);

	if (((a == b) && (b == c)) ||
	    ((a+b+c) > 10 && (wtype0 == "small")) ||
	    ((a+b+c) < 11 && (wtype0 == "big")))
		status = "lose";

	if (wtype1 == "money")
	{
		if ( status == "lose") {
	message_vision(me->query("name") + "输了" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "。\n", me);
			mtype->set_amount((int)mtype->query_amount() - wager);
			mtype->move(me);
		}
		else {
	message_vision(me->query("name") + "赢了" + chinese_number(wager) +
mtype->query("base_unit") + mtype->query("name") + "。\n", me);
			mtype->set_amount((int)mtype->query_amount() + wager);
			mtype->move(me);
		}
	}
	return 1;
}

void fresh(object ob)
{
	if (objectp(ob))
	{
		ob->delete_temp("gamb_t");
		ob->delete_temp("casino/mark");
	}
}

int sos(int lower, int upper)
{
	int x,y;
	x = 0;

	while (lower <= upper)
	{
		y = lower*lower;
		x += y;
		lower++;
	}
	return x;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
