// seller.c

inherit KNOWER;
inherit F_VENDOR;

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
		"/d/village/npc/obj/shoes",
		"/d/village/npc/obj/bottle",
	}));

	set("chat_msg_chance", 5);
	set("chat_msg", ({
		"小贩一边整理东西一边嘟囔：别看我平时不走动，消息知道得还不少。\n",
		"小贩四周看看，低声道：今天怎么这么太平？\n",
		"小贩打了个哈欠，看着你道：不瞒你说，太湖这些大大小小的事情我还知道一点。\n",
	}));

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
