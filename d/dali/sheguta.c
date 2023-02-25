//Room: /d/dali/sheguta.c
inherit ROOM;
void create()
{
	set("short","蛇骨塔");
	set("long",@LONG
蛇骨塔位于大理城内，建在点苍山斜阳峰东坡。相传洱海有妖蛇
名“薄劫”，其尾塞海口，洪水泛滥，有勇士段赤城只身入洱海与妖
蛇同归于尽。后人建塔以震水势，用蛇骨灰塔，水势自息。这是一座
密椽式方形砖塔。
LONG);
	set("objects", ([
	   __DIR__"npc/kid": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"taihejiekou",
	    "west"  : __DIR__"qingchi",
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
