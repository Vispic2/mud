// combatd.c

#pragma optimize
#pragma save_binary

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_DBASE;

// 关于玩家数据(/combat/)的说明
// PKS：杀害的玩家数目
// MKS；杀死的NPC数目(动物不计算)
// WPK：主动杀死玩家的次数
// WPK_NOTGOOD：主动杀死非正派(shen < 500)玩家的次数
// WPK_BAD：    主动杀死的邪派(shen <-500)玩家的次数
// WPK_NOTBAD： 主动杀死非邪派(shen >-500)玩家的次数
// WPK_GOOD：   主动杀死的正派(shen > 500)玩家的次数
// DPS：主动打晕玩家的次数
// DPS_NOTGOOD：主动打晕非正派(shen < 500)玩家的次数
// DPS_BAD：    主动打晕的邪派(shen <-500)玩家的次数
// DPS_NOTBAD： 主动打晕非邪派(shen >-500)玩家的次数
// DPS_GOOD：   主动打晕的正派(shen > 500)玩家的次数
// dietimes：   死亡的次数

// combat/today纪录(mapping)
// which_day: 日期(实际时间中日期)
// id       : n, 主动打晕某个ID的次数

#define DEFAULT_MAX_PK_PERDAY	   3
#define DEFAULT_MAX_PK_PERMAN	   1

