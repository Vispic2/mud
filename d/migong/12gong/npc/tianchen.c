// by happ@YSZZ

inherit NPC;
#include "star.h"

void create()
{
        set_name("童虎", ({"tong hu", "tian chen"}));
        set("long", "传说中在庐山五老峰静坐0243年的中国老人鵟n");
        set("gender","男性");
        set("title", "【龙圣】");
        set("no_get",1);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "童虎说道：只有中国才有最好的功夫。\n",
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("staff", 250);
        set_skill("lunhui-zhang",250);
        set_skill("jienan-zhi",250);
        set_skill("lotusmove",250);
        set_skill("spells",250);
        set_skill("buddhism", 250);
        map_skill("staff","lunhui-zhang");
        map_skill("unarmed","jienan-zhi");
        map_skill("spells","buddhism");
        map_skill("dodge","lotusmove");
        set("max_neili", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",60);
        set("force_factor", 60);
        set("max_qi", 17000);
        set("max_jing", 17000);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
       // carry_object(__DIR__"obj/tc_staff")->wield();
}

void check()
{
        object ob=this_object();
     //   object me=query_temp("my_killer");
       object me=this_player();
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }

     if (me->query("combat_exp")>1000000)set("combat_exp",me->query("combat_exp"));if (me->query("str")>25) set("str",me->query("str"));if (me->query("con")>25) set("str",me->query("con"));if (me->query("dex")>25) set("str",me->query("dex"));if (me->query("int")>25) set("str",me->query("int"));
     switch(random(5))
     {
        case 0:
        {
        message_vision(HIC"$N大喊一声『庐山升龙霸』一条居龙自九天而起，直飞$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"$N被巨龙在空中顶得翻了几十个跟头！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else        message_vision(HIG"$N身型急转，不知道绕了多少圈才夺过巨龙的攻击！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N高喊一声：『庐山亢龙霸』，一条恶龙自溅底而出，尾巴向$n扫去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(GRN"$N被恶龙的尾巴甩了个正着，$N顿时眼冒金星！\n"NOR,me);
              me->add("eff_qi",-2*me->query("max_qi")/10);
              me->add("eff_jing",-2*me->query("max_jing")/10);
                }
        else
        message_vision(HIY"$N用尽全身力气，飞升而气，恶龙的尾巴正从$N的脚底板扫过！\n"NOR,me);

        }
        break;

        case 2:
        {

        message_vision(HIR"$N高喊一声：『庐山百龙霸』，无数只巨龙向$n冲过来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIR"$N如一个球一样，被无数只巨龙在空中戏弄着！\n"NOR,me);
              me->add("eff_qi",-3*me->query("max_qi")/10);
              me->add("eff_jing",-3*me->query("max_jing")/10);
                }
        else
        message_vision(HIR"$N看准了巨龙之间的空隙，左转右转，才勉强离难！\n"NOR,me,ob);
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
        if((ob&&ob->query("gong/shinu")=="done") && (ob&&ob->query("gong/tiancheng")!="done"))
        {
        ob->start_busy(3);
        message("channel:chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第七宫：天秤宫!\n"NOR,users());
        ob->set("gong/tiancheng","done");
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
