// pi.c 开天辟地

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "开天"ZJBR"辟地"; }

int perform(object me, object target)
{
	object weapon, weapon2;
	int damage, i, n;
	string msg, str;
	int ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	if (! target || ! me->is_fighting(target))
		return notify_fail("「开天辟地」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    weapon->query("skill_type") != "blade")
		return notify_fail("运用「开天劈地」手中必须有刀！\n");

	if (me->query_skill("hujia-daofa", 1) < 200)
		return notify_fail("你的胡家刀法不够娴熟，不会使用「开天辟地」。\n");
				
	if (me->query_skill("force") < 250)
		return notify_fail("你的内功修为不够高。\n");
			
	if (me->query("neili") < 800)
		return notify_fail("你现在内力太弱，不能使用「开天劈地」。\n");

	if (userp(me) && ! me->query("can_perform/hujia-daofa/pi"))
		return notify_fail("你还不会使用「开天辟地」这一绝技。\n");
			
	msg = HIC "$N" HIC "一声长笑，中宫直进，双手紧握" + weapon->name() +
	      HIC "刀柄，长吸一口气，全力向$n" HIC "迅猛劈去！"NOR"\n";

	if (target->query_temp("lengyue-shengong_freeze"))
	{
		msg += HIW + weapon->name() +
		HIW "寒气逼人，刀身撕裂空气，片片雪花飘落，刀未至气先及，$n" HIW
		"眉毛都蒙上了薄薄白霜！"NOR"\n";
	}

	ap = me->query_skill("blade") + me->query_skill("force");
	dp = target->query_skill("force");
	if (ap / 3 + random(ap / 3) > dp)
	{
		damage = ap + random(ap);
		damage += me->query("jiali");

		me->add("neili", -(damage / 2));

		if (! objectp(weapon2 = target->query_temp("weapon")))
		{       
			msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 80,
						       HIR "只见$n" HIR "一声惨叫，胸口给"
						       "劈开一个巨大的口子，鲜血汹涌喷出！"NOR"\n");
     	for (i = 0; i < 2; i++)
				{
				
					if (me->query_skill("miaojia-jian",1) + random(ap) > dp){
					msg += (random(2) ? HIB : HIC) + "$N看准时机向$n的左右"HIG"肩膀各挥"HIY"一刀，打的$n"HIM"毫无还手之力！"NOR"\n";
					target->receive_damage("qi", damage / 9, me);
					target->receive_wound("qi",damage / 18 + random(damage / 15), me);
					}else{
					msg += (random(2) ? HIB : HIC) + "你猛然朝$n连挥两刀，只见$n一个反复横跳躲开了你这两刀！"NOR"\n";
					}
				}
				
			if (target->query_temp("lengyue-shengong_freeze"))
				msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 33,
							   HIB "\n$n" HIB "身形摇晃间，感觉到"
							   + weapon->name() + HIB + 
							   "上一阵刺骨的寒气侵入体内，复又喷出"
							   "一口鲜血！"NOR"\n");
		} else
		{
			if (weapon2->is_item_make() || weapon2->query("damage") > 180 ||
			    weapon2->query("skill_type") == "hammer")
				msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
							   HIG "$p" HIG "横过" + weapon2->name() + HIG "试图招架，"
							   HIG "怎奈这刀气如此犀利，透过" + weapon2->name() +
							   HIG "直震得$p" HIG "狂吐鲜血，五脏六腑都要翻转过来！"NOR"\n");
			else
			{
				msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 50,
							   HIR "$n" HIR "见状不妙，连忙举起" + 
							   weapon2->name() + HIR + "抵挡，在$N" HIR
							   "这霸气无双的一招下，" + weapon2->name() +
							   HIR "给震成碎片！"NOR"\n");
				n = 2 + random(3);
				for (i = 0; i < n; i++)
				{
					msg += (random(2) ? HIB : HIC) + "碎片四散飞溅，射入了$n的身体！"NOR"\n";
	
					target->receive_damage("qi", damage / 7, me);
						target->receive_wound("qi",damage / 15 + random(damage / 15), me);
				}
	
				msg += "\n" + HIY + weapon->name() + HIY "余势未尽，又劈入了$n" + HIY + 
					"的胸口，$n遭此重创，鲜血狂喷而出！"NOR"\n";

				weapon2->set_name("碎裂的" + weapon2->query("name"));
				weapon2->move(environment(target));
				weapon2->set("value", 0);
				weapon2->set("weapon_prop", 0);
			}

			target->reset_action();
			target->receive_damage("qi", damage / 2, me);
					       target->receive_wound("qi",
					       damage / 4 + random(damage / 4), me);

			if (target->query_temp("lengyue-shengong_freeze"))
				msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 25,
							   HIB "\n$n" HIB "身形摇晃间，感觉到"
							   + weapon->name() + HIB + 
							   "上一阵刺骨的寒气侵入体内，复又喷出"
							   "一口鲜血！"NOR"\n");
		}
		me->start_busy(3);
		target->start_busy(1 + random(2));
	} else 
	{
		msg += HIY "$n" HIY "见势不妙，抽身急退，险险避过$N"
		       HIY "的这记开天辟地，尘土飞扬中，地上裂开了一道大口子！"NOR"\n";
		me->add("neili", -100);
		me->start_busy(3);
	}
	
	message_sort(msg, me, target);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
