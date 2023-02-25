// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,bt;
	string str,cmd,cmds;

	if(!arg)
	{
		write(ZJBTSET"b12:""常用"ZJBR"指令"NOR":mycmds ofen"ZJSEP"b13:""技能"ZJBR"相关"NOR":mycmds skill"ZJSEP"b14:""战斗"ZJBR"相关"NOR":mycmds fight"ZJSEP
			"b15:""功能"ZJBR"相关"NOR":mycmds quest"ZJSEP"b16:""游戏"ZJBR"指南"NOR":mycmds help"ZJSEP"b17:"HIC"聊天"NOR""ZJBR+HIC"频道"NOR":liaotian\n");
		write(ZJTTMENU"飞行:help ditu"ZJSEP"客栈:recall"ZJSEP"门派:recalle"ZJSEP"回家:huijia"ZJSEP"附近:help ditus"ZJSEP"其他"":help qt"ZJSEP"停止"":halt"NOR"\n");
	}
	else if(arg=="ofen")
		write(ZJBTSET"b1:""查看"ZJBR"背包:i"ZJSEP"b2:""综合"ZJBR"属性:score"ZJSEP"b3:""健康"ZJBR"状态:hp"
			ZJSEP"b4:""查看"ZJBR"装备:arm"ZJSEP"b5:"HIG"角色↑"ZJBR"家园↑"NOR":uplv"ZJSEP"b6:""称号"ZJBR"系统:querytitles"
			ZJSEP"b7:""队伍"ZJBR"信息"NOR":team"ZJSEP"b8:""帮会"ZJBR"相关:banghui"ZJSEP"b9:"HIY"随身"ZJBR"商城"NOR":shangchang"ZJSEP"b10:""玩家"ZJBR"排行:tops"ZJSEP"b11:""乘雕"ZJBR"飞行"NOR":help mapb"+"\n");					
	else if(arg=="skill")
		write(ZJBTSET"b1:""查看"ZJBR"技能:skills"ZJSEP"b2:""日常"ZJBR"练功:help liangong"ZJSEP"b3:""内力"ZJBR"回血:exert recover"
			ZJSEP"b4:""内力"ZJBR"回精:exert regenerate"ZJSEP"b5:""内力"ZJBR"疗伤:exert heal"ZJSEP"b6:""内力"ZJBR"疗神:exert inspire"
			ZJSEP"b7:""内力"ZJBR"疗疾:exert dispel"ZJSEP"b8:""内功"ZJBR"加力:enforce"ZJSEP"b9:""技经"ZJBR"互查:skill"ZJSEP"b10:"HIM"参数"ZJBR"设定"NOR":set nocha_skills"ZJSEP"b11:"HIG"天赋"ZJBR"进阶"NOR":special"+"\n");
	else if(arg=="fight")
	{
		str = ZJBTSET;
		for(i=1;i<11;i++)
		{
			if(cmd=me->query("mycmds/fight/b"+i))
				str += "b"+i+":"+cmd;
			else
				str += "b"+i+":""点击"ZJBR"选择"+i+NOR":mycmds reset "+i;
			str += ZJSEP;
		}
		str += "b11:"CYN"战斗"ZJBR"设置"NOR":taolu";
		write(str+"\n");
	}
	else if(arg=="quest")
	// write(ZJBTSET"b1:""仆役"ZJBR"系统:puyi"ZJSEP"b2:""邀请"ZJBR"系统:ainvitationd"ZJSEP"b3:""红包"ZJBR"系统"":fahb"
	// ZJSEP"b4:"HIR"自动"ZJBR"寻路"NOR":walk"ZJSEP"b5:""刺杀"ZJBR"任务"NOR":cisha"ZJSEP"b6:"HIC"随从"ZJBR"面板"NOR":sc"ZJSEP"b7:""师门"ZJBR"扫荡:saodang"
	// ZJSEP"b8:""境界"ZJBR"突破:jinjie"ZJSEP"b9:""战令"ZJBR"系统:zhanlin main"ZJSEP"b10:""VIP"ZJBR"成就:vip"ZJSEP"b11:"HIY"挖宝"ZJBR"探索"NOR":searchs"+"\n");
		write(ZJBTSET"b1:""仆役"ZJBR"系统:puyi"ZJSEP"b2:""邀请"ZJBR"系统:ainvitationd"ZJSEP"b3:""红包"ZJBR"系统"":fahb"
			ZJSEP"b4:"HIR"自动"ZJBR"寻路"NOR":walk"ZJSEP"b5:""刺杀"ZJBR"任务"NOR":cisha"ZJSEP"b6:"HIC"随从"ZJBR"面板"NOR":sc" 
			ZJSEP"b8:""境界"ZJBR"突破:jinjie"ZJSEP"b9:""战令"ZJBR"系统:zhanlin main"ZJSEP"b10:""VIP"ZJBR"成就:vip"ZJSEP"b11:"HIY"挖宝"ZJBR"探索"NOR":searchs"+"\n");
	else if(arg=="help")  //help pay 赞助说明
		// write(ZJBTSET"b1:""更新"ZJBR"公告:help anews"ZJSEP"b2:""新手"ZJBR"指南"NOR":help newbie"ZJSEP"b3:"HIR"本服"ZJBR+HIM"特色"NOR":help ts"
		// 	ZJSEP"b4:""自动"ZJBR"师门:set sign5 zdsm;accept quest;use ch dan"ZJSEP"b5:""开始"ZJBR"挂机:set sign1 1"ZJSEP"b6:""结束"ZJBR"挂机"NOR":unset sign1"ZJSEP"b7:共享"ZJBR"指令"NOR":newbook1"ZJSEP"b8:""离线"ZJBR"任务"NOR":lixian"
		// 	ZJSEP"b9:""色彩"ZJBR"精灵:color"ZJSEP"b10:""角色"ZJBR"重建"NOR":suicide"ZJSEP"b11:"HIW"MUD"ZJBR"状态"NOR":mudinfo"+"\n");
		write(ZJBTSET"b1:""更新"ZJBR"公告:help anews"ZJSEP"b2:""新手"ZJBR"指南"NOR":help newbie"ZJSEP"b3:"HIR"本服"ZJBR+HIM"特色"NOR":help ts"
		ZJSEP"b4:""自动"ZJBR"师门:set sign5 zdsm;accept quest;use ch dan"ZJSEP"b5:""开始"ZJBR"挂机:set sign1 1"ZJSEP"b6:""结束"ZJBR"挂机"NOR":unset sign1"ZJSEP"b7:共享"ZJBR"指令"NOR":newbook1"
		ZJSEP"b9:""色彩"ZJBR"精灵:color"ZJSEP"b10:""角色"ZJBR"重建"NOR":suicide"ZJSEP"b11:"HIW"MUD"ZJBR"状态"NOR":mudinfo"+"\n");
	else if(arg=="reset")
	{
		str = ZJBTSET;
		for(i=1;i<17;i++)
		{
			str += "b"+i+":""点击"ZJBR"选择"+i+NOR":mycmds reset "+i;
			str += ZJSEP;
		}
		str += "b11:""返回"NOR":mycmds fight";
		write(str+"\n");
		write(ZJTMPSAY"请点击你想要定义的按钮选择新功能。\n");
	}
	else if(sscanf(arg,"reset %d %s",bt,cmd)==2)
	{
		string a,b;

		if(bt<1||bt>16)
			return notify_fail(ZJOBLONG"没有这个按钮。。。\n");
		if(cmd == "自定义")
		{
			write(INPUTTXT("请输入自定义字串：标题:命令(查看:look)","mycmds reset "+bt+" $txt#")+"\n");
			return 1;
		}
		cmd = replace_string(cmd,"：",":");
		cmd = replace_string(cmd,"#E",ESA);
		cmd = replace_string(cmd,"/",ZJBR);
		cmd = replace_string(cmd,"\n",ZJBR);
/*
		cmds=cmd;
	    str = ZJOBLONG"是否将此招式使用互博：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,10,28);
		str +=	
	    HIY"使用:mycmds reset 1 "+cmd+" twice"ZJSEP
        HIY"不使用"NOR":mycmds reset "+cmd+"";
		message("vision", str+"\n", me);		
    
    
   */
    
	    if(sscanf(cmd,"%s:%s",a,b)!=2)
		return notify_fail("格式错误，请重新定义！"NOR"\n");
		me->set("mycmds/fight/b"+bt,cmd);
        write(ZJBTSET"b"+bt+":"+cmd+"\n");
	
		
	}
	else if(sscanf(arg,"reset %d",bt)==1)
	{
		mapping smap, pmap, pfms,skips;
		string force_ski,weapon_ski,*pfm,ski_type,uski_type;
		int k,flag;
		string msg,*valid_types,*skis,*cmdd;
		object weapon;

		if(bt<1||bt>16)
			return notify_fail(ZJOBLONG"没有这个按钮。。。\n");

		valid_types = ({"finger","hand","cuff","claw","strike","unarmed"});
		skips = ([]);
		if(!smap = me->query_skill_map()) smap=([]);
		if(!pmap = me->query_skill_prepare()) pmap=([]);
		msg = "";

		if(objectp(weapon = me->query_temp("weapon")))
			ski_type = weapon->query("skill_type");

		if(force_ski=smap["force"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("force");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" force."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(force_ski=smap["xinfa"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("xinfa");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					if(skips[force_ski+pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" xinfa."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(force_ski=smap["parry"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("parry");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					if(skips[force_ski+pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" parry."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(force_ski=smap["dodge"])
		{
			pfms = SKILL_D(force_ski)->query_pfm("dodge");
			if(mapp(pfms)&&pfms!=([]))
			{
				pfm = sort_array(keys(pfms), (: strcmp :) );
				for(i=0;i<sizeof(pfm);i++)
				{
					if(skips[force_ski+pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" dodge."+pfm[i]+ZJSEP;
					skips[force_ski+pfm[i]]=1;
				}
			}
		}

		if(objectp(weapon))
		{
			if(stringp(weapon_ski=smap[ski_type]))
			{
				pfms = SKILL_D(weapon_ski)->query_pfm(ski_type);
				if(mapp(pfms)&&pfms!=([]))
				{
					pfm = sort_array(keys(pfms), (: strcmp :) );
					for(i=0;i<sizeof(pfm);i++)
					{
						if(skips[weapon_ski+pfm[i]]) continue;
						cmdd = explode(pfms[pfm[i]],":");
						msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" "+ski_type+"."+pfm[i]+ZJSEP;
						skips[weapon_ski+pfm[i]] = 1;
					}
				}
			}
		}
		else if(!objectp(weapon))
		{
			if(mapp(pmap)&&pmap!=([]))
			{//首先推送准备技能
				skis = sort_array(keys(pmap), (: strcmp :) );
				for(k=0;k<sizeof(skis);k++)
				{
					if(skips[pmap[skis[k]]]) continue;
					pfms = SKILL_D(pmap[skis[k]])->query_pfm(skis[k]);
					if(mapp(pfms)&&pfms!=([]))
					{
						pfm = sort_array(keys(pfms), (: strcmp :) );
						for(i=0;i<sizeof(pfm);i++)
						{
							if(skips[pmap[skis[k]]+pfm[i]]) continue;
							cmdd = explode(pfms[pfm[i]],":");
							msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" "+skis[k]+"."+pfm[i]+ZJSEP;
							skips[pmap[skis[k]]+pfm[i]] = 1;
						}
					}
				}
			}

			skis = sort_array(keys(smap), (: strcmp :) );
			for(k=0;k<sizeof(skis);k++)
			{
				flag = 1;
				for(i=0;i<sizeof(valid_types);i++)
				{
					if(SKILL_D(smap[skis[k]])->valid_enable(valid_types[i]))
					{
						uski_type = valid_types[i];
						flag = 2;
					}
				}
				if(!skips[smap[skis[k]]]&&flag==2)
				{
					pfms = SKILL_D(smap[skis[k]])->query_pfm(uski_type);
					if(mapp(pfms)&&pfms!=([]))
					{
						pfm = sort_array(keys(pfms), (: strcmp :) );
						for(i=0;i<sizeof(pfm);i++)
						{
							if(skips[smap[skis[k]]+pfm[i]]) continue;
							cmdd = explode(pfms[pfm[i]],":");
							msg += cmdd[0] + ":zuoyou "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" "+skis[k]+"."+pfm[i]+ZJSEP;
							skips[smap[skis[k]]+pfm[i]] = 1;
						}
					}
				}
			}
		}
		write(ZJOBLONG"你想设定按钮"+chinese_number(bt)+NOR"为什么功能？\n"ZJOBACTS2+ZJMENUF(5,5,8,30)
			+msg
			+"拉弓"ZJBR"射箭:mycmds reset "+bt+" 拉弓"ZJBR"射箭：shot"ZJSEP
			+"内力"ZJBR"回气:mycmds reset "+bt+" 内力"ZJBR"回气：exert recover"ZJSEP
			+"内力"ZJBR"回精:mycmds reset "+bt+" 内力"ZJBR"回精：exert regenerate"ZJSEP
		      +"内力"ZJBR"疗伤:mycmds reset "+bt+" 内力"ZJBR"疗伤：exert heal"ZJSEP
			+"内力"ZJBR"疗疾:mycmds reset "+bt+" 内力"ZJBR"疗疾：exert dispel"ZJSEP
			+"释放"ZJBR"怒气:mycmds reset "+bt+" 释放"ZJBR"怒气：burning"ZJSEP
			+"吃护"ZJBR"心丹:mycmds reset "+bt+" 吃护"ZJBR"心丹：use huxin dan"ZJSEP
			+""HIR"招式"ZJBR"出招"NOR":mycmds reset "+bt+" 招式"ZJBR"出招：taolua"ZJSEP			
			+"\n");
	}
	return 1;
}

int help(object me)
{
     write(@HELP

这个指令让设定游戏默认的自定义按钮。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
