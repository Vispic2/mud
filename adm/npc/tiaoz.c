// yanshang2.c 盐商头子
//Yanqi 08/11/2k
//提升到160k可以做@yeju

#include <ansi.h>
inherit NPC;
int ask_job();
int ask_job1();
int ask_job2();
int ask_job3();
int ask_job4();
void create()
{
        set_name(HIR"挑战使"NOR, ({ "fu ben", "fu", "ben" }));
        set("gender", "男性");
        set("age", 12+random(20));
        set("long", "他是boss挑战传送使。\n");
        set("combat_exp", 3000000);        
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 30000);
        set_skill("dodge", 20000);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("inquiry", ([
                 "独臂雪人": (: ask_job :),
                 "九头妖蛇": (: ask_job1 :),
                 "九爪孽龙": (: ask_job2 :),
                 "万年火龟": (: ask_job3 :),
                 "射影沙龙": (: ask_job4 :),
             
        ]));
        set("chat_chance", 3);
        set("chat_msg", ({
                "副本挑战使：那位英雄来挑战一下九头妖蛇呢？\n",
        }) );
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
        setup();        
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}
int ask_job()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
        
        command("whisper "+me->query("id")+"独臂雪人十分强大，你可要当心啊，我这就送你去雪山之巅！");
        tell_object(me,HIW"独臂雪人十分强大，你可要当心啊，我这就送你去雪山之巅！\n"NOR);
        me->move("/d/fuben/tiaozhan/enter");
        return 1;
}



int ask_job1()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
      


        command("whisper "+me->query("id")+" 九头妖蛇十分强大，你可要当心啊，我这就送你去九头魔河！");
        tell_object(me,BLU"九头妖蛇十分强大，你可要当心啊，我这就送你去九头魔河！\n"NOR);
        me->move("/d/fuben/tiaozhan/enter1");
        return 1;
}

int ask_job2()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
       

        command("whisper "+me->query("id")+" 九爪孽龙十分强大，你可要当心啊，我这就送你去汪洋大海！");
        tell_object(me,HIC"九爪孽龙十分强大，你可要当心啊，我这就送你去汪洋大海！\n"NOR);
        me->move("/d/fuben/tiaozhan/enter2");
        return 1;
}

int ask_job3()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
     

        command("whisper "+me->query("id")+" 万年火龟十分强大，你可要当心啊，我这就送你去大海之中！");
        tell_object(me,HIR"万年火龟十分强大，你可要当心啊，我这就送你去大海之中！\n"NOR);
        me->move("/d/fuben/tiaozhan/enter3");
        return 1;
}

int ask_job4()
{
        object me;
        int exp1;
        
        me=this_player();

        exp1=me->query("combat_exp");
    
       
        command("whisper "+me->query("id")+" 射影沙龙十分强大，你可要当心啊，我这就送你去汪洋大海！");
        tell_object(me,CYN"射影沙龙十分强大，你可要当心啊，我这就送你去沼泽之地！\n"NOR);
        me->move("/d/fuben/tiaozhan/enter4");
        return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
