// jinsha.c

#include <ansi.h>
inherit COMBINED_ITEM;
string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIM "高级天赋书" NOR, ({ "tianfu jineng shu2" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "用来重置天赋技能的道具，可以获得两个天赋技能。\n");
		set("unit", "本");
		set("base_unit", "本");
		set("base_value", 500);
		set("yuanbao", 20);
//set("no_get",1);
        set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
		set("base_weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	if(me->query("combat_exp", 1) < 2) 
                return notify_fail("你没有实战基础，无法使用" + name() + "！\n");

	message_vision(CYN "$N" CYN "使用了一"+query("unit") + name() + CYN "，感觉获得了新生一般。"NOR"\n", me);
      me->set_temp("born_skill2",1);
	UPDATE_D->born_player(me);
	add_amount(-1);

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
