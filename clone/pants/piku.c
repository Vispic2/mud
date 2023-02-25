// piku.c

#include <ansi.h>
#include <armor.h>

inherit PANTS;

string do_wear();

void create()
{
	set_name(RED "皮裤" NOR, ({ "piku"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("icon", "05078"); 
		set("material", "pants");
		set("armor_prop/armor", 15);
		set("armor_prop/warm", 15);
		set("value", 8000);
		set("wear_msg", (: do_wear :));
	}
	setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "女性")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "穿在身上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "抖了抖，穿在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "穿在身上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在身上。\n";
	} 
	else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "穿在身上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "抖了抖，穿在身上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "穿在身上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "穿在身上，甚是猥琐。\n";
	}
	return msg;
}

int query_autoload()
{
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
