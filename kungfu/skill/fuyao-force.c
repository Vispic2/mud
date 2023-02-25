// freezing-force.c 少林 冰蚕寒功
// Feb.21 1998 by Java

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
	return force == "guixi-gong";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("fuyao-force", 1);
	return lvl * lvl * 15 * 18 / 100 / 200;
}

int valid_learn(object me)
{
    	if (me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，难以锻炼扶摇心经！\n");

	if (me->query_skill("jiuyang-shengong", 1))
			if (me->query_skill("force", 1) < me->query_skill("fuyao-force", 1))
		return notify_fail("你的基本内功水平不够，难以锻炼更深厚的扶摇心经！\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("扶摇心经无法通过简单的练习来增加熟练度。\n");
}

// hit effect called by combatd
mixed force_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	mixed result;
	int lvl;
	int flvl;

	result = ::force_hit_ob(me, victim, damage_bonus, factor);
	if (intp(result) && result > 0)
	{
		lvl  = me->query_skill("fuyao-force", 1);
		flvl = me->query("jiali");
		if (lvl < 80 || flvl < 100)
			return;

	    	if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
		    victim->affect_by("fuyao-poison",
				      ([ "level" : flvl * 1 / 2 + random(flvl / 2),
					 "id"    : me->query("id"),
					 "duration" : lvl / 40 + random(lvl / 50) ])))
		{
			return ([ "damage" : result,
				  "msg" : HIW "$n" HIW "扶摇寒毒入体，全身血液好似要凝固一样。"NOR"\n" ]);
	    }
	}

	return result;
}

string exert_function_file(string func)
{
	return __DIR__"fuyao-force/" + func;
}

int diffcult_level() { return 200; }
