//anranxiaohun-zhang.c 黯然消魂掌
// By hxsd@ CuteRabbit Studio 99-4-16 16:22 new
#include <ansi.h>
//inherit F_SSERVER;
inherit SKILL;

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([      "action": ""+(order[random(13)])+"$N单臂负后，凝目远眺，脚下虚浮，胸前门户洞开，全身姿势与武学中各项大忌无不吻合。$n略一迟疑，浑身已为$N掌力所绕"NOR"",
        "dodge": 30,
        "force": 400,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 5,
        "damage_type": "内伤"
]),
([      "action": "$N一招"+(order[random(13)])+"「心惊肉跳」"NOR"，小腹肌肉颤动，同时胸口向内收缩，倏地弹出迎向$n的双拳",
        "dodge": 15,
        "force": 380,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 25,
        "damage_type": "瘀伤"
]),
([	"action": "$N一式"+(order[random(13)])+"「杞人忧天」"NOR"，抬头向天，对$n的招数浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拢住$n全身",
	"dodge": 10,
	"force": 320,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 35,
	"damage_type": "抓伤"
]),
([	"action": "$N突然手足齐动，一式"+(order[random(13)])+"「无中生有」"NOR"左掌右袖，双足头锤，连的胸背腰腹尽皆有招式攻出，无一不足以伤人",
        "dodge": 15,
	"force": 160,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 45,
	"damage_type": "内伤"
]),
([	"action": "$N一式"+(order[random(13)])+"「拖泥带水」"NOR"，右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，暗藏五行杀机，直罩$n的$l",
	"dodge": 30,
	"force": 230,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 55,
	"damage_type": "瘀伤"
]),
([	"action": "$N身影陡转，如鬼魅般忽前忽后，瞬左瞬右，一式"+(order[random(13)])+"「徘徊空谷」"NOR"掌风已至$n的$l",
	"dodge": 10,
	"force": 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 65,
	"damage_type": "抓伤"
]),
([	"action": "$N长叹一声，沧桑疲惫，身形凝重，却是一招"+(order[random(13)])+"「力不从心」"NOR"，诱得$n全力进击之际，反手直拍命门大穴",
	"dodge": 10,
	"force": 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 75,
	"damage_type": "内伤"
]),
([	"action": "$N面目僵然，四肢挺直，无弯无折，便似"+(order[random(13)])+"「行尸走肉」"NOR"般，刀臂剑腿，横斩直刺$n的$l",
	"dodge": 25,
	"force": 500,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 85,
	"damage_type": "瘀伤"
]),
([	"action": "$N一式"+(order[random(13)])+"「庸人自扰」"NOR"，左手锤胸，一边晃首不止，身形却也在倏忽间绕敌身后，右掌闪电般暴击$n的后心",
	"dodge": 20,
	"force": 430,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 105,
	"damage_type": "瘀伤"
]),
([	"action": ""+(order[random(13)])+"$N突然头下脚上，倒过身子，口中嗬嗬而叫，手代足行，足似手攻，双足狂踢未定，双手互又闪电般拍向$n的下盘"NOR"",
	"dodge": 10,
	"force": 360,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 125,
	"damage_type": "震伤"
]),
([	"action": ""+(order[random(13)])+"$N忽然狂笑不止，忽又颠哭阵阵，嬉笑哀啼，$n不由心神驿动，正迷沉恍惚中$N已一腿攻向$n的$l"NOR"",
	"dodge": 20,
	"force": 400,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 145,
	"damage_type": "瘀伤"
]),
([	"action": ""+(order[random(13)])+"却见$N翻身坐倒，双手合十，默颂经文，旋及人似车轮般旋向空中，凭空砸向$n,威力骇人，无法硬接"NOR"",
	"dodge": 20,
	"force": 450,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
        "lvl" : 165,
	"damage_type": "瘀伤"
]),
([	"action" : "$N一招"HIW"杞人忧天"NOR"抬头向天，浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拍向$n的$l。",
	"force" : 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 120,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 0,
	"skill_name" : "杞人忧天",
	"damage_type" : "内伤"
]),
([	"action" : "$N一招"HIG"无中生有"NOR"手臂下垂，绝无半点防御姿式，突然间手足齐动，左掌右袖、双足头锤、连得胸背腰腹尽皆有招式发出撞向$n.",
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 100,
	"force" : 250,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 10,
	"skill_name" : "无中生有",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIB"拖泥带水"NOR"右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，左右齐攻$n。",
	"force" : 250,
	"dodge" : 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 20,
	"skill_name" : "拖泥带水",
	"damage_type" : "内伤"
]),

