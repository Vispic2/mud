// jinglei.c 弹指惊雷
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;

string final(object me, object target, int ap, int dp, int wound);
 
string query_name() { return "弹指"ZJBR"惊雷"; }
string *pfm_type() { return ({ "finger", }); }

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「弹指惊雷」只能在战斗中对对手使用。\n");

	skill = me->query_skill("tanzhi-shentong", 1);

	if (skill < 120)
		return notify_fail("你的弹指神通等级不够, 不能使用「弹指惊雷」！\n");

	if (me->query("neili") < 250)
		return notify_fail("你的真气不够，无法运用「弹指惊雷」！\n");
 
	if (me->query_skill_mapped("finger") != "tanzhi-shentong") 
		return notify_fail("你没有激发弹指神通，无法使用「弹指惊雷」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "使出弹指神通之「弹指惊雷」，顿时"
	      "眼内精光暴射，一股锐利的指气袭向$n" HIC "！"NOR"\n";
 
	ap = me->query_skill("finger") + me->query_skill("force");
	dp = target->query_skill("force") + target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -200);
		damage = ap / 3 + random(ap / 2);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 55,
					   (: final, me, target, ap, dp, damage :));
		me->start_busy(3);
	} else
	{
		msg += CYN "可是$p" CYN "的看破了$P" CYN "的企图，立刻采取"
		       "守势，使$P" CYN "的「弹指惊雷」没有起到作用。"NOR"\n";
		me->add("neili", -50);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

string final(object me, object target, int ap, int dp, int wound)
{
	object weapon;
	string msg;

	msg = HIR "$p" HIR "只觉得眼前杀气纵横，不由"
	      "大惊失色，连避不及，只觉得"
	      "气海穴上一阵剧痛，几乎晕厥！"NOR"\n";
	target->receive_damage("jing", wound / 3, me);
	target->receive_wound("jing",  wound / 6, me);
	if ((weapon = target->query_temp("weapon")) &&
	    ap / 4 + random(ap) > dp)
	{
		msg += HIR "$p" HIR "手腕一麻，手中" + weapon->name() +
		       HIR "不由脱手而出！"NOR"\n";
		weapon->move(environment(me));
	}
	
	return msg;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
