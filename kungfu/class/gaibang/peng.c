#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed ask_me(); 
#include "gaibang.h"

void consider();

void create()
{
	set_name("彭有敬", ({"peng youjing", "peng", "youjing"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌钵龙头");
	set("gender", "男性");
	set("age", 50);
	set("long", 
		"彭有敬是丐帮中净衣派的首领，衣着干净华丽，不象叫化子。\n"
		"他脸上挂着慈祥的笑容，一双眼睛有摄人心魄的力量。\n");

	set("attitude", "peaceful");
	
	set("str", 28);
	set("int", 27);
	set("con", 24);
	set("dex", 25);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 70);
	set("shen_type", -1);
	
	set("combat_exp", 850000);
	set("score", 20000);
	
	set_skill("force", 170);
	set_skill("jiaohua-neigong", 170);
	set_skill("unarmed", 165);
	set_skill("changquan", 165);
	set_skill("dodge", 160);
	set_skill("feiyan-zoubi", 160);
	set_skill("parry", 170);
	set_skill("staff", 180);
	set_skill("fengmo-zhang", 180);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("parry", "fengmo-zhang");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("staff", "fengmo-zhang");

	create_family("丐帮", 18, "九袋长老");

	set("inquiry", ([
		"疯魔杖法" : (: ask_me :),
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/clone/weapon/tiegun")->wield();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob)) return;

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
	if (me->query("can_perform/fengmo-zhang/qunmo"))
		return "你不是已经会了吗？呆在这里找打呀！";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "何出此言？";

	if (me->query("beggarlvl") < 6)
		return "你在帮里的辈分太低了，等你到六代弟子后再来找我吧！";

	if (me->query_skill("fengmo-zhang", 1) < 150)
		return "你的疯魔杖法还不到家，要多练练！";

	message_vision( HIY "$n" HIY "点了点头，突然一声暴喝，"
			"手中铁杖一阵乱舞，挥舞出数道杖影，气势"
			"澎湃，力不可挡。\n正是疯魔杖法的精要所在！"NOR"\n",
			me, this_object());
	command("haha");
	command("say 明白了？");
	tell_object(me, HIC "你学会了「群魔乱舞」这一招。"NOR"\n");
	if (me->can_improve_skill("staff"))
		me->improve_skill("staff", 160000);
	me->set("can_perform/fengmo-zhang/qunmo", 1);
	return 1;
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
