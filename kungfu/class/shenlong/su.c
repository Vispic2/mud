// su.c 苏荃

#include "shenlong.h"

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

mixed ask_skill();

void create()
{
	set_name("苏荃", ({ "su quan", "su" }));
	set("title",  HIY"神龙教"NOR"教主夫人" );
	set("long", "她就是神龙教教主洪安通的夫人。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "friendly");
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);
	
	set("max_qi", 3500);
	set("max_jing", 1800);
	set("neili", 3700);
	set("max_neili", 3700);
	set("jiali", 50);
	set("combat_exp", 620000);
	set("shen_type", -1);

	set_skill("force", 150);
	set_skill("shenlong-xinfa", 150);
	set_skill("dodge", 180);
	set_skill("yixingbu", 160);
	set_skill("hand", 150);
	set_skill("strike", 180);
	set_skill("shenlong-bashi", 150);
	set_skill("huagu-mianzhang", 120);
	set_skill("parry", 150);
	set_skill("staff", 150);
	set_skill("shedao-qigong", 120);
	set_skill("literate", 100);
	set_skill("medical", 200);
	set_skill("shenlong-mixin", 200);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("strike", "huagu-mianzhang");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shedao-qigong");
	map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");

	create_family("神龙教", 1, "教主夫人");

	set("inquiry", ([
		"神龙教" : "一般人是入不了我神龙教的(join shenlongjiao)。",
		"入教"   : "一般人是入不了我神龙教的(join shenlongjiao)。",
		"退教"   : "哈哈哈哈！退教？这么多年我还真听过几起，不过他们已经都死了。",
		"口号"   : "万年不老！永享仙福！寿与天齐！文武仁圣！",
		"rujiao" : "一般人是入不了我神龙教的(join shenlongjiao)。",
		"tuijiao": "哈哈哈哈！退教？这么多年我还真听过几起，不过他们已经都死了。",
		"绝招"    : (: ask_skill :),
		"飞燕回翔": (: ask_skill :),
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?\n") :),
		(: command("say 你活得不耐烦了找死啊？\n") :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang3" :),
		(: perform_action, "staff.chang3" :),
		(: perform_action, "staff.chang3" :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	object ob;

	::init();

	if (interactive(ob = this_player()) && ! is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
	add_action("do_join", "join");
}

void greeting(object ob)
{
	object obj;
	if (! objectp(ob)) return;
	if (interactive(ob) && objectp(obj = present("used gao", ob)))
	{
	   	set("combat_exp", 100000);
	   	set("qi", 100);
	   	set("jing", 100);
	}
}

void attempt_apprentice(object ob)
{
	command("say 好吧，你就和我学武功吧。");
	command("recruit " + ob->query("id"));
}

mixed ask_skill()
{
	object me;

	me = this_player();

	if (me->query("can_perform/shenlong-bashi/huixiang"))
		return "你不是已经会了吗？";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们神龙教的人，何出此言？";

	if (me->query_skill("shenlong-bashi", 1) < 160)
		return "你的神龙八式还不到家，要多练练！";

	message_vision(HIY "$n" HIY "点了点头，在$N" HIY
		       HIY "耳边轻声嘀咕了几句，又提起"
		       "玉腿，在空中比划了一下，突然间"
		       "猛地向前勾出。\n招式华丽，看得"
		       "$N" HIY "如痴如醉。"NOR"\n",
		       me, this_object());
	command("nod");
	command("say 你可明白了？");
	tell_object(me, HIC "你学会了「飞燕回翔」这一招。"NOR"\n");
	if (me->can_improve_skill("hand"))
		me->improve_skill("hand", 160000);
	me->set("can_perform/shenlong-bashi/huixiang", 1);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
