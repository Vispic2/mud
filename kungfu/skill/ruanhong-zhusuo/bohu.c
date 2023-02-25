// bohu.c 搏虎诀

#include <ansi.h>
#include <combat.h>

string name() { return HIY "搏虎诀" NOR; }
string query_name() { return "搏虎诀"; }
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

	//if (userp(me) && ! me->query("can_perform/ruanhong-zhusuo/bohu"))
		//return notify_fail("你还不会使用这一招！\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
              weapon->query("skill_type") != "whip" )
                return notify_fail("你使用的武器不对，无法施展" + name() + "。\n");

        if ((int)me->query_skill("ruanhong-zhusuo", 1) < 150)
                return notify_fail("你的软红蛛索不够娴熟，无法施展" + name() + "。\n");

        if( me->query("neili")<300 )
                return notify_fail("你的内力不够，无法施展" + name() + "。\n");

        if (me->query_skill_mapped("whip") != "ruanhong-zhusuo")
                return notify_fail("你没有激发软红蛛索，无法施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "一声暴喝，使出「搏虎」诀，手中" + weapon->name() +
              HIY "狂舞，漫天鞭影幻作无数小圈，铺天盖地罩向$n" + HIY "！\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("parry") + target->query_skill("force");

        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("whip");
                me->add("neili", -300);
                me->start_busy(2);
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 45,
                                           HIR "只听$n" HIR "一声惨叫，" + weapon->name() + HIR
                                           "已在$p" + HIR "身上划出数道深可见骨的伤口，皮肉"
                                           "分离，鲜血飞溅，苦不堪言！\n" NOR);
        } else
        {
                me->add("neili", -100);
                me->start_busy(3);
                msg += CYN "可是$p" CYN "运足内力，奋力挡住了"
                       CYN "$P" CYN "这神鬼莫测的一击！\n"NOR;
        }
        message_combatd(msg, me, target);

        return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
