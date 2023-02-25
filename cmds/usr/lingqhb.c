//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	    object ob,obj;
		string user,hb,yqh,yqc,ssss,lop;
		int b,c,h,max,min,j,kj,jh;
        if(!arg)
		return notify_fail("你要领取什么？\n");
	    
	if (sscanf(arg, "%s %d",arg,h) != 2)
	return notify_fail("没有这个红包！\n");
		
	user = lower_case(arg);
	if(!(ob=find_player(arg)))
	{
		ob = new(LOGIN_OB);
		ob->set("id",arg);
		ob->set("body", USER_OB);
		ob = LOGIN_D->make_body(ob);
		destruct(ob);
	}
	if(!ob)
	return notify_fail("红包已经领取完！\n");
	b=ob->query("hongbao/"+h+"/hbje");
	c=ob->query("hongbao/"+h+"/lqcs");
	if(c<=0)
	{
		ob->delete("hongbao/"+h+"");
		ob->save();
	return notify_fail("红包已经领取完！\n");
	}
	if(me->query("lingquhb/"+arg+"/"+h+""))
	return notify_fail("你已经领取过这个红包，不能再领取！\n");
    ob->add("hongbao/"+h+"/lqcs",-1);
	ob->save();
	me->add("lingquhb/"+arg+"/"+h+"",1);
	max=(b/c)+(b/(c*2));
	min=b/(c*2);
	j=random(max-min)+min;
    if(!(hb=ob->query("hongbao/"+(ob->query("fahbcs")-1)+"/hblx")))
	return notify_fail("红包类型有误！\n");
	if(hb=="元宝")
	{
	if(ob->query("hongbao/"+h+"/lqcs")==0)
	{
	  j=ob->query("hongbao/"+h+"/hbje");
	  ob->add("hongbao/"+h+"/hbje",-j);
	  ob->save();
	  me->add("yuanbao",j);	
	  if(ob->query("hongbao/"+h+"/max"))
	  {
		if(j>ob->query("hongbao/"+h+"/maxsz"))
		{
		ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save();
		}
		lop=ob->query("hongbao/"+h+"/max");
        yqh = lower_case(lop);
	    if(!(obj=find_player(lop)))
	    {
		obj = new(LOGIN_OB);
		obj->set("id",lop);
		obj->set("body", USER_OB);
		obj = LOGIN_D->make_body(obj);
		destruct(obj);
	    }
		if(ob&&obj)
		CHANNEL_D->do_channel(ob,""+ob->query_temp("pindao/id")+"",""HIY"『元宝红包』"HIC"已经领取完，〖"WHT+obj->query("name")+HIC"〗是"MAG"运气王"HIC"，领取到"HIR+ob->query("hongbao/"+h+"/maxsz")+HIC"点元宝!"NOR"\n");
	  }
       else{
		ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save(); 
		lop=ob->query("hongbao/"+h+"/max");
		 if(!(obj=find_player(lop)))
	    {
		obj = new(LOGIN_OB);
		obj->set("id",lop);
		obj->set("body", USER_OB);
		obj = LOGIN_D->make_body(obj);
		destruct(obj);
	    }
		if(ob&&obj)
		CHANNEL_D->do_channel(ob,""+ob->query_temp("pindao/id")+"",""HIY"『元宝红包』"HIC"已经领取完，〖"WHT+obj->query("name")+HIC"〗是"MAG"运气王"HIC"，领取到"HIR+ob->query("hongbao/"+h+"/maxsz")+HIC"点元宝!"NOR"\n");
	   }	  
	}
	else{
	ob->add("hongbao/"+h+"/hbje",-j);
	ob->save();
	me->add("yuanbao",j);
	if(ob->query("hongbao/"+h+"/max"))
	{
	if(j>ob->query("hongbao/"+h+"/maxsz"))
		{
		ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save();
		}	
	}
	else
	{
ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save(); 
	}
	}
	//log_files("cmds/hb", sprintf("%s：%s(%s)领取了"+ob->query("name")+"("+ob->query("id")+")的红包，领取到了："+j+"个元宝。\n",ctime(time()),me->query("name"),me->query("id")));	
	tell_object(ob,HIW""+me->query("name")+"领取了你的"HIR"红包"HIW"，获得了"HIY+j+HIW"点元宝"NOR"!\n目前剩余"HIR"红包"HIC"个数"HIY+ob->query("hongbao/"+h+"/lqcs")+HIC"个!\n"HIR"红包"HIC"剩余金额"HIY+ob->query("hongbao/"+h+"/hbje")+HIC"！"NOR"\n");  
	return notify_fail(HIC"你领取了一个"HIR"红包"HIC"!\n你获得了"HIY+j+HIC"个元宝!\n目前剩余"HIR"红包"HIC"个数"HIY+ob->query("hongbao/"+h+"/lqcs")+HIC"个!\n"HIR"红包"HIC"剩余金额"HIY+ob->query("hongbao/"+h+"/hbje")+HIC"！"NOR"\n\n");
	}
	
