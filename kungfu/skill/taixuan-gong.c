// taixuan-gong.c 侠客岛太玄功
// Jay 4/5/96
// modified by Venus Oct.1997
inherit FORCE;

string *dodge_msg = ({
	"$n左手拍出，劲风到处，把$N震到一边。\n",
	"$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
	"$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
	"$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("taixuan-gong", 1);
	return lvl * lvl * 15 * 18 / 100 / 200;
}

mapping *action = ({
([      "action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
	"force" : 450,
	"attack": 150,
	"dodge" : 70,
	"parry" : 80,
	"damage": 95,
	"damage_type":  "瘀伤"
]),
([      "action":"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去",    
	"force" : 470,
	"attack": 140,
	"dodge" : 60,
	"parry" : 90,
	"damage": 110,
	"damage_type":  "瘀伤"
]),
([      "action":"$N大喝一声，张口一股内气向$n脸上喷去",
	"force" : 440,
	"attack": 135,
	"dodge" : 55,
	"parry" : 85,
	"damage": 105,
	"damage_type":  "瘀伤"
]),
([      "action":"$N猱身而上，双掌猛地拍向$n",
	"force" : 480,
	"attack": 170,
	"dodge" : 100,
	"parry" : 75,
	"damage": 95,
	"damage_type":  "瘀伤"
]),
([      "action":"$N身体微侧，突然飞起一脚，踢向$n下三路。脚到中途，猛地一抬，踢向$n面门",
	"force" : 470,
	"attack": 175,
	"dodge" : 80,
	"parry" : 65,
	"damage": 110,
	"damage_type":  "瘀伤"
]),
([      "action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
	"force" : 460,
	"attack": 160,
	"dodge" : 75,
	"parry" : 85,
	"damage": 100,
	"damage_type":  "瘀伤"
]),

});

int valid_enable(string usage)
{
    return usage == "unarmed" ||
	   usage == "dodge" ||
	   usage == "parry" ||
	   usage == "force";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	if ((int)me->query_skill("literate", 1))
		return notify_fail("你觉得太玄神功深奥之极，一时间难以领会。\n");

	if ((int)me->query("str") < 25)
		return notify_fail("你若有所悟，然而总是有点不明白。\n");
	if ((int)me->query("int") < 19)
		return notify_fail("你若有所悟，然而总是有点不明白。\n");
	if ((int)me->query("con") < 25)
		return notify_fail("你若有所悟，然而总是有点不明白。\n");
	if ((int)me->query("dex") < 25)
		return notify_fail("你若有所悟，然而总是有点不明白。\n");

	return ::valid_learn(me);
}

string perform_action_file(string action)
{
	return __DIR__"taixuan-gong/perform/" + action;
}
string exert_function_file(string action)
{
	return __DIR__"taixuan-gong/exert/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
