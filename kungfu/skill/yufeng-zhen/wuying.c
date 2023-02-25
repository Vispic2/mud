// wuying.c

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "无影"ZJBR"神针"; }
string *pfm_type() { return ({ "throwing", }); }

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
		return notify_fail("无影针只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("handing")) ||
	    (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你现在手中并没有拿着玉蜂针，怎么施展无影针？\n");

	if (weapon->query_amount() < 5)
		return notify_fail("至少要有五根玉蜂针你才能施展无影针。\n");

	if ((skill = me->query_skill("yufeng-zhen", 1)) < 100)
		return notify_fail("你的玉蜂针手法不够娴熟，不会使用无影针。\n");

	if (me->query_skill_mapped("throwing") != "yufeng-zhen")
		return notify_fail("你没有激发玉蜂针，不能使用无影针。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你内力不够了。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->add("neili", -80);
	weapon->add_amount(-5);

	msg= HIY "$N" HIY "身不慌，足不移，手掌只是轻轻一抖，只见"
	     "几点寒光一闪，闪电般的袭向$n" HIY "！"NOR"\n";

	me->start_busy(2);
	my_exp = me->query_skill("throwing");
	ob_exp = target->query_skill("dodge");
	if (my_exp / 2 + random(my_exp) > ob_exp)
	{
		msg += HIR "结果$p" HIR "反应不及，中了$P" + HIR "一" +
		       weapon->query("base_unit") + weapon->name() +
		       HIR "！"NOR"\n";
		target->receive_wound("qi", skill + random(skill / 2), me);
		COMBAT_D->clear_ahinfo();
		weapon->hit_ob(me, target,
			       me->query("jiali") + 120);
		if (stringp(pmsg = COMBAT_D->query_ahinfo()))
			msg += pmsg;
		message_combatd(msg, me, target);
	} else
	{
		msg += HIG "可是$p" HIG "从容不迫，轻巧的闪过了$P" HIG "发出的" +
		       weapon->name() + HIG "。"NOR"\n";
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
