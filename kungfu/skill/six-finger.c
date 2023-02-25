// six-finger.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name"  : "少商剑",
	"action": "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“" HIW "少商剑" NOR "”有如石破天惊、风雨大至之势，指向$n的$l",
	"force" : 390,
	"attack": 160,
	"dodge" : 90,
	"parry" : 110,
	"damage": 160,
	"damage_type":  "刺伤"
]),
([      "name"  : "商阳剑",
	"action": "$N食指连动，手腕园转，“" HIR "商阳剑" NOR "”一剑又一剑的刺出，轻灵迅速，奇巧活泼，剑气纵横，无人能够看清剑气的来路",
	"force" : 370,
	"attack": 165,
	"dodge" : 110,
	"parry" : 115,
	"damage": 180,
	"damage_type":  "刺伤"
]),
([      "name"  : "中冲剑",
	"action": "$N右手中指一竖，“" HIY "中冲剑" NOR "”向前刺出。真气鼓荡，嗤然声响，无形剑气直指$n的$l",
	"force" : 490,
	"attack": 155,
	"dodge" : 100,
	"parry" : 90,
	"damage": 220,
	"damage_type":  "刺伤"
]),
([      "name"  : "关冲剑",
	"action": "$N右手无名指伸出，“" HIY "关冲剑" NOR "”剑路拙滞古朴，一股雄浑无比的内力鼓荡而出，如排山倒海一般向$n涌去",
	"force" : 460,
	"attack": 160,
	"dodge" : 100,
	"parry" : 115,
	"damage": 180,
	"damage_type":  "刺伤"
]),
([      "name"  : "少泽剑",
	"action": "$N左手小指一伸，一条气流从少冲穴中激射而出，“" HIW "少泽剑" NOR "”出手入风，指向$n的$l",
	"force" : 430,
	"attack": 150,
	"dodge" : 95,			    
	"parry" : 112,
	"damage": 170,
	"damage_type":  "刺伤"
]),
([      "name"  : "少冲剑",
	"action": "$N右手反指，小指伸出，真气自少冲穴激荡而出，“" HIW "少冲剑" NOR "”横生奇变，从那意想不到的方向刺向$n的$l",
	"force" : 330,
	"attack": 160,
	"dodge" : 90,
	"parry" : 115,
	"damage": 140,
	"damage_type":  "刺伤"
]),
});

string main_skill() { return "six-finger"; }

mapping sub_skills = ([
	"shaoshang-sword"  : 120,
	"shangyang-sword"  : 120,
	"zhongchong-sword" : 120,
	"guanchong-sword"  : 120,
	"shaoze-sword"     : 120,
	"shaochong-sword"  : 120,
	]);

int get_ready(object me)
{
	return 1;
}

int get_finish(object me)
{
	if (me->query("int") < 32)
	{
		tell_object(me, "你演练完毕，觉得六剑没什么关系，不禁一片茫然。\n");
		return 0;
	}

	if (me->query("con") < 26)
	{
		tell_object(me, "你演练完毕，就觉得眼前金星乱冒，太阳穴突突的跳。\n");
		return 0;
	}

	if (me->query_skill("literate", 1) < 200)
	{
		tell_object(me, "你觉得六脉神剑极其深奥，看来多研究一下学问可能更有帮助。\n");
		return 0;
	}

	if (me->query_skill("lamaism", 1) < 200)
	{
		tell_object(me, "你演练完毕，发现如果通晓密宗心法应该更有帮助。\n");
		return 0;
	}

	if (me->query_skill("buddhism", 1) < 200)
	{
		tell_object(me, "你演练完毕，发现如果通晓禅宗心法应该更有帮助。\n");
		return 0;
	}

	if ((int)me->query("max_neili") < 3000)
	{
		tell_object(me, "你觉得真气不继，无法融会贯通六剑。\n");
		return 0;
	}

	if (random(10) < 7)
	{
		tell_object(me, "你觉得有所感悟，或许再演练一次就能融会贯通，练成六脉神剑。\n");
		return 0;
	}

	tell_object(me, HIY "一阵凡尘往事涌上心头，你几欲放声长叹。眼前不断闪现出六脉剑法，\n"
			    "霎那间，你终于通晓六脉神剑。"NOR"\n");
	return 1;
}

mapping query_sub_skills()
{
	return sub_skills;
}

int valid_enable(string usage) { return usage == "finger" ||  usage == "parry"; }

int double_attack() { return 1; }

