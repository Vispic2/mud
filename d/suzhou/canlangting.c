// Room: /d/suzhou/canlangting.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "沧浪亭");
	set("long", @LONG
沧浪亭在苏州的北大街南侧，因为环境相对幽雅，使得男
女老少都喜爱在这里闲庭散步。在亭中放眼望去，四周一片碧
绿的草坪，亭子翼然于耸翠之中，飞檐凌空琵琶形牌科，布满
檐口四周，亭上的额匾和石柱上的楹联(lian)使人更加喜爱这
里。
LONG );
	set("outdoors", "suzhou");
	set("item_desc", ([
		"lian" :
"清风明月本无价 近水远山皆有情\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"dongdajie1",
		"southwest" : __DIR__"xidajie1",
		"north"     : __DIR__"beidajie1",
		"south"     : __DIR__"baodaiqiao",
	]));
	set("objects", ([
		"/adm/npc/hongniang" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