else if(hb=="元宝票")
	{
	if(ob->query("hongbao/"+h+"/lqcs")==0)
	{
	  j=ob->query("hongbao/"+h+"/hbje");
	  ob->add("hongbao/"+h+"/hbje",-j);
	  ob->save();
	  me->add("jifeng",j);
	   if(ob->query("hongbao/"+h+"/max"))
	  {
		if(j>ob->query("hongbao/"+h+"/maxsz"))
		{
		ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save();
		}
		lop=ob->query("hongbao/"+h+"/max");
        yqh = lower_case(lop);
	    if(!(obj=find_player(lop)))
	    {
		obj = new(LOGIN_OB);
		obj->set("id",lop);
		obj->set("body", USER_OB);
		obj = LOGIN_D->make_body(obj);
		destruct(obj);
	    }
		if(ob&&obj)
	CHANNEL_D->do_channel(ob,""+ob->query_temp("pindao/id")+"",""HIY"『元宝票红包』"HIC"已经领取完，〖"WHT+obj->query("name")+HIC"〗是"MAG"运气王"HIC"，领取到"HIR+ob->query("hongbao/"+h+"/maxsz")+HIC"点元宝票!"NOR"\n");
	  }
       else{
		ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save();
		lop=ob->query("hongbao/"+h+"/max");
		 if(!(obj=find_player(lop)))
	    {
		obj = new(LOGIN_OB);
		obj->set("id",lop);
		obj->set("body", USER_OB);
		obj = LOGIN_D->make_body(obj);
		destruct(obj);
	    }
		if(ob&&obj)
	CHANNEL_D->do_channel(ob,""+ob->query_temp("pindao/id")+"",""HIY"『元宝票红包』"HIC"已经领取完，〖"WHT+obj->query("name")+HIC"〗是"MAG"运气王"HIC"，领取到"HIR+ob->query("hongbao/"+h+"/maxsz")+HIC"点元宝票!"NOR"\n");
	   }
	}
	else{
	ob->add("hongbao/"+h+"/hbje",-j);
	ob->save();
	me->add("jifeng",j);
		if(ob->query("hongbao/"+h+"/max"))
	{
	if(j>ob->query("hongbao/"+h+"/maxsz"))
		{
		ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save();
		}	
	}
	else
	{
ob->set("hongbao/"+h+"/max",me->query("id"));
        ob->set("hongbao/"+h+"/maxsz",j);		
	    ob->save(); 
	}
	}
	//log_files("cmds/hb", sprintf("%s：%s(%s)领取了"+ob->query("name")+"("+ob->query("id")+")的红包，领取到了："+j+"个元宝。\n",ctime(time()),me->query("name"),me->query("id")));	
	tell_object(ob,HIW""+me->query("name")+"领取了你的"HIR"红包"HIW"，获得了"HIY+j+HIW"点元宝票"NOR"!\n目前剩余"HIR"红包"HIC"个数"HIY+ob->query("hongbao/"+h+"/lqcs")+HIC"个!\n"HIR"红包"HIC"剩余金额"HIY+ob->query("hongbao/"+h+"/hbje")+HIC"！"NOR"\n");  
	return notify_fail(HIC"你领取了一个"HIR"红包"HIC"!\n你获得了"HIY+j+HIC"个元宝票!\n目前剩余"HIR"红包"HIC"个数"HIY+ob->query("hongbao/"+h+"/lqcs")+HIC"个!\n"HIR"红包"HIC"剩余金额"HIY+ob->query("hongbao/"+h+"/hbje")+HIC"！"NOR"\n\n");
	}
	
	
	

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
