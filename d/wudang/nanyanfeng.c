//Room: nanyanfeng.c 南岩峰
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","南岩峰");
      set("long",@LONG
这里是武当三十六岩之最，松树翳天，木石争奇，峭壁万仞。在悬崖
之半筑有一宫宇，下临深渊，工程浩大。宫前有一石柱，自峭壁上横出。
LONG);
      set("objects", ([
	   CLASS_D("wudang") +"/mo": 1,
      ]));

      set("exits",([ /* sizeof() == 1 */
	  "eastdown" : __DIR__"langmeiyuan",
	  "southdown": __DIR__"shizhu",
	  "west"     : __DIR__"sheshenya",
      ]));
      set("outdoors", "wudang");
      setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "武当派") && dir == "southdown" &&
		objectp(present("mo shenggu", environment(me))))
	   return notify_fail("莫声谷拦住你说：此处乃本派禁地，请止步。\n");

	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