// 经验底线(random(my_exp) > EXP_LIMIT，则不加经验)
#define	EXP_LIMIT	20000000
string *guard_msg = ({
	append_color(CYN "$N注视著$n的行动，企图寻找机会出手。"NOR"\n", CYN),
	append_color(CYN "$N正盯著$n的一举一动，随时准备发动攻势。"NOR"\n", CYN),
	append_color(CYN "$N缓缓地移动脚步，想要找出$n的破绽。"NOR"\n", CYN),
	append_color(CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。"NOR"\n", CYN),
	append_color(CYN "$N慢慢地移动著脚步，伺机出手。"NOR"\n", CYN),
});

string *catch_hunt_msg = ({
	append_color(HIW "$N和$n仇人相见分外眼红，立刻打了起来！"NOR"\n", HIW),
	append_color(HIW "$N对著$n大喝：「可恶，又是你！」"NOR"\n", HIW),
	append_color(HIW "$N和$n一碰面，二话不说就打了起来！"NOR"\n", HIW),
	append_color(HIW "$N一眼瞥见$n，「哼」的一声冲了过来！"NOR"\n", HIW),
	append_color(HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」"NOR"\n", HIW),
	append_color(HIW "$N喝道：「$n，我们的帐还没算完，看招！」"NOR"\n", HIW),
	append_color(HIW "$N喝道：「$n，看招！」"NOR"\n", HIW) });

string *winner_msg = ({
	append_color(CYN "\n$N哈哈大笑，说道：承让了！"NOR"\n", CYN),
	append_color(CYN "\n$N双手一拱，笑著说道：承让！"NOR"\n", CYN),
	append_color(CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！"NOR"\n", CYN),
	append_color(CYN "\n$N双手一拱，笑著说道：知道我的利害了吧！"NOR"\n", CYN),
	append_color(CYN "\n$n向后退了几步，说道：这场比试算我输了，下回看我怎么收拾你！"NOR"\n", CYN),
	append_color(CYN "\n$n向后一纵，恨恨地说道：君子报仇，十年不晚！"NOR"\n", CYN),
	append_color(CYN "\n$n脸色一寒，说道：算了算了，就当是我让你吧！"NOR"\n", CYN),
	append_color(CYN "\n$n纵声而笑，叫道：“你运气好！你运气好！”一面身子向后跳开。"NOR"\n", CYN),
	append_color(CYN "\n$n脸色微变，说道：佩服，佩服！"NOR"\n", CYN),
	append_color(CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！"NOR"\n", CYN),
	append_color(CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！"NOR"\n", CYN),
});

void create()
{
	int pd, pm;

	seteuid(getuid());
	set("channel_id", "战斗精灵");

	if (undefinedp(pd = CONFIG_D->query_int("max pk perday")))
		pd = DEFAULT_MAX_PK_PERDAY;

	if (undefinedp(pm = CONFIG_D->query_int("max pk perman")))
		pm = DEFAULT_MAX_PK_PERMAN;

	set("pk_perday", pd);
	set("pk_perman", pm);
}

// message after damage info
static string foo_before_hit = 0;
static string foo_after_hit = 0;

void set_bhinfo(string msg)
{
	if (! foo_before_hit)
	{
		foo_before_hit = msg;
		return;
	}

	foo_before_hit += msg;
}

void set_ahinfo(string msg)
{
	if (! foo_after_hit)
	{
		foo_after_hit = msg;
		return;
	}

	foo_after_hit += msg;
}

string query_bhinfo() { return foo_before_hit; }

string query_ahinfo() { return foo_after_hit; }

void clear_bhinfo() { foo_before_hit = 0; }

void clear_ahinfo() { foo_after_hit = 0; }

string damage_msg(int damage, string type)
{
	string str;
	if (damage == 0)
		return "结果没有造成任何伤害。\n";   
	switch (type)
	{
	case "擦伤":
	case "割伤":
		if (damage < 15)  str = "结果只是轻轻地划破$p的皮肉。"; else
		if (damage < 40)  str = "结果在$p$l划出一道细长的血痕。"; else
		if (damage < 100) str = "结果「嗤」地一声划出一道伤口！"; else
		if (damage < 200) str = "结果「嗤」地一声划出一道血淋淋的伤口！"; else
		if (damage < 400) str = "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！"; else
				  str = "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的伤口！！";
		  return str  +"\n";
		break;
	case "刺伤":
		if (damage < 15)  str = "结果只是轻轻地刺破$p的皮肉。"; else
		if (damage < 40)  str = "结果在$p$l刺出一个创口。"; else
		if (damage < 100) str = "结果「噗」地一声刺入了$n$l寸许！"; else
		if (damage < 200) str = "结果「噗」地一声深深刺进$n的$l！"; else
		if (damage < 400) str = "结果「噗嗤」地一声，$w已在$p$l刺出一个血窟窿！"; else
				  str = "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！";
		 return str  +"\n";
		break;
	case "瘀伤":
	case "震伤":
		if (damage < 15)  str = "结果只是轻轻地碰到，比拍苍蝇稍微重了点。"; else
		if (damage < 40)  str = "结果在$p的$l造成一处瘀青。"; else
		if (damage < 100) str = "结果一击命中，$n的$l登时肿了一块老高！"; else
		if (damage < 150) str = "结果一击命中，$n闷哼了一声显然吃了不小的亏！"; else
		if (damage < 200) str = "结果「砰」地一声，$n退了两步！"; else
		if (damage < 400) str = "结果这一下「砰」地一声，打得$n差一点摔倒在地！"; else
		if (damage < 800) str = "结果重重地击中，$n「哇」地一声吐出一口鲜血！"; else
				  str = "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！";
		 return str +"\n";
		break;
	case "内伤":
		if (damage < 15)  str = "结果只是把$n打得退了半步，毫发无损。"; else
		if (damage < 40)  str = "结果$n痛哼一声，在$p的$l造成一处瘀伤。"; else
		if (damage < 100) str = "结果一击命中，把$n打得痛得弯下腰去！"; else
		if (damage < 150) str = "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！"; else
		if (damage < 200) str = "结果$n闷哼了一声，脸色一下变得惨白，显然受伤不轻！"; else
		if (damage < 400) str = "结果重重地击中，$n「哇」地一声吐出一口鲜血！"; else
		if (damage < 800) str = "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！"; else
				  str = "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！";
		  return str +"\n";
		break;
	case "点穴":
		if (damage < 15)  str = "结果只是轻轻的碰到$n的$l，根本没有点到穴道。"; else
		if (damage < 40)  str = "结果$n痛哼一声，在$p的$l造成一处淤青。"; else
		if (damage < 100) str = "结果一击命中，$N点中了$n$l上的穴道，$n只觉一阵麻木！"; else
		if (damage < 200) str = "结果$n闷哼了一声，脸上一阵青一阵白，登时觉得$l麻木！"; else
		if (damage < 400) str = "结果$n脸色一下变得惨白，被$N点中$l的穴道,一阵疼痛遍布整个$l！"; else
		if (damage < 800) str = "结果$n一声大叫，$l的穴道被点中,疼痛直入心肺！"; else
				  str = "结果只听见$n一声惨叫，一阵剧痛游遍全身，跟着直挺挺的倒了下去！";
		  return str +"\n";
		break;
	case "抽伤":
		if (damage < 15)  str = "结果只是在$n的皮肉上碰了碰，好象只蹭破点皮。"; else
		if (damage < 40)  str = "结果在$n$l抽出一道轻微的紫痕。"; else
		if (damage < 100) str = "结果「啪」地一声在$n$l抽出一道长长的血痕！"; else
		if (damage < 200) str = "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！"; else
		if (damage < 400) str = "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！"; else
		if (damage < 800) str = "结果「啪」地一声爆响！这一下好厉害，只抽得$n皮开肉绽，血花飞溅！"; else
				  str = "结果只听见$n一声惨嚎，$w重重地抽上了$p的$l，$n顿时血肉横飞！";
		  return str +"\n";
		break;
	case "反震伤":
		if (damage < 15)  str = "结果$N受到$n的内力反震，闷哼一声。"; else
		if (damage < 40)  str = "结果$N被$n的反震得气血翻腾，大惊失色。"; else
		if (damage < 100) str = "结果$N被$n的反震得站立不稳，摇摇晃晃。"; else
		if (damage < 200) str = "结果$N被$n以内力反震，「嘿」地一声退了一步。"; else
		if (damage < 300) str = "结果$N被$n的震得反弹回来的力量震得半身发麻。"; else
		if (damage < 400) str = "结果$N被$n的内力反震，胸口有如受到一记重击，差点透不过气！"; else
		if (damage < 600) str = "结果$N被$n内力反震，眼前一黑，差点晕过去！！"; else
				  str = "结果$N被$n内力反震，狂吐鲜血，身子象断了线的风筝向後飞去！！";
		   return str +"\n";
		break;
	case "砸伤":
		if (damage < 10)  str = "结果只是轻轻地碰到，像是给$n搔了一下痒。"; else
		if (damage < 40)  str = "结果在$n的$l砸出一个小臌包。"; else
		if (damage < 100) str = "结果$N这一下砸个正着，$n的$l登时肿了一块老高！"; else
		if (damage < 150) str = "结果$N这一下砸个正着，$n闷哼一声显然吃了不小的亏！"; else
		if (damage < 200) str = "结果只听「砰」地一声，$n疼得连腰都弯了下来！"; else
		if (damage < 400) str = "结果这一下「轰」地一声砸得$n眼冒金星，差一点摔倒！"; else
		if (damage < 800) str = "结果重重地砸中，$n眼前一黑，「哇」地一声吐出一口鲜血！"; else
				  str = "结果只听见「轰」地一声巨响，$n被砸得血肉模糊，惨不忍睹！";
		   return str +"\n";
		break;
	default:
		if (! type) type = "伤害";
		if (damage < 50)  str = "结果只是勉强造成一处轻微"; else
		if (damage < 100)  str = "结果造成轻微的"; else
		if (damage < 200) str = "结果造成一处"; else
		if (damage < 300) str = "造成一处严重"; else
		if (damage < 500) str = "结果造成颇为严重的"; else
		if (damage < 700) str = "结果造成相当严重的"; else
		if (damage < 900) str = "结果造成十分严重的"; else
		if (damage < 1000) str = "结果造成极其严重的"; else
				  str = "结果造成非常可怕的严重";
		return  str+ type  +"！\n";
	}
}

string eff_status_msg(int ratio)
{
	if (ratio==100) return HIG "看起来气血充盈，并没有受伤。" NOR;
	if (ratio > 90) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
	if (ratio > 80) return HIY "看起来可能受了点轻伤。" NOR;
	if (ratio > 70) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
	if (ratio > 60) return HIY "受伤不轻，看起来状况并不太好。" NOR;
	if (ratio > 50) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
	if (ratio > 40) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
	if (ratio > 30) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
	if (ratio > 20) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
	if (ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	if (ratio > 5 )return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
	return RED "受伤过重，已经奄奄一息，命在旦夕了" NOR;
}

int valid_power(int combat_exp)
{
	if (combat_exp < 2000000)
		return combat_exp / 1000;

	combat_exp -= 2000000;
	if (combat_exp < 1000000)
		return 2000 + combat_exp / 10000;

	combat_exp -= 1000000;
	return 2000 + (1000 / 10) + (combat_exp / 2000);
}

varargs int skill_power(object ob, string skill, int usage, int delta)
{
	int status, level, power;
	mapping dbase;
	mapping temp;
	mapping fight;
	mapping apply;

	if (! living(ob)) return 0;

	level = ob->query_skill(skill);

	dbase = ob->query_entire_dbase();
	temp = ob->query_entire_temp_dbase();
	if (temp)
	{
		apply = temp["apply"];
		fight = temp["fight"];
	}

	switch (usage)
	{
		case SKILL_USAGE_ATTACK:
			if (apply) level += apply["attack"];
			break;
		case SKILL_USAGE_DEFENSE:
			if (apply) level += apply["defense"];
			break;
	}

	level += delta;
	if (level < 1)
	{
		power = valid_power((int)ob->query("combat_exp")) / 2;
		if (usage == SKILL_USAGE_ATTACK)
			power = power / 30 * dbase["str"];
		else
			power = power / 30 * dbase["dex"];

	 	return  power;
	}

	if (level > 500)
		power = level * level / 10000 * level;
	else
		power = level * level * level / 10000;

	power += valid_power(dbase["combat_exp"]);

	if (usage == SKILL_USAGE_ATTACK)
	{
		power = power / 30 * (dbase["str"] + (temp ? temp["str"] : 0));
		if (fight && ob->is_fighting())
			 power += power / 100 * fight["attack"];
	} else
	{
		power = power / 30 * (dbase["dex"] + (temp ? temp["dex"] : 0));
		if (fight && ob->is_fighting())
			 power += power / 100 * fight[skill];
	}
	return power;
}

varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your;
	mapping my_temp, your_temp;
	mapping prepare, action;
	string limb, *limbs;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	string parry_msg;
	mixed foo;

	int crit,delta;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int wounded;
	int has_weapon;
	int baoji;

	object weapon2;	// weapon of victim
	object cloth;   // armor of victim

	string skill_name,result;
	string damage_msg,damage_info;
	mapping fight;

	object env_me;
	object env_v;

	if (environment(me)->query("no_fight")&&!me->query_condition("killer")&&!victim->query_condition("killer"))
	{
		message_vision("$N和$n各自退了一步，收住了招。\n",me, victim);
		me->remove_enemy(victim);
		victim->remove_enemy(me);
		return 0;
	}

	if (environment(me) != environment(victim))
	{
		me->remove_enemy(victim);
		victim->remove_enemy(me);
		return 0;
	}

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();

	if (! (my_temp = me->query_entire_temp_dbase()))
		my_temp = allocate_mapping(5);

	if (! (your_temp = victim->query_entire_temp_dbase()))
		your_temp = allocate_mapping(5);

	//
	// (0) Choose skills.
	//
	prepare = me->query_skill_prepare();
	if (! prepare) prepare = ([]);

	if (objectp(weapon))
		attack_skill = weapon->query("skill_type");
	else
	{
		switch (sizeof(prepare))
		{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
		}
	}

	if (attack_skill == "pin")
		attack_skill = "sword";

	// (1) Find out what action the offenser will take.
	//
	me->reset_action();
	action = me->query_action();

	has_weapon = weapon || me->query_temp("armor/hands");

	if (! action)
	{
		// reconfirm
		me->reset_action();
		action = me->query_action();
		if (! mapp(action))
		{
			CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s(%s): bad action = %O",me->query("name"), me->query("id"),me->query_action(1)));
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n紧跟着" + action["action"] + "！\n"; 

	if(!stringp(skill_name = action["skill_name"]))
		if(!stringp(skill_name = me->query_skill_mapped(attack_skill)))
			skill_name = attack_skill;
	me->set_temp("attack_skill_name",to_chinese(skill_name));

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	if (! arrayp(limbs))
	{
		limbs = ({ "身体" });
		victim->set("limbs", limbs);
	}
	limb = limbs[random(sizeof(limbs))];

	if (! my["not_living"])
	{
		fight = allocate_mapping(5);
		fight["attack"] = action["attack"];
		fight["dodge"]  = action["dodge"];
		fight["parry"]  = action["parry"];
		my_temp["fight"] = fight;
	}
	//计算攻击者技能 攻击力
	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK, 0);
	if (ap < 1) ap = 1;

	if (my["character"] == "阴险奸诈")
		//阴险性格AP加乘120%
		ap += ap * 20 / 100;     
	//计算被 攻击者 的 轻功 躲闪值
	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE, 0);
	if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
	{
		//如果装备特殊轻功，则计算特殊轻功的加乘率
		dp += dp / 200 * SKILL_D(dodge_skill)->query_effect_dodge(me, victim);
	}
	if (dp < 1) dp = 1;
	//如果被攻击者处于繁忙状态，躲闪值降低3倍 
	if (victim->is_busy()) dp /= 3;

	//
	// (3) Fight!

	damage = 0;   //破坏
	wounded = 0;   //创伤
	damage_info = "";  //破坏信息
	
	//如果随机（攻击值+被攻击者的躲闪值）小于躲闪值，认为躲闪成功
	if (random(ap + dp) < dp && victim->query("qi")!=0)
	{  // Does the victim dodge this hit?

#if INSTALL_COMBAT_TEST
		if (wizardp(me) && me->query("env/combat_test"))
			tell_object(me, HIY "【测试精灵】：己方 AP：" + ap +"，DP：" + dp + "。"NOR"\n");
		if (wizardp(victim) && victim->query("env/combat_test"))
			tell_object(victim, HIC "【测试精灵】：对方 AP：" + ap + "，DP：" + dp + "。"NOR"\n");
#endif

		//如果没有装备特殊轻功，就给与基本轻功
		if (! dodge_skill) dodge_skill = "dodge";
		//取出轻功的躲闪信息。
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
		damage = -1;
		//判断是否增加轻功的熟练度
		//如果躲闪值小于攻击值，而且还躲过了攻击
		if (userp(me) || userp(victim))  
		{
			if (random(dp+ap) < dp && random(my["int"]) > 14)
			{
				//如果随即被攻击者的经验不大于极限经验，并且随机到真就加奖励
				if (your["combat_exp"] < EXP_LIMIT && victim->query("combat_exp")<me->query("combat_exp"))
				{
					tell_object(victim,"你在"HIC"躲避"NOR+me->query("name")+"时对"HIG"【"+to_chinese(dodge_skill)+"】"NOR"顿有所悟: "YEL"武功熟练度 "HIY"↑"NOR","YEL"实战经验 "HIY"↑" NOR"\n");				
					your["combat_exp"]++;
					victim->improve_skill(dodge_skill, 1);
			       
				}
			}
		}
	} 
	else  //如果躲闪不成功，就判断是否增加攻击的奖励
	{
		//
		//      (4) Check if the victim can parry this attack.
		// 都是可以互动的
		if (userp(me) || userp(victim))     
		{
			//计算是否给予攻击奖励。
			//如果攻击小于躲闪 并且 随机悟性大于14 ，并且潜能是否超出
			if (random(ap + dp) < dp && random(my["int"]) > 12 )
			{
				if( me->query("combat_exp") < victim->query("combat_exp"))
				{
					if(me->query("potential") < me->query_potential_limit())
					{
						tell_object(me,"你在"HIR"攻击"NOR+victim->query("name")+"时对"HIG"【"+to_chinese(attack_skill)+"】"NOR"顿有所悟:"YEL" 武功熟练度 "HIY"↑"NOR","YEL"经验点 "HIY"↑" NOR"\n");
						my["potential"]++;
						your_temp["give_potential"] += my["mud_age"] / 86400;
						me->improve_skill(attack_skill, 1);     
					}
				}
			}
		}
		delta = 0;
		//取出装备主手的兵器对象
		if (weapon2 = your_temp["weapon"])
		{
			if (! weapon) delta = 10;  //如果没有兵器，delta=10
		} 
		else
		{
			if (weapon) delta = -10;   //有装备兵器，delta=-10
		}
		//计算被攻击者 招架技能 的值
		pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE, delta);
		//如果被攻击者 繁忙，招架值减少3倍
		if (victim->is_busy()) pp /= 3;
		if (pp < 1) pp = 1;
		//计算特殊招架技能给予的招架值加乘。
		if (stringp(parry_skill = victim->query_skill_mapped("parry")))
			pp += pp / 200 * SKILL_D(parry_skill)->query_effect_parry(me, victim);
		//如果随机（攻击值+招架值）小于招架值 则判断 招架成功，除非气血为0
		if (random(ap + pp) < pp && victim->query("qi")!=0)
		{
		       
#if INSTALL_COMBAT_TEST
			if (wizardp(me) && me->query("env/combat_test"))
				tell_object(me, HIY "【测试精灵】：己方 AP：" + ap + "，PP：" + pp + "。"NOR"\n");
			if (wizardp(victim) && victim->query("env/combat_test"))
				tell_object(victim, HIC "【测试精灵】：对方 AP：" + ap + "，PP：" + pp + "。"NOR"\n");
#endif
			//如果没有特殊招架，则给予 [基本招架]
			if (! parry_skill) parry_skill = "parry";
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.
			//取出有带兵器的[特殊招架]信息
			parry_msg = SKILL_D(parry_skill)->query_parry_msg(weapon2);
			//如果没有[特殊招架]兵器的招架信息
			if (! stringp(parry_msg))
				//就取出[基本招架]兵器信息
				parry_msg = SKILL_D("parry")->query_parry_msg(weapon2);
			//如果有招架信息，则赋予result+招架信息
			if (stringp(parry_msg))
				result += parry_msg + "\n";
			damage = -2;
			//判断是否给予招架奖励
			//如果招架值小于攻击，而招架成功，并且计算 xx>30
		      if (userp(me) || userp(victim))  
		      {
				if (random(ap + pp) < pp && random(my["int"]) > 14)
				{
					//如上，通过就给予招架奖励
					if (your["combat_exp"] < EXP_LIMIT && victim->query("combat_exp")<me->query("combat_exp"))
					{
						tell_object(victim,"你在"HIM"招架"NOR+me->query("name")+"时对"HIG"【"+to_chinese(parry_skill)+"】"NOR"顿有所悟:"YEL" 武功熟练度 "HIY"↑"NOR","YEL"经验点 "HIY"↑" NOR"\n");					
						your["combat_exp"]++;		   
						victim->improve_skill(parry_skill, 1);
					}
					else
					{
					     tell_object(victim,WHT+"【你的对手太弱了，无法取得任何经验！！！】"NOR"\n");
					}
				}
		      }
		} 
		else
		{
			//
			// (5) We hit the victim and the victim failed to parry
			//
			//如果有兵器，则取出兵器的攻击力，否则取出空手攻击力
			if (weapon)
				damage = me->query_temp("apply/damage");
			else
				damage = me->query_temp("apply/unarmed_damage");
							
			//将攻击力变成在一定的随机范围波动。
			damage = (damage + random(damage)) / 2;
			if (action["damage"])
				damage += action["damage"] * damage / 100;
			//攻击者力量取出
			damage_bonus = me->query_str();
			//判断是否是 愤怒状态
			if (my["jianu"])
			{
				// does angry bnous
				damage_bonus += me->cost_craze(my["jianu"]);
				//是否为狂化状态，计算狂化状态信息
				if (me->query_craze() > 1000 && random(my["jianu"] + 200) > 200)
				{
					damage_info += random(2) ? HIR "$N" HIR "大喝一声，双目圆睁，一股凌厉的杀气油然而起！"NOR"\n"
								 : HIR "$N" HIR "奋不顾身的扑上前来，招招紧逼$n" HIR "，毫不容情。"NOR"\n";
					//消耗怒气值
					me->cost_craze(200 + random(300));
					damage_bonus += my["jianu"] * 2;
				}
			}

			// Clear the special message info after damage info
			foo_before_hit = 0;
			foo_after_hit = 0;

			// Let force skill take effect.
			if (my["jiali"] && (my["neili"] > my["jiali"]))
			{
				if (force_skill = me->query_skill_mapped("force"))
				{
					foo = SKILL_D(force_skill)->force_hit_ob(me, victim, damage_bonus, my["jiali"]);
					if (stringp(foo)) damage_info += foo; else
					if (intp(foo)) damage_bonus += foo; else
					if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage_bonus += foo["damage"];
					}
				}

#if INSTALL_COMBAT_TEST
				if (wizardp(me) && me->query("env/combat_test"))
					tell_object(me, HIY "【测试精灵】：己方 AP：" + ap + "，DP：" + dp + "，PP：" + pp +
						    "，伤害效果：" + damage + "，额外伤害效果：" + damage_bonus + "。"NOR"\n");
				if (wizardp(victim) && victim->query("env/combat_test"))
					tell_object(victim, HIC "【测试精灵】：对方 AP：" + ap + "，DP：" + dp + "，PP：" + pp +
						    "，伤害效果：" + damage + "，额外伤害效果：" + damage_bonus + "。"NOR"\n");
#endif
			}

			if (action["force"])
				damage_bonus += action["force"] * damage_bonus / 100;

			// calculate the damage
			if (damage_bonus > 0)
				damage += (damage_bonus + random(damage_bonus)) / 3;

			// Let's attack & parry skill, weapon & armor do effect
			while (damage > 0)
			{
				if (my["not_living"] || your["not_living"])
					// Only two living do this
					break;

				if (damage < 1) break;

				// Let parry skill take its special effort.
				if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
				{
					victim->set_temp("dodge_valid_damage", 1);
					foo = SKILL_D(dodge_skill)->valid_damage(me, victim, damage, weapon);
					victim->delete_temp("dodge_valid_damage");
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
					if (damage < 1) break;
				}

				if (stringp(parry_skill = victim->query_skill_mapped("parry")))
				{
					foo = SKILL_D(parry_skill)->valid_damage(me, victim, damage, weapon);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
					if (damage < 1) break;
				}
				// 魔幻兽
				if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["beast"]))
				{
					foo = cloth->valid_damage(me, victim, damage, weapon);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				else if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["armor"]))
				{
					foo = cloth->valid_damage(me, victim, damage, weapon);
					if (stringp(foo)) damage_info += foo; else
					if (intp(foo)) damage += foo; else
					if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				else if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["cloth"]))
				{
					foo = cloth->valid_damage(me, victim, damage, weapon);
					if (stringp(foo)) damage_info += foo; else
					if (intp(foo)) damage += foo; else
					if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}

				if (damage < 1) break;

				if (martial_skill = me->query_skill_mapped(attack_skill))
				{
					foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
					if (damage < 1) break;
				}

				// Let weapon or living have their special damage.
				if (weapon)
				{
					foo = weapon->hit_ob(me, victim, damage);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				else
				{
					foo = me->hit_ob(me, victim, damage);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				break;
			}

			//
			//      (6) Inflict the damage.
			//
			//几率触发生成暴击
				if (weapon&&baoji = weapon->baoji())		
				{					
				    if (baoji >= random(100))
			      	{
			     	damage +=damage;
			     	tell_object(me,weapon->name()+HIR"暴击效果触发！\n"NOR);
				   }
				}
			if (damage > 0)
			{
				if (my["character"] == "心狠手辣")
					damage += damage * 20 / 100;

				wounded = damage;

				if (wounded > 400)
					wounded = (wounded - 400) / 4 + 300;
				else if (wounded > 200)
					wounded = (wounded - 200) / 2 + 200;
				else if (wounded < 1)
					wounded = 0;

				// recalculate damage
				if (damage > 400)
					damage = (damage - 400) / 4 + 300;
				else if (damage > 200)
					damage = (damage - 200) / 2 + 200;

				if (your["character"] == "光明磊落")
					wounded -= wounded * 20 / 100;

				damage = COMBAT_D->calc_damage(me, victim, damage);
//暴击修正
				if( (crit = me->query("gain/2ap") - victim->query("gain/2dp")) > 0 )
				{
					if( crit > random(150) )
					{
						damage *= 2;
						//wounded *= 2;
						result += RED"$N凝神贯注，对着$n发出会心一击！"NOR"\n";
					}
				}
				damage = victim->receive_damage("qi", damage, me);
				if (wounded > 0 && (has_weapon || random(3) == 1))
				{
					wounded = COMBAT_D->calc_wound(me, victim, wounded);
					victim->receive_wound("qi", wounded, me);
				}

#if INSTALL_COMBAT_TEST
				if (wizardp(me) && me->query("env/combat_test"))
					tell_object(me, HIY "【测试精灵】：你对" + victim->query("name") + "造成" + damage + "点伤害，" +  wounded + "点创伤。"NOR"\n");
				if (wizardp(victim) && victim->query("env/combat_test"))
					tell_object(victim, HIG "【测试精灵】：你受到" + me->query("name") + damage + "点伤害，" + wounded + "点创伤。"NOR"\n");
#endif

				// add message before hit in victim
				if (foo_before_hit)
					result += foo_before_hit;

				result += damage_msg(damage, action["damage_type"]);
				damage_info += "( $n" + eff_status_msg(victim->query("qi") * 100 / victim->query("max_qi")) + ")\n";
			}

			if (foo_after_hit)
				damage_info += foo_after_hit;
		}
	} 

	result = replace_string(result, "$l", limb);
	if (objectp(weapon))
		result = replace_string(result, "$w", weapon->name());
	else if (stringp(action["weapon"]))
		result = replace_string(result, "$w", action["weapon"]);
	else if (attack_skill == "finger" || attack_skill == "hand")
		result = replace_string(result, "$w", "手指" );
	else if (attack_skill == "strike" || attack_skill == "claw")
		result = replace_string(result, "$w", "手掌" );
	else
		result = replace_string(result, "$w", "拳头" );

	message_combatd(result, me, victim, damage_info,damage,action["damage_type"]);

	if (damage > 0)
	{
		if (victim->is_busy())
			victim->interrupt_me(victim, 2 + random(2));
		if ((!me->query_temp("fight_team")) && (! me->is_killing(your["id"])) && (! victim->is_killing(my["id"])) 
			&& ! victim->query("not_living") && your["qi"] * 3 <= your["max_qi"])
		{
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			if (me->query("can_speak") && victim->query("can_speak"))
				message_vision(winner_msg[random(sizeof(winner_msg))],me, victim);
			if (me == victim->query_competitor())
			{
				me->win();
				victim->lost();
			}
		}
	}

	if (functionp(action["post_action"]))
		evaluate(action["post_action"], me, victim, weapon, damage);

	if (attack_type == TYPE_REGULAR && damage < 1 && your_temp["guarding"])
	{
		if (random(my["dex"]) < 8)
		{
			message_vision("$N一击不中，露出了破绽！\n",me,victim);
			do_attack(victim, me, your_temp["weapon"],TYPE_QUICK);
		} else
		{
			message_vision("$n见$N攻击失误，趁机发动攻击！\n",me,victim);
			do_attack(victim, me, your_temp["weapon"],TYPE_RIPOSTE);
		}
	}
}

varargs string do_damage(object me, object target, mixed type, int damage, int percent, mixed final)
{
	mapping my;
	object weapon;
	object cloth;
	int apply;
	int armor;
	int wound;
	int jiali;
	int bonus;
	mixed foo;
	string msg;
	string skill;
	string *limbs;
	string limb;
	string damage_type;
	string result;
	int str;
	int damage_bonus;

	// Am I use weapon
	if (type == WEAPON_ATTACK)
	{
		apply  = me->query_temp("apply/damage");
		weapon = me->query_temp("weapon");
	}
	else if (type == UNARMED_ATTACK)
	{
		apply  = me->query_temp("apply/unarmed_damage");
		weapon = 0;
	}
	else
	{
		apply  = 0;
		weapon = 0;
	}

	// Check the target's armor
	armor = target->query_temp("apply/armor");

	damage += apply;
	msg = "";
	foo_after_hit = 0;

	while (type == UNARMED_ATTACK || type == WEAPON_ATTACK)
	{
		if (random(100) < 40)
			break;
		// Let parry skill take its special effort
		if (skill = target->query_skill_mapped("parry"))
		{
			foo = SKILL_D(skill)->valid_damage(me, target, damage, weapon);
			if (stringp(foo))
				msg += foo;
			else if (intp(foo))
				damage += foo;
			else if (mapp(foo))
			{
				msg += foo["msg"];
				damage += foo["damage"];
			}
		}
		if (damage < 1) break;

		// Let dodge skill take its special effort
		if (skill = target->query_skill_mapped("dodge"))
		{
			target->set_temp("dodge_valid_damage", 1);
			foo = SKILL_D(skill)->valid_damage(me, target, damage, weapon);
			target->delete_temp("dodge_valid_damage", 1);
			if (stringp(foo))
				msg += foo;
			else if (intp(foo))
				damage += foo;
			else if (mapp(foo))
			{
				msg += foo["msg"];
				damage += foo["damage"];
			}
		}

		if (damage < 1) break;
		  //魔幻兽
		if (cloth = target->query_temp("armor/beast"))
		{
			foo = cloth->valid_damage(me, target, damage, weapon);
			if (stringp(foo))
				msg += foo;
			else if (intp(foo))
				damage += foo;
			else if (mapp(foo))
			{
				msg += foo["msg"];
				damage += foo["damage"];
			}
		} else 
		// Let cloth & armor take its special effort
		if (cloth = target->query_temp("armor/armor"))
		{
			foo = cloth->valid_damage(me, target, damage, weapon);
			if (stringp(foo))
				msg += foo;
			else if (intp(foo))
				damage += foo;
			else if (mapp(foo))
			{
				msg += foo["msg"];
				damage += foo["damage"];
			}
		}
		else if (cloth = target->query_temp("armor/cloth"))
		{
			foo = cloth->valid_damage(me, target, damage, weapon);
			if (stringp(foo))
				msg += foo;
			else if (intp(foo))
				damage += foo;
			else if (mapp(foo))
			{
				msg += foo["msg"];
				damage += foo["damage"];
			}
		}
		break;
	}

	while (damage > 0)
	{
		if (target->is_busy()) target->interrupt_me(target, 4 + random(4));

		if (type == WEAPON_ATTACK)
			foo = weapon->hit_ob(me, target, damage);
		else if (type == UNARMED_ATTACK)
			foo = me->hit_ob(me, target, damage);
		else if (objectp(type))
			foo = type->hit_ob(me, target, damage);

		if (stringp(foo))	msg += foo;
		else if (intp(foo)) damage += foo;
		else if (mapp(foo))
		{
			msg += foo["msg"];
			damage += foo["damage"];
		}

		my = me->query_entire_dbase();
		if ((jiali = my["jiali"]) > 0 && my["neili"] >= jiali)
		{
			my["neili"] -= jiali;
			if (type == REMOTE_ATTACK)
			{
				damage_bonus = jiali * damage / 200;
			}
			else
			{
				damage_bonus = jiali * damage / 300;
				skill = target->query_skill_mapped("force");
				if (stringp(skill))
				{
					foo = SKILL_D(skill)->valid_damage(me, target, damage_bonus);

					if (stringp(foo)) msg += foo;
					else if (intp(foo)) damage_bonus += foo;
					else if (mapp(foo))
					{
						msg += foo["msg"];
						damage_bonus += foo["damage"];
					}
				}
				damage += damage_bonus;
			}
		}

		str = me->query_str() + me->query_temp("str");

		if (str < 20) damage += damage * str / 50;
		else if (str < 40) damage += damage * ((str - 20) / 2 + 20) / 50;
		else damage += damage * ((str - 40) / 4 + 30) / 50;

		if (damage < 1) break;

		if (damage > 1500)	damage = (damage - 1500) / 4 + 1000;
		else if (damage > 500)	damage = (damage - 500) / 2 + 500;

		damage = COMBAT_D->calc_damage(me, target, damage);
		target->receive_damage("qi", damage, me);
		wound = (damage - random(armor)) * percent / 100;

		if (target->query("character") == "光明磊落")
			wound -= wound * 20 / 100;

		if (wound > 0)
		{
			wound = COMBAT_D->calc_wound(me, target, wound);
			target->receive_wound("qi", wound, me);
		}
        
		if (functionp(final)) final = evaluate(final);

		if (stringp(final))
		{
			if (sscanf(final, "%s@%s", final, limb) == 2)
			{
				if (sscanf(final, "%s:%s", result, damage_type) != 2)
				{
					result = HIR "这招打了个正中！";
					damage_type = final;
				}
				if (sscanf(limb, "?%*s"))
				{
					// auto select limb
					limbs = target->query("limbs");
					if (! arrayp(limbs))
					{
						limbs = ({ "身体" });
						target->set("limbs", limbs);
					}
					limb = limbs[random(sizeof(limbs))];
				}

				// indicate damage type & limb
				final = replace_string(damage_msg(damage, damage_type), "$l", limb);
				final = replace_string(final, "$n", "$n" HIR);
				final = replace_string(final, "$N", "$N" HIR);
				final = replace_string(final, "$p", "$p" HIR);
				final = replace_string(final, "$P", "$P" HIR);
				if (weapon)
					final = replace_string(final, "$w", weapon->name() + HIR);
				final = result + HIR + final + NOR;
			}

			msg += final;
        	msg += HIG "(造成伤害" NOR + HIR + damage + NOR + HIG "/" NOR + HIR + wound + NOR + HIG ")\n"NOR;
			msg += "( $n" + eff_status_msg(target->query("qi") * 100 / target->query("max_qi")) + ")\n";
		}

		break;
	}
	
	if (damage < 0)
	{
	    msg += "$N的攻击打在$n身上没有丝毫作用。\n";
	}

	if (foo_after_hit) msg += foo_after_hit;
	if (foo_before_hit) msg = foo_before_hit + msg;

	// Clear the special message info after damage info
	foo_before_hit = 0;
	foo_after_hit = 0;
	return msg;
}

varargs string do_respond(object me, object target, int damage, int percent, mixed final)
{
	int armor;
	int wound;
	string msg;
	string skill;
	string damage_type;
	string result;
	int str;

	// Check the target's armor
	armor = target->query_temp("apply/armor");

	msg = "";

	while (damage > 0)
	{
		if (target->is_busy()) target->interrupt_me(target, 4 + random(4));

		str = me->query_str() + me->query_temp("str");

		if (str < 20) damage += damage * str / 50;
		else if (str < 40) damage += damage * ((str - 20) / 2 + 20) / 50;
		else damage += damage * ((str - 40) / 4 + 30) / 50;

		if (damage < 1) break;

		if (damage > 1500)	damage = (damage - 1500) / 4 + 1000;
		else if (damage > 500)	damage = (damage - 500) / 2 + 500;

		damage = COMBAT_D->calc_damage(me, target, damage);
		target->receive_damage("qi", damage, me);
		wound = (damage - random(armor)) * percent / 100;

		if (target->query("character") == "光明磊落")
			wound -= wound * 20 / 100;

		if (wound > 0)
		{
			wound = COMBAT_D->calc_wound(me, target, wound);
			target->receive_wound("qi", wound, me);
		}

		if (stringp(final))
		{
			msg += final;
			msg += "( $N" + eff_status_msg(target->query("qi") * 100 / target->query("max_qi")) + ")\n";
		}

		break;
	}

	return msg;
}

//      fight()
//
void fight(object me, object victim)
{
	object ob;
	object weapon;
	string askill;
	int    double_attack;
	mapping prepare;
	string result;
	mapping my_temp;

	if (! living(me)) return;

	if (! mapp(my_temp = me->query_entire_temp_dbase()))
		my_temp = ([ ]);

	prepare = me->query_skill_prepare();
	if (weapon = my_temp["weapon"])
		askill = weapon->query("skill_type");
	else if (! prepare || sizeof(prepare) == 0) askill = "unarmed";
	else if (sizeof(prepare)) askill = (keys(prepare))[0];
	if (askill == "pin") askill = "sword";

	askill = me->query_skill_mapped(askill);
	if (askill && random(me->query_dex()) >= 8)
		double_attack = (sizeof(prepare) >= 2 && ! weapon) ||	SKILL_D(askill)->double_attack();

	// If victim is busy or unconcious, always take the chance to make an attack.
	if (victim->is_busy() || ! living(victim))
	{
		me->set_temp("guarding", 0);
		if (! victim->is_fighting(me)) victim->fight_ob(me);
		do_attack(me, victim, my_temp["weapon"], TYPE_QUICK);

		if (me->is_fighting(victim) && victim->is_fighting(me) && double_attack)
		{
			me->set_temp("action_flag",1);
			do_attack(me, victim, my_temp["weapon"], TYPE_QUICK);
			me->set_temp("action_flag",0);
		}

	// Else, see if we are brave enough to make an aggressive action.
	} else
	if (me->query_str() > random(victim->query_str() * 3 / 4))
	{
		me->set_temp("guarding", 0);
		if (! victim->is_fighting(me))
			victim->fight_ob(me);
		do_attack(me, victim, my_temp["weapon"], TYPE_REGULAR);

		if (me->is_fighting(victim) && victim->is_fighting(me) && double_attack)
		{
			me->set_temp("action_flag",1);
			do_attack(me, victim, my_temp["weapon"], TYPE_REGULAR);
			me->set_temp("action_flag",0);
		}

	// Else, we just start guarding.
	} else
	if (! me->query_temp("guarding"))
	{
		me->set_temp("guarding", 1);
		message_combatd( guard_msg[random(sizeof(guard_msg))], me, victim, "",0,"");
		return;
	} else return;
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if (! userp(me) && ! userp(obj)) return;

	if (me->query_temp("owner") == obj ||
	    obj->quety_temp("owner") == me)
		return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if (me->query_temp("looking_for_trouble")) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out("start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int shen;

	// Are we still exist( not becoming a corpse )?
	if (! me || ! obj || ! living(me)) return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) ||
	    environment(me) != environment(obj) ||
	    (environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	shen = 0 - (int)me->query("shen");
	message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);

	if (! userp(me) || (int)me->query("neili") > (random(shen) + shen)/10 )
		return;

	if (shen > (int)me->query("score") && ! wizardp(obj))
	{
		message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me) + "看你实在很不顺眼，去死吧。\n", me, obj);
		me->kill_ob(obj);
		if (living(obj) && ! userp(obj))
			obj->kill_ob(me);
		else
			obj->fight_ob(me);
	} else
	{
		message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj) + "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n", me, obj);
		me->fight_ob(obj);
		obj->fight_ob(me);
	}
}

