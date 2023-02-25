// lianhuan.c 连环

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "连环掌"; }
string *pfm_type() { return ({ "strike", }); }

int perform(object me, object target)
{
	object weapon;
	string msg;
	mapping p;
	int i;
	int af;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「连环掌」只能对战斗中的对手使用。\n");
 
	if (objectp(me->query_temp("weapon")))
		return notify_fail("施展「连环掌」必须空手！\n");

	if (! mapp(p = me->query_skill_prepare()) ||
	    p["strike"] != "chongyang-shenzhang")
		return notify_fail("你必须准备好使用重阳神掌攻击才能施展「连环掌」。\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够！\n");

	if ((int)me->query_skill("chongyang-shenzhang", 1) < 100)
		return notify_fail("你的重阳神掌还不到家，无法使用「连环掌」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "大喝一声，双掌连环拍出，攻向$n" HIY "！"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -80);
	af = member_array("strike", keys(p));

	for (i = 0; i < 4; i++)
	{
		if (! me->is_fighting(target))
			break;

		me->set_temp("action_flag", af);		
		COMBAT_D->do_attack(me, target, 0, 0);
	}

	me->start_busy(1 + random(4));
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
