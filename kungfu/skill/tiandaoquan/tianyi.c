#include <ansi.h>
#include <combat.h>

string name() { return HIR "天意拳" NOR; }
string query_name() { return "天意拳"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int i, count;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(name() + "只能对战斗中的对手使用。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail(name() + "只能空手施展。\n");

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("你的武学修养还不到家，难以施展" + name() + "。\n");

        if (me->query_skill_mapped("unarmed") != "tiandaoquan")
                return notify_fail("你没有激发天道拳法，难以施展" + name() + "。\n");

        if (me->query_skill_prepared("unarmed") != "tiandaoquan")
                return notify_fail("你没有准备天道拳法，难以施展" + name() + "。\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的内功修为不够，难以施展" + name() + "。\n");

        if( me->query("max_neili")<100 )
                return notify_fail("你的内力修为不够，难以施展" + name() + "。\n");

        if( me->query("neili")<100 )
                return notify_fail("你现在的真气不足，难以施展" + name() + "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = WHT "$N" WHT "身形一展，施出天道拳绝技「" HIR "天意拳" NOR +
              WHT "」，十八道拳锋激起层层气浪，朝$n" WHT "狂劈而去。\n" NOR;

        message_combatd(msg, me, target);
	me->add("neili", -100);

	count = me->query_skill("unarmed") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 18; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, 0, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
