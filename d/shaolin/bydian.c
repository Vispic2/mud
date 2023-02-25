// Room: /d/shaolin/bydian.c
inherit ROOM;

void create()
{
	set("short", "白衣殿");
	set("long", @LONG
这是白衣殿，供奉白衣观音大士。大士高居须弥座上，手托
净瓶，眉含微愁，唇绽浅笑，仿佛对人间疾苦既存忧心，又觉释
怀。殿中放了红木大香案，香案上供品齐备，香火十分旺盛。
LONG );
	set("exits", ([
		"west" : __DIR__"guangchang5",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
