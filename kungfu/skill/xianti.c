// daojian-guizhen.c 刀剑归真
// Edit By Vin 11/2/2001

#include <ansi.h>
inherit SKILL;

int difficult_level() { return 1400; }

mapping *action = ({
([      "action" : "$N手中$w缓缓横推而出，左手蓦地施一招「" HIW "推波助"
                   "澜" NOR "」，右手同时又施展\n出「" HIY "洗剑怀中抱月"
                   NOR "」，由上至下同时朝向$n$l砍去",
        "force" : 410,
        "attack": 170,
        "dodge" :-60,
        "parry" :-80,
        "damage": 270,
        "damage_type" : "割伤",
]),
([      "action" : "$N一招「" HIY "黄龙转身吐须" NOR "」，朝$n疾刺出三"
                   "剑，猛然间又变招为「" HIW "沙鸥掠波" NOR "」！\n自下"
                   "而上划出个半弧形刀芒闪出，刀芒中$w幻作一道白光射向$n",
        "force" : 560,
        "attack": 220,
        "dodge" :-30,
        "parry" :-70,
        "damage": 280,
        "damage_type" : "刺伤",
]),
([      "action" : "$N神色微变，一招「" HIY "丹凤朝阳" NOR "」，招式"
                   "顿时变得凌厉无比，接着使一招「" HIW "天设牢笼" NOR
                   "」！\n那$w便有如白雾一般压向$n",
        "force" : 490,
        "attack": 170,
        "dodge" :-160,
        "parry" :-180,
        "damage": 290,
        "damage_type" : "割伤",
]),
([      "action" : "$N使一招胡家刀法的「" HIW "闭门铁扇" NOR "」，$w毫"
                   "不经意的缓缓斜着推斩出，招至\n中途，刹那间忽然只见寒"
                   "光一闪而过，$N又一招苗家剑法之「" HIY "迎门腿反劈华"
                   "山" NOR "」！\n却见$w光芒闪烁不定，已经反劈而下",
        "force" : 530,
        "attack": 210,
        "dodge" :-70,
        "parry" :-80,
        "damage": 270,
        "damage_type" : "割伤",
]),
([      "action" : "$N猛喝一声，一招胡家刀法「" HIW "翼德闯帐" NOR "」"
                   "并苗家剑法「" HIY "返腕翼德闯帐" NOR "」，手中\n$w反"
                   "手疾挑而出，接着转身跃起，一道白光射向$n的胸口",
        "force" : 470,
        "attack": 130,
        "dodge" :-70,
        "parry" :-40,
        "damage": 280,
        "damage_type" : "刺伤",
]),
([      "action" : "只见$N手中$w“嗤”的一声斜刺向天空，随即又向下“唰"
                   "唰”两下，左右横\n斩而出，顿时幻出一道闪亮的十字，向"
                   "$n涌出，正是胡家刀法中「" HIW "白鹤舒翅" NOR "」\n以"
                   "及苗家剑法中「" HIY "提撩剑白鹤舒翅" NOR "」的精髓",
        "force" : 430,
        "attack": 190,
        "dodge" :-110,
        "parry" :-140,
        "damage": 330,
        "damage_type" : "刺伤",
]),
([      "action" : "$N一招「" HIY "上步云边摘月" NOR "」，纵身跃起，不"
                   "见踪影，忽然间却见$w从半空中穿出\n变招「" HIW "春"
                   "风送暖" NOR "」，左脚跃步落地，$w顺势往前，呼啸着劈"
                   "向$n的$l",
        "force" : 510,
        "attack": 180,
        "dodge" :-70,
        "parry" :-120,
        "damage": 300,
        "damage_type" : "割伤",
]),
([      "action" : "只见$N一招「" HIY "冲天掌苏秦背剑" NOR "」，左手虚"
                   "击，右手$w猛的自下方挑起，刹时\n又出杀着「" HIW "八方"
                   "藏刀势" NOR "」，顿时剑光中闪出无数朵刀花从四面八方"
                   "涌向$n全身",
        "force" : 530,
        "attack": 190,
        "dodge" :-120,
        "parry" :-120,
        "damage": 280,
        "damage_type" : "割伤",
]),
});

