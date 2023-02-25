// This program is a part of NT MudLIB

#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG "碧海神龙" NOR, ({ "bihao shenlong", "bihai", "shenlong" }) );
        set("title", HIC "龙族" NOR);
        set("gender", "男性");
        set("age", 20);
        set("combat_exp", 4000000000);        
        set("max_neili",100000);
        set("neili", 100000);
        set("max_jing", 100000);
        set("jing", 100000);
        set("max_qi", 100000);
        set("eff_qi", 100000);
        set("qi", 100000);
        set("jingli", 100000);
        set("max_jingli", 100000);   
        set("str", 100);
        set("int", 100);
        set("con", 100);
        set("dex", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set("jiali", 10);                      
        set_temp("apply/attack",100);
        set_temp("apply/unarmed_damage",100);
        set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        
	if (clonep(this_object()))
	{
		set("chat_chance", 30);
		set("chat_msg", ({ (: random_move :) }));
		set("born_time", time());		
		keep_heart_beat();
	}
        setup();
}
int accept_fight(object ob)
{
        message_vision("$N微一摇头，略一摆尾，扫了上来。。\n",this_object(), ob);
        kill_ob(ob);
        return -1;
}
int accept_kill(object ob)
{
        return 1;
}
int accept_hit(object ob)
{
        return 1;
}
mixed hit_ob(object me, object ob, int damage_bouns)
{
if(random(10)==5)
        ob->start_busy(5 + random(6));
        me->receive_wound("qi", 500 + random(500), ob);
        return HIY "$N" HIY "周围烟雾缭绕，光华四射，登时令$n"
               HIY "心力受损。"NOR"\n" ;
}
void random_move()
{
        
        if (time() - query_temp("born_time") > 1800)
        {                
        	message_vision("$N化作一道轻烟，消失了。\n", this_object());
            message("channel:chat",CYN"【BO"HIG"SS】"HIG"："+query("name")+HIG+"化作一道轻烟，消失了。"NOR"\n",users());	      
       
                destruct(this_object());       
                return;       
        }
}

void die()
{
object ob,killer;
int a=random(20);
if (objectp(killer = query_last_damage_from()))
	{
                killer->add("potential",500000);
                killer->add("combat_exp", 500000);
                killer->add("experience", 100000);
                killer->add("yuanbaos", 100);
                tell_object(killer,"你击败了："+name()+"，因此获得了500000点潜能，500000点经验，100000点体会,100元宝票。\n");
   }
if(a==2)
{
ob=new("/clone/money/gold");

ob->move(environment());
message_sort(HIW "$N" HIW "化作一道轻烟，消失了，留下了一物你定眼一看原来是"+ob->name()+HIW+"。\n", this_object());
}
if(a==5)
{
ob=new("/clone/shizhe/dan_jiuzhuan");
ob->move(environment());
message_sort(HIW "$N" HIW "化作一道轻烟，消失了，留下了一物你定眼一看原来是"+ob->name()+HIW+"。\n", this_object());
}
if(a==9)
{
ob=new("/clone/shizhe/putao1");
ob->move(environment());
message_sort(HIW "$N" HIW "化作一道轻烟，消失了，留下了一物你定眼一看原来是"+ob->name()+HIW+"。\n", this_object());
}
message_sort(HIW "$N" HIW "化作一道轻烟，消失了。\n", this_object());
message("channel:chat",CYN"【BO"HIG"SS】"HIG"："+query("name")+HIG+"化作一道轻烟，消失了。"NOR"\n",users());	
ob=new("/clone/money/yuanbao");
ob->move(environment());
//destruct(this_object());
::die();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
