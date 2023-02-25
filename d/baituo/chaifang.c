//room: caifang.c
inherit ROOM;

void create()
{
  set("short","柴房");
  set("long","这是间不宽的柴房，木柴已经快烧光了，墙角放着几把『柴刀』。\n");
  set("exits",([
      "west" : __DIR__"chufang",
  ]));
  set("objects",([
    __DIR__"npc/laocai" : 1,
  ]));
//  set("no_clean_up", 0);

 setup();
 replace_program(ROOM);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
