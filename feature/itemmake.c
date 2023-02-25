// itemmake.c 自制道具
//增加十兵宝石克制效果，并修复原十兵在包裹可以生效的问题。2020-06-01北京须臾徐
#include <dbase.h>
#include <ansi.h>
#include <name.h>
#include <move.h>
#include <command.h>
//#include <stdio.h>
//#include <math.h>
//#include <stdlib.h>

//#define PI 3.1415926
inherit F_OBSAVE;
inherit F_NOCLONE;
int weapon_level();

int is_item_make() { return 1; }

#define	LEVEL1		50
#define	LEVEL2		500
#define	LEVEL3		1000
#define	LEVEL4		3000
#define	LEVEL5		6000
#define	LEVEL6		10000
#define	LEVEL7		15000
#define	LEVEL8		20000
#define	LEVEL9		25000
#define MAX_LEVEL       LEVEL9
#define ULTRA_LEVEL     (LEVEL9 + 10)

static int *levels = ({ LEVEL1, LEVEL2, LEVEL3, LEVEL4,
			LEVEL5, LEVEL6, LEVEL7, LEVEL8,
			LEVEL9, ULTRA_LEVEL });

static int performing  = 0;
static int attack_lvl  = 0;
static int defense_lvl = 0;


int is_stay_in_room() { return attack_lvl >= ULTRA_LEVEL; }
int level_max_exp(int level)
{
	int lvl,attack_lvl;

	attack_lvl = weapon_level();
	lvl = sizeof(levels);

	while (--lvl)
		if (attack_lvl >= levels[lvl])
			break;
	lvl++;
	if(lvl>9) lvl = 9;
	return levels[lvl];
}
int level_now(int level)
{
	int lvl,attack_lvl;

	attack_lvl = weapon_level();
	lvl = sizeof(levels);

	while (--lvl)
		if (attack_lvl >= levels[lvl])
			break;
	lvl++;
	return lvl;
}
// 武器的主人ID - 通过文件的名字来判断
string item_owner()
{
	string owner;
	if (sscanf(base_name(this_object()), ITEM_DIR "%*s/%s-%*s", owner))
		return owner;

	return 0;
}

string item_kaiguang()
{
	string kaiguang;
	if (sscanf(base_name(this_object()), ITEM_DIR "%*s/%s-%*s", kaiguang))
		return kaiguang;

	return 0;
}


// 判断该武器是否被当前某人所持有
int is_not_belong_me(object me)
{
	string user;

	user = query("user");
	if (! user || ! sscanf(user, "%*s(" + me->query("id") + ")"))
		return 1;

	return 0;
}

// 武器装备的等级
int weapon_level()
{
	mapping o;
	string *ks;
	int lvl;
	int i;

	lvl = 0;
	o = query("owner");
	if (mapp(o))
	{
		ks = keys(o);
		for (i = 0; i < sizeof(ks); i++)
			lvl += o[ks[i]];
	}

	lvl /= 100;
	if (lvl > MAX_LEVEL) lvl = MAX_LEVEL;

	if (lvl == MAX_LEVEL && query("magic/power"))
		// 具有魔法属性
		lvl = ULTRA_LEVEL;
	return lvl;
}

int weapon_exp()
{
   mapping o;
	string *ks;
	int lvl_exp;
	int i;

	lvl_exp = 0;
	o = query("owner");
	if (mapp(o))
	{
		ks = keys(o);
		for (i = 0; i < sizeof(ks); i++)
			lvl_exp += o[ks[i]];
	}
     return lvl_exp/100;
}
// 防御装备的等级
int armor_level()
{
	mapping o;
	string *ks;
	int lvl;
	int i;

	lvl = 0;
	o = query("owner");
	if (mapp(o))
	{
		ks = keys(o);
		for (i = 0; i < sizeof(ks); i++)
			lvl += o[ks[i]];
	}

	lvl /= 100;
	if (lvl > MAX_LEVEL) lvl = MAX_LEVEL;

	if (lvl == MAX_LEVEL && query("magic/power"))
		// 具有魔法属性
		lvl = ULTRA_LEVEL;
	return lvl;
}

int armor_exp()
{
   mapping o;
	string *ks;
	int lvl_exp;
	int i;

	lvl_exp = 0;
	o = query("owner");
	if (mapp(o))
	{
		ks = keys(o);
		for (i = 0; i < sizeof(ks); i++)
			lvl_exp += o[ks[i]];
	}
     return lvl_exp/100;
}

