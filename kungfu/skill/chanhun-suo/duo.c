#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "夺魂鞭"; }
string *pfm_type() { return ({ "whip", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (playerp(me) && ! me->query("can_perform/chanhun-suo/duo"))
		return notify_fail("你还不会使用夺魂。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("夺魂只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，使不了绝技夺魂。\n");

	if (me->query_skill("chanhun-suo", 1) < 80)
		return notify_fail("你的缠魂索功力太浅，使不了绝技夺魂。\n");

	if (me->query("neili") < 200)
		return notify_fail("你的真气不够，无法使用夺魂。\n");

	if (me->query_skill_mapped("whip") != "chanhun-suo")
		return notify_fail("你没有激发缠魂索法，使不了琐魂。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "诡异的一笑，手中" + weapon->name() +
	      HIY "抖得笔直，劈向$n" HIY "手腕，可是待到中途却又停滞，转往$n"
	      HIY "胸口挥去！"NOR"\n";

	ap = me->query_skill("whip") + me->query_skill("force");
	dp = target->query_skill("force") + target->query_skill("parry");

	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 3 + random(ap / 3);
		me->add("neili", -100);
		me->start_busy(2);

		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 25,
					   HIR "结果$n" HIR "一声惨叫，未能看破$N"
					   HIR "的企图，被这一鞭硬击在胸口，鲜血飞"
					   "溅，皮肉绽开！"NOR"\n");
		message_combatd(msg, me, target);
		if (ap > 400) ap = 400;
		dp += target->query_skill("martial-cognize", 1) * 2;
		if (! target->is_busy() &&
		    weapon->query("material") == "white silk" &&
		    ap / 2 + random(ap) > dp)
		{
			message_vision(HIW "$N" HIW "一抖，手中的" + weapon->name() +
				       HIW "“嗖”的串了出来，隐隐然缠向$n"
				       HIW "。\n$n" HIW "大吃一惊，急忙退后，闪去这一招。"NOR"\n",
				       me, target);
		}
	} else
	{
		me->add("neili", -100);
		me->start_busy(3);
		msg += CYN "可是$p" CYN "飞身一跃而起，躲避开了"
		       CYN "$P" CYN "的攻击！"NOR"\n";
		message_combatd(msg, me, target);
	}

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
