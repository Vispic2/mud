//TORJQ3.C

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
大路已经延伸到了尽头，西首方向一座门楼高耸，门前有十几
个金衣人往返巡逻，气势森严。门楼两旁并插镶金青龙旗，迎风招
展，烈烈生威。红色大门紧闭，不时有教众从侧小门进出，也被盘
查得紧。向西北而行，是去洪水旗的路，而西南方向则通往烈火旗。
LONG );
	set("exits", ([
		"east" :      __DIR__"jmqmen",
		"southeast" : __DIR__"tojmq2",
		"northeast" : __DIR__"tohtq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
