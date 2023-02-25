//Room: slxl1.c 松林小路
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","松林小路");
      set("long",@LONG
这是山脚松林中的小路，两边长满参天的红松树，只能看见一线天空。
路旁有道士在奋力砍树。西边通向武当山门，东边可通往解剑岩。
LONG);
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
	  "west"      : __DIR__"xuanyuegate",
	  "eastdown"  : __DIR__"jiejianyan",
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
