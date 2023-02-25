// Room: westroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "西大街");
	set("long", @LONG
你不知不觉地就来到了成都西北角，从这里往北望，显得格外冷
清。青石大道上只有零零落落的几个人，在慢悠悠闲逛。往南是西大
街，东北方向是另一条大街，西北角有个好大的药店，卖一些武林中
人常用的药，唐门弟子常来此配药。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
	    "south"      : __DIR__"westroad2",
	    "northeast"  : __DIR__"northroad1",
	    "northwest"  : __DIR__"yaodian",
	]));
	set("objects", ([
	    "/d/huashan/npc/haoke": 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
