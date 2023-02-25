
inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int practice_skill(object me)
{
	return notify_fail("酿酒之技只能通过读书来提高。\n");
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
