//Room: bgschanfang.c 保国寺禅房
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","保国寺禅房");
      set("long",@LONG
这儿是保国寺内的一间禅房，布局简单，供寺内和尚诵经修行之用。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "east"    : __DIR__"dxdian",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
