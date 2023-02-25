//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int a,b;
	string user,str,hb,lx;
	string ssss;
	mapping bhinfo;
	object ob;
		if(!me->query_temp("pindao")||me->query_temp("pindao")!="chat")
		{
          me->set_temp("pindao","chat");
		}
		if(me->query_temp("pindao")!="chat")
	    return notify_fail("请把聊天频道切换到闲聊！\n");
	if (me->is_chatter())
		return notify_fail("聊天魂魄目前不能发红包。\n");
		if (!me->query("born"))
			return notify_fail("你还没出生呢。。。\n");
			if (! me->query("born"))
		return notify_fail("你还没有出生呐？\n");                 
        if (me->is_busy())
        return notify_fail("你正忙著呢。\n");
        if (me->is_fighting())
        return notify_fail("你现在正在战斗！\n"); 
        if (me->is_ghost()) 
        return notify_fail("等你还了阳再说吧。\n");                 
        if (me->is_in_prison())   
        return notify_fail("你正在做牢呢。\n");
        if( me->query("doing") )
        return notify_fail("你还想干什么？！\n");
	if (me->query("chblk_on"))
		return notify_fail("你的频道被关闭了，无法发放红包！\n");
		if (time() - me->query_temp("last_use_channel") < 4)
		{
			if (me->query_temp("last_message") == "chat")
				return notify_fail("不要在短期内使用频道发布重复的信息。\n");
		}	
	
	hb="元宝";
	if(arg=="元宝")
	hb="元宝";
	//else if(arg=="元宝票")
	//hb="元宝票";
	
	if (!arg||sscanf(arg,"%d",a)!=1)
	{
		write(INPUTTXT("你目前红包类型为"+hb+"，请输入红包金额:","fahb $txt# "+hb+"")+"\n"+ZJOBACTS2+ZJMENUF(3,3,9,30)""HIY"元宝红包"NOR":fahb 元宝\n");
		return 1;
	}
	
		if (sscanf(arg,"%d %s %d",a,hb,b)!=3)
	{
		write(INPUTTXT("请输入领取人数：","fahb "+arg+" $txt# ")+"\n"); 
		return 1;
	}
		
	   
	if(a<10)
	return notify_fail("红包金额最低不能少于10哦 \n");
	if(b<1||b>10)
	return notify_fail("领取人数最低不能少于1，最大不能超过10哦 \n");

	if(hb=="元宝")
	{
	if(me->query("yuanbao")<a)
	return notify_fail("你的元宝不够！\n");
    me->add("yuanbao",-a);
    me->add("hongbao/"+me->query("fahbcs")+"/hblx","元宝");
    CHANNEL_D->do_channel(me,""+me->query_temp("pindao/id")+"", ""HIY"『"+ZJSIZE(25)+ZJURL("cmds:lingqhb "+me->query("id")+" "+me->query("fahbcs")+"")+ZJSIZE(25)+HIY+ZJSIZE(25)+"元宝红包来了"HIY"』！"NOR"");
	}
	/*
	if(hb=="元宝票")
	{
	if(me->query("yuanbaos")<a)
	return notify_fail("你的元宝票不够！\n");
    me->add("yuanbaos",-a);
    me->add("hongbao/"+me->query("fahbcs")+"/hblx","元宝票");
    CHANNEL_D->do_channel(me,""+me->query_temp("pindao/id")+"", ""HIY"『"+ZJSIZE(25)+ZJURL("cmds:lingqhb "+me->query("id")+" "+me->query("fahbcs")+"")+ZJSIZE(25)+HIY+ZJSIZE(25)+"元宝票红包来了"HIY"』！"NOR"");
	}
		
	*/
	
    me->add("hongbao/"+me->query("fahbcs")+"/hbje",a);
	me->add("hongbao/"+me->query("fahbcs")+"/lqcs",b);
	me->add("fahbcs",1);
	//log_files("cmds/hb", sprintf("%s：%s(%s)发送了红包，金额："+a+"，包数："+b+"。\n",ctime(time()),me->query("name"),me->query("id")));
	
}

int help (object me)
{

	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