([	"action" : "$N一招"HIY"力不从心"NOR"含胸收腹，头缓缓低下，脚步沉重的迈向$n,右掌软绵绵的拍向$n的$l。",
	"force" : 300,
	"damage" : (int)this_player()->query("age")*8,
	"dodge" : 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"lvl" : 30,
	"skill_name" : "力不从心",
    "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIR"行尸走肉"NOR"踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无的踢向$n",
	"force" : 250,
	"damage" : (int)this_player()->query("age")*8,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 100,
	"lvl" : 40,
	"skill_name" : "行尸走肉",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双掌平托，一招"HIM"庸人自扰"NOR"没精打采的拍向$n的$l.",
	"force" : 250,
	"dodge" : 100,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 50,
	"skill_name" : "庸人自扰",
            "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"RED"倒行逆施"NOR"突然纵起丈余，头下脚上，倒过身子，一掌拍向$n的$l",
	"force" : 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 100,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 60,
	"skill_name" : "倒行逆施",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"YEL"心惊肉跳"NOR"凝目远眺，脚下虚浮，胸前门户洞开，全身姿式与武学中各项大忌无不吻合。",
	"force" : 300,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : 120,
	"damage" : (int)this_player()->query("age")*9,
	"lvl" : 70,
	"skill_name" : "心惊肉跳",
           "damage_type" : "内伤"
]),
([	"action" : "$N一招"BLU"废寝忘食"NOR"脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，左掌右拳攻向$n的$l。",
	"force" : 300,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*10,
	"lvl" : 80,
	"skill_name" : "废寝忘食",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIC"徘徊空谷"NOR"左攻右打，虚虚实实的攻向$n的$l。",
	"force" : 300,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*11,
	"lvl" : 90,
	"skill_name" : "徘徊空谷",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"CYN"饮恨吞声"NOR"左手做饮酒状，右掌斜斜劈向$n的$l。",
	"force" : 350,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*12,
	"lvl" : 100,
	"skill_name" : "饮恨吞声",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"MAG"六神不安"NOR"身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n的$l。",
	"force" : 400,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*13,
	"lvl" : 110,
	"skill_name" : "六神不安",
           "damage_type" : "内伤"
]),
([	"action" : "$N一招"WHT"穷途末路"NOR"闪身到$n身旁，左掌举到胸前平推而出，接着右掌斜斜劈向$n的$l。",
	"force" : 450,
	"dodge" : 120,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*14,
	"lvl" : 120,
	"skill_name" : "穷途末路",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIY"呆若木鸡"NOR"双目直直的盯着$n，身体动也不动一下的飞向$n",
	"force" : 500,
	"dodge" : 150,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*15,
	"lvl" : 130,
	"skill_name" : "呆若木鸡",
           "damage_type" : "内伤"
]),
([	"action" : "$N低头冥想，一招"HIB"若有所失"NOR"右掌向外平平推向$n的$l。",
	"force" : 500,
	"dodge" : 150,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*16,
	"lvl" : 140,
	"skill_name" : "若有所失",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIB"四通八达"NOR"双掌晃出千万掌影将$n笼罩在掌力之下。",
	"force" : 580,
	"dodge" : 160,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*17,
	"lvl" : 150,
	"skill_name" : "四通八达",
           "damage_type" : "内伤"
]),
([	"action" : "$N错步上前，一招"HIB"鹿死谁手"NOR"招招抢先，以快打慢，一个转身已经转到了$n的身后，运指如风点向$n的大椎穴。",
	"force" : 600,
	"dodge" : 160,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*18,
	"lvl" : 160,
	"skill_name" : "鹿死谁手",
           "damage_type" : "点穴"
]),
([      "action" : "$N一招「"HIW"杞人忧天"NOR"」抬头向天，浑若不见，呼的一掌"
                   "向自己头顶空空拍出，手掌斜下，掌力化成弧\n"
                   "形，四散落下拍向$n的$l",
        "force"  : 250,
        "attack" : 40,
        "dodge"  : 40,
        "damage" : 120,
        "lvl"    : 0,
        "skill_name" : "杞人忧天",
        "damage_type": "内伤"
]),
([      "action" : "$N一招「"HIG"无中生有"NOR"」手臂下垂，绝无半点防御姿式，"
                   "突然间手足齐动，左掌右袖、双足头锤、连得\n"
                   "胸背腰腹尽皆有招式发出撞向$n",
        "force"  : 260,
        "attack" : 45,
        "dodge"  : 45,
        "damage" : 125,
        "lvl"    : 10,
        "skill_name" : "无中生有",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIB"拖泥带水"NOR"」右手云袖飘动，宛若流水，左掌"
                   "却重滞之极，便似带着几千斤泥沙一般，左右\n"
                   "齐攻$n",
        "force"  : 280,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 130,
        "lvl"    : 20,
        "skill_name" : "拖泥带水",
        "damage_type": "内伤"
]),

