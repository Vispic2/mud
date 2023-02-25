// senlin6.c
inherit ROOM;

void create()
{
	set("short", "百木园");
	set("long", @LONG
这里是梅庄的百木园，你一走到这里，就象走到了一个连绵无尽
的小森林一样，这里无数的松树，柏树，白杨，还有很多叫不出来名
字的异种苗木，你走在其中，只想把这片树林尽情的欣赏一遍，永不
出去才好。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
	    "south" : __DIR__"senlin7",
	    "north" : __DIR__"senlin4",
	    "west" : __DIR__"senlin3",
	    "east" : __DIR__"senlin8",
	]));
	set("objects", ([ /* sizeof() == 1 */
	    __DIR__"npc/jiading.c" : 1,
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
