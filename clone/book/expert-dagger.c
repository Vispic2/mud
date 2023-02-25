// expert_dagger.c

inherit ITEM;

void create()
{
	set_name("短兵秘要", ({ "dagger book", "book" }));
	set_weight(600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"封面上写著「短兵秘要）」\n");
		set("value", 50000);
		set("material", "paper");
		set("skill", ([
			"name": 	"dagger",
			"exp_required":	1000,
			"jing_cost":	50,
			"difficulty":	30,
			"max_skill":    99,
			"min_skill":    50,
		]));
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
