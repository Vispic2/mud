// Room: /qingcheng/songfengguan.c

inherit ROOM;
void create()
{
	set("short", "松风观");
	set("long", @LONG
这里是松风观，是青城派总所。青城派威镇川中，以其人才辈
出之故。当今掌门人余沧海道长，虽其貌不扬，身形矮小，却是青
城一代宗师。观中陈设奢华，显见青城派财力不菲。
LONG );
	set("exits", ([
		"north" : __DIR__"shangqing",
	]));
	set("objects", ([
		__DIR__"npc/hai" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
