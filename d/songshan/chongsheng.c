// Room: /d/songshan/chongsheng.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "崇圣门");
	set("long", @LONG
崇圣门前古神库有四座镇库铁人，高达丈许，振臂握拳，怒
目挺胸，身姿雄健。向北就是中岳庙最大的殿宇中岳大殿了。
LONG );
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"tianzhongge",
	]));
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
