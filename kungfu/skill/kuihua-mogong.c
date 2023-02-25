// kuihua-shengong 葵花魔功

inherit FORCE;

string *dodge_msg = ({
	"$n微微一动，已然远去，使$N的进攻全然无用。\n",
	"$n霎时间平移了数步，如鬼如魅，使$N全然无法掌握。\n",
	"$n忽的一退，闪去天下任何追击。\n",
	"$n足不离地，腰肢猛摆，居然将$N的进攻全部躲过。\n",
});

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("kuihua-mogong", 1);
	return lvl * lvl * 20 * 15 / 100 / 200;
}

mapping *actionf = ({
([      "action":"$N倏的近前，身形快极，手指戳向$n的$l",
	"force" : 410,
	"attack": 172,
	"dodge" : 120,
	"parry" : 60,
	"damage": 150,
	"damage_type":  "刺伤"
]),
([      "action":"$N扑向前来，身形如同鬼魅，令人难以捉摸，手指忽的刺向$n的$l",
	"force" : 410,
	"attack": 180,
	"dodge" : 90,
	"parry" : 70,
	"damage": 160,
	"damage_type":  "刺伤"
]),
([      "action":"$N身形一转，手指刺出，直指$n的$l",
	"force" : 430,
	"attack": 175,
	"dodge" : 90,
	"parry" : 50,
	"damage": 170,
	"damage_type":  "刺伤"
]),
([      "action":"$N飘然远去，忽又进前，速度快的不可思议，一指如闪电般刺向$n的$l",
	"force" : 425,
	"attack": 180,
	"dodge" : 85,
	"parry" : 65,
	"damage": 150,
	"damage_type":  "刺伤"
]),
([      "action":"$N身体一晃，突然飞起一脚，踢向$n的$l",
	"force" : 430,
	"attack": 170,
	"dodge" : 90,
	"parry" : 55,
	"damage": 160,
	"damage_type":  "瘀伤"
]),
([      "action":"$N足下疾走，身形变幻莫测，突然一指插向$n的$l",
	"force" : 440,
	"attack": 185,
	"dodge" : 115,
	"parry" : 55,
	"damage": 180,
	"damage_type":  "刺伤"
]),
});

mapping *actionw = ({
([      "action":"$N倏的近前，身形快极，手中的$w戳向$n的$l",
	"force" : 330,
	"attack": 200,
	"dodge" : 130,
	"parry" : 40,
	"damage": 160,
	"damage_type":  "刺伤"
]),
([      "action":"$N扑向前来，身形如同鬼魅，令人难以捉摸，手中的$w忽的刺向$n的$l",
	"force" : 330,
	"attack": 185,
	"dodge" : 120,
	"parry" : 45,
	"damage": 190,
	"damage_type":  "刺伤"
]),
([      "action":"$N身形一转，$w刺出，直指$n的$l",
	"force" : 355,
	"attack": 210,
	"dodge" : 120,
	"parry" : 45,
	"damage": 200,
	"damage_type":  "刺伤"
]),
([      "action":"$N飘然远去，忽又进前，速度快的不可思议，$w如闪电般刺向$n的$l",
	"force" : 345,
	"attack": 190,
	"dodge" : 135,
	"parry" : 55,
	"damage": 180,
	"damage_type":  "刺伤"
]),
([      "action":"$N身体一晃，突然飞起一脚踢向$n的下阴，蓦的又收回，反手$w刺向$n的$l",
	"force" : 360,
	"attack": 180,
	"dodge" : 120,
	"parry" : 57,
	"damage": 210,
	"damage_type":  "刺伤"
]),
([      "action":"$N足下疾走，身形变幻莫测，突然一扬手，$w飞也似的插向$n的$l",
	"force" : 340,
	"attack": 200,
	"dodge" : 135,
	"parry" : 50,
	"damage": 190,
	"damage_type":  "刺伤"
]),
});

string *usage_skills = ({ "sword", "dodge",
			  "parry", "force" });

int valid_enable(string usage)
{
	return (member_array(usage, usage_skills) != -1) ||
	       usage == "unarmed" || usage == "finger";
}

int valid_combo(string combo)
{
	return combo == "kuihua-mogong";
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
	return weapon ? actionw[random(sizeof(actionw))] :
			actionf[random(sizeof(actionw))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	int level;
	int i;

	if ((int)me->query("combat_exp") < 3000000 && !me->query("relife/zhuanshi"))
		return notify_fail("你觉得葵花魔功深奥之极，"
				   "凭自己的战斗经验一时间难以领会。\n");

	if ((int)me->query_skill("martial-cognize", 1) < 50)
		return notify_fail("你觉得葵花魔功过于深奥之极，以"
				   "自己的武学修养全然无法明白。\n");

	if (me->query("character") != "阴险奸诈")
		return notify_fail("你看了葵花魔功这些阴险毒辣的武功，不"
				   "由的心惊肉跳，难以领会。\n");

	if (me->query("dex") < 22 && me->query_dex() < 63)
		return notify_fail("你觉得自己的身法不行，不可能掌握这么飘缈"
				   "玄奇的葵花魔功。\n");

	level = me->query_skill("kuihua-mogong", 1);

	if ((int)me->query_skill("martial-cognize", 1) < 300 &&
	    (int)me->query_skill("martial-cognize", 1) < level && !me->query("relife/zhuanshi"))
		return notify_fail("你觉得自己的武学修养有限，难以领会更高深的葵花魔功。\n");

	for (i = 0; i < sizeof(usage_skills); i++)
		if (me->query_skill(usage_skills[i], 1) < level)
			return notify_fail("你对" + to_chinese(usage_skills[i]) +
					   "的理解还不够，无法继续领会更高深的葵花魔功。\n");

	if (me->query_skill("finger", 1) < level &&
	    me->query_skill("unarmed", 1) < level)
		return notify_fail("你需要领会更高境界的指法和拳脚功夫才能继续研究葵花魔功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("葵花魔功博大精深，无法简单的通过练习进步。\n");
}

int difficult_level()
{
     object me; 
     int lv;
     me = this_player(); 
     lv = me->query_skill("pixie-jian", 1) - 180; 
     if (lv > 100) lv = 100; 
     
     if (! me->query("special_skill/ghost"))
	return 1000;
     else
	return 500 - lv;
}

string perform_action_file(string action)
{
	return __DIR__"kuihua-mogong/perform/" + action;
}

string exert_function_file(string action)
{
	return __DIR__"kuihua-mogong/exert/" + action;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
