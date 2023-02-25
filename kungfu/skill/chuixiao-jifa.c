// chuixiao-jifa.c 吹箫技法

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if (me->query("int") < 24)
		return notify_fail("就你那悟性？五音不全，学什么吹箫？\n");

	return 1;
}

int play(object me, object ob, string arg)
{
	int lvl;
	int i;
	string m_name;

	if (! arg)
		return notify_fail("你要吹什么曲子？\n");

	if (! (lvl = me->query_skill(arg, 1)))
		return notify_fail("你不会吹这首曲子。\n");

	if (! SKILL_D(arg)->valid_enable("chuixiao-jifa"))
		return notify_fail("这也能当箫曲吹么？\n");

	lvl += me->query_skill("chuixiao-jifa", 1) / 2;
	m_name = to_chinese(arg);

	if (me->is_busy())
		return notify_fail("你现在正忙，等会儿再吹箫吧。\n");

	if (lvl < 15)
	{
		message_vision("$N鼓足了气吹了一下$n，结果只"
			       "是发出了几下“呜呜”的声音。\n",
			       me, ob);
	} else
	if (lvl < 30)
	{
		message_vision("$N拿起$n，吹了几声，难听的"
			       "一塌糊涂。\n", me, ob);
	} else
	if (lvl < 60)
	{
		message_vision("$N拿起$n，轻轻的吹了几声，"
			       "还算是马马虎虎，不太难听。\n",
			       me, ob);
	} else
	if (lvl < 90)
	{
		message_vision("$N拿起$n，吹了一首" + m_name + "，有点"
			       "箫的意思，颇为不错。\n",
			       me, ob);
	} else
	if (lvl < 150)
	{
		message_vision("$N拿起$n，吹了一首" + m_name + "，颇为"
			       "动人，引人入胜。\n", me, ob);
	} else
	if (lvl < 225)
	{
		message_vision("$N拿起$n，吹了一首" + m_name + "，听得"
			       "众人感慨万千，甚是投入。\n",
			       me, ob);
	} else
	if (lvl < 300)
	{
		message_vision("$N拿起$n，吹了一首" + m_name + "，众人听得"
			       "如痴如醉，似乎有一股清香直沁入心"
			       "肺，妙不可言。\n", me, ob);
	} else
	{
		message_vision("$N拿起$n，吹了一首" + m_name + "，若哀若思"
			       "，众人犹如身临其境，忽悲忽喜，又"
			       "如乘风而行，不知踪影。\n",
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
