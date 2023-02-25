// by name 2021.4.19
//QQ：3468713544
#include <ansi.h>
inherit F_SSERVER;
inherit F_SAVE;
inherit CLASS_D("generate") + "/chineses";
int is_sc(){ return 1; }
string query_save_file()
{
	string id;
	id = query("owner");
	if (! stringp(id))
	return 0;
	return sprintf(DATA_DIR "sc/%c/%s", id[0], id);
}	
void create()
{

	::create();
	set_name("随从", ({ "suicong" }));
	set("race", "人类");
	set("unit", "只"); 
	set("str", 10);
	set("int", 10);
	set("spi", 10);
	set("con", 10);
	set("dex", 10);
	set("no_sell", "这玩意不能卖！"); 
	set("qi", 100);
	set("max_qi", 100);
	set("eff_qi", 100);
	set("eff_jing", 100);	
	set("jing", 100);
	set("max_jing", 100);	
	set("neili", 100);
	set("max_neili", 100);    
	set("jingli", 100);
	set("max_jingli", 100);		 
	set("combat_exp", 10000);	
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defence",100);
	set_temp("apply/armor", 100);
    set_temp("apply/unarmed_damage",100);
	setup();
	call_out("jiazai",1);
}
string long()
{
	string result;
    object ob=this_object();
	result = query("long");
	return result;
}

int jiazai()
{
	object ob,me,emy;
	me = this_object();
	ob = find_player(""+query("owner")+"");	
	if(me->query("shimensss") == 1&&ob->query("shimensss") == 1){    
    me->force_me("shimensc");
    me->add("combat_pet",1);
    me->add("potential_pet",1);
    me->set("shimen",1);  //本次放出有奖励的标识
    }else{      
    if(typeof(ob)=="object"){	 
	if (!present(me,ob)&&!present(me,environment(ob))){
    me->move(environment(ob)); 
    }
	}else{
	save();
	destruct(me);	 
    }
    if(typeof(ob)=="object"){	
   	if(ob->is_fighting()){
	emy = offensive_target(ob);
	me->fight_ob(emy);
	}
    }   
}
call_out("jiazai",2);
}
int accept_object(object me,object ling)
{

    object ob;
    int i;
	me=this_player();
	ob=this_object();	
	if(query("owner")==me->query("id")){
    if(ling->query("money_id")){
	if(ling->value()<10000){
	command("say 只能给予黄金或银票！");
	return;
	}else{
	i=ling->value()/500;  
    ob->add("combat_exp",i);  
    command("say 给予成功，本次给予为随从提升了"+i+"点经验！");    
   }
   }else{
   command("say 目前升级随从只要黄金或者银票！");
   return;
   }
   save();
   return 1;
   }else{
   command("say 你不是我主人，我不能要你东西！！！");
   return;
  }
}
void die()
{	
    int jing, qi;	
	jing = (int) query("max_jing");
	qi = (int) query("max_qi");
    set("eff_qi", qi);
	set("eff_jing", jing);
	set("qi", qi);
	set("jing", jing);
	save();	
	return ::die();
}
void unconcious()
{
	die();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
