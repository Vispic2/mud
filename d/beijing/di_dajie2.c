#include <room.h>
inherit ROOM;

void create()
{
	set("short", "地安门大街");
	set("long", @LONG
这里是北京城的地安门大街。街道是整整齐齐的杨树林，道上行人络绎不
绝，车两马匹穿插其中。大街上由闲逛的游人，上京赶考的考生，背负着担子
的挑夫以及正在玩耍着的幼童构出了一幅繁忙热闹的盛世景象。北边过地安门
到达京城的城郊，南边是热闹的地安门广场。
LONG );
       set("exits", ([
		"north" : __DIR__"di_anmen",
		"south" : __DIR__"di_dajie1",
	]));
	set("objects", ([
		__DIR__"npc/dipi" : 1,
		__DIR__"npc/tiaofu" : 2,
	]));

	set("outdoors", "beijing");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
