//jinu.c

inherit NPC;

#include <ansi.h>
#include "bajiao.h"

void create()
{
	set_name("妓女", ({ "ji nu" }) );
	set("gender", "女性" );
	set("age", 25);
	set("str", 10);
	set("per", 30);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
