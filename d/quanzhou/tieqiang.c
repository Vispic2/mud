// Room: /d/quanzhou/tieqiang.c
inherit ROOM;
void create()
{
	set("short", "铁枪庙");
	set("long", @LONG
这铁枪庙祀奉的是五代时名将铁枪王彦章。庙旁有座高塔，塔顶
群鸦世代为巢，当地乡民传说铁枪庙的乌鸦是神兵神将，向来不敢侵
犯，以致生养繁殖，越来越多。庙内案桌下有个小洞。
LONG );
	set("exits", ([
		"west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));
	set("item_desc", ([
	    "【案桌】" : "一个破旧的案桌，下边好像有个隐藏的土洞。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	]));
	set("objects", ([
		__DIR__"npc/wuya": 4
	]));
	set("outdoors", "jiaxing");
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮" ) 
		{
			message("vision",
				me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underqz");
			message("vision",
				me->name() + "从洞里走了进来。\n",
				environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
