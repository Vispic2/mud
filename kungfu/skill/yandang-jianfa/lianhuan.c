#include <ansi.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "剑连环"; }
int perform(object me, object target)
{
        object weapon;
              int i,j,k,u,damage;
              weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");
        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对。\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("yandang-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if((int)me->query("max_neili") < 5000 )
                return notify_fail("你的内力太差。\n");

        if((int)me->query("neili") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("jing") < 1000 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("yandang-jianfa", 1) < 500)
        	    return notify_fail("你的雁荡剑法等级不够，不能使用这一招！\n");
	  k=(int)me->query_skill("sword");
         j=(int)target->query_skill("dodge");
        if(k<500)
                return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");
		u=1+k/50;
		if (u>10) u=10;

		message_vision(HIC"\n$N仰天大喝了一声：\n"NOR,me,target);
		message_vision(HIW"\n剑～～～～连～～～～环\n"NOR,me,target);
		message_vision(HIC"\n一刹那间千万剑光破空而来，劈面罩向$n\n"NOR,me,target);
		for (i=0;i<=u;i++)
		{
			COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR, HIC"\n一刹那间千万剑光破空而来，劈面罩向$n\n"NOR);
			if (random(k+j)>j)
			{
				message_vision(HIY"\n$n一个不慎，中了一剑\n"NOR,me,target);
				damage=k/2+random(k/2);
				target->receive_damage("qi",damage);
				target->receive_wound("qi",damage/3);
				COMBAT_D->report_status(target);
				me->add("neili", -300);
			}
			else
			{
				message_vision(HIY"\n$n左跳右闪，好不容易避开了一轮剑雨\n"NOR,me,target);
				me->add("neili", -100);
			}
		}
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
			}
		}
    me->start_busy(3);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
