
#include <ansi.h>
inherit F_CLEAN_UP;
//加个十连抽用for 寒江雪
int main(object me, string arg)
{
int i;
string str;
string sk;
object daoju;
string *random_ob=get_dir("/clone/vip1/");
string *sk_list = ({
		"qishang-quan",
		"qishang-quan",
		"qishang-quan",
		"qishang-quan",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"baihua-quan",
		"baihua-quan",
		"baihua-quan",
		"baihua-quan",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"sougu",
		"sougu",
		"yunlong-bian",
		"yunlong-shenfa",
		"hanxing-bada",
		"xuanming-zhang",
		"shenzhaojing",
});

	if(!arg)
	{
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
	  
		str = ZJOBLONG"幸运大抽奖。搏一搏单车变摩托，欧皇与非酋只再一瞬之间！！(剩余幸运抽奖次数：["+me->query("cjj")+"])\n";
		str += ZJOBACTS2+ZJMENUF(2,2,9,31);
		str +=
		HIY"幸运抽奖[单抽]:choujiang 1"ZJSEP			
		HIR"幸运抽奖[十抽]"NOR":choujiang 2"ZJSEP	                                	                                                                                  
        "返回:look"NOR;	
		message("vision", str+"\n", me);	
		}
		else
	if(arg=="1") 
	{	
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
    if (me->query("cjj") < 1)
    return notify_fail("幸运抽奖次数不足，请前往商场购买抽奖卷！\n");
    i= random(1000);
    //if(i == 500)
    if(0)
    {       
    sk = sk_list[random(sizeof(sk_list))];	
	me->add_skill(sk, 180);
	write(HIY"你抽到了"+to_chinese(sk)+"提升到了180级！\n"NOR );
	me->add("cjj",-1);
	CHANNEL_D->do_channel(this_object(),"rumor", me->query("name")+"在抽奖系统中获得了"+to_chinese(sk)+"技能，一统江湖指日可待啊！！");	
    me->start_busy(5);
	}else{
	string id = random_ob[random(sizeof(random_ob))];     	
	daoju=new("/clone/vip1/"+id+"");
    daoju->move(me);
    me->add("cjj",-1);
    CHANNEL_D->do_channel(this_object(),"rumor", me->query("name")+"在抽奖系统中获得了"+daoju->short()+"。");									
    me->start_busy(5);
    }
}
else
if(arg=="2") 
	{	
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
    if (me->query("cjj") < 10)
    return notify_fail("幸运抽奖次数不足，请前往商场购买抽奖卷！\n");
    
    for(int ttt=0;ttt<10;ttt++){
    i= random(1000);
    if(i == 500){			
	me->add_skill(sk, 180);
	write(HIY"你抽到了"+to_chinese(sk)+"提升到了180级！\n"NOR );	    
	me->add("cjj",-1);
	CHANNEL_D->do_channel(this_object(),"rumor", me->query("name")+"在抽奖系统中获得了"+to_chinese(sk)+"技能，一统江湖指日可待啊！！");	
	me->start_busy(50);
	}else{
	string id = random_ob[random(sizeof(random_ob))];     	
	daoju=new("/clone/vip1/"+id+"");
    daoju->move(me);
    me->add("cjj",-1);    
    CHANNEL_D->do_channel(this_object(),"rumor", me->query("name")+"在抽奖系统中获得了"+daoju->short()+"。");		    			
    me->start_busy(50);
    }        
   }    
  }
	return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
