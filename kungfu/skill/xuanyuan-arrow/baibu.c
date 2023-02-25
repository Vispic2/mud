// baibu.c 百步穿杨

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "百步"ZJBR"穿杨"; }

int perform(object me, object target)
{
	int skill, i;
	int n;
	int my_exp, ob_exp;
	string pmsg;
	string msg;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("百步穿杨只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    ! weapon->is_arrow())
		return notify_fail("你现在手中并没有拿着箭，怎么施展百步穿杨？\n");

	if (weapon->query_amount() < 3)
		return notify_fail("至少要有一支箭你才能施展百步穿杨。\n");

	if ((skill = me->query_skill("xuanyuan-arrow", 1)) < 100)
		return notify_fail("你的轩辕箭法不够娴熟，不会使用百步穿杨。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -80);
	weapon->add_amount(-1);

	msg= HIY "突然间，$N" HIY "几个筋斗倒翻而去，已在$n" HIY
	     "数丈之外。$n" HIY "正待追击，$N" HIY "忽然转身，好一个「百步穿杨」！\n"
	     HIY "说时迟，那时快，" HIY + weapon->name() + HIY "已带着破空之声，直射$n"
	     HIY "面门！"NOR"\n";

	me->start_busy(2);
	my_exp = me->query_skill("throwing");
	ob_exp = target->query_skill("dodge");
	if (my_exp / 2 + random(my_exp) > ob_exp)
	{
		msg += HIR "结果$p" HIR "反应不及，中了$P" + HIR "一箭！"NOR"\n";
		target->receive_wound("qi", skill / 3 + random(skill / 3), me);
		COMBAT_D->clear_ahinfo();
		weapon->hit_ob(me, target,
			       me->query("jiali") + 120);
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += CYN "可是$p" CYN "从容不迫，轻巧的闪过了$P"
		       CYN "这一箭。"NOR"\n";
		message_combatd(msg, me, target);
	}

	me->reset_action();
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
