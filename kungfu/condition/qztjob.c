#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
object obj,gift;
    object *team;

int maxpot,maxexp,minexp;      
     int i=0,count=0;
maxexp=me->query("combat_exp");
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;

if(environment(me)->query("short")!=me->query_temp("qztjob")
&& duration<17)
{
tell_object(me, HIY "\n敌人杀进来了，你任务失败！\n" NOR); 
me->delete_temp("qztjob");
me->apply_condition("qztjob",0);
return 0;	
}
else     if (!duration)
{
message_vision(HIR"\n$N敌人的法王杀到了!!\n"NOR,me); 
				obj=new("/quest/menpaijob/quanzhen/jianxi"); 
				obj->do_copy(me,maxpot);
				obj->set("title",HIG"蒙古护教法王"NOR);
				obj->move(environment(me));
                                obj->set_temp("host",me->query("id"));
				message_vision(HIY"$N狂笑不已：快点接受大汉的封教,不然全部叫你们死光!!\n"NOR, obj);
				obj->kill_ob(me);
      return 0;
}
else  	 if( duration%3==0 && duration <17
		 &&!environment(me)->query("no_fight")
		 )
       {  me->start_busy(1);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("qztjob", duration - 1);
tell_object(me, RED "\n任务紧急，请快速细致！\n" NOR); 
}
        return 1;
}


void zuji(object me)
{   
    object *team,obj,gift;
int maxpot,maxexp,minexp;      
     int i=0,count=0;
maxexp=me->query("combat_exp");
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;
        if (!me) return;
if (!me->query_temp("qztjob")) return;
if (random(20)>15)
			{ obj=new("/quest/menpaijob/quanzhen/mengu3");   
	          obj->do_copy(me,maxpot,3);
	          obj->set("title",HIY"蒙古兵"NOR);     
              obj->move(environment(me));
              obj->kill_ob(me);
			}
		     else 
			{
	  	      obj=new("/quest/menpaijob/quanzhen/mengu3"); 
		      obj->do_copy(me,maxpot,1);
	          obj->set("title",HIG"蒙古兵"NOR);
	          obj->move(environment(me));
              obj->kill_ob(me);
	          obj=new("/quest/menpaijob/quanzhen/mengu3");
	           obj->set("title",HIW"蒙古兵"NOR);
		      if (random(20)>5)
			  {obj->do_copy(me,maxpot,2);
	           obj->set("title",HIW"蒙古兵"NOR);
			  }
			   else 
               obj->do_copy(me,maxpot,1);
		       obj->move(environment(me));
               obj->kill_ob(me);
}
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
