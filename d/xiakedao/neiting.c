// neiting.c

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
这是一个石洞，此洞硕大无朋，四周点满了火把，把整个大厅照
耀得十分明亮，中间放着很多石桌和石凳，有很多的江湖人物在石室
在参悟武功之余，在这里休息一会。
LONG );

	set("exits", ([
		"enter" : __DIR__"shihole1",
		"north" : __DIR__"xiuxis2",
		"east"  : __DIR__"shibi",
		"west"  : __DIR__"chashi",
	]));

	set("objects", ([
		__DIR__"npc/shipotian" : 1,
		__DIR__"npc/daoseng": 1,
		__DIR__"npc/dizi": 2,
	]));

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
