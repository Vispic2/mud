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
team=me->query_team();
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;

if(environment(me)->query("short")!=me->query_temp("tjob")
&& duration<17)
{
tell_object(me, HIY "\n奸细偷偷溜出了城，你任务失败！\n" NOR); 
me->delete_temp("tjob");
me->apply_condition("mptjob",0);
return 0;	
}
else     if (!duration)
{
message_vision(HIR"\n$N敌人的头领杀到了!!\n"NOR,me); 
	     obj=new(__DIR__"npc/jianxi"); 
   	     obj->do_copy(me,maxpot);
   	     obj->set("title",HIR"敌派奸细"NOR);
  	     obj->move(environment(me));
e=(int)me->query_skill("force",1)*4/5;
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
	     obj->kill_ob(me);me->kill(this_object());
  	     me->delete_temp("tjob");
  	     gift=new(__DIR__"npc/mijian");
  	     gift->set_temp("host",me->query("id"));
  	     gift->move(obj);
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
        me->apply_condition("mptjob", duration - 1);
tell_object(me, RED "\n任务紧急，请快速细致！\n" NOR); 
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
team=me->query_team();
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
for(i=100;i*i*i/10<=maxexp;i++);
maxpot=i;
        if (!me) return;
if (!me->query_temp("tjob")) return;
	    if (random(19)== 0)
	    {
	      obj=new("quest/menpai/jobnpc/btshan");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"白驼山首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 2)
	    {
	      obj=new("quest/menpai/jobnpc/tangmen");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"唐门首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 3)
	    {
	      obj=new("quest/menpai/jobnpc/feitian");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"御剑流首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 4)
	    {
	      obj=new("quest/menpai/jobnpc/wudujiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"五毒教首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 5)
	    {
	      obj=new("quest/menpai/jobnpc/lingxiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"凌霄城首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 1)
	    {
	      obj=new("quest/menpai/jobnpc/gumu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"古墓派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 2)
	    {
	      obj=new("quest/menpai/jobnpc/gaibang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"丐帮派首座弟子"NOR);     
              obj->move(environment(me));
   e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 3)
	    {
	      obj=new("quest/menpai/jobnpc/emei");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"峨嵋派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 4)
	    {
	      obj=new("quest/menpai/jobnpc/dali");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"大理国首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 5)
	    {
	      obj=new("quest/menpai/jobnpc/huashan");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"华山派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 6)
	    {
	      obj=new("quest/menpai/jobnpc/kunlun");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"昆仑派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 7)
	    {
	      obj=new("quest/menpai/jobnpc/shaolin");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"少林派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 8)
	    {
	      obj=new("quest/menpai/jobnpc/mr");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"慕容派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 9)
	    {
	      obj=new("quest/menpai/jobnpc/mingjiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"明教首座弟子"NOR);     
                 obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 10)
	    {
	      obj=new("quest/menpai/jobnpc/lingjiu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"灵鹫宫首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 11)
	    {
	      obj=new("quest/menpai/jobnpc/taohua");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"桃花岛首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 12)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan1");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"雪山派护教弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 13)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan2");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"雪山派护教法王"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 14)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan3");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"雪山派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 15)
	    {
	      obj=new("quest/menpai/jobnpc/xingxiu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"星宿派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 16)
	    {
	      obj=new("quest/menpai/jobnpc/wudang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"武当派首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 17)
	    {
	      obj=new("quest/menpai/jobnpc/tiezhang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"铁掌帮首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	    else 
	    if (random(19)== 18)
	    {
	      obj=new("quest/menpai/jobnpc/yunlong");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"云龙会首座弟子"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}
              obj->kill_ob(me);me->kill(this_object());
	     }
	      obj=new(__DIR__"npc/mengbing");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"蒙古勇士"NOR);     
              obj->move(environment(me));
e=(int)me->query_skill("force",1)*3/4;
if (random(5)==0) e=(int)me->query_skill("force",1)*4/5;
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
                 obj->kill_ob(me);me->kill(this_object());
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);
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
