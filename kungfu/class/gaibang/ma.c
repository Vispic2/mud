#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed ask_me(); 
#include "gaibang.h"

void consider();

void create()
{
	set_name("马大元", ({"ma dayuan", "ma", "dayuan"}));
	set("title", "丐帮副帮主");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"一个四十多岁的汉子，他就是丐帮副帮主马大元。\n");
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 21);
	set("con", 32);
	set("dex", 25);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1800);
	set("max_jing", 1800);
	set("neili", 4800);
	set("max_neili", 4800);
	set("jiali", 120);
	
	set("combat_exp", 2000000);
	set("shen_type", 1);
	set("score", 25000);
	
	set_skill("force", 200);
	set_skill("huntian-qigong", 200);
	set_skill("jiaohua-neigong", 180);
	set_skill("unarmed", 180);
	set_skill("changquan", 180);
	set_skill("claw", 200);
	set_skill("suohou-gong", 200);
	set_skill("dodge", 180);
	set_skill("feiyan-zoubi", 180);
	set_skill("parry", 200);
	set_skill("begging", 180);
	set_skill("checking", 180);

	set("no_teach", ([
		"huntian-qigong" : "要学混天气功找帮主他老人家去。",
	]));

	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "jueming-tui");
	map_skill("claw", "suohou-gong");
	map_skill("parry", "suohou-gong");
	map_skill("dodge", "feiyan-zoubi");

	prepare_skill("claw", "suohou-gong");

	set("inquiry", ([
		"琐喉功": (: ask_me :),
	]));

	create_family("丐帮", 17, "副帮主");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "claw.suo" :),
		(: exert_function, "recover" :),
	}) );

	setup();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob)) return;

	if (ob->query("beggarlvl") < 8)
	{
		command("say 你在本帮的地位太低，还是先向各位长老学习吧！");
		return;
	}

	if ((int)ob->query_str() < 26)
	{
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "膂力不行，似乎不宜学丐帮的功夫？");
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

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/suohou-gong/suo"))
		return "自己下去练习，别老是纠缠不清的！";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "又不是我们帮的，问这个干嘛？";

	if (me->query("beggarlvl") < 9)
		return "我倒是有心传授你一些东西，但那是等你成为九袋长老之后的事。";

	if (me->query_skill("suohou-gong", 1) < 150)
		return "你的琐喉功还不到家，要多练练！";

	message_vision( HIY "$n" HIY "笑了笑，轻声在$N"
			HIY "耳边低声吩咐了几句，全是琐"
			"喉功的精微要诣，$N" HIY "一边听"
			"一边不住地点头。"NOR"\n",
			me, this_object());
	command("nod");
	command("say 这便是琐喉功的要诣所在，可记清楚了？");
	tell_object(me, HIC "你学会了「琐喉」这一招。"NOR"\n");
	if (me->can_improve_skill("claw"))
		me->improve_skill("claw", 160000);
	me->set("can_perform/suohou-gong/suo", 1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
