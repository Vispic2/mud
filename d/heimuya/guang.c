//ROM

inherit ROOM;

void create()
{
	set("short", "山谷");
	set("long", @LONG
这里是一处山谷，上面种植着草坪。南面是『日月神教』的
青龙堂。向西有一条上山的石道。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "east" : __DIR__"linjxd1",
	    "southup" : __DIR__"dating3",
	    "west" : __DIR__"shidao1",
	]));
	set("objects",([
	    __DIR__"npc/kid" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
