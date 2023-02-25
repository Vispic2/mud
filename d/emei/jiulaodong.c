//Room: jiulaodong.c 九老洞
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short", "九老洞");
      set("long", @LONG
这就是峨嵋第一大洞，洞内深窈无比，神秘难测。你一走进来，便发觉洞
中叉洞多如迷宫，怪异莫测，似乎黝黑无底。还是快快离开吧。
LONG);
      set("objects", ([
	   __DIR__"npc/bat" : 4,
      ]));
      set("exits", ([ /* sizeof() == 1 */
	  "out"     : __DIR__"jldongkou",
	  "north"   : __DIR__"jldongnei",
	  "south"   : __DIR__"jldongnei",
	  "east"    : __DIR__"jldongnei",
	  "west"    : __DIR__"jldongnei",
      ]));
      setup();
      replace_program(ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
