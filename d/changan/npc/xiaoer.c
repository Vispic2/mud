//xiaoer.c

inherit KNOWER;

void create()
{
	set_name("店小二", ({"xiaoer","xiaoer","xiao","waiter","er"}));
	set("shop_id",({"waiter","xiaoer","xiao","er"}));
	set("shop_title","店小二");
	set("gender", "男性");
	set("combat_exp", 2000);
	set("age", 21);
	set("per", 23);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("unarmed", 10);
	setup();
	carry_object(__DIR__"obj/linen")->wear();
	add_money("silver", 1);

}

void greeting(object ob)
{
	if (! ob || ! visible(ob) || environment(ob) != environment())
		return;
	say(name() + "笑咪咪地说道：这位" + RANK_D->query_respect(ob) +
	    "，进来歇歇脚，休息一下吧。\n");
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 300)
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
		who->set_temp("rent_paid", 1);
		return 1;
	}
	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
