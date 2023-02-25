#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIY "圆月弯刀" NOR "」"
string query_name() { return HIR"圆月"ZJBR"弯刀"NOR; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap,jing, i,dp;
        int isGhost=1;
        string *colors = ({HBWHT,HBCYN,HBBLU,HBYEL,HBGRN,HBRED,HIW,HIG,HIY,WHT,HIM,RED,HIR,HIC});
	
        if (! target){
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
        return notify_fail(XIAN "只能对战斗中的对手使用。\n");
        
        if (! objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对，难以施展" XIAN "。(需要300级)\n");
        if ((int)me->query_skill("force") < 300)
        return notify_fail("你的内功火候不够，难以施展" XIAN "。(需要300级)\n");

        if ((int)me->query_skill("yuan-blade", 1) < 300)
        return notify_fail("你的圆月弯刀还不到家，难以施展" XIAN "。(需要300级)\n");

        if (me->query_skill_mapped("blade") != "yuan-blade")
        return notify_fail("你没有激发圆月弯刀，难以施展" XIAN "。\n");

        if ((int)me->query("neili") < 1000)
        return notify_fail("你的真气不够，难以施展" XIAN "。(需要1000点)\n");

        if (! living(target))
        return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
        
        msg = colors[random(14)] + "$N" +colors[random(14)] + "刀气横空，刀光烁闪，连环七刀，每刀均令$n" +colors[random(14)] + "不得不全神应付，\n" "每刀均是朴实古拙，偏又有，明月当空的感觉。\n"  "且刀刀均针对$n" +colors[random(14)] + "的身形变化，似是把$n" +colors[random(14)] + "看通看透一般！\n" NOR; 
        ap = ap = me->query_skill("force") + me->query_skill("blade") + me->query("dex") + me->query("str") + me->query("int") + me->query("con");
        dp = target->query_skill("dodge") + target->query_skill("force");
        
        jing = (int)target->query("max_jing")/1000;
	
        damage = me->query_skill("blade");
        damage *= 2;
        if (me->query("qi") <= me->query("max_qi")){
        if(1==random(5)){
        me->add("eff_qi",damage);
        me->add("qi",damage);        
        }
        }
        me->add("neili", -1000);
        msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 130,colors[random(14)] +"霎时一股冰寒的刀气掠过全身，$n" +colors[random(14)] + "全身顿时鲜血淋漓，摇摇欲倒！\n" NOR);    //   msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage,180,HIR "霎时一股冰寒的刀气掠过全身，$n" +colors[random(14)] +"全身顿时鲜血淋漓，摇摇欲倒！\n" NOR);

     for (i = 0; i < 7; i++)
	{
		if (! me->is_fighting(target))
			break;
		if (random(3) == 0 && ! target->is_busy())
			target->start_busy(1);
			
		target->receive_damage("jing", jing/5, me);
		target->receive_wound("jing", jing/5, me);
		
		COMBAT_D->do_attack(me, target, weapon, 0);
   	}
        me->start_busy(1);
        
        
        if (ap / 2 + random(ap * 2) > dp && ! target->is_busy())
        target->start_busy(ap / 100 + 10);
       
        message_combatd(msg, me, target);

        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
