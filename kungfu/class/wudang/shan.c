// shan.c 张翠山

#include <ansi.h>
#include "wudang.h"

inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
	set_name("张翠山", ({ "zhang cuishan", "zhang" }));  
	set("nickname","武当五侠");
	set("long", 
		"他就是张三丰的五弟子、武当七侠之中的张翠山。\n"
		"身穿一件干干净净的白色道袍。\n");
	set("gender", "男性");
	set("age",31);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 35);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 150);
	set("combat_exp", 1400000);
	set("score", 60000);

	set_skill("force", 180);
	set_skill("wudang-xinfa", 180);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 170);
	set_skill("tiyunzong", 170);
	set_skill("unarmed", 180);
	set_skill("taiji-quan", 180);
	set_skill("strike", 180);
	set_skill("yitian-zhang", 180);
	set_skill("wudang-zhang", 170);
	set_skill("hand", 160);
	set_skill("paiyun-shou", 160);
	set_skill("parry", 180);
	set_skill("sword", 175);
	set_skill("wudang-jian", 175);
	set_skill("taiji-jian", 175);
	set_skill("taoism", 160);
	set_skill("literate", 120);

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
	map_skill("strike", "yitian-zhang");

	prepare_skill("strike", "yitian-zhang");

	create_family("武当派", 2, "弟子");

	set("inquiry", ([
		"倚天屠龙掌": (: ask_me :),
		"谁与争锋"  : (: ask_me :),
		"绝招"  : (: ask_me :),
	]));

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zheng" :),
	}) );

	setup();

	carry_object("/d/wudang/obj/whiterobe")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",2 , ob);
	}
}

void greeting(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	if (find_object(query("startroom")) == environment())
		return;

	if ((int)ob->query("shen") < -1000)
	{
		say(CYN "\n\n张翠山脸现怒容：“邪魔外道，吃了豹子"
		    "胆了，敢乱闯武当！”\n\n");
		message_vision("张翠山居高临下，出手一招，$N只"
			       "得硬接，身子晃了一下。\n", ob);
		COMBAT_D->do_attack(this_object(), ob, query_temp("weapon"));
	}
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 30)
	{
		command("say 你的资质还没到铁划银钩的境界，收你也是白搭。\n");
		return;
	}

	if ((int)ob->query("shen") < 5000)
	{
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query_skill("wudang-xinfa", 1) < 70)
	{
		command("say 我武当派最注重内功心法" + RANK_D->query_respect(ob)+
			"是否应该在武当心法上多下点功夫啊?");
		return;
	}

	if ((int)ob->query_skill("taoism", 1) < 70)
	{
		command("say 习武是为了强身健体，一味的练武是不可取的。");
		command("say 我看你还需要在修身养性方面多锻炼锻炼，以提高你"
			"的道德心法。");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/yitian-zhang/zheng"))
		return "你不是已经会了吗，是不是想我再施展一次在你身上？";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们武当派的人，何出此言？";

	if (me->query("shen") < 120000)
		return "你行侠仗义的事情做的还很不够，我不能传你绝招！";

	if (me->query_skill("yitian-zhang", 1) < 125)
		return "你的倚天屠龙掌还不到家，要多练练！";

	message_vision(HIY "$n" HIY "点了点头，运起太极神功，将倚天屠"
		       "龙掌二十四字一气呵成，携带着排山倒海之劲一\n齐"
		       "施展了出来。只见双掌纷飞，掌风凌厉，直刮得$N" HIY
		       "脸庞隐隐生痛。"NOR"\n",
		       me, this_object());
	command("nod");
	command("say 将倚天屠龙掌二十四招连续使出，便是新招。你可明白了？");
	tell_object(me, HIC "你学会了「谁与争锋」这一招。"NOR"\n");
	if (me->can_improve_skill("strike"))
		me->improve_skill("strike", 160000);
	me->set("can_perform/yitian-zhang/zheng", 1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
