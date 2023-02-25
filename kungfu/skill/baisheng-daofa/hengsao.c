// hengshao.c 横扫千军

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string final(object me, object target, int ap, int dp);
 
string query_name() { return "横扫"ZJBR"千军"; }
string *pfm_type() { return ({ "blade", }); }

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
		return notify_fail("「横扫千军」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("运用「横扫千军」必须手中持刀！\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够！\n");

	if ((int)me->query_skill("baisheng-daofa", 1) < 150)
		return notify_fail("你的百胜刀法还不到家，无法使用「横扫千军」！\n");

	if (me->query_skill_mapped("blade") != "baisheng-daofa")
		return notify_fail("你没有激发百胜刀法，无法使用「横扫千军」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	ap = me->query_skill("blade") + me->query_str() * 10;
	if (me->query("character") == "光明磊落")
	{
		msg = HIR "$N" HIR "嗔目大喝，杀气凛然而起，手持" + weapon->name() +
		      HIR "义无反顾的猛然横扫$n" HIR "，全然不顾生死，浩气怅然！"NOR"\n";
		ap += ap * 3 / 10;
	} else
		msg = HIR "$N" HIR "将内力运在" + weapon->name() +
		      HIR "上面，“唰”的一声扫向$n。"NOR"\n";

	dp = target->query_skill("parry") + target->query_str() * 10;
	damage = 0;
	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap / 2);
	    me->add("neili", -500+random(500));
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,  (: final, me, target, ap, dp :));
		me->start_busy(3);
	} else 
	{
		msg += HIC "$n" HIC "奋力招架，硬生生的挡住了这令天地失色之必杀一击！"NOR"\n";
	     me->add("neili", -150);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}

string final(object me, object target, int ap, int dp)
{
	object weapon;
	string msg;

	msg = HIR "$n" HIR "连忙抵挡，却那里招架得住，整个人"
	      "被这一击打得飞身而起，远落平沙！";
	if ((ap / 3 > dp)&& objectp(weapon = target->query_temp("weapon")))
	{
		//msg += "就此毙命！"NOR"\n";
		//call_out("char_killed", 0, target, me);
		msg += "手中的" + weapon->name() + HIR+ "再也拿捏不住，应声而出。"+NOR+"\n";
		weapon->move(environment(me));
	} else
	if ((ap / 2 > dp) && objectp(weapon = target->query_temp("weapon")))
	{
		msg += "手中的" + weapon->name() + HIR "再也拿捏不住，应声而出。"NOR"\n";
		weapon->move(environment(me));
	} else
		msg += ""NOR"\n";
	return msg;
}

void char_killed(object ob, object me)
{
	if (objectp(ob) && objectp(me) && me->is_fighting(ob) &&
	    environment(ob) == environment(me))
		ob->die(me);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
