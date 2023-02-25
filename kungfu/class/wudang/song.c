#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;
inherit F_COAGENT;

string ask_me();
string ask_book();
mixed ask_skill();

void create()
{
	set_name("宋远桥", ({ "song yuanqiao", "song" }));
	set("nickname", "武当首侠");
	set("long", 
		"他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
		"身穿一件干干净净的灰色道袍。\n"
		"他身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
	set("gender", "男性");
	set("age", 61);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 31);
	set("int", 27);
	set("con", 32);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 160);
	set("combat_exp", 1500000);
	set("score", 70000);

	set_skill("force", 200);
	set_skill("wudang-xinfa", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 160);
	set_skill("tiyunzong", 160);
	set_skill("unarmed", 185);
	set_skill("taiji-quan", 185);
	set_skill("strike", 185);
	set_skill("wudang-zhang", 185);
	set_skill("zhenshan-zhang", 185);
	set_skill("hand", 185);
	set_skill("paiyun-shou", 185);
	set_skill("parry", 180);
	set_skill("sword", 185);
	set_skill("wudang-jian", 185);
	set_skill("shenmen-jian", 185);
	set_skill("taiji-jian", 185);
	set_skill("taoism", 190);
	set_skill("literate", 120);
	set_skill("medical", 200);
	set_skill("liandan-shu", 200);

	set("no_teach", ([
		"taiji-shengong" : "要想学习太极神功请向张真人请教。",
		"taiji-jian"     : "太极剑必须张真人亲传。",
		"taiji-quan"     : "太极拳必须张真人亲传。",
	]));

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	map_skill("strike", "zhenshan-zhang");
	map_skill("hand", "paiyun-shou");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	create_family("武当派", 2, "弟子");

	set("inquiry", ([
		"秘籍"     : (: ask_me :),
		"武当药理" : (: ask_book :),
		"神门刺"   : (: ask_skill :),
	]));

	set("book_count", 1);
	set("book2_count", 1);

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

	set("coagents", ({
		([ "startroom" : "/d/wudang/houyuan",
		   "id"	: "yu lianzhou" ]),
	}));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query("shen") < 25000)
	{
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_skill("wudang-xinfa", 1) < 80)
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
	command("say 希望你能全心修炼道家心法，领悟道家真髓！");
	command("recruit " + ob->query("id"));
	if ((string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}

string ask_book()
{
	object ob;
	
	if (this_player()->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(this_player()) + 
		       "与本派素无来往，不知此话从何谈起？";

	if (this_player()->query_skill("liandan-shu", 1) < 60)
		return "你炼丹术这么差，药理拿给你也读不懂。";

	if (query("book2_count") < 1)
		return "你来晚了，那本武当药理不在此处。";

	add("book2_count", -1);
	ob = new("/clone/book/wudang");
	ob->move(this_player(), 1);
	return "好吧，这本「武当药理」你就拿去看吧。";
}

string ask_me()
{
	object ob;
	
	if (this_player()->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(this_player()) + 
		       "与本派素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";

	add("book_count", -1);
	ob = new("/clone/book/force_book");
	ob->move(this_player(), 1);
	return "好吧，这本「太极十三式」你拿回去好好钻研。";
}

mixed ask_skill()
{
	object me;

	me = this_player();
	if (me->query("can_perform/shenmen-jian/ci"))
		return "你不是已经会了吗？";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们武当派的人，何出此言？";

	if (me->query("shen") < 50000)
		return "你行侠仗义的事情做的还很不够，我不能传你绝招！";

	if (me->query_skill("shenmen-jian", 1) < 120)
		return "你的神门十三剑还不到家，要多练练！";

	message_vision(HIY "$n" HIY "点了点头，在$N" HIY
		       HIY "耳边轻声嘀咕了几句，又拔出"
		       "腰间长剑，挥舞出几个剑花，然后"
		       "猛地斜斜刺出。\n招式简朴，毫无"
		       "半点华丽可言。"NOR"\n",
		       me, this_object());
	command("nod");
	command("say 你可明白了？");
	tell_object(me, HIC "你学会了「神门刺」这一招。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 160000);
	me->set("can_perform/shenmen-jian/ci", 1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
