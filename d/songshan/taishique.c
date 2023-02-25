
// Room: /d/songshan/taishique.c
inherit ROOM;

void create()
{
	set("short", "太室阙");
	set("long", @LONG
嵩山古称方外，又称崇山，为五岳中的中岳，由太室少室二山沿
绵而成。汉武帝时称 "嵩高" ，取自诗经 "嵩岳维高，峻极于天" ，
道教以之为第六小洞天。阕高丈余，南面刻 "中岳太室阳城" 六字，
篆文古朴，苍劲有力。向西就是去少室山少林寺的路，北走一里许便
是中岳庙了，南面有一小屋。
LONG );
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"east"  : "/d/shaolin/ruzhou",
		"west"  : "/d/shaolin/shijie1",
		"south" : "/d/shaolin/maowu",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/yao" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
