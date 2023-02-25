// Room: /d/mingjiao/gudi1.c

inherit ROOM;

void create()
{
	set("short", "昆仑谷底");
	set("long", @LONG
前面是一堵屏风也似的大山壁。眼前茫茫云海，更无去路，你
竟是置身在一个三面皆空的极高平台上。那平台倒有十余丈方圆，
可是半天临空，上既不得，下又不能，当真是死路一条。这大平台
上白皑皑的都是冰雪，既无树林，更无野兽。
LONG );
	set("outdoors", "mingjiao");
	set("item_desc", ([
		"【雪壁】" : "山谷两侧石壁上白雪皑皑。\n"
		ZJOBACTS2"攀爬:climb",
	]));
	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb()
{
	int n = this_player()->query_skill("dodge", 1);

	message_vision("$N深吸了一口气，慢慢沿着雪壁向上爬。\n", this_player());
	if (n >40)
	{
		message_vision("$N爬了半天，手肘膝盖都已被坚冰割得鲜血淋漓，终
于爬了上来。\n", this_player());
		this_player()->move(__DIR__"gudi2");
	} else
	{
		message_vision("$N爬了一会，太累了，不小心滑了下来。唉!没办法了
，你认命吧。\n", this_player());
		this_player()->receive_damage("qi", 15);
		this_player()->receive_wound("qi", 10);
	}
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
