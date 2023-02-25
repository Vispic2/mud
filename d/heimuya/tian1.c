inherit ROOM;
 
void create()
{
	set("short", "天香堂");
	set("long",@LONG
这里是黑木崖的第四大堂“天香堂”。一中年妇人横眉立在
当地。
LONG );
	set("exits", ([
	    "northdown"   : __DIR__"dating4",
	]));
	set("objects", ([
	    __DIR__"npc/shang" : 1,
	]));       
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
