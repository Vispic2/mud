//Room: shanhongpb.c 山洪瀑布
//Date: Oct. 2 1997 by Venus

#include <ansi.h>

//inherit BUILD_ROOM;
inherit ROOM;

string look_hongshui();

void create()
{
	set("short","山洪瀑布");
	set("long",@LONG
这里是一处峡谷，每年雨季山洪爆发时就形成了一处蔚为壮观的
瀑布。传说当年神雕侠杨过就是在这里练成绝世的玄铁剑法的。现在
人去谷空，只剩下空寥的山谷和奔腾的洪水(hongshui)。看来倒是个
隐居的好去处。
LONG);
	set("outdoors", "huashan");
	set("max_room", 3);
	set("item_desc", ([
		"hongshui" : (: look_hongshui :),
	]));
	set("exits",([ /* sizeof() == 1 */
		"southwest"     : __DIR__"shaluo",
	]));
		set("action_list", ([
		
			"穿过瀑布": "cross",
	]));
	setup();
}

void init()
{
	add_action("do_cross", "cross");
}

string look_hongshui()
{
	return @DESC
这是一股奔腾不息的洪水，水中隐隐有个东西在发光，但你定睛
仔细一看，发现那只不过是水面反射的日光罢了。这个瀑布似乎
可以穿(cross)过去。
DESC ;
}

int do_cross()
{
	object me;
	function f;
	object cloth;

	me = this_player();
	if (me->query_dex() / 2 + random(me->query_dex()) < 22)
	{
		message_vision("$N望了望奔腾的瀑布，突然一跃，试图穿过"
			       "瀑布，结果“扑通”一下摔进了水中。\n", me);

		cloth = me->query_temp("armor/cloth");
		if (cloth && cloth->washed(120 + random(120)))
			tell_object(me, "你身上的" + cloth->name() + "湿透了！\n");
		return 1;
	}

	message_vision("$N望了望奔腾的瀑布，突然一跃，穿过了"
		       "瀑布。\n", me);
	me->move(__DIR__"shandong");
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
