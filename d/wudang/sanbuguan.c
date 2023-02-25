//Room: sanbuguan.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "三不管");
	set("long", @LONG
这里是四川、湖北与陕西的交界，俗称三不管。小土路的两旁有疏疏落落
的农舍耕田，几只牛羊正在吃草。路上行人很少，都匆匆赶路。
LONG);
	set("outdoors", "wudang");
	set("exits", ([
	    "east"      : __DIR__"wdroad8",
	    "southeast" : __DIR__"wdroad9",
	    "southwest" : "/d/emei/wdroad",
	]));
	set("objects", ([
		__DIR__"npc/cow": 1,
	]));
//	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
