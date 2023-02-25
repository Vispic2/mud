#include <ansi.h>
#include "baiyun.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

mixed ask_skill1();

void create()
{
        set_name("西门吹雪", ({"ximen chuixue","ximen",}));
        set("long",
                "他就是隐居江湖剑神西门吹雪.隐居白云城当客卿\n"
        );
        set("gender", "男性");
        set("nickname", HIR "剑神" NOR);
        set("title", "天下无敌");
        set("attitude", "friendly");

        set("age", 30);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 3000);
        set("max_jing", 2700);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 50);
        set("combat_exp", 500000);

        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("sword", 50);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("throwing", 500);
	
        set_skill("doomforce", 500);
        set_skill("doomstrike", 500);
        set_skill("doomsteps", 500);
	set_skill("chuixue-jian",500);

        map_skill("force", "doomforce");//吹雪神功
        map_skill("unarmed", "doomstrike");//寒天神掌
        map_skill("sword", "chuixue-jian");//寒天吹雪剑
        map_skill("dodge", "doomsteps");//吹雪步法
//        prepare_skill("strike", "qingmang-zhang");

        create_family("白云城", 1, "客卿");

        set("inquiry", ([
                "拜师"        : "心有正气",
                //"电光四射"    : (: ask_skill1 :),
        ]));

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dian" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/d/city/npc/obj/cloth")->wear();
        carry_object("/d/city/npc/obj/changjian")->wield();
}

void attempt_apprentice(object me)
{
        string purename, name, new_name;

        if (! permit_recruit(me))
                return;


	

        if ((int)me->query("shen") < 10000)
        {
                command("heng");
                command("say 我们孤山白云城向来不问江湖事，也不结交你这样的名声不好之人。");
                return;
        }

	
        if ((int)me->query("shen") < -1000)
        {
                command("heng");
                command("say 我白云城向来不问江湖事，更不会结交名声不好之人。");
                return;
        }

        command("say 好吧，既然你有心练武，我就收下你。");
        command("recruit " + me->query("id"));
}