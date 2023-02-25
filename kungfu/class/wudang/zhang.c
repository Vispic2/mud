// zhang.c 张三丰

#include <ansi.h>
#include "wudang.h"

#define ZHENWU_SWORD    "/clone/weapon/zhenwu"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed ask_jian();
mixed ask_me();
mixed ask_tu();

void create()
{
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", HIG "邋遢真人" NOR);
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 31);
	set("int", 39);
	set("con", 40);
	set("dex", 32);
	
	set("max_qi", 7500);
	set("max_jing", 5000);
	set("max_jingli", 4000);
	set("jingli", 4000);
	set("max_neili", 9999);
	set("neili", 9999);
	set("jiali", 150);
	set("combat_exp", 3200000);
	set("score", 1200000);

	set_skill("force", 300);
	set_skill("taiji-shengong", 300);
	set_skill("wudang-xinfa", 300);
	set_skill("dodge", 260);
	set_skill("tiyunzong", 260);
	set_skill("unarmed", 290);
	set_skill("taiji-quan", 290);
	set_skill("strike", 290);
	set_skill("wudang-zhang", 290);
	set_skill("hand", 290);
	set_skill("paiyun-shou", 290);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("wudang-jian", 300);
	set_skill("taiji-jian", 300);
	set_skill("blade", 260);
	set_skill("taiji-dao", 260);
	set_skill("taoism", 500);
	set_skill("literate", 180);
	set_skill("medical", 270);
	set_skill("liandan-shu", 270);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("hand", "paiyun-shou");
	map_skill("strike", "wudang-zhang");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("blade", "taiji-dao");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	set("inquiry", ([
		"真武剑" : (: ask_jian :),
		"绝招"   : "你想学什么绝招？",
		"真武除邪": (: ask_me :),
		"太极图"  : (: ask_tu :),
	]));

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.tu" :),
		(: perform_action, "unarmed.zhen" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void scan()
{
	::scan();

	if (! query_temp("weapon"))
		map_skill("parry", "taiji-quan");
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("wudang-xinfa", 1) < 120)
	{
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在武当心法上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") < 60000)
	{
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query("combat_exp") < 300000)
	{
		command("say 你现在经验尚浅，不能领会高深的武功，先锻炼要紧。");
		return;
	}

	if (ob->query_skill("taoism", 1) < 120)
	{
		command("say 我武当派武功全从道藏悟出。");
		command("say 你对道家心法的领悟还不够。");
		command("say " + RANK_D->query_respect(ob) + "还是多研究研究道学心法吧。");
		return;
	}

	if (ob->query_int() < 32)
	{
		command("say 我武当派武功极需靠自己领悟。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}

	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}

mixed ask_jian()
{
	object me;
	object ob;
	object owner;

	me = this_player();
	if (me->is_bad())
	{
		if (me->query("family/family_name") == "武当派")
			message_vision("$N大怒，对$n道：“你身为武当弟子，"
				       "反而误入魔道，还不快快醒转？”\n",
				       this_object(), me);
		else
			message_vision("$N大怒，对$n喝道：“好一个邪魔外"
				       "道，居然敢窥测真武剑？”\n",
				       this_object(), me);
		return 1;
	}

	if (me->query("family/family_name") != "武当派")
		return "真武剑是我们武当镇派之宝，你打听它干什么？";

	if (me->query("family/master_id") != query("id"))
		return "只有我的弟子才能用真武剑，你还是请回吧。";

	if (me->query("shen") < 60000)
		return "你行侠仗义的事情做得不够，我不能把真武剑交给你。";

	ob = find_object(ZHENWU_SWORD);
	if (! ob) ob = load_object(ZHENWU_SWORD);
	owner = environment(ob);
	while (owner)
	{
		if (owner->is_character() || ! environment(owner))
			break;
		owner = environment(owner);
	}

	if (owner == me)
		return "真武剑不是在你的手中么，怎么反而来找我呢？";

	if (objectp(owner) && owner != this_object())
	{
		if (! owner->is_character())
			return "我已经把真武剑已经借出去了。";

		if (owner->query("family/master_id") == query("id"))
			return "真武剑现在在" + owner->query("name") +
			       "手中，你要想用就去找他吧。";
		else
			return "真武剑现在落在" + owner->query("name") +
			       "手中，你去把他找回来吧。";
	}

	ob->move(this_object());
	message_vision("$N点点头道：“好，你用这真武剑要多作一些行"
		       "侠仗义的事情！”\n", this_object(), me);
	command("give zhenwu jian to " + me->query("id"));
	ob->start_borrowing();
	return 1;
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/taiji-jian/zhenwu"))
		return "自己好好多练习吧！";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们武当派的人，何出此言？";

	if (me->query("shen") < 120000)
		return "你行侠仗义的事情做的还很不够，我不能传你绝招！";

	if (me->query_skill("taiji-jian", 1) < 180)
		return "你的太极剑法不到180级，还要多练练！";

	message_vision(HIY "$n" HIY "微微颔首，随手拣起一根树枝向$N" HIY
		       HIY "扫来，$N" HIY "见来招平淡无奇，颇为疑惑，只是随手一挡。\n"
		       "忽然$p" HIY "剑势大变，气度非凡，变化无穷，$P"
		       HIY "大吃一惊，慌乱不迭。"NOR"\n",
		       me, this_object());
	command("smile");
	command("say 你可明白了？");
	tell_object(me, HIG "你学会了真武除邪。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 160000);
	me->set("can_perform/taiji-jian/zhenwu", 1);
	return 1;
}

mixed ask_tu()
{
	object me;

	me = this_player();
	if (me->query("can_perform/taiji-quan/tu") >= 10 )
		return "该学的你都已经学了，以后要善加利用！";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们武当派的人，何出此言？";

	if (me->query("shen") < 250000)
		return "你行侠仗义的事情做得还不够多，我不能放心传你绝招！";

	if (me->query_skill("taiji-quan", 1) < 250)
		return "你的太极拳法不到250级，还要多练练！";

	if (me->query_skill("taiji-shengong", 1) < 300)
		return "你的太极神功还不到300级，好好修行吧！";

	if (me->query_skill("taoism", 1) <300)
		return "你的道学心法研究的还不够明白，要下功夫苦学才是！";

	if (me->query("max_jing") < 1000)
		return "你的精力不足1000点，就算传给你太极图你也难以运用。";

	message_vision(HIY "$n" HIY "点点头，双手轻轻划了一个圈子，"
		       "地上的土雾无端吸起，渐渐又落下。"NOR"\n",
		       me, this_object());
	command("smile");
	command("say 你看懂了多少？");

	if (me->query("potential") < me->query("learned_points") + 100)
	{
		write("你看了半天，没有研究出什么新的东西，看来是潜能还不够！\n");
		return 1;
	}

	me->add("learned_points", 100);

	if (me->add("can_perform/taiji-quan/tu", 1) < 10)
	{
		message_vision(HIY "$N" HIY "迷迷茫茫的点了点头，深思良久。"NOR"\n", me);
		tell_object(me, HIG "你对太极图有了一点领悟。"NOR"\n");
	} else
	{
		message_vision(HIY "$N" HIY "脸露笑容，喜道：我已经"
			       "明白了，所谓真与幻象其实并无分别啊！\n"
			       "$n" HIY "哈哈长笑道：明白就好，明白就好，以后勿得轻易使用，你去吧！\n",
			       me, this_object());
			       
		tell_object(me, HIG "你学会了道家密技太极图。"NOR"\n");
		if (me->can_improve_skill("taoism"))
			me->improve_skill("taoism", 160000);
		if (me->can_improve_skill("taiji-shengong"))
			me->improve_skill("taiji-shengong", 160000);
		if (me->can_improve_skill("unarmed"))
			me->improve_skill("unarmed", 160000);
	}

	return 1;
}

int accept_object(object me, object ob)
{
	int r;
	if (r = ::accept_object(me, ob))
		return r;

	if (base_name(ob) != ZHENWU_SWORD)
	{
		command("say 你给我这种东西干什么？");
		return 0;
	}

	if (me->query("family/master_id") != query("id"))
		command("say 多谢这位" + RANK_D->query_respect(me) + "将真武剑交回。");
	else
		command("say 很好，很好！");
	destruct(ob);
	return 1;
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
