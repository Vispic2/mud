// luoying-zhang.c 落英神掌
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "action" : "$N双手平伸，向外掠出，一式「"+GRN+"春云乍展"+NOR+"」，指尖轻盈漂动，"
		   "轻轻反点$n的$l",
	"force" : 40,
	"dodge" : 15,
	"lvl"   : 0,
	"damage_type" : "瘀伤",
	"skill_name" : GRN"春云乍展"NOR
]),
([      "action" : "$N右手五指缓缓一收，一式「"+BLU+"回风拂柳"+NOR+"」，五指忽然遥遥拂向$n，"
		   "$n只觉得五股疾风袭向自己五处大穴",
	"force" : 60,
	"dodge" : 20,
	"lvl"   : 10,
	"damage_type" : "内伤",
	"skill_name" : BLU"回风拂柳"NOR
]),
([      "action" : "$N突然纵身跃入半空，单掌劈落，一式「"+HIM+"江城飞花"+NOR+"」，拍向$n的头顶",
	"force" : 80,
	"dodge" : 25,
	"lvl"   : 20,
	"damage_type" : "瘀伤",
	"skill_name" : HIM"江城飞花"NOR
]),
([      "action" : "$N突然跃起，双手连环，运掌如剑，势如疾风电闪，一式「"+HIR+"雨急风"
		   "狂"+NOR+"」，攻向$n的全身",
	"force" : 100,
	"dodge" : 25,
	"lvl"   : 30,
	"damage_type" : "瘀伤",
	"skill_name" : HIR"雨急风狂"NOR
]),
([      "action" : "$N左手挥起，掌心朝天，伸出右手并拢食指中指，捻个剑决，一式"
		   "「"+HIB+"星河在天"+NOR+"」，直指$n的中盘",
	"force" : 130,
	"dodge" : 20,
	"lvl"   : 40,
	"damage_type" : "瘀伤",
	"skill_name" : HIB"星河在天"NOR
]),
([      "action" : "$N突然抽身而退，接着一式「"+HIC+"流华纷飞"+NOR+"」，平身飞起，双掌向$n"
		   "的后脑连拍数掌",
	"force" : 150,
	"dodge" : 35,
	"lvl"   : 60,
	"damage_type" : "瘀伤",
	"skill_name" : HIC"流华纷飞"NOR
]),
([      "action" : "$N突然抽身跃起，左掌挟着劲风汹涌拍出，接着右掌自左掌后突地"
		   "伸出，一式「"+HIB+"彩云追月"+NOR+"」抢在左掌前向$n的$l拍去",
	"force" : 170,
	"dodge" : 45,
	"lvl"   : 70,
	"damage_type" : "瘀伤",
	"skill_name" : HIB"彩云追月"NOR
]),
([      "action" : "$N使一式「"+YEL+"天如穹庐"+NOR+"」，全身突然飞速旋转，双掌忽前忽后，猛"
		   "地拍向$n的胸口",
	"force" : 200,
	"dodge" : 35,
	"lvl"   : 80,
	"damage_type" : "瘀伤",
	"skill_name" : YEL"天如穹庐"NOR
]),
([      "action" : "$N前后一揉，一式「"+HIG+"朝云横度"+NOR+"」，化掌如剑，一股凌厉剑气袭向$n"
		   "的下盘",
	"force" : 240,
	"dodge" : 45,
	"lvl"   : 90,
	"damage_type" : "内伤",
	"skill_name" : HIG"朝云横度"NOR
]),
([      "action" : "$N使一式「"+BLU+"白虹经天"+NOR+"」，双掌舞出无数圈劲气，一环环向$n的$l"
		   "斫去",
	"force" : 270,
	"parry" : 25,
	"dodge" : 50,
	"lvl"   : 100,
	"damage_type" : "内伤",
	"skill_name" : BLU"白虹经天"NOR
]),
([      "action" : "$N双手食指和中指一和，一式「"+HIR+"紫气东来"+NOR+"」，一股强烈的气流涌向"
		   "$n的全身",
	"force" : 290,
	"parry" : 25,
	"dodge" : 55,
	"lvl"   : 120,
	"damage_type" : "内伤",
	"skill_name" : HIR"紫气东来"NOR
]),
([      "action" : "$N一式「"+HIY+"落英漫天"+NOR+"」，双掌在身前疾转，掌花飞舞，铺天盖地直指"
		   "向$n。$n只见漫天掌花，眼花缭乱。",
	"force" : 320,
	"parry" : 30,
	"dodge" : 65,
	"damage_type" : "瘀伤",
	"lvl" : 140,
	"skill_name" : HIY"落英漫天"NOR
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; } 

int valid_combine(string combo) { return combo=="xuanfeng-leg"; }

int valid_learn(object me)
{
    	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练落英神剑掌必须空手。\n");

    	if ((int)me->query_skill("force") < 80)
		return notify_fail("你的内功火候不够，无法学落英神剑掌。\n");

    	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力太弱，无法练落英神剑掌。\n");

    	if ((int)me->query_skill("strike", 1) < (int)me->query_skill("luoying-shenzhang", 1))
		return notify_fail("你的基本掌法水平有限，无法领会更高深的落英神剑掌。\n");

    	return 1;
}

string query_skill_name(int level)
{
    	int i;
    	for (i = sizeof(action)-1; i >= 0; i--)
		if (level >= action[i]["lvl"])
	    		return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    	int i, level;
    	level = (int)me->query_skill("luoying-shenzhang", 1);
    	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
	    		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");

    	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练落英神剑掌。\n");

    	me->receive_damage("qi", 45);
    	me->add("neili", -40);
    	return 1;
}
//等级提升，是否学会新的招式
string query_skill_up(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	 {
		if(level == action[i]["lvl"])
		 {
		     return action[i]["skill_name"];
		 }
	 }
	  return "no";
}

string perform_action_file(string action)
{
    	return __DIR__"luoying-shenzhang/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
