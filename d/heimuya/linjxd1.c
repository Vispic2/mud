// ROOM : linjxd1.c
inherit ROOM;
void create()
{
  set("short","林间小道");
  set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵
阵风吹过树梢，发出沙沙的响声，令你不寒而栗。不过西边好象
是一个山谷。 
LONG );
  set("exits",([
      "south" : __DIR__"linjxd2",
      "north" : __DIR__"linjxd5",     
      "east"  : __DIR__"road1",
      "west"  : __DIR__"guang",
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
