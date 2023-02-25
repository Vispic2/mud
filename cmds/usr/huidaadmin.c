//inventory.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
string a,b;
object ob;
object *players;
int i,q=0,w=0,e=0,j,k,l;
string ll;
string *fk=({
      "#",
	});
	
      if(me->query("huida")!=1)
		{
		tell_object(me,HIY"你回答过了，不能再回答了！"NOR"\n"); 
	return 1;  
	   }
	   
	   
       if(!arg)
	   {
		tell_object(me,HIY"回答啥？"NOR"\n"); 
		return 1;  
	   }
	   
    foreach (ll in fk){
	if (strsrch(arg,ll) != -1)
	{
	write(HIR"不能包涵特殊符号。"NOR"\n");
	return 1;
	}
	}
	   
	   
	   
	      if (! me->query("born"))
		return notify_fail("你还没有出生呐？\n");
        if (me->is_ghost()) 
        return notify_fail("等你还了阳再说吧。\n");                 
        if (me->is_in_prison())   
        return notify_fail("你正在做牢呢。\n");
        if( me->query("doing") )
        return notify_fail("你还想干什么？！\n");
		
       if(sscanf(arg, "%s %s",a,b)!=2)
	   {
	  	write(INPUTTXT("请输入内容：""","huidaadmin $txt# "+arg)+"\n"); 
		return 1;
	   }
	       foreach (ll in fk){
	if (strsrch(arg,ll) != -1)
	{
	write(HIR"不能包涵特殊符号。"NOR"\n");
	}
	}
	 if(a==b)
		 {
		players = users();
		for(i = 0; i<sizeof(players); i++)
         {
			 if(players[i]->query("huida")==2)
               q=1;
		   else if(players[i]->query("huida")==3)
			   w=1;
		   else if(players[i]->query("huida")!=4)
			   e=1;
       }
	   if(q==0)
	   {
		   j=2000+random(500);
		   k=1600+random(500);
		me->set("huida",2);
		me->add("yuanbao",10);
		me->add("potential",j);
		me->add("combat_exp",k);
//CHANNEL_D->do_channel(this_object(), "chat", HIR"热烈恭喜！"HIC+me->query("name")+HIG"第一个抢答出来！"NOR"");
message("channel:chat",HIC"【闲聊】问答系统""："HIR"热烈恭喜！"HIC+me->query("name")+"("+me->query("id")+")，"+HIG+"第一个抢答出来！"NOR"\n",users());	
		tell_object(me,HIY"由于你是第一个回答出来，你获得了十个元宝,"+j+"点潜能,"+k+"点经验"NOR"\n");   
	   }else if(w==0)
	   {
		 j=1800+random(500);
		k=1000+random(300);
			me->add("potential",j);
		me->add("combat_exp",k);
		me->set("huida",3);
		me->add("yuanbao",5);
	//	me->add("yuanbao",1);
		message("channel:chat",HIC"【闲聊】问答系统""："HIR"热烈恭喜！"HIC+me->query("name")+"("+me->query("id")+")，"+HIG+"第二个抢答出来！"NOR"\n",users());	
//CHANNEL_D->do_channel(this_object(), "chat", HIR"热烈恭喜！"HIC+me->query("name")+HIG"第二个抢答出来！"NOR"");
		tell_object(me,HIY"由于你是第二个回答出来，你获得了五个元宝,"+j+"点潜能,"+k+"点经验"NOR"\n");  
	   }else if(e==0)
	   {
		   j=1000+random(500);
		   k=600+random(300);
		   	me->add("potential",j);
		me->add("combat_exp",k);
		me->set("huida",4);
		//me->add("yuanbao",1);
	message("channel:chat",HIC"【闲聊】问答系统""："HIR"热烈恭喜！"HIC+me->query("name")+"("+me->query("id")+")，"+HIG+"第三个抢答出来！"NOR"\n",users());	
//CHANNEL_D->do_channel(this_object(), "chat", HIR"热烈恭喜！"HIC+me->query("name")+HIG"第三个抢答出来！"NOR"");
		tell_object(me,HIY"由于你是第三个回答出来，你获得了"+j+"点潜能,"+k+"点经验"NOR"\n");  
	   }
	   else
	   {
		me->set("huida",5);
		   j=300+random(300);
		   k=200+random(200);
		   	me->add("potential",j);
		me->add("combat_exp",k);
	//	me->add("yuanbao",2);
	//	tell_object(me,HIY"你获得了两个元宝"NOR"\n"); 
		tell_object(me,HIY"回答正确，你获得了"+j+"点潜能,"+k+"点经验"NOR"\n");
	   }
		return 1;
		 }
		 else 
		 {
		tell_object(me,HIY"可惜，你回答错了！"NOR"\n"); 
		me->set("huida",0);
		return 1; 
		 }
	
		
}
int help (object me)
{
	tell_object(me,HIY"你对说道：“”。"NOR"\n");  
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
