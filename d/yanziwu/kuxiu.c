//ROOM: /d/yanziwu/kuxiu.c

inherit ROOM;

void create()
{
	set("short", "苦修场");
	set("long",@LONG
这里的场地有些破落，虽然经常打扫，但是场地仍然看得出不少痕
迹。希望出人头地的慕容家弟子在武功有了一定的修为以后往往到这里
来作进一步的修行。场地中间有一些铁作的练功人，剽悍异常。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west" : __DIR__"shijian",
		"east": __DIR__"kuxiu2",
	]));

	set("objects", ([
		"/clone/npc/tie-ren" : 4,
	]));

	set("for_family", "慕容世家");
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
