// waiter.c

#include <ansi.h>;

inherit NPC;

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
	setup();
}

string accept_ask(object me, string topic)
{
	switch (random(3))
	{
	case 0:
		return "嗨！我忙着呢，你和我那醉仙楼做活的兄弟聊聊吧！";

	case 1:
		return "你干啥？没看我忙着呢么？";

	default:
	       return "我那醉仙楼做活的兄弟消息才叫灵通，你去和他聊吧。";
	}
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
	case 0:
		say( "店小二笑咪咪地说道：\n"
			"这位" + RANK_D->query_respect(ob) + "，进来喝杯茶，歇歇腿吧。\n");
		break;
	case 1:
		say( "店小二用脖子上的毛巾抹了抹手，说道：\n"
			"这位" + RANK_D->query_respect(ob) + "，请进请进。\n");
		break;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 1000) 
	{
		tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}
	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
