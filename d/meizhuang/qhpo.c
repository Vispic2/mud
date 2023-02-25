// qhpo.c
inherit ROOM;

void create()
{
	set("short", "奇槐坡");
	set("long", @LONG
这里就是奇槐坡了，这里种着大大小小，千奇百怪的槐树，有的
槐树一直向天，有的又曲折盘绕，你从这里隐隐约约听到一阵阵的琴
声，似有似无，若隐若现。
LONG
	);
	set("outdoors", "meizhuang");
	set("exits", ([ /* sizeof() == 2 */
	    "eastup" : __DIR__"xiaodao",
	    "north"  : __DIR__"senlin1",
	]));
	set("no_clean_up", 0);

	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
