// sangong.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "功散"ZJBR"八脉"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	if (me->query("max_neili") < 1)
		return notify_fail("你已经将内力散尽，没什么必要再散功了。\n");

	tell_object(target, HIY "你默默的按照吸星大法的诀窍将内力散入奇经八脉。"NOR"\n");
	message("vision", HIY + me->name() + "呼吸沉重，却又不像受伤的样"
			  "子，不知道在修炼什么厉害的功夫。"NOR"\n",
		environment(me), ({ me }));

	me->start_busy(1);
	me->add("max_neili", -1);

	return 1;
}

void del_sucked(object me)
{
	me->delete_temp("sucked");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
