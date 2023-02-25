// room2.c

inherit ROOM;

void create()
{
	set("short","练功室");
	set("long",
		"这里是白驼山弟子的练功室。有几个制作精致的木人陪你练功。\n"
	);
	set("exits",([
		"out" : __DIR__"fang",
	]));
	set("for_family", "欧阳世家");

	set("objects",([
		"/clone/npc/mu-ren" : 4,
	]));

	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