// 武器装备的长描述
string weapon_long()
{
	string  n;
	mapping c;
	int type;
	int k;
	int lvl;
	string tessera_name;
	string result;

	c = query("combat");
	n = query("unit") + name();
	if (! c)
		return "这" + n + "显然还没有饮过人血，上面纯洁无暇。\n";
	k = c["MKS"] + c["PKS"];

	if (c["WPK_GOOD"] < k / 2 &&
	    c["WPK_BAD"]  < k / 2)
		type = 0;
	else
	if (c["WPK_GOOD"] > c["WPK_BAD"] * 2)
		type = -1;
	else
		type = 1;

	if (c["MKS"] + c["PKS"] < 10)
		return "这" + n + "看来已经用过人血开祭，上面隐现血痕。\n";

	attack_lvl = weapon_level();
	lvl = sizeof(levels);
	while (--lvl)
		if (attack_lvl >= levels[lvl])
			break;
	lvl++;

	switch (type)
	{
	case 1:
		if (attack_lvl >= ULTRA_LEVEL)
			result = HIY "它看上去平平常常，没有半点特殊，只是"
				 "隐隐的让人感到那不凡的气质。"NOR"\n";
		else
		if (attack_lvl >= MAX_LEVEL)
			result = HIY "它看上去让人发自内心无限崇敬，一股"
			       "皓然正气悠然长存，颇具帝王风范，君临"
			       "天下，威镇诸路凶神恶煞、难道这就是传说中才"
			       "会出现的诸神之" + name() + HIY "？"NOR"\n";
		else
		if (attack_lvl >= LEVEL8)
			result = HIC "一眼望去，你觉得有无数的凶灵在疯狂"
			       "乱舞，哭天抢地，凄烈之极，似乎要重返"
			       "人间。你忍不住要长叹一声，昔日凶魔，也难逃死劫。"NOR"\n";
		else
		if (attack_lvl >= LEVEL7)
			result = HIC "它上面附着着不知多少凶魂，无数邪派"
			       "凶魔毙命于下，一股哀气犹然不散，让你"
			       "忍不住打了个冷战。"NOR"\n";
		else
		if (attack_lvl >= LEVEL6)
			result = HIR "它看上去令人惊心动魄，这就是名动江湖的" + name() + HIR
			       "，多少凶煞就此毙命，成就人间正义。"NOR"\n";
		else
		if (attack_lvl >= LEVEL5)
			result = HIR "它上面隐隐然透出一股血光，多年以来，许多"
			       "江湖上闻名一时的凶魔都成了" + name() + HIR "下的游魂。"NOR"\n";
		else
		if (attack_lvl >= LEVEL4)
			result = HIW "这就是江湖上著名的神兵之一：" + name() + HIW
			       "，穷凶极恶之徒见此物无不心驰神摇。"NOR"\n";
		else
		if (attack_lvl >= LEVEL3)
			result = HIW "这" + n + HIW "有一股正气散发出来，看来它下面凶魂不少。"NOR"\n";
		else
		if (attack_lvl >= LEVEL2)
			result = RED "这" + n + RED "隐然透出一股正气，"
			       "看来它杀了不少凶恶之徒。"NOR"\n";
		else
		if (attack_lvl >= LEVEL1)
			result = RED "细观之下，刃口有一丝血痕，想必是它杀人不少"
			       "，殷血于此吧！"NOR"\n";
		else
			result = CYN "看得出这" + n + CYN "曾经杀过不少凶恶之徒。"NOR"\n";
		break;

	case -1:
		if (attack_lvl >= ULTRA_LEVEL)
			result = HIR "它看上去平平常常，没有半点特殊，但是"
				 "不知为何却总是让人感到有些不安。"NOR"\n";
		else
		if (attack_lvl >= MAX_LEVEL)
			result = HIR "它看上去让人打心底泛出阵阵寒意，隐"
			       "隐然上面似乎附着着无数冤魂，但是全然被这" + n + HIR
			       "上面的杀气所制，难道这就是传说中才会出现的邪神之" + name() + HIR
			       "？"NOR"\n";
		else
		if (attack_lvl >= LEVEL8)
			result = HIC "一眼望去，你觉得有无数的冤魂向你扑"
			       "来，哭天抢地，凄烈之极，你忍不住打了"
			       "个寒战，不敢再看第二眼。"NOR"\n";
		else
		if (attack_lvl >= LEVEL7)
			result = HIC "它上面附着着不知多少冤魂，无数高手"
			       "饮恨于下，一股怨气直冲霄汉，让你忍不"
			       "住打了个冷战。"NOR"\n";
		else
		if (attack_lvl >= LEVEL6)
			result = HIW "它看上去令人惊心动魄，这就是名动江湖的" + name() + HIW
			       "，不知多少英雄就此饮恨。"NOR"\n";
		else
		if (attack_lvl >= LEVEL5)
			result = HIW "它上面隐隐然透出一股血光，多年以来，许多"
			       "江湖上闻名一时的高手都成了" + name() + HIW "下的游魂。"NOR"\n";
		else
		if (attack_lvl >= LEVEL4)
			result = HIG "这就是江湖上著名的凶器之一：" + name() + HIG
			       "，谁曾想那么多仁人义士饮恨于下。"NOR"\n";
		else
		if (attack_lvl >= LEVEL3)
			result = HIG "有一股戾气散发出来，看来它下面游魂不少。"NOR"\n";
		else
		if (attack_lvl >= LEVEL2)
			result = RED "隐然透出一股戾气，看来它杀了不少人。"NOR"\n";
		else
		if (attack_lvl >= LEVEL1)
			result = RED "细观之下，刃口有一丝血痕，想必是它杀人不少"
			       "，殷血于此吧！"NOR"\n";
		else
			result = CYN "看得出这" + n + CYN "曾经杀过不少侠义之士。"NOR"\n";
		break;

	default:
		if (attack_lvl >= ULTRA_LEVEL)
			result = HIC "它看上去平平常常，没有半点特殊，只是一件"
				 "平凡之极的兵器而已。"NOR"\n";
		else
		if (attack_lvl >= MAX_LEVEL)
			result = HIC "它安然畅意，似乎就要腾空而去，跳出"
			       "三界，不入五行。世间万物，仿佛俱在它"
			       "霸气所及之处。冤魂不舞、群邪辟易，无不被这" + n + HIC
			       "上古神兵的霸气所制。"NOR"\n";
		else
		if (attack_lvl >= LEVEL8)
			result = HIM "一眼望去，你觉得有无数的游魂向你扑"
			       "来，哭天抢地，凄烈之极，你顿时觉得它"
			       "沉重无比，几乎拿捏不住。"NOR"\n";
		else
		if (attack_lvl >= LEVEL7)
			result = HIM "它上面附着着不知多少游魂，无数正邪"
			       "高手丧命于下，一股怨气哀愁油然不尽，"
			       "让你忍不住打了个冷战。"NOR"\n";
		else
		if (attack_lvl >= LEVEL6)
			result = HIR "它看上去令人惊心动魄，这就是名动江湖的" + name() + HIR
			       "，多少正邪高手都难逃此劫，堕入轮回。"NOR"\n";
		else
		if (attack_lvl >= LEVEL5)
			result = HIR "它上面隐隐然透出一股血光，多年以来，许多"
			       "江湖上闻名一时的高手都成了这" + n + HIR "下的游魂。"NOR"\n";
		else
		if (attack_lvl >= LEVEL4)
			result = HIW "这就是江湖上著名的利器之一：" + name() + HIW
			       "，谁能想到那么多高手饮恨于下。"NOR"\n";
		else
		if (attack_lvl >= LEVEL3)
			result = HIW "这" + n + HIW "有一股杀气散发出来，看来它下面游魂不少。"NOR"\n";

		else
		if (attack_lvl >= LEVEL2)
			result = RED "这" + n + RED "隐然透出一股杀气，看来它杀了不少人。"NOR"\n";

		else
		if (attack_lvl >= LEVEL1)
			result = RED "细观之下，刃口有一丝血痕，想必是它杀人不少"
			       "，殷血于此吧！"NOR"\n";
		else
			result = CYN "看得出这" + n + CYN "曾经杀过不少人。"NOR"\n";
		break;
	}

	if (query("magic"))
	{
		result += HIY + name() + HIY "的等级：" + lvl + "/9"NOR"\n";
		if (stringp(tessera_name = query("magic/tessera")))
			result += "它上面镶嵌着" + tessera_name + "，闪烁着奇异的光芒。\n";
	} else
	if (lvl)
	{
		result += HIY + name() + HIY "的等级：" + lvl + "/9"NOR"\n";

		if (query("magic/imbue_ok"))
			result += HIM + name() + HIM "已经充分的浸入了，需要"
				  "镶嵌以充分发挥威力。"NOR"\n";
		else
		if ((n = query("magic/imbue")) > 0)
			result += HIM + name() + HIM "已经运用灵物浸入了" +
				  chinese_number(n) + "次，正在激发它的潜能。"NOR"\n";
	}

	return result;
}

