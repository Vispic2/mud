//抗日任务 (改编自12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{

      
        set_name(HIR"九爪孽龙"NOR, ({"jiuzhua long", "long"}));
        set("long", "一种巨形怪物。据说自宇宙初造，浑沌初开之时，此物便已生活在江洋大海之中，极有灵性。九爪孽龙长逾两丈，顶背有长列巨刺，坚逾钢铁，犀得无比；全身生有黑色鳞甲，大如蒲扇；刀枪不入；腹下呈灰白状；蹄爪之间常排泄奇腥粘液，山野小虫，触之即死；口吐白烟，腥咸热辣，毒烈无比。但它亦有三处致命的弱点，即左右眼和舌根。若同时击伤此三处，可致之于死地。九爪孽龙盘踞长江口外花鸟山，时常悠游于东海之中，商旅闻之丧胆。或有人上花鸟山欲除之，往反为所害。四海神龙付出了惨重代价，方得到双剑乾坤燕公来之助而除之。\n");
        set("gender","男性");
        set("title", HIR"【boss】"NOR);
        set("no_get",1);
        set("age",250);
        set("attitude", "peaceful");
        set("con",250);
        set("per",250);
        set("str",250);
        set("int",250);
        set("combat_exp",40000000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "九爪孽龙：吼！\n"   
        }));
         set("max_neili", 3000000);
         set("neili", 3000000);
         set("max_jingli",3000000);
         set("jingli",3000000);
         set("jiali",3000000);
         set("max_qi", 3000000);
         set("qi", 3000000);
         set("max_jing", 3000000);
          set_skill("dodge", 300);
          set_skill("force", 300);
          set_skill("parry", 300);
          set_skill("unarmed",300);
        create_family("boss类",1,"九爪孽龙");
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
        x =200000;   
        }
        else
        {
          ob->add("potential",15000);
        ob->add("combat_exp", 18000);
        ob->add("experience", 10000);
         tell_object(ob,HIR"你赢得了18000经验,15000潜能，10000实战体会\n\n"NOR);   
         players = users();
         x = 250000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/2);
        players[i]->add("experience", x/8);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了九爪孽龙，你赢得了"+x+"经验,"+x/2+"潜能，"+x/8+"实战体会.\n"NOR); 
       }
            message("channel:chat",HBRED"世界boos挑战"HIR"："+ob->query("name")+"神功盖世，击杀九爪孽龙，当是武林楷模，在线共计"+w+"名玩家瞻仰！\n"NOR,users());
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
