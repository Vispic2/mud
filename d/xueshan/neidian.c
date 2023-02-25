//      neidian.c 内殿
inherit ROOM;

void create()
{
	set("short", "内殿");
	set("long", @LONG
这里是雪山寺的内殿，也是掌门人见客的地方。雪山
寺的掌门人、大轮明王、吐蕃国师鸠摩智是西域一代高僧，
也是西域不世出的武林宗师。他驻锡本寺后，雪山寺方声
名远播。
LONG );
	set("exits", ([
		"east" : __DIR__"tiantai",
		"west" : __DIR__"midao",
		"south" : __DIR__"zoulang3",
		"north" : __DIR__"houdian",
	]));

	set("objects", ([
		CLASS_D("xueshan")+"/jiumozhi" : 1
	]));

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