// 是普通武器装备
int is_weapon()
{
	return stringp(query("skill_type"));
}

// 是空手武器装备
int is_unarmed_weapon()
{
	return query("armor_type") == "hands";
}

// 道具的长描述
string item_long()
{
	if (is_weapon() || is_unarmed_weapon())
		return weapon_long();

	return "";
}

// 武器装备的伤害值
int apply_damage()
{
	int d;
	int p;

	attack_lvl = weapon_level();
	p = query("point") / 2;
	d = attack_lvl * p / MAX_LEVEL;
	return d + p;
}

// 防御装备的有效值
int apply_armor()
{
	int d;
	int p;

	defense_lvl = armor_level();
	p = query("point");
	d = defense_lvl * p / MAX_LEVEL;
	return d + p;
}

// 进行保存数据的接口函数
mixed save_dbase_data()
{
	mapping data;
	object  user;

	data = ([ "combat" : query("combat"),
		  "owner"  : query("owner"),
		  "magic"  : query("magic"),
		  "kaiguang"  : query("kaiguang"),
		  "consistence" : query("consistence"), ]);

	if (! (user = environment()))
		data += ([ "user" : query("user") ]);
	else if (playerp(user))
		data += ([ "user" : user->name(1) + "(" + user->query("id") + ")" ]);

	return data;
}

