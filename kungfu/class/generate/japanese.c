// japanese.c 日本鬼子

inherit CHALLENGER;

void create()
{
	object ob;

	set_name("日本鬼子", ({ "japanese" }));
	set("long", "日本鬼子。\n");
	set("gender", "男性");
	set("age", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	// the follow 5 setting has no use
	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 100);
	set("shen", -1000);

	set("combat_exp", 3000000);
	set("scale", 100);

	set_skill("force", 200);
	set_skill("fushang-neigong", 200);
	set_skill("dodge", 200);
	set_skill("renshu", 200);
	set_skill("parry", 200);
	set_skill("dongyang-dao", 200);
	set_skill("blade", 200);

	map_skill("blade", "dongyang-dao");
	map_skill("force", "fushang-neigong");
	map_skill("dodge", "renshu");
	map_skill("parry", "dongyang-dao");

	set("rank_info/rude", "鬼子");

	set("die_give", ([
		"/clone/vip/putao" : 2,
		"/clone/vip/putao" : 2,
		"/clone/vip/putao" : 2,
		"/clone/vip/putao" : 2,
		"/clone/vip/putao" : 2,
	]));

	set("die_give2", ([
		"/clone/vip/dan_jiuzhuan" : 3,
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "blade.luan" :),
		(: perform_action, "blade.zhan" :),
	}));

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/jpn-dao")->wield();
}

string challenge()
{
	set("opinion/msg", ({
		(random(2) ? "此人来自东洋扶桑，据说那里的东洋刀法极其怪异。"
			   : "东洋扶桑远在东海之外，那里的武士擅长使用窄刃长刀。"),
		(random(2) ? "是啊，东洋忍术也是诡秘得很。"
			   : "没错，不过东洋刀造型奇特，配合忍术还是颇有威力。"),
		(random(2) ? "哼！此人气焰如此嚣张，实为习武者大忌！"
			   : "此人可谓鼠目寸光，须知武道无穷，一丝也马虎不得！"),
	}));

	command(random(2) ? "haha" : "heng");
	switch (random(3))
	{
	case 0:
		return "我！大和武士" + name() + "，来向你们中原"
			"武人挑战！谁敢出来迎战？";

	case 1:
		return "我就是东洋扶桑国的" + name() + "，你们中"
			"原有没有人是我的对手？";

	default:
		return "我" + name() + "代表大和武士来向你们挑战"
			"，有种的就给我滚出来！";
	}
}

void unconcious()
{
	command("chat 八格呀路！");
	die();
}

void competition_with(object ob)
{
	command("say 八格呀路，你死去吧！\n");
	::competition_with(ob);
	kill_ob(ob);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
