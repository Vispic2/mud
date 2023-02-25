#include <room.h>

inherit ROOM;

void create()
{
    set("short", "前院");
    set("long", @LONG
你现在正站在一个宽敞的院子中。院子原来是作为练武场用
的。但自从桃花岛弟子被黄药师逐出岛外，就已经没人在此练武。
东面是兵器室，西面是厨房，往南就是桃花山庄正厅了。
LONG );
    set("exits", ([
	"north" : __DIR__"damen",
	"south" : __DIR__"dating",
	"east"  : __DIR__"bingqi",
	"west"  : __DIR__"chufang",
    ]));
    set("outdoors", "taohua");
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
