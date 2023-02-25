// 武学修养

inherit SKILL;

int valid_learn(object me)
{
	return notify_fail("武学修养是你武学方面的领悟，无法通过简单学习获得提升。\n");
}

int valid_research(object me)
{
	return notify_fail("武学修养来自你对实战体会的汲取吸收，无法通过研究提升。\n");
}
void skill_improved(object me)
{
	int wa,ma,xiuyang;
   wa = me->query_skill("sword-cognize",1);
	 ma = me->query_skill("martial-cognize",1);
	xiuyang = wa > ma ?(wa * 3/4 + ma * 1/2) : (ma * 3/4 + wa * 1/2);
		if(me->query("xiuyang")!=xiuyang)
		me->set("xiuyang",xiuyang);
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
