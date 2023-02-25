// huqingyu.c
#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("胡庆余",({ "hu qingyu","hu" }));
	set("gender", "男性" );
	set("age", 63);
	set("long",
"胡庆余是当世一大巫医，他的本事神奇无比。真有生死肉骨之功。\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	setup();
}
void init()
{
	object ob,me;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
