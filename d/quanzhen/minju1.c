// minju1.c 民居
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这好象是一家相对殷实的小康人家，屋内铺着青砖，摆着一套红
木桌椅。墙上挂着几幅山水画(hua)， 主人不在家里。
LONG
	);
	set("exits", ([
		"east" : __DIR__"beijie",
	]));
	set("item_desc", ([
		"hua": "这不是北宋范宽的‘溪山行旅图’吗？你"
		       "大吃一惊。揉了揉眼睛仔细一看，原来是副赝品。\n"
	]) );
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