// 接受存盘数据的接口函数
int receive_dbase_data(mixed data)
{
	if (! mapp(data))
		return 0;

	if (mapp(data["combat"]))
		set("combat", data["combat"]);

	if (mapp(data["owner"]))
		set("owner", data["owner"]);

	if (mapp(data["magic"]))
		set("magic", data["magic"]);

	if (stringp(data["kaiguang"]))
		set("kaiguang", data["kaiguang"]);

	if (stringp(data["user"]))
		set("user", data["user"]);

	if (! undefinedp(data["consistence"]))
		set("consistence", data["consistence"]);

	return 1;
}

// 读取存盘的数据
int restore()
{
	int r;

	if (base_name(this_object()) + ".c" == __FILE__)
		return 0;

	r = ::restore();
	set("no_sell", 1);
	return r;
}

// 保存数据
int save()
{
	int res;

	if (base_name(this_object()) + ".c" == __FILE__)
		return 0;

	return ::save();
}

// 魔法效果攻击对手
mixed weapon_hit_ob(object me, object victim,int damage_bonus)
{
	if (attack_lvl < MAX_LEVEL)
		return;

	if (query("magic/power")&&time()-this_object()->query_temp("use_times")>6	)
	{
		remove_call_out("shibing");
		call_out("shibing",0,me,victim);
		this_object()->set_temp("use_times",time());
		return ;
	}
	else if(attack_lvl==MAX_LEVEL&&time()-this_object()->query_temp("use_times")>8)
	{
		remove_call_out("jiubing");
		call_out("jiubing",0,me,victim);
		this_object()->set_temp("use_times",time());
		return ;
	}
}

//装备十甲
mixed valid_damage(object ob, object me, int damage, object weapon)
{
	if (defense_lvl < MAX_LEVEL)
	return;
	if (item_owner() != me->query("id"))
	return;
	if (query("magic/power"))
	{
		return ITEM_D->valid_damages(ob,me,damage,weapon);
	}
}




private mixed target_baoshi(object ob)
{
	object sbt;
	string bs1,bs2;//,name1,name2;
	int pd1,pd2,tmp;

	if(objectp(sbt=ob->query_temp("weapon"))&&sbt->query("equipped")=="wielded")
		(string)bs1=sbt->query("magic/type");
		pd1=stringp(bs1)?1:0;
	if(objectp(sbt=ob->query_temp("armor/hands"))&&sbt->query("equipped")=="worn")
		(string)bs2=sbt->query("magic/type");
		pd2=stringp(bs2)?1:0;
	tmp=pd1+pd2;
	switch(tmp){
		case 0 : return "";
		case 2 : return bs1;
		case 1 : return (pd1>pd2)?bs1:bs2;
	}
}
//宝石克制系数
/*水克火/土克水/木克土/金克木/火克金，受到伤害减益最大
土遇火；木遇水；金遇土；金遇水，受到伤害有少许减益
*/
private mixed kz_xs(object me,object target)
{

	//object *enemy;
	string a,b;
	int aa,bb,i,judge;
	string *bsxh = ({
		"fire",//火-炎帝0
		"cold",//水-黑帝1
		"all",//土-黄帝2
		"magic",//木-青帝3
		"lighting"//金-白帝4
	});//无宝石时m_array返回-1
if(!target) return;

if( me->is_fighting() )
{
	a=target_baoshi(me);
	b=target_baoshi(target);
	aa=member_array(a,bsxh);
	bb=member_array(b,bsxh);
	if(aa>=0&&bb>=0)
	{
	judge=(bb<aa)?(aa-bb):(bb-aa);
	switch(judge){
		case 0:	return 100-random(10);
		case 1:	return (random(4)==2)?60:60+random(40)/2;
		case -4:return (random(4)==2)?60:60+random(40)/2;//黑克炎；黄克黑；青克黄；白克青；炎克白
		case 2:	return (random(3)==2)?70:70+random(30)/3;//黄克炎；青克黑；白克黄
		case 3:	return (random(2)==1)?90:90+random(10);}//青克炎；白克黑；后者对前者有克制}
	}
	else
	return 100;

}
}



