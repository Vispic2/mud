// 勾魂追命(gouhun)

#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "寒天吹雪" NOR "」"

inherit F_SSERVER;

string *weapon_sk = ({
	"sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

string query_name() { return "寒天"ZJBR"吹雪"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count;
	int i, attack_time;


	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(PFM "只能对战斗中的对手使用。\n");

	
	
	if ((int)me->query_skill("chuixue-jian", 1) < 100)
		return notify_fail("你" + to_chinese("chuixue-jian") + "不够娴熟，难以施展" PFM "。\n");

	
	if (me->query("neili") < 300)
		return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N手中武器寒气逼人，剑气撕裂空气，片片雪花飘落，剑未至气先及，$n眉毛都蒙上了薄薄白霜！" + "\n" + NOR;

	ap = me->query_skill("sword");
	dp = target->query_skill("parry");
	attack_time = 6;

	if (ap * 2 / 3 + random(ap * 2) > dp)
	{
		msg += HIM "结果$n闪避不及，$N的剑气顿时透体而入，$n口中鲜血狂喷，连退数步。" + ""NOR"\n";
		count = ap / 10;
		me->add_temp("apply/attack", count);
		me->add_temp("apply/damage", count);
	} else
	{
		msg += NOR + CYN "$p见势不妙，抽身急退，险险避过$P的这记杀招，尘土飞扬中，地上裂开了一道大口子！" + ""NOR"\n";
		count = 0;
	}

	message_sort(msg, me, target);

	attack_time += me->query("jieti/times") * 2;
	if (attack_time > 13)
		attack_time = 13;

	me->add("neili", -attack_time * 20);

	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

		if (random(2) && ! target->is_busy()) target->start_busy(1);

		COMBAT_D->do_attack(me, target, (member_array("sword", weapon_sk) == -1 ? 0 : weapon), 0);
	}
	me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -count);
	me->start_busy(3 + random(attack_time/ 3));

	return 1;
}