int valid_learn(object me)
{
	if (me->query("int") < 32)
		return notify_fail("你研究了半天，也没能理解六脉神剑的奥妙。\n");

	if (me->query("con") < 26)
		return notify_fail("你研究了一会儿，只觉得眼前金星乱冒，太阳穴突突的跳。\n");

	if (me->query_skill("literate", 1) < 200)
		return notify_fail("你觉得六脉神剑极其深奥，不是你这种学问水平所能研究的。\n");

	if (me->query_skill("lamaism", 1) < 200)
		return notify_fail("你发现这里面有很多奥妙都和密宗心法有关，难以理解。\n");

	if (me->query_skill("buddhism", 1) < 200)
		return notify_fail("你发现这里面有很多奥妙都和禅宗心法有关，难以理解。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练六脉神剑必须空手。\n");

	if ((int)me->query("max_neili") < 3000)
		return notify_fail("你的内力太弱，无法学六脉神剑。\n");

	if ((int)me->query_skill("finger", 1) < 120)
		return notify_fail("你的基本指法火候不够。\n");

	if ((int)me->query_skill("finger", 1) < (int)me->query_skill("six-finger", 1))
		return notify_fail("你的基本指法水平有限，无法无法领会更高深的六脉神剑。\n");

	return 1;
}

string query_skill_name(int level)
{
	int i;
	for (i = sizeof(action); i > 0; i--)
		if (level >= action[i - 1]["lvl"])
			return action[i - 1]["skill_name"];
}

int practice_skill(object me)
{
	int cost;

	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
	cost = me->query_skill("six-finger", 1) / 2 + 160;
	if ((int)me->query("neili") < cost)
		return notify_fail("你的内力不够练六脉神剑。\n");
	me->receive_damage("qi", 80);
	me->add("neili", -cost);
	return 1;
}					  

mixed hit_ob(object me, object victim, int damage_bonus)
{

if(me->query("six-finger_zj")){
	if (random(5) >= 3||me->query("family/family_name") == "段氏皇族")
	{
		victim->receive_wound("qi", damage_bonus / 2);
		if (wizardp(me)) 
		tell_object(me, HIR"打上限 -"+damage_bonus/2+"。"NOR"\n");
		return HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！"NOR"\n";
	}
	}else{
	
	if (random(10) >= 7||me->query("family/family_name") == "段氏皇族")
	{
		victim->receive_wound("qi", damage_bonus / 2);
		if (wizardp(me)) 
		tell_object(me, HIR"打上限 -"+damage_bonus/2+"。"NOR"\n");
		return HIR "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！"NOR"\n";
	}
	
	
	}
	
	
}

mapping query_action(object me, object weapon)
{
	if (! undefinedp(me->query_temp("six-action")))
		return action[me->query_temp("six-action")];

	if (random(10) == 8)
	{
		me->add("neili", -200);
		return ([
	"action": HIC "$N" HIC "忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，连绵无尽。\n"
		      HIC "顿时只见四处剑气纵横，尘烟四起，六路剑法回转运使，$n" HIC "顿时心神大乱，但觉全身几处刺\n"
		      HIC "痛，几股" HIR "鲜血" HIC "从身上飙出。忍痛抬头一"
		      "看，一柱剑气迎面又到" NOR,
	"attack": 140,
	"dodge" : 150,
	"parry" : 120,
	"damage": 270,
	"force" : 580,
	"damage_type": "刺伤"]);
	}
	return action[random(sizeof(action))];
}

// here: the attacker is $N, and you, the defenser is $n
string query_parry_msg(object victim_weapon)
{
	switch (random(4))
	{
	case 0:
		return "$n随意挥洒，道道剑气纵横交错，宛若天网，$N唯有望洋兴叹，徒呼奈何。\n";
	case 1:
		return "$n不闪不避，一招中冲剑直袭$N的胸前大穴，迫得$N只有回身自救。\n";
	case 2:
		return "$n六剑连出，剑气回荡，直割得$N眉毛削落，脸面生痛，再也不能前进半分！\n";
	default:
		return "$n一声长笑，无形剑气四处散开，将$N层层裹住，惟有勉强支撑。才约略摆脱了$n的反击。\n";
	}
}

void skill_improved(object me)
{
	int i;
	string *sub_skillnames;
	sub_skillnames = keys(sub_skills);
	for (i = 0; i < sizeof(sub_skillnames); i++)
		me->delete_skill(sub_skillnames[i]);
}

string perform_action_file(string action)
{
	return __DIR__"six-finger/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
