// sample master.c code
inherit NPC;
inherit F_MASTER;

#include "gaibang.h"

void consider();

void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌棒龙头");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 21);
	set("con", 32);
	set("dex", 25);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 80);
	
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("score", 25000);
	
	set_skill("force", 180);
	set_skill("jiaohua-neigong", 180);
	set_skill("unarmed", 180);
	set_skill("changquan", 150);
	set_skill("dodge", 150);
	set_skill("feiyan-zoubi", 150);
	set_skill("parry", 170);
	set_skill("staff", 170);
	set_skill("begging", 120);
	set_skill("checking", 150);
	set_skill("jueming-tui", 180);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "jueming-tui");
	map_skill("parry", "jueming-tui");
	map_skill("dodge", "feiyan-zoubi");
	
	create_family("丐帮", 18, "九袋长老");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
		(: exert_function, "recover" :),
	}) );

	setup();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob)) return;

	if ((int)ob->query_str() < 26)
	{
		command("say 我们丐帮的武艺一向以刚猛为主，" + RANK_D->query_respect(ob) + "膂力不行，似乎不宜学丐帮的功夫？");
		return;
	}

	if (ob->query_skill("force") < 150)
	{
		command("say 你的内功火候还不行，先和别的师傅学习吧。");
		return;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) +
		"能好好学习本门武功，将来在江湖中闯出一番作为。");

	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}

int recognize_apprentice(object me)
{
	if (me->query("family/family_name") != query("family/family_name"))
		return 0;

	if (me->query("beggarlvl") < 9)
		return 0;

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
