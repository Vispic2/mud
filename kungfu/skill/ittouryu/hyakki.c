 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "百鬼"ZJBR"夜狂"; }
int perform(object me, object target)
{
        string msg;
        int extra,adjust;
        int count;
        object weapon,targetweapon;
        extra = me->query_skill("ittouryu",1);

        if ( extra < 150) return notify_fail("你的［一刀流剑术］还不够纯熟！\n");
        	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真气不够！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［百鬼夜狂］只能对战斗中的对手使用。\n");
//      if(me->query_temp("timer/hyakki")+60>time())
//              return notify_fail("你的杀气已尽，无法在短时间内再出这一招。\n");
        msg = HIR  "\n\n$N突然仰天长嚎，头发如钢针般根根直竖，$n依稀看到$N的瞳仁正在变成红色。
$N猛地扑向$n，发动了一刀流的最强一招-「百鬼夜狂」，将$n笼罩在一片刀光中。
" NOR;
        count=0;

        adjust = 440-me->query_skill("blade")>0?0:440-me->query_skill("blade");
//      message_vision("adjust is "+(string)adjust+"\n",me);
//      me->set_temp("timer/hyakki",time());
if (adjust>300) adjust=300;
if (extra>300) extra=300;
        me->add_temp("apply/attack",adjust);
        me->add_temp("apply/damage",extra);
if (random(3)==0) target->start_busy(3);
        msg += HIC  "百鬼袭！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg = HIG  "百鬼冲！！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg = HIB  "百鬼碎！！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg = HIY  "百鬼突！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg = HIM  "百鬼坠！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg = HIW  "百鬼斩！！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg = HIR  "灭！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if(random(2)==0) count++;
        msg="\n\n";
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-adjust);
        if(!count)
                msg+=HIB"$n好整以暇地闪过$N所有的攻击，冷冷地说：
“该轮到我了！”。\n"NOR;
        else if(count<4)
                msg+=HIY"突然，一蓬鲜血激射，随之$n破出刀光，捂着殷红的衣襟，
退向一侧。\n"NOR;
        else if(count<7)
                msg+=HIM"突然，一蓬鲜血激射，随之$n破出刀光，捂着殷红的衣襟，
口中撕吼着：“魑魅魍魉...”,
$N接道：“百鬼夜狂”。\n"NOR;
        else
                msg+=HIR"突然，一蓬鲜血激射，随之$N破出刀光，背对着血泊中的$n
傲慢地说道：“笑止千万！”\n"NOR;
        message_vision(msg,me,target);
        me->add("neili",-500);
        if (count>3) target->start_busy(3);
                else target->start_busy(count);
        if (count>5) me->start_busy(3);
                else me->start_busy(5);

        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
