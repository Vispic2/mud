//ROM dating
inherit ROOM;
void create()
{
	set("short", "天香堂");
	set("long", @LONG
这是『日月神教』下第四大堂：天香堂的大厅，远远望去郁
郁渺渺，好似不食人间烟火。堂梁上有一块匾(bian)。
LONG    );
	set("exits", ([
		"west" : __DIR__"road1",
		"southup" : __DIR__"tian1",
	]));
	set("item_desc", ([
	    "bian": "上面写到：天香堂---日月神教圣姑住地。\n",
       	]) );
	set("no_clean_up", 0);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
