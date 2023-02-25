
// Room: nanheqiaos.c
inherit ROOM;
void create()
{
	set("short","南河桥");
	set("long",@LONG
这里是成都南门外南河桥。府河和南河夹城流过，成为天然的护
城河，滋润着这个天府之国的川中首府。向北就进城了，向南又是一
条小路。
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : "/d/xuedao/sroad1",
	    "north"  : __DIR__"southgate",
	    "east"  : __DIR__"lingyundamen",
	    
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
