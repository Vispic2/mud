#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "你的巡山任务的时间结束了。\n" NOR);
                return 0;
	}
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
         {
          me->start_busy(2);
          call_out("zuji", 0, me);    
     
	 }
        me->apply_condition("huaxunshan", duration - 1);
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
   	if(random(10)>7)
	{obj=new("/quest/menpaijob/huashan/xixia3");
	 maxpot=maxpot+10+random(10);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("qi")* 1/2);
        obj->set("eff_qi", me->query("eff_qi")* 1/2);
        obj->set("jing", me->query("jing")* 1/2);
        obj->set("neili", me->query("neili")* 1/2);
        obj->set("max_neili", me->query("max_neili")* 1/2);
        obj->set("eff_jing", me->query("eff_jing")* 1/2);
        obj->set_skill("kuang-jian",maxskill*3/4);
        obj->set_skill("sword",maxskill*3/4);
        obj->set_skill("parry",maxskill*3/4);        
        if ( me->query("combat_exp")>1000000)
        {
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("qi"));
        obj->set("eff_qi", me->query("eff_qi"));
        obj->set("jing", me->query("jing"));
        obj->set("neili", me->query("neili")* 3/4);
        obj->set("max_neili", me->query("max_neili")* 3/4);
        obj->set("eff_jing", me->query("eff_jing")* 3/4);
        obj->set_skill("dodge", maxskill+random(20));
        obj->set_skill("unarmed", maxskill*3/4);
        obj->set_skill("parry", maxskill*3/4);
        obj->set_skill("force", maxskill*3/4);
        obj->set_skill("zixia-shengong", maxskill*3/4);
        obj->set_skill("huashan-ken", maxskill*3/4);
        obj->set_skill("feiyan-huixiang", maxskill*3/4);


        obj->set("title",HIG"华山剑宗大弟子"NOR);
        obj->set_temp("apply/attack", 150);
        obj->set_temp("apply/defense",150);
        obj->set_temp("apply/armor", 150);
        obj->set_temp("apply/damage", 150);
         }
        if ( me->query("combat_exp")>4000000)
        {
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
        obj->set_skill("dodge", maxskill+random(20));
        obj->set_skill("unarmed", maxskill);
        obj->set_skill("parry", maxskill);
        obj->set_skill("force", maxskill);
        obj->set_skill("zixia-shengong", maxskill);
        obj->set_skill("huashan-ken", maxskill);
        obj->set_skill("feiyan-huixiang", maxskill);
        obj->set_skill("kuang-jian",maxskill);
        obj->set_skill("sword",maxskill);
        obj->set_skill("parry",maxskill);        

        obj->set("title",HIG"华山剑宗大弟子"NOR);
        obj->set_temp("apply/attack", 200);
        obj->set_temp("apply/defense",200);
        obj->set_temp("apply/armor", 200);
        obj->set_temp("apply/damage", 250);

         }
	 obj->set("title",HIG"华山剑宗大弟子"NOR);

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
        obj->set("max_neili", me->query("max_neili")* 1/2);
        obj->set("eff_jing", me->query("eff_jing")* 1/2);
        obj->set_skill("zixia-shengong", maxskill/2);
        obj->set_skill("huashan-ken", maxskill/2);
        obj->set_skill("feiyan-huixiang", maxskill/2);

        obj->set_skill("kuang-jian",maxskill/2);
        obj->set_skill("sword",maxskill/2);
        obj->set_skill("parry",maxskill/2);        
        obj->set("combat_exp",maxexp);
        obj->set("title",HIR"华山剑宗弟子"NOR);
	  maxpot=maxpot-random(10);
	 }
//	obj->do_copy(maxpot);
	obj->move(environment(me));
	message_vision(HIR"\n$N对着$n大叫一声，杀啊!。\n"NOR,obj,me); 
	obj->set_leader(me);
	obj->kill_ob(me);
	me->kill_ob(obj);
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
