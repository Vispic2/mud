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
	set_name(HIG "天香玉露" NOR, ({"magic water", "yvlu", "lu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "滴");
		set("base_unit", "滴");
		set("long", HIG "这是附着在灵芝上的一滴晶莹剔透的玉露，传说采自"
				"灵山，千年来以灵芝为母，不断的吸取着日精月华，具有着无比神奇的功效(加最大内力，且内功等级180之前增加熟练度)。\n");
		set("yuanbao", 30);
		set("value", 100000);
		set("base_value", 100000);
		set("base_weight", 1);
		set("only_do_effect", 1);
		set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
	}
	setup();
}

int do_effect(object me)
{
	string force;

	message_vision(HIG "$N" HIG "小心翼翼的将玉露含在嘴中，登时觉得"
		       "灵台一阵空明，浑身上下飘飘欲仙，一时间竟有不在尘世的感觉。"NOR"\n", me);
	if (me->improve_neili(120 + random(50)))
		me->set("neili", me->query("max_neili"));

	force = me->query_skill_mapped("force");
	if (me->can_improve_skill("force")&&me->query_skill("force",1)<180)
		me->improve_skill("force", 400000);
	if (stringp(force) && me->can_improve_skill(force)&&me->query_skill(force,1)<180)
		me->improve_skill(force, 400000);
       add_amount(-1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
