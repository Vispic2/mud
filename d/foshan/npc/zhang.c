// zhang.c

inherit NPC;

void create()
{
	set_name("张朝唐", ({ "zhang chaotang", "zhang" }) );
	set("gender", "男性" );
	set("age", 22);
	set("int", 28);
	set("per", 23);
	set("long", 
"这是个饱读诗书的南洋书生，他一直向往中土文化，特来赶考。\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
