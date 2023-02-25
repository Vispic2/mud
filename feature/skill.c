// skill.c
#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;
mapping wprepare;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }
varargs void map_skill(string skill, string mapped_to);

void clear_all_skill()
{
	skills = ([]);
	learned = ([]);
	skill_map = ([]);
	skill_prepare = ([]);
	wprepare = ([]);
}

void set_skill(string skill, int val)
{
	if (! find_object(SKILL_D(skill)) &&
	    file_size(SKILL_D(skill)+".c") < 0)
		error("F_SKILL: No such skill (" + skill + ")\n");

	if (! mapp(skills)) skills = ([ skill: val ]);
	else skills[skill] = val;
}

void add_skill(string skill, int val)
{
    int i;
	if (! find_object(SKILL_D(skill)) &&file_size(SKILL_D(skill)+".c") < 0)
	error("F_SKILL: No such skill (" + skill + ")\n");	
    i=this_object()->query_skill(skill,1)+val;    
	if (! mapp(skills)) skills = ([ skill: i ]);
	else skills[skill] = i;		
}

int delete_skill(string skill)
{
	int i;
	string *sk;

	if (mapp(skill_map))
	{
		map_delete(skill_map, skill);
		sk = keys(skill_map);
		for (i = 0; i < sizeof(sk); i++)
		{
			if (skill_map[sk[i]] == skill)
				map_skill(sk[i], 0);
		}
	}

	if (mapp(skills))
	{
		map_delete(skills, skill);
		if (mapp(learned))
		{
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if (! mapped_to && mapp(skill_map))
	{
		if ( skill_prepare ) map_delete(skill_prepare, skill);
		map_delete(skill_map, skill);
		return;
	}

	if (! find_object(SKILL_D(skill)) &&
	    file_size(SKILL_D(skill)+".c") < 0 )
	    error("F_SKILL: No such skill (" + skill + ")\n");

	if (! mapp(skills) || undefinedp(skills[mapped_to]))
		return;
		
	if (skill_prepare) map_delete(skill_prepare, skill);
	if (! mapp(skill_map)) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
	if (! mapped_to && mapp(skill_prepare))
	{
		map_delete(skill_prepare, skill);
		return;
	}

	if (! find_object(SKILL_D(skill)) &&
	    file_size(SKILL_D(skill)+".c") < 0)
		error("F_SKILL: No such skill (" + skill + ")\n");

	if (! mapp(skills) || undefinedp(skills[mapped_to]))
		return;
		
	if (! mapp(skill_prepare)) skill_prepare = ([ skill: mapped_to ]);
	else skill_prepare[skill] = mapped_to;
}

varargs void prepare_wskill(string skill, string mapped_to)
{
	if (! mapped_to && mapp(wprepare))
	{
		map_delete(wprepare, skill);
		return;
	}

	if (! find_object(SKILL_D(skill)) &&
	    file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if (! mapp(skills) || undefinedp(skills[mapped_to]))
		return;
		
	if (! mapp(wprepare)) wprepare = ([ skill: mapped_to ]);
	else wprepare[skill] = mapped_to;
}


string query_skill_mapped(string skill)
{
	if (mapp(skill_map) && ! undefinedp(skill_map[skill]))
		return skill_map[skill];
	return 0;
}

string query_skill_prepared(string skill)
{
	if (mapp(skill_prepare) && !undefinedp(skill_prepare[skill]))
		return skill_prepare[skill];
	return 0;
}

string query_wprepared(string skill)
{
	if (mapp(wprepare) && !undefinedp(wprepare[skill]))
		return wprepare[skill];
	return 0;
}

varargs int query_skill(string skill, int raw)
{
    int num=0,mer=0,forces=0,parrys=0,dodges=0;
	forces=query_temp("shijia/forces");
	parrys=query_temp("shijia/parrys");
	dodges=query_temp("shijia/dodges");
	
    num=query_temp("suit_skill/"+skill);   //套装技能
	if(stringp(query("meridian/ap"))&&skill==query("meridian/ap"))
	mer = query("gain/attack");
	else if(stringp(query("meridian/dp"))&&skill==query("meridian/dp"))
	mer = query("gain/defense");
	if (! raw)
	{
		int s;
		s = query_temp("apply/" + skill);
		s += query_temp("apply/dodge",dodges);
		s += query_temp("apply/force",forces);
		s += query_temp("apply/parry",parrys);		
		
		if (mapp(skills))
		{
			s += skills[skill]+mer+num / 2;
			if (mapp(skill_map))
				s += skills[skill_map[skill]];
		}
		return s;
	}
	if (mapp(skills) && ! undefinedp(skills[skill]))
		return skills[skill];
	return 0;
}


mapping query_skill_map()
{
	return skill_map;
}

mapping query_skill_prepare()
{
	return skill_prepare;
}

mapping query_wprepare()
{
       return wprepare;  
}

int skill_death_penalty()
{
	string *sk;
	int i,j;

	if (wizardp(this_object()) || ! mapp(skills)) return 0;
	if (this_object()->query("combat_exp")<337500) return 0;

	sk = keys(skills);

	if (!mapp(learned)) learned = ([ ]);
	for(i = 0; i<sizeof(sk); i++)
	{
//		if(SKILL_D(sk[i])->type()=="knowledge") continue;
		j = skills[sk[i]] + 1;
		learned[sk[i]] -= (j*j+1)/5;
		if (learned[sk[i]] < 0) {
			j = skills[sk[i]];
			skills[sk[i]]--;
			learned[sk[i]] += (j*j+1);
		}
		if (j <= 1 ) {
			map_delete(skills,sk[i]);
			map_delete(learned,sk[i]);
		}
	}
	skill_map = 0;
	skill_prepare = 0;

	return 1;
}

int skill_expell_penalty()
{
	int i;
	string *skname;

	if (! mapp(skills)) 
	return 1;

	skname = keys(skills);
	for (i = 0; i < sizeof(skname); i++)
	{
		if (file_size(SKILL_D(skname[i]) + ".c") < 0)
		{
			delete_skill(skname[i]);
			continue;
		}

		if (SKILL_D(skname[i])->type() != "martial" ||
		    skname[i] == "martial-cognize")
			continue;

		if (SKILL_D(skname[i])->valid_enable("parry") ||
	    	    SKILL_D(skname[i])->valid_enable("dodge") ||
	    	    SKILL_D(skname[i])->valid_enable("throwing") ||
	    	    SKILL_D(skname[i])->valid_enable("force"))
		{
			delete_skill(skname[i]);
			continue;
		}

		if (query_skill(skname[i], 1) >= 100)
			set_skill(skname[i], 100);
    	}

    	skill_map = 0;
    	skill_prepare = 0;
}

int can_improve_skill(string skill)
{
	int lvl;
	int exp;

	if (! find_object(SKILL_D(skill)) &&
	    file_size(SKILL_D(skill)+".c") < 0)
		error("F_SKILL: No such skill (" + skill + ")\n");

	switch (SKILL_D(skill)->type())
	{
	case "knowledge":
		// 知识类技能
		return 1;

	case "technic":
		// 技术类技能
		return 1;

	case "martial":
	case "poison":
		lvl = query_skill(skill, 1);
		exp = this_object()->query("combat_exp");
		if (lvl * lvl * lvl / 10 > exp)
			return 0;
		return 1;

	default:
		return 1;
	}
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi;
	int lvl,lvl_name;
	int mlvl;
	string type;

	if (! find_object(SKILL_D(skill)) &&file_size(SKILL_D(skill)+".c") < 0)
	error("F_SKILL: No such skill (" + skill + ")\n");
	if (! mapp(skills)) skills = ([]);
	if (undefinedp(skills[skill])) skills[skill] = 0;
	type = SKILL_D(skill)->type();

	switch (type)
	{
	case "martial":
	if (intp(mlvl = skills["martial-cognize"]) &&skill != "martial-cognize")
	// martial-cognize does extra bonus for martial skills
	amount += amount * mlvl / 500;
	break;

	case "knowledge":
		if (intp(mlvl = skills["culture-cognize"]) &&skill != "culture-cognize")
			// culture-cognize does extra bonus for culture skills
			amount += amount * mlvl / 500;
		break;

	case "technic":
		if (intp(mlvl = skills["technic-cognize"]) && skill != "technic-cognize")
			// culture-cognize does extra bonus for culture skills
			amount += amount * mlvl / 500;
		break;
	}

	// adjust the point improved
	lvl = skills[skill];
	amount = 1 + amount * 100 / (lvl + 100);
	if (! mapp(learned)) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if ((! weak_mode || !userp(this_object())) && learned[skill] > (skills[skill] + 1) * (skills[skill] + 1))
	{
		skills[skill]++;
		learned[skill] = 0;
		printf("\n");	    
		tell_object(this_object(), HIR"恭喜："+NOR" 你的"+HIY+"「" +to_chinese(skill)+ "」"+NOR"进步了！\n");
    //    tell_object(find_player("name"),"执行结果："+learned[skill]+"===="+skills[skill]+"\n");
		lvl_name=(int)this_object()->query_skill(skill,1);
		if(SKILL_D(skill)->query_skill_up(lvl_name))
		{
			if (lvl_name==1)
			{
				tell_object(this_object(), HIR"恭喜："+NOR" 你从"+HIY+"「" +to_chinese(skill)+ "」"+NOR+"中领悟了"+HIY+"「" +to_chinese(SKILL_D(skill)->query_skill_up(0))+ "」"+NOR+"的招式。\n");
			}
			else if(SKILL_D(skill)->query_skill_up(lvl_name)!="no")
			{       
				tell_object(this_object(), HIR"恭喜："+NOR" 你从"+HIY+"「" +to_chinese(skill)+ "」"+NOR+"中领悟了"+HIY+"「" +to_chinese(SKILL_D(skill)->query_skill_up(lvl_name))+ "」"+NOR+"的招式。\n");
			}
		}
		printf("\n");
		SKILL_D(skill)->skill_improved(this_object());
	}
}
/*

varargs int query_skill(string skill, int raw)
{
	string myclass;
	int xiuyang;
	object weapon;
	int num=0,mer=0,xishu=100;//命中系数100为不变，110为增加10%
	int kxiu,bxiu;
	int ng;
	int viplvl;
	int forces=0,parrys=0,dodges=0;
	forces=query_temp("shijia/forces");
	parrys=query_temp("shijia/parrys");
	dodges=query_temp("shijia/dodges");
	
	num=query_temp("suit_skill/"+skill);   //套装技能
	if(stringp(query("meridian/ap"))&&query("meridian/ap")=="kongshou"&&skill==query("kongxiu"))
	mer = query("gain/attack");
	else
	if(stringp(query("meridian/ap"))&&query("meridian/ap")=="bingqi"&&skill==query("bingxiu"))
	mer = query("gain/attack");
	else if(stringp(query("meridian/dp"))&&skill==query("meridian/dp"))
	mer = query("gain/defense");

	
	
	if (! raw)
	{
		int s;
		s = query_temp("apply/" + skill);
		s += query_temp("apply/dodge",dodges);
		s += query_temp("apply/force",forces);
		s += query_temp("apply/parry",parrys);		
				
		s += query_temp("apply/skills");
		if(skill==query("kongxiu"))
		s +=kxiu;
		else 
		if(skill==query("bingxiu"))
		s +=bxiu;	
		xiuyang=query("xiuyang");
		myclass=query("family/family_name");
		
		if(myclass)
	{	weapon = query_temp("weapon");	
		if(myclass=="少林派")
		{
		 if( query_skill_mapped("force") == "hunyuan-yiqi"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("con");
		 if( query_skill_mapped("dodge") == "shaolin-shenfa"&&skill=="dodge" )
		 		s+=query_skill("hunyuan-yiqi",1)/10;
		 if( query_skill_mapped("sword") == "damo-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=query_skill("hunyuan-yiqi",1)/10+query("con");  	
		 if( query_skill_mapped("whip") == "riyue-bian"&&skill=="whip" &&objectp(weapon)&&(string)weapon->query("skill_type") == "whip")
		 		s+=query_skill("hunyuan-yiqi",1)/10+query("con");     
		 if( query_skill_mapped("strike") == "yipai-liangsan"&&query_skill_prepared("strike") == "yipai-liangsan" &&(skill=="force"||skill=="strike" ))
		 		s+=query_skill("hunyuan-yiqi",1)/10+query("con");      			 	
		}	
		if(myclass=="武当派")
		{
		 if( query_skill_mapped("force") == "taiji-shengong"&&skill=="dodge" )
		 		s+=query_skill("force")/5+query("con")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "tiyunzong"&&skill=="dodge" )
		 		s+=query_skill("taiji-shengong",1)/10+xiuyang/10; 			
		 if( query_skill_mapped("sword") == "taiji-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=query_skill("taiji-shengong",1)/10+xiuyang/10+query("con");  	
		 if( query_skill_mapped("unarmed") == "taiji-quan"&&query_skill_prepared("unarmed") == "taiji-quan" &&skill=="parry")
		 		s+=query_skill("taiji-shengong",1)/10+xiuyang/10+query("con"); 	
		}		
		if(myclass=="峨嵋派")
		{
		 if( query_skill_mapped("force") == "linji-zhuang"&&skill=="parry" )
		 		s+=query_skill("force")/5+query("con")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "zhutian-bu"&&skill=="dodge" )
		 		s+=query_skill("linji-zhuang",1)/10+xiuyang/10; 			
		 if( query_skill_mapped("sword") == "huifeng-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=query_skill("linji-zhuang",1)/10+xiuyang/10+query("con");  	
		 if( query_skill_mapped("strike") == "piaoxue-zhang"&&query_skill_prepared("strike") == "piaoxue-zhang" &&(skill=="strike"||skill=="force"))
		 		s+=query_skill("linji-zhuang",1)/10+xiuyang/10+query("str"); 	
		}			
		if(myclass=="华山剑宗")
		{ng=query_skill("huashan-xinfa",1);
		 if( query_skill_mapped("force") == "huashan-xinfa"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("int")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "huashan-shenfa"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "lonely-sword"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 if( query_skill_mapped("sword") == "lonely-sword"&&skill=="sword" &&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
		 		s+=ng/10+xiuyang/10+query("int");  	
		}			
		if(myclass=="华山派")
		{ng=query_skill("zixia-shengong",1);
		 if( query_skill_mapped("force") == "zixia-shengong"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("int")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "feiyan-huixiang"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "huashan-sword"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 if( query_skill_mapped("sword") == "huashan-sword"&&skill=="sword" &&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
		 		s+=ng/10+xiuyang/10+query("int");  	
		}			
		if(myclass=="丐帮")
		{ng=query_skill("huntian-qigong",1);
		 if( query_skill_mapped("force") == "huntian-qigong"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("con")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "xiaoyaoyou"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "dagou-bang"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 if( query_skill_mapped("parry") == "dragon-strike"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 if( query_skill_mapped("strike") == "dragon-strike"&&query_skill_prepared("strike") == "dragon-strike" &&(skill=="strike"))
		 		s+=ng/10+xiuyang/10+query("str"); 					
		 if( query_skill_mapped("staff") == "dagou-bang"&&skill=="staff" &&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
		 		s+=ng/10+xiuyang/10+query("int");  	
		}			
		if(myclass=="桃花岛")
		{ng=query_skill("bibo-shengong",1);
		 if( query_skill_mapped("force") == "bibo-shengong"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("int")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "anying-fuxiang"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "yuxiao-jian"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 					
		 if( query_skill_mapped("sword") == "yuxiao-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("int");  	
		}			
		if(myclass=="星宿派")
		{ng=query_skill("freezing-force",1);
		 if( query_skill_mapped("force") == "freezing-force"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("str")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "zhaixinggong"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "tianshan-zhang"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 	if( query_skill_mapped("parry") == "chousui-zhang"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 	 if( query_skill_mapped("strike") == "chousui-zhang"&&query_skill_prepared("strike") == "chousui-zhang" &&(skill=="strike"))
		 		s+=ng/10+xiuyang/10+query("str");						
		 if( query_skill_mapped("staff") == "tianshan-zhang"&&skill=="staff"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff" )
		 		s+=ng/10+xiuyang/10+query("str"); 
		 	if( skill=="poison"&&query_skill_mapped("force") == "freezing-force"
			&& query_skill_mapped("dodge") == "zhaixinggong"
			&& (query_skill_mapped("parry") == "tianshan-zhang"||query_skill_mapped("parry") == "chousui-zhang")
			&& ((query_skill_mapped("staff") == "tianshan-zhang")
			     ||(query_skill_mapped("strike") == "chousui-zhang"&&query_skill_prepared("strike") == "chousui-zhang" ))	 	)
		 	   s+=query_skill("poison",1); 		 		
		}			
		if(myclass=="逍遥派")
		{ng=query_skill("beiming-shengong",1);
		 if( query_skill_mapped("force") == "beiming-shengong"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("int")+xiuyang/10;
			 if( query_skill_mapped("parry") == "zhemei-shou"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 	if( query_skill_mapped("parry") == "ruyi-dao"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 	 if( query_skill_mapped("hand") == "zhemei-shou"&&query_skill_prepared("hand") == "zhemei-shou" &&(skill=="hand"))
		 		s+=ng/10+xiuyang/10+query("int");						
		 if( query_skill_mapped("blade") == "ruyi-dao"&&skill=="blade"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade" )
		 		s+=ng/10+xiuyang/10+query("int"); 
		}			
		if(myclass=="古墓派")
		{ng=query_skill("surge-force",1);
		 if( query_skill_mapped("force") == "surge-force"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("con")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "yunv-shenfa"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "sad-strike"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 	if( query_skill_mapped("parry") == "xuantie-jian"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 	 if( query_skill_mapped("unarmed") == "sad-strike"&&query_skill_prepared("unarmed") == "sad-strike" &&(skill=="unarmed"))
		 		s+=ng/10+xiuyang/10+query("con");						
		 if( query_skill_mapped("sword") == "xuantie-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("con"); 
		}			
		if(myclass=="全真教")
		{ng=query_skill("xiantian-gong",1);
		 if( query_skill_mapped("dodge") == "jinyan-gong"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("sword") == "quanzhen-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("con");  	
		}			
		
		if(myclass=="神龙教")
		{ng=query_skill("shenlong-xinfa",1);
		 if( query_skill_mapped("force") == "shenlong-xinfa"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10+query("dex"); 	
		 if( query_skill_mapped("dodge") == "yixingbu"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( (query_skill_mapped("parry") == "huagu-mianzhang"||query_skill_mapped("parry") == "shenlong-bashi")&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		  if( query_skill_mapped("strike") == "huagu-mianzhang"&&query_skill_prepared("strike") == "huagu-mianzhang" &&(skill=="strike"))
		 		s+=ng/5+xiuyang/10+query("dex");					
		  if( query_skill_mapped("strike") == "huagu-mianzhang"&&query_skill_prepared("strike") == "huagu-mianzhang" &&(skill=="poison"))
		 		s+=ng/10+xiuyang/10+query("dex");
		 	 if( query_skill_mapped("hand") == "shenlong-bashi"&&query_skill_prepared("hand") == "shenlong-bashi" &&(skill=="hand"))
		 		s+=ng/5+xiuyang/10+query("dex");	
		}			
			if(myclass=="雪山寺")
		{ng=query_skill("longxiang-gong",1);
				 if( query_skill_mapped("dodge") == "shenkong-xing"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "riyue-lun"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 if( query_skill_mapped("hammer") == "riyue-lun"&&skill=="hammer"&&objectp(weapon)&&(string)weapon->query("skill_type") == "hammer" )
		 		s+=ng/10+xiuyang/10+query("str");
		}	
		if(myclass=="血刀门")
		{ng=query_skill("xuehai-mogong",1);
			 if( query_skill_mapped("dodge") == "shenkong-xing"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "xue-dao"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 if( query_skill_mapped("blade") == "xue-dao"&&skill=="blade"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade" )
		 		s+=ng/10+xiuyang/10+query("str");
		}	
		if(myclass=="灵鹫宫")
		{ng=query_skill("bahuang-gong",1);
		 if( query_skill_mapped("dodge") == "yueying-wubu"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "tianyu-qijian"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 if( query_skill_mapped("sword") == "tianyu-qijian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("dex");
		}	
		if(myclass=="欧阳世家")
		{ng=query_skill("hamagong",1);
		 if( query_skill_mapped("force") == "hamagong"&&(skill=="parry"||skill=="dodge" ))
		 		s+=ng/5+xiuyang/10+query("str"); 	
		 if( query_skill_mapped("dodge") == "chuanchu-bufa"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( (query_skill_mapped("parry") == "hamagong"||query_skill_mapped("parry") == "lingshe-zhangfa")&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 if( query_skill_mapped("staff") == "lingshe-zhangfa"&&skill=="staff"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff" )
		 		s+=ng/10+xiuyang/10+query("str");
		  if( query_skill_mapped("unarmed") == "hamagong"&&query_skill_prepared("unarmed") == "hamagong" &&(skill=="unarmed"))
		 		s+=ng/10+xiuyang/10+query("str");		
		}	
		if(myclass=="关外胡家")
		{ng=query_skill("lengyue-shengong",1);
		 if( query_skill_mapped("force") == "lengyue-shengong"&&(skill=="parry"||skill=="dodge" ))
		 		s+=ng/5+xiuyang/10+(query("str")+query("int"))/2; 	
		 if( query_skill_mapped("dodge") == "sixiang-bufa"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "daojian-guizhen"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 if( query_skill_mapped("blade") == "daojian-guizhen"&&skill=="blade"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade" )
		 		s+=ng/10+xiuyang/10+(query("str")+query("int"))/2;
		  if( query_skill_mapped("unarmed") == "hamagong"&&query_skill_prepared("unarmed") == "hamagong" &&(skill=="unarmed"))
		 		s+=ng/10+xiuyang/10+query("str");		
		}
		if(myclass=="慕容世家")
		{ng=query_skill("zihui-xinfa",1);
		 if( query_skill_mapped("force") == "zihui-xinfa"&&skill=="parry")
		 		s+=ng/5+xiuyang/10+query("con"); 	
		 if( query_skill_mapped("dodge") == "beidou-xianzong"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 
		 		 if( query_skill_mapped("sword") == "murong-sword"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("con");
		  if( query_skill_mapped("unarmed") == "hamagong"&&query_skill_prepared("unarmed") == "hamagong" &&(skill=="unarmed"))
		 		s+=ng/10+xiuyang/10+query("str");		
		}
		if(myclass=="段氏皇族")
		{ng=query_skill("kurong-changong",1);
		 if( query_skill_mapped("force") == "kurong-changong"&&(skill=="parry"||skill=="dodge"))
		 		s+=ng/5+xiuyang/10+query("int"); 	
		 if( query_skill_mapped("dodge") == "tiannan-step"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "six-finger"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
		 if( query_skill_mapped("finger") == "six-finger"&&query_skill_prepared("finger") == "six-finger" &&(skill=="finger"))
		 		s+=ng/10+xiuyang/10+query("int");		
		}
		if(myclass=="明教")
		{
			if(query_skill_mapped("force") == "jiuyang-shengong")
			{ng=query_skill("jiuyang-shengong",1);
				if( query_skill_mapped("unarmed") == "jiuyang-shengong"&&query_skill_prepared("unarmed") == "jiuyang-shengong" &&(skill=="parry"))
		 		s+=ng/10+xiuyang/10+query("int");		
		 		if( query_skill_mapped("claw") == "sougu-yingzhua"&&query_skill_prepared("claw") == "sougu-yingzhua" &&(skill=="claw"))
		 		s+=ng/10+xiuyang/10+query("int");
			}	
			if(query_skill_mapped("force") == "shenghuo-shengong")
			{ng=query_skill("shenghuo-shengong",1);
			if( query_skill_mapped("dodge") == "shenghuo-bu"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10;
		 	if( query_skill_mapped("sword") == "shenghuo-ling"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("int");	 		
			}	
		}
		if(myclass=="日月神教")
		{
			if(query_skill_mapped("force") == "kuihua-shengong")
			{ng=query_skill("kuihua-shengong",1);
				if( query_skill_mapped("force") == "kuihua-shengong"&&skill=="parry")
		 		s+=ng/5+xiuyang/10+query("dex");
				 if( query_skill_mapped("parry") == "kuihua-shengong"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 
				 if( query_skill_mapped("sword") == "kuihua-shengong"&&skill=="dodge"&&objectp(weapon)
				 	&&((string)weapon->query("skill_type") == "sword"||(string)weapon->query("skill_type") == "pin") )
		 		s+=ng/10+xiuyang/10+query("dex");
			}	
			if(query_skill_mapped("force") == "xixing-dafa")
			{ng=query_skill("xixing-dafa",1);
			if( query_skill_mapped("force") == "xixing-dafa"&&(skill=="parry"||skill=="dodge"))
		 		s+=ng/5+xiuyang/10+query("con");
			if( query_skill_mapped("dodge") == "piaomiao-shenfa"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10;
		 	if( query_skill_mapped("parry") == "tianmo-jian"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 	
		 	if( query_skill_mapped("sword") == "tianmo-jian"&&skill=="sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 		s+=ng/10+xiuyang/10+query("con");	 		
			}	
		}
		if(myclass=="昆仑派")
		{ng=query_skill("liangyi-shengong",1);
		 if( query_skill_mapped("force") == "liangyi-shengong"&&(skill=="parry"||skill=="dodge") )
		 		s+=query_skill("force")/5+query("int")+xiuyang/10;
		 if( query_skill_mapped("dodge") == "chuanyun-bu"&&skill=="dodge" )
		 		s+=ng/10+xiuyang/10; 			
		 if( query_skill_mapped("parry") == "qiankun-jian"&&skill=="parry" )
		 		s+=ng/10+xiuyang/10; 		
		 if( query_skill_mapped("sword") == "qiankun-jian"&&skill=="sword" &&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
		 		s+=ng/10+xiuyang/10+query("int");  	
		}																	
	}
		
		
		
		if (mapp(skills))
		{
			s += skills[skill]+mer+num+forces+parrys+dodges;//特殊等级按1算
			if (mapp(skill_map))
				s += skills[skill_map[skill]]/2;//基础等级按1/2算
	
		}
				//vip激发加成
		viplvl=query("zjvip/level");
		switch(viplvl){
		case 4:	xishu=101;
			break;
		case 5:	xishu=103;
			break;
		case 6:	xishu=105;
			break;
		case 7:	xishu=108;
			break;
		case 8:	xishu=110;
			break;		
		case 9:	xishu=112;
			break;
		case 10:	xishu=115;
			break;			
		default:	xishu=100;
			break;				
		}
		
		s=s*xishu/100;				
		return s;
	}
	if (mapp(skills) && ! undefinedp(skills[skill]))
		return skills[skill];//基本技能等级
	return 0;
}

*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
