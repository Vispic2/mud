#include <room.h>
inherit ROOM;

void create()
{
	set("short", "文庙三楼");
	set("long", @LONG
这里是文庙正殿，内有孔夫子像。历代皇帝都懂得利用儒教思想来巩固
自己的江山社稷，当朝皇帝自然也不例外。不论何人到此，都毕恭毕敬地上
香礼拜。
LONG );
	set("exits", ([
		"down" : __DIR__"wenmiao2",
	]));

	set("objects", ([
		"/d/beijing/npc/wangym" : 1,
	]));

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
