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
	int a,b,c,d,s;
a=me->query("zhuanshi");
b=me->query("htsss");
c=me->query("djsss");
d=me->query("rxsss");
s=24+a+b+c+d;
	lvl = me->query_skill("zuoyou-hubo", 1);
	if (me->query("combat_exp") < 3000000)
 notify_fail("三百万经验且先天悟性低于等于24可学！\n");

	if (lvl >= MAX_LAYER * LEVEL_PER_LAYER)
		return notify_fail("你的左右互博之术已经修炼"
				   "的炉火纯青，再难进步了。\n");

	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;

if (me->query("int") >= s )
		return notify_fail("你觉得心烦意乱，难以尝试更高深的分心之术。【先天悟性大于等于24】\n");

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

void skill_improved(object me)
{
	int lvl;
	int layer;

	lvl = me->query_skill("zuoyou-hubo", 1);
	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	if (! layer)
	{
		tell_object(me, HIM "你潜心领悟左右互"
				"博，若有所悟。"NOR"\n");
	} else
	if ((lvl % LEVEL_PER_LAYER) == 0)
	{
		tell_object(me, HIM "你领悟了第" + chinese_number(layer) +
			    "层境界的左右互博的奥妙。"NOR"\n");
	} else
		tell_object(me, HIM "你对第" + chinese_number(layer) +
			    "层境界的左右互博又加深了一点了解。"NOR"\n");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
