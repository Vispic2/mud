// Room: /d/songshan/qimushi.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "启母石");
	set("long", @LONG
这里有一壁三丈巨石当道。相传大禹治水时要打通辕擐山，大禹
化熊扒挖不止。禹妻涂山氏送饭时不慎撞破，失惊而逃，到此化石。
其时涂山已有身孕，大禹追及唤子，巨石北裂一口，夏启呱呱落地。
巨石因此唤作启母石。
LONG );
	set("exits", ([
		"southeast" : __DIR__"shandao1",
		"west"      : __DIR__"qimuque",
		"northup"   : __DIR__"shandao2",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
