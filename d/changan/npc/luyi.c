//liuyi

inherit NPC;

#include <ansi.h>
#include "bajiao.h"

void create()
{
	set_name(HIG "绿衣" NOR, ({ "lu yi" }) );
	set("title", CYN "群玉八娇" NOR);
	set("gender", "女性" );
	set("age", 22);
	set("str", 30);
	set("per", 40);
	set("long", @LONG
一个全身上下穿着粉装，领露酥胸的美女．
LONG);
	set("combat_exp", 10);
	set("attitude", "friendly");

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
