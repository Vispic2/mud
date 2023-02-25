//抗日任务 (改编自12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{

      //  int lvl,lvls;
       // lvl=30000+random(20000);
        set_name(HIW"独臂雪人"NOR, ({"dubi xueren", "xueren"}));
        set("long", "雪山之巅里的怪物，生有巨大的头颅传言它因巫师凡人废了一只手，\n");
        set("gender","男性");
        set("title", HIR"【boss】"NOR);
        set("no_get",1);
        set("age",100);
        set("attitude", "peaceful");
        set("con",100);
        set("per",100);
        set("str",100);
        set("int",100);
        set("combat_exp",40000000000);
        set("chat_chance",10);
        set("chat_msg", ({
                "独臂雪人：吼！\n"   
        }));
         set("max_neili", 1000000);
         set("neili", 1000000);
         set("max_jingli",1000000);
         set("jingli",1000000);
         set("jiali",1000000);
         set("max_qi", 1000000);
         set("qi", 1000000);
         set("max_jing", 1000000);
          set_skill("dodge",100);
          set_skill("force", 100);
          set_skill("parry", 100);
          set_skill("unarmed", 100);
        create_family("boss类",1,"独臂雪人");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: perform_action, "sword.daya" :),
    }) );
        setup();
}
 
 void die()
{
        object nvh;
         object ob =  this_object()->query_last_damage_from();
            object *players;
         int w,x,i;
        ob->start_busy(1); 
        if (sizeof(ob->query_team()) > 1)
        {
        players = ob->query_team();
        x = 100000;   
        }
        else
        {
         ob->add("potential",100000);
         ob->add("combat_exp", 100000);
         ob->add("experience", 10000);
         tell_object(ob,HIR"你赢得了100000经验,100000潜能，10000实战体会\n\n"NOR);   
         players = users();
         x = 800000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/3);
        players[i]->add("experience", x/13);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了独臂雪人，你赢得了"+x+"经验,"+x/3+"潜能，"+x/13+"实战体会.\n"NOR); 
       }
            message("channel:chat",HBRED"世界boos挑战"HIR"："+ob->query("name")+"神功盖世，击杀了独臂雪人，当是武林楷模，在线共计"+w+"名玩家瞻仰！\n"NOR,users());
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
