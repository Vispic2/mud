// shimen.c

inherit ROOM;

void create()
{
	set("short", "石门");
	set("long", @LONG
得到一道大石门前，只见两旁刻着两行大字，右首是“文成
武德”，左首是“仁义英明”，横额上刻着“日月光明”四个大
红字。
LONG    );
	set("outdoors", "heimuya");
	set("objects", ([
	    __DIR__"npc/zhang2" : 1,
	]));
	set("exits", ([
	    "eastdown" : __DIR__"shijie2",
	    "westup"   : __DIR__"up1",
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
