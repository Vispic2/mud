//ROOM: chufang.c
inherit ROOM;

void create()
{
  set("short","藕香榭");
  set("long",@LONG
这是间厨房，浓郁的饭菜香味一个劲地钻进你的鼻子， 你仿佛听到
“咕咕”的响声，环顾四周不知来源。原来是你的肚子作怪。
LONG );
  set("exits",([
      "east" : __DIR__"changl6",
  ]));
  set("objects",([
      __DIR__"npc/lisao" : 1,
      __DIR__"obj/suanmei" : 2,
      __DIR__"obj/gao" : 2,  
  ]));
  set("resource/water", 1);
  setup();
  replace_program(ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
