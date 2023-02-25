// Room: /d/shaolin/chufang2.c
inherit ROOM;
void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是一间厨房。厨房很大，可能也是因为兼作仓库的缘故。
灶头砌在北首，一根大烟囱直通出屋顶。房子四壁被常年烟火熏得
发黑，连房梁也是焦黑焦黑。墙角堆满了柴火，另一边放了些晒干
的辣椒，稻谷等。东边的墙灰剥落了一块，露出犬牙交错的砖缝来。
屋角边有个大洞。
LONG );
	set("exits", ([
		"southwest" : __DIR__"houshan",
	]));
	set("item_desc",([
		"【石板】"	: "西...东...北...东...南...北...东...西\n",
		"【大洞】"	: "墙角被扒开了个大洞，里面黑沉沉的，不知通往哪里。\n"
		ZJOBACTS2"钻洞:enter dong\n",
	]));
	set("resource/water", 1);
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
			me->move("/d/gaibang/undersl");
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
