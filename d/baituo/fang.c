//fang.c
inherit ROOM;
void create()
{
	set("short","练功房");
	set("long",
		"这里是白驼山弟子的练功房。里面有几个单间，是练功室。\n"
		"第子们在里边砌磋武艺，绝对不允许外人打搅。\n"
	);
	set("exits",([
		"west" : __DIR__"liangong",
		"1" : __DIR__"room1",
		"2" : __DIR__"room2",
		"3" : __DIR__"room3",
     
	]));

	set("objects",([
		__DIR__"npc/trainer" : 1,
	]));

	setup();

}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
