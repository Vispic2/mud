// Room: /d/mingjiao/gudi5.c

inherit ROOM;
void create()
{
	set("short", "昆仑仙境");
	set("long", @LONG
向西走了二里多，只见峭壁上有一道大瀑布冲击而下，料想是
雪融而成，阳光照射下尤如一条大玉龙，极是壮丽。瀑布泄在一座
清澈碧绿的深潭(tan )之中，潭水却也不见满，当是另有泄水的去
路。你观赏了半晌，一低头，见手足上染满了清苔污泥，另有无数
给荆棘硬草割破的血痕，於是走近潭边，除下鞋袜，伸足到潭水中
去洗涤(xidi)。
LONG );
	set("outdoors", "mingjiao");
	set("exits", ([
		"east" : __DIR__"gudi3",
	]));
	set("fish_count",2);
	set("item_desc", ([
		"【深潭】" : "你附身潭边，凝神瞧去，只见碧绿的水中十馀条大白鱼来回游动。\n"
		ZJOBACTS2"洗涤:xidi",
	]));
	setup();
}

void init()
{
	add_action("do_xidi", "xidi");
}

int do_xidi()
{
	object fish, me = this_player();

	if ((this_player()->query_dex() < 25) || query("fish_count") <= 0)
		message_vision("$N洗了一会，突然泼喇一声，潭中跳起一尾大白鱼，足有一尺多长，$N忙伸手去抓，虽然碰到了鱼身，却一滑滑脱了。\n", me);
	else
	{
message_vision("潭中跳起一尾大白鱼，足有一尺多长，$N忙伸手去抓，一把把它攥在手心。\n", me);
		add("fish_count",-1);
	}
	fish = new(__DIR__"obj/fish");
	fish->move(me, 1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
