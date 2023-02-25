//抗日任务 (改编自12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{

      //  int lvl,lvls;
       // lvl=30000+random(20000);
        set_name(HIB"九头魔蛇"NOR, ({"jiutou she", "guizi"}));
        set("long", "九头魔河里的怪物，生有九颗狰狞的头颅传言它以血为饮，生肉为食，\n");
        set("gender","男性");
        set("title", HIR"【boss】"NOR);
        set("no_get",1);
        set("age",200);
        set("attitude", "peaceful");
        set("con",200);
        set("per",200);
        set("str",200);
        set("int",200);
        set("combat_exp",40000000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "九头魔蛇：吼！\n"   
        }));
         set("max_neili", 2000000);
         set("neili", 2000000);
         set("max_jingli",2000000);
         set("jingli",2000000);
         set("jiali",2000000);
         set("max_qi", 2000000);
         set("qi", 2000000);
         set("max_jing", 2000000);
          set_skill("dodge", 200);
          set_skill("force", 200);
          set_skill("parry", 200);
          set_skill("unarmed", 200);
        create_family("boss类",1,"九头魔蛇");
        set("chat_chance_combat", 200);
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
        x = 230000;   
        }
        else
        {
        ob->add("potential",10000);
        ob->add("combat_exp", 13000);
        ob->add("experience", 900);
         tell_object(ob,HIR"你赢得了13000经验,10000潜能，900实战体会\n\n"NOR);   
         players = users();
         x = 330000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/2);
        players[i]->add("experience", x/10);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了九头魔蛇，你赢得了"+x+"经验,"+x/2+"潜能，"+x/10+"实战体会.\n"NOR); 
       }
            message("channel:chat",HBRED"世界boos挑战"HIR"："+ob->query("name")+"神功盖世，击杀了九头妖蛇，当是武林楷模，在线共计"+w+"名玩家瞻仰！\n"NOR,users());
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
