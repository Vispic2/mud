//Room: milin1.c 密林
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","密林");
      set("long",@LONG
这是黑森森的一片密林，楠木参天，浓阴蔽日。这里东下二里是报国寺，
西边林间隐藏着一座庙宇。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "northeast"  : __DIR__"bgs",
	  "west"       : __DIR__"fhs",
      ]));
      set("outdoors", "emei");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
