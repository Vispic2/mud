inherit FORCE;

int valid_enable(string usage)
{
            return usage == "force";
}

int valid_force(string force)
{
        return force == "yijinjing" ||
               force == "fenxin-jue";
}

int valid_learn(object me)
{
         
            return ::valid_learn(me);
}

int practice_skill(object me)
{
            return notify_fail("绝情心法只能用学(learn)的来增加熟练度。\n");
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
