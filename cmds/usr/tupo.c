// animaout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int outing(object me);
int halt_outing(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int exercise_cost;
	object where;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (! me->query("breakup"))
		return notify_fail("你还没有打通任督二脉，说什么修炼?\n");

	if (! me->query("animaout"))
		return notify_fail("你还没有修炼元婴，说什么修炼?！\n");

//	if (! where->query("no_fight") && ! where->query("owner_special"))
	//	return notify_fail("在这里修炼元婴出世？不太安全吧？\n");

	if (! where->query("room_lp"))
		return notify_fail("人仙之体的修炼必须要到渡劫谷，此处喧哗至极难以静心修炼！！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (me->query("potential") - me->query("learned_points") < 100000)
		return notify_fail("你的潜能不够，没法精修修炼人仙之体，需要10w潜能。\n");

	if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
		return notify_fail("你现在的气太少了，无法静心修炼人仙之体。\n");

	if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
		return notify_fail("你现在的精太少了，无法静心修炼人仙之体。\n");

	if ((int)me->query("age") < 20)
		return notify_fail("你上未20岁，不能修炼至高的人仙之体。\n");

	message_vision("$N盘膝坐下，开始静心，闭关修行。\n", me);
	me->set("startroom", base_name(where));
	me->set("doing", "breakup");
	CLOSE_D->user_closed(me);
	me->start_busy(bind((:call_other, __FILE__, "outing" :), me),
		       bind((:call_other, __FILE__, "halt_outing" :), me));
	CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s%s(%s)开始静心修行，苦心修炼人仙之体。",
					ultrap(me) ? "玉皇大帝" : "",me->name(1), me->query("id")));

	return 1;
}

int continue_outing(object me)
{
	me->start_busy(bind((:call_other, __FILE__, "outing" :), me),
		       bind((:call_other, __FILE__, "halt_outing" :), me));
	CLOSE_D->user_closed(me);
	tell_object(me, HIR "你继续闭关修行以修炼人仙之体..."NOR"\n");
	return 1;
}

private void stop_outing(object me)
{
	CLOSE_D->user_opened(me);
	if (! interactive(me))
	{
		me->force_me("chat* sigh");
		call_out("user_quit", 0, me);
	}
}

int outing(object me)
{
	string msg;

	if (me->query("potential") <= me->query("learned_points"))
	{
		tell_object(me, "你没有办法继续修炼突破下去了。\n");
		message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);
		CLOSE_D->user_opened(me);
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("听说%s(%s)修炼结束，似乎没有什么成果。",me->name(1), me->query("id")));
		if (! interactive(me))
		{
			me->force_me("chat* sigh");
			call_out("user_quit", 0, me);
		}

		return 0;
	}

	me->add("learned_points", 1);

	if (random(10))
		return 1;

	if (random(50000) < me->query("int"))
	{
		message_vision(HIY "只见$N" HIY "四周现出一层薄薄的气层，折射出一缕青光，顿时你感觉身体流通的血液无比的舒服！"NOR"\n", me);
		tell_object(me, HIM "你觉得境界正在一点一点的突破，忽然心如止水，如身出天际，无源无尽、你身上的每一寸皮肤开始脱落长出新的皮肤，你感觉重获新生一般的干净透彻。"NOR"\n");
		me->set("lp", 1);
		CHANNEL_D->do_channel(this_object(), "rumor",
				      sprintf("听说%s(%s)经过在渡劫谷的苦修，终于修成了神仙，练得人仙之体。",
				      me->name(1), me->query("id")));
		CHAR_D->setup_char(me);
		stop_outing(me);
		return 0;
	}

	switch (random(4))
	{
	case 0:
		msg = "突破中。\n";
		break;

	case 1:
		msg = "突破中。。\n";
		break;

	case 2:
		msg = "突破中。。。\n";
		break;

	default:
		msg = "突破中。。。。\n";
		break;
	}

	tell_object(me, msg);
	return 1;
}

int halt_outing(object me)
{
	CLOSE_D->user_opened(me);
	tell_object(me, "你中止了闭关。\n");
	message_vision(HIY "$N" HIY "轻轻叹了一口气，缓缓的睁开眼。"NOR"\n", me);
	me->add("potential", (me->query("learned_points") - me->query("potential")) / 2);
	CHANNEL_D->do_channel(this_object(), "rumor", "听说" + me->name(1) + "修炼中途突然复出。");
	return 1;
}

private void user_quit(object me)
{
	if (! me || interactive(me))
		return;

	me->force_me("quit");
}

int help(object me)
{
	write(@HELP
指令格式 : animaout

档你打通任督二脉以后，并且具有非常高深的精力修行时，可以用这
条指令修炼元婴出世。如果成功可以大大的增加你的精和精力上限。

HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
