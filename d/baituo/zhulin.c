//zhulin.c
inherit ROOM;
void create()
{
	set("short","竹林");
	set("long",
		"这里是青竹林，常有蛇出没。南边是蒿草丛。北边有一个大岩洞。\n"
	);

	set("exits",([
		"northup" : __DIR__"cave",
		"south" : __DIR__"cao2",
	]));

	set("objects",([
		"/clone/beast/qingshe" : random(3),
		"/clone/beast/dushe" : random(2),
	]));

	set("resource/snake", ({ "/clone/beast/jinshe",
				 "/clone/beast/dushe",
				 "/clone/beast/qingshe", }));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
