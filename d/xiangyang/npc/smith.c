// smith.c

inherit "/inherit/char/smith.c";

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("title", "铁匠铺老板");
	set("shen_type", 1);
	set("icon","05011");
	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		   "/clone/weapon/changjian",
		   "/clone/weapon/hammer",
		   "/clone/weapon/tudao",
		   "/clone/weapon/dagger",
		   "/clone/weapon/tiegun",
		   "/clone/weapon/gangdao",
		   "/clone/cloth/tiejia",
	}));

	set("inquiry", ([
		"工作" : (: ask_me :),
		"job"  : (: ask_me :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
