
#include <room.h>

inherit ROOM;
void create()
{
	set("short", HIR"试炼之地"NOR);
	set("long", @LONG
	这里是神兽试炼之地。
LONG );
	set("exits", ([
		"south":__DIR__"ruko",
	]));
	set("objects", ([
	]));
	setup();
}

void heart_beat()
{
	object *inv;
	inv = all_inventory(this_object());
	if(!sizeof(inv)||(sizeof(inv)==1&&!playerp(inv[0])))
	{
		set_heart_beat(0);
		destruct(this_object());
	}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
