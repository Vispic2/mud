// due.c

inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
	set_name("渡厄", ({ "du e", "e" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色"
		"枯黄，如同一段枯木。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2350000);

	set("str", 34);
	set("int", 36);
	set("con", 35);
	set("dex", 33);

	set("qi", 5800);
	set("max_qi", 2900);
	set("neili", 7200);
	set("max_neili", 7200);
	set("jiali", 110);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("buddhism", 250);
	set_skill("force", 270);
	set_skill("whip", 270);
	set_skill("parry", 270);
	set_skill("dodge", 260);

	set_skill("hunyuan-yiqi", 270);
	set_skill("shaolin-xinfa", 270);
	set_skill("riyue-bian", 270);
	set_skill("shaolin-shenfa", 260);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("finger", 260);
	set_skill("strike", 260);
	set_skill("nianhua-zhi", 260);
	set_skill("sanhua-zhang", 260);

	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	set_skill("medical", 250);
	set_skill("shaolin-yishu", 250);

	set("inquiry", ([
		"伏魔杖"     : (: ask_me :),
	]));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: perform_action, "finger.fuxue" :),
		(: perform_action, "strike.san" :),
		(: perform_action, "whip.chan" :),
		(: perform_action, "whip.he" :),
		(: perform_action, "whip.shang" :),
	}));

	setup();
}

mixed ask_me()
{
	mapping fam; 
	object ob;
	object me;
	
	me = this_player();
	if (! me->query_temp("valid_in_fumoquan"))
	{
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		kill_ob(me);
		return 1;
	}

	if (me->query_temp("valid_in_fumoquan") != 1)
	{
		command("heng");
		return 1;
	}

	if (me->query("combat_exp") < 1000000)
		return "你这点微末本事，打听达摩祖师留下的利器作甚？";

	if (present("fumo zhang", me))
		return RANK_D->query_respect(me) + 
		"宝杖只有一把，而且就在你身上，真是贪得无餍！";

	if (present("fumo zhang", environment()) )
		return RANK_D->query_respect(me) + 
		"宝杖只有一把，而且就在这里任你取走，真是贪得无餍！";

	ob = get_object("/d/shaolin/obj/fumo-zhang");
	if (! ob || environment(ob) && environment(ob) != this_object())
		return "抱歉，你来晚了，伏魔杖已经给人取走了。";

	message_vision("$N长笑一声，点点头，从身后的树洞里取出伏魔杖交给$n。\n",
		       this_object(), me);
	ob->move(me, 1);

	return "你既然能闯进金刚伏魔圈来，必然是当今武林中的非凡人物，这伏魔杖是适逢其主了！";
}

#include "/kungfu/class/shaolin/du.h"

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
