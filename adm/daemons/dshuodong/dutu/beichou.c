inherit NPC;

void create()
{
    set_name("北丑", ({"bei chou"}));
    set("long", "北丑\n");
    
    set("gender", "男性");
	set("age", 35);
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 500000);
	set("max_qi", 500000);
	set("jing", 500000);
	set("max_jing", 500000);
	set("neili", 200000);
	set("max_neili", 200000);
	set("no_get", 1);
	set("jiali", 100);

	set("combat_exp", 2750000);
	set("score", 200000);

	set_skill("cuff", 100);
	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("strike", 100);
    
    setup();
    
	carry_object("/clone/misc/cloth")->wear();
	
    if (clonep())
	{
		set("chat_chance", 50);
		set("chat_msg", ({
			(: NPC_D->random_move(this_object()) :),
		}));
		keep_heart_beat();
	}
}

int is_beichou()    {return 1;}

void init()
{
    object * dutu;
    
    if (sizeof(dutu = filter_array(all_inventory(environment(this_object())), (: ($1)->is_dutu() :))))
    {
        if (objectp(dutu[0]))
            kill_ob(dutu[0]);
    }
}

void die()
{
    __DIR__"dutu_beichou"->beichou_die();
    ::die();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
