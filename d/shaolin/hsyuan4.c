// Room: /d/shaolin/hsyuan4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "和尚院四部");
	set("long", @LONG
这里是和尚院待客的地方，靠墙左右两侧摆着一溜太师椅。
墙角一几，放着几个茶壶。有个茶壶壶身上题了“碧螺春”三
个篆字，壶嘴热气腾腾，似乎是刚沏的新茶。一位小沙弥在一
边垂手站立。
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang3",
		"west" : __DIR__"zhulin4",
		"south" : __DIR__"zoulang6",
		"north" : __DIR__"hsyuan5",
	]));
	set("resource/water",1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-xu" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
