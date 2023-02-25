#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	object ling2;
	set_name("妙风使", ({ "miaofeng shi", "miaofeng", "shi" }));
	set("long", "一个三十多岁的中年美妇，装束奇异，不同\n"
		    "普通的中土人士。这便是波斯明教总教教主\n"
		    "座下的妙风使。\n");
	set("title", HIB "波斯总教教主座下" NOR);
	set("nickname", HIY "云风月三使" NOR);
	set("gender", "女性");
	set("age", 33);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 800);
	set("neili", 2600);
	set("max_neili", 2600);
	set("jiali", 100);
	set("combat_exp", 800000);

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("literate", 100);
	set_skill("sanscrit", 300);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 180);
	set_skill("parry", 180);
	set_skill("finger", 220);
	set_skill("strike", 220);
	set_skill("sword", 180);
	set_skill("shenghuo-ling", 180);
	set_skill("tougu-zhen", 220);
	set_skill("yinfeng-dao", 220);
	set_skill("shenghuo-xinfa", 200);
	set_skill("qiankun-danuoyi", 180);
	set_skill("sanscrit", 200);

	map_skill("dodge", "qiankun-danuoyi");
	map_skill("force", "shenghuo-xinfa");
	map_skill("finger", "tougu-zhen");
	map_skill("strike", "yinfeng-dao");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-ling");

	prepare_skill("strike", "yinfeng-dao");
	prepare_skill("finger", "tougu-zhen");

	create_family("波斯明教总舵", 32, "弟子");

	setup();

	if (clonep())
	{
		ling2 = find_object("/clone/book/ling2");
		if (! ling2) ling2 = load_object("/clone/book/ling2");
		if (! environment(ling2))
			ling2->move(this_object());
			ling2->wield();
	}

	carry_object(__DIR__"obj/jiaofu")->wear();
}

void init()
{
	object me;

	me = this_player();

	if (! interactive(me))
		return;

	if (living(this_object()) && present("yitian sword", me))
	{
		command("say 咦？倚天剑怎么会在你手里，看来这次中原之行没白跑了！");
		kill_ob(me);
		return;
	}

	if (living(this_object()) && present("tulong blade", me))
	{
		command("say 哼，把屠龙刀交出来，我们已经守侯多时了！");
		kill_ob(me);
		return;
	}

	if (living(this_object()) && present("shenghuo ling", me))
	{
		command("say 咦？你怎么会拿着我教的圣火令？死吧！");
		kill_ob(me);
		return;
	}
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("shen") > 1000)
	{
		command("say 叽哩古拉，花不鲁鲁，你这人看上去不象是好人，开滚。");
		return -1;
	}

	if (skill != "sanscrit")
	{
		command("say 教你点我在印度学的一点东西，你还不知足啊？");
		return -1;
	}

	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
