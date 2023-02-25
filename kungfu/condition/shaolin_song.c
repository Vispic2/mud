#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration) return 0;
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
                 && environment(me)->query("short")!="渡船"
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(2);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("shaolin_song", duration - 1);
}
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot;
	int maxexp;
	int maxskill;
        if (!me) return;
	maxskill=me->query_skill("force");
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp");
        if (maxskill<5)
        maxskill=5;
   	if(random(10)>6)
	{obj=new("/quest/menpaijob/huashan/xixia"+sprintf("%d",random(3)+1));
	 maxpot=maxpot+10+random(10);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("qi")* 3/4);
        obj->set("eff_qi", me->query("eff_qi")* 3/4);
        obj->set("max_qi", me->query("max_qi")* 3/4);
        obj->set("eff_jing", me->query("eff_jing")* 3/4);
        obj->set("max_jing", me->query("max_jing")* 3/4);
        obj->set("jing", me->query("jing")* 3/4);
        obj->set("neili", me->query("neili")* 3/4);
        obj->set("max_neili", me->query("max_neili")* 3/4);
        obj->set_skill("kuang-jian",maxskill*3/4);
        obj->set_skill("sword",maxskill*3/4);
        obj->set_skill("parry",maxskill*3/4);        
        obj->set_skill("zixia-shengong", maxskill*3/4);
        obj->set_skill("huashan-ken", maxskill*3/4);
        obj->set_skill("feiyan-huixiang", maxskill*3/4);

	 obj->set("title",HIR"邪派弟子"NOR);
	}
	else
	{
	 obj=new("/quest/menpaijob/huashan/xixia1");
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("qi")* 3/4);
        obj->set("eff_qi", me->query("eff_qi")* 3/4);
        obj->set("max_qi", me->query("max_qi")* 3/4);
        obj->set("eff_jing", me->query("eff_jing")* 3/4);
        obj->set("max_jing", me->query("max_jing")* 3/4);
        obj->set("jing", me->query("jing")* 3/4);
        obj->set("neili", me->query("neili")* 3/4);
        obj->set("max_neili", me->query("max_neili")* 3/4);
        obj->set_skill("kuang-jian",maxskill*3/4);
        obj->set_skill("sword",maxskill*3/4);
        obj->set_skill("parry",maxskill*3/4);        
        obj->set_skill("zixia-shengong", maxskill*3/4);
        obj->set_skill("huashan-ken", maxskill*3/4);
        obj->set_skill("feiyan-huixiang", maxskill*3/4);

         obj->set("combat_exp",maxexp);
	  maxpot=maxpot-random(10);
	 }
	obj->do_copy(maxpot);
	obj->move(environment(me));
	obj->set("title",HIR"邪派弟子"NOR);
	message_vision(HIR"\n$N对着$n大叫一声，杀啊!。\n"NOR,obj,me); 
	obj->kill_ob(me);
	obj->set_leader(me);
}

string query_type(object me)
{
	return "job";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
