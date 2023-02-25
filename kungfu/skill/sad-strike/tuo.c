// tuo.c
// 杨过决战金轮法王时所施展的决定胜负
// 的一招。

#include <ansi.h>
#include <combat.h>

#define TUO "「" HIM "拖泥带水" NOR "」"

inherit F_SSERVER;

string query_name() { return "拖泥"ZJBR"带水"; }
string *pfm_type() { return ({ "unarmed", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	int ap, dp;
	int effqi, maxqi;
	string couple;
	object cob;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(TUO "只能对战斗中的对手使用。\n");

	if (me->query("static/marry") > 1)
		return notify_fail("你感情早已不纯，哪里还能领略到那种黯然销魂的感觉？\n");

	if (! me->query("couple/id"))
		return notify_fail("你老婆都没有，还黯然什么？\n");

	if ((int)me->query_skill("force") < 250)
		return notify_fail("你的内功有效等级不足250级，使不出" TUO "。\n");

	if ((int)me->query_skill("sad-strike", 1) < 180)
		return notify_fail("你的黯然销魂掌不足180级，不会使用" TUO "。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你的真气不够，无法使用" TUO "。\n");

	if (me->query_skill_mapped("unarmed") != "sad-strike")
		return notify_fail("你没有激发黯然销魂掌，无法使用" TUO "。\n");

	if (! stringp(couple = me->query("couple/id")))
		return notify_fail("你没有妻子，体会不到这种万念俱灰的感觉。\n");

	if (! objectp(cob = find_player(couple)))
		return notify_fail("老婆不在啊，苦闷向谁发？\n");

	if (time() - me->query_temp("last_perform/sad-strike/tuo") < 60)
		return notify_fail("你刚刚施展完拖泥带水，现在心情没有那么郁闷了。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	effqi = me->query("eff_qi");
	maxqi = me->query("max_qi");

	ap = me->query_skill("unarmed");
	dp = target->query_skill("dodge");
	me->start_busy(3);

	if (effqi < maxqi * 25 / 100)
	{
		msg = HIR "$N" HIR "心下万念俱灰，凄然向" + cob->name(1) +
		      HIR "望了一眼，暗道：“别了！你自己保重。”\n"
		      "当下失魂落魄，随手一招，恰好使出了黯然销魂掌中"
		      "的「拖泥带水」。"NOR"\n";
		ap += ap * 50 / 100;
	} else
	{
		msg = HIM "只见$N" HIM "没精打采的挥袖卷出，拍出一掌，正是"
		      "黯然销魂掌中的「拖泥带水」。"NOR"\n";
	}
	if (ap / 2 + random(ap) > dp)
	{ 
		damage = ap + random(ap / 2);
		me->add("neili", -300);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 100,
					   HIR "只听$n" HIR "一声闷哼，“噗”的一"
					   "声，这一掌正好击在$p" HIR "肩头。 \n"
					   NOR);
		me->set_temp("last_perform/sad-strike/tuo", 1);
	} else
	{
		me->add("neili", -100);
		msg += HIC "可是$p" HIC "小心应付、奋力招架，挡开了这一招。\n"
		       NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
