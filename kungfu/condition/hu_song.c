#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration) return 0;
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
                 && environment(me)->query("exits")
//		 && strsrch(environment(me)->query("short"),"船")==0
		 && !me->is_fighting())
       {
         me->start_busy(6);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("hu_song", duration - 1);
}
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot;
	me=this_player();
        if (!me) return;
	maxpot=me->query_temp("maxpot");
if (!maxpot) maxpot=100;
   	if(random(6)>4)
	{obj=new("quest/hyhusong/skiller"+sprintf("%d",random(3)+1));
	 maxpot=maxpot+10+random(10);
	 obj->set("title",HIR"天字一号"NOR);
	}
	else
	{ obj=new("quest/hyhusong/killer");
	  maxpot=maxpot-random(10);
	 }
	obj->do_copy(maxpot);
	obj->move(environment(me));
	message_vision(HIR"\n$N对着$n发出一阵阴笑声，令$n全身上下的寒毛根根竖起，不寒而栗。\n"NOR,obj,me); 
	if(objectp(present("gong zi", environment(this_player()))))
	{
	obj->kill_ob(present("gong zi",environment(this_player())));
 	present("gong zi",environment(this_player()))->kill_ob(obj);
 	present("gong zi",environment(this_player()))->start_busy(6);
        obj->set_leader(present("gong zi",me));
 //       obj->kill_ob(present("gong zi",me));
 	}
	obj->set_leader(me);
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
