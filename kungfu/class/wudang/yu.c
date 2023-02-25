// yu.c 俞莲舟

#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

mixed ask_me();

void create()
{
	set_name("俞莲舟", ({ "yu lianzhou", "yu" }));
	set("nickname", "武当二侠");
	set("long", 
		"他就是张三丰的二弟子俞莲舟。\n"
		"他今年五十岁，身材魁梧，气度凝重。\n"
		"虽在武当七侠中排名第二，功夫却是最精。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 32);
	set("dex", 32);
	
	set("max_qi", 4800);
	set("max_jing", 2400);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 100);
	set("combat_exp", 1600000);
	set("score", 50000);

	set_skill("force", 195);
	set_skill("wudang-xinfa", 195);
	set_skill("taiji-shengong", 195);
	set_skill("dodge", 170);
	set_skill("tiyunzong", 170);
	set_skill("unarmed", 180);
	set_skill("taiji-quan", 180);
	set_skill("strike", 180);
	set_skill("wudang-zhang", 180);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 180);
	set_skill("claw", 180);
	set_skill("huzhua-shou", 180);
	set_skill("parry", 180);
	set_skill("sword", 185);
	set_skill("wudang-jian", 185);
	set_skill("taiji-jian", 185);
	set_skill("taoism", 160);
	set_skill("literate", 100);
	set_skill("medical", 160);
	set_skill("liandan-shu", 160);

	set("no_teach", ([
		"taiji-shengong" : "要想学习太极神功请向张真人请教。",
		"taiji-jian"     : "太极剑必须张真人亲传。",
		"taiji-quan"     : "太极拳必须张真人亲传。",
	]));

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("hand", "paiyun-shou");
	map_skill("claw", "huzhua-shou");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	map_skill("strike", "wudang-zhang");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	create_family("武当派", 2, "弟子");

	set("inquiry", ([
		"虎爪绝户手": (: ask_me :),
		"绝户": (: ask_me :),
		"绝招"  : (: ask_me :),
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 150);
	set_temp("apply/unarmed_damage", 150);

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query("shen") < 15000 )
	{
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_skill("wudang-xinfa",1) < 80)
	{
		command("say 我武当派最注重内功心法" + RANK_D->query_respect(ob)+
			"是否应该在武当心法上多下点功夫啊?");
		return;
	}

	if ((int)ob->query_skill("taoism", 1) < 80)
	{
		command("say 习武是为了强身健体，一味的练武是不可取的。");
		command("say 我看你还需要在修身养性方面多锻炼锻炼，以提高"
			"你的道德心法。");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("say 希望你能好好用功，发扬我武当精神！");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/huzhua-shou/juehu"))
		return "这一招你不是已经会了吗？";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们武当派的人，何出此言？";

	if (me->query("shen") < 100000)
		return "这一招太过阴恨，如果被你用去我恐怕不放心！";

	if (me->query_skill("huzhua-shou", 1) < 120)
		return "你的虎爪绝户手还不到家，还是自己先下去多多练习吧。";

	message_vision(HIY "$n" HIY "叹了口气，在$N" HIY
		       HIY "耳边轻声说了几句虎爪绝户手的精要，"
		       "隔了良久，又叹了一口气。"NOR"\n",
		       me, this_object());
	command("sigh");
	command("say 这就是虎爪绝户手的精要所在，但是切记使用之前一定要慎重考虑。");
	tell_object(me, HIC "你学会了「绝户」这一招。"NOR"\n");
	if (me->can_improve_skill("claw"))
		me->improve_skill("claw", 160000);
	me->set("can_perform/huzhua-shou/juehu", 1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
