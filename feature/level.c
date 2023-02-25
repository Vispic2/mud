// level.c 
#pragma save_binary
#include <dbase.h>
#include <ansi.h>;

//计算升级需要最大的经验
int level_max_exp(object me)
{
	int max_exp,lvl;
	lvl=(int)me->query("level");
	if(lvl<5)
		max_exp=lvl*10+1000;
	if(lvl<10 && lvl>4)
		max_exp=lvl*15+20000;
	if(lvl<20 && lvl>9)
		max_exp=lvl*20+50000;
	if(lvl<30 && lvl>19)
		max_exp=lvl*30+100000;
	if(lvl<40 && lvl>29)
		max_exp=lvl*40+200000;
	if(lvl<50 && lvl>39)
		max_exp=lvl*50+300000;
	if(lvl<59 && lvl>49)
		max_exp=lvl*100+500000;
	if(lvl<69 && lvl>58)
		max_exp=lvl*1000+1000000;
	if(lvl<79 && lvl>68)
		max_exp=lvl*1000+2000000;
	if(lvl<89 && lvl>78)
		max_exp=lvl*1000+3000000;
	if(lvl<99 && lvl>88)
		max_exp=lvl*1000+4000000;
	if(lvl<109 && lvl>98)
		max_exp=lvl*1000+5000000;
	if(lvl>=109)
		max_exp=lvl*2*5000+500000000;
 
	return max_exp;
}
//升级判断--升级不会消耗实战经验。
varargs void improve_level(object me)
{
	int exp_num;
	exp_num=me->query("combat_exp");
	if(exp_num >= level_max_exp(me))
	{
		tell_object(me, HIG"只见一阵绚丽的光芒从你身上闪过  "NOR"\n");
		printf(HIC"≡"HIY"────────────────────────────"HIC"≡"NOR"\n");
		tell_object(me, HIR" 恭喜:"+NOR" 你的 "+YEL+"「Level」: "HIY" 提升了 ↑"+NOR"！"+HIG"    内: +20  精: +10 "+NOR+"\n");
		me->add("max_neili",20); 
		me->add("max_jingli",10);     
		if(exp_num>=level_max_exp(me))
		{
			me->add("level",1);
			if((int)me->query("level")%1==0)
			{
				me->add("skill_point",1);
				write(HIG"恭喜：  <你获得附加技能点> + 1 "NOR"\n");
			}
			if((int)me->query("level")%10==0)
			{
				me->add("tianfu_point",1);
				write(HIG"恭喜：  <你获得附加天赋点> + 1 "NOR"\n");
			}
		}
		else
		{
			me->set("combat_exp",0);
			me->add("level",1);
		}
		printf(HIC"≡"HIY"────────────────────────────"HIC"≡"NOR"\n");
	}  
	else
	{
		write(HIR"你的实战经验不足以提升等级!"NOR"\n");
	}   
}
//提升天赋点数
varargs void up_tianfu(object me,string arg)
{
	int i;
	if(me->query("tianfu_point")>=1)
	{
	if(arg=="str"){
	me->add("str",1);
	write(HIR"恭喜：   "HIG"你的「先天臂力」增加了!"NOR"\n");
	}else
	if(arg=="int"){
	me->add("int",1) ;
	write(HIR"恭喜：   "HIG"你的「先天悟性」增加了!"NOR"\n");
	}else
	if(arg=="con"){
    me->add("con",1) ;
	write(HIR"恭喜：   "HIG" 你的「先天根骨」增加了!"NOR"\n");
	}else
	if(arg=="dex"){
	me->add("dex",1) ;
	write(HIR"恭喜：   "HIG"你的「先天身法」增加了!"NOR"\n");
	}	
	me->add("tianfu_point",-1);
	}else{
	write(HIR"你的天赋点不足以提升先天属性! "NOR"\n");
	}
	/*
	if((int)me->query("tianfu_point"))
	{
		i=random(400);
		write(HIY"你将一点宝贵的「天赋点」灌注进了身体，顿时一片金光闪过。"NOR"\n");
		if(i<=100) 
		{
			me->add("str",1) ;
			write(HIR"恭喜：   "HIG"你的「先天臂力」增加了!"NOR"\n");
		}
		if(i>100 && i<=200) 
		{
			me->add("int",1) ;
			write(HIR"恭喜：   "HIG"你的「先天悟性」增加了!"NOR"\n");
		}
		if(i>200 && i<=300) 
		{
			me->add("con",1) ;
			write(HIR"恭喜：   "HIG" 你的「先天根骨」增加了!"NOR"\n");
		}
		if(i>300) 
		{
			me->add("dex",1) ;
			write(HIR"恭喜：   "HIG"你的「先天身法」增加了!"NOR"\n");
		}
		me->add("tianfu_point",-1);
	}
	else
	{
		write(HIR"你的天赋点不足以提升先天属性! "NOR"\n");
	}
	*/
}

//随机提升装备的特殊技能等级
varargs void up_skills(object me)
{
	int skill_point;
	mixed me_skills;
	mixed sky_skills;
	mapping skills;
	int i;
	int exp,level;
	me_skills=me->query_skill_map();
	if(sizeof(me_skills))
	{
		if((int)me->query("skill_point"))
		{
			i=random(sizeof(me_skills));
			sky_skills=keys(me_skills);
			skills=me->query_skills();
			exp=me->query("combat_exp");
			level=skills[me_skills[sky_skills[i]]];
			if(level*level*level/10 < exp)
			{
				skills[me_skills[sky_skills[i]]]++;
				tell_object(me, "你消耗了一个技能点，只见一阵"HIM"紫色"NOR"的光芒从你身上闪过！！！  "NOR"\n");
				printf(HIC"≡"HIY"────────────────────────────"HIC"≡"NOR"\n");
				tell_object(me,HIR"  恭喜："NOR" 你的特殊武功"MAG" [ "+to_chinese(me_skills[sky_skills[i]])+" ]"NOR" 提升了 "HIM"↑"NOR" ."NOR"\n");
				printf(HIC"≡"HIY"────────────────────────────"HIC"≡"NOR"\n");
				me->add("skill_point",-1);
			}
			else
			{
				write(HIR"你的经验不足以支持技能的提升!"NOR"\n");
			}
		}
		else
		{
			write(HIR"你的技能点不足!"NOR"\n");
		}
	}
	else
	{
		write(HIR"技能点只能提升装备着的特殊武功!"NOR"\n");
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
