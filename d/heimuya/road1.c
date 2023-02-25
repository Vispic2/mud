//road1.c 黄土路
// by Xiang

inherit ROOM;

void create()
{
	set("short", "乱石坡");
	set("long", @LONG
这是一处乱石怪异的小山岗，向东北是通往平安州的小路。
据说前方经常有野兽出没，不可久留。
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
	    "northeast" : __DIR__"road2",
	    "southwest" : __DIR__"road4",
	    "west"  : __DIR__"linjxd1",
	    "east"  : __DIR__"dating4",
	]));
	set("objects",([  
	   __DIR__"npc/laozhe" : 1 ,
	])); 
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
