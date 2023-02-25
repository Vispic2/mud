#include <room.h>
inherit ROOM;

void create()
{
	set("short", "文　庙");
	set("long", @LONG
这里是文庙正殿，内有孔夫子像。历代皇帝都懂得利用儒教思想来巩固
自己的江山社稷，当朝皇帝自然也不例外。不论何人到此，都毕恭毕敬地上
香礼拜。
LONG );
	set("exits", ([
		"south" : __DIR__"dong_3",
		"up" : __DIR__"wenmiao2",	
	]));

	set("objects", ([
		__DIR__"npc/shusheng1" : 2,
		__DIR__"npc/shusheng2" : 1,
	]));

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
