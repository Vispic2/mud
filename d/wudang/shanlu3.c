//Room: shanlu3.c 山路
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","山路");
      set("long",@LONG
你走在登山的路径上，路的左右各有一条大铁链，象两条长蛇向山上山
下蜿蜒爬去。满眼是乔木夹道，如行于绿幕中。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "west"     : __DIR__"shanlu2",
	  "southup"  : __DIR__"shanlu4",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
