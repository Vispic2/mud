// by happ@YSZZ

#include <armor.h>

inherit CLOTH;
#include "chk_owner.c"

void create()
{
   set_name("黄金圣衣", ({ "huangjin shengyi" }) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("no_give",1);
     set("value",2000000);
     set("material", "steel");
     set("armor_prop/armor",1200);
  }
   setup();
}
int query_autoload() { return 1; }

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
