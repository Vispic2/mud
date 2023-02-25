// by ranger_游侠
// heishi.c

inherit ROOM;

void create()
{
	set("short", "垃圾场");
	set("long", "这里是垃圾场，一些不能轻易丢弃的东西可以在这里销毁，销毁之前请慎重考虑，避免损失。");
	set("exits", ([
		"south" : "/fuben/jlj/ljc",
		"northeast":__DIR__"guangchang",
	]));
	set("objects", ([
	]));
	set("no_fight","1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	setup();
}

void init()
{
	add_action("do_drop", "drop");
}

int do_drop(string arg)
{
	object ob,me = this_player();
	if(ob=present(arg,me))
	{
		tell_object(me,"你将"+ob->short()+"丢进了垃圾场。\n");
		
		destruct(ob);
	}
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
