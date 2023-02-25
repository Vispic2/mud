// Room: caotang.c
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "杜甫草堂");
	set("long", @LONG
这里是杜甫流寓成都的故居。草堂里流水回萦，小桥勾连，竹树
掩映，显得既庄严肃穆，古朴典雅，又不失幽深静谧，秀丽清朗。
LONG );
	set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"path2",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
