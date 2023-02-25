// box.c 功德箱

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"八"+HIG"卦"+HIR+"炉"NOR, ({ "bagua lu" }) );
	set_weight(99999999);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", HIC"---这是太上老君的炼丹炉，可以练出极品丹药---"ZJBR""ZJBR""ZJBR""+ZJSIZE(22)+ZJURL("cmds:wanfa")+HIG"查看玩法"+NOR+"        "+ZJSIZE(22)+ZJURL("cmds:peifang")+HIM+"查看配方"+NOR+"        "+ZJSIZE(22)+ZJURL("cmds:liandan")+HIR"开始炼丹\n"NOR);
		set("value", 99999999);
		set("no_get",1);
		set("no_drop",1);
		set("no_give",1);
	}
	setup();
}


void init()
{
    add_action("do_wanfa", "wanfa");
    add_action("do_peifang", "peifang");
	add_action("do_liandan", "liandan");
}
int do_wanfa(string arg)
{
	object me,ob;
    
	write(HIR"暂未开放炼丹系统，敬请期待！\n"NOR);

	return 1;
}
int do_peifang(string arg)
{
	object me,ob;
    
	write(HIR"暂未开放炼丹系统，敬请期待！\n"NOR);

	return 1;
}
int do_liandan(string arg)
{
	object me,ob;
    
	write(HIR"暂未开放炼丹系统，敬请期待！\n"NOR);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
