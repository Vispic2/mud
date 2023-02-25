#include <room.h>
#include <huodong.h>
inherit ROOM;
#define FAMILY "桃花岛"
#define OUTROOM "/d/taohua/tingzi"
#include <jjenter.h>

void create()
{
	set("short", "竞技场");
	set("long", "这里是"+FAMILY+"门派竞技场的入口。");
	set("exits", ([
		"west" : OUTROOM,
	]));
	set("no_fight",1);
	set("no_fly",1);
	set("objects",([
	]));
	set("action_list",([
		"活动报名":"jjsign",
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
