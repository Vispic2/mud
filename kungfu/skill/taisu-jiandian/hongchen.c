// hongchen .红尘十丈


string query_name() { return "红尘"ZJBR"十丈"; }
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
        int ap, dp; if (userp(me) && ! me->query("can_perform/taisu-jiandian/hongchen"))
                return notify_fail("你未受高人指点还不会使用这招\n");
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("「红尘十丈」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("没装备剑怎么使用「红尘十丈」？\n");

        if (me->query_skill_mapped("sword") != "taisu-jiandian")
                return notify_fail("你没有激发太素剑典，不能使用「红尘十丈」。\n");

        if (me->query_skill_mapped("force") != "taisu-jforce")
                return notify_fail("你没有激发太素心经，不能使用「红尘十丈」。\n");

        if ((int)me->query_skill("taisu-jiandian", 1) < 400)
                return notify_fail("你的太素剑典(400)不够娴熟，还使不出「红尘十丈」。\n");
if ((int)me->query_skill("martial-cognize") < 200)
                return notify_fail("你的武学修养境界不够，难以施展「红尘十丈」。\n");
        if ((int)me->query_skill("taisu-force") < 400)
                return notify_fail("你的太素心经火候不够，难以施展「红尘十丈」。\n");

        if ((int)me->query("neili") < 4500)
               return notify_fail("你现在真气不够，难以施展「红尘十丈」！"NOR"\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wname = weapon->name();
       ap = me->query("per") / 20;
       damage = ((int)me->query_skill("taisu-jiandian", 1) + (int)me->query_skill("sword", 1)) * 15;

        damage *= ap;
;

        // 第一招
        ap = me->query("per") + me->query("int");
        dp = target->query("per")+target->query("int");
         msg = HIW "$N" HIW "诵曰：" HBYEL"----------红尘 十丈---------- \n" NOR
	      HIW "$N" HIW "诵曰：" HBYEL"----却困众生芸芸哀拓之意----- \n" NOR
              HIW "$N" HIW "手中" + weapon->name() +"清吟" HIW "光芒大盛"HIW"，仿佛天地都被影响，\n" NOR
              HIW "无数哀从天地间$n" HIC" 围攻而去！\n" NOR;
        if (ap + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIW "$p" HIW "奋力抵挡，却哪里招架得住？被$P"
                                           HIW "这一剑劈下，登时鲜血迸流！"NOR"\n");
        } else
        {
                msg += HBWHT "$p" CYN "嘿的一声，硬声声将$P"
                       HBMAG "这一下，转移开来。"NOR"\n";
        }

        // 第二招
        ap = me->query("per")+me->query("int");
        dp = target->query("per")+target->query("int");
  
  	msg +=  HIW "$N" HIW "诵曰：" HBWHT"----------仁心虽小---------- \n\n" NOR;
       	msg +=	HIW "$N" HIW "诵曰：" HBWHT"----------也容我佛慈悲------ \n\n" NOR;
        msg +=  HIW "$N" HIW "顿时" + weapon->name() +"剑芒一转" HIY "光芒未暗，金芒又起"HIY"，犹如诸天古佛加持。\n\n" NOR;
	msg +=	HBWHT "神圣光芒吞没了$n ！.\n\n" NOR;
        if (ap  + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                          HIW "$p" HIW "困在佛光之中，寸步"
                                           "难行，身上多了数道伤口！"NOR"\n");
        } else
        {
                msg += HBWHT "$p" CYN "眉头一皱，浑然不将$P"
                HBWHT "玄妙的招数放在眼中，冷笑一声，竟没起到半点作用。"NOR"\n";
        }

        // 第三招
        ap = me->query_skill("sword") + me->query_skill("per") * 3;
        dp = target->query_skill("force") + target->query("per") * 3;
     
  	msg +=  HIW "$N" HIW "朱唇轻起：" HBRED"----------情之一字----------  \n\n" NOR;	
  	msg +=  HIW "$N" HIW "口诵而曰：" HBRED"---------如冰 上 燃火---------- \n\n" NOR;
        msg +=  HIW "$N" HIR "抛起" + weapon->name() +"金光一暗" HIR "火光跳跃"HIR"，侵蚀了天地。\n\n" NOR;
        msg +=  HIW "无数暴躁的火力疯狂涌向$n!\n\n" NOR;
        if (ap + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
                                           HIW "$p" HIW "只觉得一股悲凄凉意"
                                           "如体，转眼，黯然神伤。。明显是中了情伤！"NOR"\n");
        } else
        {
                msg += HIW "$p" HIW "一口冰凉的内气运起，$P"
                HBWHT "附体剑芒虽然厉害，却未能伤$p" HBWHT "分毫。"NOR"\n";
        }

        // 第四招
        ap = me->query_dex();
        dp = target->query_dex();
  	msg +=  HIW "$N" HIW "再吐真言：" HBRED"-------火烈则冰融------- \n\n" NOR;
       	msg +=	HIW "$N" HIW "又诵而曰：" HBCYN"-------冰融则火灭------- \n\n" NOR;
        msg +=  HIW "$N" HIW "手中" + weapon->name() +"突然" HIY "寒火相交"HIY"，冻结了天地\n\n" NOR;
	msg +=	  HIW "无数寒冰之力疯狂涌向$n .\n\n" NOR;
        if (ap + random(ap) + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 40,
                                           HIW "$p" HIW "只满一步，登时被$P"
                                           HIW "这一剑刺了个正中，鲜血四处飞射！"NOR"\n");
        } else
        {
                msg += HBMAG "$p" HBMAG "身法却是更快，只是一退，让$P"
                CYN "这一招堪勘不能奏效。"NOR"\n";
        }

        // 第五招
        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
       	msg +=	HIW "$N" HIW HBMAG "似诵似吟道.-------佛曰：不可说------- \n\n" NOR;
        msg +=  HIW "$N" HIW HBRED ".-顿时,数中异力凝结，天地一片安宁祥和.-\n\n" NOR;
        msg +=  HIW "$N" HIW HBCYN "--切起于动乱，最终归于平静。--\n\n" NOR;
        if (ap  + random(ap) > dp)
        {
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
                                           HIW "$p" HIW "只觉浑身如同在火中被泡了一样。身体之中"
                                           HIW "却是如同冰寒一样。无比难受！"NOR"\n");
        } else
        {
                msg += HIW "$p" HIW "冷静非凡，丝毫不为这奇幻的招数"
                       "所动，休目抵抗，幻象不攻自破！"NOR"\n";
        }

        me->start_busy(2);
        me->add("neili", -400 - random(100));
        message_combatd(msg, me, target);
        return 1;
}
