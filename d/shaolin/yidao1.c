// Room: /d/shaolin/yidao1.c
inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
一条尘土飞扬的大驿道。四周人来人往。挑担子的
行商，赶着大车的马夫，上京赶考的书生，熙熙攘攘，非常热闹。
不时还有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。
LONG );
	set("exits", ([
		"south" : __DIR__"yidao",
		"north" : __DIR__"yidao2",
	]));
	set("outdoors", "nanyang");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
