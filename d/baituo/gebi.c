//gebi

inherit ROOM;

void create()
{
	set("short", "戈壁");
	set("long", @LONG
这里是临近沙漠的戈壁滩，荒无人烟。东边是一望无际的大沙漠，
西北方可以看见一座小镇。
LONG
	);
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : "/d/xingxiu/shamo10",
		"northwest" : __DIR__"dongjie",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
