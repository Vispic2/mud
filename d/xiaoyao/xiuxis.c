// xiuxis.c
inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是一间在树林中的小屋，屋子中间摆着几张大床，几张桌子，看来是
个休息的地方，室中光线柔和，使人更增睡意。
LONG );
	set("exits", ([ 
		"east" : __DIR__"xiaodao2", 
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("sleep_room",1);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
