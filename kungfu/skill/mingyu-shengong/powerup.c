// powerup.c 

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "冥雨"ZJBR"战气"; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if ( !wizardp(this_player()) && (me->query("family/family_name") != "移花宫"))
		return notify_fail("你不是移花宫弟子不能使用冥雨神功.\n
		 		    冥雨神功博大精深, 非移花宫弟子不传, 真不知道你是怎么学会的!\n
				    要是让两位宫主知道了你可惨了.\n");
	if( target != me ) 
		return notify_fail("你只能用冥雨神功来提升自己的战斗力。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") ) 
                 return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(
	HIM "$N微一凝神，运起冥雨神功，身边无数烟雾围绕, 将全身潜能尽数提起。ⅵ\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
     me->set_temp("zjb_yihua", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
   if ( (int)me->query_temp("powerup") ) {
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
      me->delete_temp("zjb_yihua");
	tell_object(me, "你的冥雨神功运行完毕，将内力收回丹田。\n");}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
