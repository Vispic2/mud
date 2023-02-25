// zhengting.c 正厅

#include <ansi.h>
inherit ROOM;

int do_sleep(string arg);

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是古墓的正厅，本来应该停放灵柩棺木之类的东西，却不知
道被人般到哪里去了。厅正中端坐着一位白衣少女，厅角上摆放着一
张石头做成的大床(chuang)，厅中横系着一条绳子，不知道做什么用
的，除此之外，别无摆设。
LONG
	);

	set("exits", ([
		"west"  : __DIR__"liangong",
		"north" : __DIR__"xiaoting",
		"south" : __DIR__"houting",
		"east"  : __DIR__"xiuxishi",
	]));

	set("objects", ([
		CLASS_D("gumu") + "/longnv" : 1,
		CLASS_D("gumu") + "/yang"   : 1,
	]));

	set("item_desc", ([
		"寒玉床": "这是一张用"+HIB"千年寒玉"NOR+"雕成的寒玉床。\n"
				ZJOBACTS2"躺上去:sleep\n",
	]) );
	set("valid_startroom",1);
	setup();
}

void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object me=this_player();
	int lvl_force;

	lvl_force = (int)me->query_skill("force", 1);
	if (lvl_force > 150)
	{
		message_vision("$N躺上了寒玉床，开始潜运内功，使内息遍行大小周天。\n", this_player());
		if (random(20) > 12)
		{
			message_vision("$N调息完毕，只觉得精神健旺，内息充沛欲奔腾而出。\n", this_player());
			if (me->can_improve_skill("force") && lvl_force < 180)
				me->improve_skill("force", 1 + lvl_force / 20);

			me->receive_damage("qi", lvl_force / 3 + random(lvl_force / 3));
		}
		else
		{
			message_vision("$N调息完毕，站起身来，提了提内力，好象没什么长进。\n", this_player());
			me->receive_damage("qi", 10 + random(10));
		}
	} else
	{
		message_vision("$N躺上寒玉床，只觉得冰冷刺骨，‘啊’的一声狼狈不堪地跳了起来。\n",this_player());
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	object yang;

	if ((dir == "west" || dir == "east") &&
	    objectp(yang = present("yang guo", this_object())))
		return yang->permit_pass(me, dir);

	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
