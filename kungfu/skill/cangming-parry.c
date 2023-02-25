// liuli-jinshen.c

#include <ansi.h>

inherit SHAOLIN_SKILL;

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force") < 450)
		return notify_fail("你的内功火候不够，无法领悟沧溟魔身。\n"); 

if( me->query_skill("buddhism", 1) < 400 )
                return notify_fail("你佛法修为不足，无法领悟沧溟魔身\n");

 

if( me->query_skill("sanscrit", 1) < 300 )
                return notify_fail("你梵文知识不足，无法领悟沧溟魔身\n");	if ((int)me->query("max_neili") < 3500)
		return notify_fail("你的内力还不足以修习沧溟魔身。\n");

	if ((int)me->query_skill("parry", 1) < (int)me->query_skill("cangming-parry", 1))
		return notify_fail("你的基本招架水平有限，无法领会更高深的沧溟魔身。\n");

	return 1;
}

string query_txt()
{
	return "要求：内功激发450，内力3500，禅宗心法400，梵文300，等级不能高于基本招架"ZJBR
	"特效：以内力化解攻击者伤害，内力消耗=伤害/50，对比自身(内功激发*12+最大内/2)和攻击者(内功激发*12+内力/2)，同数值1/1概率触发"
	"，内力低于最大内/2不触发";
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	int ap, dp;
	int cost;

	cost = damage / 8;

	if (! living(me) ||
	    (int)me->query_skill("cangming-parry", 1) < 100 ||
	    (int)me->query("neili") < cost ||
	    (int)me->query("neili") < me->query("max_neili")/2)
		return;

	ap = ob->query_skill("force") * 12 + ob->query("max_neili")/1;
	dp = me->query_skill("force") * 12 + me->query("neili")/1;

	if (ap / 80 + random(ap) < dp)
		{
		me->add("neili", -cost);
        tell_object(me,BLK HBBLU "你" BLK HBBLU "唤出无常恶鬼护住周身，用"+cost+"内力抵挡了"+damage+"伤害。"NOR"\n");
		result = ([ "damage": -damage ]);

		switch (random(5))
		{
		case 0:
			result += (["msg" : BLK HBBLU "$n" BLK HBBLU "唤出无常恶鬼护住周身，顿时煞气冲天，$N"
					    BLK HBBLU "无从下手。"NOR"\n"]);
					break;
		case 1:
			result += (["msg" : BLK HBBLU "只见$N" BLK HBBLU "这一招打了个正中！然而$n"
					    BLK HBBLU "好似一个没事人一样笑道道：入我魔道！不死之身！！"NOR"\n"]);
			break;
		case 2:
			result += (["msg" : BLK HBBLU "$N" BLK HBBLU "一招正好打在$n" BLK HBBLU "身上，可"
					    "力量犹如石沉大海，丝毫不起作用.....举血誓，身化魔！灌铸不死身！"NOR"\n"]);
			break;
		case 3:
			result += (["msg" : BLK HBBLU "$N" BLK HBBLU "一招击在$n" BLK HBBLU "身上，但只听$n"
					    BLK HBBLU "狂笑不止：哈哈哈哈！！！身如恶鬼，内外浊，心如恶鬼，便是死生也要由我定！\n"]);
			break;
		default:
			result += (["msg" : BLK HBBLU "$n" BLK HBBLU "硬接了$N"
					    BLK HBBLU "这一招，却没有受到半点伤害，恶鬼如我，我便是这世间的魔！一身气血浑然天成，似已铸成不死身！"NOR"\n"]);
			break;
		}
		return result;
	}
}

int query_effect_parry(object attacker, object me)
{
	int lvl;

	lvl = me->query_skill("cangming-parry", 1);
	if (lvl < 200) return 0;
	if (lvl < 380) return 50;
	if (lvl < 430) return 80;
	if (lvl < 550) return 10;
	if (lvl < 650) return 80;
	if (lvl < 650) return 120;
	if (lvl < 750) return 100;
	return 150;
}

int practice_skill(object me)
{
	int cost;
	int lvl;

	if ((lvl = me->query_skill("cangming-parry", 1)) < 100)
				return notify_fail("你对沧溟魔身的了解甚浅，还不足以自行锻炼。\n");

	cost = 85 + (lvl - 100) / 3;
	if ((int)me->query("qi") < 70)
		return notify_fail("你的体力太低了。\n");

	if ((int)me->query("neili") < cost)
		return notify_fail("你的内力不够练沧溟魔身。\n");

	me->receive_damage("qi", 50);
	me->add("neili", -cost);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"cangming-parry/" + action;
}

