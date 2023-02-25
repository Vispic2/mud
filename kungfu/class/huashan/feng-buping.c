// feng-buping.c  封不平

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_GUARDER;

#include <ansi.h>
#include "jianzong.h"

mixed ask_feilong();
mixed ask_sanxian();
mixed ask_sword_martial();

void create()
{
	set_name("封不平", ({ "feng buping", "feng" }) );
	set("nickname", YEL"狂风快剑"NOR);
	set("gender", "男性");
	set("class", "swordsman");
	set("title", "华山剑宗第十三代弟子");
	set("age", 45);
	set("long",
		"封不平是华山剑宗第一高手，满脸戾气一张黄焦焦的面皮。\n");
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 32);
	set("con", 31);
	set("dex", 29);

	set("max_qi", 4700);
	set("max_jing", 2400);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);

	set("combat_exp", 1800000);
	set("shen_type", -1);
	set("apprentice_available", 3);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feilong" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	set_skill("unarmed", 180);
	set_skill("sword", 220);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("strike", 180);
	set_skill("dodge", 190);
	set_skill("literate", 100);
	set_skill("huashan-sword", 220);
	set_skill("kuangfeng-jian", 220);
	set_skill("huashan-xinfa", 200);
	set_skill("huashan-quanfa", 180);
	set_skill("huashan-zhangfa", 180);
	set_skill("huashan-shenfa", 190);

	map_skill("sword", "kuangfeng-jian");
	map_skill("parry", "kuangfeng-jian");
	map_skill("force", "huashan-xinfa");
	map_skill("unarmed", "huashan-quanfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	set("inquiry", ([
		"绝招"   : "我剑宗剑法精奇，你想学哪门绝招？",
		"绝技"   : "我剑宗剑法精奇，你想学哪门绝招？",
		"剑道修养" : (: ask_sword_martial :),
		"天外飞龙" : (: ask_feilong :),
		"夺命连环三仙剑" : (: ask_sanxian :),
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.kuang" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack", 220);
	set_temp("apply/defense", 220);
	set_temp("apply/damage", 200);
	set_temp("apply/unarmed_damage", 200);

	create_family("华山剑宗", 13, "弟子");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

mixed ask_feilong()
{
	object me;

	me = this_player();
	if (me->query("can_perform/huashan-sword/feilong"))
		return "你还不快去练习武功，一雪我们剑宗羞耻？";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们华山剑宗的人，请走吧！";

	if (me->query_skill("huashan-sword", 1) < 150)
		return "你的华山剑法还不到家，不要再给我丢脸了！";

	message_vision(HIY "$n" HIY "大喝一声，手中粘了一个石子"
		       "奋力击出，飞至半空突然化作粉末！\n"
		       HIY "$n" HIY "回头凝视着$N" HIY "道：这一"
		       "招没什么稀奇，就是要舍生忘死，运足内力！"
		       "你虽为剑宗弟子，也要好好修炼内力！"NOR"\n",
		       me, this_object());
	tell_object(me, HIG "你学会了天外飞龙。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 90000);
	me->set("can_perform/huashan-sword/feilong", 1);
	return 1;
}

mixed ask_sanxian()
{
	object me;

	me = this_player();
	if (me->query("can_perform/huashan-sword/sanxian"))
		return "你还不快去练习武功，一雪我们剑宗羞耻？";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + "不是我们华山剑宗的人，请走吧！";

	if (me->query_skill("huashan-sword", 1) < 135)
		return "你的华山剑法学成这个样子，还有脸向我讨教绝技？";

	message_vision(HIY "$n" HIY "看了看四周，并无他人，于是站起身来，慢慢演出数剑，招式\n"
		       "精妙，当真是匪夷所思！\n"
		       HIY "$n" HIY "坐下，沉思良久，乃道：“当年剑气相争，我剑宗弟子使出这\n"
		       "门绝技，连毙对方多名高手，威力非同小可。你可要好好研习！"NOR"\n",
		       me, this_object());
	tell_object(me, HIG "你学会了夺命连环三仙剑。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 90000);
	me->set("can_perform/huashan-sword/sanxian", 1);
	return 1;
}

mixed ask_sword_martial()
{
	object ob;
	object me;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) +
		       "，剑道漫漫，自己要勤加修炼啊！";

	if (me->query("combat_exp") < 200000)
		return "你这点武功也来向我求教剑道奥妙？好好给我练功去！";

	if (me->query_skill("sword-cognize", 1) < 10)
		return "你毫无剑道修养根基，我如何与你谈其中奥妙？";

	if (me->query_skill("sword-cognize", 1) >= 200)
		return "你剑道了解得已经不少了，我是没什么好再教你的了。";

	if (me->query_temp("last_ask/murongbo/martial") + 60 > time())
		return "改日再谈吧，今天你要多想想，好好体会体会。";

	message_vision("$N看看$n，道：“好吧，我就与你谈谈我在剑道方面的心得。”\n",
		       this_object(), me);

	if (me->query("potential") - me->query("learned_points") < 100)
	{
		tell_object(me, "你听得迷迷糊糊的，没听出个所以然，看来是潜能不够。\n");
		return 1;
	}

	me->add("learned_points", 100);
	tell_object(me, HIG "你听的心中豁然开朗，通晓了不少剑道的奥妙。"NOR"\n");
	me->set_temp("last_ask/murongbo/martial", time());
	me->improve_skill("sword-cognize", 1500 + random(2000));
	return 1;
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob) )
		return;

	if (query("apprentice_available"))
	{
		if (find_call_out("do_recruit") != -1)
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else
	{
		command("say 老夫今天已经收了三个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if ((int)ob->query_int() < 24)
		command("say 我华山派以剑法为主，依我看" + RANK_D->query_respect(ob) +
			"的智力不适合于学剑法。");
	else
	{
		command("say 好，好，好，很好。");
		command("recruit " + ob->query("id"));
	}
}

int recruit_apprentice(object ob)
{
	if (::recruit_apprentice(ob))
		ob->set("title", "华山剑宗第十四代弟子");
		add("apprentice_availavble", -1);
}

void reset()
{
	set("apprentice_available", 3);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
