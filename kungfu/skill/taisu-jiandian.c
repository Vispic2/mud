#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。\n",
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。\n",
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。\n",
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。。\n",
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。。\n",
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。。\n",
        "$n手中之兵深受太素剑气的所温养早已有了灵性，自动抵消了$N的所有攻击。。\n",
});

string *finger_name = ({ "左手中指", "左手无名指", "左手食指",
                         "右手中指", "右手无名指", "右手食指", }); 

mapping *action = ({
([          "action":"太素剑典中的【破】之意突显$w忽隐忽现，忽左忽右向$n攻去", // 描述
            "force" : 400,                                                   // 攻击力
            "attack": 120,                                                    // 命中点
            "parry" : 120,                                                         // 如果该找可以做招架则招架点数
            "dodge" : 120,                                                          // 轻功点数，同parry
            "damage": 300,                                                         // 伤害力
            "lvl" : 10,                                                         // 发出该招要求的等级
            "skill_name" : "破",                                       // 该找名字
            "damage_type":  "刺伤"                                           // 伤害类型
]),
([          "action":"$N使出太素剑典中的【化】之剑意，曼妙身躯回转一番向$n攻去",    
            "force" : 400,
            "attack": 120,
            "parry" : 300,
            "dodge" : 350,
            "damage": 320,
            "lvl" : 20,
            "skill_name" : "化",
            "damage_type":  "刺伤"
]),
([          "action":"$N使出太素剑典中的【惊】之剑意，人剑一合，犹如玄女般向$n直射而去",
            "force" : 400,
            "attack": 200,
            "parry" : 120,
            "dodge" : 150,
            "damage": 340,
            "lvl" : 40,
            "skill_name" : "惊",
            "damage_type":  "刺伤"
]),
([          "action":"$N使出太素剑典中的【伤】之剑意，手中的$w光暗不定，犹如大浪涛涛，将$n笼罩在一片剑影之下",
            "force" : 400,
            "attack": 150,
            "parry" : 200,
            "dodge" : 200,
            "damage": 500,
            "lvl" : 80,
            "skill_name" : "伤",
            "damage_type":  "刺伤"
]),
([          "action":"$N有如柳絮，手中$w轻举面容无比神圣，轻轻一剑向前方的$n划去",
            "force" : 600,
            "attack": 200,
            "parry" : 200,
            "dodge" : 300,
            "damage": 350,
            "lvl" : 160,
            "skill_name" : "神",
            "damage_type":  "刺伤"
]),
([          "action":"$N一声冷笑冷眉轻皱，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
            "force" : 400,
            "attack": 300,
            "parry" : 200,
            "dodge" : 100,
            "damage": 340,
            "lvl" : 180,
            "skill_name" : "迎风而上",
            "damage_type":  "刺伤"
]),
});

// valid_enable()函数返回该技能可激发的种类
int valid_enable(string usage)
{
        return usage == "sword" ||
               usage == "dodge" ||
               usage == "parry" ||
               usage == "unarmed";
}

// 返回1表示该找可以一招两式
int double_attack() { return 1; }

// 这个不用说了吧，是yanjiu和learn的时候调用的函数
int valid_learn(object me)
{
       if (me->query("family/family_name") != "古墓派" &&
	    me->query("family/family_name") != "古墓派")
return notify_fail("古月太素只有古墓弟子方可修习\n");


                if (me->query("gender") != "女性")return notify_fail("古月太素只有女性方可修习。\n");
  
        if (me->query_skill("sword", 1) < 100)
                return notify_fail("你的基本剑法造诣太浅，无法理解太素剑典。\n");

        if (me->query_skill("dodge", 1) < 100)
                return notify_fail("你的基本轻功造诣太浅，无法理解太素剑典。\n");

        if (me->query_skill("parry", 1) < 100)
                return notify_fail("你的基本招架造诣太浅，无法理解太素剑典。\n");

        if (me->query_skill("sword", 1) < me->query_skill("taisu-jiandian", 1))
                return notify_fail("你的基本剑法造诣有限，无法理解更高深的太素剑典。\n");

        if (me->query_skill("dodge", 1) < me->query_skill("taisu-jiandian", 1))
                return notify_fail("你的基本轻功造诣有限，无法理解更高深的太素剑典。\n");

        if (me->query_skill("parry", 1) < me->query_skill("taisu-jiandian", 1))
                return notify_fail("你的基本招架造诣有限，无法理解更高深的太素剑典。\n");

        if (me->query_skill("unarmed", 1) < me->query_skill("taisu-jiandian", 1))
                return notify_fail("你的基本拳脚造诣有限，无法理解更高深的太素剑典。\n");

        return 1;
}

