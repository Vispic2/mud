inherit NPC;
#include "star.h"
 
void create()
{
        set_name("阿提米斯", ({"adimis", "ju xie"}));
        set("long", "传说中的月亮女神－阿提米斯，守护着巨蟹座。\n");
        set("gender","女性");
        set("title", "【月亮神】");
         set("no_get",1);
        set("age",37);
        set("con",30);
        set("spi",40);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "阿提米斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("jinniu", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_neili", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 11000);
        set("max_jing", 11000);

        setup();
        carry_object(__DIR__"obj/jx_cloth")->wear();
        carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
       // object me=query_temp("my_killer");
          object me=this_player();
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               
 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(6))

     {        
        case 0:
        {
        message_vision(HIC"$N高举双手，$n的面前忽然出现了万丈波浪！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N被波浪冲了个大踉镪，差点摔倒！\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$N一声轻笑，躲开了这万丈波浪。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N眼望天空，一轮圆月忽然出现在$n的面前！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"原来这一轮圆月竟锋利无比，$N的身上被划了一大血口！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$N躲避及时，圆月在地上嘣出了一道裂痕。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIC"$N口念咒语，一只巨蟹从天而降，落在$n的面前。\n",ob,me);
                              
        if(random(3)==0)

                {
              message_vision(HIR"巨蟹伸出一双大铁钳，夹住了$N！\n"NOR,me);
              me->start_busy(1);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIR"$N定睛一看，原来是个幻象！\n"NOR,me,ob);
        }
        break;

  }
        if( random(30) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

      object ob = query_temp("my_killer");
//object ob=this_player();
        if((ob&&ob->query("gong/shuangzi")=="done") &&(ob&&ob->query("gong/juxie")!="done"))
        {
        ob->start_busy(3);
        message("channel:chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第四宫巨蟹座，继续向黄金战士前进。\n"NOR,users());
        ob->set("gong/juxie","done");
        ob->add("gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");

        }
       ::die();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
