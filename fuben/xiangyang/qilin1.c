//by 秦始皇 qsh ednpc tools.
// xiaolu.c

#include <ansi.h>
inherit ROOM;
int exitss(object me);
void create()
{
	set("short",HIC"玄武门外"NOR);
	set("qilin",1);
		set("exits", ([
		"east" : __DIR__"xiaolu",
	]));
	set("objects", ([
				//"/d/aaa/npc/qilin" :4,
	]));
		set("action_list", ([
		""HIR"退出守卫襄阳"NOR :"exits",
	]));
	set("long","");
	setup();
}

void init()
{
	add_action("exitss","exits");
}

int exitss(object me)
{
me=this_player();
me->move("/d/xiangyang/northgate2");
me->start_busy(5);
write("退出守卫襄阳了，周围的蒙古兵大喊了一声逃兵！\n");
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
