//Room: fudian1.c

inherit ROOM;

void create ()
{
	set ("short", "右翼殿");
	set ("long", @LONG
右翼殿虽较皇宫大殿为低，亦高出其他建筑物两丈有多，各由一二
十丈的长廊走道连接皇宫大殿。三座大殿一主二副，自成一个体系，气
象肃森。
LONG);
	set("exits", 
	([ //sizeof() == 1
		"west" : __DIR__"huanggong",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/shiwei" : 2,
	]));
	
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
