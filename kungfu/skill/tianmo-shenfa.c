
// tianmo-shenfa.c 天魔身法
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
        "只见$n身随意转，一扭身已飘到$N背后，躲过了这一招。\n",
        "$n运起天魔身法，身影有如疾电流窜，令$N的攻势全数落空。\n",
        "$N只感眼前一花，$n已幻化成无数化身四散飞射。\n"
        "$n身影突如陀螺急转，形成猛烈的气劲漩涡，坚密如墙，$N根本无从入手。\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { 

      /*  mapping myfam;
        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "圣剑山庄"|| myfam["master_id"] != "a fei")
                return notify_fail("天魔身法只能向魔剑阿飞学习。\n");*/
        if ((int)me->query_skill("tianmo-shenfa",1) > 500)
                return notify_fail("这套身法法我就教到这儿，以后就要靠你自己练了。\n");

return 1; 
}

string query_dodge_msg(string limb, object me)
{
        if (me) me->set_temp("fight/dodge",3*me->query_skill("tianmo-shenfa",1));
        return dodge_msg[random(sizeof(dodge_msg))];

}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练天魔身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}
