//Room: shizhu.c 石柱
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","石柱");
      set("long",@LONG
这是南岩宫前的一根石柱，雕成龙形，自峭壁上横出，犹如飞龙在天。龙首
刻一香炉，在此上香称为“上龙头香”，是香客的最大心愿。石柱仅粗如屋梁，
旁无扶栏，前有白云缭绕，下有万丈深渊，稍一失足，即尸骨无存。
LONG);
      set("exits",([ /* sizeof() == 1 */
	  "northup"  : __DIR__"nanyanfeng",
	  "enter"    : __DIR__"nanyangong",
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
}

void init()
{
	add_action("do_mianbi", "face");
}


int do_mianbi(string arg)
{
	object ob;

	ob = this_player();
	if (! arg)
	{
		message_vision("$N面对着石柱趺坐静思良久，白"
			       "忙一场，一无所获。\n",ob);
		return 1;
	}

	if ((int)ob->query_skill("literate", 1) < 100)
	{
		message_vision("$N面对着石柱上满面蝌蚪文，没"
			       "一个字认识。\n",ob);
		return 1;
	}

	if ((int)ob->query_skill("taoism", 1) < 100)
	{
		message_vision("$N对石柱上每一个字都认识，就"
			       "是不知道说的是什么。\n",ob);
		return 1;
	}

	if (arg == "taiji-jian" ||
	    arg == "taiji-quan" ||
	    arg == "tiyunzong")
	{
		if ((int)ob->query_skill(arg, 1) < 100)
		{
			message_vision("$N的" + to_chinese(arg) +
				       "显然太低，无法领悟石柱内容。\n",ob);
			return 1;
		}

		if ((int)ob->query_skill(arg, 1) > 180)
		{
			message_vision("$N的" + to_chinese(arg) +
				       "已经没必要读石柱内容了。\n", ob);
			return 1;
		}

		if (! ob->can_improve_skill(arg))
		{
			message_vision("$N的实战经验不足，无法"
				       "领悟石柱内容。\n", ob);
			return 1;
		}

		if (ob->query("jing") < 150)
		{
			message_vision("$N太累了，现在无法领"
				       "悟石柱内容。\n", ob);
			return 1;
		}

		message_vision("$N面对着石柱趺坐静思，良久，对" +
			       to_chinese(arg) + "似有所悟。\n", ob);
		ob->improve_skill(arg, 1 + random(ob->query("int")));
		ob->add("jing", -100 - random(50));
		return 1;
	}

	message_vision("$N面对着石柱趺坐静思，良久，似有所悟。\n", ob);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
