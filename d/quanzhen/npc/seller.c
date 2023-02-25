// seller.c

inherit KNOWER;
inherit F_VENDOR;

string ask_me();

void create()
{
	set_name("小贩", ({ "seller" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"这是个小贩，别看他长的老老实实，可你别想从他那儿掏便宜。\n");
	set("combat_exp", 300);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/stick",
		__DIR__"obj/bottle",
		__DIR__"obj/egg",
		"/d/xingxiu/obj/fire",
	}) );
	set("inquiry", ([
		"药" : (: ask_me :),
		"药材" : (: ask_me :),
	]) );
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy", "buy");
}

string ask_me()
{
	object me = this_player();

	if (me->query_temp("tmark/药") != 0)
		return "我走南闯北，没见过你这么罗嗦的人！\n";

	me->set_temp("tmark/药", 1);
	return "当年我到极北森林中采药，还真遇到了一些好药材，要买得先交钱。\n";
}

int accept_object(object who, object ob)
{
	object obj;

	if ((ob->query("money_id")) && (ob->value() >= 10000) &&
	    who->query_temp("tmark/药"))
	{
		obj = new("/d/guanwai/obj/shouwu");
		obj->move(who, 1);
		who->set_temp("tmark/药", 0);
		write("小贩说道：“既然您出得起价钱，这味药可就归您了。”\n");
		return 1;
	}
	else
	{
		if (ob->query("money_id"))
		{
			write("小贩阴笑一声，说道：“嘿嘿，给我这么多钱哪。”\n");
			return 1;
		}
		else
			return notify_fail("小贩诧异地说道：“给我这个干什么？”\n");
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
