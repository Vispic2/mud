// /NPC xuzhu.c

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

#include <ansi.h>
#include "lingjiu.h"

void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long", @LONG
这是一个二十五六岁的年轻人，浓眉大眼，大大的鼻子扁平下塌, 容貌
颇为丑陋。身穿一件华贵雅致的长袍, 倒使他更显几分精神。
LONG );
	set("title", "灵鹫宫掌门人");
	set("gender", "男性");
	set("age", 26);
	set("nickname", HIM "梦郎" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 26);
	set("int", 27);
	set("con", 42);
	set("dex", 27);

	set("qi", 5500);
	set("max_qi", 5500);
	set("jing", 2600);
	set("max_jing", 2600);
	set("neili", 7800);
	set("max_neili", 7800);
	set("jiali", 100);

	set("combat_exp", 2450000);
	set("score", 40000);
	set_skill("force", 270);
	set_skill("dodge", 240);
	set_skill("parry", 270);
	set_skill("hand",250);
	set_skill("strike", 250);
	set_skill("sword", 240);

	set_skill("zhemei-shou", 250);
	set_skill("liuyang-zhang", 250);
	set_skill("yueying-wubu", 240);
	set_skill("bahuang-gong", 270);
	set_skill("tianyu-qijian", 240);
	set_skill("lingjiu-xinfa", 120);

	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");

	prepare_skill("hand", "zhemei-shou");
	prepare_skill("strike", "liuyang-zhang");	

	create_family("灵鹫宫",2, "弟子");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "hand.jiubu" :),
		(: perform_action, "strike.jiutian" :),
		(: perform_action, "strike.zhong" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	add_money("silver", 50);
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("lingjiu-xinfa", 1) < 100) 
	{
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该多练练灵鹫心法？");
		return;
	}

	if ((int)ob->query("max_neili") < 800) 
	{
		command("say 我派武功全看内力，若内力不济"
			"决难练成，你先修炼好内力再说吧！");
		return;
	}

	if ((int)ob->query("combat_exp") < 200000)
	{
		command("say 你实战经验不足，还是好好锻炼一下再说吧。");
		return;
	}

	if ((string)ob->query("gender")=="女性")
	{
		message_vision("虚竹垂目沉思片刻, 说道：“好吧, 我"
			       "就收下你了。”\n", ob);
		command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		return;
	} else
	{
		message_vision("虚竹瞪着你看了半天,说道："
			       "“阁下不会是想来抢我的生意吧?”\n", ob);
		return;
	}
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
