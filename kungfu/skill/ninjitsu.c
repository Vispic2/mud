// literate.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
        return notify_fail("忍术只能用学的。\n");
} 

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
