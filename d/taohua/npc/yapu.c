// yapu.c 哑仆

inherit NPC;

void create()
{
	 set_name("哑仆", ({ "ya pu"}));
	set("age", 18);
	set("gender", "男性");
	set("long",
"这是一个桃花岛的哑仆。他们全是十恶不赦的混蛋，黄药师刺哑他们，\n
充为下御。\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 16);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 80);
	set_skill("force", 60);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 80);

	setup();
	carry_object("/d/city/obj/cloth")->wear();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
