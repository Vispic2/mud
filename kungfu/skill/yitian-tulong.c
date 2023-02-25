// yitian-tulong.c 「倚天屠龙功」
// xQin 9/1/98
// Under Modify

#include <ansi.h>
#include <combat.h>

inherit SKILL;
//inherit F_SSERVER;

int raozhi(object me, object victim, object weapon, int damage);
string *taijin = ({"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

nomask int parry_available() { return 1; }
string *parry_msg = ({
	"$p但觉一股劲风袭至胸口，当下$W一带，画出一个上撇，刚好封住了$P$w的来势。\n",
	"危急之中，$p伸$W在$P的$w上一按，一借力，轻轻巧巧的避过，这一招乃是「武」字诀中的一戈。\n",
	"$p$W下掠，反手使出一记「刀」字诀，带住$P的$w，$W一撇一点，身子借势窜起。\n",
	"当下$p$W使一招「刀」字诀中的左撇，借着$P的来势，稍加拨动，当千钧一发之际，转危为安。\n",
});

string query_parry_msg(object weapon, object victim)
{
        object ob;

        if (!objectp(ob = victim->query_temp("weapon")) )
                return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", random(2)?"左手":"右手");
        else
                return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action_unarmed = ({
([      "action":"$N右掌疾探，回指反抓，左足飞起，正好踢向$n的$l",
        "force" : 260,
        "dodge" : 40,
        "parry" : 20,
        "damage": 250,
        "damage_type":  "瘀伤"
]),
([      "action":"$N左掌拍出，右掌陡地后发先至，跟着左掌斜穿，又从後面抢了上来",
        "force" : 280,
        "dodge" : 40,
        "parry" : 20,
        "damage": 290,
        "lvl" : 112,
        "damage_type":  "瘀伤"
]),
([      "action":"$N一个左拗步、抢到了西首，右掌自左向右平平横扫，打向$n的太阳穴",
        "force" : 260,
        "dodge" : 40,
        "parry" : 20,
        "damage": 300,
        "damage_type":  "瘀伤"
]),
([      "action":"$N倏的跃起，飞身而前，左手一挥一掠，却是「天」字诀的一撇",
        "force" : 260,
        "dodge" : 40,
        "parry" : 20,
        "damage": 310,
        "damage_type":  "擦伤"
]),
([      "action":"$N招数一变，双掌飞舞，有若絮飞雪扬，软绵绵不着力气，用的正是「莫」字诀",
        "force" : 200,
        "dodge" : 80,
        "parry" : 20,
        "damage": 320,
        "damage_type":  "内伤"
]),
([      "action":"$N转身吐气，左拳送出，却是「下」字诀的一直，拍的一声，击向$n的$l",
        "force" : 220,
        "dodge" : 130,
        "parry" : 20,
        "damage": 250,
        "damage_type":  "瘀伤"
]),
([      "action":"$N神定气足，挥洒自如，蓦地右手倏出，使一个「龙」字诀中的一钩，抓向$n",
        "force" : 240,
        "dodge" : 180,
        "parry" : 20,
        "damage": 320,
        "damage_type":  "抓伤",
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :)
]),
([      "action":"$N双足一点，纵起丈余，使出一招「争」字诀中的一下直钩，右手在半空中疾挥下来",
        "force" : 360,
        "dodge" : 110,
        "parry" : 20,
        "damage": 320,
	"weapon": "右手",
        "damage_type":  "割伤"
]),
([      "action":"$N长啸一声，右掌直划下来，当真是星剑光芒，如矢应机，霆不暇发，电不及飞，这一直乃是「锋」字的最後一笔",
        "force" : 300,
        "dodge" : 140,
        "parry" : 20,
        "damage": 420,
	"weapon": "右掌",
        "damage_type":  "割伤"
])
});

mapping *action_weapon = ({
([      "action" : "$N剑走轻灵，光闪如虹，$w疾点而出，当的一声，剑尖斜砸$n",
        "force" : 200,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 320,
        "damage_type" : "刺伤",
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :)
]),
([      "action" : "$N跟着纵起，凌空下击，捷若御风，$w一转，点向$n的$l，吞吐开阖之际，又飘逸又凝重",
        "force" : 250,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 340,
        "damage_type" : "刺伤"
]),
([      "action" : "$N当下左足踏上，剑交左手，虚虚实实，剑尖上光芒闪烁，嗤嗤嗤的发出轻微响声",
        "force" : 250,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 360,
        "damage_type" : "刺伤"
]),
([      "action" : "$N倏的跃起，飞身而前，$w一挥一掠，却是「天」字诀的一撇",
        "force" : 200,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 380,
        "damage_type" : "割伤"
]),
([      "action" : "$N$w一起，使一招「谁」字诀，但见剑尖乱颤，霎时间便如化为数千个剑尖，罩住$n中盘",
        "force" : 270,
        "dodge" : 130,
        "parry" : 20,
        "damage" : 380,
        "damage_type" : "刺伤"
]),
([      "action" : "$N转身吐气，$w送出，却是「下」字诀的一直，刺向$n的$l",
        "force" : 300,
        "dodge" : 130,
        "parry" : 20,
        "damage" : 440,
        "damage_type" : "刺伤"
]),
([      "action" : "突然间$N$w使招「龙」字诀中的一钩，嗤的一响，划向$n$l",
        "force" : 350,
        "dodge" : 115,
        "parry" : 20,
        "damage" : 460,
        "damage_type" : "割伤"
]),
([      "action" : "$N双足一点，纵起丈余，使出一招「争」字诀中的一下直钩，将$w在半空中疾挥下来",
        "force" : 400,
        "dodge" : 130,
        "parry" : 20,
        "damage" : 480,
        "damage_type" : "割伤"
]),
([      "action" : "$N右手$w电光火石般连连颤动，自$n灵台穴一路顺势直下，使的是「锋」字诀中最後一笔一直，便如书法中的颤笔，疾如星火，气吞牛",
        "force" : 450,
        "dodge" : 135,
        "parry" : 20,
        "damage" : 400,
        "damage_type" : "刺伤"
])
});

//画天字 :) just an example
string  *special_msg = ({
HIY"$N跟着纵起，凌空下击，捷若御风，$w一转，点向$n的$l，宛如“天”字的一横"NOR,
HIY"接着$N双足一点，纵起丈余，一招“天”字诀中的第二横，将$w在半空中疾挥下来"NOR,
HIY"$N倏的跃起，飞身而前，$w一挥一掠，却是“天”字诀的一撇"NOR,
HIY"$N顺手使出“天”字的一捺，$w扫向$n$l，劲道凌厉之极"NOR,
});


int valid_enable(string usage) 
{ 
    return usage == "cuff" || usage == "parry" || usage == "unarmed"|| usage == "sword"; 
}

object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

mapping query_action(object me, object weapon)
{
        object victim;
        string *limbs, *msg, limb, msg1, msg2;

        if( !victim && me->is_fighting() ) victim = offensive_target(me);
//        limbs = victim->query("limbs");
//        limb = limbs[random(sizeof(limbs))];
if (victim && me && victim!=me)
{

	msg = ({
		HIW "突然间$N$w"HIW"破空，疾刺$n"+limb+"，剑到中途，剑尖微颤，竟然弯了过去，斜刺$p$l" NOR,
		HIY "$N右手捏着剑诀，左手$w"HIY"不住抖动，突然平刺，剑尖急颤，看不出攻向何处。这一剑笼罩了$n上盘七处要穴" NOR,
		HIC "$N左手$w"HIC"缓缓向前划出，剑身弯成一道弧形。$n觉一股森森寒气，直逼过来" NOR,
	});

        msg1 = "不料铮的一声轻响，$w反弹过来，直刺入$p的$l";
        msg2 = "不料$P剑交右手，寒光一闪，快速无伦地向$p$l划出";

        if(me->query_temp("raozi_attack")){
                me->add("neili", -(me->query("jiali")));
		me->add("jing", -(me->query("jiajin")));
                return ([
        	"action": me->query_temp("raozi_attack")==1?msg1:msg2,
        	"force" : 550+random(200),
        	"dodge" : 60,
        	"parry" : 20,
        	"damage" : 500+random(500),
        	"damage_type": me->query_temp("raozi_attack")==1?"刺伤":"割伤",
		]);
                }
        if(me->query_temp("tian") > 4) me->delete_temp("tian");
        if(me->query_temp("tian")){
                me->add_temp("tian", 1);
                me->add("neili", -20);
        	return ([
        	"action": special_msg[me->query_temp("tian")-2],
        	"force" : 450+random(200),
        	"dodge" : 60,
        	"parry" : 20,
        	"damage" : 500+random(500),
        	"damage_type":"刺伤",
		]);
		}
	 if (random(me->query_temp("raozhi")) > 100 ) {
		me->add("neili", -50);
        	return ([
        	"action": msg[random(sizeof(msg))],
        	"force" : 550+random(300),
        	"dodge" : 110,
        	"parry" : 320,
        	"damage" : 500+random(600),
        	"damage_type":"刺伤",
		"post_action": (: raozhi :)
		]);
		}
}

        if (!weapon)
		return action_unarmed[random(sizeof(action_unarmed))];
        else
		return action_weapon[random(sizeof(action_weapon))];
       
}

int valid_learn(object me)
{
        if ((int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("你的「太极神功」火候太浅。\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) > 1)
                return notify_fail("你有「黯然消魂掌」学不了这个!\n");

        if ((int)me->query_skill("taiji-quan", 1) < 200)
                return notify_fail("你的「太极拳」火候太浅。\n");
        if ((int)me->query_skill("juehu-shou", 1) < 200)
                return notify_fail("你的三阴绝户手火候太浅。\n");
        if ((int)me->query_skill("wudang-mianzhang", 1) < 200)
                return notify_fail("你的武当绵掌火候太浅。\n");
        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("你的绕指柔剑火候太浅。\n");
        if (me->query_skill("yitian-tulong",1) > 299)
        return notify_fail("你觉头脑一片混乱，难以领会「倚天屠龙功」的精髓所在。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);
return 1;
}

int practice_skill(object me)
{
        if ((int)me->query_skill("taiji-shengong", 1) < 200)
                return notify_fail("你的「太极神功」火候太浅。\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) > 1)
                return notify_fail("你有「黯然消魂掌」学不了这个!\n");

        if ((int)me->query_skill("taiji-quan", 1) < 200)
                return notify_fail("你的「太极拳」火候太浅。\n");

        if ((int)me->query_skill("juehu-shou", 1) < 200)
                return notify_fail("你的三阴绝户手火候太浅。\n");
        if ((int)me->query_skill("wudang-mianzhang", 1) < 200)
                return notify_fail("你的武当绵掌火候太浅。\n");
        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("你的绕指柔剑火候太浅。\n");
        if ((int)me->query("jing") < 200)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 200)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 200)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 100);
        me->receive_damage("jing", 100);
        me->add("neili", -100);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yitian-tulong/" + action;
}

int raozhi(object me, object victim, object weapon,int damage)
{
	int sword, force, ap, dp;
	string *limbs, limb, result, str, type;

	sword = me->query_skill("sword");
	force = me->query_skill("force");
        ap = (sword + force + me->query("combat_exp")/2000) * (99+random(5));
        dp = (victim->query_skill("dodge") + victim->query_skill("parry") + victim->query("combat_exp")/2000) * 100;

//        limbs = victim->query("limbs");
//        limb = limbs[random(sizeof(limbs))];
        type = random(2)?"刺伤":"割伤";
        
	if( damage < 0 && ap > dp ) 
	{
/*
           	damage = me->query_temp("apply/damage") + me->query_str() + me->query("jiali") + me->query("jiajin");
		damage = damage + random(force + sword) /10 ;
		if(me->query("neili") > random(victim->query("neili")*2) ) damage = damage + random(damage);
           	victim->receive_damage("qi", damage, me);
                if( random(damage) > (int)victim->query_temp("apply/armor"))
		victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me); 

                me->add("neili", -(me->query("jiali")));
		me->add("jing", -(me->query("jiajin")));
*/

		if (type == "刺伤") me->set_temp("raozi_attack", 1);
                else me->set_temp("raozi_attack", 2);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 2);
                me->delete_temp("raozi_attack");

/*
		message_vision("不料铮的一声轻响，"+weapon->name()+"反弹过来，直刺入$p"+limb+"！！\n",me,victim);
		else 
		message_vision("不料$P剑交右手，寒光一闪，快速无伦地向$p"+limb+"划出！！\n",me,victim);

           	result = COMBAT_D->damage_msg(damage, type);
           	result = replace_string( result, "$l", limb);
           	result = replace_string( result, "$w", weapon->name());
           	str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));

           	message_vision(result, me, victim);
           	message_vision("( $N"+str+" )\n", victim);
*/
		return 1;
	}

	return 1;
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
              
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
msg = HIG"$N 如抱太极，一股雄浑无比的力道组成了一个旋涡来！\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"的内力 被太极神功借力打力 反击在自己身上 ！\n"NOR;
//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}       
	if(me->query("combat_exp") > ob->query("combat_exp")*2/3
    	&& !me->query_temp("weapon")
    	&& me->query_skill_mapped("parry") == "yitian-tulong"
    	&& me->query_skill("taiji-shengong", 1) > 120
    	&& me->query_skill("yitian-tulong",1) > 120
    	&& me->query("neili") > 500 
    	&& living(me)
    	&& random(10) >= 6)
    {
    	message_vision(HIM"当下$N左手使一招「武」字诀中的右钩，带动$n攻来之势，右手使一招「刀」字诀中的左撇，以手掌稍加拨动，变了方向。只见$N长袖飞舞，手掌隐在袖中，竟似以衣袖卷起$n，掷向天空一般。但听得「腾」的一响，$n结结实实地摔在地上！\n"NOR,me,ob);         
if (ob->query("qi") > damage)
{
         ob->receive_damage("qi", damage/2+ob->query("jiali")*2, me);
         ob->receive_wound("qi", ob->query("jiali"), me);
if (!ob->is_busy())
         ob->start_busy(2);
}
         COMBAT_D->report_status(ob);
         return 500;
    }
    return 1;          
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
