// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) {return 1;}

string exert_function_file(string func)
{
	return "/kungfu/skill/force/" + func;
}

void skill_improved(object me)
{     
	int s;
	s = me->query_skill("force", 1);
    if (s%10==0) 
       {
		tell_object(me, HIW
"由於你的内功修炼有成，你的"+HIY"【后天根骨】"+NOR+"改善了。\n");
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
