// fonxanforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("棋道只能用学的，或是从运用(exert)中增加熟练度。\n");
}

 
int effective_level() { return 12;}

int learn_bonus()
{
	return -50;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 30;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
