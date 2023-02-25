// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW"雪山之巅"NOR);
	set("long", @LONG
这是独臂雪人的领地雪山之巅，四周弥漫着邪恶的气息，一股股恶臭传来。
LONG );
	set("objects", ([
		"/fuben/npc/xueren" : 1,
	]));
	set("outdoors", "city");
		set("action_list",([
		HIR"退出挑战"NOR:"quits",
	
	]));
        setup();
}
void init()
{
	add_action("do_quit","quits");

}
int do_quit()
{
object me;
me = this_player();
me->move("/d/city/guangchang");
write("退出成功\n");
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
