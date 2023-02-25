//room: menlang.c
inherit ROOM;

void create()
{
  set("short","门廊");
  set("long",
      "这是个门廊，门廊的飞檐上挂着一串串的小铜铃，\n"
  "在清风中发出清脆动听的铃声。\n"
      );
  set("exits",([
      "north" : __DIR__"huayuan",
      "south" : __DIR__"liangong",
     ]));
  set("objects",([
    __DIR__"npc/guanjia" : 1,
    ]));
// set("no_clean_up", 0);
 set("outdoors","baituo");
 setup();
 replace_program(ROOM);
}







/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
