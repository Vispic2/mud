//shanlu.c
inherit ROOM;

void create()
{
  set("short","山路");
  set("long","这里是山上的泥路。\n");
  set("exits",([
      "northwest" : __DIR__"shanlu1",
      "southeast" : __DIR__"guangchang",
     ]));
  set("outdoors", "baituo");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
