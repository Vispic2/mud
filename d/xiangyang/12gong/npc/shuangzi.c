inherit NPC;
#include "star.h"
 
void create()
{
        set_name("赫尔梅斯", ({"homeis", "shuang zi"}));
        set("long", "传说中的传令神赫尔梅斯，守护双子座。\n");
        set("gender","男性");
        set("title", "【传令神】");
        set("no_get",1);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
         set("combat_exp",1000000);
          set("daoxing",2800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "赫尔梅斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("shuangzi", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangzi");
        map_skill("dodge","balei");
        set("max_neili", 4000);
        set("force", 8000);
        set("max_mana",4500);
        set("mana",9000);
        set("mana_factor",180);
        set("force_factor", 150);
        set("max_qi", 9000);
        set("max_jing", 9000);

        setup();
        carry_object(__DIR__"obj/sz_cloth")->wear();
         carry_object(__DIR__"obj/westsword")->wield();

}
 
void init()
{
        add_action("do_none","cast");
        add_action("do_none","ji");
}

void check()
{
        object ob=this_object();
     //   object me=query_temp("my_killer");
       object me=this_player();
        if( ! me ) return ;

        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                            

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIG"$N手中令旗一挥，一阵狂风呼啸而起！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIG"$N被风吹的跪在地上，毫无半点力量！\n"NOR,me);
              me->add("eff_qi",-me->query("max_qi")/10);
              me->add("eff_jing",-me->query("max_jing")/10);
                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一挥手中令旗，一道闪电劈向$n！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N被闪电劈了个正着，直电的头皮发麻！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIC"$N早就看清了闪电的方向，轻轻一闪，躲开了。\n"NOR,me);
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
        if((ob&&ob->query("gong/jinniu")=="done") && (ob&&ob->query("gong/shuangzi")!="done"))
        {
        ob->start_busy(3);
        message("channel:chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第三宫双子座，向黄金战士进军。\n"NOR,users());
        ob->set("gong/shuangzi","done");
        ob->add("gong/number",1);
        ob->add("combat_exp", 20000);
        tell_object(ob,"你赢得了20000经验");

        }
       ::die();
}

int do_none()
{
        object me = this_object();

        message_vision("$N冷笑一声：在我传令神面前，还想有什么花样？\n",me);
        return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
