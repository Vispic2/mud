// panying.c 盘鹰诀

#include <ansi.h>
#include <combat.h>

string name() { return YEL "盘鹰诀" NOR; }
string query_name() { return "盘鹰诀"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能在战斗中对对手使用。\n");

	//if (userp(me) && ! me->query("can_perform/ruanhong-zhusuo/panying"))
		//return notify_fail("你还不会使用这一招！\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
              weapon->query("skill_type") != "whip" )
                return notify_fail("你使用的武器不对，无法施展" + name() + "。\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 80)
                return notify_fail("你的软红蛛索不够娴熟，无法施展" + name() + "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if( me->query("neili")<100 )
                return notify_fail("你的内力不够，无法施展" + name() + "。\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("你没有激发软红蛛索，无法施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = YEL "$N" YEL "使出软红蛛索「盘鹰」诀，手腕轻轻一抖，顿时鞭"
              "影重重，完全笼罩$n" YEL "四周！\n";

        me->start_busy(1);

        ap = me->query_skill("whip");
        dp = target->query_skill("dodge");
        if( ap / 2 + random(ap) > dp )
        {
                msg += HIR "$n" HIR "微作诧异，一时勘破不透$N" HIR "招中"
                       "奥妙，顿被攻了个措手不及！\n" NOR;
                target->start_busy(ap / 90 + 2);
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P"
                       CYN "的企图，小心应对，并没有上当。\n" NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
