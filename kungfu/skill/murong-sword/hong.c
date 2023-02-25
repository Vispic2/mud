// hong.c 白虹贯日

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "白虹"ZJBR"贯日"; }
string *pfm_type() { return ({ "sword", }); }

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
		return notify_fail("「白虹贯日」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("施展「白虹贯日」手中必须拿着一把剑！\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你的真气不够，无法施展「白虹贯日」！\n");

	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功火候不够，无法施展「白虹贯日」！\n");

	if ((int)me->query_skill("murong-sword", 1) < 180)
		return notify_fail("你的慕容剑法还不到家，无法使用绝技「白虹贯日」！\n");

	if (me->query_skill_mapped("sword") != "murong-sword")
		return notify_fail("你没有激发慕容剑法，无法使用「白虹贯日」！\n");

	msg = HIW "$N" HIW "身形一转，转眼间跃起空中，随即雪亮的剑光一旋一扫，自右"
	      "向左，疾速卷向$n" HIW "！"NOR"\n";
	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -250);
		me->start_busy(3);
		damage = ap + random(ap / 2);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 59,
					   HIR "$n" HIR "身形急退，然而$N" HIR "此剑来得"
					   "迅伦无比，剑气更是遥遥而至，登时在$n"
					   HIR "身上刺穿了一道深深的创口。"NOR"\n");
	} else
	{
		me->add("neili", -100);
		me->start_busy(2);
		msg += WHT "$n" WHT "见此招势道凶猛，不敢轻易招架，身子"
		       "先曲后仰再弹，双脚一踏一盘一跃，向后急掠而退。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
