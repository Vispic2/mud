// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
string *dodge_msg = ({
        "$n身影一晃，霎那间挪至$N的背后。\n",
        "$n微微向左一摆身，整个人飘出丈外。\n",
        "$n双手微微舞动，整个人象一片树叶般随着气流飘荡。\n",
        "$n双腿微踢，象一只轻捷的燕子飞了开。\n",
        "$n腰身一拱，整个人弹出丈外。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="dodge");
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
	if( (int)me->query("qi") < 30 )
		return notify_fail("你的体力太差了，不能练太虚幻步。\n");
	me->receive_damage("qi", 30);
	return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
        return __DIR__"ghosty-steps/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
