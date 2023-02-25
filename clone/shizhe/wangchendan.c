// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "忘尘丹" NOR, ({ "wangchen dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIR"清除角色除"HIY"元宝"NOR"和"HIW"会员相关"NOR"的所有数据（谨慎使用）！\n"NOR);
		set("unit", "颗");
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		//set("no_get",1);
		set("value", 500000);
		set("yuanbao", 1200);
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision(CYN "$N" CYN "小心的服下了" + name() + CYN "，所有数据清空。"NOR"\n", me);
	UPDATE_D->init_player(me);
	destruct(this_object());
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
