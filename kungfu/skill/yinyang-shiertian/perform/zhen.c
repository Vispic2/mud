#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#define YINYANG "「" HIW "镇阴阳" NOR "」"


int perform(object me, object target)
{
        string msg;
        int lvl;
        int ap, dp, dp1;
        int sub, damage;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(YINYANG "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(YINYANG "只能空手使用。\n");

        if (me->query_skill_mapped("force") != "yinyang-shiertian")
                return notify_fail("你没有激发阴阳九转十二重天为特殊内功，无法使用" YINYANG "。\n");

        if ((int)me->query("neili") < 2000)
	        return notify_fail("你的真气不够，无法施展" YINYANG "！\n");

        if (me->query("max_neili") < 5000)
	        return notify_fail("你的内力修为还不足以使出" YINYANG "。\n");

        if ((int)me->query_skill("force") < 500)
	        return notify_fail("你的内功火候不够，难以施展" YINYANG "！\n");

        if ((lvl = (int)me->query_skill("yinyang-shiertian", 1)) < 500)
	        return notify_fail("你的阴阳九转十二重天还不够熟练，无法使用" YINYANG "！\n");

        if (! living(target))
	        return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_sort(HIM "\n$N" HIM "运起阴阳九转十二重天，左手" HIB "阴"
		     HIM "，右手" HIR "阳" HIM "，澎湃的内劲由体内而发，"
		     HIM "以排山倒海之势卷向$n" HIM "！\n" NOR, me, target);

        ap =   me->query_skill("force");

        sub = 0;
        dp1 = 0;

        if (target->query_skill_mapped("force") == "yinyang-shiertian")
        {
	        sub = 3;
	        dp1 = target->query_skill("yinyang-shiertian", 1);
        } else
        if (target->query_skill_mapped("force") == "taixuan-gong")
        {
	        sub = 3;
                dp1 = target->query_skill("taixuan-gong", 1) / 2;
        } else
        if (target->query_skill_mapped("force") == "taiji-shengong")
        {
                sub = 3;
                dp1 = target->query_skill("taiji-shengong", 1) / 2;
        }else
        if (target->query_skill_mapped("force") == "jiuyin-shengong")
        {
                sub = 1;
                dp1 = target->query_skill("jiuyin-shengong", 1);
        }else
        if (target->query_skill_mapped("force") == "jiuyang-shengong")
        {
                sub = 2;
                dp1 = target->query_skill("jiuyang-shengong", 1);
        }

        //第一招：阴

        dp = target->query_skill("dodge");

        if (sub == 1 || sub == 3)
                dp += dp1;

        message_sort(HIB "\n$N" HIB "左掌往前一推，阴寒无比的真气汹涌而出，"
		     "似乎能连空气都一起冻住！\n" NOR, me, target);

        if (ap * 2 / 3 + random(ap) > dp)
        {
	        damage = me->query_skill("force")*10;
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(20),
					  HIB "$n" HIB "但见$N" HIB "左掌已攻出，"
				          HIB "正欲反击。突然间胸口一震，不禁暗暗叫苦，"
                                          HIB "胸口处一股寒气升起，全身都被冻僵了。\n" NOR);
	        target->start_busy(3 + random(lvl / 500));
        } else
        {
                msg = CYN "$n" CYN "见$P" CYN "来势汹涌，不敢轻易抵"
	              "挡，连忙飞身腾挪，躲闪开来。\n" NOR;
        }

        message_sort(msg, me, target);

        //第二招：阳

        dp = target->query_skill("parry");

        if (sub == 2 || sub == 3)
	        dp += dp1;

        message_sort(HIR "\n$N" HIR "右手金光万道，灼热的真气澎湃激荡，"
		     HIR "所到之处散发着一股焦臭的味道！\n" NOR, me, target);

        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = me->query_skill("force")*10;
	        msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 80 + random(40),
                                          HIR "$n" HIR "急忙抽身后退，忽然金光暴涨，"
					  HIR "只见$n" HIR "跌跌撞撞向后连退数步，伏倒"
                                          "在地。须眉、衣衫都发出一股焦臭。\n" NOR);
        } else
        {
                msg = CYN "可是$n" CYN "看透$P" CYN "此招之中的破绽，镇"
	              "定逾恒，应对自如。\n" NOR;
        }

        message_sort(msg, me, target);

	me->start_busy(3 + random(4));
	me->add("neili", -500 - random(100));
	return 1;
}

