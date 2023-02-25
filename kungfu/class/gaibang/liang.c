// liang.c

inherit NPC;
inherit F_MASTER;
inherit F_GUARDER;

#include <ansi.h>

void kicking(object ob);

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "传功长老");
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。"
		"丐帮武功向来较强，近来梁长老一力整顿，更是蒸蒸日上。\n");

	set("attitude", "peaceful");
	set("class", "beggar");
	set("no_get", 1);
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 4800);
	set("max_neili", 4800);
	set("jiali", 100);
	
	set("combat_exp", 1200000);
	
	set_skill("force", 195);
	set_skill("jiaohua-neigong", 195);
	set_skill("unarmed", 180);
	set_skill("changquan", 180);
	set_skill("strike", 170);
	set_skill("xiaoyaoyou", 170);
	set_skill("dodge", 170);
	set_skill("feiyan-zoubi", 170);
	set_skill("parry", 190);
	set_skill("staff", 170);
	set_skill("jiaohua-bangfa", 170);
	set_skill("begging", 80);
	set_skill("checking", 150);
	set_skill("training", 120);
	
	map_skill("force", "jiahua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("strike", "xiaoyaoyou");
	map_skill("staff", "jiaohua-bangfa");
	map_skill("dodge", "feiyan-zoubi");

	create_family("丐帮", 18, "九袋长老");
	setup();
}

void init()
{
	object ob;
	mapping myfam;
	
	::init();

	if (! stringp(query("startroom")) ||
	    find_object(query("startroom")) != environment())
		return;

	if (interactive(ob = this_player()) &&
	    ! wizardp(ob) && ! is_fighting() && living(this_object()))
	{
		myfam = (mapping)ob->query("family");
		if (! myfam || myfam["family_name"] != "丐帮")
		{
			message_vision(HIW "粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！"NOR"\n",
				       ob);
			kicking(ob);
		}
	}
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	message_vision(HIC "只见梁长老一脚恰好踢中$N的屁股" + "，$N一个跟斗就飞了出去。"NOR"\n", ob);

	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +
		"从小门里飞了出来。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	if (ob->query("detach/丐帮") || ob->query("betrayer/丐帮"))
	{
		command("say 哈哈！想吃回头草？没门！");
		return 0;
	}

	if (ob->query("betrayer/times"))
	{
		command("say 我们丐帮虽然是叫花子，但是堂堂正正行路，不会收判师之徒的！");
		return 0;
	}

	if (ob->query("family/family_name") && ob->query("family/family_name") != "丐帮")
	{
		command("say 嘿！你既然已经有了名师指点，还来我们丐帮干什么？");
		return 0;
	}

	if ((int)ob->query_str() < 30)
	{
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
		return;
	}

	if (ob->query_skill("force") < 150)
	{
		command("say 你的内功火候还不行，先和别的师傅学习吧。");
		return;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) + "能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}

int recognize_apprentice(object me)
{
	if (me->query("family/family_name") != query("family/family_name"))
		return 0;

	if (me->query("beggarlvl") < 9)
		return 0;

	return 1;
}

void unconcious()
{
	die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
