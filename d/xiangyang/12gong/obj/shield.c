#include <armor.h>
#include <ansi.h>

//inherit F_UNIQUE;
inherit SHIELD;
void create()
{
  set_name(HIY"战神之光"NOR, ({"zhanshen zhiguang","shield", "dun"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 1000);
   set("long", "这是传说中的战神阿雷斯所化成的盾。\n");
   set("material", "crimsonsteel");
   set("no_sell", 1);
   set("no_drop", 1);
   set("no_put", 1);
   set("armor_prop/armor", 80);
   set("armor_prop/dodge", -2);
  }
  setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
