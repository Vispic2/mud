
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("达摩棍", ({ "damo gun", "gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根桦木白腊棍，举可齐眉，轻重合宜，可攻击大片敌人。\n");
                set("value", 20000);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("shaolin",1);
        }
        init_club(300);
        setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
