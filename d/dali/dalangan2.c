//Room: /d/dali/dalangan2.c
inherit ROOM;
void create()
{
	set("short","杆栏中层");
	set("long",@LONG
这个杆栏的中层面积颇大，宽敞开阔。正中的香案古色古香，贡
着的神像雕制精细，显得与众不同，大盘的贡品正飘出香味，尤其当
中的一个羊头特别抢眼。看来这里是本村的祭祀所。
LONG);
	set("objects", ([
	   __DIR__"npc/jisi1": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"dalangan1",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
