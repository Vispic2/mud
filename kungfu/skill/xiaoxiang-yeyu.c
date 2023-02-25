#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "tanqin-jifa"; }

int valid_learn(object me)
{
        if (me->query_skill("tanqin-jifa", 1) < 50)
                return notify_fail("你弹琴技法水平太差，无法领会潇湘夜雨。\n");

        if (me->query_skill("tanqin-jifa", 1) < me->query_skill("xiaoxiang-yeyu", 1))
                return notify_fail("你弹琴技法水平有限，无法领会更精妙的潇湘夜雨。\n");

        return 1;
}

int practice_skill(object me)
{
        object ob;

        if (! objectp(ob = me->query_temp("handing")) ||
            ! ob->valid_as_qin())
                return notify_fail("你不拿琴在手上，怎么练习？\n");

        if ((int)me->query("jing") < 80)
                return notify_fail("你的精神不够好，没法练习了。\n");

        if ((int)me->query("qi") < 30)
                return notify_fail("你现在口干舌燥，实在是太累了。\n");

        me->receive_damage("jing", 25);
        me->receive_damage("qi", 10);

        return 1;
}

void do_effect(object me)
{
        object *obs;
        int lvl;

        lvl = me->query_skill("tanqin-jifa", 1) / 2 +
              me->query_skill("xiaoxiang-yeyu", 1);

        if (lvl < 100)
                return;

        // special effort
        obs = all_inventory(environment(me)) - ({ me });
        obs->receive_heal("qi", random(lvl) + 20);
        message("vision", HIG "你听了" + me->name() + HIG "一曲潇湘夜雨，顿"
                          "觉神清气爽，内息渐渐缓和了下来。\n" NOR, obs);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
