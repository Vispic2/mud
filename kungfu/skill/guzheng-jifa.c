// guzheng-jifa.c 古筝技法

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if (me->query("int") < 24 && me->query_int() < 35)
		return notify_fail("就你那点悟性？五音不全，学什么古筝？\n");

	return 1;
}

int play(object me, object ob, string arg)
{
	int lvl;
	int i;
	string m_name;

	if (! arg)
		return notify_fail("你要演奏什么曲子？\n");

	if (! (lvl = me->query_skill(arg, 1)))
		return notify_fail("你不会演奏这首曲子。\n");

	if (! SKILL_D(arg)->valid_enable("guzheng-jifa"))
		return notify_fail("这不能用来弹奏！\n");

	lvl += me->query_skill("guzheng-jifa", 1) / 2;
	m_name = to_chinese(arg);

	if (me->is_busy())
		return notify_fail("你现在正忙，等会儿再演奏吧。\n");

	if (lvl < 15)
	{
		message_vision("$N捅了捅$n，结果只是发出了几"
			       "下“叮叮当当”的声音。\n",
			       me, ob);
	} else
	if (lvl < 30)
	{
		message_vision("$N拨拉了一下$n，发出几声怪响，难听的"
			       "一塌糊涂。\n", me, ob);
	} else
	if (lvl < 60)
	{
		message_vision("$N摆好$n，轻轻的弹了几下，"
			       "声音还算清脆，不太难听。\n",
			       me, ob);
	} else
	if (lvl < 90)
	{
		message_vision("$N摆好$n，弹了一首" + m_name + "，有点"
			       "意思，颇为不错。\n",
			       me, ob);
	} else
	if (lvl < 150)
	{
		message_vision("$N摆好$n，弹了一首" + m_name + "，颇为"
			       "动人，引人入胜。\n", me, ob);
	} else
	if (lvl < 225)
	{
		message_vision("$N摆好$n，弹了一首" + m_name + "，听得"
			       "众人感慨万千，甚是投入。\n",
			       me, ob);
	} else
	if (lvl < 300)
	{
		message_vision("$N摆好$n，弹了一首" + m_name + "，众人犹如"
			       "听见溪水荡流，怡然陶趣，真是妙不可言。\n",
			       me, ob);
	} else
	{
		message_vision("$N摆好$n，弹了一首" + m_name + "，宛若清溪"
			       "流上心头，令人无酒自醉，去又似身至仙"
			       "境，心灵空明。\n",
			       me, ob);
	}
	me->start_busy(3 + random(3));

	SKILL_D(arg)->do_effect(me);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
