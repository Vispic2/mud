#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "风火轮"; }
string *pfm_type() { return ({ "staff", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (userp(me) && ! me->query("can_perform/fumo-zhang/lun"))
		return notify_fail("你现在还不会使用「" HIR "风火轮" NOR "」这一招！\n");

	if (! target || ! me->is_fighting(target))
		return notify_fail("「" HIR "风火轮" NOR "」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对！\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，难以运用使用「" HIR "风火轮" NOR "」！\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在的真气不够，无法使用「" HIR "风火轮" NOR "」！\n");

	if ((int)me->query_skill("fumo-zhang", 1) < 150)
		return notify_fail("你的二十四路伏魔杖还不到家，无法使用「" HIR "风火轮" NOR "」！\n");

	if (me->query_skill_mapped("staff") != "fumo-zhang") 
		return notify_fail("你没有激发二十四路伏魔杖，无法使用「" HIR "风火轮" NOR "」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "一声暴喝，手中" + weapon->name() + HIW "一阵狂舞，"
	      "残影化出无数个大圈，如同" NOR + HIR "风火轮" NOR + HIW "一般，铺"
	      "天盖地席卷向$n" HIW "！"NOR"\n";
	ap = me->query_skill("staff");
	dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap / 2);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 30,
					   HIR "$n" HIR "完全无法看清$N"
					   HIR "招中的虚实，只听“砰砰砰"
					   "”几声，连续被$P"
					   HIR "击中，顿时呕血数升！"NOR"\n");
		me->start_busy(2);
	} else 
	{
		msg += CYN "$n" CYN "奋力招架，总算抵挡住了$P"
		       CYN "的攻击！"NOR"\n";
		me->add("neili", -80);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