string main_skill() { return "daojian-guizhen"; }

mapping sub_skills = ([
        "miaojia-jian" : 250,
        "hujia-daofa"  : 250,
]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if( !(ob=me->query_temp("weapon") )
            || ob->query("skill_type") != "sword"
            && ob->query("skill_type") != "blade" )
        {
                tell_object(me, "你空手舞了半天，发现不拿把刀或是剑实在"
                                "难以演练。\n");
                return 0;
        }

        if( me->query("character") != "光明磊落" && me->query("character") != "国士无双")
        {
                tell_object(me, "你演练了半天，心中暗道：什么刀剑合一竟"
                                "如此难练，看来不过是骗人的罢了。\n");
                return 0;
        }

        if( me->query("int")<32 )
        {
                tell_object(me, "你演练完毕，只感剑法和刀法毫无牵连，看"
                                "来依你的悟性，无法将其合一。\n");
                return 0;
        }

        if( me->query("dex")<26 )
        {
                tell_object(me, "你演练完毕，只觉依自己的身法灵动性，根"
                                "本无法将二者合一。\n");
                return 0;
        }

        if( me->query("con")<32 )
        {
                tell_object(me, "你演练完毕，只觉依自己的根骨不足，根"
                                "本无法将二者合一。\n");
                return 0;
        }

        if( me->query("str")<31 )
        {
                tell_object(me, "你演练完毕，只觉依自己的臂力不足，根"
                                "本无法将二者合一。\n");
                return 0;
        }

        if (me->query_skill("literate", 1) < 200)
        {
                tell_object(me, "你觉得苗家剑法和胡家刀法都极其深奥，看"
                                "来多研究一下学问可能更有帮助。\n");
                return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 200)
        {
                tell_object(me, "你演练完毕，发现自己的武学修养尚待提高"
                                "，暂且无法将二者合一。\n");
                return 0;
        }


        if( me->query("max_neili")<4500 )
        {
                tell_object(me, "你觉得自己真气不继，无法将苗家剑法和胡"
                                "家刀法二者合一。\n");
                return 0;
        }

        if (random(30) < 27)
        {
                tell_object(me, "你觉得有所感悟，或许再演练一次就能融会"
                                "贯通，将二者合一。\n");
                return 0;
        }

        tell_object(me, HIY "\n一阵凡尘往事涌上心头，你几欲放声长叹。霎"
                        "那间，苗家剑法和胡家刀法交替着不断在\n你脑海里"
                        "闪现，终于融会贯通，合二为一。你终于通晓了刀剑"
                        "归真的诀窍。\n" NOR);message("channel:chat", HBYEL HIR"【天降奇才】"HBRED HIC + "听说"+me->query("name")+"天纵奇才，将胡家刀法与苗家剑法合二为一，领悟了刀剑归真！
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "blade" || usage == "parry";
}

int valid_learn(object me)
{
        object ob;
        int lvls, lvlb, lvld;

        lvls = me->query_skill("sword", 1);
        lvlb = me->query_skill("blade", 1);
        lvld = me->query_skill("daojian-guizhen", 1);

        if( !(ob=me->query_temp("weapon") )
            || ob->query("skill_type") != "sword"
            && ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一柄剑或一柄刀才能够练习。\n");

        if( me->query("character") != "光明磊落" && me->query("character") != "国士无双" )
                return notify_fail("你练习了半天，心中暗道：什么刀剑合"
                                   "一，竟如此难练，这东西不练也罢。\n");

        if( me->query("int")<32 )
                return notify_fail("你研究了半天，却只感剑法和刀法毫无"
                                   "牵连，看来是自己天资不足。\n");

        if( me->query("dex")<26 )
                return notify_fail("你研究了半天，只觉依自己的身法灵动"
                                   "性，根本无法修习这门武功。\n");

        if( me->query("con")<32 )
        {
                tell_object(me, "你演练完毕，只觉依自己的根骨不足，根"
                                "本无法修习这门武功。\n");
                return 0;
        }

        if( me->query("str")<31 )
        {
                tell_object(me, "你演练完毕，只觉依自己的臂力不足，根"
                                "本无法修习这门武功。\n");
                return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 250)
                return notify_fail("你觉得苗家剑法和胡家刀法都极其深奥"
                                   "，依照自己武学修养难以理解。\n");

        if( me->query("max_neili")<4500 )
                return notify_fail("你的内力太弱，无法将苗家剑法和胡家"
                                   "刀法二者合一学习。\n");

        if (lvls < 250 || lvlb < 250)
                return notify_fail("你的刀剑根基火候不足，难以修炼刀剑"
                                   "归真。\n");

        // 刀法和剑法均低于刀剑归真
        if (lvls < lvld && lvlb < lvld)
                return notify_fail("你的刀剑根基火候不足，无法领会更高"
                                   "深的刀剑归真。\n");

        // 刀法和剑法中其一低于刀剑归真
        if (lvls < lvld || lvlb < lvld)
        {
                // 倘若修炼者为武学大宗师，且基本刀法及剑法等级均
                // 超过 320 级，则只需要其中之一支持即可
                if (! ultrap(me) || lvls < 320 || lvlb < 320)
                        return notify_fail("你的刀法或剑法火候不足，无"
                                           "法领会更高深的刀剑归真。\n");
        }
        return 1;
}

int practice_skill(object me)
{
        if( me->query("qi")<100 )
                return notify_fail("你的体力不够练刀剑归真。\n");

        if( me->query("neili")<100 )
                return notify_fail("你的内力不够练刀剑归真。\n");

        me->receive_damage("qi", 85);
        me->add("neili", -85);
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

/*
void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);

        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}
*/

void skill_improved(object me)
{
        int lvl;

        lvl = me->query_skill("daojian-guizhen", 1);

        if( lvl >= 200 &&
            !me->query("can_perform/daojian-guizhen/ben") )
        {
                tell_object(me, HIC "你通晓了刀剑归真「" HIR "万马奔腾" HIC "」的奥秘。\n" NOR);
                me->set("can_perform/daojian-guizhen/ben", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }

        if( lvl >= 300 &&
            !me->query("can_perform/daojian-guizhen/po") )
        {
                tell_object(me, HIC "你通晓了刀剑归真「" HIR "破定军山" HIC "」的奥秘。\n" NOR);
                me->set("can_perform/daojian-guizhen/po", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }

        if( lvl >= 250 &&
            !me->query("can_perform/daojian-guizhen/tian") )
        {
                tell_object(me, HIC "你通晓了刀剑归真「" HIR "刀剑七重天" HIC "」的奥秘。\n" NOR);
                me->set("can_perform/daojian-guizhen/tian", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }

        if( lvl >= 280 &&
            !me->query("can_perform/daojian-guizhen/xue") )
        {
                tell_object(me, HIC "你通晓了刀剑归真「" HIR "天下有血" HIC "」的奥秘。\n" NOR);
                me->set("can_perform/daojian-guizhen/xue", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 100)
                return 0;

        if (damage_bonus < victim->query_int())
                return 0;

        // if (me->query_temp("daojian-guizhen/max_pfm"))
        {
                victim->receive_damage("qi", damage_bonus, me);
                victim->receive_wound("qi", damage_bonus / 2, me);
                return random(2) ? HIR "只听「噗嗤」一声，一股鲜血至$n"
                                   HIR "胸前射出。\n" NOR:

                                   HIR "霎时只见寒光一闪，一柱鲜血至$n"
                                   HIR "胸前射出。\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"daojian-guizhen/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;
        if( !objectp(me->query_temp("weapon")) )
                return 0;

        lvl = me->query_skill("daojian-guizhen", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp, level;

        if ((level = (int)me->query_skill("daojian-guizhen", 1)) < 100 ||
            !objectp(me->query_temp("weapon")) )
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("daojian-guizhen", 1) + me->query_skill("hujia-daofa", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                result += (["msg" : HIC "$n" HIC "突然使出一招「大雪纷纷」，发出万长白芒，寒光四射，直劈向$N"
                            "化守势为攻势，对$N发动进攻！\n" NOR]);
                COMBAT_D->do_attack(me,ob,me->query_temp("weapon"));
                return result;
        }
}
