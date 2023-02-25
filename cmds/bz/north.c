
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "北部资源");
	set("long", @LONG
这里是北部资源点，如果活动开始并且你的帮派报名了，你在此即可为自己帮派增加资源点！
LONG );
	set("outdoors", "city");
	set("exits", ([
	 	"south" : "/cmds/bz/zhong",	 
	 	//"south" : "/cmds/bz/south",		
	 	//"west" : "/cmds/bz/west",	
	 	//"east" : "/cmds/bz/east",	
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
