//by 游侠 ranger's ednpc tools.
// wizard.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"公共"HIR"闭关室"NOR);
	set("long","这里是公共闭关室，可以挂机............");
	set("no_fight", 1);
	set("exits", ([
		"west" : "/d/city/kedian",
	]));
	set("gg_bgs", 1);
	setup();
}

void init()
{
	add_action("discmds",({"kill"}));
}
int discmds()
{
	tell_object(this_player(),"在这里不能使用此命令！\n");
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
