//Cracked by Kafei
// feiyu-bian.c 《九阴真经》鞭法
// xQin 8/99 暂名：飞雨飘萍鞭

#include <ansi.h>
#include <combat.h>

inherit SKILL;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int special(object me, object victim, object weapon, int damage);

mapping *action = ({
([	"action" : "蓦地里只见人影闪动，$N飞身而前，一条$w向$n迎面击至，快速无伦的连连进招",
	"damage_type" : "鞭伤"
]),
([	"action" : "$N身法诡异，鞭法奇幻，手中那$w便如灵蛇颤动，竟从半路弯将过来，直奔$n$l",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中的$w犹似一条柔丝，竟如没半分重量，身子忽东忽西，忽进忽退，在$n身周飘荡不定",
	"damage_type" : "鞭伤"
]),
([	"action" : "突然之间，$N身形一闪一晃，疾退数丈，$w从右肩急甩向后，陡地击向$n$l，正如天外游龙，矢矫而至",
	"damage_type" : "鞭伤"
]),
([	"action" : "$N忽地从$n身旁一闪而过，尚未回身，然而背后竟似生了眼睛一般，$w说到便到，直指$n的$l",
	"damage_type" : "刺伤"
]),
([	"action" : "只见$N身影忽高忽低，飘忽灵动、变幻无方，$w回将过来，疾风暴雨般向$n攻击",
	"damage_type" : "鞭伤"
]),
([	"action" : "$N身在半空，如一只青鹤般凌空扑击而下，身法漫妙无比，$w抖出，对准$n天灵盖砸了下去，狠辣迅捷之极",
	"damage_type" : "内伤"
])
});

int valid_enable(string usage)
{
	return usage == "whip" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 20)
                return notify_fail("你的临济十二庄火候太浅。\n");


	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, force, dodge, neili;
	object target = offensive_target(me);

	i = random(sizeof(action));
	force = me->query_skill("force");
	dodge = me->query_skill("dodge");
	neili = me->query("neili");
if (!force) force=10;
if (!dodge) dodge=10;
if (!neili) neili=10;
if (target && me)
{
	if( me->query_temp("perform/chanrao/"+target->name()) )
	{
		me->add("neili", -15);
		me->add("jing", -5);
		me->add_temp("perform/chanrao/"+target->name(), -1);

		if( me->query_temp("perform/chanrao/"+target->name()) < 1 )
		{
			me->delete_temp("perform/chanrao");
			target->start_busy(1);
		}
		else target->start_busy(2);
	}
}
	if( objectp(me->query_temp("secondary_weapon")) )
	{
		force /= 2;
		neili /= 2;
	}

	return ([
		"action": action[i]["action"],
		"force" : (random(force)+force)/2,
		"damage": 150+(random(neili)+neili)/100,
		"dodge" : (random(dodge)+dodge)/10,
		"damage_type": action[i]["damage_type"],
		]);
}

int practice_skill(object me)
{
	notify_fail("你只能用向师傅学的方法来提高这项技能的水平。\n");
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;
weapon = me->query_temp("weapon");
if (me && victim)
{
if (random((int)me->query_skill("feiyu-bian"))>180)
{
victim->receive_damage( "qi", random(400));
victim->receive_wound( "qi", random(200));
                victim->start_busy(1 + random(3));
	return HIR"$N右手一抖，"+ weapon->name() +
	HIC"登时卷成十多个大大小小的圈子，好看已极，\n左手翻处，青光闪动，露出了一把短刀刺中了$n。\n"NOR;
}
if (random(10)>7)
{
	return HIB"$n见到$N这般身法鞭法，如风吹柳絮，水送浮萍，实非人间气象，霎时间宛如身在梦中，心中一寒！\n"NOR;
}
}
}



string perform_action_file(string action)
{
	return __DIR__"feiyu-bian/" + action;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
