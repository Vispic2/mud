// by happ@YSZZ

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
#include "chk_owner.c"

void create()
{
   set_name(HIY"黄金圣衣"NOR, ({ "huangjin shengyi" }) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("no_get",1);
      set("no_sell",1);
       set("value",0);
     set("material", "steel");
     set("armor_prop/armor",1200);
  }
   setup();
}
int query_autoload() { return 1; }

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