void shibing(object me, object target)
{

    int ap,dp,damage,dam_bing;
	string msg,ob,value;
	int kzxs,kzxs_op;
	//object op;
	mapping eyes=(["fire":"炎帝宝石",
	"all":"黄帝宝石",
	"lighting":"白帝宝石",
	"cold":"黑帝宝石",
	"magic":"青帝宝石",]);


	if(!target) return;
	if (this_object()->query("equipped")!="worn"&&!me->query_temp("weapon"))
	return;

	if( me->is_fighting())
    {
		if( ! present( target,environment(me)) ) return;
        msg = HIR"\n"NOR;
		ap = me->query_skill("sword-cognize",1)+me->query_skill("martial-cognize",1);
		dp = target->query_skill("sword-cognize",1)+target->query_skill("martial-cognize",1);
		if(dp<1){dp=1;}
		dam_bing = this_object()->query("point");
		ob=target_baoshi(target);
		value=eyes[ob];
		kzxs = kz_xs(me,target);
		kzxs_op = 100-kzxs;

		if( random(dp) < ap ){
	
            damage = me->query_skill("tiangang-bati",1)+me->query_skill("wanjian-guizong",1)+me->query_skill("yinyang-jiuzhuan",1)+me->query_skill("rulai-shenzhang",1)+me->query_skill("yuan-blade",1)+me->query_skill("zuixian-wangyue",1)+me->query_skill("lieyan-jue",1)+me->query_skill("ruijin-jue",1)+me->query_skill("chunyang-jue",1);       
			damage = ap/2+random(ap*ap/dp)*kzxs/100*random(2); 

		if( damage > 0 )
			{

					if(this_object()->query("magic/type")=="fire")//火--伤气+吸内
					{
						if(random(6)==1)
						{
							if(random(2)==1)
							{
								msg += HIR "一道火光从" + this_object()->name() + HIR"上迸出，迅捷无伦的击中$n" HIR "，令人避无可避！\n" NOR;
							}
							else
							{
								msg += HIR ""+ this_object()->name()+ HIR"暴出漫天通红的火球直击而来，$n" HIR" 被置身一片火海，惨叫连连。\n" NOR;
							}

							if(kzxs_op>0)
							msg += HIR "却被$n武器上的"+  value +HIR"克制，$n受到伤害减弱"+ kzxs_op +HIC"%!\n"NOR;
							target->receive_damage("qi", damage+random(3)*dam_bing, me);
							target->receive_wound("qi", damage*2/3, me);//提高伤气
						}
						else if(random(6)==2)
						{
							if(random(2)==1)
							{
								msg += HIR "忽然间" + this_object()->name() + HIR"变得透体通红，$n" HIR "的内力以肉眼可见的速度在快速流失。\n" NOR;
							}
								else
								{
								msg += HIR "一道通红的火光从" + this_object()->name() + HIR "上迸出扩散开来，正中$n"HIR "的真气汇聚之所-丹田。\n" NOR;
								}
							if(kzxs_op>0)
								msg += HIR "$n的武器对此并无任何" +HIR"克制，$n受到最大伤害！！"+HIC"%!\n" NOR;

							if( target->query("neili")>damage )//减内加内有效
							{
								target->add("neili", -damage*dp/ap);
								me->add("neili", damage*dp/ap/2);

								if(target->query("neili")<0)
									target->set("neili",0);

								if(me->query("neili")>me->query("max_neili")*2)
									me->set("neili",me->query("max_neili")*2);
							}
						}
						else if(random(6)==3)
						{
							if (!me->query_temp("weapon_performing")&&!me->query_condition("bingtx"))
							{
								//msg += HIC "$N" HIC "要发动连招了。"NOR"\n";
								remove_call_out("continue_attack");
								call_out("continue_attack",0,me,target);
								me->apply_condition("bingtx", 3);
							}
						}


					}
					else if(this_object()->query("magic/type")=="lighting")//金-伤气+BUSY
					{
						if(random(6)==1)
						{
							if(random(2)==1)
								{
									msg += HIW""+this_object()->name()+HIW"喷出一团炽白的光球，直奔$n" HIW "而去，$n" HIW "被打了个正着。\n" NOR;
								}
							else
							{
								msg += HIW""+this_object()->name()+HIW"暴出漫天夹杂响雷的闪电直击而来，$n"HIW "被闪电悉数直穿身体而过。\n" NOR;
							}

								if(kzxs_op>0)
									//msg += HIW "$n的武器对此并无任何" +HIW"克制，$n受到最大伤害！！"+HIR"%!\n" NOR;
									msg += HIW "却被$n武器上的"+ value+HIW"克制，$n受到伤害减弱"+kzxs_op+HIR"%!\n" NOR;


							target->receive_damage("qi", damage+random(3)*dam_bing, me);
							target->receive_wound("qi", damage*2/3, me);
						}
						else if(random(6)==2)
						{
							if(random(2)==1)
							msg += HIW "天际隐隐响起几声闷雷，一道霹雳直下，" + this_object()->name() + HIW "忽明忽暗，震得$n"HIW "酸软无力。\n" NOR;
							else
							msg += HIW ""+ this_object()->name() + HIW "迸发出几道明亮的闪光，兹兹作响，让$n" HIW "不由为之酥麻。\n" NOR;
							if(kzxs_op>0){
								//case 0: msg += HIW "$n的武器对此并无任何" +HIW"克制，$n受到最大伤害！！"+HIR"%!\n" NOR;
								 msg +=HIW "却被$n武器上的"+  value+HIW"克制，$n受到伤害减弱"+kzxs_op+HIR"%!\n" NOR;
											}

							if(ap/dp>1)
							 target->start_busy(random(10));
							 else
							target->start_busy(ap/dp*random(10));
						}
						else if(random(6)==3)
						{
							if (!me->query_temp("weapon_performing")&&!me->query_condition("bingtx"))
							{
							//msg += HIC "$N" HIC "要发动连招了。"NOR"\n";
							remove_call_out("continue_attack");
							call_out("continue_attack",0,me,target);
							me->apply_condition("bingtx", 3);
							}
						}




					}
					else if(this_object()->query("magic/type")=="cold")//水-伤精+BUSY
					{

						if(random(6)==1)
						{
							if(random(2)==1)
								msg += HIC+this_object()->name()+HIC"暴出漫天冰锥直射而来，$n"HIC "转眼间心神受创，依然魂飞魄散。\n" NOR;
							else
								msg += HIC "忽然间" +this_object()->name() + HIC "变得透体通蓝，一道道冰冷的寒光迸发出来，$n" HIC "天灵只是一冷。\n" NOR;
								if(kzxs_op>0){
									//case 0:msg += HIR "$n的武器对此并无任何" +HIR"克制，$n受到最大伤害！！"+HIC"%!\n" NOR;
									msg +=HIC "却被$n武器上的"+ value+HIC"克制，$n受到伤害减弱"+kzxs_op+HIC"%!\n" NOR;
								}
							target->receive_damage("jing", damage/2, me);
							target->receive_wound("jing", damage/4, me);
						}
						else if(random(6)==2)
							{
								if(random(2)==1)
									msg += HIC "忽然间" + this_object()->name() + HIC"变得透体通蓝，一面淡蓝的冰墙把$n"HIC "冰封在了里面。\n" NOR;
								else
									msg += HIC "一道光圈由" + this_object()->name() + HIC "射出，""森然盘旋在$n" HIC "四周，悄然无息。\n" NOR;

									if(ap/dp>1)
									target->start_busy(random(10));
									else
									target->start_busy(ap/dp*random(10));
							}
						else if(random(6)==3)
						{
							if (!me->query_temp("weapon_performing")&&!me->query_condition("bingtx"))
							{
								//msg += HIC "$N" HIC "要发动连招了。"NOR"\n";
								remove_call_out("continue_attack");
								call_out("continue_attack",0,me,target);
								me->apply_condition("bingtx", 3);
							}
						}



					}
					else if(this_object()->query("magic/type")=="magic")//木-吸内+BUSY
					{

						if(random(6)==1)
						{
							if(random(2)==1)
								msg += HIG+ this_object()->name() + HIG"蓦的冒出几丝略带清香的白烟飘然而过，$n"HIG "顿时内力消散。\n" NOR;
							else
								msg += HIG"霎时间"HIG+ this_object()->name()+HIG"之影暴长 ，似乎变幻出无数枝干，将$n"HIG "紧紧抓住，吸取真气。\n" NOR;
								if(kzxs_op>0){
									//case 0:msg += HIG "$n的武器对此并无任何" +HIG"克制，$n受到最大伤害！！"+HIR"%!\n" NOR;
									msg +=HIG "却被$n武器上的"+  value+HIG"克制，$n受到伤害减弱"+kzxs_op+HIR"%!\n" NOR;}
							if( target->query("neili")>damage )//减内加内有效
							{
								target->add("neili", -damage*dp/ap);
								me->add("neili", damage*dp/ap/2);

								if(target->query("neili")<0)
									target->set("neili",0);

								if(me->query("neili")>me->query("max_neili")*2)
									me->set("neili",me->query("max_neili")*2);
							}
						}
						else if(random(6)==2)
						{
							if(random(2)==1)
								msg += HIG+ this_object()->name()+HIG"在$n"HIC"周身盘旋，将$n"HIG"带入翡翠梦境，令$n"HIG"迷失不已。\n" NOR;
							else
								msg += HIG + this_object()->name()+HIG"闪出无数条亮影，如枯木回春般蔓延了$n"HIG"全身，令$n"HIG"动弹不得。\n" NOR;

								if(ap/dp>1)
								target->start_busy(random(10));
								else
								target->start_busy(ap/dp*random(10)+1);
						}
						else if(random(6)==3)
						{
							if (!me->query_temp("weapon_performing")&&!me->query_condition("bingtx"))
							{
								//msg += HIC "$N" HIC "要发动连招了。"NOR"\n";
								remove_call_out("continue_attack");
								call_out("continue_attack",0,me,target);
								me->apply_condition("bingtx", 3);
							}
						}
					}
					else //土-伤精+伤气
					{

						if(random(6)==1)
						{
							if(random(2)==1)
								msg += YEL + this_object()->name()+ YEL"夹杂土石之缘，带动山石之雨，震天怒响击向$n。 \n"NOR;
							else
								msg +=  YEL + this_object()->name()+ YEL"汲取大地灵气，向$n发起攻击，只见飞沙走石。\n" NOR;
								if(kzxs_op>0)
								{
									//case 0: msg += YEL "$n的武器对此并无任何" +YEL"克制，$n受到最大伤害！！"+HIR"%!\n" NOR;
								 msg += YEL"却被$n武器上的"+  value+YEL"克制，$n受到伤害减弱"+kzxs_op+HIR"%!\n" NOR;
								}

								target->receive_damage("qi", damage+random(3)*dam_bing, me);
								target->receive_wound("qi", damage*2/3, me);//提高伤气
						}
						else if(random(6)==2)
						{
							if(random(2)==1)
								msg += YEL + this_object()->name()+ YEL"突然颤抖，音声低沉凝重，引山摇地动之式，$n"YEL"以不能自已！\n" NOR;
							else
								msg += HIY  + this_object()->name()+HIY"响起一阵奇异的声音，犹如地龙咆哮，令$n"HIY "心神不定，神情恍惚。\n" NOR;
								if(kzxs_op>0){
									//case 0:msg += HIY"$n的武器对此并无任何" +HIY"克制，$n受到最大伤害！！"+HIR"%!\n" NOR;
									msg += HIY "却被$n武器上的"+ value +HIY"克制，$n受到伤害减弱"+kzxs_op+HIR"%!\n" NOR;}
							target->receive_damage("jing", damage/2, me);
							target->receive_wound("jing", damage/4, me);
						}
						else if(random(6)==3)
						{
							if (!me->query_temp("weapon_performing")&&!me->query_condition("bingtx"))
							{
								//msg += HIC "$N" HIC "要发动连招了。"NOR"\n";
								remove_call_out("continue_attack");
								call_out("continue_attack",0,me,target);
								me->apply_condition("bingtx", 3);
							}
						}
					}

				}
		   }
			else
    	msg += "但是被$n躲开了。\n";
		message_vision(msg, me, target);
		}

	call_out("shibing",6,me,target);
	}

