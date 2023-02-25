// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("阿波罗", ({"apolo", "shi zi"}));
        set("long", "传说中的太阳神－阿波罗，守护着狮子座。\n");
        set("gender","男性");
        set("title", "【狮子神】");
        set("no_get",1);
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
          set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "太阳神－阿波罗说道：不知何时能再见到雅典娜！\n"   
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
        set("max_neili", 4500);
        set("force", 9000);
        set("max_mana",5000);
        set("mana",4000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_qi", 13000);
        set("max_jing", 13000);

        setup();
        carry_object(__DIR__"obj/shz_cloth")->wear();
         carry_object(__DIR__"obj/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        
        if( ! me ) return ;

 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
if(!present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));

     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIC"$N张开大嘴，居然吐出一团青光，罩向$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"青光如雨点般落在$N的身上！\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$N大吼一声，居然把青光反弹了回去。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N手指太阳，只见阳光突然变强，照得人睁不开眼！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIC"$N感觉到浑身如针扎般刺痛。\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIC"阳光照在$N的身上，$N感到无限的暇意。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIC"$N在怀里摸索着什么......居然是一只狮子，狮子向$n扑去。\n",ob,me);
                              
                if(random(2)==0)

                {
              message_vision(HIY"$N不知如何是好，狮子趁机猛咬了一口！\n"NOR,me);
              me->start_busy(1);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$N仔细一看，原来是个纸做的狮子！\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("gong/juxie")=="done") && (ob&&ob->query("gong/shizi")!="done"))
        {
        ob->start_busy(3);
        message("channel:chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第五宫狮子座，继续向黄金战士前进。\n"NOR,users());
        ob->set("gong/shizi","done");
        ob->add("gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");

        }
       ::die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
