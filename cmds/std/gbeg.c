// beg.c

#include <ansi.h>
#include <config.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	int sp, dp;

	object where = environment(me);

	seteuid(getuid());

	if (me->query("family/family_name") != "丐帮")
	  	return notify_fail("只有乞丐才能乞讨！\n");

	if (environment(me)->query("no_beg") ||
	    environment(me)->query("no_fight"))
		return notify_fail("这里不是你叫化子能来讨饭的地方！\n");

	if (me->query_temp("begging"))
		return notify_fail("你已经在向人家乞讨了！\n");

	if (! arg)
		return notify_fail("指令格式：beg 人物\n");

	victim = present(arg, environment(me));
	if (! victim || victim == me)
		return notify_fail("你想乞讨的对象不在这里。\n");

	if (! living(victim) || ! objectp(victim))
		return notify_fail("你要向谁乞讨？\n");

	if (victim->query("family/family_name") == "丐帮")
		return notify_fail("你不能向乞丐乞讨！\n");

	if (! wizardp(me) && wizardp(victim))
		return notify_fail("玩家不能向巫师乞讨。\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("一边打架一边要饭？你真是活腻了！\n");

	if (victim->is_fighting())
		return notify_fail(victim->name() + "正在打架，没空理你！\n");

	if (! ob) ob = present("gold", victim);
	if (! ob) ob = present("silver", victim);
	if (! ob) ob = present("coin", victim);

	if (! ob)
		return notify_fail( victim->name() + "身上看起来没有什麽让你感兴趣的东西。\n");

	if (ob->query("equipped") || ob->query("no_drop"))
		return notify_fail("这是那人的随身家伙，肯定不会给你。\n");

	sp = (int)me->query_skill("begging");
	sp = sp * sp * sp / 10;

	if (sp < 1) sp = 1;
	dp = (int)victim->query("jing") + ob->value() / 5;

	tell_object(me, "你装出可怜巴巴的样子，慢慢地向" + victim->name() + "走过去，伸出双手，想要"
			+ ob->query("unit") + ob->name() +"...\n\n");
	tell_object(victim, me->name() + "可怜巴巴地向你慢慢走过来，伸出手，说道：" + RANK_D->query_respect(victim) + "行行好，给我"
			+ ob->query("unit") + ob->name() + "吧 ...！\n\n");
	message("vision", "只见" + me->name() + "装出可怜巴巴的样子，慢慢地向"
		+ victim->name() + "走过去，\n伸出双手，说道："
		+ RANK_D->query_respect(victim) + "，行行好吧 ...\n\n", environment(me), ({ me, victim}) );

	me->set_temp("begging", 1);
	call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	int bcount;
	object ob1;
	object where;

	if (! objectp(me)) return;
	me->delete_temp("begging");

	where = environment(me);
	if (! objectp(ob) || ! living(me) || me->is_fighting())
		return;

	if (! victim || environment(victim) != environment(me))
	{
		tell_object(me, "太可惜了，你要乞讨的人已经走了。\n");
		return;
	}

	if (environment(ob) != victim)
	{
		tell_object(me, "太可惜了，人家好像已经没有" + ob->name() + "了。\n");
		return;
	}

	if (living(victim) && (random(sp + dp) > dp))
	{
		if (! ob->query("money_id") || ! (amount = ob->query_amount()))
		{
			tell_object(me, "看来还是走吧，这家伙身上已经没有多少油水可榨了。\n");
			return;
		}

		bcount = amount / 5;
		if (! bcount) bcount = 1;
		ob->set_amount(amount - bcount);

		ob1=new("/clone/money/" + ob->query("money_id"));
		ob1->set_amount(bcount);
		ob1->move(me);

		tell_object(me, victim->name() + "低头想了一会，又看了看你，摇摇头，叹了口气，丢给你一" +
				ob1->query("unit") + ob1->name() + "。\n");
		tell_object(victim, "你看着" +  me->name() +"的可怜样，叹了口气，丢给他一" +
				ob1->query("unit") + ob1->name() + "。\n");

      		if (me->can_improve_skill("begging"))
	  		me->improve_skill("begging", random(me->query("int")));

      		if ((int)me->query("potential") < (int)me->query_potential_limit())
			me->add("potential", 1);

		me->add("combat_exp",1);
		if (! me->is_busy())
			me->start_busy(3 + random(4));
	} else
	{
		if (random(sp) > dp / 2)
		{
			message_vision(victim->name() + "狠狠"
				       "地瞪了$N一眼，喝道：滚！"
				       "$N吓了一跳，急忙扭头灰溜"
				       "溜地走开了。\n", me);
			if (! me->is_busy())
				me->start_busy(3);
			return;
		}

		tell_object(me, victim->name() + "扭过头去，对你理都不理。\n");
		tell_object(victim, "你扭过头去，对" + me->name() +
			    "理都不理。\n");
		message("vision", victim->name() + "扭过头去，对" +
			me->name() +  "理都不理。\n",
			environment(me), ({ me, victim }) );

		if (! me->is_busy())
			me->start_busy(3);
	}
}

int help(object me)
{
	write(@HELP
指令格式 : beg <某物> from <某人>

HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
