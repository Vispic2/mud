// linghu.c 令狐冲

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
#include "qizong.h"

mixed ask_me();

void create()
{
	set_name("令狐冲", ({ "linghu chong", "linghu", "chong" }));
	set("nickname", "大师兄");
	set("long", "令弧冲身材较瘦，长的浓眉阔眼，气宇暄昂，在同门中排行老大，\n"
		    "是华山派年轻一代中的顶尖好手。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 4800);
	set("max_qi", 4800);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 5700);
	set("max_neili", 5700);
	set("jiali", 60);

	set("combat_exp", 2200000);
	set("score", 150000);

	set_skill("blade", 120);
	set_skill("cuff", 120);
	set_skill("feiyan-huixiang", 200);
	set_skill("strike", 120);
	set_skill("huashan-zhangfa",120);
	set_skill("unarmed",120);
	set_skill("huashan-quanfa",120);
	set_skill("force", 220);
	set_skill("yijinjing", 220);
	set_skill("dodge", 200);
	set_skill("parry", 220);
	set_skill("sword", 240);
	set_skill("huashan-sword", 240);
	set_skill("lonely-sword", 240);
	set_skill("literate", 40);
	set_skill("tanqin-jifa", 250);
	set_skill("xiaoao-jianghu", 250);
	set_skill("qingxin-pushan", 250);

	map_skill("force", "yijinjing");
	map_skill("unarmed", "huashan-quanfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("tanqin-jifa", "xiaoao-jianghu");

	create_family("华山派", 14, "弟子");

	set("inquiry", ([
		"风清扬" : "唉，已经很久没有见到他老人家了。你问这干嘛？",
		"任盈盈" : "你要干什么？想找麻烦吗？",
		"清心普善咒" : "这可是莹莹教给我的...",
		"笑傲江湖"   : "这是曲洋长老和刘正风师叔留下来的...唉！",
		"琴谱"       : (: ask_me :),
     	]));

	set("no_teach", ([
		"yijinjing" : "此乃少林秘传，蒙方正大师传授，我不能擅自教你。",
		"lonely-sword" : "风老先生传我九剑的时候我立下誓言不得私"
				 "自传授，你还是学习其他武功吧！",
	]));

	set("music_book", 1);
	setup();	 	
	carry_object("/d/heimuya/npc/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/heimuya/npc/obj/card2");
}

int recognize_apprentice(object me, string skill)
{
	if (skill != "tanqin-jifa" &&
	    skill != "xiaoao-jianghu" &&
	    skill != "qingxin-pushan")
	{
		command("say 对不起...我不能传授你这些，你要是想学点操琴技术还差不多。");
		return -1;
	}

	if (me->query_temp("can_learn/linghu/" + skill))
		return 1;

	me->set_temp("can_learn/linghu/" + skill, 1);
	command("say 好吧，你既然对" + to_chinese(skill) +
		"有兴趣，我就教你一点。");

	return 1;
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query("combat_exp") < 1000000)
	{
		command("say 你的实战经验不行，我不想收你为徒。");
		return;
	}

	if (ob->query_int() < 28)
	{
		command("say 你天生悟性太差，学不好华山派的功夫。");
		return;
	}

	if (ob->query_skill("sword", 1) < 120)
	{
		command("say 华山剑法乃是以剑为基础，你的基本"
			"剑法还没有学好，我看算了吧。");
		return;
	}

	if( ob->query_skill("force", 1) < 120 )
	{
		command("say 虽然剑法讲究剑术，可是内力不行实"
			"战效果也不会好，你先打好内功基础。");
		return;
	}

       	command("nod");
	command("say 好吧，我收下你作徒弟了。");
	command("recruit " + ob->query("id"));
	return;
}

mixed ask_me()
{
	object me;
	object ob;

	me = this_player();
	if (query("music_book") < 1)
		return "我的琴谱已经借出去了。\n";

	ob = new("/clone/book/qin");
	ob->move(me, 1);
	message_vision("$n把琴谱给了$N，道：你拿去好好学习吧。\n",
		       me, this_object());
	set("music_book", 0);
	return 1;
}

void reset()
{
	set("music_book", 1);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