void start_hatred(object me, object obj)
{
	if (! me || ! obj || ! living(me))
		return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) || environment(me) != environment(obj) || 
		(environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	if (me->query_temp("owner") == obj->query("id") ||
	    obj->query_temp("owner") == me->query("id"))
		return;

	// We found our hatred! Charge!
	if (me->query("can_speak"))
		message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);

	me->want_kill(obj);
	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);

	if (! playerp(me) && me->is_busy() && ! intp(me->query_busy()))
		me->interrupt_me(me);
}

void start_vendetta(object me, object obj)
{
	if (! me || ! obj || ! living(me))
		return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) ||
	    environment(me) != environment(obj) ||
	    (environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	// We found our vendetta opponent! Charge!
	me->want_kill(obj);
	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);
}

void start_aggressive(object me, object obj)
{
	if (! me || ! obj || ! living(me)) return;

	me->set_temp("looking_for_trouble", 0);

	if (me->is_fighting(obj) ||
	    environment(me) != environment(obj) ||
	    (environment(me)->query("no_fight") && !obj->query_condition("killer")))
		return;

	// We got a nice victim! Kill him/her/it!!!
	me->want_kill(obj);
	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);
}

int player_escape(object killer, object ob)
{
	object iob;
	string msg;

	if (! objectp(ob))
		return 0;

	// 是玩家么？
	if (! playerp(ob))
		return 0;

	if ((int)ob->query("combat/which_day") == time() / 86400 &&
	    (int)ob->query("total_count") > 0)
		return 0;

	// 真的晕倒了，察看是否是被别人有意打晕的
	if (! killer) killer = ob->query_defeated_by();
	if (! killer || ! playerp(killer) ||
	    ! killer->is_want_kill(ob->query("id")))
		return 0;

	if (ob->query("combat_exp") >= 150000)
		return 0;

	switch (random(7))
	{
	case 0:
		msg = "突然只听幽幽一声长叹，一掌轻轻按来。$N大吃一惊，不及"
		      "多加思索，只是抬手一格。匆忙之间只怕对手过于厉害，难"
		      "以招架，急忙向后跃开。却见来人并不追击，只是一伸手拎"
		      "起$n，转身飘然而去，仙踪渺然。\n";
		break;

	case 1:
		msg = "$N将$n打翻在地，“哈哈”一声笑声尚未落下，只听有人冷"
		      "哼一声，忽然间掌风袭体，$N顿感呼吸不畅，几欲窒息，慌"
		      "忙中急忙退后，待得立稳脚跟，却见$n早已无影无踪。\n";
		break;

	case 2:
		msg = "一人忽然掠至，喝道：“岂有此理？我龙岛主最恨此欺善怕"
		      "恶之辈，休走！”说罢一掌击来，$N奋力招架，一招之下几"
		      "欲吐血！只见来人轻轻提起$n，冷笑两声，转身离去，$N惊"
		      "骇之下，竟然说不出一句话来。\n";
		break;

	case 3:
		msg = "突然一人喝道：“且慢！”只见一道黑影掠到，飞起一脚将"
		      "$N踢了个跟头，左手拎起$n，冷冷对$N道：“今日所幸尚未"
		      "伤人命，你作恶不甚，饶你去吧！”$N捂胸运气，不住喘息"
		      "，眼睁睁的看着来人去了。\n";
		break;

	case 4:
		msg = "$N跨前一步，忽然看到面前已多了两人，一胖一瘦，一喜一"
		      "怒，不由暗生疑窦。一人手中亮出一面铜牌，笑道：“这位" +
		      RANK_D->quert_respect(killer)+ "，这面罚恶铜牌你收下可"
		      "好？”$N听了大吃一惊，手只是一软，哪里还敢搭半句话？"
		      "那瘦子冷冷看了过来，目光如电，$N讪讪笑了两声，目送两"
		      "人带了$n逍遥而去。\n";

	case 5:
		msg = "恰在此时，正逢一老者路过，只见他微一颦眉，喝道：“兀"
		      "那" + RANK_D->query_rude(killer)+ "，伤人做甚？”$N大"
		      "怒道：“你是何人，如此嚣张？”老者大怒，一掌拍落，$N"
		      "向上只是一格，“噗噜”一下双腿陷入土中，足有半尺。老"
		      "者森然道：“我乃侠客岛木岛主是也，如有不服，恭候大驾"
		      "！”此时$N内息如狂，连句场面话也说不出来，只能眼看$n"
		      "被那木岛主带了离去。\n";
		break;

	default:
		msg = "忽听“哈哈”一阵长笑，一人道：“龙兄，想不到我们三十"
		      "年不履中土，这些武林高手却是越来越不长进了！”另一人"
		      "道：“正是，看来赏善罚恶，漫漫无期，终无尽头。”$N听"
		      "得大汗涔涔而下，环顾四方却无一人，转回头来，更是大吃"
		      "一惊！连$n也不见了。\n";
		break;
	}

	if ((environment(killer) == environment(ob)) &&
	    killer->is_fighting(ob))
	{
		msg = replace_string(msg, "$n", ob->name());
		message_sort(msg, killer);
	} else
	{
		msg = "正逢一老者路过，见了" + ob->name() + "晕倒在地，叹口"
		      "气，将他扶起带走了。\n";
		message("vision", msg, environment(ob));
	}


	// 将身上带的东西放下
	foreach (iob in all_inventory(ob))
//		if (! iob->query("money_id") && ! iob->query("owner_id") && ! iob->query("equipped"))
                if ( iob->query("id")=="shaolin wuji")
			iob->move(environment(ob));


	// 初始化玩家的状态
	ob->clear_condition();
	ob->remove_killer(killer);
	killer->remove_killer(ob);

	// 通缉伤人凶手
	if (! killer->query_condition("killer"))
	{
		msg = "听说官府发下海捕文书，缉拿伤人凶手" + killer->name(1) + "。";
		killer->apply_condition("killer", 900);
	} else
	{
		msg = "听说官府加紧捉拿累次伤人的暴徒" + killer->name(1) + "。";
		killer->apply_condition("killer", 900 + (int)killer->query_condition("killer"));
	}
	CHANNEL_D->do_channel(this_object(), "rumor", msg);

	ob->move("/d/xiakedao/shiroom24");
	ob->set("startroom", "/d/xiakedao/shiroom24");
	ob->revive();
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("qi", 0);
	ob->set("jing", 0);

	if (intp(ob->query_busy()))
		ob->start_busy(30);

	tell_object(ob, "你睁开眼来，看到两位老者正在静坐修炼。\n"
		    HIG "龙岛主告诉你：" + RANK_D->query_respect(ob) +
			"，你要想离岛不妨和我说一声(ask long about 离岛)。"NOR"\n");

	return 1;
}

