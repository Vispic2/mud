// shu-sheng.c

inherit NPC;

void create()
{
	set_name("书生", ({ "shu sheng", "sheng" }) );
	set("gender", "男性" );
	set("age", 22);
	set("int", 28);
	set("long",
		"这是个饱读诗书，却手无搏鸡之力的年轻书生。\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
