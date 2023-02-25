//Room: sheshenya.c 舍身崖
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","舍身崖");
      set("long",@LONG
这是一处险峻的悬崖峭壁，相传真武帝在此舍身得道。崖上立有铁栅栏，
防止有人自杀步真武帝的后尘。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "east"     : __DIR__"nanyanfeng",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
