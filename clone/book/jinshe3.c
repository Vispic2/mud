// jinshe3.c 

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>;

void setup()
{}

void create()
{
	set_name(YEL"「金蛇秘芨」"NOR"下册", ({ "jinshe book3","book3", }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("material", "paper");
		set("long",
	"这是一本用薄纸写成的书。上书：「金蛇秘芨」。\n"
	"书皮泛黄，看来已经保存很久了。\n", );
		set("skill", ([
			"name"	: "jinshe-zhang",
			"exp_required":	100000,
			"jing_cost"   :	50,
			"difficulty"  :	35,
			"max_skill"   : 119,
		]));
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
