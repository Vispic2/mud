//by 俗尘
//VIP1 累计赞助100元
//VIP2 累计赞助300元
//VIP3 累计赞助500元
//VIP4 累计赞助800元
////VIP5 累计赞助1000元
//VIP6 累计赞助1300元
//VIP7 累计赞助1500元
//VIP8 累计赞助1800元
//VIP9 累计赞助2000元
//VIP10 累计赞助3000元
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    string str;
	if(!arg)
	{
		str = ZJOBLONG"VIP成就系统："ZJBR
"VIP1 累计赞助100元"ZJBR
"VIP2 累计赞助300元"ZJBR
"VIP3 累计赞助500元"ZJBR
"VIP4 累计赞助800元"ZJBR
"VIP5 累计赞助1000元"ZJBR
"VIP6 累计赞助1300元"ZJBR
"VIP7 累计赞助1500元"ZJBR
"VIP8 累计赞助1800元"ZJBR
"VIP9 累计赞助2000元"ZJBR
"VIP10 累计赞助3000元\n";
		str+=ZJOBACTS2+ZJMENUF(2,2,10,28);
		//str+=ZJOBACTS+ZJMENUF(1,4,10,30);
		str +=
		HIG"VIP1 ["+((me->query("zjvip/all_pay") > 100) ? "已达成":"未达成")+"] ["+((me->query("zjvip/1") ==1) ? "已领取":"未领取")+"]:vip 1"ZJSEP
		HIG"VIP2 ["+((me->query("zjvip/all_pay") > 300) ? "已达成":"未达成")+"] ["+((me->query("zjvip/2") ==1) ? "已领取":"未领取")+"]:vip 2"ZJSEP
		HIG"VIP3 ["+((me->query("zjvip/all_pay") > 500) ? "已达成":"未达成")+"] ["+((me->query("zjvip/3") ==1) ? "已领取":"未领取")+"]:vip 3"ZJSEP
		HIG"VIP4 ["+((me->query("zjvip/all_pay") > 800) ? "已达成":"未达成")+"] ["+((me->query("zjvip/4") ==1) ? "已领取":"未领取")+"]:vip 4"ZJSEP
		HIG"VIP5 ["+((me->query("zjvip/all_pay") > 1000) ? "已达成":"未达成")+"] ["+((me->query("zjvip/5") ==1) ? "已领取":"未领取")+"]:vip 5"ZJSEP
		HIG"VIP6 ["+((me->query("zjvip/all_pay") > 1300) ? "已达成":"未达成")+"] ["+((me->query("zjvip/6") ==1) ? "已领取":"未领取")+"]:vip 6"ZJSEP
		HIG"VIP7 ["+((me->query("zjvip/all_pay") > 1500) ? "已达成":"未达成")+"] ["+((me->query("zjvip/7") ==1) ? "已领取":"未领取")+"]:vip 7"ZJSEP
	    HIG"VIP8 ["+((me->query("zjvip/all_pay") > 1800) ? "已达成":"未达成")+"] ["+((me->query("zjvip/8") ==1) ? "已领取":"未领取")+"]:vip 8"ZJSEP
	    HIG"VIP9 ["+((me->query("zjvip/all_pay") > 2000) ? "已达成":"未达成")+"] ["+((me->query("zjvip/9") ==1) ? "已领取":"未领取")+"]:vip 9"ZJSEP	   
		HIG"VIP10 ["+((me->query("zjvip/all_pay") > 3000) ? "已达成":"未达成")+"] ["+((me->query("zjvip/10") ==1) ? "已领取":"未领取")+"]:vip 10"ZJSEP
        HIR"VIP称号[开]:vip kai"ZJSEP
        HIR"VIP称号[关]"NOR":vip guan";
        
		message("vision", str+"\n", me);		
	}
	else
	 if(arg=="1") 
	{	      
		if (me->query("zjvip/all_pay") < 100)
		return notify_fail(HIR"你的赞助贡献不足100点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
				if (me->query("zjvip/1")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			
        me->add("zjvip/level",1);
        me->set("zjvip/1",1);
        write(HIY"恭喜您达到了VIP1，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP1！");
}
else
		 if(arg=="2") 
	{	      
		if (me->query("zjvip/all_pay") < 300)
		return notify_fail(HIR"你的赞助贡献不足300点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/2")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
		if (me->query("zjvip/1")<1)
		return notify_fail(HIR"你还没激活VIP1，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/2",1);
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP2，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP2！");
}else
	 	 if(arg=="3") 
	{	      
		if (me->query("zjvip/all_pay") < 500)
		return notify_fail(HIR"你的赞助贡献不足500点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/3")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/2")<1)
		return notify_fail(HIR"你还没激活VIP2，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/3",1);
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP3，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP3！");
}else
	 if(arg=="4") 
	{	      
		if (me->query("zjvip/all_pay") < 800)
		return notify_fail(HIR"你的赞助贡献不足800点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/4")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/3")<1)
		return notify_fail(HIR"你还没激活VIP3，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/4",1);
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP4，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP4！");
}else
	 if(arg=="5") 
	{	      
		if (me->query("zjvip/all_pay") < 1000)
		return notify_fail(HIR"你的赞助贡献不足1000点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/5")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/4")<1)
		return notify_fail(HIR"你还没激活VIP4，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/5",1);
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP5，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP5！");
}else
	 if(arg=="6") 
	{	      
		if (me->query("zjvip/all_pay") < 1300)
		return notify_fail(HIR"你的赞助贡献不足1300点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/6")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/5")<1)
		return notify_fail(HIR"你还没激活VIP5，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/6",1);
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP6，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP6！");
}else
	 if(arg=="7") 
	{	      
		if (me->query("zjvip/all_pay") < 1500)
		return notify_fail(HIR"你的赞助贡献不足1500点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/7")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/6")<1)
		return notify_fail(HIR"你还没激活VIP6，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/7",1);
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP7，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP7！");
}else
	 if(arg=="8") 
	{	      
		if (me->query("zjvip/all_pay") < 1800)
		return notify_fail(HIR"你的赞助贡献不足1800点，你不能激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/8")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/7")<1)
		return notify_fail(HIR"你还没激活VIP7，请按顺序激活！"NOR"\n");		
		
				me->set("zjvip/8",1);
				
        me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP8，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP8！");
}else
	 if(arg=="9") 
	{	      
		if (me->query("zjvip/all_pay") < 2000)
		return notify_fail(HIR"你的赞助贡献不足2000点，你们激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");		
		if (me->query("zjvip/9")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/8")<1)
		return notify_fail(HIR"你还没激活VIP8，请按顺序激活！"NOR"\n");		
		
					me->set("zjvip/9",1);
         me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP9，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP9！");
}else
	 if(arg=="10") 
	{	      
		if (me->query("zjvip/all_pay") < 3000)
		return notify_fail(HIR"你的赞助贡献不足3000点，你们激活该成就！目前赞助：["+me->query("zjvip/all_pay")+"]点！"NOR"\n");	
		if (me->query("zjvip/10")==1)
		return notify_fail(HIR"请不要重复激活！"NOR"\n");		
			if (me->query("zjvip/9")<1)
		return notify_fail(HIR"你还没激活VIP9，请按顺序激活！"NOR"\n");		
		
			me->set("zjvip/10",1);
         me->add("zjvip/level",1);
        write(HIY"恭喜您达到了VIP10，感谢您的长期支持！"NOR"\n");
        CHANNEL_D->do_channel( this_object(), "rumor","恭喜："+me->query("name")+"达到了至尊VIP10！");
}else
if(arg=="kai")
{
if (me->query("zjvip/all_pay") < 100)
return notify_fail(HIR"连VIP1都没有开了有什么用？目前VIP等级：["+me->query("zjvip/level")+"]级！"NOR"\n");
me->set("zjvip/levelsss",1);
   write(HIY"开启VIP称号成功！"NOR"\n");
}else
if(arg=="guan")
{
if (me->query("zjvip/all_pay") < 100)
return notify_fail(HIR"连VIP1都没有关了有什么用？目前VIP等级：["+me->query("zjvip/level")+"]级！"NOR"\n");
me->set("zjvip/levelsss",0);
   write(HIY"关闭VIP称号成功！"NOR"\n");
}
else
if(arg=="kais")
{
if (me->query("zzdiy")<1)
return notify_fail(HIR"连自制称号限权都没有开了也没用！"NOR"\n");
me->set("zzdiysss",1);
   write(HIY"开启自制称号成功！"NOR"\n");
}if(arg=="guans")
{
if (me->query("zzdiy")<1)
return notify_fail(HIR"连自制称号限权都没有关了也没用！"NOR"\n");
me->set("zzdiysss",0);
   write(HIY"关闭自制称号成功！"NOR"\n");
}
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