void announce(object ob, string event)
{
  //  object me=this_player();
    
	switch (event)
	{
	case "kuilei":
		message_vision(NOR"$N使用替身傀儡化作一道白光消失了！\n", ob);
		
		break;

	case "dead":
//	tell_object(find_player("name"),"执行结果："+me->name()+"\n");
		message_vision(NOR"$N吐了几口" HIR "鲜血" NOR "，在地上抽动了几下就死了！\n", ob);	
		break;

	case "unconcious":
		message_vision("\n"NOR"\n$N脚下一个不稳，倒在地上昏了过去。\n", ob);
		player_escape(0,ob);
		break;

	case "revive":
		message_vision("$N慢慢睁开眼睛，清醒了过来。\n", ob);
		break;
	}
}

// called when winner hit the victim to unconcious
void winner_reward(object winner, object victim)
{
	object owner;
	int temp;
	int td;
	mapping today;

	owner = winner->query_temp("owner");
	if (objectp(owner))
		winner = owner;

	winner->defeated_enemy(victim);

	if (! playerp(winner) || wizardp(victim) && 0)
		return;

	if (! winner->is_want_kill(victim->query("id")))
		// only if I want kill ob, I will record it.
		return;

	winner->add("combat/DPS", 1);
	if (victim->is_not_bad())  winner->add("combat/DPS_NOTBAD", 1);
	if (victim->is_not_good()) winner->add("combat/DPS_NOTGOOD", 1);
	if (victim->is_bad())      winner->add("combat/DPS_BAD", 1);
	if (victim->is_good())     winner->add("combat/DPS_GOOD", 1);

	if (victim->query_condition("killer"))
		return;

	if (victim->query("combat_exp") < 150)
		return;

	//log_files("static/killrecord",
	//	 sprintf("%s %s defeat %s\n",
	//		 log_time(), log_id(winner), log_id(victim)));

	td = time() / 86400;
	today = winner->query("combat/today");
	if (! mapp(today) || today["which_day"] != td)
	{
		today = ([ "which_day" : td,
			   "total_count" : 1,
			   victim->query("id") : 1, ]);
	} else
	{
		// count how many times that winner hit the victim to unconcious
		temp = ++today[victim->query("id")];
		if (temp == query("pk_perman"))
		{
			// reach limit
			tell_object(winner, BLINK HIR "\n今天你已经打晕" +
				    victim->name() + chinese_number(temp) +
				    "次了，手下留"
				    "情吧，否则麻烦可要找上门了。"NOR"\n");
		} else
		if (temp > query("pk_perman"))
			// too many times
			winner->set("combat/need_punish", "这厮逼人太甚，真是岂有此理！");

		// count how many users that winner hit to unconcious
		temp = ++today["total_count"];
		if (temp == query("pk_perday"))
		{
			// reach limit
			tell_object(winner, BLINK HIR "\n今天你已经打晕" +
				    chinese_number(temp) + "次玩家了，手下留"
				    "情吧，否则麻烦可要找上门了。"NOR"\n");
		} else
		if (temp > query("pk_perday"))
			// too many users
			winner->set("combat/need_punish", "丧尽天良，大肆屠戮，罪无可恕！");
	}
	winner->set("combat/today", today);
}

