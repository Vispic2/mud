// taiji-jian.c 太极剑
// cleansword 2/15/96
// Marz 5/21/96
// Updated by Doing

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
	"force" : 25,
	"dodge" : 20,
	"parry" : 25,
	"lvl"   : 0,
	"damage_type" : "刺伤"
]),
([      "action": "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
	"force" : 30,
	"dodge" : 25,
	"parry" : 30,
	"lvl"   : 6,
	"damage_type" : "刺伤"
]),
([      "action": "$N身形往右一挫，左手剑诀，右手$w使出一式「大魁星」刺向$n的$l",
	"force" : 30,
	"dodge" : 35,
	"parry" : 35,
	"lvl"   : 12,
	"damage_type" : "刺伤"
]),
([      "action": "$N双膝下沉，右手$w使出一式「探海式」，由下而上疾刺$n的$l",
	"force" : 35,
	"dodge" : 35,
	"parry" : 40,
	"lvl"   : 15,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 35,
	"dodge" : 45,
	"parry" : 45,
	"lvl"   : 18,
	"damage_type" : "刺伤"
]),
([      "action": "$N上身往左侧一拧，一招「乌龙摆尾」，右手$w反手向$n的$l挥去",
	"force" : 35,
	"dodge" : 45,
	"parry" : 55,
	"lvl"   : 21,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$n的$l",
	"force" : 40,
	"dodge" : 60,
	"parry" : 55,
	"lvl"   : 24,
	"damage_type" : "刺伤"
]),
([      "action": "$N左腿提膝，手中$w斜指，一招「宿鸟投林」刺向$n的$l",
	"force" : 40,
	"dodge" : 55,
	"parry" : 60,
	"lvl"   : 27,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「青龙出水」，$w自下而上划出一个大弧，平平地挥向$n的$l",
	"force" : 45,
	"dodge" : 65,
	"parry" : 65,
	"lvl"   : 30,
	"damage_type" : "刺伤"
]),
([      "action": "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
	"force" : 45,
	"dodge" : 70,
	"parry" : 70,
	"lvl"   : 35,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「风卷荷叶」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
	"force" : 50,
	"dodge" : 75,
	"parry" : 80,
	"lvl"   : 40,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「虎抱头」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
	"force" : 50,
	"dodge" : 75,
	"parry" : 80,
	"lvl"   : 45,
	"damage_type" : "刺伤"
]),
([      "action": "$N使出「狮子摇头」，$w由右向左划出一个大８字，将$n圈在其中",
	"force" : 55,
	"dodge" : 85,
	"parry" : 80,
	"lvl"   : 50,
	"damage_type" : "刺伤"
]),
([      "action": "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
	"force" : 55,
	"dodge" : 95,
	"parry" : 80,
	"lvl"   : 60,
	"damage_type" : "刺伤"
]),
([      "action": "$N轻轻跃起，一招「野马跳涧」，$w在半空中化为一圈银芒，落向$n的$l",
	"force" : 60,
	"attack": 3,
	"dodge" : 95,
	"parry" : 90,
	"lvl"   : 80,
	"damage_type" : "刺伤"
]),
([      "action": "$N两腿前箭后弓，一招「射雁式」，右手$w直刺$n的$l",
	"force" : 65,
	"attack": 5,
	"dodge" : 100,
	"parry" : 100,
	"lvl"   : 100,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「小魁星」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
	"force" : 70,
	"attack": 7,
	"dodge" : 100,
	"parry" : 105,
	"damage": 1,
	"lvl"   : 110,
	"damage_type" : "刺伤"
]),
([      "action": "$N猱身扑上，一招「白猿献果」，手中$w斜斜地向$n的$l挥去",
	"force" : 75,
	"attack": 10,
	"dodge" : 110,
	"parry" : 120,
	"damage": 2,
	"lvl"   : 120,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「迎风掸尘」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。",
	"force" : 80,
	"attack": 12,
	"dodge" : 105,
	"parry" : 115,
	"damage": 4,
	"lvl"   : 130,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「顺水推舟」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
	"force" : 85,
	"attack": 15,
	"dodge" : 115,
	"parry" : 125,
	"damage": 5,
	"lvl"   : 140,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「流星赶月」，$w疾刺$n的$l",
	"force" : 90,
	"attack": 18,
	"dodge" : 135,
	"parry" : 125,
	"damage": 8,
	"lvl"   : 150,
	"damage_type" : "刺伤"
]),
([      "action": "$N突然盘蹲下身来，一招「海底捞月」，$w自下而上地向$n的$l挥去",
	"force" : 95,
	"attack": 20,
	"dodge" : 125,
	"parry" : 125,
	"damage": 12,
	"lvl"   : 160,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「挑帘式」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
	"force" : 100,
	"attack": 22,
	"dodge" : 135,
	"parry" : 145,
	"damage": 17,
	"lvl"   : 170,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「黄蜂入洞」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
	"force" : 105,
	"attack": 25,
	"dodge" : 140,
	"parry" : 165,
	"damage": 20,
	"lvl"   : 180,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「大鹏展翅」，身形跃起，右手$w刺向$n的$l",
	"force" : 110,
	"attack": 28,
	"dodge" : 145,
	"parry" : 155,
	"damage": 22,
	"lvl"   : 190,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「车轮剑」，$w化作一片银盘，平平地向$n的$l卷去",
	"force" : 115,
	"attack": 28,
	"dodge" : 155,
	"parry" : 175,
	"damage": 25,
	"lvl"   : 200,
	"damage_type" : "刺伤"
]),
([      "action": "$N左脚轻点地面，身形往前一扑，一招「天马行空」，$w向$n的$l挥去",
	"force" : 120,
	"attack": 29,
	"dodge" : 165,
	"parry" : 180,
	"damage": 31,
	"lvl"   : 210,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「风扫梅花」，身体跃在半空，手中$w扫向$n的$l",
	"force" : 125,
	"attack": 32,
	"dodge" : 175,
	"parry" : 185,
	"damage": 33,
	"lvl"   : 220,
	"damage_type" : "刺伤"
]),
([      "action": "$N一招「却步抽剑」，左脚跃步落地，$w回抽，反手勾向$n的$l",
	"force" : 130,
	"attack": 35,
	"dodge" : 185,
	"parry" : 200,
	"damage": 34,
	"lvl"   : 230,
	"damage_type" : "刺伤"
]),
([      "action": "$N右腿半屈般蹲，一招「如封似闭」，剑尖虚指，转身撩向$n的$l",
	"force" : 135,
	"attack": 38,
	"dodge" : 185,
	"parry" : 220,
	"damage": 37,
	"lvl"   : 240,
	"damage_type" : "刺伤"
]),
([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
	"force" : 150,
	"attack": 40,
	"dodge" : 220,
	"parry" : 220,
	"damage": 40,
	"lvl" : 250,
	"damage_type" : "刺伤"
]),
});

