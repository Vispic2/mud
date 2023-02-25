// tianmo-jinshen.c 天魔金身
// by King 97.05

inherit SKILL;

#include <ansi.h>

string *parry_msg = ({
	"$N一招击在$n身上，却被$n暗运天魔金身，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
	"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
	"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
	"$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈子。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

string *dodge_msg = ({
	"$N一招击在$n身上，却被$n暗运天魔金身，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
	"$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
	"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
	"$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

string *pfail_msg = ({
	"$n暗运天魔金身，试图将内力尽数移入地下，然而$N早已勘破其中奥妙，内力变化莫测。\n",
	"$n轻轻一带，$N发现自己招数回击过来，急忙变招，身转如意，反让$n防不胜防。\n",
	"$n手臂回转，在$N手肘下轻轻一推，然而$N招数忽的一变，并未落空。\n",
	"$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，顺势变招扑前直击。\n",
	"$n左牵右引，$N如身处漩流，顺势变招，圆转如意，随心所欲。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，猛然警醒，聚力于一点，力攻对方。\n",
});

int valid_enable(string usage) 
{ 
	return usage == "parry" ;
}

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
	int layer;


	layer = (int)me->query_skill("tianmo-jinshen", 1) / 50;
	if (layer > 13) layer = 13;

	if (me->query("int") < 1 + layer)
		return notify_fail("你觉得第" + chinese_number(layer) +
				   "层天魔金身实在是深奥无比，全然无法理解。\n");

	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太差，无法修炼天魔金身。\n");
	
	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功火候不够，无法勉强修炼天魔金身。\n");

	if ((int)me->query_skill("parry", 1) < (int)me->query_skill("tianmo-jinshen", 1))
		return notify_fail("你的基本招架火候有限，无法体会更高深的天魔金身。\n");

	if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("tianmo-jinshen", 1))
		return notify_fail("你的基本轻功火候有限，无法体会更高深的天魔金身。\n");

	if ((int)me->query_skill("force", 1) < (int)me->query_skill("tianmo-jinshen", 1))
		return notify_fail("你的基本内功火候有限，无法体会更高深的天魔金身。\n");

	return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
	mapping result;
	string msg;
	int ap, dp, mp;

	if ((int) me->query_skill("tianmo-jinshen", 1) < 100 ||
	    ! living(me))
		return;

	mp = ob->query_skill("count", 1) + ob->query_skill("never-defeated", 1)/3;
	ap = ob->query_skill("force", 1) + mp;
	dp = me->query_skill("tianmo-jinshen", 1);

	if ( me->query("int") > ob->query("int"))
	{
          if (ap / 2 + random(ap) < dp) {
		msg = parry_msg[random(sizeof(parry_msg))];
		msg = replace_string(msg, "$N", "$N" HIG);
		msg = replace_string(msg, "$n", "$n" HIG);
		msg = HIG + msg + NOR;
		result = ([ "damage": -damage,
			    "msg"   : msg ]);
		return result;
            } else if (mp >= 100)
	     {
		msg = pfail_msg[random(sizeof(pfail_msg))];
		msg = replace_string(msg, "$N", "$N" HIY);
		msg = replace_string(msg, "$n", "$n" HIY);
		msg = HIY + msg + NOR;
		COMBAT_D->set_bhinfo(msg);
	      }
	} else {
	if ( random(ap) < dp/3 && ap/2<dp)
	{
		msg = parry_msg[random(sizeof(parry_msg))];
		msg = replace_string(msg, "$N", "$N" HIG);
		msg = replace_string(msg, "$n", "$n" HIG);
		msg = HIG + msg + NOR;
		result = ([ "damage": -damage,
			    "msg"   : msg ]);
		return result;
	} else
	if (mp >= 100)
	   {
		msg = pfail_msg[random(sizeof(pfail_msg))];
		msg = replace_string(msg, "$N", "$N" HIY);
		msg = replace_string(msg, "$n", "$n" HIY);
		msg = HIY + msg + NOR;
		COMBAT_D->set_bhinfo(msg);
	    }
      }
}

int practice_skill(object me)
{
	return notify_fail("天魔金身只能通过学习或研读天魔金身心法提高。\n");
}

string perform_action_file(string func)
{
	return __DIR__"tianmo-jinshen/" + func;
}

void skill_improved(object me)
{
	int lvl;
	int layer;

	lvl = me->query_skill("tianmo-jinshen", 1);
	layer = lvl / 50;
	if (layer > 13) layer = 13;

	if (! layer)
	{
		tell_object(me, HIM "你潜心修炼天魔金"
			    "身心法，若有所悟。"NOR"\n");
	} else
	if ((lvl % 50) == 0)
	{
		tell_object(me, HIM "你修炼成了第" + chinese_number(layer) +
			    "层的天魔金身心法。"NOR"\n");
	} else
		tell_object(me, HIM "你对第" + chinese_number(layer) +
			    "层的天魔金身心法又加深了一层了解。"NOR"\n");

	if (lvl > me->query_skill("force") * 2 / 3)
	{
		if (lvl < me->query_skill("force") * 2 / 3 + 10)
		{
			tell_object(me, HIG "你觉得内息一阵紊乱，丹田时冷时热，不由得大吃一惊。\n"
			      "心想莫非是走火入魔？忽然你觉得丹田越来越是寒冷，极为难受。"NOR"\n");
			message("vision", HIG + me->name() + HIG "的脸色忽红忽"
				"绿，变得不停，只是浑身颤抖，似乎十分痛苦。"NOR"\n",
				environment(me), ({ me }));
			return;
		}

		tell_object(me, HIB "你忽然觉得丹田腾起一阵寒意，霎时间四肢"
		      "百赅一起变得寒冷无比，忍不住大声呻吟。"NOR"\n");
		message("vision", HIB + me->name() + HIB "忽然一"
			"抖，脸色忽然变得惨白，隐然笼罩了一股绿气，呻吟不止。"NOR"\n",
			environment(me), ({ me }));
	} else
	if (lvl < 350 && (lvl * 20 + 400) > me->query("max_neili"))
	{
		if ((lvl * 20 + 400) < me->query("max_neili") + 200)
		{
			tell_object(me, HIR "你试着运转了一下内息，一时觉得内"
			      "力不济，看来还是不要贸然修炼大金身神功。"NOR"\n");
			return;
		}

		tell_object(me, HIR "你试着运转了一下内息，忽然觉得一口气"
		      "竟然转不过来，顿时心中绞痛，接连吐了几口鲜血。"NOR"\n");
		message("vision", HIR + me->name() + HIR "脸色忽然"
			"一变，呕出几口鲜血，触目惊心。"NOR"\n",
			environment(me), ({ me }));
	} else
		return;

	me->apply_condition("qiankun-except", lvl + (int)me->query_condition("qiankun-except"));
}

int diffcult_level() { return 300; }


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
