inherit SKILL;
#include "/kungfu/skill/eff_msg.h";


string *parry_msg = ({
	HIC"一刹那间$n化刚为柔的急剧转折，已使出属《不灭体》神功！\n"NOR,
	RED"结果$n使出《不灭体》，倒反了$n这招的去势。\n"NOR,
	HIW"$n动也不动，待他进到身前，《不灭体》内力斜引，将他力道推卸了开去！\n"NOR,
	BLU"$N一招击在$n身上，却被$n暗运《不灭体》，保护了全身。\n"NOR,
	YEL"蓦地里好象旁边有一股力道飞来，将$N的力道一引，从$N身旁斜斜带过！\n"NOR,
	YEL"$n当下潜运《不灭体》，使$N击向$n的一招莫名奇妙的溜滑向一旁。\n"NOR,
	HIR"$n再使《不灭体》，一牵一引，托的一响，将$n的力道引偏。\n"NOR,
	YEL"$n右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拔，上身半点不动，将$N此招化于无形！\n"NOR,
	WHT"$n巧运《不灭体》，使$n这招莫名其妙的在中途转了方向，力道化于无形！\n"NOR,
});

string *unarmed_parry_msg = ({
	HIC"一刹那间$n化刚为柔的急剧转折，已使出属《不灭体》神功！\n"NOR,
	RED"结果$n使出《不灭体》，倒反了$n这招的去势。\n"NOR,
	HIW"$n动也不动，待他进到身前，《不灭体》内力斜引，将他力道推卸了开去！\n"NOR,
	BLU"$N一招击在$n身上，却被$n暗运《不灭体》，保护了全身。\n"NOR,
	YEL"蓦地里好象旁边有一股力道飞来，将$N的力道一引，从$N身旁斜斜带过！\n"NOR,
	YEL"$n当下潜运《不灭体》，使$N击向$n的一招莫名奇妙的溜滑向一旁。\n"NOR,
	HIR"$n再使《不灭体》，一牵一引，托的一响，将$n的力道引偏。\n"NOR,
	YEL"$n右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拔，上身半点不动，将$N此招化于无形！\n"NOR,
	WHT"$n巧运《不灭体》，使$n这招莫名其妙的在中途转了方向，力道化于无形！\n"NOR,
});



string *dodge_msg = ({
        HIC"但见$n施展《不灭体》，左一转，右一斜，就已经绕到了$N的身後。\n",NOR
        RED"可是$n施展《不灭体》，只是轻描淡写地向旁踏出一步，就巧妙地避开了$N的攻势。\n",NOR
        YEL"只见$n身影滴溜溜地一转，体迅飞鸟，飘忽若神，施展的正是《不灭体》。\n",NOR
        WHT"$N只觉得眼前一花，头脑发昏，只觉得四面都是$n的身影！\n",NOR
        BLU"$n左脚轻轻地踏出一步，施展《不灭体》，若往若返，把$N牵得团团乱转。\n",NOR
});

int valid_enable(string usage)
{
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(object weapon,string limb)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_learn(object me)
{



    int lvl = (int)me->query_skill("bumieti", 1);

	// if (lvl < 1  )
	// 	return notify_fail("你不能直接学习！\n");

    if ((int)me->query_skill("force", 1) < 100)
        return notify_fail("就这么点基本内功还想学"+HIY+"《不灭体》"+NOR+"？\n");

	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("就这么点内力还想学"+HIY+"《不灭体》"+NOR+"？\n");

    if ((int)me->query_skill("force", 1) < lvl)
        return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");

	if ((int)(me->query("max_neili", 1)/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！\n");

        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练"+HIY+"《不灭体》"+NOR+"。\n");
        me->receive_damage("qi", 40);
        return 1;
}
int ob_hit(object ob, object me, int damage)
{
	int neili,a;
    if (!me->is_ghost() && living(me)
        && me->is_fighting() && me->query("neili") > 800 )
	{

		if(random(5)==1)
		{ 
            if(me->query("qi") < (int)me->query("max_qi"))
			{
				message_vision(HIW"$N运起《不灭体》，保护了$N全身！\n"NOR, me,ob);
                message_vision(HIY"《不灭体》护体神功为$N吸收了大量伤害，伤势慢慢好转。\n"NOR,me,ob);
                me->add("neili", -180);
                me->add("eff_qi",me->query_skill("force")/2);
				if (me->query("eff_qi") > me->query("max_qi"))
					me->set("eff_qi", me->query("max_qi"));
                    me->add("qi",me->query_skill("force"));
				if (me->query("qi") > me->query("eff_qi"))
					me->set("qi", me->query("eff_qi"));
            }
		}
		if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
		{
			if (!ob->is_busy())
				ob->start_busy(4);
			message_vision(WHT"$n被《不灭体》反震得不能动弹!\n"NOR, me,ob);
		}
		message_vision(HIG"$n所有的攻击全打在了《不灭体》的气墙上！\n"NOR, me,ob);
		  return 0;
	}
	else
		return damage;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
