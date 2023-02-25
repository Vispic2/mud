// Room: northgate.c

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "北城门");
	set("long", @LONG
这是成都北城门，城门正上方刻着“北门”两个楷书大字，城墙
上贴着几张官府告示(gaoshi)。一条笔直的青石板大道向北延伸。北
边望去，一片绿油油的田野夹着随风摇曳的高树，长竹。城门边两行
官兵仔细盘查进出人等。
LONG
	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"south"  : __DIR__"northroad2",
		"north"  : __DIR__"fuheqiaon",
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
