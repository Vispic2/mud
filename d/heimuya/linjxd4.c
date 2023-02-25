// ROOM : linjxd4.c
inherit ROOM;
void create()
{
  set("short","林间小道");
  set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵
阵风吹过树梢，发出沙沙的响声，令你不寒而栗。
LONG );
  set("exits",([
      "south" : __DIR__"linjxd6",
      "north" : __DIR__"linjxd1",     
      "east"  : __DIR__"linjxd2",
      "west"  : __DIR__"linjxd5",
  ]));
  set("no_clean_up", 0);
  setup();
  //replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
