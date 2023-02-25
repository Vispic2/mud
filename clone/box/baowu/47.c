#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "淑女剑" NOR, ({ "shunv jian", "jian", "shunv", "sword" }));
        set_weight(4000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "这是一口遍体通黑的剑，剑身上用金丝锩着几个字：\n"
                            "窈窕淑女，君子好逑。\n" NOR);
                set("unit", "柄");
                set("value", 6000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIW "$N" HIW "一声清啸，一柄无尖无锋的宝剑已"
                                 "握在手中。\n" NOR);

                set("unwield_msg", HIW "$N" HIW "反转剑身，「唰」的一声，淑"
                                   "女剑已入鞘。\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(600+random(320));
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
