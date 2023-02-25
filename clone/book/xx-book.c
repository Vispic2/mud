// xx-book.c

inherit ITEM;

void create()
{
	set_name("拓本", ({ "ta ben" , "book"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张很普通的纸，上面抄录了一些口诀，似乎是一"
			    "种叫做吸星大法\n的内功诀窍。\n");
		set("material", "paper");
		set("skill", ([
			"name"	:  "xixing-dafa",
			"exp_required":  100000,
			"jing_cost"   :  70,
			"difficulty"  :  45,
			"max_skill"   :  200,
		]));
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
