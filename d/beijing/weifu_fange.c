inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
这里是鹿鼎公府的左边的一个厢房，是供给王府的客人所居住的。厢房中
央摆着几张大床，几张桌子。室中光线柔和，使人更增睡意。
LONG );
	set("exits", ([
		"west" : __DIR__"weifu_dating",
	]));

       set("no_fight",1);
       set("no_steal",1);
       set("sleep_room",1);
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
