// This program is a part of NITAN MudLIB
// taishang-wangqingjue.c

#include <ansi.h>

inherit FORCE;
string *xue_name = ({
        "劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
        "幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", });

string *dodge_msg = ({
       HIC "$N身形加速，电光挪移，饶是$n攻击范围既广且厉，却总能在间不容发的空隙避过。\n" NOR,
       HIC "$N空中快速转折，在$n每次攻击前又倏乎消失，一下子就脱出$n的攻击范围。\n" NOR,
       HIC "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n" NOR,
       HIC "$N凭著高速身法，在$n的攻击范围内进退趋避，险险闪过一道又一道的攻击。\n" NOR,
       HIC "$N腾挪快速，竟然在空中形成身影残像，有如无数$N一起挪动。\n" NOR,
       HIC "$n眼前忽然一花，眼前$N的身影似乎有些淡化，而另外一个$N竟尔出现在面前不足一尺的近处。\n" NOR,
});

string *parry_msg = ({
        HIY "$n轻轻一带，$N" HIY "发现自己招数回击过来，吓得往后倒退几步。\n" NOR,
        HIY "$n手臂回转，在$N" HIY "手肘下轻轻一推，$N" HIY "招数落空。\n" NOR,
        HIY "$n右手伸出，在$N" HIY "手腕上轻轻一拉，$N" HIY "收势不住，直往前扑去。\n" NOR,
        HIY "$n身形不动，$N" HIY "一招击下，有如石沉大海，不觉呆住了。\n" NOR,
        HIY "$n左牵右引，$N" HIY "如身处漩流，连续转了好几个圈。\n" NOR,
        HIY "$n双手回圈，$N" HIY "只觉得前面好象有一堵墙，再也攻不进去。\n" NOR,
        HIY "$n轻轻一转，$N" HIY "一招击在地上，只打得尘土飞扬。\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taishang-wangqingjue", 1);
        return lvl / 10 * lvl / 10 * 25 * 40 / 10 / 20;
}

