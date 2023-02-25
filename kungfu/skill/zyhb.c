// zuoyou-hubo.c 左右互博
// by Doing Lu

inherit SKILL;

#include <ansi.h>

#define LEVEL_PER_LAYER	 30
#define MAX_LAYER	       12

string type() { return "special"; }

int valid_learn(object me)
{
	int layer;
	int lvl;

	lvl = me->query_skill("zuoyou-hubo", 1);
	
	
	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	

	return 1;
}
int valid_research(object me)
{
	return notify_fail("左右互博只能通过学习不断提高。\n");
}

int practice_skill(object me)
{
	return notify_fail("左右互博只能通过学习不断提高。\n");
}

