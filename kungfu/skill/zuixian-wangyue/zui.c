// jingsng.c 金刚拳 醉仙望月

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return BGRN"醉仙"ZJBR"望月"NOR; }
string *pfm_type() { return ({ "dodge", }); }

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if ((int)me->query_temp("zuixian"))
		return notify_fail("你已经在运功中了。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if ((int)me->query("neili") < 3000)
    return notify_fail("你的真气不够，无法施展「醉仙望月」！\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功修为不够，不能使用醉仙望月！\n");

	if ((int)me->query_skill("dodge") < 300)
		return notify_fail("你的轻功还不到家，无法使用醉仙望月！\n");

if ((int)me->query_skill("zuixian-wangyue") < 300)
		return notify_fail("你的醉仙望月还不到家，无法使用醉仙望月！\n");
	if (me->query_skill_mapped("dodge") != "zuixian-wangyue") 
		return notify_fail("你没有激发醉仙望月，无法使用醉仙望月！\n");

   
	msg = BGRN "$N" BGRN "使出醉仙望月的绝技「醉仙望月」，顿时你感觉自己的身体轻身如燕！"NOR"\n";
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int)me->query_skill("zuixian-wangyue", 1);	
	message_combatd(msg, me, target);	


    //增加四维，轻功激发，招架激发，防御力，攻击力，兵器伤害力，装备防护力。
	

	me->add_temp("apply/dex",skill*2);	
	me->add_temp("apply/dodge",skill*2);
	me->add_temp("apply/parry",skill*2);	
	me->add_temp("apply/armor",skill*2);
	
	me->set_temp("zuixian", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me,skill:),skill);
	me->add("neili", -3000);	
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("zuixian"))
	{	
	    me->add_temp("apply/dex",-amount*2);	
	    me->add_temp("apply/dodge",-amount*2);
	    me->add_temp("apply/parry",-amount*2);	
    	me->add_temp("apply/armor",-amount*2);     	
		me->delete_temp("zuixian");
		tell_object(me, "你的醉仙望月运行完毕，将内力收回丹田。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
