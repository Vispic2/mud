// mizong-xinfa.c 密宗心法
// by secret

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
        return notify_fail("密宗心法只能通过学习(learn)来提高!\n");
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
