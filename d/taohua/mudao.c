
inherit ROOM;

void create()
{
    set("short", "墓道");
    set("long",@LONG
这是通往墓室的通道。通道十分宽敞，顶部悬挂着一颗大大的夜明珠，照得
整个墓道如同白昼。墓道尽头便是墓室。
LONG);
	set("exits", ([
		"up"   : __DIR__"mudi",
		"down" : __DIR__"mushi",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
