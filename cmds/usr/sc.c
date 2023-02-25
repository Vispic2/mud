// by name 2021.4.19
//QQ：3468713544
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    int i,sc_exp,sc_lvl;     
    string skill,msg;
    object *scs,sc;	
    mapping *sk;
//   if(arg=="scsx"){
   if(!arg){
//   if(!wizardp(me))
//return notify_fail("只有巫师才能这么操作！\n");
   if(me->query("scs")<1){
   return notify_fail(ZJOBLONG"你想对随从进行什么操作：\n"
   ZJOBACTS2+ZJMENUF(3,3,8,31)+"招募随从:sc zhaomu\n");
   }else{ 
   if(!me->query("scs"))
   return notify_fail("你还没有随从呢！\n");  
   msg=ZJOBLONG+"你想对随从进行什么操作：\n";
   msg+=ZJOBACTS2+ZJMENUF(2,2,9,31);
//   if(!me->query_temp("sc_zhaohuan")){
   msg+="召唤随从:sc call"ZJSEP;
//   }else{
   msg+=HIR"收回随从"NOR":sc gone"ZJSEP;
   
 //  if(!me->query("sc_quest")){
   msg+="开始任务:sc quest"ZJSEP;
//   }else{
   msg+=HIR"结束任务"NOR":sc no"ZJSEP;
//   }
//   if(!me->query_temp("sc_guard")){
   msg+="保护模式:sc guard"ZJSEP;
//   }else{
   msg+=HIR"取消保护"NOR":sc guards"ZJSEP;
//   }
   msg+="提升等级:sc lvl"ZJSEP;
   msg+="修改描述:sclong";
  // msg+="执行命令:sc cmd\n";
   write(msg+"\n");
   }
   }else 
   if(arg=="zhaomu"){			
   if(me->query("scss")<1){
   if (me->query("balance") < 1000000)
   return notify_fail("你钱庄存款不足，不能进行招募随从，需要100量黄金！\n");		
	sc = new("/clone/sc/sc");
	sc->set_name("影·"+me->query("name"),({me->query("id")+" sc"}));
	sc->set("owner",me->query("id"));
	sc->set("sc",1);
	sc->set("scsss_key",1);
	sc->move(environment(me));
//	sc->set_leader(me);  
//sc->force_me("follow "+sc->query("owner")+"");
	me->set("scs",1);
	me->add("balance",-1000000);
	me->set("namesuicong","影·"+me->query("name"));
	me->set("namesuicongid",me->query("id")+" sc");
	sc->save();
	write("领取招募成功\n");	
    }else
   	if(me->query("scs") < 1 )
   	{
	sc = new("/clone/sc/sc");
	sc->set_name("影·"+me->query("name"),({me->query("id")+" sc"}));
	sc->set("owner",me->query("id"));
	sc->set("sc",1);
	sc->set("scsss_key",1);
	sc->move(environment(me));
//	sc->set_leader(me);  
//sc->force_me("follow "+sc->query("owner")+"");
	me->set("scs",1);
	me->set("scss",0);
	me->set("namesuicong","影·"+me->query("name"));
	me->set("namesuicongid",me->query("id")+" sc");
	sc->save();
	write("重新招募随从成功\n");	
    }else{
    write("你已经有随从了，可以使用指令：sc gone召唤\n");   
    }   
	}else
	if(arg=="call")
	{
    if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
    if(me->query("shimensss"))
    return notify_fail("你的随从正在任务中呢！\n");
	scs = children("/clone/sc/sc");
	for(i=0;i<sizeof(scs);i++){
    if(scs[i]->query("owner")==me->query("id")){
	scs[i]->set("qi",me->query("max_qi"));
	scs[i]->set("eff_qi",me->query("max_qi"));
    scs[i]->set("max_qi",me->query("max_qi"));			
	scs[i]->set("max_neili",me->query("max_neili"));
	scs[i]->set("neili",me->query("max_neili"));
	scs[i]->set("max_jing",me->query("max_jing"));
	scs[i]->set("jing",me->query("max_jing"));
    scs[i]->set("eff_jing",me->query("eff_jing"));
	scs[i]->set("max_jingli",me->query("max_jingli"));
	scs[i]->set("jingli",me->query("max_jingli"));		
	scs[i]->set("int",me->query("int"));		
	scs[i]->set("str",me->query("str"));	
	scs[i]->set("dex",me->query("dex"));	
	scs[i]->set("con",me->query("con"));				
	scs[i]->move(environment(me));
	return 1;
	}
}
		sc = new("/clone/sc/sc");
		sc->set("owner",me->query("id"));
		sc->set_name(sc->query("name"),({me->query("id")+" sc"}));
		sc->restore();
        sc->set("scsss_key",1);
        me->set_temp("sc_zhaohuan",1);
		sc->move(environment(me));
		sc->save();		
		write("召唤随从成功。\n");
}else if(arg=="gone")
{
	  if(!me->query("scs"))
      return notify_fail("你还没有随从呢！\n");       
      if(me->query("shimensss"))
      return notify_fail("你的随从正在任务中呢！\n");      
	  scs = children("/clone/sc/sc");
	  for(i=0;i<sizeof(scs);i++){
	  if(scs[i]->query("owner")==me->query("id")){
	  scs[i]->set("qi",me->query("max_qi"));
	  scs[i]->set("eff_qi",me->query("max_qi"));
	  scs[i]->set("max_qi",me->query("max_qi"));			
 	  scs[i]->set("max_neili",me->query("max_neili"));
	  scs[i]->set("neili",me->query("max_neili"));
	  scs[i]->set("eff_jing",me->query("eff_jing"));
	  scs[i]->set("max_jing",me->query("max_jing"));
	  scs[i]->set("jing",me->query("max_jing"));
	  scs[i]->set("max_jingli",me->query("max_jingli"));
	  scs[i]->set("jingli",me->query("max_jingli"));		
	  scs[i]->set("int",me->query("int"));		
	  scs[i]->set("str",me->query("str"));	
	  scs[i]->set("dex",me->query("dex"));	
	  scs[i]->set("con",me->query("con"));	
	  me->delete_temp("sc_zhaohuan");
	  scs[i]->save();						
	  destruct(scs[i]);
	  
	  write("你的随从被收回去了。\n");
	  return 1;
	}
}
    return notify_fail("你的随从已经收回去了！\n");
    }else if(arg=="lvl"){		
    if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
	if(!(sc=present(me->query("id")+" sc",environment(me))))
    return notify_fail("你的随从不在你身边，无法升级！\n");    	
   sk=keys(sc->query_skills());
   sc_exp=sc->query("combat_exp");
   sc_lvl=(sc_exp/10000)+1;
   
   
   
 //  if(sc_lvl>=300) sc_lvl=300;
 
 
 
   //sc_lvl=sqrt3(sc_exp);
   write(HIC"=----------------------------------="NOR"\n");
   foreach(skill in sk){
   sc->set_skill(skill,sc_lvl);
   }
   write(HIC"目前随从技能等级："+sc_lvl+"\n目前随从经验值："+sc_exp+"\n下一级需要经验："+((sc_exp+10000)+1)+""NOR"\n");
   write(HIC"=----------------------------------="NOR"\n");
   sc->save();	
   return 1;	
}else if(arg=="quest"){
    if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
    if(me->query("shimensss"))
    return notify_fail("你的随从正在任务中呢！\n");
	if(!(sc=present(me->query("id")+" sc",environment(me))))
    return notify_fail("你的随从不在你身边，无法进行任务！\n");
    if(sc->query_skill("force",1) <100)
    return notify_fail("随从内功等级至少要100级才能做任务！\n");    
   	sc->set("shimensss",1);	
    sc->delete("combat_pet");	
    sc->delete("potential_pet");	
    sc->save();      
	me->set("shimensss",1);	
	me->set("sc_quest",1);
    write(HIR"开始任务模式成功，注：如果随从长时间为动，收回放出，再开始任务即可。"NOR"\n");
	return 1;	 	
}else if(arg=="no"){
	    if(!me->query("scs"))
        return notify_fail("你还没有随从呢！\n");
		scs = children("/clone/sc/sc");
		for(i=0;i<sizeof(scs);i++){
		if(scs[i]->query("owner")==me->query("id")){
		if(scs[i]->query("shimen") < 1){			
		scs[i]->move(environment(me));
		scs[i]->delete("shimensss");
		me->delete("shimensss");
		write(HIC"结束任务模式"NOR"\n");				
		}else{			
		scs[i]->move(environment(me));
		scs[i]->delete("shimensss");
		scs[i]->delete("shimen");
		scs[i]->force_me("give "+scs[i]->query("owner")+" all");
		me->delete("shimensss");
		me->add("combat_exp",scs[i]->query("combat_pet")*1);
		me->add("potential",scs[i]->query("potential_pet")*1);
		write(HIG"结束任务模式，你获得了："+scs[i]->query("combat_pet")*1+"点经验，"+scs[i]->query("potential_pet")*1+"点潜能！"NOR"\n");		
		scs[i]->delete("combat_pet");
	    scs[i]->delete("potential_pet");
		}
		me->delete("sc_quest");
		return 1;
	}
}
	me->set("shimensss",0);
    write("结束任务模式成功\n");
}else if(arg=="guard"){	
	if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
    if(me->query("shimensss"))
    return notify_fail("你的随从正在任务中呢！\n");
	if(!(sc=present(me->query("id")+" sc",environment(me))))
    return notify_fail("你的随从不在你身边，无法进行保护！\n");
    sc->force_me("guard "+sc->query("owner"));	
    me->set_temp("sc_guard",1);
    write("你的随从开始保护你了\n");	
}else if(arg=="guards"){		
	if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
    if(me->query("shimensss"))
    return notify_fail("你的随从正在任务中呢！\n");
	if(!(sc=present(me->query("id")+" sc",environment(me))))
    return notify_fail("你的随从不在你身边，无法进行取消保护！\n");
    sc->force_me("guard cancel");	
    me->delete_temp("sc_guard");
    write("你的随从取消保护你了\n");	
}else{
if(!wizardp(me))
return notify_fail("只有巫师才能这么操作！\n");
if(!me->query("scs"))
return notify_fail("你还没有随从呢！\n");
if(me->query("shimensss"))
return notify_fail("你的随从正在任务中呢！\n");
if(!(sc=present(me->query("id")+" sc",environment(me))))
return notify_fail("你的随从不在你身边，无法执行命令！\n");
write(INPUTTXT("请输入想让随从执行的命令", "sc $txt#") + "\n");	
sc->force_me(arg);
write("命令："+arg+"\n");
return 1;
}		
/*
}else{
write("暂时不开放\n");
}
*/
	return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
