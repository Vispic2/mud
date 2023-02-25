// jingsng.c 金刚拳 天罡霸体

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return HIY"天罡"ZJBR"霸体"NOR; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if ((int)me->query_temp("bati"))
		return notify_fail("你已经在运功中了。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if ((int)me->query("neili") < 3600)
    return notify_fail("你的真气不够，无法施展「天罡霸体」！(需要3600点)\n");

	if ((int)me->query_skill("force") < 360)
		return notify_fail("你的内功修为不够，不能使用天罡霸体！(需要360级)\n");

	if ((int)me->query_skill("tiangang-bati") < 360)
		return notify_fail("你的天罡霸体修为不够，不能使用天罡霸体！(需要360级)\n");
	if (me->query_skill_mapped("force") != "tiangang-bati") 
		return notify_fail("你没有激发天罡霸体，无法使用天罡霸体！\n");

   
	msg = BYEL "$N" BYEL "使出天罡霸体的绝技「天罡地煞」，顿时战气击起方圆百米的石粒，威不可挡！"NOR"\n";
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int)(me->query_skill("tiangang-bati", 1)/4);	
	message_combatd(msg, me, target);	


    //增加四维，轻功激发，招架激发，防御力，攻击力，兵器伤害力，装备防护力。
	me->add_temp("apply/str",skill);	
	me->add_temp("apply/dex",skill);	
	me->add_temp("apply/int",skill);	
	me->add_temp("apply/con",skill);	
	me->add_temp("apply/dodge",skill);
	me->add_temp("apply/parry",skill);
	
	me->add_temp("apply/armor",skill);
	me->add_temp("apply/attack",skill);	
	
    me->add_temp("apply/unarmed_damage", skill);
    me->add_temp("apply/damage",skill);
	me->set_temp("bati", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me,skill:),skill);
	me->add("neili", -3600);	
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("bati"))
	{
	    me->add_temp("apply/str",-amount);	
	    me->add_temp("apply/dex",-amount);	
	    me->add_temp("apply/int",-amount);	
	    me->add_temp("apply/con",-amount);	
        me->add_temp("apply/dodge",-amount);
	    me->add_temp("apply/parry",-amount);
	
    	me->add_temp("apply/armor",-amount);
     	me->add_temp("apply/attack",-amount);	
	
        me->add_temp("apply/unarmed_damage",-amount);
        me->add_temp("apply/damage",-amount);	
        
		me->delete_temp("bati");
		tell_object(me, "你的天罡霸体运行完毕，将内力收回丹田。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
