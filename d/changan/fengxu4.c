//Room: fengxu4.c

inherit ROOM;

void create ()
{
	set ("short", "冯诩道");
	set ("long", @LONG
冯诩道是长安城中心大街，青石板路笔直的伸展出去，一路上行人
比肩，笙歌处处。景物之美，直如神仙境地。东面是凌烟阁。
LONG);
	set("exits", 
	([ //sizeof() == 3
		"north" : __DIR__"fengxu3",
		"south" : __DIR__"fengxu5",
		"east" : __DIR__"lingyange",
	]));

	set("outdoors", "changan");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
