// shandao2.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这一路上山，地势极险，脚下是万丈深谷，而山道极之陡峭
窄小，倘若一不留神，必将命丧于此。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "eastdown" : __DIR__"shandao1",
	    "westup"   : __DIR__"shijie1",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
