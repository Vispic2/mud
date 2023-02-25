// shaofanshifu.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("烧饭师傅", ({ "shaofan shifu", "shifu" }));
	set("str", 50);
	set("gender", "男性");
	set("age", 18);
	set("long", "他是聚义馆厨房的烧饭师傅。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
