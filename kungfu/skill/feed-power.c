// feed-power.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
}

int valid_learn(object me)
{
	if (me->query_skill("feed-power", 1) < 500)
		return 1;

	return 0;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
