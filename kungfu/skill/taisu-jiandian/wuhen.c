#include <ansi.h>
#include <combat.h>





inherit F_SSERVER;
string query_name() { return "太素"ZJBR"无痕"; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp,cp;
        int damage;
 if (userp(me) && ! me->query("can_perform/taisu-jiandian/wuhen"))
                return notify_fail("你未受高人指点还不会使用这招\n");
        
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("太素无痕只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展太素无痕。\n");
if ((int)me->query_skill("martial-cognize") < 150)
                return notify_fail("你的武学修养境界不够，难以施展「太素无痕」。\n");
        if (me->query_skill("taisu-force") < 300)
                return notify_fail("你的太素心经修为不够，难以施展太素无痕。\n");

        if (me->query_skill("taisu-jiandian", 1) < 300)
                return notify_fail("你的太素剑典修为不够，难以施展太素无痕。\n");

        if (me->query("neili") < 3000)
                return notify_fail("你的真气不够，难以施展太素无痕。\n");

        if (me->query_skill_mapped("sword") != "taisu-jiandian")
                return notify_fail("你没有激发太素剑典，难以施展此招。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	                 

        msg = HIY "$N" HIW "停下手中一切动作，右手捏诀，手中" + weapon->name() +
              HIY "佛光大盛。飞身而起，从各方向劈向$n" HIW "！\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("per") * 3;
        dp = target->query_skill("force") + target->query("per") * 3;
	cp = me->query_skill("taisu-jiandian");
        if (ap + cp / 2 > dp + cp / 3)
        {
                damage = ap * 3 + cp * 3 + random(cp * 10);
                me->add("neili", -200);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 1000,
                                            BLK HBWHT "$n" BLK HBWHT "只感不妙，身前竟出现了七八个$N的幻影,$n" BLK HBWHT"一时抵挡不住身中七八剑，顿时气息紊乱血流不止！\n" NOR);

        } else
        {
                me->add("neili", -200);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "并不慌乱，收敛心神，轻轻格挡开了$P"
                       CYN "的剑招。\n"NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}
