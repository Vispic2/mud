//ROOM: /d/yanziwu/tingxiang.c

inherit ROOM;

void create()
{
	set("short", "听香水榭");
	set("long",@LONG
绿柳杏花丛中有八九间茅房，四周竹篱掩映，错落有致，这就是慕
容公子的婢女阿朱的住所了。
LONG );
	set("exits", ([
	    "west" : __DIR__"biheqiao",
//	    "south" : __DIR__"shuiyun",
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
