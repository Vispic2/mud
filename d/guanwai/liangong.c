// liangong.c 练功房

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，屋中立着一些练武者常用的木人。东面似乎还有
一间房子。
LONG );
	set("exits", ([
		"east" : __DIR__"liangonge",
		"west" : __DIR__"houyuan",
		"south": __DIR__"liangongs",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 4
	]));
	set("for_family", "关外胡家");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
