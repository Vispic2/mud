#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + RED "圣火令" NOR, ({ "shenghuo ling", "shenghuo", "ling" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 8000);
                set("material", "steel");
                set("treasure", 1);
                set("long", NOR + RED "
这是一柄两尺来长的黑牌，看上去非金非铁，但质地却是坚硬
无比。整个令牌竟有若透明，令中隐隐似有火焰飞腾，实则是
令质映光，颜色变幻。令上刻得有不少波斯文，所记似乎和武
学有关，内容深奥，看来需要仔细研读一番才能够领悟。\n" NOR);
                set("wield_msg", HIR "$N" HIR "从腰间抽出一片黑黝的"
                                 "铁牌握在手中。\n" NOR);
                set("unwield_msg", HIR "$N" HIR "单手一抖，已将圣火"
                                 "令插回了腰间。\n" NOR);

        }
        init_sword(880);
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