//void jiubing(object me,object target, object weapon, int damage_bonus)
void jiubing(object me,object target)
{
    int ap,dp,dam,damage;
    string msg;

	if(!target) return;

	if (this_object()->query("equipped")!="worn"&&!me->query_temp("weapon"))
		return;

	// if(me->query("quest/id"))
		// return;

	if(me->is_fighting())
    {
        //target = offensive_target(me);
        //if( target->query("die_give2") ) return ;

		if(!present(target,environment(me))) return ;

        msg = HIR"\n"NOR;
		ap = me->query_skill("sword-cognize",1)+me->query_skill("martial-cognize",1);
		dp = target->query_skill("sword-cognize",1)+target->query_skill("martial-cognize",1);
		//dam = me->query("apply_damage")

		if(random(dp) < ap)
		{
			damage = ap/2+random(ap*2/3);   //将伤害与二者的修养对比联系起来

			if( damage > 0 )
			{
				if(random(8)==0)
				{
					msg += HIY "$N" HIY "抖动" + this_object()->name() + HIY "，幻化成夜空流星，数道" HIM "紫芒" HIY "破空袭向$n"HIY "，光华夺目，令人目眩！"NOR"\n";
					target->receive_damage("jing", damage/3, me);
					target->receive_wound("jing", damage/6, me);
				}
				else if(random(8)==1)
				{
					msg += HIR "$N" HIR "大喝一声，" + this_object()->name() + HIR "遥指$n" HIR "，一道杀气登时将$n" HIR "震得连连吐血。"NOR"\n";
					target->receive_damage("qi", damage, me);
					target->receive_wound("qi", damage/2, me);
				}
				else if(random(8)==2)
				{
					 msg += HIC "$N" HIC "暗运内劲，" + this_object()->name() + HIC "化为无数柔丝将$n" HIC "裹住，$n" HIC "束手束脚，动作迟缓。"NOR"\n";
					 target->start_busy(ap/60);
				}
				else if(random(8)==3)
				{
					if (!me->query_temp("weapon_performing")&&!me->query_condition("bingtx"))
					{
						//msg += HIC "$N" HIC "要发动连招了。"NOR"\n";
						remove_call_out("continue_attack");
						call_out("continue_attack",0,me,target);
						me->apply_condition("bingtx", 4);
					}
				}
			}
			else
                msg += HIC "\n谁知$n毫无反应。\n" NOR;
		}
        else
			msg += "但是被$n躲开了。\n";

		message_vision(msg, me, target);
	}

	call_out("jiubing",8,me,target);
}

