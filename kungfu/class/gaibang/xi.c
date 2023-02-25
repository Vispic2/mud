#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed ask_me(); 
#include "gaibang.h"

void consider();

void create()
{
	set_name("奚长老", ({"xi zhanglao", "xi", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("gender", "男性");
	set("age", 45);

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
	set_skill("parry", 180);
	set_skill("staff", 180);
	set_skill("fumo-zhang", 180);
	set_skill("begging", 150);
	set_skill("checking", 150);
	set_skill("jueming-tui", 180);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "jueming-tui");
	map_skill("parry", "fumo-zhang");
	map_skill("staff", "fumo-zhang");
	map_skill("dodge", "feiyan-zoubi");
	
	set("inquiry", ([
		"伏魔杖": (: ask_me :),
	]));

	create_family("丐帮", 18, "九袋长老");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "staff.lun" :),
		(: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/clone/weapon/gangzhang")->wield(); 
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
	if (me->query("can_perform/fumo-zhang/lun"))
		return "自己好好多练习吧！";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "何出此言？";

	if (me->query("beggarlvl") < 8)
		return "你在帮里的辈分太低了，等你到八代弟子后再来找我吧！";

	if (me->query_skill("fumo-zhang", 1) < 150)
		return "你的伏魔杖还不到家，要多练练！";

	message_vision( HIY "$n" HIY "微笑着点了点头，突然一声暴喝，"
			"手中铁杖挥舞，残影化出无数个大圈，如\n同" NOR +
			HIR "风火轮" NOR + HIY "一般，气势如虹，当真"
			"微妙无比！"NOR"\n",
			me, this_object());
	command("nod");
	command("say 你可明白了？");
	tell_object(me, HIC "你学会了「风火轮」这一招。"NOR"\n");
	if (me->can_improve_skill("staff"))
		me->improve_skill("staff", 160000);
	me->set("can_perform/fumo-zhang/lun", 1);
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