int query_jingli_improve(object me)
{
        int lvl;
        
        lvl = (int)me->query_skill("taishang-wangqingjue", 1);
        
        if (me->query_skill_mapped("force") == "taishang-wangqingjue")
                return lvl * 40 / 3;

        return 0;
}
mapping *action = ({
([      "action": "$N双指并拢虚点而出，将「"NOR + HIG "一阳指" NOR "」及"
                  "「" NOR + HIG "拈花指" NOR "」合为一式，顿时一股罡风直射$n",
        "force" : 1000,
        "attack": 600,
        "dodge" : 750,
        "parry" : 750,
        "damage": 850,
        "weapon" : HIC "大自在有无形剑气" NOR,
        "damage_type" : "刺伤"
]),
([      "action": "$N双指齐点而出，合「" HIG "幻阴指" NOR "」及「" HIG "无相指" NOR "」为一式，顿时剑气已笼罩$n全身各处",
        "force" : 1100,
        "attack": 700,
        "dodge" : 650,
        "parry" : 650,
        "damage": 550,
        "weapon" : HIC "大自在有无形剑气" NOR,
        "damage_type" : "刺伤"
]),
([
        "action": "只见$N十指箕张，随手指指点点，将「" HIG "大力金刚指" NOR "」及"
                  "「" HIG "大天龙指" NOR "」的精髓招式同时使出，\n顿时剑气纵横，尘"
                  "砂四起，逼向$n而去",
        "force" : 1100,
        "attack": 700,
        "dodge" : 650,
        "parry" : 650,
        "damage": 550,
        "weapon" : HIC "大自在有无形剑气" NOR,
        "damage_type" : "刺伤"
]),
([
        "action": "只见$N纵身跃起，长啸一声，凌空而下，「" HIG "七星指" NOR "」及「" HIG "天罡指" NOR "」化为一式射"
                  "向$n全身各处",
        "force" : 1000,
        "attack": 600,
        "dodge" : 750,
        "parry" : 750,
        "damage": 850,
        "weapon" : HIC "大自在有无形剑气" NOR,
        "damage_type" : "刺伤"
]),
([      "action": "$N伸出两指，弹指无声，陡见两缕紫气由指尖透出，「" HIG "乾天指" NOR "」及「" HIG "玄天指" NOR "」射向$n周身大穴",
        "force" : 1300,
        "attack": 750,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon" : HIC "大自在有无形剑气" NOR,
        "damage_type" : "刺伤"
]),
([      "action": "遥见$N伸出一指轻轻拂向$n，指未到，「" HIC "大自在有无形剑气" NOR "」已将$n压"
                  "得透不过气来",
        "force" : 1300,
        "attack": 750,
        "dodge" : 600,
        "parry" : 600,
        "damage": 600,
        "weapon" : HIC "大自在有无形剑气" NOR,
        "damage_type" : "刺伤"
])
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *usage_skills = ({ "unarmed","finger","dodge", "parry", "force", "sword", "blade"});

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
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
        int lvl;
        int i;
        lvl = me->query_skill("taishang-wangqingjue", 1);
		
         // 与武道三千冲突
        if( me->query_skill("wudao-shanqian",1) )
                return notify_fail("你感觉体内的道佛真气跌宕起伏，全身欲裂。\n");       
        if( me->query("str")<15 )
                return notify_fail("你先天臂力不足。\n");

        if( me->query("int")<15 )
                return notify_fail("你先天悟性不足。\n");

        if( me->query("dex")<15 )
                return notify_fail("你先天身法不足。\n");
                
        if( me->query("con")<15 )
                return notify_fail("你先天根骨不足。\n");    

       			
	/*	for (i = 0; i < sizeof(usage_skills); i++)
                if (me->query_skill(usage_skills[i], 1) < lvl)
                        return notify_fail("你对" + to_chinese(usage_skills[i]) +
                                           "的理解还不够，无法继续领会更高深的太上忘情决。\n");*/

        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;

        if ((int)me->query_skill("taishang-wangqingjue", 1) < 350
           || me->query_skill_mapped("parry") != "taishang-wangqingjue"
           || (int)me->query("neili") < 200
           || ! living(me))
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("taishang-wangqingjue", 1) * 16 + me->query_skill("martial-cognize", 1);

        if( ob->query("reborn/times") < 4 )dp+=1000;
        
        if (dp + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIW "$N" HIW "眼睛一花，$n" HIW "已没了踪"
                                            "影。突然$n" HIW "从身后拍了一下$N" HIW "的"
                                            "头，轻轻跃开。\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$N" HIW "眼前一花，似乎见到$n" HIW "身"
                                            "形一晃，但随即又见$n" HIW "回到原地，却似"
                                            "从未离开。\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$n" HIW "尖啸一声，忽然身子一转已不见了踪影，$N" HIW
                                           "只觉耳边风声不断，但随即又见$n" HIW "回到了原地。\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "忽然间，只见$n" HIW "腰枝一摆，顿时出现无数个"
                                            "$n" HIW "的影子，$N" HIW "却无法辨别出$n" HIW "的方位。\n" NOR]);
                        break;
                }
                return result;
        }
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name1, name2;		
		name1 = finger_name[random(sizeof(finger_name))];
		name2 = xue_name[random(sizeof(xue_name))];	

        victim->receive_wound("qi", damage_bonus * 4, me);
        me->add("neili", me->query("jiali") / 3);

        if (victim->query("neili") < 500)
                victim->set("neili", 0);
        else
                victim->add("neili", -300);

        		return NOR + HIW "$n" HIW "霎时间只见$N" HIW "身子猛摆，顿时化分为无数身影" + name1 + "宛若流星般刺向$n" + name2 + "。\n" NOR;	   
 }

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("taishang-wangqingjue", 1);
        if (lvl < 200) return 200;
        if (lvl < 250) return 300;
        if (lvl < 350) return 400;
        return 200;
}
int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("taishang-wangqingjue", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

int practice_skill(object me)
{
        return notify_fail("太上忘情决博大精深，无法简单的通过练习进步。\n");
}

int difficult_level()
{
        return 4500;
}

string perform_action_file(string action)
{
        return __DIR__"taishang-wangqingjue/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"taishang-wangqingjue/exert/" + action;
}
void skill_improved(object me)
{
        int lvl, layer;

        lvl = me->query_skill("taishang-wangqingjue", 1);
        layer = lvl / 50;


        if ((lvl % 10) == 0)
        {
                tell_object(me, HIY "你炼成了第" + chinese_number(layer) +
                                "层的太上忘情决。\n" NOR);
        }
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
