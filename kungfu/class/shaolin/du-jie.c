// dujie.c

inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
	set_name("渡劫", ({ "du jie", "jie" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色惨白，象一张纸一样。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2300000);

	set("str", 32);
	set("int", 30);
	set("con", 33);
	set("dex", 31);

	set("qi", 5000);
	set("max_qi", 2500);
	set("neili", 6700);
	set("max_neili", 6700);
	set("jiali", 90);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("buddhism", 250);
	set_skill("force", 255);
	set_skill("whip", 255);
	set_skill("parry", 250);
	set_skill("dodge", 240);

	set_skill("hunyuan-yiqi", 255);
	set_skill("shaolin-xinfa", 255);
	set_skill("riyue-bian", 255);
	set_skill("shaolin-shenfa", 240);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("finger", 250);
	set_skill("jingang-zhi", 250);

	map_skill("finger", "jinggang-zhi");

	prepare_skill("finger", "jingang-zhi");

	set_skill("medical", 200);
	set_skill("shaolin-yishu", 200);

	set("inquiry", ([
		"金刚罩"     : (: ask_me :),
	]));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: perform_action, "finger.fumo" :),
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
		return "你这点微末本事，打听达摩祖师留下的宝物作甚？";

	if (present("jingang zhao", me))
		return RANK_D->query_respect(me) + 
		"宝罩只有一件，而且就在你身上，真是贪得无餍！";

	if (present("jingang zhao", environment()))
		return RANK_D->query_respect(me) + 
		"宝罩只有一件，而且就在这里任你取走，真是贪得无餍！";

	ob = get_object("/d/shaolin/obj/jingang-zhao");
	if (! ob || environment(ob) && environment(ob) != this_object())
		return "抱歉，你来晚了，金刚罩已经给人取走了。";

	message_vision("$N一声不吭地瞧了$N半饷，扭过身，从树洞里取出金刚罩递给$n。\n",
		       this_object(), me);
	ob->move(me, 1);

	return "你能挨我们三个老不死的三招日月神鞭不死，确实是命大，这件金刚罩就是你的了！";
}

#include "/kungfu/class/shaolin/du.h"

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
