//      dadian.c 大殿
inherit ROOM;
void create()
{
	set("short", "大殿");
	set("long", @LONG
这里是雪山寺的大殿，中央供奉着佛祖塑像。僧人们
在念着经文。远来的香客们在这里虔诚地膜拜。大殿两侧
都是侧殿。
LONG );
	set("exits", ([
		"east"  : __DIR__"cedian1",
		"west"  : __DIR__"cedian2",
		"south" : __DIR__"guangchang",
	]));
	set("objects", ([
		CLASS_D("xueshan")+"/lazhang" : 1,
		__DIR__"npc/xiang-ke" : 2,
	]));
	set("valid_startroom", 1);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
