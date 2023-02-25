#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
object obj,gift;
    object *team;
        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int k,a,b,c,d,e,f,temp;
int maxpot,maxexp,minexp;      
     int i=0,count=0;
maxexp=me->query("combat_exp");
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;

if(environment(me)->query("short")!=me->query_temp("mjtjob")
&& duration<17)
{
tell_object(me, HIY "\n五大门派杀进来了，你任务失败！\n" NOR); 
me->delete_temp("mjtjob");
me->apply_condition("mjtjob",0);
return 0;	
}
else     if (!duration)
{
message_vision(HIR"\n$N敌人的首领杀到了!!\n"NOR,me); 
				obj=new("/quest/menpaijob/mingjiao/jianxi"); 
				obj->do_copy(me,maxpot);

				obj->set("title",HIG"五派首领"NOR);
                                obj->set_temp("hostmj",me->query("id"));
				obj->move(environment(me));
e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//删除自己所有功夫
}				
				message_vision(HIY"$N狂笑不已：就凭你们几个也想挡住我的去路?\n"NOR, obj);
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
        me->apply_condition("mjtjob", duration - 1);
tell_object(me, RED "\n五大门派要杀到了，请快点救援！\n" NOR); 
}
        return 1;
}


void zuji(object me)
{   
    object *team,obj,gift;
int maxpot,maxexp,minexp;      

        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int k,a,b,c,d,e,f,temp;
 
     int i=0,count=0;
maxexp=me->query("combat_exp");
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;
        if (!me) return;
if (!me->query_temp("mjtjob")) return;
if (random(20)>15)
			{ obj=new("/quest/menpaijob/mingjiao/wudang");   
	          obj->do_copy(me,maxpot,3);
	          obj->set("title",HIY"武当派弟子"NOR);     
              obj->move(environment(me));
              e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//删除自己所有功夫
}
              obj->kill_ob(me);
			}
		     else 
			{
	  	      obj=new("/quest/menpaijob/mingjiao/emei"); 
		      obj->do_copy(me,maxpot,1);
	          obj->set("title",HIG"峨嵋派弟子"NOR);
	          obj->move(environment(me));
e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//删除自己所有功夫
}
              obj->kill_ob(me);
	          obj=new("/quest/menpaijob/mingjiao/shaolin");
	           obj->set("title",HIW"少林派弟子"NOR);
		      if (random(20)>5)
			  {obj->do_copy(me,maxpot,2);
	           obj->set("title",HIW"少林派弟子"NOR);
			  }
			   else 
               obj->do_copy(me,maxpot,1);
		       obj->move(environment(me));
e=(int)me->query_skill("force",1)*2/3;
if (!me->query_skill("force")) e=320;
if (e<= 300) e=320;
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->set_skill(sname[i],e);//删除自己所有功夫
}
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