void finish_xuanshang(object xuanshang_order, object killer, object victim)
{
	xuanshang_order->finish_xuanshang(killer, victim);
}

void killer_reward(object killer, object victim)
{
	object owner;
	string vmark;
	object box,*inv;
	string msg = "莫名其妙地死了";
	string follow_msg = 0;
	object weapon;
	mapping actions;
	int i,shen_delta;
	mapping ks, vs, kcombat;
	int win_exp;
	int flag, no_loss = 0;
	object xuanshang_order;
string npcn;	
string *npcns=({
"出尘子",
"慕容龙城",
"澄信",
"澄心",
"洪七公",
"道果禅师",
"段正淳",
"岳夫人",
"澄灵",
"梅剑",
"李莫愁",
"摘星子",
"杨过",
"曲灵风",
"道成禅师",
"慧真尊者",
"金轮法王",
"慕容博",
"黄药师",
"苏星河",
"孙不二",
"虚通",
"道静师太",
"道相禅师",
"欧阳克",
"胡逸之",
"静玄师太",
"清虚道长",
"达摩老祖",
"王诚",
"澄和",
"澄志",
"韦一笑",
"嘉木活佛",
"陆乘风",
"清闻比丘",
"欧阳锋",
"慕容复",
"矮老者",
"无根道长",
"陈玄风",
"周芷若",
"程灵素",
"慧合尊者",
"薛慕华",
"赵志敬",
"道品禅师",
"玄慈大师",
"无名老僧",
"陆高轩",
"丁春秋",
"康广陵",
"平四",
"崔志方",
"天狼子",
"澄知",
"澄观",
"道象禅师",
"玄痛大师",
"莫声谷",
"玄悲大师",
"清缘比丘",
"胜谛",
"葛伦布",
"虚明",
"血刀老祖",
"静闲师太",
"慧名尊者",
"李明霞",
"东方不败",
"宋远桥",
"张无忌",
"方碧琳",
"皮玄青",
"许雪亭",
"张三丰",
"澄欲",
"劳德诺",
"丘处机",
"陈志益",
"丛不弃",
"善勇",
"周伯通",
"程瑶迦",
"玄寂大师",
"令狐冲",
"慧空尊者",
"清善比丘",
"慧虚尊者",
"郝大通",
"林朝英",
"玄难大师",
"道尘禅师",
"贡唐仓国师",
"向问天",
"卓不凡",
"道一禅师",
"玄苦大师",
"张淡月",
"静迦师太",
"殷梨亭",
"道觉禅师",
"岳不群",
"虚竹",
"房志起",
"胖头陀",
"殷天正",
"静慧师太",
"高老者",
"王处一",
"张松溪",
"萨木活佛",
"刘处玄",
"达尔巴",
"宝象",
"范松",
"澄意",
"清为比丘",
"慧色尊者",
"清法比丘",
"谷虚道长",
"澄净",
"清无比丘",
"灵智上人",
"小龙女",
"赵鹤",
"胡斐",
"澄明",
"清晓比丘",
"杨莲亭",
"风清扬",
"慧洁尊者",
"澄灭",
"俞岱岩",
"赵灵珠",
"渡厄",
"范遥",
"静心师太",
"俞莲舟",
"澄思",
"洪安通",
"谭处端",
"王重阳",
"逍遥子",
"梅超风",
"慧修尊者",
"张乘云",
"澄坚",
"贝锦仪",
"渡劫",
"清乐比丘",
"灭绝师太",
"阿紫",
"渡难",
"小昭",
"道正禅师",
"张乘风",
"狮吼子",
"马钰",
"尹志平",
"李志常",
"成不忧",
"张志光",
"静空师太",
"空见",
"澄寂",
"杨逍",
"静虚师太",
"鸠摩智",
"苏荃",
"封不平",
"澄识",
"殷锦",
"苟读",
"清观比丘",
"黄蓉",
"澄行",
"姬清虚",
"慧如尊者",
"澄尚",
"拉章活佛",
"出尘子",
});




	if (! objectp(victim))
		return;

	if (objectp(killer))
	{
		owner = killer->query_temp("owner");
		if (objectp(owner))
			killer = owner;
	}

	// This while is only to enable "break"
	vs = victim->query_entire_dbase();
	while (1)
	{
		if (! objectp(killer))
			break;

		// call the killer's override function
		killer->killed_enemy(victim);

		if (! objectp(killer) || ! playerp(killer))
			break;

		// assure the killer's dbase
		ks = killer->query_entire_dbase();
		if (! mapp(kcombat = ks["combat"]))
		{
			kcombat = ([ ]);
			ks["combat"] = kcombat;
		}
//刺杀任务
if(mapp(killer->query("cisha"))){
if(victim->name()==killer->query("cisha/name")){		
killer->set("cisha/"+killer->query("cisha/name")+"_ok",1);		
}
}

		
		
		
		
		
	
		// adjust the "shen" & "experience" of the killer
		if (ks["combat_exp"] < vs["combat_exp"])
		{
			win_exp=1;

			if(random(20)==1)
			{
				tell_object(killer,"\n"HIM"<恭喜>:"NOR"  你"HIR"杀死了"NOR+victim->query("name")+HIG", 奖励:"GRN"【黄金】"NOR"... "HIY"  <额外经验>: "NOR+HIG+win_exp+YEL+" ↑" NOR"\n");
				box=new("/clone/money/gold"); 
				box->move(environment(killer));
			}

			ks["combat_exp"]+=win_exp;
			
			if (ks["combat_exp"] >= 100000 && ks["combat_exp"] >= vs["combat_exp"] * 2 / 3)
			{
				// adjust experience
				if (! intp(ks["experience"]))
					ks["experience"] = 0;
				killer->improve_experience(1 + random(5));
			}

			// adjust shen
			shen_delta = -vs["shen"] / 10;
			if (shen_delta > 100)
			{
				// 非线性校正获得的正神
				shen_delta = (shen_delta - 100) / 3 + 100;

				if (shen_delta > 200)
					shen_delta = (shen_delta - 200) / 3 + 200;

				if (shen_delta > 300)
					shen_delta = (shen_delta - 300) / 3 + 300;
			} else
			if (shen_delta < -100)
			{
				// 非线性校正获得的负神
				shen_delta = (shen_delta + 100) / 3 - 100;

				if (shen_delta < -200)
					shen_delta = (shen_delta + 200) / 3 - 200;

				if (shen_delta < -300)
					shen_delta = (shen_delta + 300) / 3 - 300;
			}
					
			ks["shen"] += shen_delta;
		}

		// weapon get the bonus
		if ((weapon = killer->query_temp("weapon")) ||
		    (weapon = killer->query_temp("armor/hands")))
			weapon->killer_reward(killer, victim);

		// record the user's killing
		if (userp(victim))
		{
			if (! intp(kcombat["PKS"]))
				kcombat["PKS"] = 1;
			else
				kcombat["PKS"]++;

			// do family action
			FAMILY_D->family_kill(killer, victim);

			// do league action
			LEAGUE_D->league_kill(killer, victim);

			if (victim->query_condition("killer"))
			{
				follow_msg = "听说杀人凶手" + victim->name(1) + "被" + killer->name(1) + "在" +
					     environment(victim)->short() + HIM"就地正法了。";
				break;
			}

			if (objectp(xuanshang_order = (present(victim->query("id") + "-order", killer))))
				call_out("finish_xuanshang", 1, xuanshang_order, killer, victim);

			if (! killer->is_want_kill(vs["id"]))
				break;

			if (! intp(kcombat["WPK"]))
				kcombat["WPK"] = 1;
			else
				kcombat["WPK"]++;

			if (! killer->query_condition("killer"))
			{
				follow_msg = "听说官府发下海捕文书，缉拿杀人凶手" + killer->name(1) + "。";
				killer->apply_condition("killer", 900);
			} else
			{
				follow_msg = "听说官府加紧捉拿累犯重案的暴徒" + killer->name(1) + "。";
				killer->apply_condition("killer", 900 + (int)killer->query_condition("killer"));
			}

			// assure data of kcombat
			if (! intp(kcombat["WPK_NOTBAD"])) kcombat["WPK_NOTBAD"] = 0;
			if (! intp(kcombat["WPK_NOTGOOD"])) kcombat["WPK_NOTGOOD"] = 0;
			if (! intp(kcombat["WPK_GOOD"])) kcombat["WPK_GOOD"] = 0;
			if (! intp(kcombat["WPK_BAD"])) kcombat["WPK_BAD"] = 0;

			// record the combat info.
			if (victim->is_not_bad())  kcombat["WPK_NOTBAD"]++;
			if (victim->is_not_good()) kcombat["WPK_NOTGOOD"]++;
			if (victim->is_good())     kcombat["WPK_GOOD"]++;
			if (victim->is_bad())      kcombat["WPK_BAD"]++;
			break;
		}

		if (vs["can_speak"])
			if (! intp(kcombat["MKS"]))
				kcombat["MKS"] = 1;
			else
				kcombat["MKS"]++;

		break;
	}

	
if (playerp(victim)&&victim->query("combat_exp")<1000000)
	{
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// clear all condition
		victim->clear_condition();

		// remove vendetta
		map_delete(vs, "vendetta");

		// generate message of die reason
		if (objectp(killer) && killer->is_character())
		{
			msg = "被" + filter_color(killer->name(1));
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="砍死了";
				break;
			case "刺伤":
				msg+="刺死了";
				break;
			case "震伤":
			case "瘀伤":
				msg+="击死了";
				break;
			case "内伤":
				msg+="震死了";
				break;
			default:
				msg+="杀死了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor", follow_msg);

		tell_object(victim,HIM + "新手保护期[<100万经验]免去了你的死亡惩罚" + NOR"\n");
		victim->start_busy(15);
		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
			string cname;
			object couple;

			//log_files("static/killrecord",
			//	 sprintf("%s %s killed %s\n",
			//		 log_time(),
			//		 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);
		}
	}
	else 
	if (playerp(victim)&&victim->query_temp("kuilei_used"))
	{
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// clear all condition
		victim->clear_condition();

		// remove vendetta
		map_delete(vs, "vendetta");

		// generate message of die reason
		if (objectp(killer) && killer->is_character())
		{
			msg = "被" + filter_color(killer->name(1));
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="砍死了";
				break;
			case "刺伤":
				msg+="刺死了";
				break;
			case "震伤":
			case "瘀伤":
				msg+="击死了";
				break;
			case "内伤":
				msg+="震死了";
				break;
			default:
				msg+="杀死了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor",
					      follow_msg);

		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + "使用了替身傀儡免去了死亡惩罚。", victim->name(1)));

		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
			string cname;
			object couple;

			//log_files("static/killrecord",
			//	 sprintf("%s %s killed %s\n",
			//		 log_time(),
			//		 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);
		}
	}
	else if (playerp(victim))
	{
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// clear all condition
		victim->clear_condition();

		// adjust shen
		vs["shen"] -= vs["shen"] / 10;

		// adjust combat exp.
		vs["combat_exp"] -= vs["combat_exp"] * 2 / 100;

		// adjust weiwang
		vs["weiwang"] -= vs["weiwang"] / 10;

		// adjust score
		vs["score"] -= vs["score"] / 10;

		// remove vendetta
		map_delete(vs, "vendetta");

		// lost half of potential
		if (vs["potential"] > vs["learned_points"] && vs["combat_exp"] > 337500)
			vs["potential"] += (vs["learned_points"] - vs["potential"]) / 5;

		// lost half of experience
		if (vs["experience"] > vs["learned_experience"])
			vs["experience"] += (vs["learned_experience"] - vs["experience"]) / 5;

		victim->skill_death_penalty();
		inv = all_inventory(victim);
		for(i=0;i<sizeof(inv);i++)
		{
			if(inv[i]->is_item_make()&&inv[i]->query("equipped"))
				inv[i]->owner_death_penalty();
		}

		// generate message of die reason
		
		
		if (objectp(killer) && killer->is_character())
		{
			msg = "被" + filter_color(killer->name(1));
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="砍死了";
				break;
			case "刺伤":
				msg+="刺死了";
				break;
			case "震伤":
			case "瘀伤":
				msg+="击死了";
				break;
			case "内伤":
				msg+="震死了";
				break;
			default:
				msg+="杀死了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor",follow_msg);

		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
			string cname;
			object couple;

			//log_files("static/killrecord",
			//	 sprintf("%s %s killed %s\n",
			//		 log_time(),
			//		 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);

			// check sadly
			cname = victim->query("couple/id");
			if (cname &&
			    victim->query("gender") == "女性" &&
			    victim->query("combat_exp") >= 970000 &&
			    objectp(couple = find_player(cname)) &&
			    couple != killer &&
			    couple->query("static/marry") <= 1 &&
			    victim->query("static/marry") <= 1)
			{
				couple->add("static/sadly", 1);
				tell_object(couple, "你的妻子死在了" +
					    killer->name(1) + "的手下" +
					    "，你感到了一阵深深的哀伤。\n");
			}
		}
	}
	
	else
	if (victim->query("sc"))
	{
		// clear punish info.
		if (objectp(killer) && killer->is_punisher())
			victim->delete("combat/need_punish");

		// clear all condition
		victim->clear_condition();

		// remove vendetta
		map_delete(vs, "vendetta");

		// generate message of die reason
		if (objectp(killer) && killer->is_character())
		{
			msg = "被" + filter_color(killer->name(1));
			actions = killer->query_action();
			switch (mapp(actions) ? actions["damage_type"] : "杀伤") {
			case "擦伤":
			case "割伤":
				msg+="砍死了";
				break;
			case "刺伤":
				msg+="刺死了";
				break;
			case "震伤":
			case "瘀伤":
				msg+="击死了";
				break;
			case "内伤":
				msg+="震死了";
				break;
			default:
				msg+="杀死了";
			}
		}
		if (stringp(victim->query_temp("die_reason")))
			msg = filter_color(victim->query_temp("die_reason"));

		victim->delete_temp("die_reason");
		CHANNEL_D->do_channel(this_object(), "rumor",		
			sprintf("听说%s" HIM + msg + "。", victim->name(1)));

		// show the follow msg after victim die
		if (follow_msg)
			CHANNEL_D->do_channel(this_object(), "rumor", follow_msg);

		tell_object(victim,HIM + "新手保护期[<100万经验]免去了你的死亡惩罚" + NOR"\n");
	//	victim->start_busy(15);
		victim->set("combat/last_die", filter_color(msg));
		if (objectp(killer) && playerp(killer) && playerp(victim))
		{
			string cname;
			object couple;

			//log_files("static/killrecord",
			//	 sprintf("%s %s killed %s\n",
			//		 log_time(),
			//		 log_id(killer), log_id(victim)));

			killer->remove_killer(victim);
		}
	}
	
	
	
	
	
	
	

	if (stringp(vmark = victim->query("vendetta_mark")) && objectp(killer))
		killer->add("vendetta/" + vmark, 1);
}

