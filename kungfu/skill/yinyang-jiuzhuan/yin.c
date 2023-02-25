// jingsng.c 金刚拳 阴阳九转

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return BBLU"阴阳"ZJBR"九转"NOR; }
string *pfm_type() { return ({ "parry", }); }

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	
	if (! target){
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	    if ((int)me->query_skill("force") < 500)
		return notify_fail("你的内功修为不够，不能使用阴阳九转！(需要500级)\n");
     	if ((int)me->query_skill("parry") < 500)
		return notify_fail("你的招架还不到家，无法使用阴阳九转！(需要500级)\n");
        if ((int)me->query_skill("yinyang-jiuzhuan") < 500)
		return notify_fail("你的阴阳九转还不到家，无法使用阴阳九转！(需要500级)\n");
	    if (me->query_skill_mapped("parry") != "yinyang-jiuzhuan") 
		return notify_fail("你没有激发阴阳九转，无法使用阴阳九转！\n");

   
	msg = BBLU "$N" BBLU "使出阴阳九转的绝技「阴阳九转」，顿时你感觉自己的身体轻身如燕！"NOR"\n";	
	skill = (int)me->query_skill("yinyang-jiuzhuan", 1);	
	

	
	me->add("neili",-skill*50);
	message_combatd(msg, me, target);	
	
	
	if(!me->query_temp("jiuzhuan")){
	me->set_temp("gain/break",skill/4);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me,skill:),skill);
	}
	me->set_temp("jiuzhuan", 1);		
	me->start_busy(10);	
	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("jiuzhuan"))
	{
	    
        me->set_temp("gain/break",-amount/4);
        
		me->delete_temp("jiuzhuan");
		tell_object(me, "你的阴阳九转运行完毕，将内力收回丹田。\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
