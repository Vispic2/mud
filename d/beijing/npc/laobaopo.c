inherit NPC;

void create()
{
	set_name("老鸨婆", ({ "laobao po", "laobao", "po" }) );
	set("gender", "女性" );
	set("title", "怡红院老板娘");
	set("age", 42);
	set("long", 
	    "\n这老鸨婆虽是徐娘半老，但仍风韵尤存，只不过脸上的粉太厚了。\n");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", -1);

	set("combat_exp", 25000);

	set("max_qi", 300);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("attitude", "friendly");

	setup();
	carry_object("/d/beijing/npc/obj/nvcloth")->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	command("look " + me->query("id"));

	if (me->query("gender") == "无性")
	{
		command("say 你当老娘是烂婊子吗？辣块妈妈，老娘满汉蒙藏回都接，就是不伺候太监！");
		command("kick " + me->query("id"));
		message("vision", me->name() +"被老鸨婆一脚踢出门外。\n",
			environment(me), ({me}));
		me->move("/d/beijing/wang_8");
		message("vision", me->name() +"被人从怡红院里踢了出来，栽倒在地上，磕掉两颗门牙。\n", 
			environment(me), ({me}));
	} else
	{
		if (me->query("class") == "bonze")
		{
			command("say 呦，" + RANK_D->query_respect(me) +
				"也来光顾我们怡红院啊。");
		}
		if (me->query("gender") == "女性")
		{
			command("say 哎呀，这年月大姑娘也逛窑子，成何体统。");
			command("say 可惜我儿子不在，不然让他伺候你。");
		}
		command("say 楼上楼下的姑娘们，客人来了！");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
