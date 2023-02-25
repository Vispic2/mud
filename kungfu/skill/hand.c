// hand.c

inherit SKILL;

void skill_improved(object me)
{
    if (me->query_skill("hand",1)%30==0) {
	tell_object(me, HIW "由於你勤练武艺，你的"+HIY"【后天膂力】"+NOR+"提高了。"NOR"\n");
    }
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
