//Roon: lianpath1.c 莲花峰小路
//Date: Oct. 2 1997 by Venus
inherit ROOM;

void create()
{
      set("short","莲花峰小路");
      set("long",@LONG
小路通往莲花峰，周围静静悄悄，微闻蝉鸣。四望密林幽谷，让人
胆寒。
LONG);
      set("outdoors", "xx");
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
	  "westup"   : __DIR__"lianpath2",
	  "northeast": __DIR__"zhenyue",
      ]));
      setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
