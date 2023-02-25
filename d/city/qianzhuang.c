// Room: /city/qianzhuang.c
inherit ROOM;
void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。
    在对面的墙上挂了块牌子(paizi)。
LONG );
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"【牌子】" : "本钱庄提供以下服务：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"存钱:cun"ZJSEP"取钱:qu"ZJSEP"查账:check\n",
	]) );

	set("objects", ([
		__DIR__"npc/qian" : 1,
		"adm/npc/licai" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
