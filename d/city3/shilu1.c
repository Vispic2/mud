
// Room: nanheqiaos.c
inherit ROOM;
void create()
{
	set("short","石路");
	set("long",@LONG
这里是凌云内！前面便是凌云窟，火麒麟！
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */

	    "west"  : __DIR__"lingyundamen",
	    "east"  : __DIR__"lingyunku",
	    
	    
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
