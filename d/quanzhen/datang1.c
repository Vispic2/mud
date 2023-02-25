// datang1.c 大堂一进
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大堂一进");
	set("long", @LONG
这里是大堂，是全真教接待客人的地方。堂很大，几十张桌椅一
字排开也丝毫不显拥挤。地下铺着整齐的青砖，几名道童正忙前忙后
地端茶送水招呼客人。
LONG
	);
	set("exits", ([
		"east" : __DIR__"datang2",
		"west" : __DIR__"damen",
		"north" : __DIR__"huizhentang",
		"south" : __DIR__"xianzhentang",
	]));
	set("objects",([
		__DIR__"npc/daotong" : 1 + random(3),
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
