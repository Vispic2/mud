#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIY "日月金轮" NOR, ({ "riyue jinlun", "riyue", "jinlun", "lun" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "金轮法王的随身兵器，乃是由金银铜铁锡五柄"
                            "法轮组成。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "将日月金轮高举在手中，空气"
                                 "中顿时沁出一股寒气。\n" NOR);
                set("unwield_msg", HIY "$N" HIY "一声冷笑，将日月金轮收回"
                                 "怀中。\n" NOR);
                set("stable", 100);
        }
        init_hammer(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(16))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("hammer") / 10 + 2);
                return HIY "霎时$N" HIY "手中日月金轮黄芒暴涨，气势如虹，$n"
                       HIY "不由得心中一紧，攻势顿时缓滞！\n" NOR;

        case 1:
                n = me->query_skill("hammer");
                victim->receive_damage("qi", n * 3 / 4);
                victim->receive_wound("qi", n * 3 / 4);
                return HIY "$N" HIY "一声嗔喝，手中日月金轮陡然化作五轮，从"
                       "五个不同的方位一齐袭向$n" HIY "！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
