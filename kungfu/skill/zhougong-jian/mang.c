#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "周公"ZJBR"剑芒"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp, lvl;
	int skill;
	int damage;
	object ob;

	if (userp(me) && ! me->query("can_perform/zhougong-jian/mang"))
		return notify_fail("你还不知道如何发出剑芒。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("剑芒只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("只有用剑才能发出剑芒。\n");

	if (me->query_skill_mapped("sword") != "zhougong-jian")
		return notify_fail("你必须激发周公剑才能使出剑芒。\n");

	if ((int)me->query_skill("zhougong-jian", 1) < 100)
		return notify_fail("你的周公剑不够娴熟，无法使出剑芒。\n");

	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("依你目前的内力修为还无法使出剑芒。\n");

	if ((int)me->query("neili", 1) < 500)
		return notify_fail("你现在真气不够，无法使出剑芒。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	skill = me->query_skill("zhougong-jian", 1);

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");

	lvl = (int) me->query_skill("zhougong-jian", 1) / 5 + 1;

	msg = HIW "$N" HIW "一声清啸，手中" + weapon->name() + HIW "凌"
		  "空划出，剑尖陡然生出半尺吞吐不定的青芒，一道剑气破空"
		  "径直划向$n。"NOR"\n";

	if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap / 2);

		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
					   HIR "$n" HIR "一声惨叫，凌厉的剑气已划过气门，"
					   "在身上刺出数个血洞，鲜血如泉水般涌出！"NOR"\n");
		message_combatd(msg, me, target);
	} else
	{
		msg += CYN "可是$n" CYN "看破了$N" CYN "的企图，斜跃避开。"NOR"\n";
		message_combatd(msg, me, target);
	}

	msg = HIW "$N" HIW "见$n" HIW "应接不暇，一声冷笑，兵刃挥洒而出，一记更加"
		  "凌厉的剑芒由剑尖弹射而出，凌空直射$n" HIW "。"NOR"\n";

	if (ap / 4 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap / 2);

		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
					   HIR "只听“噗嗤”一声，剑气正中$n" HIR "胸口，留"
					   "下一个碗口大的血洞！$n" HIR "哀嚎一声，再也无法"
					   "站起。"NOR"\n");
		me->start_busy(2 + random(2));
		me->add("neili", -300);
		message_combatd(msg, me, target);
		return 1;
	}

	msg += CYN "$n" CYN "强忍全身的痛楚，飞身一跃，避开了$N" CYN "这强大的杀着。"NOR"\n";
	me->start_busy(2 + random(3));
	me->add("neili", -200);
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
