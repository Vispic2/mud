//jiabu.c
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void greeting(object);
void init();
void create()
{
	set_name("贾布", ({ "jia bu", "jia", "bu"}) );
	set("gender", "男性" );
	set("age", 45);
	set("title", "日月神教青龙堂长老");
	set("long", "他蜡黄瘦脸，两边太阳穴高高鼓起，便如藏了一枚枚核桃似的。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 15);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 29);

	set("max_qi", 1000);
	set("max_jing",1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 350000);
	set("score", 30000);
	set("jiali", 200);
	set_skill("force", 140);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("hammer",100);
	set_skill("blade",100);
	set_skill("taiji-shengong",70);
	set_skill("tiyunzong", 80);
	set_skill("taiji-dao", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	
	map_skill("parry", "taiji-dao");
	map_skill("blade", "taiji-dao");
	create_family("日月神教",2,"弟子 青龙堂长老");

	set("chat_chance", 2);
	set("chat_msg", ({
		 "贾布叹道: “攘外必先安内，堂中令牌被盗若是被教主知道，我命休矣。”\n"
	}) );
	setup();
	carry_object(__DIR__"obj/dadao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
      

}



void attempt_apprentice(object ob)
{
     command("say 我这点皮毛，不敢，不敢!\n");
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
