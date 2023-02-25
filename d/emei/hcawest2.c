//Room: hcawest2.c 华藏庵西廊
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","华藏庵西廊");
      set("long",@LONG
这里是峨嵋华藏庵西廊。走廊往南禅房，北边通往广场。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "south" : __DIR__"hcachanfang",
	  "north" : __DIR__"hcawest1", 
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
