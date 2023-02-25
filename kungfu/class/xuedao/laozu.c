// /kungfu/class/xuedao/xuedao.c  血刀老祖
// by secret

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

#include <ansi.h>
#include "xuedao.h"

mixed ask_me();
string ask_midao();
mixed ask_xblade();

void create()
{
	set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
	set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
	);
	set("title",HIR"血刀门第四代掌门"NOR);
	set("gender", "男性");
	set("age", 85);
	set("attitude", "peaceful");
	set("shen_type", -1);

	set("str", 33);
	set("int", 31);
	set("con", 35);
	set("dex", 32);

	set("max_qi", 5200);
	set("max_jing", 2600);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 80);
	set("combat_exp", 2100000);

	set_skill("lamaism", 220);
	set_skill("literate", 80);
	set_skill("force", 230);
	set_skill("parry", 220);
	set_skill("blade", 225);
	set_skill("xue-dao", 225);
	set_skill("sword", 180);
	set_skill("mingwang-jian", 180);
	set_skill("dodge", 210);
	set_skill("mizong-neigong", 230);
	set_skill("xuehai-mogong", 230);
	set_skill("shenkong-xing", 210);
	set_skill("hand", 200);
	set_skill("dashou-yin", 200);
	set_skill("cuff", 200);
	set_skill("yujiamu-quan", 200);

	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");
	map_skill("sword", "mingwang-jian");

	prepare_skill("cuff", "yujiamu-quan");
	prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.shendao" :),
		(: perform_action, "blade.xueyu" :),
		(: perform_action, "hand.jingang" :),
		(: perform_action, "cuff.chen" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	create_family("血刀门", 4, "掌门");
	set("class", "bonze");

	set("inquiry", ([
		"祭血神刀"  : (: ask_me :),
		"绝招"      : (: ask_me :),
		"绝技"      : (: ask_me :),
		"密道"      : (: ask_midao :),
		"秘道"      : (: ask_midao :),
		"血刀经"    : "宝象哪里好像还有吧，我这儿没有了。",
		"血刀秘籍"  : "你去问问宝象好了。",
		"血刀"      : (: ask_xblade :),
	]));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xblade")->wield();

	add_money("silver", 3);
	set("xblade_count", 1);
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query("class") != "bonze")
	{
		ob->set_temp("pending/join_bonze", 1);
		command("say 你不是出家人，我们血刀门是不会收留的。"
			"如果你要出家，去找善勇。");
		return;
	}

	if ((string)ob->query("gender") != "男性")
	{
		command("say 我不收女徒弟。\n");
		return;
	}

	if ((string)ob->query("family/family_name") != "血刀门")
	{
		command("say 这位" + RANK_D->query_respect(ob) +
			"既非本门弟子，还是请回吧！\n");
		return;
	}

	if ((int)ob->query("combat_exp") < 150000)
	{
		command("say 你的实战经验也忒差了，回去好好给我练功去！");
		return;
	}

	if ((int)ob->query("shen") > -40000)
	{
		command("say 你是不是向着侠义道，连杀人都不会！\n");
		return;
	}

	if ((int)ob->query_skill("lamaism", 1) < 135)
	{
		command("say 入我血刀门，修习密宗佛法是首要的。\n");
		return;
	}

	if ((int)ob->query_skill("force") < 160)
	{
		command("say 你这个废物！怎么练的？内功这么差！\n");
		return;
	}

	if ((int)ob->query_skill("blade", 1) < 100)
	{
		command("say 你刀法这么差，还有脸来见我？\n");
		return;
	}

	command("nod");
	command("recruit " + ob->query("id"));

	ob->set("title", HIR "血刀门老祖亲传弟子" NOR);
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/xue-dao/shendao"))
		return "你好好练习武功，不要丢我的脸！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你是什么人？我看怎么不象是我们血刀弟子呢？";

	if (me->query_skill("xue-dao", 1) < 100)
		return "就你这点本事？等你把血刀刀法练熟了再来找我吧！";

	if (me->query("shen") > -1000)
		return "你这人是怎么做的？连杀人都不会了？";

	message_vision(HIR "$n" HIR "抬抬手道：“你过来！”$N"
		       HIR "连忙靠上前去，只听$n"
		       HIR "嘀嘀咕咕的说了些什么。"NOR"\n",
		       me, this_object());
	command("heihei");
	command("say 你明白了吧！");
	tell_object(me, HIG "你通晓了祭血神刀的奥妙。"NOR"\n");
	if (me->can_improve_skill("blade"))
		me->improve_skill("blade", 90000);
	me->set("can_perform/xue-dao/shendao", 1);
	return 1;
}

string ask_midao()
{
	object me;

	me = this_player();
	if (me->query("family/family_name") != "血刀门")
		return "你说什么？我不知道啊。";

	command("whisper " + me->query("id") + " 你既然已经入"
		"我门来，以后若要去中原办事，\n即可用我门血刀"
		"先辈们留下的密道，你可到山外杂物堆处进入"
		"(enter mash)，\n然后即可到达中原；回来是找我"
		"血刀伏在中原的铁匠，接口密语是“血海无\n边”，牢记了！");
	return "你可知晓了？此秘密不可泄露于他人，否则天诛地灭！";
}

void unconcious()
{
	die();
}

mixed ask_xblade()
{
	object ob;
	object me;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return "你找死啊？";

	if (query("xblade_count") < 1)
		return "我手头可没有富余的了，等等吧！";

	if (me->query_temp("asked/xblade"))
		return "我不是给过你一把么？你要是弄丢了，就给我找回来！";

	if (me->query("combat_exp") < 200000)
		return "你武功太差了，就别给老祖我丢脸了。";

	me->set_temp("asked/xblade", time());

	add("xblade_count", -1);
	ob = new("/d/xuedao/obj/xblade");
	ob->move(me, 1);
	message_vision("$N掏出一把血红的缅刀，递给$n，"
		       "道：“你可要拿好了！”。\n", this_object(), me);
	return 1;
}

void reset()
{
	set("xblade_count", 1);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
