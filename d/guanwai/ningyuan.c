#include <ansi.h>
inherit ROOM;
//免费进入副本次数
object me = this_player();
//	int a=me->query("zjvip/level")*10;
int cs = 2;
void create()
{
	set("short", "宁远");
	set("long", @LONG
这里是关外驻防的军事重镇。城高河宽，守备森严，城楼上不但有大量
的官兵驻防，甚至还有几门红衣火炮，架设其上。城门旁几名官兵正在检察
来往行人的物品，不时传来几声叱骂之声。
LONG );
	set("exits", ([
		"northeast" : __DIR__"road4",
		"south"     : __DIR__"road3",
	]));
		set("action_list", ([
		HIY"伏击金兵"NOR:"ask_job 1",
	]));	 
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	setup();
}

void init()
{
    add_action("ask_job","ask_job");
}

int ask_quest()
{
	object me = this_player();
	string str;
	mixed *local,*last;
	int times;
	int ok =0,i;
	object *ob_list,room;
	int k;
	
	if (userp(me)) {
		if (me->query("fuben/jinbing")) {
		ob_list = children("/adm/daemons/fuben_jinbing");
		for(i=0; i<sizeof(ob_list); i++)  {
		if (ob_list[i]->query("id") == me->query("id")) {
		if (room = find_object(ob_list[i]->query("enter")))
		if (me->move(room))
			tell_object(me, HIR"系统检测到你上次的副本还未结束\n"NOR);
			return 1;
			}
		}
	}
		local = localtime(time());
		if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
				ok = cs;
		}
		last = localtime(me->query("fuben/jinbing/times"));
		times = me->query("fuben/jinbing/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/jinbing/mun",0);
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "今日已经任务你已经完成"+(2+ok)+"次了，明天再来吧。"NOR"\n");
			return 1;
		}
		tell_object(me, str+"\n");
	}
	return 1;
}

int ask_job(string arg)
{
	object obj, me=this_player();
	object fb_room, *ob;
	int i, ok=0;
	int times;
	mixed *local,*last;
	string data;
// if(me->query("combat_exp")<5000000||me->query("combat_exp")>8000000){
// tell_object(me, "此副本属于中级副本，经验高于500万且小于800万，不能挑战了！"NOR"\n");
// return 1;
// }
	if (!arg || (arg !="1" && arg !="2" && arg !="3")) {
		ask_quest();
		return 1;
	}
	if (to_int(arg) < 1 || to_int(arg)>3) {
		tell_object(me, "你想干什么！"NOR"\n");
		return 1;
	}
	if (me->query_condition("killer")){
		tell_object(me, "你是杀人犯?！"NOR"\n");
		return 1;
	}
        if( me->query("eff_qi")<me->query("max_qi") )
               return notify_fail("你好像受伤了，不适合副本。\n");

        if( me->query("eff_jing")<me->query("max_jing") )
               return notify_fail("你好像受伤了，不适合副本。\n");
               	
	ob=deep_inventory(me);
	for (i=0;i<sizeof(ob);i++) {
		if (userp(ob[i])) {
			tell_object(me, "不支持组队！\n");
			return 1;
		}
	}

	me->delete_temp("ask_no");

	local = localtime(time());

	//免费提供一次进入机会
	if (to_int(local[4])+1 == 1 && local[3] >= 1 && local[3] <= 1) {
			ok = cs;
	}
		last = localtime(me->query("fuben/jinbing/times"));
		times = me->query("fuben/jinbing/mun");
		if(last[7]!=localtime(time())[7])
			me->set("fuben/jinbing/mun",0);
			/*
		else if(last[7]==localtime(time())[7]&&times>=2+ok && !wizardp(me))
		{
			tell_object(me, "今日已经任务你已经完成"+(2+ok)+"次了，明天再来吧。"NOR"\n");
			return 1;
	}*/
	data = (to_int(local[4])+1)+"-"+local[3];
	if (me->query("fuben/jinbing/mun") <= cs)
	{
		me->set("fuben/jinbing/times",time());
		me->add("fuben/jinbing/mun", 1);
		me->add("fuben/jinbing/"+data, 1);
		fb_room = new("/adm/daemons/fuben_jinbing");//改
		fb_room->init(me);
		fb_room->set("id", me->query("id"));
		tell_object(me, HIR"你正在进行伏击金兵副本"NOR"\n");
		//log_files("fubensss", sprintf("%s：%s(%s)进入了金兵副本。\n",ctime(time()),me->query("name"),me->query("id")));

	} else 
		tell_object(me, "你今天的任务次数已经没有了\n");
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
