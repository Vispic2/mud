// Room: /d/taishan/.c
inherit ROOM;

void create()
{
	set("short", "围屏山");
	set("long", @LONG
这里是泰山的其中一座山峰。山的东面有一个虎头崖，其形状
有如一头伏虎。南面有避风崖，崖上大大地刻着「振衣冈」三字于
上面。北边则有北斗坛。从这里往东走，便可到达伺奉泰山之神碧
霞元君的碧霞祠。
LONG );
	set("exits", ([
		"westdown" : __DIR__"tianjie",
		"east" : __DIR__"bixia",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
