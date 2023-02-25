// liandan_fang.c

#include <ansi.h>

inherit ROOM;

#define DAN_DIR	 "/d/beijing/npc/dan/"

int do_liandan(string arg);

void create()
{
	set("short", "炼丹房");
	set("long", @LONG
这是姚春的炼丹房，四周堆放着炼丹的药材，一个漆黑的炼丹炉(lu)耸立
在中央，房中的药味经久不散，并且总有一股散不尽的淡青色烟雾，长时间的
丹药炼制已经让这个房间充满了神秘的色彩。
LONG );
	//set("no_fight", 1);
	set("item_desc", ([
		"【丹炉】" : "一个深黑色的大铁丹炉，顶部不停地升起丝丝青烟。\n"
		ZJOBACTS2"炼丹:liandan\n",
	]));


	set("exits", ([
		"south" : __DIR__"liandan_yaoshi",
	]));

	setup();
}

void init()
{
	add_action("do_liandan", "liandan"); 
}

int do_liandan(string arg)
{
	int time;

	object me = this_player();
	time = 10 + random(10);

	if (me->is_busy())
		return notify_fail("等你有空了再说吧。\n");

	if ((int)me->query_temp("liandan") < 1)
		return notify_fail("炼丹之地，切勿滋扰。\n");

	if ((int)me->query_temp("liandan") < 2)
		return notify_fail("原料都没有，炼什么啊？\n");

	if ((int)me->query_temp("liandan") == 3)
		return notify_fail("丹药炼制中，请勿分心。\n");

	if ((int)me->query_temp("liandan") == 4)
		return notify_fail("炼制成功，快去复命吧。\n");

	if ((int)me->query("jing") < 80 ||
	    (int)me->query("qi") < 80)
		return notify_fail("你已经筋疲力尽了。\n");

	message_vision(HIY "$N" HIY "将原料药材一一放进炉中，盘腿坐下，闭目静待。"NOR"\n", me); 
	me->set_temp("liandan", 3);
	me->start_call_out((: call_other, __FILE__, "liandan", me :), time*2);
	me->start_busy(time);
	return 1;
}

// 特殊丹列表
//string *SM_LIST = ({ "danS_2", "danS_3", "danS_4", "danS_5",});
string *SM_LIST = ({ 
"/d/beijing/npc/dan/danS_2",
"/d/beijing/npc/dan/danS_3",
"/d/beijing/npc/dan/danS_4",
"/d/beijing/npc/dan/danS_5",
"/clone/vip/zyao1",
"/clone/vip/zyao2",
"/clone/vip/dan_chongmai2",
"/clone/vip/dan_chongmai3",
"/clone/vip/dan_chongmai4",
});

// 普通丹列表
string *NORMAL_LIST = ({ "danC_4", "danD_2", "danD_3", "danD_4", });

void liandan(object me)
{
	object ob;
	int a;

	if (environment(me) != this_object())
		return;

	me->receive_damage("jing", 50 + random(30));
	me->receive_damage("qi", 50 + random(30));
	if (random(3) == 1) 
	{
		me->set_temp("liandan", 1);
		message_vision(HIR "正当$N" HIR "昏昏然的时候，一阵刺鼻"
			       "的气味从炉中冲出，$N" HIR "急忙开炉取药，"
			       "结果被弄得个灰头土脸。"NOR"\n",me);
            tell_object(me,ZJFORCECMD("s")+ZJFORCECMD("s")+ZJFORCECMD("ask xiao tong about 采药"));
	} else
	if (random(100) == 1)
	{
		message_vision(HIY "炉顶青烟渐渐转淡，蓦然一道金光闪过，$N"
			       HIY "不禁吃了一惊，此时丹药气味渐浓，$N"
			       HIY "赶紧把炼制而成的丹丸取出。"NOR"\n", me);
		me->set_temp("liandan", 4);
		//老代码 ob = new(DAN_DIR + SM_LIST[random(sizeof(SM_LIST))]);
            //报错 ob = new(random(sizeof(SM_LIST)));
            ob = new(SM_LIST[random(sizeof(SM_LIST))]);
		tell_object(me, CYN "你炼成了珍品" + CYN + ob->name() + "。"NOR"\n");
		ob->move(me, 1);
            tell_object(me,ZJFORCECMD("s")+ZJFORCECMD("ask yao chun about 炼丹"));
	} else
	{
		message_vision(HIC "炉顶青烟渐渐转淡，丹药气味渐浓，$N"
			       HIC "高兴地把炼制而成的丹丸取出。"NOR"\n", me);
		me->set_temp("liandan", 4);
		ob = new(DAN_DIR + NORMAL_LIST[random(sizeof(NORMAL_LIST))]);
		tell_object(me, CYN "你炼成了" + CYN + ob->name() + "。"NOR"\n");
		ob->move(me, 1);
            me->force_me("s");
            me->force_me("ask yao chun about 炼丹");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