([      "action" : "$N一招「"HIY"力不从心"NOR"」含胸收腹，头缓缓低下，脚步沉"
                   "重，右掌软绵绵的拍向$n的$l",
        "force"  : 300,
        "attack" : 55,
        "dodge"  : 55,
        "damage" : 135,
        "lvl"    : 40,
        "skill_name" : "力不从心",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIR"行尸走肉"NOR"」踢出一脚。这一脚发出时恍恍惚"
                   "惚，隐隐约约，若有若无的踢向$n",
        "force"  : 330,
        "attack" : 60,
        "dodge"  : 60,
        "damage" : 140,
        "lvl"    : 60,
        "skill_name" : "行尸走肉",
        "damage_type": "瘀伤"
]),
([      "action" : "$N双掌平托，一招「"HIM"庸人自扰"NOR"」没精打采的拍向$n的$l",
        "force"  : 360,
        "attack" : 70,
        "dodge"  : 65,
        "damage" : 145,
        "lvl"    : 80,
        "skill_name" : "庸人自扰",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"RED"倒行逆施"NOR"」突然纵起丈余，头下脚上，倒过"
                   "身子，一掌拍向$n的$l",
        "force"  : 390,
        "attack" : 80,
        "dodge"  : 70,
        "damage" : 50,
        "lvl"    : 100,
        "skill_name" : "倒行逆施",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"YEL"心惊肉跳"NOR"」凝目远眺，脚下虚浮，胸前门户"
                   "洞开，全身姿式与武学中各项大忌无不吻合",
        "force"  : 420,
        "attack" : 90,
        "dodge"  : 75,
        "damage" : 155,
        "lvl"    : 120,
        "skill_name" : "心惊肉跳",
        "damage_type": "内伤"
]),
([      "action" : "$N一招「"BLU"废寝忘食"NOR"」脚下虚浮，有如几天不吃不睡后"
                   "的脚步朗舱的袭到$n的身旁，左掌和右拳攻\n"
                   "向$n的$l",
        "force"  : 460,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 160,
        "lvl"    : 140,
        "skill_name" : "废寝忘食",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIC"徘徊空谷"NOR"」左攻右打，虚虚实实的攻向$n的$l",
        "force"  : 490,
        "attack" : 110,
        "dodge"  : 85,
        "damage" : 65,
        "lvl"    : 160,
        "skill_name" : "徘徊空谷",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"CYN"饮恨吞声"NOR"」左手做饮酒状，右掌斜斜劈向$n的$l",
        "force"  : 520,
        "attack" : 55,
        "dodge"  : 90,
        "damage" : 190,
        "lvl"    : 70,
        "skill_name" : "饮恨吞声",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"MAG"六神不安"NOR"」身如陀螺急转，展开轻功围着$n"
                   "快速游走，忽然飞身而起，拍向$n的$l",
        "force"  : 550,
        "attack" : 50,
        "dodge"  : 95,
        "damage" : 175,
        "lvl"    : 200,
        "skill_name" : "六神不安",
        "damage_type": "内伤"
]),
([      "action" : "$N一招「"WHT"穷途末路"NOR"」闪身到$n身旁，左掌举到胸前平"
                   "推而出，接着右掌斜斜劈向$n的$l",
        "force"  : 570,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 180,
        "lvl"    : 220,
        "skill_name" : "穷途末路",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIY"呆若木鸡"NOR"」双目直直的盯着$n，身体动也不"
                   "动一下的飞向$n",
        "force"  : 590,
        "attack" : 55,
        "dodge"  : 55,
        "damage" : 185,
        "lvl"    : 240,
        "skill_name" : "呆若木鸡",
        "damage_type": "内伤"
]),
([      "action" : "$N低头冥想，一招「"HIB"若有所失"NOR"」右掌向外平平推向$n"
                   "的$l",
        "force"  : 520,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 190,
        "lvl"    : 260,
        "skill_name" : "若有所失",
        "damage_type": "瘀伤"
]),
([      "action" : "$N一招「"HIB"四通八达"NOR"」双掌晃出千万掌影将$n笼罩在掌"
                   "力之下",
        "force"  : 650,
        "attack" : 165,
        "dodge"  : 115,
        "damage" : 95,
        "lvl"    : 280,
        "skill_name" : "四通八达",
        "damage_type": "内伤"
]),
([      "action" : "$N错步上前，一招「"HIB"鹿死谁手"NOR"」招招抢先，以快打慢，"
                   "一个转身已经转到了$n的身后，运指如风点\n"
                   "向$n的大椎穴",
        "force"  : 580,
        "attack" : 50,
        "dodge"  : 50,
        "damage" : 100,
        "lvl"    : 300,
        "skill_name" : "鹿死谁手",
        "damage_type": "内伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage=="strike"; }


int valid_learn(object me)
{
	if(!me->query("couple/have_couple")) 
		return notify_fail("你还没有所爱的人，不能领会其中的精要！\n");
//	if (me->query("gender") != "男性") 
//                return notify_fail("你体会不到男人思念一个人的心情。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然消魂掌必须空手。\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练黯然消魂掌。\n");
	if ((int)me->query_str()< 30)
		return notify_fail("你的臂力太弱，无法练黯然消魂掌。\n");	
	if ((int)me->query_con() < 30 )
		return notify_fail("你没有雄厚的体质无法黯然消魂掌。\n");
        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("你的轻功太差，无法练黯然消魂掌。\n");
        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("你的玉女剑法火候太浅。\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("你的玉女身法火候太浅。\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("你的天罗地网火候太浅。\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("你的美女拳火候太浅。\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("你的银索金铃火候太浅。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);
        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}
 
mapping query_action(object me, object weapon)
{
    int i, j, level, adjust, tmp;
//    object target; 
string msg;            
    level   = (int) me->query_skill("anranxiaohun-zhang",1);
    for(i = sizeof(action); i > 0; i--) {
        if(level > action[i-1]["lvl"]) {
            j = NewRandom(i, 20, level/5);
//            target = offensive_target(me);    
              switch(random(3)){
                  case 0: msg = HIC"$N心下万念俱灰，没精打采的挥袖卷出，拍出一掌，只听得噗的一声，这一掌正好击向$n肩头"NOR; break;
                  case 1: msg = HIY"$N心下万念俱灰，没精打采的挥袖卷出，拍出一掌，只听得噗的一声，这一掌正好击向$n肩头"NOR; break;
                  case 2: msg = HIR"紧跟着$N踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无。砰的一响，向$n胸口袭去"NOR; break;
                  default: msg = HIC"$N心下万念俱灰，没精打采的挥袖卷出，拍出一掌，只听得噗的一声，这一掌正好击向$n肩头"NOR; break;
              }


            if (me->query_temp("anran")
               && me->query("jiali") >= 50 
               && random(10) >= 5
               && me->query_skill("yunv-xinfa",1)>10) {                
                    return ([  
                      "action":msg, 
                    "force" : action[j]["force"]+30,
                    "dodge":action[j]["dodge"]+50,
                    "damage": level+700,
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"黯然掌掌风":"黯然掌掌力",
                    "damage_type" : random(2)?"瘀伤":"割伤",
                    ]);
               }
            if (level >= 130 && random(6) > 4
               && me->query("jiali") >= 50 
               && random(10) >= 5
               && me->query_skill("yunv-xinfa",1)>10) {                
                    return ([  
                      "action":msg, 
                    "force" : action[j]["force"],
                    "dodge":action[j]["dodge"],
                    "damage": level/2+600,
                    "lvl" : action[j]["lvl"],
                    "weapon" : random(2)?"掌风":"黯然掌力",
                    "damage_type" : "割伤",
                    ]);
               }
if(!me->query_skill("yunv-xinfa"))
{
    action[j]["force"]  = action[j]["force"]/2;
    action[j]["dodge"] = action[j]["dodge"]/2;
    action[j]["parry"]  = action[j]["parry"]/2;
    action[j]["attack"] = action[j]["attack"]/2;
    action[j]["damage"] = action[j]["damage"]/2;
}
            return action[j];
        }
    }
} 


int practice_skill(object me)
{
	if (me->query_skill("anranxiaohun-zhang",1) > 100
	&& (int)me->query_skill("yunv-xinfa", 1) < (int)me->query_skill("anranxiaohun-zhang",1) )
		return notify_fail("你现在只能用learn的来学黯然消魂掌。\n");	
	if ((int)me->query("jing") < 100)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("qi") < 100)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query_str() < 30 )
		return notify_fail("你没有雄壮的臂力无法黯然消魂掌。\n");
	if ((int)me->query_con() < 30 )
		return notify_fail("你没有雄厚的体质无法黯然消魂掌。\n");
        if ((int)me->query_skill("dodge") < 100)
                return notify_fail("你的轻功太差，无法练黯然消魂掌。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练黯然消魂掌。\n");
        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("你的玉女剑法火候太浅。\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("你的玉女身法火候太浅。\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("你的天罗地网火候太浅。\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("你的美女拳火候太浅。\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("你的五展梅火候太浅。\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("你的银索金铃火候太浅。\n");



        me->receive_damage("jing", 70);
	me->receive_damage("qi", 70);
	me->add("neili", -70);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j;
    j = me->query_skill("anranxiaohun-zhang", 1);
    if( damage_bonus < 100 ) return 0;
    if( !random(8) && !victim->is_busy() && j > 140
     && me->query_skill_mapped("parry") == "anranxiaohun-zhang"
     && me->query("neili") > 1000 && me->query("max_neili") > 1500 
     && j > random(victim->query_skill("dodge",1))
     && (int)me->query_skill("yunv-xinfa", 1) > 10
     && me->query_skill_mapped("force") == "yunv-xinfa"){
          switch(random(3)){
            case 0 :
               msg = YEL"$N抬头向天，浑若不见，呼的一掌向头顶空空拍出，手掌斜下，掌力化成弧形，四散落下！\n"NOR;
               msg += HIR"结果$n被这一招「杞人忧天」带得别说挣扎，竟连站定脚步也是不能。\n"NOR; 
               if (!victim->is_busy())victim->start_busy(4);
               break;
            case 1 :
               msg = HIB"$N右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般！\n"NOR;
               msg += HIR"结果$n被这一招「拖泥带水」带得犹如身陷洪涛巨浪，跌跌撞撞。\n"NOR;
               if (!victim->is_busy())victim->start_busy(4);               
               break;
            case 2 :
               msg = HIG"突然间$N手足齐动，左掌右袖、双足头锤、连得胸背腰腹尽皆有招式发出！\n"NOR;
               msg += HIR"结果$n被这一招「无中生有」带得自身全然身不由主的境地。\n"NOR;
               if (!victim->is_busy())victim->start_busy(4);
               break;               
          }         
          message_vision(msg, me, victim);
    }
	if( damage_bonus < 100 ) return 0;
	if( damage_bonus/2 > victim->query_str() ) {
if((int)me->query_skill("yunv-xinfa", 1) > 10 || random(10) > 5
&& me->query_skill_mapped("force") == "yunv-xinfa")
{
if (me->query_skill_mapped("unarmed") == "anranxiaohun-zhang")
{
		victim->receive_wound("qi", (random(j)) / 2+20 );
		victim->receive_damage("qi", (random(j)) /2+20 );
		return HIR "只听到“哇”的一声，"+ victim->name()+"喷出了一大口鲜血！\n" NOR;
}
}
	}
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yunv-xinfa",1);
        skill = me->query_skill("yunv-xinfa", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("yunv-xinfa",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "yunv-xinfa"))
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
msg = HIC"$N"+HIC+"满场游走，招断意连，绵绵不绝，一招未毕，二招至 !$n双眼一花不知所措！\n" +NOR;
if (random(2)==0)
{
msg += HIY"$N"+HIY+"目光一闪，一把玉锋针扔出 !$n 一不当心，身上连中了几枚！\n" +NOR;	
ob->apply_condition("yf_poison",20);
}
           message_vision(msg, me, ob);
  ob->start_busy(6);  
}


           return j;
}      

string perform_action_file(string action)
{
	return __DIR__"anranxiaohun-zhang/" + action;
}


string query_description()  
{
        return 
        "杨过自和小龙女在绝情谷断肠崖前分手，不久便由神雕带着在海潮之中练功，"
        "数年之后，除了内功循序渐进之外，别的无可再练，心中整日价思念小龙女，"
        "渐渐的形销骨立，了无生趣。一日在海滨悄然良久，百无聊赖之中随意拳打脚"
        "踢，其时他内功火候已到，一出手竟具极大威力，轻轻一掌，将海滩上一只大"
        "海龟的背壳打得粉碎。他由此深思，创出了一套完整的掌法，出手与寻常武功"
        "大异，厉害之处，全在内力，一共是一十七招。他生平受过不少武学名家的指"
        "点，自全真教学得玄门正宗内功的口诀，自小龙女学得【玉女心经】，在古墓"
        "中见到【九阴真经】，欧阳锋以蛤蟆功和逆转经脉，洪七公与黄蓉授以打狗棒"
        "法，黄药师授以弹指神通和玉箫剑法，除了一阳指之外，东邪、西毒、北丐、"
        "中神通的武学无所不窥，而古墓派的武学又于五大高人之外别创蹊径，此时融"
        "会贯通，已是卓然成家。只因他单剩一臂，是以不在招数变化取胜，反而故意"
        "与武学通理相反。他将这套掌尘定名为“黯然销魂掌”，取的是江淹【别赋】"
        "中那一句“黯然销魂者，唯别而已矣”之意。";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
