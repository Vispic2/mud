#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
        "可是$n侧身一让，$N这一招扑了个空。\n",
        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
        "$n身形微晃，有惊无险地避开了$N这一招。\n",
        "$n跨出几步，落点怪异莫测，让$N这一招没有发挥任何作用。\n",
        "$n自顾自的走出几步，浑然不理$N出招攻向何处。\n",
        "$N这一招眼看就要击中，可是$n往旁边一让，去点之妙，实在是匪夷所思。\n",
        "$n往前一迈，忽然后退，恰恰避开$N这一招，有惊无险。\n",
});

int valid_enable(string usage)
{
        return usage == "dodge";
}

int valid_learn(object me)
{

		if (me->query("str") < 60)
                return notify_fail("你的先天臂力不足无法学习。\n");
        if (me->query("dex") < 60)
                return notify_fail("你的先天身法不足无法学习。\n");
		if (me->query("int") < 60)
                return notify_fail("你的先天智商不足无法学习。\n");
        if (me->query("con") < 60)
                return notify_fail("你的先天根骨不足无法学习。\n");


        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功火候不够，难以修习这等神功。\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("你的内力还不足以修习这等神功。\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("tiandao-dunyi", 1))
                return notify_fail("你的基本轻功水平有限，无法领会更高深的天道遁一。\n");
			
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;

        if ((int)me->query_skill("tiandao-dunyi", 1) < 200 ||
		    me->query_skill_mapped("dodge") != "tiandao-dunyi" ||
            ! living(me))
                return;
        
        ap = ob->query_skill("dodge", 1) * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("tiandao-dunyi", 1) * 5 + me->query_skill("tiandao-shengong", 1) * 2 + me->query_skill("martial-cognize", 1);
        
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "身子轻轻晃动，$N" HIW
                                            "眼前顿时出现了无数个$n" HIW "的幻影，令$N"
                                            HIW "完全无法辨出虚实。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "往旁边歪歪斜斜的迈出一步，却恰"
                                            "好令$N" HIW "的攻击失之毫厘。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$N" HIW "这一招来的好快，然后$n"
                                            HIW "一闪，似乎不费半点力气，却将$N"
                                            HIW "这一招刚好避开。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$n" HIW "轻轻一跃，已不见了踪影，$N"
                                            HIW "心中大骇，却又见$n" HIW "擦肩奔过，"
                                            "当真令人思索菲仪。\n" NOR]);
                        break;
                }
                return result;
     
   } 
}
void skill_improved(object me)
{
	if (me->query_skill("tiandao-dunyi",1)%30==0) {
		tell_object(me, HIW "由於你勤练武艺，你的"+HIY"【后天身法】"+NOR+"提高了。"NOR"\n");
	}
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("tiandao-dunyi", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 30;
        if (lvl < 150) return 50;
        if (lvl < 200) return 80;
        if (lvl < 250) return 100;
        if (lvl < 300) return 120;
        if (lvl < 350) return 140;
        return 150;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 70)
                return notify_fail("你的体力太差了，难以练习天道遁一。\n");

        if ((int)me->query("neili") < 70)
                return notify_fail("你的内力不够了，无法练习天道遁一。\n");

        me->receive_damage("qi", 65);
        me->add("neili", -65);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tiandao-dunyi/" + action;
}