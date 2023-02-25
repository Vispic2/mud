//抗日任务 (改编自12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{

      
        set_name(HIY"射影沙龙"NOR, ({"sheying long", "long"}));
        set("long", "栖息于黄山沼泽之中的种怪兽。它形如巨晰，口中能喷出毒泥毒沙，被射中的人会即刻晕倒，它又可利用口中强大吸力，把人吸入沼泽之内。\n");
        set("gender","男性");
        set("title", HIR"【boss】"NOR);
        set("no_get",1);
        set("age",100);
        set("attitude", "peaceful");
        set("con",300);
        set("per",300);
        set("str",300);
        set("int",300);
        set("combat_exp",40000000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "射影沙龙：吼！\n"   
        }));
         set("max_neili", 5000000);
         set("neili", 5000000);
         set("max_jingli",5000000);
         set("jingli",5000000);
         set("jiali",5000000);
         set("max_qi", 5000000);
         set("qi", 5000000);
         set("max_jing", 5000000);
          set_skill("dodge", 500);
          set_skill("force", 500);
          set_skill("parry", 500);
          set_skill("unarmed",500);
        create_family("boss类",1,"射影沙龙");
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
        x = 300000;   
        }
        else
        {
          ob->add("potential",20000);
        ob->add("combat_exp", 40000);
        ob->add("experience", 12000);
         tell_object(ob,HIR"你赢得了40000经验,20000潜能，12000实战体会\n\n"NOR);   
         players = users();
         x = 200000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/2);
        players[i]->add("experience", x/8);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了射影沙龙，你赢得了"+x+"经验,"+x/2+"潜能，"+x/8+"实战体会.\n"NOR); 
       }
            message("channel:chat",HBRED"世界boos挑战"HIR"："+ob->query("name")+"神功盖世，击杀射影沙龙，当是武林楷模，在线共计"+w+"名玩家瞻仰！\n"NOR,users());
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
