// ROOM : biguan.c
inherit ROOM;
void create()
{
  set("short","闭关室");
  set("long",@LONG
这是当年天山童姥闭关修练的地方。
LONG );
  set("sleep_room", 1);
  set("exits",([
      "south" : __DIR__"men3",
  ]));
  setup();
  replace_program(ROOM);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
