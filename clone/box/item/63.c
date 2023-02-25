#include <weapon.h>
#include <armor.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(BLK"死刀"NOR, ({"si dao","blade"}) );
        set_weight(2000);
        set("long","一把形状奇特的短刀，血槽极粗，隐隐有一股死亡的气息透出。\n" NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",15000);
                set("cant_sell","你这把刀是谁给的？！小店可不敢收哇！\n");
                set("material", "steel");
                set("armor_prop/armor",20);
        }
        init_blade(400);
        set("wield_msg", "$N「唰」的一声抽出一把明晃晃的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插入腰间。\n");
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
