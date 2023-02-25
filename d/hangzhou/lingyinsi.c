// lingyinsi.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "灵隐寺");
	set("long", @LONG
灵隐寺又名云林寺，寺前有清澈的小溪，溪旁建有冷泉亭和赫雷
亭。天王殿举目可见，殿外有两座经幢。往南便回到大道。
LONG);
	set("exits", ([
		"enter"     : __DIR__"tianwangdian",
		"south"     : __DIR__"road1",
	]));
	set("objects",([
	    __DIR__"npc/seng": 1,
	]));
	set("outdoors", "hangzhou");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
