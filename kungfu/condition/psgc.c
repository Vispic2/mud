#include <ansi.h>
#include <login.h>
#include <condition.h>



inherit F_CLEAN_UP;
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
//tell_object(me, RED "\n师门正在对你进行追杀，万事还是小心为好!\n" NOR); 
   if (duration==799)
{
						CHANNEL_D->do_channel(this_object(), "rumor",sprintf("听说%s背叛了师门。",
								me->name(1), me->name()));
message_vision(HIG"\n$N以前的师门正在对你进行追杀，万事还是小心为好!\n"NOR,me); 
}
   if (!duration)
{
message_vision(HIG"\n$N以前的门派，终于取消了对你的江湖通缉!!\n"NOR,me); 
}
        me->apply_condition("psgc", duration - 1);

if( random(88)==0
		 &&!environment(me)->query("no_fight")
		 && (int)me->query("combat_exp")> 1500000
		 )
       {
message_vision(RED"\n$N身后突然出来几个蒙面人,对着$N说：你背叛师门，拿命来!!\n"NOR,me); 
       	  me->start_busy(1);
          call_out("zuji", 0, me);    
     
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
//if (!me->query_temp("tjob")) return;
	    if (random(19)== 0)
	    {
	      obj=new("quest/menpai/jobnpc/btshan");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     
              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 2)
	    {
	      obj=new("quest/menpai/jobnpc/tangmen");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 3)
	    {
	      obj=new("quest/menpai/jobnpc/feitian");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 4)
	    {
	      obj=new("quest/menpai/jobnpc/wudujiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 5)
	    {
	      obj=new("quest/menpai/jobnpc/lingxiao");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
              me->kill(this_object());
	     }
	     else 
	    if (random(19)== 1)
	    {
	      obj=new("quest/menpai/jobnpc/gumu");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 2)
	    {
	      obj=new("quest/menpai/jobnpc/gaibang");   
	      obj->do_copy(me,maxpot,3);
	      obj->set("title",HIY"江湖杀手"NOR);     
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 3)
	    {
	      obj=new("quest/menpai/jobnpc/emei");   
	      obj->do_copy(me,maxpot,3);
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
              obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 4)
	    {
	      obj=new("quest/menpai/jobnpc/dali");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 5)
	    {
	      obj=new("quest/menpai/jobnpc/huashan");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 6)
	    {
	      obj=new("quest/menpai/jobnpc/kunlun");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 7)
	    {
	      obj=new("quest/menpai/jobnpc/shaolin");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 8)
	    {
	      obj=new("quest/menpai/jobnpc/mr");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 9)
	    {
	      obj=new("quest/menpai/jobnpc/mingjiao");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 10)
	    {
	      obj=new("quest/menpai/jobnpc/lingjiu");   
	      obj->do_copy(me,maxpot,3);

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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 11)
	    {
	      obj=new("quest/menpai/jobnpc/taohua");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 12)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan1");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 14)
	    {
	      obj=new("quest/menpai/jobnpc/xueshan3");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 15)
	    {
	      obj=new("quest/menpai/jobnpc/xingxiu");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 16)
	    {
	      obj=new("quest/menpai/jobnpc/wudang");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	     else 
	    if (random(19)== 17)
	    {
	      obj=new("quest/menpai/jobnpc/tiezhang");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     

              obj->kill_ob(me);me->kill(this_object());
	     }
	    else 
	    
	    {
	      obj=new("quest/menpai/jobnpc/yunlong");   
	      obj->do_copy(me,maxpot,3);
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
obj->set("title",RED"江湖杀手"NOR);     
              obj->kill_ob(me);me->kill(this_object());
	     }
//return 1;	
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
