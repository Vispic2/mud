// bingxue-xinfa.c  冰雪心法
// By lucas

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	mapping skl;
	string *sname;
        skl = me->query_skills();
        sname = keys(skl);
        if ((int)me->query_skill("force", 1) < 10)
               return notify_fail("你的基本内功火候还不够，还不能学习冰雪心法。\n");

	if (
	me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang-gong",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) ||
me->query_skill("zixia-shengong",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("huashan-xinfa",1))
                return notify_fail("你不先散了别派内功，怎能学冰雪心法？！\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("冰雪心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"bingxue-xinfa/" + func;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
