// bao.c

#include <ansi.h>;

inherit NPC;
inherit F_GUARDER;
inherit F_COAGENT;

void create()
{
	set_name("包不同", ({"bao butong", "bao"}));
	set("gender", "男性");
	set("age", 31);
	set("long", "他是慕容家四大家臣之三，生性喜欢饶舌。\n");
	set("attitude", "peaceful");
	set("str", 21);
	set("int", 26);
	set("con", 25);
	set("dex", 24);

	set("qi", 2900);
	set("max_qi", 2900);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 2900);
	set("max_neili", 2900);
	set("combat_exp", 550000);

	set_skill("force", 130);
	set_skill("shaolin-xinfa", 130);
	set_skill("dodge", 130);
	set_skill("shaolin-shenfa", 130);
	set_skill("parry", 140);
	set_skill("claw", 140);
	set_skill("longzhua-gong", 140);

	map_skill("force", "shaolin-xinfa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "longzhua-gong");
	map_skill("claw", "longzhua-gong");

	prepare_skill("claw", "longzhua-gong");

	create_family("慕容世家", 0, "家臣");

	set("inquiry", ([
		"慕容博":   "那是老主人。\n",
		"慕容复":   "他就是我们跟随的公子！\n",
	]));

	set("coagents", ({
		([ "startroom" : "/d/yanziwu/qinyun",
		   "id"	: "feng boe" ]),
		([ "startroom" : "/d/yanziwu/shangyu",
		   "id"	: "murong bo" ]),
	}));

	set("guarder", ([
		"refuse_home" : "$N对$n慢慢道：非也非也！既然不再是慕容传人，饶恕我无理阻拦了！",
		"refuse_other": "$N对$n冷笑道：不是慕容家的通通的给我滚出去！",
	]));

	setup();

	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 我们跟随慕容公子，不收徒。");
	return;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
