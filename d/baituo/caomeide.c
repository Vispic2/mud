//ROOM caomeide.c
inherit ROOM;
void create()
{
	set("short","草莓地");
	set("long",
	     "这里是一块草莓地，鲜红的草莓散落在绿草中，让人感到美妙惬意。\n"
	);
	set("exits", ([
		"northeast" : __DIR__"shulin1",
	]));
	set("objects" , ([
	     __DIR__"obj/caomei" : random(7),
	]));
//	set("no_clean_up", 0);
	set("outdoors","baituo");
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
