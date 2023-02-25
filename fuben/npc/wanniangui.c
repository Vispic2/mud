//抗日任务 (改编自12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{

      
        set_name(YEL"万年火龟"NOR, ({"wannian gui", "gui"}));
        set("long", "一只尺许大小的神龟。它通体火红，因万年长寿而具灵性，脖颈伸出时可达两尺之长，齿能咬金嚼铁，飞身扑人时难以提防，又可喷出红色毒雾，吸入者不治。火龟腹内有火丹一枚，人服用后可以医治百病、起死回生，亦可令人返老还童或平息走火入魔等。万年火龟极为难得，每年仅从隐藏的洞穴中连续出走七次，而且都在夜间。铁剑书生史天浩与师兄守在峨眉山中十五年之久，才掌握了火龟的活动规律，用熏醋将之制服并捕获。华山派、雪山派、天龙帮等均闻讯赶到，争夺这人间宝物，不料被突如其来的赵海萍以高绝武功抢走，将火丹给赵小蝶服下，使这位武功本已冠绝天下的少女的大般若玄功更加精进。\n");
        set("gender","男性");
        set("title", HIR"【boss】"NOR);
        set("no_get",1);
        set("age",500);
        set("attitude", "peaceful");
        set("con",300);
        set("per",300);
        set("str",300);
        set("int",300);
        set("combat_exp",4000000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "万年火龟：吼！\n"   
        }));
         set("max_neili", 4000000);
         set("neili", 4000000);
         set("max_jingli",4000000);
         set("jingli",4000000);
         set("jiali",4000000);
         set("max_qi", 4000000);
         set("qi", 4000000);
         set("max_jing", 4000000);
          set_skill("dodge", 400);
          set_skill("force", 400);
          set_skill("parry", 400);
          set_skill("unarmed",400);
        create_family("boss类",1,"万年火龟");
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
        x = 200000;   
        }
        else
        {
          ob->add("potential",18000);
        ob->add("combat_exp", 20000);
        ob->add("experience", 10000);
         tell_object(ob,HIR"你赢得了20000经验,18000潜能，10000实战体会\n\n"NOR);   
         players = users();
         x = 200000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/2);
        players[i]->add("experience", x/8);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了万年火龟，你赢得了"+x+"经验,"+x/2+"潜能，"+x/8+"实战体会.\n"NOR); 
       }
            message("channel:chat",HBRED"世界boos挑战"HIR"："+ob->query("name")+"神功盖世，击杀万年火龟，当是武林楷模，在线共计"+w+"名玩家瞻仰！\n"NOR,users());
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
