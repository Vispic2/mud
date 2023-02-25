// suxingh.c
// shilling 97.2

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_GUARDER;
inherit F_QUESTER;

#include "xiaoyao.h"

string ask_me();
string ask_book();

void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聪辩老人");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);

	set("str", 29);
	set("con", 30);
	set("int", 45);
	set("dex", 37);

	set("long", @LONG
此人就是号称聪辩老人的苏星河，据说他能言善辩，是一个武林中的
智者，而他的武功也是无人能知。
LONG );

	set("combat_exp", 1100000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("max_qi", 4400);
	set("max_jing", 2400);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("strike", 140);
	set_skill("hand", 140);
	set_skill("parry", 150);
	set_skill("blade", 130);
	set_skill("feiyan-zoubi", 150);
	set_skill("xiaoyao-xinfa", 150);
	set_skill("ruyi-dao", 140);
	set_skill("liuyang-zhang", 140);
	set_skill("zhemei-shou", 140);
	set_skill("literate", 160);
	set_skill("medical", 250);
	set_skill("xiaoyao-qixue", 250);

	map_skill("strike", "liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("force", "xiaoyao-xinfa");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	

	create_family("逍遥派", 2, "弟子");
	set("title", "逍遥派第二代掌门弟子");

	set("coagents", ({
	       ([ "startroom" : "/d/xiaoyao/shishi",
		  "id"	: "xiaoyao zi" ]),
	}));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.ruyi" :),
		(: perform_action, "hand.jiubu" :),
		(: perform_action, "strike.jiutian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	set_temp("apply/force", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();
}


void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 30)
	{
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在学问上多下点功夫，笨人可逍遥不了！");
		return;
	}

	if (ob->query_skill("force", 1) < 50)
	{
		command("sigh");
		command("say 我们逍遥派的武功都要以内功为基础，你先把"
			"基础内功学扎实吧。");
		return;
	}

	if (ob->query_skill("xiaoyao-xinfa", 1) < 50)
	{
		command("sigh");
		command("say 你连本门的入门心法都没有学好，还想学本门"
			"的上乘武学？");
		return;
	}

	command("say 好吧，我就收下你了，今后要多加努力啊！");
	command("recruit " + ob->query("id"));
}

int permit_pass(object me, string dir)
{
	if (! ::permit_pass(me, dir))
		return 0;

	if (me->query("family/master_id") == "xiaoyao zi")
		return 1;

	if (me->query("combat_exp") < 250000)
	{
		command("say 你这种身手不要去那里，好好学我们逍遥派武功。");
		return 0;
	}

	if (me->query_skill("xiaoyao-xinfa", 1) < 120)
	{
		command("say 连我们逍遥心法都学不好，乱走什么？");
		return 0;
	}

	command("sigh");
	command("say 去吧，去吧！有缘者竟成。");
	return 1;
}

int accept_hit(object who)
{
	command("heng");
	command("say " + who->name() + "，你别欺人太甚！");
	return 0;
}

void unconcious()
{
	die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
