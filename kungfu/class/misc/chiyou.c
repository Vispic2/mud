// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
        set_name("蚩尤", ({"chi you", "chi"}));
        set("gender", "男性");
        set("age", 21);
        set("shen_type", -1);
        set("long", "他穿着一身淡青色的衣服。");

        set("attitude", "peaceful");

        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("neili", 130000);
        set("max_neili", 130000);
        set("jiali", 3000);

        set("combat_exp", 150000000);
        set("score", 0);

        set_skill("force", 6000);
        set_skill("moshen-xinfa", 6000);
        set_skill("chiyou-kuangzhanjue", 6000);
        set_skill("dodge", 6000);
        set_skill("moshen-bufa", 6000);
        set_skill("jiutian-xiaoyaobu", 6000);
        set_skill("strike", 6000);
        set_skill("moshen-zhangfa", 6000);
        set_skill("cuff", 6000);
        set_skill("moshen-quanfa", 6000);
        set_skill("sword", 6000);
        set_skill("moshen-jianfa", 6000);
        set_skill("blade", 6000);
        set_skill("tiandaodao", 6000);
        set_skill("moshen-daofa", 6000);
        set_skill("moon-blade", 6000);
        set_skill("parry", 6000);
        set_skill("literate", 6000);
        set_skill("medical", 6000);
        set_skill("mojiao-medical", 6000);
        set_skill("martial-cognize", 6000);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "moshen-zhangfa");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "moshen-jianfa");
        map_skill("blade", "tiandaodao");
        map_skill("parry", "moon-blade");

        prepare_skill("strike", "moshen-zhangfa");

        create_family("魔教", 0, "祖师");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.modao" :),
                (: perform_action, "blade.tianyi" :),
                (: perform_action, "blade.weishe" :),
                (: exert_function, "recover" :),
        }) );

        set_temp("apply/attack", 5000);
        set_temp("apply/damage", 5000);
        set_temp("apply/unarmed_damage", 5000);
        set_temp("apply/armor", 5000);

        set("master_ob", 5);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
        add_money("silver",70);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