// me hit victim with poison in ob
void hit_with_poison(object me, object victim, object ob)
{
	mapping p, ap;
	string msg;
	string poison_type;

	if (! mapp(p = ob->query_temp("daub/poison")))
		return;

	if (! stringp(poison_type = ob->query_temp("daub/poison_type")))
		return;

	if (! p["remain"])
		return;

	// affect parameter
	ap = allocate_mapping(4);
	if (ob == me)
		ap["level"] = p["level"] * 9 / 10 + 1;
	else
		ap["level"] = p["level"] * 8 / 10 + 1;
		
	ap["id"]       = p["id"];
	ap["name"]     = p["name"];
	ap["duration"] = 1;

	if (p["remain"] > p["level"])
	{
		// decrase the remain poison
		p["remain"] -= p["level"];
	} else
	{
		// the poison has run out
		ob->delete_temp("daub");
	}

	msg = HIG "突然$n觉得受伤的地方有一些麻痒";
	if (p["id"] == victim->query("id"))
	{
		if (! victim->query_temp("has_announce/defense1"))
		{
			victim->set_temp("has_announce/defense1", 1);
			victim->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", victim :), victim), 15);
			msg += "。"NOR"\n" HIC "$n默一运功，冷笑两声：“好你个" +
			       RANK_D->query_rude(me) + "，居然在我面前卖弄" +
			       RANK_D->query_self_rude(victim) +
			       "毒药！真是假李鬼碰上真李逵了！”"NOR"\n";
		} else
			msg += "，不过$n并没有在意。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < victim->query_skill("poison", 1))
	{
		if (! victim->query_temp("has_announce/defense2"))
		{
			victim->set_temp("has_announce/defense2", 1);
			victim->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", victim :), victim), 15);
			msg += "。"NOR"\n" HIC "$n呼吸数次，嘿然冷笑道："
			       "“米粒之珠，也放光华？”"NOR"\n";
		} else
			msg += "，不过$n显然并没有把它放在心上。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < victim->query_skill("force") / 2)
	{
		if (! victim->query_temp("has_announce/defense3"))
		{
			victim->set_temp("has_announce/defense3", 1);
			victim->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", victim :), victim), 15);
			msg += "。"NOR"\n" HIC "$n深吸一口气，哈哈长笑道：“好家伙，居然" +
			       (ob == me ? "在身上淬毒" : "使用淬毒兵器") +
			       "，你这些下三滥的手段也敢到我面前卖弄？”"NOR"\n";
		} else
			msg += "，不过$n看起来似乎并无大碍。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	victim->affect_by(poison_type, ap);

	msg += "，大概是中毒了。"NOR"\n";
	if (p["level"] < victim->query_skill("force"))
	{
		msg += HIG "$n深深吸一了口气，面目凝重，手中的攻势陡然一紧。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	msg += HIR "$n闷哼一声，攻势顿缓，神情甚是痛苦。"NOR"\n";
	if (! victim->is_busy())
		victim->start_busy(1 + random(2));
	set_ahinfo(msg);
	return;
}

// me hit victim, but poison by victim in ob
void hit_poison(object me, object victim, object ob)
{
	mapping p, ap;
	string msg;
	string poison_type;

	if (! mapp(p = ob->query_temp("daub/poison")))
		return;

	if (! stringp(poison_type = ob->query_temp("daub/poison_type")))
		return;

	if (! p["remain"])
		return;

	if (me->query_temp("armor/hands"))
		return;

	// affect parameter
	ap = allocate_mapping(4);
	ap["level"]    = p["level"] * 7 / 10 + 1;
		
	ap["id"]       = p["id"];
	ap["name"]     = p["name"];
	ap["duration"] = 1;

	if (p["remain"] > p["level"])
	{
		// decrase the remain poison
		p["remain"] -= p["level"];
	} else
	{
		// the poison has run out
		ob->delete_temp("daub");
	}

	msg = HIG "突然$N觉得浑身有些麻痒";
	if (p["id"] == me->query("id"))
	{
		if (! me->query_temp("has_announce/defense1"))
		{
			me->set_temp("has_announce/defense1", 1);
			me->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", me :), me), 15);
			msg += "。"NOR"\n" HIC "$N默一运功，冷笑两声：“好你个" +
			       RANK_D->query_rude(victim) + "，居然在我面前卖弄" +
			       RANK_D->query_self_rude(victim) +
			       "的毒药！把你衣服上的毒药都还给我！”"NOR"\n";
		} else
			msg += "，不过$N并没有在意。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < me->query_skill("poison", 1))
	{
		if (! me->query_temp("has_announce/defense2"))
		{
			me->set_temp("has_announce/defense2", 1);
			me->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", me :), me), 15);
			msg += "。"NOR"\n" HIC "$N呼吸数次，嘿然冷笑道：“米粒之珠，也"
			       "放光华？你在衣衫上淬毒我就怕你了？”"NOR"\n";
		} else
			msg += "，不过$N显然并没有把它放在心上。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < me->query_skill("force") / 2)
	{
		if (! me->query_temp("has_announce/defense3"))
		{
			me->set_temp("has_announce/defense3", 1);
			me->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", me :), me), 15);
			msg += "。"NOR"\n" HIC "$N深吸一口气，哈哈长笑道：“你居然在衣衫上"
			       "淬毒，这些下三滥的手段也敢到我面前卖弄？”"NOR"\n";
		} else
			msg += "，不过$N看起来似乎并无大碍。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	me->affect_by(poison_type, ap);

	msg += "，看来有些不妙。"NOR"\n";
	if (p["level"] < me->query_skill("force"))
	{
		msg += HIG "$N深深吸一了口气，面目凝重，手中的攻势陡然一紧。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	msg += HIR "$N脚步一个跄踉，攻势顿缓，神色难看之极。"NOR"\n";
	me->start_busy(1 + random(2));
	set_ahinfo(msg);
	return;
}

void clear_announce(object me)
{
	if (! objectp(me))
		return;

	me->delete_temp("has_announce");
}

int PVP_DAMAGE_SCALE = 70;  // 玩家对玩家时伤害（当前值）下降为 70%
int PVP_WOUND_SCALE  = 60;  // 玩家对玩家时伤害（最大值）下降为 60%

int calc_damage(object attacker, object victim, int damage)
{
	damage += (attacker->query_gain_damage()+attacker->query_gain_break());
	if (objectp(attacker) &&
	    objectp(victim) &&
	    playerp(attacker) && 
	    playerp(victim))
	{
		damage = (damage - victim->query_gain_armor() - victim->query_temp("apply/armor")/4) * PVP_DAMAGE_SCALE / 100;
	}
	else damage -= (victim->query_temp("apply/armor")/4 + victim->query_gain_armor());

	if(damage<1) damage = 1;

	return damage;
}

int calc_wound(object attacker, object victim, int wound)
{
	wound += (attacker->query_gain_damage()+attacker->query_gain_break());
	if (objectp(attacker) &&
	    objectp(victim) &&
	    playerp(attacker) && 
	    playerp(victim))
	{
		wound = (wound - victim->query_gain_armor() - random(victim->query_temp("apply/armor"))) * PVP_WOUND_SCALE / 100;
	}

	else wound -= (random(victim->query_temp("apply/armor")) + victim->query_gain_armor());

	if(wound<1) wound = 1;

	return wound;
}

varargs int do_attack_wound(object me, object victim, object weapon, int attack_type)	//打气血上限
{
	mapping my, your;
	mapping my_temp, your_temp;
	mapping prepare, action;
	string limb, *limbs;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	string parry_msg;
	mixed foo;

	int crit,delta;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int wounded;
	int has_weapon;
	int baoji;

	object weapon2;	// weapon of victim
	object cloth;   // armor of victim

	string skill_name,result;
	string damage_msg,damage_info;
	mapping fight;

	object env_me;
	object env_v;

	if (environment(me)->query("no_fight")&&!me->query_condition("killer")&&!victim->query_condition("killer"))
	{
		message_vision("$N和$n各自退了一步，收住了招。\n",me, victim);
		me->remove_enemy(victim);
		victim->remove_enemy(me);
		return 0;
	}

	if (environment(me) != environment(victim))
	{
		me->remove_enemy(victim);
		victim->remove_enemy(me);
		return 0;
	}

	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();

	if (! (my_temp = me->query_entire_temp_dbase()))
		my_temp = allocate_mapping(5);

	if (! (your_temp = victim->query_entire_temp_dbase()))
		your_temp = allocate_mapping(5);

	//
	// (0) Choose skills.
	//
	prepare = me->query_skill_prepare();
	if (! prepare) prepare = ([]);

	if (objectp(weapon))
		attack_skill = weapon->query("skill_type");
	else
	{
		switch (sizeof(prepare))
		{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
		}
	}

	if (attack_skill == "pin")
		attack_skill = "sword";

	// (1) Find out what action the offenser will take.
	//
	me->reset_action();
	action = me->query_action();

	has_weapon = weapon || me->query_temp("armor/hands");

	if (! action)
	{
		// reconfirm
		me->reset_action();
		action = me->query_action();
		if (! mapp(action))
		{
			CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s(%s): bad action = %O",me->query("name"), me->query("id"),me->query_action(1)));
			return 0;
		}
	}

	if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n紧跟着" + action["action"] + "！\n"; 

	if(!stringp(skill_name = action["skill_name"]))
		if(!stringp(skill_name = me->query_skill_mapped(attack_skill)))
			skill_name = attack_skill;
	me->set_temp("attack_skill_name",to_chinese(skill_name));

	//
	// (2) Prepare AP, DP for checking if hit.
	//
	limbs = victim->query("limbs");
	if (! arrayp(limbs))
	{
		limbs = ({ "身体" });
		victim->set("limbs", limbs);
	}
	limb = limbs[random(sizeof(limbs))];

	if (! my["not_living"])
	{
		fight = allocate_mapping(5);
		fight["attack"] = action["attack"];
		fight["dodge"]  = action["dodge"];
		fight["parry"]  = action["parry"];
		my_temp["fight"] = fight;
	}
	//计算攻击者技能 攻击力
	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK, 0);
	if (ap < 1) ap = 1;

	if (my["character"] == "阴险奸诈")
		//阴险性格AP加乘120%
		ap += ap * 20 / 100;     
	//计算被 攻击者 的 轻功 躲闪值
	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE, 0);
	if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
	{
		//如果装备特殊轻功，则计算特殊轻功的加乘率
		dp += dp / 200 * SKILL_D(dodge_skill)->query_effect_dodge(me, victim);
	}
	if (dp < 1) dp = 1;
	//如果被攻击者处于繁忙状态，躲闪值降低3倍 
	if (victim->is_busy()) dp /= 3;

	//
	// (3) Fight!

	damage = 0;   //破坏
	wounded = 0;   //创伤
	damage_info = "";  //破坏信息
	
	//如果随机（攻击值+被攻击者的躲闪值）小于躲闪值，认为躲闪成功
	if (random(ap + dp) < dp && victim->query("qi")!=0)
	{  // Does the victim dodge this hit?

#if INSTALL_COMBAT_TEST
		if (wizardp(me) && me->query("env/combat_test"))
			tell_object(me, HIY "【测试精灵】：己方 AP：" + ap +"，DP：" + dp + "。"NOR"\n");
		if (wizardp(victim) && victim->query("env/combat_test"))
			tell_object(victim, HIC "【测试精灵】：对方 AP：" + ap + "，DP：" + dp + "。"NOR"\n");
#endif

		//如果没有装备特殊轻功，就给与基本轻功
		if (! dodge_skill) dodge_skill = "dodge";
		//取出轻功的躲闪信息。
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
		damage = -1;
		//判断是否增加轻功的熟练度
		//如果躲闪值小于攻击值，而且还躲过了攻击
		if (userp(me) || userp(victim))  
		{
			if (random(dp+ap) < dp && random(my["int"]) > 14)
			{
				//如果随即被攻击者的经验不大于极限经验，并且随机到真就加奖励
				if (your["combat_exp"] < EXP_LIMIT && victim->query("combat_exp")<me->query("combat_exp"))
				{
					tell_object(victim,"你在"HIC"躲避"NOR+me->query("name")+"时对"HIG"【"+to_chinese(dodge_skill)+"】"NOR"顿有所悟: "YEL"武功熟练度 "HIY"↑"NOR","YEL"实战经验 "HIY"↑" NOR"\n");				
					your["combat_exp"]++;
					victim->improve_skill(dodge_skill, 1);
			       
				}
			}
		}
	} 
	else  //如果躲闪不成功，就判断是否增加攻击的奖励
	{
		//
		//      (4) Check if the victim can parry this attack.
		// 都是可以互动的
		if (userp(me) || userp(victim))     
		{
			//计算是否给予攻击奖励。
			//如果攻击小于躲闪 并且 随机悟性大于14 ，并且潜能是否超出
			if (random(ap + dp) < dp && random(my["int"]) > 12 )
			{
				if( me->query("combat_exp") < victim->query("combat_exp"))
				{
					if(me->query("potential") < me->query_potential_limit())
					{
						tell_object(me,"你在"HIR"攻击"NOR+victim->query("name")+"时对"HIG"【"+to_chinese(attack_skill)+"】"NOR"顿有所悟:"YEL" 武功熟练度 "HIY"↑"NOR","YEL"经验点 "HIY"↑" NOR"\n");
						my["potential"]++;
						your_temp["give_potential"] += my["mud_age"] / 86400;
						me->improve_skill(attack_skill, 1);     
					}
				}
			}
		}
		delta = 0;
		//取出装备主手的兵器对象
		if (weapon2 = your_temp["weapon"])
		{
			if (! weapon) delta = 10;  //如果没有兵器，delta=10
		} 
		else
		{
			if (weapon) delta = -10;   //有装备兵器，delta=-10
		}
		//计算被攻击者 招架技能 的值
		pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE, delta);
		//如果被攻击者 繁忙，招架值减少3倍
		if (victim->is_busy()) pp /= 3;
		if (pp < 1) pp = 1;
		//计算特殊招架技能给予的招架值加乘。
		if (stringp(parry_skill = victim->query_skill_mapped("parry")))
			pp += pp / 200 * SKILL_D(parry_skill)->query_effect_parry(me, victim);
		//如果随机（攻击值+招架值）小于招架值 则判断 招架成功，除非气血为0
		if (random(ap + pp) < pp && victim->query("qi")!=0)
		{
		       
#if INSTALL_COMBAT_TEST
			if (wizardp(me) && me->query("env/combat_test"))
				tell_object(me, HIY "【测试精灵】：己方 AP：" + ap + "，PP：" + pp + "。"NOR"\n");
			if (wizardp(victim) && victim->query("env/combat_test"))
				tell_object(victim, HIC "【测试精灵】：对方 AP：" + ap + "，PP：" + pp + "。"NOR"\n");
#endif
			//如果没有特殊招架，则给予 [基本招架]
			if (! parry_skill) parry_skill = "parry";
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.
			//取出有带兵器的[特殊招架]信息
			parry_msg = SKILL_D(parry_skill)->query_parry_msg(weapon2);
			//如果没有[特殊招架]兵器的招架信息
			if (! stringp(parry_msg))
				//就取出[基本招架]兵器信息
				parry_msg = SKILL_D("parry")->query_parry_msg(weapon2);
			//如果有招架信息，则赋予result+招架信息
			if (stringp(parry_msg))
				result += parry_msg + "\n";
			damage = -2;
			//判断是否给予招架奖励
			//如果招架值小于攻击，而招架成功，并且计算 xx>30
		      if (userp(me) || userp(victim))  
		      {
				if (random(ap + pp) < pp && random(my["int"]) > 14)
				{
					//如上，通过就给予招架奖励
					if (your["combat_exp"] < EXP_LIMIT && victim->query("combat_exp")<me->query("combat_exp"))
					{
						tell_object(victim,"你在"HIM"招架"NOR+me->query("name")+"时对"HIG"【"+to_chinese(parry_skill)+"】"NOR"顿有所悟:"YEL" 武功熟练度 "HIY"↑"NOR","YEL"经验点 "HIY"↑" NOR"\n");					
						your["combat_exp"]++;		   
						victim->improve_skill(parry_skill, 1);
					}
					else
					{
					     tell_object(victim,WHT+"【你的对手太弱了，无法取得任何经验！！！】"NOR"\n");
					}
				}
		      }
		} 
		else
		{
			//
			// (5) We hit the victim and the victim failed to parry
			//
			//如果有兵器，则取出兵器的攻击力，否则取出空手攻击力
			if (weapon)
				damage = me->query_temp("apply/damage");
			else
				damage = me->query_temp("apply/unarmed_damage");
							
			//将攻击力变成在一定的随机范围波动。
			damage = (damage + random(damage)) / 2;
			if (action["damage"])
				damage += action["damage"] * damage / 100;
			//攻击者力量取出
			damage_bonus = me->query_str();
			//判断是否是 愤怒状态
			if (my["jianu"])
			{
				// does angry bnous
				damage_bonus += me->cost_craze(my["jianu"]);
				//是否为狂化状态，计算狂化状态信息
				if (me->query_craze() > 1000 && random(my["jianu"] + 200) > 200)
				{
					damage_info += random(2) ? HIR "$N" HIR "大喝一声，双目圆睁，一股凌厉的杀气油然而起！"NOR"\n"
								 : HIR "$N" HIR "奋不顾身的扑上前来，招招紧逼$n" HIR "，毫不容情。"NOR"\n";
					//消耗怒气值
					me->cost_craze(200 + random(300));
					damage_bonus += my["jianu"] * 2;
				}
			}

			// Clear the special message info after damage info
			foo_before_hit = 0;
			foo_after_hit = 0;

			// Let force skill take effect.
			if (my["jiali"] && (my["neili"] > my["jiali"]))
			{
				if (force_skill = me->query_skill_mapped("force"))
				{
					foo = SKILL_D(force_skill)->force_hit_ob(me, victim, damage_bonus, my["jiali"]);
					if (stringp(foo)) damage_info += foo; else
					if (intp(foo)) damage_bonus += foo; else
					if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage_bonus += foo["damage"];
					}
				}

#if INSTALL_COMBAT_TEST
				if (wizardp(me) && me->query("env/combat_test"))
					tell_object(me, HIY "【测试精灵】：己方 AP：" + ap + "，DP：" + dp + "，PP：" + pp +
						    "，伤害效果：" + damage + "，额外伤害效果：" + damage_bonus + "。"NOR"\n");
				if (wizardp(victim) && victim->query("env/combat_test"))
					tell_object(victim, HIC "【测试精灵】：对方 AP：" + ap + "，DP：" + dp + "，PP：" + pp +
						    "，伤害效果：" + damage + "，额外伤害效果：" + damage_bonus + "。"NOR"\n");
#endif
			}

			if (action["force"])
				damage_bonus += action["force"] * damage_bonus / 100;

			// calculate the damage
			if (damage_bonus > 0)
				damage += (damage_bonus + random(damage_bonus)) / 3;

			// Let's attack & parry skill, weapon & armor do effect
			while (damage > 0)
			{
				if (my["not_living"] || your["not_living"])
					// Only two living do this
					break;

				if (damage < 1) break;

				// Let parry skill take its special effort.
				if (stringp(dodge_skill = victim->query_skill_mapped("dodge")))
				{
					victim->set_temp("dodge_valid_damage", 1);
					foo = SKILL_D(dodge_skill)->valid_damage(me, victim, damage, weapon);
					victim->delete_temp("dodge_valid_damage");
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
					if (damage < 1) break;
				}

				if (stringp(parry_skill = victim->query_skill_mapped("parry")))
				{
					foo = SKILL_D(parry_skill)->valid_damage(me, victim, damage, weapon);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
					if (damage < 1) break;
				}
				// 魔幻兽
				if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["beast"]))
				{
					foo = cloth->valid_damage(me, victim, damage, weapon);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				else if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["armor"]))
				{
					foo = cloth->valid_damage(me, victim, damage, weapon);
					if (stringp(foo)) damage_info += foo; else
					if (intp(foo)) damage += foo; else
					if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				else if (mapp(your_temp["armor"]) && objectp(cloth = your_temp["armor"]["cloth"]))
				{
					foo = cloth->valid_damage(me, victim, damage, weapon);
					if (stringp(foo)) damage_info += foo; else
					if (intp(foo)) damage += foo; else
					if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}

				if (damage < 1) break;

				if (martial_skill = me->query_skill_mapped(attack_skill))
				{
					foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
					if (damage < 1) break;
				}

				// Let weapon or living have their special damage.
				if (weapon)
				{
					foo = weapon->hit_ob(me, victim, damage);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				else
				{
					foo = me->hit_ob(me, victim, damage);
					if (stringp(foo))
						damage_info += foo;
					else if (intp(foo))
						damage += foo;
					else if (mapp(foo))
					{
						damage_info += foo["msg"];
						damage += foo["damage"];
					}
				}
				break;
			}

			//
			//      (6) Inflict the damage.
			//
			//几率触发生成暴击
				if (weapon&&baoji = weapon->baoji())		
				{					
				    if (baoji >= random(100))
			      	{
			     	damage +=damage;
			     	tell_object(me,weapon->name()+HIR"暴击效果触发！\n"NOR);
				   }
				}
			if (damage > 0)
			{
				if (my["character"] == "心狠手辣")
					damage += damage * 20 / 100;

				wounded = damage;

				if (wounded > 400)
					wounded = (wounded - 400) / 4 + 300;
				else if (wounded > 200)
					wounded = (wounded - 200) / 2 + 200;
				else if (wounded < 1)
					wounded = 0;

				// recalculate damage
				if (damage > 400)
					damage = (damage - 400) / 4 + 300;
				else if (damage > 200)
					damage = (damage - 200) / 2 + 200;

				if (your["character"] == "光明磊落")
					wounded -= wounded * 20 / 100;

				damage = COMBAT_D->calc_damage(me, victim, damage);
//暴击修正
				if( (crit = me->query("gain/2ap") - victim->query("gain/2dp")) > 0 )
				{
					if( crit > random(150) )
					{
						damage *= 2;
						//wounded *= 2;
						result += RED"$N凝神贯注，对着$n发出会心一击！"NOR"\n";
					}
				}
				damage = victim->receive_wound("qi", damage, me);

#if INSTALL_COMBAT_TEST
				if (wizardp(me) && me->query("env/combat_test"))
					tell_object(me, HIY "【测试精灵】：你对" + victim->query("name") + "造成" + damage + "点伤害，" +  wounded + "点创伤。"NOR"\n");
				if (wizardp(victim) && victim->query("env/combat_test"))
					tell_object(victim, HIG "【测试精灵】：你受到" + me->query("name") + damage + "点伤害，" + wounded + "点创伤。"NOR"\n");
#endif

				// add message before hit in victim
				if (foo_before_hit)
					result += foo_before_hit;

				result += damage_msg(damage, action["damage_type"]);
				result += "(真实伤害)\n";
				damage_info += "( $n" + eff_status_msg(victim->query("qi") * 100 / victim->query("max_qi")) + ")\n";
			}

			if (foo_after_hit)
				damage_info += foo_after_hit;
		}
	}

	result = replace_string(result, "$l", limb);
	if (objectp(weapon))
		result = replace_string(result, "$w", weapon->name());
	else if (stringp(action["weapon"]))
		result = replace_string(result, "$w", action["weapon"]);
	else if (attack_skill == "finger" || attack_skill == "hand")
		result = replace_string(result, "$w", "手指" );
	else if (attack_skill == "strike" || attack_skill == "claw")
		result = replace_string(result, "$w", "手掌" );
	else
		result = replace_string(result, "$w", "拳头" );
	message_combatd(result, me, victim, damage_info,damage,action["damage_type"]);

	if (damage > 0)
	{
		if (victim->is_busy())
			victim->interrupt_me(victim, 2 + random(2));
		if ((!me->query_temp("fight_team")) && (! me->is_killing(your["id"])) && (! victim->is_killing(my["id"])) 
			&& ! victim->query("not_living") && your["qi"] * 3 <= your["max_qi"])
		{
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			if (me->query("can_speak") && victim->query("can_speak"))
				message_vision(winner_msg[random(sizeof(winner_msg))],me, victim);
			if (me == victim->query_competitor())
			{
				me->win();
				victim->lost();
			}
		}
	}

	if (functionp(action["post_action"]))
		evaluate(action["post_action"], me, victim, weapon, damage + "tesetest");

	if (attack_type == TYPE_REGULAR && damage < 1 && your_temp["guarding"])
	{
		if (random(my["dex"]) < 8)
		{
			message_vision("$N一击不中，露出了破绽！\n",me,victim);
			do_attack(victim, me, your_temp["weapon"],TYPE_QUICK);
		} else
		{
			message_vision("$n见$N攻击失误，趁机发动攻击！\n",me,victim);
			do_attack(victim, me, your_temp["weapon"],TYPE_RIPOSTE);
		}
	}
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
