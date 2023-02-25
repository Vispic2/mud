// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{
  set_name(HIB "蔷薇花" NOR, ({ "rose", "flower"}));
  set_weight(100);
  set("long","一朵娇艳的蔷薇花，散发着一丝丝甜香。\n");
  set("unit", "朵");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("material", "flower");
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "rose" &&  arg != "flower" )
    return 0;
  msg = "$N戴上一朵"+name+"，不禁想起年少时曾经的梦中人。\n"; 
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg != "rose")
    return 0;

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg!= "rose")
    return 0;

  msg = "$N将"+name+"捧起闻了闻，又惦记起昨天的故人。\n"; 
  message_vision (msg,me);
  return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
