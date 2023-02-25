#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIR "天剑三式" NOR "」"
string query_name() { return "天剑"ZJBR"三式"; }
inherit F_SSERVER;

string attack1(object me, object target, int damage);
string attack2(object me, object target, int damage);

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "只能在战斗中对对手使用。\n");

        if( !objectp(weapon=me->query_temp("weapon")) ||
            weapon->query("skill_type") != "sword" )
                return notify_fail("你使用的武器不对！\n");

        if ((int)me->query_skill("tiandaojian", 1) < 800)
                return notify_fail("你天道剑火候不足，无法施展" XIAN "。\n");

        if ((int)me->query_skill("force", 1) < 600)
                return notify_fail("你基本内功修为不够，无法施展" XIAN "。\n");

        if( me->query("neili")<3000 )
                return notify_fail("你现在真气不够，无法施展" XIAN "！\n");

        if (me->query_skill_mapped("sword") != "tiandaojian")
                return notify_fail("你没有激发天道剑，无法使用" XIAN "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -1000);

        ap=me->query_skill("sword")+me->query_skill("force")+me->query_skill("martial-cognize",1)+me->query("str");
        dp = target->query_skill("dodge") + target->query_skill("force") + target->query_skill("martial-cognize", 1);

        message_combatd(HIW "\n$N" HIW "一声长叹，似乎看尽凡尘沧桑，事态万千，持剑而立，遥望天际 ……\n\n", me, target);

        // 第一剑
        msg = HIY "$N" HIY "踏步向前，施展出天剑三式之「人法地」，" + weapon->name() + HIY
              "挥剑横扫，如天行道……\n" NOR;

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap * 3 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,300+me->query("str"),
                                           HIR "$n" HIR "惊魂未定，竟然不知躲避，被$N"
                                           HIR "一剑劈过，剑气入体，口吐鲜血，接连后退。\n" NOR);
        }
        else
        {
                msg += CYN "$n" CYN "飞身一跃，滚在一边。\n" NOR;
        }

        // 第二剑
        msg += HIY "\n$N" HIY "轻叹，猛然间，手臂一挥，一式天剑三式之「地法天」已然使出，" + weapon->name() + HIY "长鸣一声"
               "，划破黑暗，吹吸间，一道炽热的白光卷向$n" HIY "，周围空气令人窒息。\n" NOR;

        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap * 4 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,300+me->query("str"),
                                          (: attack1, me, target, damage :));
        }
        else
        {
                msg += CYN "$n" CYN "胡乱施展招式，竟将这招化解。\n" NOR;
        }

        // 第三剑
        msg += HIY "\n$N" HIY "长吟一声，天剑三式之「天法道」已然使出，$N" HIY "却早已没了踪影。\n" NOR;
        if (ap * 4 / 5 + random(ap) > dp)
        {
                damage = ap * 5 + random(ap);
                msg+=COMBAT_D->do_damage(me,target,WEAPON_ATTACK,damage,350+me->query("str"),
                                           (: attack2, me, target, damage :));


        }
        else
        {
                msg += CYN "$n" CYN "收摄心神，小心应对，竟将此招化解与无形。\n" NOR;
        }

        me->start_busy(3 + random(3));
        message_combatd(sort_msg(msg), me, target);
        return 1;
}

string attack1(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "只觉心中一阵凄凉，胸口却已翻腾不息，说不出的难受。\n" NOR;

        target->add("neili", -1*damage*2/3);

        return msg;
}

string attack2(object me, object target, int damage)
{
        string msg;

        msg = HIR "$n" HIR "早已十魂失了八魄，正惊疑间，眼前一闪，剑气透体而过。\n" NOR;

        target->receive_wound("jing", damage / 7, me);
        if (random(3) == 1)target->start_busy(6 + random(6));

        return msg;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
