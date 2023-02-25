// beimin-shengong.c 天罡诀
// by doing

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }


int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("tiangang-jue", 1);
	return lvl * lvl * 15 * 30 / 100 / 200;
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("tiangang-jue", 1);

	if (me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的天罡诀。\n");



	return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int jiali;

	if ((int) me->query_skill("tiangang-jue", 1) < 70 ||
	    ! living(me))
		return;

	if ((jiali = ob->query("jiali")) < 1)
		return;

	ap = ob->query_skill("force");
	dp = me->query_skill("force");
	if (ap / 2 + random(ap) < dp)
	{
		if (me->query("neili") < me->query("max_neili") * 2)
			me->add("neili", jiali);

		result = ([ "damage" : -damage ]);

		switch (random(4))
		{
		case 0:
			result += ([ "msg" : HIM "$N" HIM "只觉得内力源源而泄"
					     "，不由得大吃一惊。"NOR"\n" ]);
			break;
		case 1:
			result += ([ "msg" : HIM "$N" HIM "只觉得发出的内力犹"
					     "如石沉大海，不知所踪。"NOR"\n" ]);
			break;
		case 2:
			result += ([ "msg" : HIM "$N" HIM "只觉得发出的内力犹"
					     "无影无踪，浑然不知着落。"NOR"\n" ]);
			break;
		default:
			result += ([ "msg" : HIM "$N" HIM "不住催动内力，但是"
					     "只觉得$n" HIM "竟似毫不费力。"NOR"\n" ]);
			break;
		}
		return result;
	}
}

int practice_skill(object me)
{
    return notify_fail("天罡诀只能通过学习，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
    return __DIR__"tiangang-jue/" + func;
}
