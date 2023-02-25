//Room: /d/dali/luwang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","鲁望镇");
	set("long",@LONG
这里是普麽部的鲁望镇，普麽部属台夷，领属还有附近的越州。
这是一座建在山坡上的小镇，东面和北面是高耸的群山，向西和南眺
望均可见村庄和城镇。
LONG);
	set("objects", ([
	   __DIR__"npc/tshangfan": 1,
	   "/clone/npc/walker" : 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "west"    : __DIR__"feilihu",
	    "east"    : __DIR__"yulin",
	    "south"   : __DIR__"shuitian",
	    "north"   : __DIR__"zhulou3",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
