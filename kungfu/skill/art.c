// art.c 琴棋书画
// cck 3/7/97
//cool 10/10/98

inherit SKILL;
int do_play(string arg);

//void create() { seteuid(getuid()); }

int valid_enable(string usage)
{
        return (usage == "parry");
}


int valid_learn(object me)
{
	if ( me->query("int") < 24 && me->query_int() < 32)
	return notify_fail("琴棋书画乃是极其风雅之事，" +RANK_D->query_respect(me)+"似乎太过于俗气了些。\n");

	if( (int)me->query("shen") < -10000 )
	return notify_fail("你杀人如麻，倘若不能先平息了心头魔念，哪里又会有心思弹琴下棋？\n");

//	if(me->query("family/master_name") != "何足道" )
//	return notify_fail("你一个练武的粗人，学这些酸腐文人的东西干什么？\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("琴棋书画只能靠学(learn)来提高。\n");
}

void init()
{
		add_action("do_play", "play");
}

int do_play(string arg)
{
		object me = this_player();

		if ( !arg && (arg != "music") && (arg != "zheng") && (arg != "gu zheng")
			  && (arg != "wei qi") && (arg != "qi") && (arg != "go") )
			return notify_fail("你要做什么？\n");

		if ( present("gu zheng", this_player()) &&
			((arg == "music") || (arg == "zheng") || (arg == "gu zheng"))  )
		{
			if ( me->query_skill("art", 1) < 30 )
			{
				message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调杂乱无章，宛如鬼哭狼号。\n", me);
				me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >100 )
			{
				message_vision("$N摆出一张古筝，铮铮琮琮弹了几声，只听得曲调平和，洋洋洒洒，颇有佳意。\n", me);
				return 1;
			}
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
		tell_object(me, "你摆出一张古筝，调了调弦，弹了起来，你只觉得连日来烦燥的心情好了许多。\n");

			message_vision("只见" + me->query("name") +
		  "雅兴大发，竟弹起曲子来，你只觉得时而金戈铁马、大漠平沙。。。。。。\n"
		  "时而小桥流水、几户人家。。。。。。万般气象，你心情顿时宁静了许多。\n",
			environment(me), ({me}) );

			return 1;
		}

		if ( present("wei qi", this_player()) && ((arg == "wei qi") || (arg == "qi") || (arg == "go")) )
		{
			if ( (me->query_skill("art", 1) < 40) )
			{
				message_vision("$N摆出一张棋盘，想研究围棋，却总觉得心烦意乱，定不下神来。\n", me);
		        me->receive_damage("jing", random(20) );
				me->receive_damage("qi", random(20) );
				return 1;
			}
	if ( me->query_skill("art", 1) >100 )
			{
				message_vision("$N摆出一张棋盘，只觉棋面布局尽在筹幄只之中，无密可研。\n", me);
				return 1;
			}

			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			me->improve_skill("art", (int)me->query_int()/4 + (int)me->query_skill("art", 1)/10);
			tell_object(me, "你摆出一张棋盘，研究起围棋来，只觉得心平气和，很快就仿佛入定了。\n");

			message_vision("只见" + me->query("name") +
		  "雅兴大发，竟打起棋谱来，对外界仿佛不闻不问，一副莫测高深的模样。\n",
			environment(me), ({me}) );

		}
			return 1;
		}

string perform_action_file(string action)
{
    return __DIR__"art/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
