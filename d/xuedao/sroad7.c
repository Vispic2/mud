// sroad7.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "大雪山口");
	set("long", @LONG
群山环绕，四周积雪终年不化。南边不远处有一个山谷。
LONG );
	set("exits", ([
		"eastdown"  : __DIR__"sroad6",
		"southdown"   : __DIR__"sroad8",
	]));
	set("objects", ([
		__DIR__"npc/caiyaoren": 1,
	]));
	set("outdoors", "xuedao");
	setup();
}

int valid_leave(object me, string dir)
{
	if (! playerp(me))
		return ::valid_leave(me, dir);

	if (dir == "southup")
	{
		message_vision(HIW "突然轰隆一声巨响，$N脚下踏"
			       "了个空，... 啊...雪崩了！"NOR"\n", me);
		if (me->query_dex() / 2 + random(me->query_dex()) < 13)
		{
			me->receive_damage("qi", 70);
			me->receive_wound("qi", 70);
		}
		tell_object(me, HIW "只见大片的积雪从山峰上奔腾而下，向你铺天"
				"盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！"NOR"\n");
		message("vision", HIW "只见大片的积雪从山峰上奔腾而下，向" + me->name(1) +
				  "铺天盖地地扑过来，沿途并夹带了不少岩石。赶紧逃命吧！"NOR"\n",
				  environment(me), ({ me }));
		if (me->query_dex() / 2 + random(me->query_dex()) >= 15)
		{
			me->move(__DIR__"sroad8");
			return -1;
		} else 
		{
			me->move(__DIR__"sroad5");
			return -1;
		}
	}
	return ::valid_leave(me,dir);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