// 绝招：连环攻击
void continue_attack(object me,object target)
{
	int i;
	string msg="";
	int ap, dp,times;

	if( ! target ) return ;

	if(attack_lvl==MAX_LEVEL)
	times=3+random(5);//三到七连
	else
	times=5+random(6);//五到十连


	if( me->is_fighting())
     {
        //target = offensive_target(me);

		if( ! present( target,environment(me)) ) return ;

		if (me->query("character") == "光明磊落")//黄HIY
		{
		msg  = HIY "\n$N" HIY "说道，你要战便作战。一声长笑，人与" + this_object()->name() +
			   HIY "合二为一，飞也似的扑向$n" HIY "！"NOR"\n";
		}
		else
		if (me->query("character") == "狡黠多变")//青HIC
		{
		msg  = HIC "\n$N" HIC "对$n"HIC"说道：“看你身后！”声东击西计策成功，$N"HIC"人与" + this_object()->name() +
			   HIC "合而为一，趁机向$n" HIC "攻去！"NOR"\n";
		}
		else
		if (me->query("character") == "心狠手辣")//HIR
		{
		msg  = HIR "\n$N" HIR "大吼一声，拼了！使出杀招，狠狠地向$n扑去，人与" + this_object()->name() +
			   HIR "合二为一" HIR "！"NOR"\n";
		}
		else
		if (me->query("character") == "阴险奸诈")//HIG
		{
		msg  = HIG "\n$N" HIG "道：不打了，你真厉害。趁$n放松警惕之时，人与" + this_object()->name() +
			   HIG "合二为一，从背后向$n" HIG "扑去！"NOR"\n";
		}

		ap = me->query_skill("sword-cognize",1)+me->query_skill("martial-cognize",1);
		dp = target->query_skill("sword-cognize",1)+target->query_skill("martial-cognize",1);

		if (ap / 2 + random(ap) > dp)
			msg += HIR "$n" HIR "大骇之下慌忙后退，却哪里躲避得开？一时不禁破绽迭出！\n"
				   HIY "$N" HIY "抓住$n" HIY "露出的破绽，急挥" +
				   this_object()->name() + HIY "，连续" + chinese_number(times) +
				   "招全部罩向$n" HIY "的要害！"NOR"\n";
		else
		{
			msg += HIC "$n" HIC "冥神抵挡，将$N" HIC "这必杀一击的所有变化全然封住！"NOR"\n";
			message_combatd(msg, me, target);
			return;
		}

		message_combatd(msg, me, target);

		me->set_temp("weapon_performing", 1);
		i = times;

		while (i--)
		{
			if (! me->is_fighting(target)) break;
			if (! living(target)) break;

			if (! target->is_busy() && random(2))
				target->start_busy(1);


			if(me->query_temp("weapon"))
			{
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"),0);
			}
			else
			{
			COMBAT_D->do_attack(me, target, 0, 0);
			}
		}

	me->delete_temp("weapon_performing");
    }
}





