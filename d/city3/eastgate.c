// Room: eastgate.c
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "东门");
	set("long", @LONG
这是成都东城门，城门正上方刻着“东门”两个楷书大字，城墙
上贴着几张官府告示(gaoshi)。一条笔直的青石板大道向东西两边延
伸。东边是郊外，一片平平展展的平原风光，真是不愧天府之国的美
称。西边是城里。
LONG
	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"fuheqiaoe",
		"west"  : __DIR__"eastroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing"    : 2,
	]));
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n成都提督\n吴天德\n";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
