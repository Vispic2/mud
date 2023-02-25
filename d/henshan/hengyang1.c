// Room: /d/henshan/hengyang1.c
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "衡阳西街");
	set("long", @LONG
你走在碎石铺就的狭小街道上。街上时常有人持剑疾行，似乎这里
出了啥事了。南边是一家小店，北面一座大宇巍峨，重檐叠瓦，门口彩
灯高悬，管家家丁好象都是武林中人。
LONG );
	set("outdoors", "hengyang");
	set("exits", ([
		"east"   : __DIR__"hengyang",
		"west"   : __DIR__"hsroad4",
		"south"  : __DIR__"shop",
		"north"  : __DIR__"liufugate",
		"southwest" : __DIR__"majiu",
	]));

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
