// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{

int i,bt;
	string str,cmd;
	if(!arg)
	{
        str = ZJOBLONG"自动招式系统："ZJBR
        "你目前设置了已下几个招式"ZJBR
        "招式一["+((me->query("taolu/fight/bb1") <1 )?"未设置招式":" "+me->query("taolu/fight/b1")+"")+"]"ZJBR
        "招式二["+((me->query("taolu/fight/bb2") <1 )?"未设置招式":" "+me->query("taolu/fight/b2")+"")+"]"ZJBR
        "招式三["+((me->query("taolu/fight/bb3") <1 )?"未设置招式":" "+me->query("taolu/fight/b3")+"")+"]"ZJBR
        "招式四["+((me->query("taolu/fight/bb4") <1 )?"未设置招式":" "+me->query("taolu/fight/b4")+"")+"]"ZJBR
        "招式五["+((me->query("taolu/fight/bb5") <1 )?"未设置招式":" "+me->query("taolu/fight/b5")+"")+"]"ZJBR
        "招式六["+((me->query("taolu/fight/bb6") <1 )?"未设置招式":" "+me->query("taolu/fight/b6")+"")+"]"ZJBR
        "招式七["+((me->query("taolu/fight/bb7") <1 )?"未设置招式":" "+me->query("taolu/fight/b7")+"")+"]"ZJBR
        "招式八["+((me->query("taolu/fight/bb8") <1 )?"未设置招式":" "+me->query("taolu/fight/b8")+"")+"]"ZJBR
        "招式九["+((me->query("taolu/fight/bb9") <1 )?"未设置招式":" "+me->query("taolu/fight/b9")+"")+"]"ZJBR
        "招式十["+((me->query("taolu/fight/bb10") <1 )?"未设置招式":" "+me->query("taolu/fight/b10")+"")+"]"ZJBR
        "注意：设置完成后使用指令：taolua，即可自动释放你设定好的招式！\n";
        
		str += ZJOBACTS2+ZJMENUF(2,2,9,31);
		str +=
        HIR"设置招式:taolu reset"ZJSEP
		HIR"清除招式"NOR":taolu qingchu"ZJSEP
		HIY"战斗脚本"NOR":zdjb"ZJSEP
		HIY"重新设置"NOR":mycmds reset"ZJSEP
		HIM"招式说明"NOR":help taolus"ZJSEP
		HIM"招式说明"NOR":help taolus";
		message("vision", str+"\n", me);		
	}
	else
	
  if(arg=="reset")
	{
		str = ZJBTSET;

		for(i=1;i<11;i++)
		{
			str += "b"+i+":""第"+chinese_number(i)+""ZJBR"招式"NOR":taolu reset "+i;
			str += ZJSEP;
		}
		str += "b11:""返回"ZJBR"页面"NOR":mycmds fight";
		write(str+"\n");
		write(HIW"请设置你想设置的技能招式，从左到右，分别代表1到10个招式！\n"NOR);
		write(ZJTMPSAY+HIR+"请设置你想设置的技能招式，从左到右！\n"NOR);
	}
	else
	 if(sscanf(arg,"reset %d %s",bt,cmd)==2)
	{
		string a,b;

		if(bt<1||bt>10)
			return notify_fail(ZJOBLONG"没有这个按钮。。。\n");
		if(cmd == "自定义")
		{
			write(INPUTTXT("请输入自定义字串：标题:命令(查看:look)","taolu reset "+bt+" $txt#")+"\n");
			return 1;
		}
		cmd = replace_string(cmd,"：",":");
		cmd = replace_string(cmd,"#E",ESA);
		cmd = replace_string(cmd,"/",ZJBR);
		cmd = replace_string(cmd,"\n",ZJBR);
		me->set("taolu/fight/b"+bt,cmd);
		me->set("taolu/fight/bb"+bt,1);
		write("第"+bt+"招式，招式名为："+cmd+"\n");				
	}
	else if(sscanf(arg,"reset %d",bt)==1)
	{
		mapping smap, pmap, pfms,skips;
		string force_ski,weapon_ski,*pfm,ski_type,uski_type;
		int k,flag;
		string msg,*valid_types,*skis,*cmdd;
		object weapon;

		if(bt<1||bt>10)
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
					msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" force."+pfm[i]+ZJSEP;
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
					if(skips[pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" xinfa."+pfm[i]+ZJSEP;
			//		msg += cmdd[0] + ":taolu reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" xinfa."+pfm[i]+ZJSEP;
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
					if(skips[pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" parry."+pfm[i]+ZJSEP;
				//	msg += cmdd[0] + ":taolu reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" parry."+pfm[i]+ZJSEP;
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
					if(skips[pfm[i]]) continue;
					cmdd = explode(pfms[pfm[i]],":");
					msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" dodge."+pfm[i]+ZJSEP;
				//	msg += cmdd[0] + ":taolu reset "+ bt+" " +replace_string(cmdd[0],ESA,"#E")+"："+ cmdd[1]+" dodge."+pfm[i]+ZJSEP;
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
					//	msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" force."+pfm[i]+ZJSEP;
						msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" "+ski_type+"."+pfm[i]+ZJSEP;
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
							msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" "+skis[k]+"."+pfm[i]+ZJSEP;
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
							msg += cmdd[0] + ":taolu reset "+ bt+" "+ cmdd[1]+" "+skis[k]+"."+pfm[i]+ZJSEP;
							skips[smap[skis[k]]+pfm[i]] = 1;
						}
					}
				}
			}
		}
		write(ZJOBLONG"你想设定的招式"+chinese_number(bt)+NOR"\n"ZJOBACTS2+ZJMENUF(5,5,8,30)
			+msg		
			+"拉弓"ZJBR"射箭:taolu reset "+bt+" shot"ZJSEP
			+"内力"ZJBR"回气:taolu reset "+bt+" exert recover"ZJSEP
			+"内力"ZJBR"回精:taolu reset "+bt+" exert regenerate"ZJSEP
		    +"内力"ZJBR"疗伤:taolu reset "+bt+" exert heal"ZJSEP
			+"内力"ZJBR"疗疾:taolu reset "+bt+" exert dispel"ZJSEP
			+"释放"ZJBR"怒气:taolu reset "+bt+" burning"ZJSEP
			+"使用"ZJBR"护心丹:taolu reset "+bt+" use huxin dan"ZJSEP
			+"使用"ZJBR"沧海丹:taolu reset "+bt+" use ch dan"ZJSEP
								
			+"\n");
	}
	
	if(arg=="qingchu")
	{
	    str = ZJOBLONG"请选择删除招式：\n";
		str += ZJOBACTS2+ZJMENUF(1,1,10,28);
		str +=
        HIW"招式一["+me->query("taolu/fight/b1")+"]:taolu qingchu1"ZJSEP
        HIW"招式二["+me->query("taolu/fight/b2")+"]:taolu qingchu2"ZJSEP
        HIW"招式三["+me->query("taolu/fight/b3")+"]:taolu qingchu3"ZJSEP
        HIW"招式四["+me->query("taolu/fight/b4")+"]:taolu qingchu4"ZJSEP
        HIW"招式五["+me->query("taolu/fight/b5")+"]:taolu qingchu5"ZJSEP
        HIW"招式六["+me->query("taolu/fight/b6")+"]:taolu qingchu6"ZJSEP
        HIW"招式七["+me->query("taolu/fight/b7")+"]:taolu qingchu7"ZJSEP
        HIW"招式八["+me->query("taolu/fight/b8")+"]:taolu qingchu8"ZJSEP
        HIW"招式九["+me->query("taolu/fight/b9")+"]:taolu qingchu9"ZJSEP
        HIW"招式十["+me->query("taolu/fight/b10")+"]:taolu qingchu10";
		message("vision", str+"\n", me);		
	}	
	
