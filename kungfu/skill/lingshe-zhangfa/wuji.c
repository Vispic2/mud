// wuji.c 横行无忌

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "横行"ZJBR"无忌"; }
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

	if (! target || ! me->is_fighting(target))
		return notify_fail("「横行无忌」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("运用「横行无忌」必须手中持杖！\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，难以运用使用「横行无忌」！\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在的真气不够，无法使用「横行无忌」！\n");

	if ((int)me->query_skill("lingshe-zhangfa", 1) < 150)
		return notify_fail("你的灵蛇杖法还不到家，无法使用「横行无忌」！\n");

	if (me->query_skill_mapped("staff") != "lingshe-zhangfa") 
		return notify_fail("你没有激发灵蛇杖法，无法使用「横行无忌」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "一声冷笑，手中的" + weapon->name() + HIY "忽然变得"
	      "如同活物一般，时上时下，忽左忽右，不知攻向$n" HIY "何处！"NOR"\n";
	ap = me->query_skill("staff");
	dp = target->query_skill("parry");
	me->start_busy(3);
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 55,
					   HIR "$n" HIR "实在无法捕捉到$P"
					   HIR "的实招，接连挡空，连中数招，"
					   "登时吐了一口鲜血！"NOR"\n");
	} else 
	{
		msg += CYN "$n" CYN "奋力招架，总算抵挡住了$P"
		       CYN "的攻击！"NOR"\n";
		me->add("neili", -80);
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
