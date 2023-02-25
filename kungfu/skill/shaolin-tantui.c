/* 
   shaolin-tantui.c 少林弹腿
   和龙爪功(weituo-zhang)互备
   截自《少林拳法》，取其十七，十八，二十三至三十式。
   1/3/98 by snowman
*/

inherit SKILL;

mapping *action = ({
([      "action" : "$N使出「采刁踢」，左手以采刁手由上向前勾落，同时，左腿以勾腿式向$n$l勾踢而出",
	"force" : 50,
	"dodge" : 40,
	"lvl" : 0,
	"skill_name" : "采刁踢",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N将身体重心移至左脚，使右脚离地蓄劲，一招「套步踢」，右腿以勾腿式由上向前勾落",
	"force" : 60,
	"dodge" : 35,
	"lvl" : 0,
	"skill_name" : "套步踢",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N右手化掌，向前直采而出，使出「翻身拦打」，右脚原地跺步，使身体转向$n踢出",
	"force" : 70,
	"dodge" : 20,
	"lvl" : 20,
	"skill_name" : "翻身拦打",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N收左手，右手原地向前架采而出，右脚顺势向$n$l直踢，正是一式「进步架打」",
	"force" : 80,
	"dodge" : 25,
	"lvl" : 20,
	"skill_name" : "进步架打",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N将重心放至右脚，使左脚放虚，一招「回步冲捶」，向左原地转回，膝盖顺势抵向$n$l",
        "force" : 100,
	"dodge" : 15,
	"lvl" : 40,
	"skill_name" : "回步冲捶",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N左掌向前直撑，封住底盘，一式「托按侧蹬」，右腿转身以反蹬腿向$n蹬出",
        "force" : 120,
	"dodge" : 25,
	"lvl" : 40,
	"skill_name" : "托按侧蹬",
	"damage_type" : "内伤"
]),
([      "action" : "$N一招「采刁撑腿」，左掌护住右腕不动，右手原地向外翻手抓采，接著左脚前踢$n",
        "force" : 140,
	"dodge" : 25,
	"lvl" : 60,
	"skill_name" : "采刁撑腿",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N左掌原地回圈，向前封出，一招「扭步挟肘」，右脚猛然拖进，向$n下盘猛踢三脚",
        "force" : 160,
	"dodge" : 10,
	"lvl" : 60,
	"skill_name" : "扭步挟肘",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N双手化十字手，交叉於胸前，使出「并步迎抄」，双腿一跃，并踢$n$l",
        "force" : 180,
	"dodge" : 20,
	"lvl" : 80,
	"skill_name" : "并步迎抄",
	"damage_type" : "瘀伤"
]),
([      "action" : "$N跟着又是一招「并步迎抄」，十字手顺势向上双抄後，双腿凌空再次踢向$n",
        "force" : 200,
	"dodge" : 15,
	"lvl" : 100,
	"skill_name" : "并步迎抄",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"; }

int valid_combine(string combo){
        if(this_player()->query_skill("shaolin-tantui", 1) > 150
	   && this_player()->query_int() > 45)
   	         return combo=="weituo-zhang";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("学少林弹腿时手里不能拿武器。\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 10)
		return notify_fail("你的本门内功火候不够，无法练韦驮掌。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练少林弹腿。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;

	level   = (int) me->query_skill("shaolin-tantui",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jing") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练少林弹腿。\n");
	me->receive_damage("jing", 25);
	me->receive_damage("neili", -5);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
