// by name 真解
#include <ansi.h>

inherit F_CLEAN_UP;

int breaking(object me);
int halt_breaking(object me);

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	int exercise_cost;
	object where;

	seteuid(getuid());
	where = environment(me);
	if(!arg)
	return notify_fail("你要干什么？\n");
	if(!(arg=="taixuan-gong"||arg=="pixie-jian"||arg=="dragon-strike"||arg=="lonely-sword"||arg=="six-finger"||arg=="poison"))	
	return notify_fail("暂时没有这个真解武功！！！\n");
	
    if (me->query(""+arg+"_zj"))
	return notify_fail(HIC"你已经感悟了"+to_chinese(arg)+"的奇妙之处，没有必要再来一次。"NOR"\n");

	if (! where->query(""+arg+"_zj"))
	return notify_fail("你想在这里感悟"+to_chinese(arg)+"？\n");

	if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");

	if (me->query("zhenyuan") < 1000)
	return notify_fail("你的真元不够，没法感悟"+to_chinese(arg)+"的奥秘。\n");

	if ((int)me->query("qi") * 100 / me->query("max_qi") < 90)
	return notify_fail("你现在的气太少了，无法静心感悟。\n");

	if ((int)me->query("jing") * 100 / me->query("max_jing") < 90)
	return notify_fail("你现在的精太少了，无法静心感悟。\n");

	if ((int)me->query("max_neili") < 1000)
	return notify_fail("你觉得内力颇有不足，看来目前还很难感悟"+to_chinese(arg)+"。\n");

	if ((int)me->query("neili") * 100 / me->query("max_neili") < 90)
	return notify_fail("你现在的内力太少了，无法静心闭关。\n");

	if ((int)me->query_skill(arg,1) < 300)
	return notify_fail("你觉得自己的"+to_chinese(arg)+"火候颇有不足。\n");
	
    me->set("zhenjies",arg);//不会搞怎么获取arg的值，下面不好整，只能这样了。。。
    
	message_vision("$N盘膝坐下，开始冥神运功，感悟"+to_chinese(arg)+"的奥秘。\n", me);
	me->set("doing", "breakup");
	CLOSE_D->user_closed(me);
	me->start_busy(bind((:call_other, __FILE__, "breaking" :), me),
	bind((:call_other, __FILE__, "halt_breaking" :), me));
	return 1;
}

int continue_breaking(object me)
{
	me->start_busy(bind((:call_other, __FILE__, "breaking" :), me),
    bind((:call_other, __FILE__, "halt_breaking" :), me));
	CLOSE_D->user_closed(me);
	tell_object(me, HIR "你继续闭关研究"+to_chinese(me->query("zhenjies"))+"的奥秘..."NOR"\n");
	return 1;
}

private void stop_breaking(object me)
{
	CLOSE_D->user_opened(me);
	if (! interactive(me))
	{
		me->force_me("chat* sigh");
		call_out("user_quit", 0, me);
	}
}

int breaking(object me)
{
	string msg;
    object where;
    where = environment(me);
	if (! where->query(""+me->query("zhenjies")+"_zj")){
     me->force_me("halt");
	}
	if (me->query("zhenyuan")<1)
	{
		tell_object(me, "你的真元耗尽了。\n");
		message_vision("$N睁开双目，缓缓吐了一口气，站了起来。\n", me);
		CLOSE_D->user_opened(me);

		if (! interactive(me))
		{
			me->force_me("chat* sigh");
			call_out("user_quit", 0, me);
		}

		return 0;
	}

    me->add("zhenyuan",-1000+random(1001));
    
	if(random(3))
	return 1;
	
	if (random(8000) < me->query("con") || random(8000) < me->query("dex") ||random(8000) < me->query("str") ||random(8000) < me->query("int") )
	{
		message_vision(HIW "只见$N" HIW "头上白雾腾腾、浑身如同笼罩在云中，看来已经到了三花聚顶、"
	    "五气朝元、龙虎相济、天人交会的紧要关头！"NOR"\n", me);
		tell_object(me, HIR "你觉得内力在丹田源源而生，不断冲击诸处大穴，浑身燥热难当，几欲大声呼喊。"NOR"\n");
		message_vision(HIC "突然$N" HIC "大喝一声，一股无形气浪陡然散布开来，四周空气登时变得燥热。"NOR"\n", me);
		tell_object(me, HIG "你顿时觉得浑身一阵轻松，一股清凉之意油然而起，心灵一片空明，内力没有丝毫阻滞，舒泰之极。"NOR"\n");
		me->set(""+me->query("zhenjies")+"_zj", 1);
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("听说%s(%s)经过数月静修，终于感悟了"+to_chinese(me->query("zhenjies"))+"的奥秘，使得实力大增！",me->name(1), me->query("id")));
		stop_breaking(me);
		return 0;
	}

	switch (random(5))
	{
	case 0:
		msg = ""HIC"你默默运转内力，脑海里一招一式的演练着"+to_chinese(me->query("zhenjies"))+"。"NOR"\n";
		break;

	case 1:
		msg = ""HIR"你将内力运出丹田，过紫宫、入泥丸、透十二重楼，遍布奇筋八脉，然后收回丹田。"NOR"\n";
		break;

	case 2:
		msg = ""HIY"你突然感觉你对"+to_chinese(me->query("zhenjies"))+"有着非同凡响的理解。"NOR"\n";
		break;

	case 3:
		msg = ""HIM"你仔细感悟着真解武学的一招一式。"NOR"\n";
		break;

	default:
		msg = ""HIW"你缓缓呼吸吐纳，将空气中水露皆收为己用。"NOR"\n";
		break;
	}

	tell_object(me, msg);
	return 1;
}

int halt_breaking(object me)
{
	CLOSE_D->user_opened(me);
	tell_object(me, "你中止了感悟"+to_chinese(me->query("zhenjies"))+"的奥秘。\n");
	message_vision(HIY "$N" HIY "轻轻叹了一口气，缓缓的睁开眼。"NOR"\n", me);
	return 1;
}

private void user_quit(object me)
{
	if (! me || interactive(me))
		return;

	me->force_me("quit");
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
