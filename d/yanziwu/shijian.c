//ROOM: /d/yanziwu/shijian.c

inherit ROOM;

void create()
{
	set("short", "试剑台");
	set("long",@LONG
玉石栏杆围成的一座石台，慕容世家的弟子经常在此练习武技，台
角放着刀枪剑戟等十八般兵器。 场中立着一些制作极为精妙的木人。
东边则是慕容家弟子苦心修行的地方。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"south"  : __DIR__"changlang",
		"east"   : __DIR__"kuxiu",
	]));

	set("objects", ([
		"/clone/npc/mu-ren" : 4,
		"/clone/weapon/zhubang.c" : 1,
		"/clone/weapon/mudao.c"   : 1,
		"/clone/weapon/zhujian.c" : 1,
		"/clone/weapon/bian.c"    : 1,
	]));
	set("for_family", "慕容世家");

	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
