//      tiantai.c 天台
inherit ROOM;

void create()
{
	set("short", "天台");
	set("long", @LONG
这里是雪山寺的高处。北边可见雄伟的大雪山，南边
可以俯瞰美丽如镜的圣湖。
LONG );
	set("exits", ([
		"west" : __DIR__"neidian",
	]));
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
