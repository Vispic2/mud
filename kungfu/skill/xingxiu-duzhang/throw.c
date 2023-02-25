// throw.c 抽髓掌施毒

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "毒掌"ZJBR"抽穗"; }

int perform(object me, object target)
{
	object obj;
	string msg;
	int lvl;

	if (! target) target = offensive_target(me);

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不能攻击别人! \n");

	if (! target || ! target->is_character())
		return notify_fail("施毒只能对对手使用。\n");

	if (target->query("not_living"))
		return notify_fail("看清楚，那不是活人。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 40)
		return notify_fail("你的化功大法不够娴熟，不能施毒。\n");

	if ((int)me->query_skill("chousui-zhang", 1) < 40)
		return notify_fail("你的抽髓掌不够娴熟，不能施毒。\n");

	if (! (objectp(obj=present("corpse", environment(me)))  ||
	    objectp(obj = present("corpse", me)) ||
	    objectp(obj = present("Skeleton", environment(me))) ||
	    objectp(obj = present("Skeleton", me)) ) )
		return notify_fail("你周围没有尸体，无法施展绝技。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = CYN "$N" CYN " 顺手抓起尸体，将毒质运于其上，掷向$n"
	      CYN "。"NOR"\n";

	if (random(lvl = (int)me->query_skill("chousui-zhang", 1)) >
	    target->query_skill("dodge") / 2)
	{
		msg += HIR " 结果$p" HIR "被$P" HIR "攻了个正着！"NOR"\n";
		target->receive_damage("qi",(int)me->query_skill("chousui-zhang", 1), me);
		target->receive_wound("qi",15 + random(10), me);
		target->receive_wound("jing", 10, me);
		target->affect_by("xx_poison",
			       ([ "level" : me->query("jiali") + random(me->query("jiali")),
				  "id"    : me->query("id"),
				  "duration" : lvl / 50 + random(lvl / 20) ]));
		me->start_busy(2);
	} else
	{
		msg += CYN "可是$p" CYN "急忙闪在一旁，躲了开去。"NOR"\n";
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	destruct(obj);
	return 1;
}