// 以下的函数因为执行的频度并不高，而且具有高度重复的性质，
// 所以都调用ITEM_D中的执行程序。

// 杀了人以后的奖励
void killer_reward(object me, object victim)
{
	ITEM_D->killer_reward(me, victim, this_object());
}

// 呼唤物品
int receive_summon(object me)
{
	return ITEM_D->receive_summon(me, this_object());
}

// 隐藏物品
int hide_anywhere(object me)
{
	return ITEM_D->hide_anywhere(me, this_object());
}

// 追寻物品
int receive_miss(object me)
{
	if (! is_weapon() && ! is_unarmed_weapon())
	{
		write("你无法追寻" + name() + "。\n");
		return 0;
	}

	if (attack_lvl < ULTRA_LEVEL)
	{
		write(name() + "尚未通灵，你难以自如的感应。\n");
		return 0;
	}

	return ITEM_D->receive_miss(me, this_object());
}

// 插在地上
int do_stab(object me)
{
	return ITEM_D->do_stab(me, this_object());
}

// 特殊能力
int do_touch(object me)
{
	if (attack_lvl != ULTRA_LEVEL)
		return notify_fail("你摸了半天，好像没什么反应。\n");

	return ITEM_D->do_touch(me, this_object());
}

// 圣化
int do_san(object me)
{
//	if ((is_weapon() || is_unarmed_weapon()) && attack_lvl < MAX_LEVEL)
//		return notify_fail("你的武器等级不到，无法圣化。\n");

	return ITEM_D->do_san(me, this_object());
}

// 浸透物品
int do_imbue(object me)
{
	return ITEM_D->do_imbue(me, this_object());
}

// 镶嵌物品
int do_enchase(object me, object tessera)
{
	return ITEM_D->do_enchase(me, this_object(), tessera);
}

// 强化物品
int do_enhance(object me, object tessera)
{
	return ITEM_D->do_enhance(me, this_object(), tessera);
}

int query_autoload() 
{
		//if(query("skill_type")== "throwing") return;
	 return (query("equipped") ? query("equipped") : "kept"); 
}


void autoload(string parameter)
{
	//if(query("skill_type")== "throwing") return;
	switch (parameter)
	{
	case "worn":
		this_object()->wear();
		break;

	case "wielded":
		this_object()->wield();
		break;
	}
}


void owner_death_penalty()
{
	object item = this_object();

	if (item->add("consistence", -20) < 0)
	{
		item->set("consistence", 0);
		if (environment(item))
			tell_object(environment(item), HIG "你的" + item->name() + "已经彻底损坏了。\n");
		item->unequip();
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