string *taiji_msg = ({
"$N神情萧索，一式「手挥五弦」左手虚抚，右手长剑扬手挥洒，点点剑花飞向$n，虚实不定",
"$N目送远方翩鸿孤飞，清叹一声，内力到处$w发出嗡嗡轻鸣，剑意似绝非断，挥洒出漫天剑影",
"但见$N剑法吞吐开合、阴阳动静，实已到了太极剑法的绝诣",
"$N手中$w虽使得极快，却丝毫听不到金刃劈风之声，足见剑劲之柔韧已达于化境",
"$N将剑法中最精要之处都发挥了出来，愈战愈强，$w发出的内劲不断增强",
"太极剑法乃张三丰晚年继太极拳所创，实是近世登峰造极的剑术，$N功劲一加运开，绵绵不绝，绝无破绽",
"$N不疾不徐的漫步扬长而步，遇到$n招数，$P$w一颤，便是一缕剑光闪出",
"$N凝望$n招式，出剑以蜿蜒之势、身处庄稳之形，宛如旭日东升，剑光如金蛇万道，闪烁不定",
"$N出剑迟缓，可是剑法中破绽之少，实所罕见",
"$N左手$w缓缓向前划出，成一弧形，一股森森寒气，直逼向$n，突然之间，$N剑交右手，寒光一闪向$n的$l划去",
"$N剑法突变，剑招凌厉狠辣，以极浑厚内力，使极锋锐利剑，出极精妙招数，青光荡漾，剑气弥漫",
"$N出剑迅捷，可是剑法中破绽之少，实所罕见",
"$N$w随手一招打出，以己之钝，挡敌之无锋，正是张三丰传授的太极剑「剑意」的精奥神髓",
"$N猛然攻出招，招招都未曾使老，已然圈转，剑势犹如浪潮一般，缓缓涌向$n",
"$N姿式固是飘渺之极，但剑招古朴浑厚，剑上的威力似乎只发挥得一二成，其余的却是蓄势以待，深藏不露",
"但见青光闪动，$N手中$w刺了出去，但见剑刃平刺，锋口向着左右",
"$N双眼注视$n，手握$w剑柄，脚走八卦，拔剑一招中宫挺进，看似缓慢无力，实则包含了上乘太极之劲，力能辟金断银",
"$N出剑没有招式，剑招中全是“神在剑先、绵绵不绝”之意，一丝丝缠向$n",
"$N画剑成圈，一点寒星刺向$n",
"但见$N将手中$w缓缓伸出，随手画了个半圆，落向$n",
"$N随手一挥，$w又左向右斜划而出，可一阵尖锐的破空声出，证明此招已达反朴归真的境界",
"$N$w在空中划成大圈，右手剑诀戳出，竟似也发出嗤嗤微声",
"$N左足踏上，剑交左手，一招“三环套月”，一剑虚虚实实，以左手剑攻敌，剑尖上光芒闪烁，嗤嗤嗤的发出轻微响声",
"$N身子缓缓右转，左手持剑缓缓向上提起，剑身横于胸前，左右掌心相对，双臂成环，手中$w点出，已然蓄势无穷",
"$N一剑刺到，青光闪闪，发出嗤嗤声响，内力极强",
"$N右手捏着剑诀，左手$w不住的抖动，罩向$n上盘七大要穴，剑尖急颤，看不出攻向何处",
"$N左手剑诀斜引，$w横过，画个半圆，劲力传出，直刺$n$l",
"$N功劲一加运开，手中$w剑势绵绵不绝，绝无破绽",
"$N手里$w使得心应手，熟极而流，剑招精奇，轻翔灵动，变幻不测，突然抖腕翻剑，直向$n的$l刺到",
"$N$w递出，顺着$n来路削下，以己之钝，挡敌之无锋，实已得了太极剑法的精奥",
"$N以意驭剑，千变万化，无穷无尽，每一招都看似平淡，实则蓄势以待，深藏不露",
"$N以$w画着一个个圆圈，每一招均是以弧形刺出，以弧形收回",
"$N以意驭剑，神在剑先，绵绵不绝，剑招看似慢吞吞，软绵绵，实则千变万化，无穷无尽",
"$N朗声长啸，剑法纵横变化，奇幻无方，$w在其内力运使之下青光闪闪，威不可挡",
"$N心中竟无半点渣滓，以意运剑，$w每发一招，便似放出一条细丝，要去缠住$n",
"$N出剑递招，可说来来去去只有一招，然而这一招却永是应付不穷",
"$N剑法吞吐开合、阴阳动静，将太极剑法中最精要之处都发挥了出来，功劲一加运开，绵绵不绝",
"$N左手$w缓缓向前划出，成一弧形。$n只觉一股森森寒气，直逼过来",
"$N右手捏著剑诀，左手$w不住抖动，突然平刺，剑尖急颤，看不出攻向何处。$P这一招中笼罩了$n上盘七大要穴",
"$N剑招未曾使老，已然圈转。突然之间，$n眼前出现了几个白色光圈，大圈小圈，正圈斜圈，闪烁不已",
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候太浅。\n");

	if ((int)me->query_skill("taiji-quan", 1) < 100)
		return notify_fail("你的太极拳火候太浅。\n");
	if ( me->query_skill("taiji-jian", 1) > me->query_skill("taiji-quan", 1)+30 )
		return notify_fail("学习太极剑需以太极拳为基础。\n");
	if ( me->query_skill("taiji-jian", 1) > me->query_skill("taiji-shengong", 1)+30 )
		return notify_fail("学习太极剑需以太极神功为基础。\n");

	if ((int)me->query_skill("sword", 1) < 100)
		return notify_fail("你的基本剑法火候太浅。\n");

	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("taiji-jian", 1))
		return notify_fail("你的基本剑法水平有限，无法领会更高深的太级剑法。\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	string str;
	level = (int) me->query_skill("taiji-jian", 1);

	if( me->query_temp("tjj/sanhuan") ) {
		switch(me->query_temp("tjj/sanhuan")){
			case 3: str = HIG"$N"HIG"使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将$w"HIG"向$n轻轻挑出"NOR; break;
			case 2: str = HIG"然后$N"HIG"移进一步，右手左招，左手右招，同样一剑接着挥出，上下连续，不着一点停顿的痕迹"NOR; break;
			case 1: str = HIG"剑光紧接，$N"HIG"手中的$w"HIG"又一次挥出急点$n$l，这三剑剑势相联，剑气相叠，剑意相同，正合道家三清之属"NOR; break;
			default: str = HIG"$N使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将$w"HIG"向$n轻轻挑出"NOR; break;
		}
		if( me->query_temp("tjj/sanhuan") > 0 )
			me->add_temp("tjj/sanhuan", -1);
		return ([
			"action":str,
			"dodge": random(30),
			"parry": random(30),
			"force": 350 + random(250),
			"damage": 140 + random(130),
			"damage_type": "刺伤",
		]);
	}

	if( level > 350 )
		return ([
			"action": WHT+replace_string(replace_string(taiji_msg[random(sizeof(taiji_msg))], "$w", "$w"), "$w", "$w"WHT)+NOR,
			"dodge": random(30),
			"parry": random(30),
			"force": 350 + random(250),
			"damage": 140 + random(130),
			"damage_type": "刺伤",
		]);

	for (i = sizeof(action); i > 0; i--)
		if (level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level / 5)];

}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mixed result;
	int ap, dp, mp;
	object m_weapon;

	if ((int) me->query_skill("taiji-jian", 1) < 100 ||
	    ! (m_weapon = me->query_temp("weapon")) ||
          m_weapon->query("skill_type") != "sword"||
	    ! living(me) )
		return;

	mp = ob->query_skill("count", 1);
	ap = ob->query_skill("force") + mp;
	dp = me->query_skill("parry", 1) / 2 +
	     me->query_skill("taiji-jian", 1);

	if (ap / 2 + random(ap) < dp)
	{
		result = ([ "damage": -damage ]);

		switch (random(3))
		{
		case 0:
			result += (["msg" : HIC "$n" HIC "一抖手中的" + m_weapon->name() +
					    HIC "，划出了一个圆圈，竟然让$N" +
					    HIC "的攻击全然落空。"NOR"\n"]);
			break;

		case 1:
			result += (["msg" : HIC "$n" HIC "手中" + m_weapon->name() +
					    HIC "轻挑，正指向$N" HIC "攻势中的破绽。"NOR"\n"]);
			break;

		default:
			result += (["msg" : HIC "$n" HIC "晃动手中的" + m_weapon->name() +
					    HIC "，不住的变幻剑势，让$N"
					    HIC "完全无法捕捉到力道。"NOR"\n"]);
			break;
		}
		return result;
	} else
	if (mp >= 100)
	{
		switch (random(2))
		{
		case 0:
			result = HIY "$n" HIY "一抖手中的" + m_weapon->name() +
				 HIY "，划出了一个圆圈，$N"
				 HIY "理也不理，当即挥招直入，进袭$n"
				 HIY "！"NOR"\n";
			break;

		case 1:
			result = HIY "$n" HIY "手中" + m_weapon->name() + "轻挑，"
				 HIY "正指向$N" HIY "攻势中的破绽，可是$N"
				 HIY "身形一变，破绽立刻不成为破绽。"NOR"\n";
			break;

		default:
			result = HIY "$n" HIY "晃动手中的" + m_weapon->name() +
				 HIY "，不住的变幻剑势，然而$N"
				 HIY "算理深厚，精演天数，丝毫不受$n"
				 HIY "的迷惑。\n"  NOR;
			break;
		}
		COMBAT_D->set_bhinfo(result);
	}
}

int practice_skill(object me)
{
	object weapon;

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力不够练太极剑法。\n");

	if ((int)me->query("neili") < 120)
		return notify_fail("你的内力不够练太极剑法。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -100);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
