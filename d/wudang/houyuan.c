// houyuan.c 后院
// by Xiang

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是后院，北面是三清殿，南面是一个圆形的门洞，有一条小路通往
后山。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaolu1",
		"north" : __DIR__"sanqingdian",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/yu" : 1
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
