// trade.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	return notify_fail("讨价还价只能通过交易来提高。\n");
}

int practice_skill(object me)
{	
	return notify_fail("讨价还价只能通过交易来提高。\n");
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
