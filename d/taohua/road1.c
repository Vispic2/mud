inherit ROOM;
 
void create()
{
	set("short", "小路");
	set("long",@LONG
这是一条小径，弯弯曲曲向远方延伸。小径两边种植了一些桃花树。
你只一瞥就发现：这些桃花全是白色的。
LONG );
	set("exits", ([
	    "east" : __DIR__"road2",
	    "west" : __DIR__"damen",
	]));
	set("outdoors", "taohua");
	set("no_clean_up", 0);
	setup();
       }

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
