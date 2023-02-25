// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIM"沼泽之地"NOR);
	set("long", @LONG
栖息于黄山沼泽之中的种怪兽。它形如巨晰，口中能喷出毒泥毒沙，被射中的人会即刻晕倒，它又可利用口中强大吸力，把人吸入沼泽之内。
LONG );
	set("objects", ([
		"/fuben/npc/sheyinglong" : 1,
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
