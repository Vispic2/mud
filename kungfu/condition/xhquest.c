#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "你的的任务结束了，可以去要奖励了。\n" NOR);
                me->set_temp("xhjob_ok",1);
                me->apply_condition("xh_busy", 6);
                me->delete_temp("shouwei");
                me->delete_temp("xhjob_start");
                return 0;
	}
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
         {
          me->start_busy(1);
          call_out("zuji", 0, me);    
     
	 }
        me->apply_condition("xhquest", duration - 1);
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot;
	int maxexp;
	int maxskill;
	int maxqi;
        if (!me) return;
	maxskill=me->query_skill("force");
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp");
	maxqi=me->query("eff_qi");
        if (maxskill<5)
        maxskill=5;
   	if(random(10)>5)
	{
	obj=new("/quest/menpaijob/gaibang/mengu"+sprintf("%d",random(3)+1));
	 maxpot=maxpot+10+random(10);
        obj->set_skill("kuang-blade",maxskill*2/3);
        obj->set_skill("blade",maxskill*2/3);
        obj->set_skill("parry",maxskill*2/3);        
         obj->set("qi",maxqi);
         obj->set("jing",maxqi);
         obj->set("neili",maxqi);
         obj->set("combat_exp",maxexp);
         obj->set("qi",maxqi);
//	 obj->set("title",HIR"天字一号"NOR);
	}
	else
	{
	 obj=new("/quest/menpaijob/gaibang/mengu1");
        obj->set_skill("kuang-blade",maxskill*2/3);
        obj->set_skill("blade",maxskill*2/3);
        obj->set_skill("parry",maxskill*2/3);        
        obj->set("combat_exp",maxexp);
         obj->set("max_qi",maxqi);
         obj->set("max_jing",maxqi);
         obj->set("max_neili",maxqi);
         obj->set("qi",maxqi);
         obj->set("jing",maxqi);
         obj->set("neili",maxqi);


	  maxpot=maxpot-random(10);
	 }
	obj->do_copy(maxpot);
	obj->move(environment(me));
	obj->move(environment(me));
	message_vision(HIR"\n$N对着$n大叫一声，杀啊!。\n"NOR,obj,me); 
	obj->kill_ob(me);
	obj->kill_ob(me);
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
