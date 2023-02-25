// feilong.c 华山剑法「天外飞龙」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "天外"ZJBR"飞龙"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int ap, dp;

	if (userp(me) && ! me->query("can_perform/huashan-sword/feilong"))
		return notify_fail("你不会使用天外飞龙。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天外飞龙」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("不拿剑怎么使用「天外飞龙」？\n");

	if ((int)me->query_skill("huashan-sword", 1) < 150)
		return notify_fail("你华山剑法不够娴熟，使不出「天外飞龙」。\n");

	if ((int)me->query_skill("force") < 150 )
		return notify_fail("你内功火候不够，使不出「天外飞龙」。\n");

	if ((int)me->query("neili") < 400)
		return notify_fail("你现在真气不够，无法将「天外飞龙」使完！\n");

	if (me->query_skill_mapped("sword") != "huashan-sword")
		return notify_fail("你没有激发华山剑法，无法使用「天外飞龙」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "心念电闪，一提内力，勒手仗剑，运劲于臂，呼"
	      "的一声向$n" HIC "掷了出去，"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
	if (ap > dp / 2 * 3 && ap / 2 + random(ap) > dp)
	{
		me->start_busy(3);
		//damage = target->query("max_qi") / 4 + ap;
		damage = me->query("max_qi") / 4 + ap;
		damage += random(damage / 4);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
					   HIR "$n" HIR "疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃"
					   "拦腰而过，鲜血飞溅，皮肉卷起！"NOR"\n");
		me->add("neili", -400);
	} else
	{
		me->start_busy(3);
		msg += CYN "然而$n" CYN "轻轻一笑，侧身伸指，正弹"
		       "在$N" CYN "的剑脊上，剑斜飞落地。"NOR"\n";
		me->add("neili", -400);
	}

	weapon->move(environment(me));
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
