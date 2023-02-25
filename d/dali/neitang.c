//Room: /d/dali/neitang.c
inherit ROOM;
void create()
{
	set("short","内堂");
	set("long",@LONG
这里是镇南王府的内堂。十分宽阔明亮。正面墙上挂着一幅水墨
画，两边各有一个窗子，透过窗户可以看见外面的青山绿水。
LONG);
	set("objects", ([
	    CLASS_D("duan")+"/duanzc": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"yongdao2",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
