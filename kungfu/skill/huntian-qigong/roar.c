// roar.c 长啸

#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "纵声"ZJBR"长啸"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;

	if ((int)me->query("neili") < 600)
		return notify_fail("你的真气不够。\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("在这里不能攻击他人。\n");

	skill = me->query_skill("force");

	me->add("neili", -150);
	me->receive_damage("qi", 10);

	me->start_busy(5);
	message_combatd(HIY "$N" HIY "深吸一囗气，运足内力，发出一阵"
			"长啸，音传百里，慑人心神！"NOR"\n", me);

	ob = all_inventory(environment(me));
	for (i = 0; i < sizeof(ob); i++)
	{
		if (! living(ob[i]) || ob[i] == me) continue;
		if (skill / 2 + random(skill / 2) < (int)ob[i]->query("con") * 2)
			continue;

		if (userp(ob[i]) && !ob[i]->die_protect(me))
			continue;

		damage = skill - ((int)ob[i]->query("max_neili") / 10);
		if (damage > 0)
		{
			ob[i]->receive_damage("jing", damage * 2, me);
			if ((int)ob[i]->query("neili") < skill * 2)
				ob[i]->receive_wound("jing", damage, me);
			tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n");
		}

		me->want_kill(ob[i]);
		ob[i]->kill_ob(me);
	}

    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
