// xiaolu8.c 后山小路
inherit ROOM;
string l_pattern();

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这里是后山上的小路。这条小路好象不是人工刻意修出来的，
也许只是以前的采药人踩多了，现出这样一条小路来。山壁上好象
刻着一些什么字迹(pattern)。走到这里，你好象迷路了。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"xiaolu7",
		"north" : __DIR__"xiaolu4",
		"south" : __FILE__,
	]));
	set("item_desc",([
	  "【山壁】" : (:l_pattern():),
	]));
	set("no_clean_up", 0);

	setup();
}

string l_pattern()
{
	object me=this_player();
	if(me->query_temp("tmark/指")==3) {
		me->add_temp("tmark/指",1);
		return("好象是被人用大力金刚指力之类的功夫在山石上刻下一首诗，这人的指力可真了得。\n");
	}
	else
	{
		me->set_temp("tmark/指",0);
		return("山壁上刻着一首诗，不知道是怎么刻上去的。\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
