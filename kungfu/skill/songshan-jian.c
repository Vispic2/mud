// songshan-jian.c  嵩山剑法

#include <ansi.h>
#include <combat.h>

inherit SKILL;
int next_sword(object me, object victim, object weapon, int damage);
mapping *action = ({
([      "action" : "$N举剑过顶，弯腰躬身，恭敬一式「万岳朝宗」，$w向$n的$l轻轻刺去，",
        "force" : 120,
        "dodge" : 20,
        "damage" : 250,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "突然间剑光一吐，$w化作一道白虹，$N使出一式「千古人龙」，剑气古朴，$w直刺$n的$l",
        "force" : 140,
        "dodge" : 15,
        "damage" : 270,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手向外一分，右手$w向右掠出一招「开门见山」，剑气森然地向$n的$l挥去",
        "force" : 200,
        "dodge" : 15,
        "damage" : 280,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一剑从空中疾劈而下，招式看似平平无奇，但呼的一声响，实有石破天惊的气势，一招「独劈华山」$w如虹地刺向$n的$l",
        "force" : 240,
        "dodge" : 10,
        "damage" : 290,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一柄$w自半空中横过，剑身似曲似直，如一件活物一般，一式「天外玉龙」奔腾矫夭，气势雄浑地斩向$n的$l",
        "force" : 270,
        "dodge" : 10,
        "damage" : 200,
        "lvl" : 40,
        "damage_type" : "割伤"
]),
([      "action" : "$N威仪整肃一式「玉井天池」，$w轰然一动，犹如千军万马奔驰而来，疾疾刺向$n的$l",
        "force" : 280,
        "dodge" : 5,
        "damage" : 210,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑转一式「叠翠浮青」，俨然长枪大戟，黄沙千里，$w电闪雷鸣，将$n笼罩于重重剑气之中",
        "force" : 300,
        "dodge" : 5,
        "damage" : 230,
        "lvl" : 60,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑尖向下，一招「龙啸九天」，$w忽然急转而上，点出的剑气将$n上身要害团团围住",
        "force" : 380,
        "dodge" : -5,
        "damage" : 240,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("songshan-qigong", 1) < 20)
                return notify_fail("你的嵩山气功火候太浅。\n");
        if ((int)me->query_skill("songyang-strike", 1) < 20)
                return notify_fail("你的大嵩阳神掌火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{

        int i, level, xuli;
	level   = (int) me->query_skill("songshan-jian",1);
	xuli = me->query_temp("songshan_xuli");

	if (me->query_temp("s_hit"))
	return ([
	"action":HIW"突然间寒光一闪，$N手中$w"+HIW"直刺向$n，剑上震荡而发巨声，实是乾坤一掷的猛击，一剑之出，具雷霆万钧之势！"NOR,
        "force" : 600 + xuli/5,
	"dodge" : 10,
        "parry" : 10,
        "damage": 600 + xuli/10,
	"post_action": (: next_sword :),
        "damage_type":  "刺伤"
]);


        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 50)
                return notify_fail("你的体力不够练嵩山剑法。\n");
        me->receive_damage("jing", 35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"songshan-jian/" + action;
}


int next_sword(object me, object victim, object weapon, int damage)
{
	int wap,wdp;
	object ob;
	ob = victim->query_temp("weapon");
if (!victim) return 1;
if (!me) return 1;
victim->start_busy(2);
        if(victim->query("eff_qi") < 0 && victim->query("qi") < 0)
        {
        message_vision(HIW"紧跟着剑光带过，"+weapon->name()+HIW"一剑从$n左肩直劈到右腰，这一剑势道之凌厉，端的是匪夷所思，只是闪电般一亮，$n已被斩成两截！\n"NOR, me,victim );

        }

        else if( damage==RESULT_PARRY && objectp(ob = victim->query_temp("weapon")) )
        {

                wap = (int)weapon->weight() / 500
                        + (int)weapon->query("rigidity")
                        + (int)me->query_str()
                        + (int)me->query("jiali")
                        + (int)me->query_skill("songshan-jian")/3
                        + me->query_temp("songshan_xuli");
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query("jiali")
                        + (int)victim->query_skill("parry")/3;
                wap = random(wap/2)+wap/2;

                if( wap > 3 * wdp ) {
	message_vision(HIY"$N手上"+weapon->name()+HIY"连连催劲，「」的一声响，与$n的"+ob->name()+HIY"一撞，喀喀喀十余声轻响过去，$n手中"+ob->name()+HIY"寸断，折成数十截掉在地下！\n"NOR, me,victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断碎的" + ob->query("name"));
//                      ob->set("value", (int)ob->query("value") / 10);
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > 2 * wdp ) {
                        message_vision(HIW"但是$N手上"+weapon->name()+HIW"连连催劲，$n手臂酸麻，虎口剧痛，"+ob->name()+HIW"登时脱手！\n" NOR,me,victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }
        }

        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
        level  = (int) me->query_skill("songshan-jian",1);

	if( random(6)==0
	&& me->query_skill("songshan-jian",1) > 290) {
	victim->start_busy(3);
	victim->apply_condition("cold_poison", victim->query_condition("cold_poison") + random(4));
	return HIC"$n突然全身一冷！无法动弹，竟已受了极重的寒冰真气！\n"NOR;
}

}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("songshan-jian",1);
        level2= (int) me->query_skill("songshan-jian",1);
        skill = me->query_skill("songshan-jian", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("songshan-jian",1);
damage2= (int) ob->query("neili",1)/10;
if (random(6)==0 && level2>=290 && (me->query_skill_mapped("sword") == "songshan-jian"))
{
j = -damage/2;
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"使出寒冰真气 !$n全身一冷！无法动弹！ \n" +NOR;
ob->apply_condition("cold_poison", ob->query_condition("cold_poison") + random(4));
  ob->start_busy(3);
           message_vision(msg, me, ob);

}


           return j;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
