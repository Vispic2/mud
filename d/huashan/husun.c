// husun.c

inherit ROOM;

void create()
{
	set("short", "猢狲愁");
	set("long", @LONG
前面又是一处十分陡峭的山岭，上面有四只铁猿，盘踞台畔，据说以
前从华山水帘洞出来的猿猴，每到这里就要返回去，连它们也感到难于超
越，此岭因而得名。
LONG );
	set("exits", ([ /* sizeof() == 2 */
	    "northdown" : __DIR__"laojun",
	    "southup"   : __DIR__"shangtianti",
	]));
	set("objects", ([ /* sizeof() == 2 */
	    "/d/wudang/npc/monkey": 1,
	    "/d/wudang/npc/little_monkey": 2,
	]));
	set("no_clean_up", 0);
	set("outdoors", "xx" );

	setup();
}
 

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
