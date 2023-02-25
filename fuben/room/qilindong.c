#include <ansi.h>
inherit ROOM;
#include <room.h>
void create()
{
	set("short",HIR"麒麟洞"NOR);
	set("long",HIR"这里是麒麟洞，输入指令：exit 即可退出战斗。"NOR);	
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
me->move(me->query("dizhi/qilin"));
me->set("exit/zd",1);
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
