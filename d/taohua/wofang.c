
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "卧房");
	set("long", @LONG
你走进了一间卧房。一股若有若无的甜香扑鼻而来。琴剑书画，
挂在墙上。锦笼纱罩，金彩珠光。小几上汝窑美人瓶内的桃花正自盛
开。右首一张床，床头放着五彩鸾纹被。
LONG );
    set("exits", ([
	"east" :__DIR__"dating",
    ]));
    set("objects", ([
	CLASS_D("taohua")+"/rong" : 1,
	__DIR__"npc/binu" : 2,
    ]) );
//    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