if(arg=="qingchu1")
	{
	me->delete("taolu/fight/b1");
	me->delete("taolu/fight/bb1");
	write(HIM"你已经成功删除招式一了\n"NOR);	
	}
	
	if(arg=="qingchu2")
	{
	me->delete("taolu/fight/b2");
	me->delete("taolu/fight/bb2");
	write(HIM"你已经成功删除招式二了\n"NOR);	
	}
	if(arg=="qingchu3")
	{
	me->delete("taolu/fight/b3");
	me->delete("taolu/fight/bb3");
	write(HIM"你已经成功删除招式三了\n"NOR);	
	}
	if(arg=="qingchu4")
	{
	me->delete("taolu/fight/b4");
	me->delete("taolu/fight/bb4");
	write(HIM"你已经成功删除招式四了\n"NOR);	
	}
	if(arg=="qingchu5")
	{
	me->delete("taolu/fight/b5");
	me->delete("taolu/fight/bb5");
	write(HIM"你已经成功删除招式五了\n"NOR);	
	}
	if(arg=="qingchu6")
	{
	me->delete("taolu/fight/b6");
	me->delete("taolu/fight/bb6");
	write(HIM"你已经成功删除招式六了\n"NOR);	
	}
	if(arg=="qingchu7")
	{
	me->delete("taolu/fight/b7");
	me->delete("taolu/fight/bb7");
	write(HIM"你已经成功删除招式七了\n"NOR);	
	}
	if(arg=="qingchu8")
	{
	me->delete("taolu/fight/b8");
	me->delete("taolu/fight/bb8");
	write(HIM"你已经成功删除招式八了\n"NOR);	
	}
	if(arg=="qingchu9")
	{
	me->delete("taolu/fight/b9");
	me->delete("taolu/fight/bb9");
	write(HIM"你已经成功删除招式九了\n"NOR);	
	}
	if(arg=="qingchu10")
	{
	me->delete("taolu/fight/b10");
	me->delete("taolu/fight/bb10");
	write(HIM"你已经成功删除招式十了\n"NOR);	
	}
	
	return 1;
}
	
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
