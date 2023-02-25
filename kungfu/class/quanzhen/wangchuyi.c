// wangchuyi.c 王处一
// By Lgg,1998.10

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;

string ask_me();

void create()
{
	set_name("王处一", ({"wang chuyi", "wang"}));
	set("gender", "男性");
	set("age", 35);
	set("class", "taoist");
	set("nickname",RED"玉阳子"NOR);
	set("long",
		"他就是全真七子之五王处一王真人。他身材修长，服饰整洁，\n"
		"三绺黑须飘在胸前，神态潇洒。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("con", 32);
	set("dex", 30);

	set("title","全真七子之五");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
	}));

	set("qi", 4200);
	set("max_qi", 4200);
	set("jing", 2100);
	set("max_jing", 2100);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 100);

	set("combat_exp", 1200000);

	set_skill("force", 170);
	set_skill("quanzhen-xinfa", 170);
	set_skill("sword", 160);
	set_skill("quanzhen-jian",160);
	set_skill("dodge", 150);
	set_skill("jinyan-gong", 150);
	set_skill("parry", 170);
	set_skill("strike", 170);
	set_skill("chongyang-shenzhang", 170);
	set_skill("haotian-zhang", 170);
	set_skill("literate",100);
	set_skill("finger",150);
	set_skill("zhongnan-zhi", 170);
	set_skill("taoism",100);
	set_skill("medical", 180);
	set_skill("liandan-shu", 180);

	map_skill("force", "quanzhen-xinfa");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger", "zhongnan-zhi");
	map_skill("strike", "haotian-zhang");
	prepare_skill("finger", "zhongnan-zhi");
	prepare_skill("strike", "haotian-zhang");

	create_family("全真教", 2, "弟子");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"南帝" : (: ask_me :),
		"段皇爷" : (: ask_me :),
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_skill("quanzhen-xinfa", 1) < 90)
	{
		command("say 你的本门内功心法火候不足，难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 8000)
	{
		command("say 我看你还是多做一些侠义之事吧。\n");
		return;
	}
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

string ask_me()
{
	object me=this_player();

	if (me->query_temp("tmark/指") == 1)
	{
		me->add_temp("tmark/指",1);
		return("去年师傅去过段皇爷那里，据说段皇爷把他最厉害的一阳指功夫
传授给我师傅了。\n");
	} else
	{
		me->set_temp("tmark/指",0);
		return("段皇爷遇上了一件大伤心事，现在出家做了和尚了，唉！");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
