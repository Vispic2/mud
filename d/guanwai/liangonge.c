// liangonge.c 练功房

inherit ROOM;

void create()
{
	set("short", "东练功房");
	set("long", @LONG
这里是东面的练功房，屋中立着一些练武者常用的木人。
LONG );
	set("exits", ([
		"west" : __DIR__"liangong",
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
