// yang.c 杨过

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>
#include "gumu.h"

string ask_yunv();
int not_to_learn_ss(object ob);

void create()
{
	set_name("杨过", ({"yang guo", "yang"}));
	set("gender", "男性");
	set("age", 26);
	set("long", @LONG
他看上去眉目之间有一股清秀之气，然而隐隐约约却让人感到一阵哀伤之情，
左袖空荡荡的，显然已是残疾。
LONG );
	set("attitude", "friendly");

	set("str", 35);
	set("int", 36);
	set("con", 34);
	set("dex", 32);

	set("qi", 5800);
	set("max_qi", 5800);
	set("jing", 2900);
	set("max_jing", 2900);
	set("neili", 8500);
	set("max_neili", 8500);
	set("jiali", 120);

	set("combat_exp", 2750000);

	set_skill("force", 290);
	set_skill("yunv-xinfa", 290);
	set_skill("surge-force", 290);
	set_skill("sword", 280);
	set_skill("yunv-jian", 280);
	set_skill("quanzhen-jian", 280);
	set_skill("xuantie-jian", 280);
	set_skill("dodge", 250);
	set_skill("yunv-shenfa", 250);
	set_skill("parry", 285);
	set_skill("unarmed", 285);
	set_skill("meinv-quan", 270);
	set_skill("strike", 280);
	set_skill("sad-strike", 280);
	set_skill("fireice-strike", 280);
	set_skill("tianluo-diwang", 260);
	set_skill("literate", 150);
	set_skill("taoism", 80);
	set_skill("medical", 180);
	set_skill("yunv-xinjing", 180);
	set_skill("throwing", 240);
	set_skill("yufeng-zhen", 240);

	map_skill("force", "surge-force");
	map_skill("sword", "xuantie-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "sad-strike");
	map_skill("strike", "tianluo-diwang");

	prepare_skill("unarmed", "sad-strike");

	create_family("古墓派", 3, "弟子");

	set("inquiry", ([
		"王重阳" : "嘿...嘿！",
		"郭靖"   : "他可真是真正的大侠。",
		"黄蓉"   : "黄师叔么...真不好说啊。",
		"小龙女" : "你打听我妻子干什么？",
		"杨康"   : "算了，不替他也罢。",
		"玉蜂针" : "我手头可没有，很久没有用它了。",
	]));

	set("guarder", ([
		"refuse_home" : "$N对$n冷冷道：滚！",
		"refuse_other": "$N对$n道：后面是古墓弟子练功的地方，你少要打扰！",
		"refuse_carry": "$N对$n喝道：把你身上得人给我撂下！",
	]));

	set("no_teach/sad_strike", (: not_to_learn_ss :));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "strike.wang" :),
		(: perform_action, "unarmed.sad" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();

	carry_object("/clone/cloth/qingyi")->wear();
}

int not_to_learn_ss(object ob)
{
	if (ob->query("gender") == "女性")
	{
		command("say 我这门武功不适合女孩子学习，还是算了吧！");
		return 1;
	}

	if (ob->query_temp("can_learn/yang/sad-strike"))
		return 0;

	if (ob->query("static/sadly") < 3)
	{
		command("say 你体会不到那种思念妻子的情怀，"
			"无法领会我的黯然销魂掌！");
		return 1;
	}

	message_vision("$n看了看$N，道：好！你我也算是颇有"
		       "渊源，我就传你黯然销魂掌！\n",
		       ob, this_object());
	ob->set_temp("can_learn/yang/sad-strike", 1);
	return 0;
}

int recognize_apprentice(object ob, string skill)
{
	if (ob->query("family/family_name") == query("family/family_name"))
	{
		if (query_skill(skill) < 1 ||
		    SKILL_D(skill)->type() != "martial")
			return 0;

		if (ob->query_int() < 32)
		{
			command("say 你这人资质不佳，我教起来太累。");
			return -1;
		}

		return 1;
	}

	if (skill == "unarmed" &&
	    this_player()->query_skill("sad-strike", 1) > 0 &&
	    this_player()->query_skill(skill, 1) < 180)
		return 1;

	if (skill != "sad-strike")
	{
		command("say 你还是找你的师傅去学习吧！");
		return 0;
	}

	if (not_to_learn_ss(ob))
		return -1;

	return 1;
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 32)
	{
		command("say 你的资质不够，难以领会上乘武功。");
		return;
	}

	if ((int)ob->query_skill("force") < 150)
	{
		command("say 想拜我为师么？你把内功练好了再来吧！");
		return;
	}

	if ((int)ob->query("max_neili") < 1000)
	{
		command("say 你把内力锻炼好了再来也不迟啊！");
		return;
	}

	command("say 好吧，看你也是性情中人，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
