// Room: /city/kongzhong.c

inherit ROOM;
void create()
{
	set("short", "空中");
	set("long", @LONG
这是万丈高空，周围飘浮着几朵白云。
偶尔飞过几只白雕。
LONG
	);
	set("outdoors", "city");
/*
	set("objects", ([
		CLASS_D("ouyang") + "/ouyangke" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west"  : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
*/
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
