#include <ansi.h>
inherit ROOM;
#include <room.h>
void create()
{
	set("short",HIR"战斗场景"NOR);
	set("long",HIR"这是一个战斗场景，输入指令：exit 即可退出战斗。"NOR);	
	setup();
}

void init()
{
	add_action("do_exit", "exit");
}

int do_exit(object me,string arg)
{
me = this_player();
write(HIG"退出了战斗场景\n"NOR);
me->move("/d/city/kedian");
me->set("exit/zd",1);
return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
