// zhou.c 周芷若

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT; 

#include <command.h>
#include <ansi.h>
#include "emei.h"

string no_teach_jybgz();

void create()
{
	set_name("周芷若", ({ "zhou zhiruo","zhiruo","zhou"}));
	set("long",
		"她是峨嵋派的第四代掌门弟子。\n"
		"一张脸秀丽绝俗。身着一身淡黄衣裳。\n"
		"略显清减的巧笑中带了些许无奈。\n"
		"她很寂寞。\n");
	set("gender", "女性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "claw.duo" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("inquiry",([
		"剃度"    : "找我剃度？不对吧。",
		"出家"    : "要出家找我的师姐们去。",
		"还俗"    : "无聊。还俗也找我！",
		"张无忌"  : "这个狠心短命的家伙，我再也不要见她！",
		"赵敏"    : "不要问这个贱婢子！",
		"倚天剑"  : "倚天不出，谁与争锋？唉！",
		"屠龙刀"  : "你想武林称雄？别做梦了。",
		"灭绝师太"  : "师父难得收徒。你先巴结我吧。",
	]));
	set("str", 22);
	set("int", 32);
	set("con", 26);
	set("dex", 24);

	set("max_qi", 5800);
	set("max_jing", 1900);
	set("neili", 4400);
	set("max_neili", 4400);
	set("jingli", 1200);
	set("max_jingli", 1200);

	set("combat_exp", 2000000);
	set_skill("persuading", 120);
	set_skill("force", 170);
	set_skill("throwing", 150);
	set_skill("dodge", 170);
	set_skill("finger", 140);
	set_skill("parry", 170);
	set_skill("unarmed", 130);
	set_skill("strike", 145);
	set_skill("sword", 170);
	set_skill("claw", 270);
	set_skill("literate", 120);
	set_skill("mahayana", 140);
	set_skill("jinding-zhang", 145);
	set_skill("jiuyin-baiguzhao", 270);
	set_skill("tiangang-zhi", 140);
	set_skill("huifeng-jian", 170);
	set_skill("zhutian-bu", 150);
	set_skill("emei-xinfa", 170);
	set_skill("linji-zhuang", 170);
	set_skill("martial-cognize", 200);

	map_skill("force","linji-zhuang");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");
	create_family("峨嵋派", 4, "掌门弟子");

	set("no_teach", ([
		"linji-zhuang" : "想学临济十二庄？找灭绝师太去。",
		"jiuyin-baiguzhao" : (: no_teach_jybgz :),
	]));

	setup();
	carry_object("/d/emei/obj/ycloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if ((int)ob->query_int() < 30)
	{
		command("say 这位" + RANK_D->query_respect(ob) + "恐怕资质差了一点。");
		command("say 不过尚大有潜力，还是先回去磨练磨练。");
		return;
	}

	command("say " + ob->query("name") + "看你这么可怜，勉为其难收下你吧。\n");
	command("recruit " + ob->query("id"));
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("family/family_name") != query("family/family_name"))
	{
		command("say 给我滚到一边去！");
		return -1;
	}

	if (skill == "claw")
	{
		if (! me->query_temp("can_learn/zhou"))
		{
			command("say 哼哼！爪法方面我颇有点心得，你既然兴趣，我就指点指点你好了。");
			me->set_temp("can_learn/zhou", 1);
		}

		return 1;
	}

	command("say 找你师傅学去吧！别问我。");
	return -1;
}

string no_teach_jybgz()
{
	object me;

	me = this_player();
	if (me->query("shen") < 20000)
		return "你这人，行侠仗义的事情做得太少，我怎能放心教你这种狠辣的武功？";

	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
