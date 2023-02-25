#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("『星宿毒经〖下册〗』", ({ "du jing2", "book2" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "\n		 『星宿毒经〖下册〗』\n\n");
		set("value", 50);
		set("material", "paper");
		set("skill",
		([
			"name":	"poison",    // name of the skill
			"exp_required": 50000,      // minimum combat experience required
			"jing_cost":    20,	  // jing cost every time study this
			"difficulty":   25,	 // the base int to learn this skill
			"max_skill":    99,	// the maximum level you can learn
			"min_skill":    50,	 // minimun level required
		]) );
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
