//Room: fsanzhaitang.c 福寿庵斋堂
//Date: Oct. 2 1997 by That
#include <room.h>
inherit ROOM;

void create()
{
      set("short","福寿庵斋堂");
      set("long",@LONG
这里便是峨嵋福寿庵的斋堂。福寿庵本不大，但由于经常接待其他庵的弟子，
斋堂倒也不小。只见厅内摆满了长长的餐桌和长凳，几位小师太正来回忙碌着布置
素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。
LONG);
      set("exits",([ 
	  "east"    : __DIR__"lingwenge",
	  "northup" : __DIR__"fsaxiuxishi",
      ]));
     // set("outdoors", "emei");
      setup();
      replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
