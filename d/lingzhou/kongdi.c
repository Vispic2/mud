// Room: /lingzhou/kongdi.c

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "林中空地");
	set("long", @LONG
这是山谷中的一大块空地，错落有致的分布着数十幢木屋，炊烟袅
袅的飘荡在上空，几个小孩正在追逐嬉闹，两条大狗没精打采的趴在屋
檐下晒太阳，周围山坡上同样是巨木参天，看上去这里就象一个气氛祥
和的小村。靠北的空地上有座大木屋看上去有点引人注目。西北和东北
各有一条山路。
LONG );
	set("exits", ([
		"east"     : __DIR__"dawu",
		"south" : __DIR__"tulu",
		"north" : __DIR__"qingxinquan", 
	]));
	set("objects", ([
		__DIR__"npc/nan" : 1,
		"/d/city/npc/wolfdog" : 2,
	]));
	set("outdoors", "lingzhou");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
