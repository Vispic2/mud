//room: liangong3.c

inherit ROOM;

void create()
{
  set("short","戏凤阁三楼");
  set("long",@LONG
这里是三楼，人比楼下的少多了，只听见楼下隐隐约约的传来阵阵娇咤，
不那么真切。
LONG );
  set("exits",([
      "down" : __DIR__"liangong2",
  ]));
  set("objects",([
      "/clone/npc/mu-ren" : 3
  ]));
  set("for_family", "灵鹫宫");
  setup();
  replace_program(ROOM);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
