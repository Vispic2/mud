// quan 九阴神拳
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "九阴"ZJBR"神拳"; }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int damage;
	int jysg,jysgs;
	jysg=me->query("jysg")*10;
	jysgs=me->query("jysg")*100;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("九阴神拳只能对战斗中的对手使用。\n");
 
	if (me->query_skill("jiuyin-shengong", 1) < 120)
		return notify_fail("你的九阴神功还不够娴熟，不能使用九阴神拳！\n");

	if (me->query("neili") < 200+jysgs)
		return notify_fail("你的内力不够，不能使用九阴神拳！需要："+(200+jysgs)+"点\n");
 
       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "一声冷哼，握拳击出，招式雄浑，难擢其威！"NOR"\n";
 
	ap = me->query_skill("cuff") + me->query("str") * 15 +
	     me->query_skill("martial-cognize", 1);
	dp = target->query_skill("dodge") + target->query("str") * 15 +
	     target->query_skill("martial-cognize", 1);
if(jysg>=5)
{
me->start_busy(1+random(2));
}else
{
	me->start_busy(2);
	}
	me->add("neili", (-100+jysgs));
	/*
	if(jysg >= 10)
	{
	
		me->add("neili",-75);
		damage = ap + random(ap/2) -target->query_gain_armor();
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 600,
					   HIR "$n" HIR "连忙格挡，可是这一拳力道何等之重，哪里抵"
					   "挡得住？只被打得吐血三尺，连退数步！"NOR"\n");
	}


else


{
*/
	if (ap / 2 + random(ap) < dp)
	{
	
		msg += HIG "只见$n" HIG "不慌不忙，轻轻一闪，躲过了$N" HIG "这一击！"NOR"\n";
	
}else
	{
		me->add("neili",(-100+jysgs));
		damage = ap + random(ap/2) -target->query_gain_armor();
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60+jysg,
					   HIR "$n" HIR "连忙格挡，可是这一拳力道何等之重，哪里抵"
					   "挡得住？只被打得吐血三尺，连退数步！"NOR"\n");
	}


//}
	message_combatd(msg, me, target);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
