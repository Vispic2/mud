// xiaoer2.c 酒店小二

inherit KNOWER;
inherit F_DEALER;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("no_get", "1");
	set("vendor_goods", ({
		__DIR__"obj/pork",
		__DIR__"obj/fish",
		__DIR__"obj/baozi",
		__DIR__"obj/shrimp",
		__DIR__"obj/chicken",
		__DIR__"obj/geng",
		__DIR__"obj/jiuping",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
