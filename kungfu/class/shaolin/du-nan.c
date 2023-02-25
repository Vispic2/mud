// dunan.c

inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
	set_name("渡难", ({ "du nan", "nan" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁铸成。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2500000);

	set("str", 33);
	set("int", 32);
	set("con", 34);
	set("dex", 31);

	set("qi", 5200);
	set("max_qi", 2600);
	set("neili", 7400);
	set("max_neili", 7400);
	set("jiali", 100);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("buddhism", 250);
	set_skill("force", 260);
	set_skill("whip", 260);
	set_skill("parry", 260);
	set_skill("dodge", 250);

	set_skill("hunyuan-yiqi", 260);
	set_skill("shaolin-xinfa", 260);
	set_skill("riyue-bian", 260);
	set_skill("shaolin-shenfa", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("strike", 260);
	set_skill("xumishan-zhang", 260);
	set_skill("claw", 250);
	set_skill("hand", 250);
	set_skill("longzhua-gong", 250);
	set_skill("qianye-shou", 250);

	map_skill("strike", "xumishan-zhang");

	prepare_skill("strike", "xumishan-zhang");

	set_skill("medical", 220);
	set_skill("shaolin-yishu", 220);

	set("inquiry", ([
		"菩提子"     : (: ask_me :),
	]));

	set("count", 1);
	if (random(16) == 8) add("count", 1);

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: perform_action, "strike.ying" :),
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

	if (uptime() < 1800)
		return "菩提子乃天地之灵物，制炼艰难无比，我现在可没有。";

	if (present("puti zi", me))
		return RANK_D->query_respect(me) + 
		"菩提子只有一颗，而且就在你身上，真是贪得无餍！";

	if (present("puti zi", environment()))
		return RANK_D->query_respect(me) + 
		"菩提子只有一颗，而且就在这里任你取走，真是贪得无餍！";

	if (query("count") < 1)
		return "菩提子乃天地之灵物，采集艰难无比，我这里现在可没有。";

	ob = new("/clone/gift/puti-zi");

	add("count", -1);

	message_vision("$N惨然一笑，接着长叹一声，从树洞里取出个白玉磁瓶，倒出菩提子递给$n。\n",
		       this_object(), me);
	ob->move(me, 1);

	return "我等昔年于佛祖座前发下宏愿，每十年遍访名山大川，历尽艰险，\n" +
	       "方采得数颗菩提子，君乃有缘人，能得此造化奇物，望好自为之！";
}

#include "/kungfu/class/shaolin/du.h"

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
