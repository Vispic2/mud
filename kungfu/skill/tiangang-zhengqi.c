// xiantian-gong.c 天罡正气
// By kanka

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("xiantian-gong", 1);
        int t = 1, j;
        if (lvl<=100)
                for (j = 1; j < lvl / 10; j++)
                        t*=2;

        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的天罡正气。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("天罡正气讲究阴阳调合，有违道家六根清净之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");

        if(lvl<=100)
        {
                if (lvl > 10 && (int)me->query("shen") < t * 100) 
                        return notify_fail("你的侠义正气太低了。\n");
        }
        else
        {
                if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
                        return notify_fail("你的侠义正气太低了。\n");
        }

        if (!me->query_skill("jiuzhuan-12tian",1) &&(me->query_skill("bibo-shengong",1)
        || me->query_skill("beimin-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("jiuyang-force",1)
        || me->query_skill("wuji-shengong",1)
        || me->query_skill("shenyuan-gong",1)
        || me->query_skill("guiyuan-dafa",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("xuantian-wuji",1)
        || me->query_skill("yunu-xinjing",1)
        || me->query_skill("zixia-shengong",1) ) )
                return notify_fail("你不先散了别派内功，怎能学天罡正气？！\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("天罡正气只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"tiangang-zhengqi/" + func;
}

