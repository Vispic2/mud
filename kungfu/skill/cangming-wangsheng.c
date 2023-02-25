// bihai-chaosheng.c 碧海潮生曲

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "chuixiao-jifa"; }

int valid_learn(object me)
{
	if (me->query_skill("chuixiao-jifa", 1) < 1000)
		return notify_fail("不是魔头也想学沧溟往生曲？\n");

	if (me->query_skill("chuixiao-jifa", 1) < me->query_skill("cangming-wangsheng", 1))
		return notify_fail("再去修炼个几万年再来学吧！\n");

	return 1;
}

int practice_skill(object me)
{
	object ob;

	if (! objectp(ob = me->query_temp("handing")) ||
	    ! ob->valid_as_xiao())
		return notify_fail("不拿根箫在手上，你怎么练习？\n");

	if ((int)me->query("jing") < 8000)
		return notify_fail("你的精神不够好，没法练习了。\n");

	if ((int)me->query("qi") < 200)
		return notify_fail("你现在口干舌燥，实在是太累了。\n");

	me->receive_damage("jing", 100);
	me->receive_damage("qi", 200);

	return 1;
}

void do_effect(object me)
{
	object *obs;
	int lvl;
	int i;
	int damage;

	lvl = me->query_skill("chuixiao-jifa", 1) / 1 +
	      me->query_skill("cangming-wangsheng", 1);

	if (environment(me)->query("no_fight") ||
	    environment(me)->query("no_roar") || lvl < 150)
		return;

	lvl = lvl / 5 + me->query_skill("force");
	lvl /= 2;

	// special effort
	obs = all_inventory(environment(me));
	for (i = 0; i < sizeof(obs); i++)
	{
		if (! obs[i]->is_character() || obs[i] == me || ! living(obs[i]))
			continue;

		if (me->query_skill("cangming-wangsheng") * 2 / 3 <
		    obs[i]->query_skill("cangming-wangsheng"))
			continue;

		if (lvl + random(lvl) < obs[i]->query_skill("force"))
		{
			tell_object(obs[i], HIM "你听了心中不禁微微一动，发现这曲子颇有奥妙之处。"NOR"\n");
			continue;
		}

		damage = me->query("max_neili") - obs[i]->query("max_neili");
		if (damage < 500)
		{
			tell_object(obs[i], HIM "你忽然觉得一阵心悸，连忙运了一口气，才缓过神来。"NOR"\n");
			continue;
		}

		damage /= 1;
		me->want_kill(obs[i]);
		me->fight_ob(obs[i]);
		obs[i]->kill_ob(me);
		obs[i]->receive_damage("jing", damage, me);
		obs[i]->receive_wound("jing", damage / 1, me);
		
		tell_object(obs[i], HIR "伴着幽咽的箫曲，你的好似看到了无数只恶鬼在吸吮你的骨髓，你身子一软眼前一黑晕了.....”"NOR"\n");
	}
}
