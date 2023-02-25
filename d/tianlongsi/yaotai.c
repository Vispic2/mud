inherit ROOM;

void create()
{
	set("short", "清都瑶台");
	set("long",@LONG
这是出入前后寺的必经之路。往南望去，可见后寺中亭台楼阁规模宏
大，构筑精丽，宅地连云，其气势之盛更胜于五台，普陀等诸处佛门胜地
的名山大寺。
LONG );
	set("outdoors","tianlongsi");
	set("exits", ([
		"south": __DIR__"wuwujing", 
		"north": __DIR__"huangtianmen",   			
	]));
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
