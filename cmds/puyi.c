// 仆役
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("仆役", ({ "pu yi"}));
	set("gender", "男性");
	set("long", "这是一个可怜巴巴仆役。\n");
    set("str", 10);
	set("dex", 10);
	set("int", 10);
	set("con", 10);
	set("shen",10);	
	set("puyi",1);
	set("combat_exp", 10);
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
