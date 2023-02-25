// time.c					  
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string amr,str;
	string wizstr="",strurl="";
	if(!arg)
	{
		if(!me->query_temp("pindao"))
		{
			arg = "chat";
			str = "闲聊";
		}
				
	}
	else if(sscanf(arg,"voice %s",amr)==1)
	{
		CHANNEL_D->do_channel(me,me->query_temp("pindao/id"),ZJSIZE(22)+ZJURL("voice:"+amr)+HIG"语音消息"NOR);
		return 1;
	}
	else if(arg=="yuyin")
	{
		return notify_fail(HIR"你的客户端版本不支持语音消息！"NOR"\n");
	}
	else if(arg=="chat")
	{
		str = "闲聊";
	}
	else if(arg=="send")
	{
		str = "跨服";
	}
	else if(arg=="rumor")
	{
		str = "谣言";
	}
	
	else if(arg=="sos")
	{
		str = "求助";
	}
	else if(arg=="party")
	{
		str = "帮派";
	}
	else if(arg=="family")
	{
		str = "同门";
	}
	else if(arg=="jiaoyi")
	{
		str = "拍卖";
	}
	else if(arg=="bill")
	{
		str = "交易";
	}
	else if(arg=="ultra")
	{
		str = "宗师";
	}
	else if(arg=="rultra")
	{
		str = "塞外宗师";
	}
	else if(arg=="inter")
	{
		str = "联盟";
	}
	else if(arg=="pindao")
	{
	write(ZJOBLONG"请选择聊天频道：\n"+ZJOBACTS2+ZJMENUF(3,3,9,31)+"闲聊:liaotian chat"ZJSEP"跨服:send"ZJSEP"谣言:liaotian rumor"ZJSEP"求助:liaotian sos"ZJSEP"同门:liaotian family"ZJSEP"帮派:liaotian party"ZJSEP"交易:liaotian bill"ZJSEP"宗师:liaotian ultra"+"\n");
	return 1;
	}
	else if(arg=="wiz")
	{
		str = HIY"巫师"NOR;
	}
	else if(arg=="bc"){
		me->set_temp("liao_open",1);
		me->force_me("liaotian");
		write(HIG"你已设置为发送信息后，聊天窗口保持不关闭。"NOR"\n");
		return 1;
	}
	else if(arg=="qx"){
		me->delete_temp("liao_open");
		write(HIR"你已设置为发送信息后，聊天窗口自动关闭。"NOR"\n");
		me->force_me("liaotian");
		return 1;
	}else{
	str = arg;	
	}
	if(me->query_temp("liao_open")){
		strurl = ZJURL("cmds:liaotian qx")BOLD+WHT"取消保持"+NOR+NOR;
	}else{
		strurl = ZJURL("cmds:liaotian bc")BOLD+GRN"保持窗口"+NOR+NOR;
	}
	

	if(arg)
	{
		me->set_temp("pindao/id",arg);
		me->set_temp("pindao/name",str);
	}
//	write(INPUTTXT("当前频道【"HIY+me->query_temp("pindao/name")+NOR"】，请输入内容："+strurl,me->query_temp("pindao/id")+" $txt#")+"\n"+ZJOBACTS2+ZJMENUF(3,3,9,30)"选择频道:liaotian pindao"ZJSEP"表情动作:emote"ZJSEP"发送语音:liaotian yuyin\n");		 		 
	
	if(!me->query("web")){
		write(INPUTTXT("当前频道【"HIY+me->query_temp("pindao/name")+NOR"】，请输入内容：  "+strurl,
			me->query_temp("pindao/id")+" $txt#")+"\n"
			+ZJOBACTS2+ZJMENUF(4,4,9,30)
			+""HIW"选择频道"NOR":liaotian pindao"ZJSEP		
			+""CYN"表情动作"NOR":emote"ZJSEP		
			+""HIR"发送表情"NOR":biaoqing\n"
			);
	
	}else{
	
	write(INPUTTXT("当前频道【"HIY+me->query_temp("pindao/name")+NOR"】，请输入内容：  "+strurl,
			me->query_temp("pindao/id")+" $txt#")+"\n"
			+ZJOBACTS2+ZJMENUF(4,4,9,30)
			+""HIC"闲聊"NOR":liaotian chat"ZJSEP
			+""HIM"谣言"NOR":liaotian rumor"ZJSEP
			+""HIG"求助"NOR":liaotian sos"ZJSEP
			+""CYN"同门"NOR":liaotian family"ZJSEP
			+""RED"帮派"NOR":liaotian party"ZJSEP
			+""HIY"交易:liaotian bill"ZJSEP		
			+""WHT"宗师"NOR":liaotian ultra"ZJSEP	
			+""HIW"跨服"NOR":send"ZJSEP			
			+""CYN"表情动作"NOR":emote"ZJSEP		
			+""HIR"发送表情"NOR":biaoqing\n"
			);
	
	
	}
		
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令告诉你现实世界中现在的时间。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
