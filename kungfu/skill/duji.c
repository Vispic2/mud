// duji.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
//   if ( me->query("class") != "bonze" )
//      return notify_fail("你现在不能学习毒技。\n");
    return 1;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
