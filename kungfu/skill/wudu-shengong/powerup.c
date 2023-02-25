// powerup.c 化蛇大法

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "五毒"ZJBR"战气"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

       if( target != me ) return notify_fail("你只能用五毒神功提升自己的战斗力。\n");

	if( (int)me->query("neili") < 100 )	return notify_fail("你的内力不够。\n");
       if( (int)me->query_temp("powerup") ) return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("wudu-shengong",1)/3;

	me->add("force", -100);
 
	message_vision(
        BLU "$N运起五毒神功,头顶黑气蒸腾，全身肌肤坟起黑色的鳞甲，双目凶光四射！\n" NOR, me);

	me->add_temp("apply/armor", skill*3);
	me->add_temp("apply/unarmed", skill);
	me->add_temp("apply/attack", skill);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
       me->add_temp("apply/unarmed", -amount*2);
	me->add_temp("apply/attack",-amount*2);
       me->add_temp("apply/armor",-amount*6);
	me->delete_temp("powerup");
      tell_object(me, "你的五毒神功运行完毕，身体逐渐恢复正常。\n");}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
