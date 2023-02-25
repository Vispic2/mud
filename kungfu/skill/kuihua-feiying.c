inherit SKILL;

string *dodge_msg = ({
"突然$n对着$N轻轻吹了口气，$N只觉得香风扑面，忙向后纵出丈许避开。\n",
"$N只觉眼前白光一闪，$n的人影已经站在两丈开外，$N的招式全部打在空处。\n",
"$n身子一晃，$N的眼前顿时出现了四个$n的身形，当真不知哪个是真哪个是假。\n",
"$n身形一转，向后闪出尺余，在电光火石之间逼过了$N的攻击。\n",
"$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。\n",
"$N眼睛一花，便没了$n的踪影。回头一看，$n已经站在$N的身后。\n",
"$n一声长笑，身子倒纵出去，已离开$N有三丈远近，侧头向$N瞪视，一言不发。\n"
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") || (usage == "move"); 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jing") < 40 )
                return notify_fail("你的体力太差了，不能练习葵花飞影术。\n");
        me->receive_damage("jing", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kuihua-feiying/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
