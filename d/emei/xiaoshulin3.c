//Room: xiaoshulin3.c 小树林
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","小树林");
      set("long",@LONG
这是峨嵋山金顶华藏庵外的一片小树林。林中没有路，但地上依稀有些足
迹，似乎刚有人走过。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
	  "southeast" : __DIR__"xiaoshulin4", 
	  "north"     : __DIR__"xiaoshulin2", 
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
