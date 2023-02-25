// zhao.c 佛光普照

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "佛光"ZJBR"普照"; }
string *pfm_type() { return ({ "staff", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「佛光普照」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	      (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if (me->query_skill("force") < 200)
		return notify_fail("你的内功的修为不够，不能使用这一绝技！\n");

	if (me->query_skill("pudu-zhang", 1) < 135)
		return notify_fail("你的普渡杖法修为不够，目前不能使用佛光普照！\n");

	if (me->query("neili") < 1000)
		return notify_fail("你的真气不够，不能使用佛光普照！\n");

	if (me->query_skill_mapped("staff") != "pudu-zhang")
		return notify_fail("你没有激发普渡杖法，不能使用佛光普照！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "纵声长笑，挥动手中的" + weapon->name() +
	      HIY "，如泰山一般压向$n" + HIY "，令人叹为观止！"NOR"\n";

	ap = me->query_skill("staff") + me->query("max_neili") / 10;
	dp = target->query_skill("force") + target->query("max_neili") / 10;

	if (ap / 2 + random(ap) > dp)
	{
		damage = me->query("max_neili") - target->query("max_neili");
		if (damage < 0) damage = 0;
		damage = damage / 5 + me->query_skill("staff") / 3;
		damage += random(damage / 3);
		me->add("neili", -250);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIR "只见$p" HIR "闷哼一声，连叫都叫"
					   "不出来，身子飞跌出去，重重的摔倒在地上！"NOR"\n");
		me->start_busy(1);
	} else
	{
		me->add("neili", -60);
		me->start_busy(3);
		msg += CYN "可是$p" CYN "运足内力，奋力挡住了"
		       CYN "$P" CYN "这惊天动地的一击！"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
