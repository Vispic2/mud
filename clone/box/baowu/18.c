#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "幻灵剑" NOR, ({ "huanling jian", "huanling", "sword" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "剑身优美细长，散发着淡青银光。\n" NOR);
                set("unit", "柄");
                set("value", 7000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "银光划过，幻灵剑已落入$N" HIW "手中。\n" NOR);

                set("unwield_msg", HIW "天地忽暗，$N" HIW "手中的幻灵剑已悄然隐没 。\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;


        if (random(5) == 1)
        {
               n = me->query_skill("sword");
               victim->receive_damage("qi", n * 3 / 5);
               victim->receive_wound("qi", n * 2 / 7);
               return HIW "$N" HIW "一声冷哼，手中幻灵剑犹如灵蛇一般游走不定，霎时一道剑气至剑尖激"
                      "射而出，贯向$n" HIW "！\n" NOR;
        }
        return damage_bonus;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
