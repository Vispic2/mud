//xiaolu4

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long",
	     "这里是一条上山的小路向西分出一条岔道。北边是山贼的老窝。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 1,
	]));

	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
