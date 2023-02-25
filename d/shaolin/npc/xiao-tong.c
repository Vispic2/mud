// Npc: /d/shaolin/npc/xiao-tong.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("小沙弥", ({
		"xiao shami",
		"xiao",
		"shami",
	}));
	set("long",
		"他是一位未通世故的少年和尚，脸上挂着天真的稚笑。\n"
	);


	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 10);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 500);
	set("score", 100);

	set_skill("force", 8);
	set_skill("dodge", 8);
	set_skill("unarmed", 8);
	set_skill("parry", 8);


	setup();

}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
