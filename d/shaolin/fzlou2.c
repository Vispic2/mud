inherit ROOM;

void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室陈设简洁，正中一几，一蒲团，一矮床。北面墙上写
着大大的一个『禅』字。一位慈眉善目的灰衣老僧正端坐于蒲团
上打坐。
LONG );
	set("exits", ([
		"south" : __DIR__"fzlou1",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/xuan-ci" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
