#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(NOR + CYN "屠龙刀" NOR, ({ "tulong dao", "tulong", "dao", "blade" }) );
        set_weight(32000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + CYN "这便是号称武林至尊的屠龙宝刀，四尺来长"
                            "的单刀，竟达一百多斤之重。\n相传其中藏有旷世的大"
                            "秘密。\n" NOR);
                set("unit", "柄");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "一声狂笑，从背后抽出那柄号称「"
                                 HIR "武林至尊" HIY "」的屠龙宝刀高高举起。\n" NOR);
                set("unwield_msg", HIY "$N" HIY "哈哈一笑，将屠龙宝刀插回背后。\n" NOR);
                set("stable", 100);
        }
        init_blade(800+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
if (random(5)==0)
{
        victim->receive_damage("jing", me->query("str") * 2);
        victim->receive_wound("jing", me->query("str") * 2);
        return HIM "屠龙刀夹带着刺耳的破空声划出一道道长虹，霎时间$n"
               HIM "只感到心神意乱。\n" NOR;
}
        return damage_bonus;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
