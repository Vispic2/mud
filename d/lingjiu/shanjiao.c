//ROOM: shanjiao.c
inherit ROOM;
void create()
{
	set("short", "缥缈峰山脚");
	set("long",@LONG
这里是缥缈峰山脚, 抬头上望, 缥缈峰耸入云天, 峰顶白云缭绕, 宛
若仙境. 白云深处隐约可见琼楼玉宇, 那就是令江湖人物闻名丧胆的『灵
鹫宫』。听说宫中住着一些武艺高强的女侠, 而且只收女弟子为徒。
LONG
	);
	set("outdoors", "lingjiu");
	set("exits", ([
		"westup" : __DIR__"ya",
		"southdown" : "/d/xingxiu/tianroad2"
	]));
	set("objects",([
		__DIR__"npc/jiuyi" : 1,
       ]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