// 这个是标准函数不需要修改
string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

// 这个是标准函数不需要修改
mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("taisu-jiandian", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

// 返回闪避信息
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

// 被对方打中后调用的函数，比如将该招激发为招架或轻功
mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("taisu-jiandian", 1) < 100 ||
            ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("dodge") + mp;
        dp = me->query_skill("dodge", 1) / 2 +
             me->query_skill("taisu-jiandian", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                         result += (["msg" : HIY "$n" HIY "面露九仪太素之相，镇定自若"
                                            "，$N" HIY "只觉$n浑身毫无破绽可寻，" HIY 
                                            "一时间根本无从攻击。\n"NOR]);
                        break;
                case 1:
                        result += (["msg" : HIY "$N" HIY "一招击中$n" HIY "上身"
                                            "，可却被$n太素剑气所慑，招式顿显无力。\n" NOR]);
                        break;
                case 2:
                       result = HIW "$n" HIW "简简单单的接下了$N"
                                 HIW "这一招，丝毫无损。可是$N"
                                 HIW "招中有招，进攻却是不止。\n" NOR;
                        break;
                default:
                        result += (["msg" : HIW "突然间白影急晃，$n" HIW "向后滑出丈余"
                                            "，立时又回到了原地，躲过了$N" HIW "这一招"
                                            "。\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(4))
                {
                case 0:
                        result = HIY "$N" HIY "眼睛一花，$n" HIY "已没了踪影"
                                 "。可是$N" HIY "精通易理，丝毫不为所乱，尽自"
                                 "出招。\n" NOR;
                        break;
                case 1:
                        result = HIY "$N" HIY "眼前一花，似乎见到$n" HIY "身"
                                 "形一晃。$N" HIY "一声轻笑，已瞬间看破招中虚"
                                 "实。\n" NOR;
                        break;
                case 2:
                        result = HIY "$n" HIY "身形飘忽，有如柳絮，随风飘荡，"
                                 "可是$N" HIY "理也不理，连续数招径直攻出。\n"
                                 NOR;
                        break;
                default:
                        result = HIY "突然间白影急晃，$n" HIY "向后滑出丈余，"
                                 "可是$N" HIY "不假思索，追身攻上，更是巧妙无"
                                 "方。\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

// 当该招激发为轻功时的轻功效果
int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("taisu-jiandian", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 40;
        if (lvl < 150) return 40;
        if (lvl < 200) return 50;
        if (lvl < 250) return 80;
        if (lvl < 300) return 100;
        if (lvl < 350) return 120;
        return 150;
}

// 当打中对方时调用的函数
mixed hit_ob(object me, object victim, int damage)
{
        mixed result;
        if (damage < 100) return 0;

        if (random(damage) > victim->query_str()) 
        {
                result = ([ "damage" : damage ]);
                result += ([ "msg" : HIW "你听到「嗤」的一声轻响，已被$N的兵器所发杀气挫伤，$n顿时血止不住的往外流！！！\n" NOR ]);

                return result;
        }
}

// 当练习该招时调用的函数
int practice_skill(object me)
{
        return notify_fail(HIC "太素剑典只能通过读《太素剑典》来提升。\n" NOR);
}

// 该招的学习难度
int difficult_level()
{
        return 15000;
}

// 该招的perform文件位置__DIR__代表当前目录；
string perform_action_file(string action)
{
        return __DIR__"taisu-jiandian/" + action;
}