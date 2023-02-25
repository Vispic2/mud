// Room: /d/snow/herbshop1.c

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间光线阴暗的密室，从地上厚厚的灰尘看得出来这里很少有
人出入，靠西边的地上放着一副脚镣，连着一条铁链镶在墙上，不知道
是用来锁什麽人，南面的墙(wall)是用红杉木做的，跟另外三面的灰土
墙比起来显得有些不寻常。
LONG );
	set("exits", ([
		"east" : __DIR__"chuchang",
	]));
	set("item_desc", ([
		"【杉墙】" : "一堵斑剥淋漓的墙。\n"
		ZJOBACTS2"推墙:break wall\n",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/bai" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_move", "push");
	add_action("do_move", "break");
}

int do_move(string arg)
{
	object paper, me=this_player();

	if (! arg || arg == "")
		return 0;

	if (arg == "wall")
	{
		if (!query("had_staffbook") && me->query("neili",)>200)
		{
			message_vision("$N运足内力猛向破墙拍去，只听哗得一阵响，墙顶落下来一本破纸...。\n",
				       this_player());
			paper = new("/clone/book/staff_book");
			paper->move(__FILE__);
			set("had_staffbook", 1);
			return 1;
		}
		message_vision("$N狠狠一头撞在墙，眼前顿时鲜红一片...\n",this_player());
		this_player()->receive_damage("qi", 30);
		return 1;
	}
	return 0;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
