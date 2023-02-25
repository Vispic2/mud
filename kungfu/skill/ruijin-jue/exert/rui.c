// jingsng.c 金刚拳 锐金决

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return HIY"锐"ZJBR"金决"NOR; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if (! target){
		me->clean_up_enemy();
		target = me->select_opponent();
	}	
	if ((int)me->query("ruijin")  > 0)
    return notify_fail("你已经在运功中了。\n");
	if ((int)me->query("neili") < 1000)
    return notify_fail("你的真气不够，无法施展「锐金决」！(需要1000点)\n");
	if ((int)me->query_skill("force") < 180)
	return notify_fail("你的内功修为不够，不能使用锐金决！(需要180级)\n");
	if ((int)me->query_skill("ruijin-jue") < 180)
	return notify_fail("你的锐金决修为不够，不能使用锐金决！(需要180级)\n");
	if (me->query_skill_mapped("force") != "ruijin-jue") 
	return notify_fail("你没有激发锐金决，无法使用锐金决！\n");
   
	msg = BYEL "$N" BYEL "使出锐金决的绝技「锐金决」！"NOR"\n";
	skill = (int)(me->query_skill("ruijin-jue", 1)/2);	    
    message_combatd(msg, me, target);	
	me->start_call_out((: call_other, __FILE__, "remove_effect", me,skill:),skill);
    me->set_temp("gain/damage",skill/2);
    me->set_temp("ruijin");
	me->add("neili", -1000);	
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("ruijin"))
	{
	    me->set_temp("gain/damage",-amount/2);
		me->delete_temp("ruijin");
		tell_object(me, "你的锐金决运行完毕，将内力收回丹田。\n");
	}
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
