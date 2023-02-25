// Room: /d/xingxiu/riyuedong.c
// Jay 3/18/96

inherit ROOM;

void create()
{
	set("short", "日月洞");
	set("long", @LONG
这里是星宿派总舵所在地日月洞。洞内灯火通明，正中一把虎皮椅上端坐着
星宿派掌门人丁春秋。洞壁上装饰着虎皮、鹿头、雕羽，及一些字画(zihua)。
洞两侧竖立兵器架，上面排列的大多是各种棍棒。
LONG );
	set("exits", ([
	     "south" : __DIR__"xxh2",
	]));
set("action_list", ([
		HIM"毒技真解"NOR:"zhenjie poison",
	]));
	set("poison_zj",1);
	set("item_desc", ([
		"zihua" : "都是些吹捧星宿老仙的诗词和他的画像。\n

※※※※※※※※※※※※※※※※※
※※※※　　　　　　　　　※※※※
※※※※　古　威　德　星　※※※※
※※※※　今　震　配　宿　※※※※
※※※※　无　寰　天　老　※※※※
※※※※　比　宇　地　仙　※※※※
※※※※　　　　　　　　　※※※※
※※※※※※※※※※※※※※※※※
"
	]) );

	set("objects", ([
		"/kungfu/class/xingxiu/ding" : 1,
		"/clone/weapon/tiegun" : 1,
	]) );
	set("outdoors", "xingxiu");
	setup();

}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
