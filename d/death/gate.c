// gate.c

#include <ansi.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "鬼门关" );
	set("long", 
		"这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n"
		"黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n"
		"回阳间了。\n");
	set("exits", ([
		"north" : "/d/death/gateway",
	]) );
	set("objects", ([
		__DIR__"npc/wgargoyle":1,
		__DIR__"npc/bgargoyle": 1,
	]) );

	set("no_fight", 1);
	set("no_sleep_room", 1);

	setup();
}
void init()
{
	if (!wizardp(this_player()))
	{
		this_player()->set("startroom", "/d/death/gate");
		add_action("discmds",({"walk","zdsm","use","eat","fly"}));
	}
}
int discmds()
{
	tell_object(this_player(),"在这里不能使用此命令！！！\n");
	return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
