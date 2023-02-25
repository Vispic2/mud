// Room: /d/suzhou/baodaiqiao.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "宝带桥");
	set("long", @LONG
宝带桥横跨于苏州的运河之上，又因桥形宛若长带，被称
为长桥。桥面宽阔，行人在桥上来往，桥边有城里的小贩吆喝、
叫卖着，熙熙攘攘，热闹非凡。宝带桥卧于碧波之上，相应生
辉，分外多娇。这里是中秋赏月的一处绝佳之地。
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"northeast" : __DIR__"dongdajie1",
		"northwest" : __DIR__"xidajie1",
		"north"     : __DIR__"canlangting",
		"south"     : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/seller": 1,
		"/adm/npc/jiaoshi" : 1,
	]));
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
