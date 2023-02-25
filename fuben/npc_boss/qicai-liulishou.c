// This program is a part of NT MudLIB

#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY "七"HIG"彩"HIM"琉"HIC"璃"HIW"兽" NOR, ({ "qicai liulishou", "qicai", "liulishou" }) );
        set("title", HIW "圣诞" HIR "怪兽" NOR);
        set("gender", "男性");
        set("age", 8888);
        set("long", @LONG
这是一只长相奇特怪兽，全身幻出七彩之色，头大身小，一对浑圆的眼
珠闪烁出摄人的光芒。
LONG );
        set("combat_exp", 4000000000);        
        set("max_neili",1000000);
        set("neili", 1000000);
        set("max_jing", 1000000);
        set("jing", 1000000);
        set("max_qi", 1000000);
        set("eff_qi", 1000000);
        set("qi", 1000000);
        set("jingli", 1000000);
        set("max_jingli", 1000000);   
        set("str", 100);
        set("int", 100);
        set("con", 100);
        set("dex", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set("jiali", 100);                      
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
        message_vision("$N一声巨吼，扑了过来。\n",this_object(), ob);
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
        return HIY "$N" HIY "周围雾气缭绕，直逼得$n" HIY "头晕目眩。"NOR"\n" ;
}
void random_move()
{
        
        if (time() - query_temp("born_time") > 1800)
        {                
                message_vision("$N长啸一声，化作一团火焰，消失在了天际之中。\n", this_object());
                message("channel:chat",CYN"【BO"HIG"SS】"HIG"："+query("name")+HIG+"长啸一声，化作一团火焰，消失在了天际之中。"NOR"\n",users());	      
       
                destruct(this_object());       
                return;       
        }
}

void die()
{
object ob,killer;
int a=random(10);
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
message_sort(HIW "$N" HIW "长啸一声，留下了一物你定眼一看原来是"+ob->name()+HIW+"，化作一团火焰，消失在了天际之中。\n", this_object());
}
if(a==5)
{
ob=new("/clone/shizhe/dan_jiuzhuan");
ob->move(environment());
message_sort(HIW "$N" HIW "长啸一声，留下了一物你定眼一看原来是"+ob->name()+HIW+"，化作一团火焰，消失在了天际之中。\n", this_object());
}
if(a==9)
{
ob=new("/clone/shizhe/putao1");
ob->move(environment());
message_sort(HIW "$N" HIW "长啸一声，留下了一物你定眼一看原来是"+ob->name()+HIW+"，化作一团火焰，消失在了天际之中。\n", this_object());
}
message_sort(HIW "$N" HIW "长啸一声，化作一团火焰，消失在了天际之中。\n", this_object());
message("channel:chat",CYN"【BO"HIG"SS】"HIG"："+query("name")+HIG+"长啸一声，化作一团火焰，消失在了天际之中。"NOR"\n",users());	
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
