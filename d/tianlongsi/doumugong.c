inherit ROOM;

void create()
{
	set("short", "斗母宫");
	set("long",@LONG
这是给进香客们休息的地方。四周围放着一溜檀木红漆椅。几个进香
客坐在上面休息。
LONG );
	set("exits", ([
		"southwest" : __DIR__"doushuai",
		"north" : __DIR__"yuhuayuan",
	]));
	set("objects",([
		"/d/wudang/npc/guest" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
