inherit ROOM;
 
void create()
{
	set("short", "白虎堂");
	set("long",@LONG
这里是黑木崖的第二大堂“白虎堂”。堂内青砖铺地，堂内
横尸满地。
LONG );
	set("exits", ([
	    "north"   : __DIR__"baistep2",
	    "south"      : __DIR__"chitang", 
	]));
	set("objects", ([
	    __DIR__"npc/shanggy" : 1,
	]));       
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
