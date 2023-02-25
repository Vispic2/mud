// This program is a part of NT MudLIB

#include <ansi.h>
inherit NPC;
void create()
{
                set_name(HIM "盗墓飞贼" NOR, ({ "daomu feizei", "daomu", "feizei" }) );
        set("title", HIC "「神秘人」" NOR);
        set("gender", random(2) == 1 ? "男性" : "女性");
        set("age", 25);
        set("long", @LONG
这是一名盗墓的飞贼，一身黑色蒙面装束，看起来身形矫健。
LONG);
        set("combat_exp", 4000000000);        
        set("max_neili",300000);
        set("neili", 300000);
        set("max_jing", 300000);
        set("jing", 300000);
        set("max_qi", 300000);
        set("eff_qi", 300000);
        set("qi", 300000);
        set("jingli", 300000);
        set("max_jingli", 300000);   
        set("str", 100);
        set("int", 100);
        set("con", 100);
        set("dex", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set("jiali", 30);                      
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
       message_vision("$N朝你袭来。\n",this_object(), ob);
        kill_ob(ob);
        return 1;
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
return HIY "$N" HIY "大喝一声，拼死反抗，竟逼得$n" HIY "手忙脚乱。"NOR"\n" ;
}
void random_move()
{
        
        if (time() - query_temp("born_time") > 1800)
        {                
        	message_vision("$N急急忙忙的走了。\n", this_object());
            message("channel:chat",CYN"【BO"HIG"SS】"HIG"："+query("name")+HIG+"猛然间，向后一跳，随手仍出一颗黑色小丸，顿时腾起一片烟雾 ...消失了。"NOR"\n",users());	      
       
                destruct(this_object());       
                return;       
        }
}

void die()
{
object ob,killer;
int a=random(17);
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
message_sort("猛然间，$N " HIG " 向后一跳，随手仍出一颗黑色小丸，顿时腾起一片烟雾...留下了一物你定眼一看原来是"+ob->name()+HIW+"。\n", this_object());
}
if(a==5)
{
ob=new("/clone/shizhe/dan_jiuzhuan");
ob->move(environment());
message_sort("猛然间，$N " HIG " 向后一跳，随手仍出一颗黑色小丸，顿时腾起一片烟雾...留下了一物你定眼一看原来是"+ob->name()+HIW+"。\n", this_object());
}
if(a==9)
{
ob=new("/clone/shizhe/putao1");
ob->move(environment());
message_sort("猛然间，$N " HIG " 向后一跳，随手仍出一颗黑色小丸，顿时腾起一片烟雾...留下了一物你定眼一看原来是"+ob->name()+HIW+"。\n", this_object());
}
message_sort("猛然间，$N " HIG " 向后一跳，随手仍出一颗黑色小丸，顿时腾起一片烟雾 ...\n", this_object());
message("channel:chat",CYN"【BO"HIG"SS】"HIG"："+query("name")+HIG+"猛然间，向后一跳，随手仍出一颗黑色小丸，顿时腾起一片烟雾...消失了。"NOR"\n",users());	
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
