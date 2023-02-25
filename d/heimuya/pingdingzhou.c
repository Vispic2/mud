// Room: /d/heimuya/pingdingzhou.c
inherit ROOM;

void create()
{
    set("short", "平定州");
    set("long", @LONG
平定州在河北境内，州府不大，但地处要冲，十分重要。
往来京城的客商穿梭频繁。但大街上日月教徒横冲直撞，出手
抓人，虽近在京畿，却丝毫没将官府放在眼里。
LONG );

    set("exits", ([
	"east" : __DIR__"road3",
	"west" : __DIR__"road2",
    ]));
    set("outdoors", "heimuya");
    set("no_clean_up", 0);
    setup();
    //replace_program(ROOM);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
