
// Room: nanheqiaos.c
inherit ROOM;
void create()
{
	set("short",HIR"凌云大门"NOR);
	set("long",@LONG
这里是凌云大门！里面便是凌云窟，火麒麟！
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
	 
	    "west"  : __DIR__"nanheqiaos",
	    "east"  : __DIR__"shilu1",
	    
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
