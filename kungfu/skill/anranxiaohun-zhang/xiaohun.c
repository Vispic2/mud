// xiaohun.c 黯然消魂
// By Kayin @ CuteRabbit Studio 99-4-16 19:18 new
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
string query_name() { return "黯然"ZJBR"神伤"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("anranxiaohun-zhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「黯然消魂」只能在战斗中使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「黯然消魂」只能空手使用。\n");

	 if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");
    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("你要把玉女心法做为内功才能用。\n");

        if( (int)me->query_skill("anranxiaohun-zhang",1) < 300 )
                return notify_fail("你的黯然消魂掌火候不够，无法使用「黯然消魂」！\n");
	if( (int)me->query_skill("xuantie-sword",1) < 100 )
                return notify_fail("你的玄铁剑法火候不够，无法领悟「黯然消魂」！\n");
        if( (int)me->query_skill("force",1) < 200 )
                return notify_fail("你的内功修为不够，无法使用「黯然消魂」！\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/unarmed_damage",800);

        msg = HIM "$N心如止水，心中思念着$N的爱人，无意之中使出了"HIR"“黯然消魂”！\n" NOR;
        msg += HIM   "就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n" NOR;
	         message_vision(msg, me, target);
	 msg = HIC  "\n   黯 \n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n      然\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n        消\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n          魂\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n             掌\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra*2);
	 me->add_temp("apply/unarmed_damage",-800);

        if( me->query("shen") > 10000
        && target->query("shen") < 10000 )
{
msg = HIG "\n$N怒视$n,大唱一声，打出最后的一掌！就似傍晚的遥烟，顿时天地间产生一丝苦涩！\n"NOR;
	if( random(me->query("combat_exp")) > target->query("combat_exp")/4 )
	 {

                msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
		target->receive_damage("qi",(int)me->query_skill("anranxiaohun-zhang")*3);
		target->receive_wound("qi",(int)me->query_skill("anranxiaohun-zhang")*3);
// should not busy target if he already in busy (by xbd)
                if (!target->is_busy()) target->start_busy(3);
//             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		message_combatd(msg, me, target);
                COMBAT_D->report_status(target);
	} else {
		msg += HIY"可是$p急中生智，伏地翻滚而出，避过了这致命一击,躲了开去。\n" NOR;
		message_combatd(msg, me, target);
	}
}
        me->add("neili", -500);
        me->start_busy(3);

        return 1;
}

