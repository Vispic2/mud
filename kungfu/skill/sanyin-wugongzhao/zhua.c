// zhua.c 三阴毒爪

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string final(object me, object target);

string query_name() { return "三阴"ZJBR"毒爪"; }
string *pfm_type() { return ({ "claw", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「三阴毒爪」只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 80)
		return notify_fail("你的三阴蜈蚣爪不够娴熟，无法使用「三阴毒爪」。\n");

	if (me->query_skill_mapped("claw") != "sanyin-wugongzhao")
		return notify_fail("你没有激发三阴蜈蚣爪，无法使用「三阴毒爪」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "突然一声怪叫，蓦的面赤如血，随即手腕一抖，抓向$n"
	      HIR "的要害。"NOR"\n";

	ap = me->query_skill("claw");
	dp = target->query_skill("parry");
	if (ap  / 2 + random(ap*3/2) > dp)
	{
		damage = ap / 2 + random(ap / 2);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   (: final, me, target :));
		me->start_busy(2);
	} else
	{
		msg += HIR "不过$p" HIR "看破了$P" HIR "的招式，"
		       "凝神招架，挡住了$P" HIR "的毒招。"NOR"\n";
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

string final(object me, object target)
{
	int lvl;

	lvl = me->query_skill("claw");
	target->affect_by("sanyin",
		       ([ "level" : me->query("jiali") + random(me->query("jiali")),
			  "id"    : me->query("id"),
			  "duration" : lvl / 40 + random(lvl / 40) ]));

	return HIR "$p" HIR "惊慌失措，连忙后退，然而没"
	       "能避开，被$P" HIR "这一爪抓得鲜血淋漓！"NOR"\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
