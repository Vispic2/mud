
#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n身形左闪右晃，姿势潇洒之极，一招[轻灵幻香]轻巧地躲开$N的进攻。"
]),
([      "action" : "$n宛如一屡青烟，飘忽不定，令人琢磨不定，一招[无魔无形]闪到了$N的身后。"
]),
([      "action" : "$n姿态幽雅之极，躲闪之中丝毫不显狼狈之态，一招[凌波涟涟]避开了$N的攻击。!"
]),
([      "action" : "$n身形突然连晃数下，宛如云雾中的幻灵，一招[雾里藏花]躲开了$N的攻击。"
])

});
int valid_enable(string usage)
{
        return usage=="dodge";
}
mapping query_action(object me)
{


	return action[random(sizeof(action))];
}


int valid_learn(object me)
{

	   return 1;
}



int practice_skill(object me)
{


	return 1;
}

string query_type()
{
	return "dodge";
}
string query_base()
{
	return "dodge";
}

int query_dodge(object me)
{
	return 100;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
