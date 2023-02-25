// regenerate.c

int exert(object me, object target)
{
	int neili_cost;
	int lvl;
	int heal;

	if (target != me)
		return notify_fail("你只能用内功恢复自己的精力。\n");
	
	if (! me->query_skill_mapped("force"))
		return notify_fail("你必须先激发所使用的内功。\n");

	heal = (int)me->query("eff_jing") - (int)me->query("jing");
	if (heal < 10)
		return notify_fail("你现在精气旺盛。\n");

	lvl = me->query_skill("force");
	if (lvl <= 0) lvl = 1;
	neili_cost = heal * 60 / lvl;
	if (me->query("breakup"))
		neili_cost = neili_cost * 7 / 10;
	if (neili_cost < 20) neili_cost = 20;
	if (neili_cost > me->query("neili"))
	{
		neili_cost = me->query("neili");
		heal = neili_cost * lvl / 60;
	}
	if (neili_cost < 20) neili_cost = 20;

	if ((int)me->query("neili") < neili_cost)
		return notify_fail("你的内力不够。\n");

	me->add("neili", -neili_cost);
	me->receive_heal("jing", heal);
	
	if (me->is_fighting())
	message_vision("$N深深吸了几口气，精神看起来好多了。\n", me);
        else tell_object(me, "你深深吸了几口气，精神看起来好多了。\n");
        //else write("你深深吸了几口气，精神看起来好多了。\n");

	if (me->is_fighting()) me->start_busy(2);
	
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
