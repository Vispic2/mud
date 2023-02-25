// Room: /guiyun/liangong.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是归云庄陆少庄主的练功房。由与陆少庄主乃少林旁支仙
霞派出身，所以房中布置尽是为习练外门硬功之用，竖立着不少木
桩和草靶。西边角上还有两个大沙坑，天花板上吊着一支大沙袋。
LONG );

	set("exits", ([
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 3,
	]));
	set("for_family", "桃花岛");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
