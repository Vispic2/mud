// kid.c

inherit NPC;

void create()
{
        set_name("男孩",({ "boy" }) );
        set("gender", "男性" );
        set("age", 12);
        set("long", "这是个农家少年，大概因从小物农，虽"
                    "然年纪不大，可已长的很粗壮了。\n");

        set("str", 16);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin",100);
}