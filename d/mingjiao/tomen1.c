// Room: /d/mingjiao/tomen1.c
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "青石阶");
    set("long", @LONG
石级到这里似乎变得宽阔了些。清新的山风扑面而来，令人
精神顿为一爽。远处传来淙淙水声，渐行渐远。山壁上挂满了厚
密的藤萝，随风轻轻摇弋。
LONG );
    set("exits", ([
	"west" : __DIR__"shanmen",
	"east" : __DIR__"tomen2",
    ]));
    set("outdoors", "mingjiao");
    set("no_clean_up", 0);
    setup();
    //replace_program(ROOM);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
