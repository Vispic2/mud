// wushe-qu.c 舞蛇曲

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "guzheng-jifa"; }

int valid_learn(object me)
{
	if (me->query_skill("guzheng-jifa", 1) < 100)
		return notify_fail("你的古筝技法水平不够，还是先练好再说吧！\n");

	if (me->query_skill("guzheng-jifa", 1) < me->query_skill("wushe-qu", 1))
		return notify_fail("你的古筝技法水平有限，无法领会更精妙的舞蛇曲。\n");

	return 1;
}

int practice_skill(object me)
{
	object ob;

	if (! objectp(ob = me->query_temp("handing")) ||
	    ! ob->valid_as_zheng())
		return notify_fail("不拿出筝来，你怎么练习？\n");

	if ((int)me->query("jing") < 80)
		return notify_fail("你的精神不够好，没法练习了。\n");

	if ((int)me->query("qi") < 30)
		return notify_fail("你现在实在是太疲惫了。\n");

	me->receive_damage("jing", 25);
	me->receive_damage("qi", 15);

	return 1;
}

void do_effect(object me)
{
	object env;
	int lvl;
	string *sn;
	object *obs;
	object ob;

	lvl = me->query_skill("guzheng-jifa", 1) / 2 +
	      me->query_skill("wushe-qu", 1);

	if ((env = environment(me))->query("no_fight"))
		return;

	if (lvl < 50)
	{
		write("你满头大汗的弹了半天，好像没有什么作用。\n");
		return;
	}

	if (me->query("neili") < 50)
	{
		me->set("neili", 0);
		write("你隐隐觉得内力有些不济。\n");
		return;
	}

	me->add("neili", -20 - random(10));

	if (! arrayp(sn = env->query("resource/snake")))
	{
		write("你弹了半天，但是没有一条蛇出来。\n");
		return;
	}

	obs = filter_array(all_inventory(env), (: $1->is_snake() :));
	if (sizeof(obs) > 12 || random(150 + lvl) < 150)
	{
		write("你弹了半天，但是似乎没有什么蛇出来。\n");
		return;
	}

	ob = new(sn[random(sizeof(sn))]);
	ob->add("snake_poison/level" + random(lvl / 5));
	ob->move(env);
	write("你弹了一曲，只听一阵嗤嗤做响，一条" + ob->name() +
	      "从草丛中窜了出来。\n");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
