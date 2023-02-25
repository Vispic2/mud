// qingfu-shenfa.c 青蝠身法
// pal 1997.05.26

inherit SKILL;

string *dodge_msg = ({
	"只见$n一招「福满乾坤」，身形陡然纵起，躲过了$N这一招。\n",
	"$n一式「五蝠献寿」，身形晃动，向一旁飘出，避开了$N这一招。。\n"
	"$n使出「洞天福地」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。\n",
	"$n一招「云龙百蝠」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 )
		return notify_fail("你的体力太低了，不能练青蝠身法。\n");

	if( (int)me->query("neili") < 40 )
		return notify_fail("你的内力不够练青蝠身法。\n");

	me->receive_damage("qi", 40);
	me->add("neili", -15);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
