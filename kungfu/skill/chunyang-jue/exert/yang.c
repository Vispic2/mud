// jingsng.c 金刚拳 纯阳决

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return HIY"纯"ZJBR"阳决"NOR; }
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
	if ((int)me->query_condition("chunyang_jue")  > 0)
    return notify_fail("你已经在运功中了。\n");
	if ((int)me->query("neili") < 1000)
    return notify_fail("你的真气不够，无法施展「纯阳决」！(需要1000点)\n");
	if ((int)me->query_skill("force") < 180)
	return notify_fail("你的内功修为不够，不能使用纯阳决！(需要180级)\n");
	if ((int)me->query_skill("chunyang-jue") < 180)
	return notify_fail("你的纯阳决修为不够，不能使用纯阳决！(需要180级)\n");
	if (me->query_skill_mapped("force") != "chunyang-jue") 
	return notify_fail("你没有激发纯阳决，无法使用纯阳决！\n");
   
	msg = BYEL "$N" BYEL "使出纯阳决的绝技「纯阳决」！"NOR"\n";
	skill = (int)(me->query_skill("chunyang-jue", 1)/2);	
    me->apply_condition("chunyang_jue",100+skill);
    message_combatd(msg, me, target);	
	me->add("neili", -1000);	
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
