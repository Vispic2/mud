 // mimicat@fy4
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "棋盘切"; }
int perform(object me, object target)
{
        string msg,weapon_name;
        int extra, myexp, hisexp;
        object weapon,myweapon;
        if(me->is_busy())
                return notify_fail("你现在正忙！！\n");
        extra = me->query_skill("ittouryu",1) ;
        if ( extra < 100) return notify_fail("你的［一刀流剑术］还不够纯熟！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真气不够！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［棋盘切］只能对战斗中的对手使用。\n");

        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        myweapon = me->query_temp("weapon");
        weapon_name= myweapon->query("name");

        if(random(hisexp*5) < (extra*extra*extra/4+myexp+hisexp)/3  && weapon)
        {
        message_vision(
HIG "$N根本无视$n的攻击，大吼一声「棋盘切」！将"+weapon_name+"高举过肩，
自右上方直向$n劈来。
面对$N的雷霆一般的一击，$n用手中的兵器下意识地一挡。
"+ HIW"
$n只觉得虎口一热，手中的"+weapon->name()+"再也拿不住了，“当”地一声掉在地上。\n\n" NOR, me,target);
        if(weapon->unequip()) weapon->move(environment(target));
        me->start_busy(1);
        }
        else if(random(hisexp*3) < (extra*extra*extra/4+myexp+hisexp)/3  && weapon)
        {
        msg = HIG "$N根本无视$n的攻击，大吼一声「棋盘切」！将"+weapon_name+"高举过肩，
自右上方直向$n劈来。
面对$N的雷霆一般的一击，$n用手中的兵器下意识地一挡。"+
HIC"\n只听得“当”地一声大响，两人手中的兵器一震，各自后退了一步。\n\n"+ NOR;
        message_vision(msg,me,target);
        me->start_busy(2);
        target->start_busy(2);
        }
        else
        {
        msg = HIG "$N根本无视$n的攻击，大吼一声「棋盘切」！将$w高举过肩，
自右上方直向$n劈来。"NOR;
        	if (extra >= 300) extra=300;
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra*2);
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra*2);
        me->start_busy(2);
        me->add("neili",-300);
        }
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
