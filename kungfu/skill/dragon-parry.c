// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{

if ((int)me->query("con") < 30)
                return notify_fail("你研究了半天，只觉得根骨有些差，始终无法理解其中的真谛。\n");

        if ((int)me->query("int") < 30)
                return notify_fail("你研究了半天，只觉得悟性有些差，始终无法理解其中的真谛。\n");

        if ((int)me->query("str") < 30)
                return notify_fail("你研究了半天，感觉膂力有些低，始终无法随意施展。\n");

        if ((int)me->query("dex") < 30)
                return notify_fail("你研究了半天，只觉依自己的身法灵动性，根本无法修习这门武功。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功火候不够，难以修习这等神功。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力还不足以修习这等神功。\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("dragon-parry", 1))
                return notify_fail("你的基本内功水平有限，无法领会更高深的魔龙缠身。\n");

        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;
        int cost;

        if ((int)me->query_skill("dragon-parry", 1) < 100 ||
            ob->query("family/family_name") == "少林派" ||
            (int)me->query("neili") < 300)
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        mp = ob->query_skill("count", 1) * 5;
        ap = ob->query_skill("force") * 5 + ob->query("max_neili") + mp;
        dp = me->query_skill("force") * 5+ me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);
 
                result += (["msg" :HIB "$n" HIB "身后忽现魔龙虚影，周身浮现阵阵煞气，将$N"
                                    HIB "的攻击一一抵挡。\n" NOR]);
 
                return result;
        }
        else if (mp >= 100)
        {
                result = HIY "$n身前仿佛有一道无形气墙，但$N早已看破$n破绽，直攻向$n要害。\n";

 

                COMBAT_D->set_bhinfo(result);
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("dragon-parry", 1);
        if (lvl < 100) return 0;
        if (lvl < 150) return 50;
        if (lvl < 200) return 60;
        if (lvl < 250) return 70;
        if (lvl < 300) return 80;
        if (lvl < 350) return 90;
        if (lvl < 400) return 100;
        return 120;
}

int practice_skill(object me)
{
        return notify_fail("魔龙缠身只能用学习或研究来提高。\n"); 
        if (me->query_skill("dragon-parry", 1) < 100)
                return notify_fail("你对魔龙缠身的了解甚浅，还不足以自行锻炼。\n");

        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太低了。\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练习魔龙缠身。\n");

        me->receive_damage("qi", 50);
        me->add("neili", -85);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dragon-parry/" + action;
}
