//ROOM: /d/yanziwu/qingzong.c

inherit ROOM;
void create()
{
	set("short", "青冢");
	set("long",@LONG
你在竹林中七绕八绕，忽然豁然开朗，原来到了慕容世家的墓地，
据说燕子坞的主人就葬于此了。地上长满了细的小草，传说这种草常年
碧绿，永不枯萎。似乎除了向南有一片竹林外别无出口。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"south" : __DIR__"zhulin3",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
