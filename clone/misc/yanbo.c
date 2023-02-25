// yanbo.c 研钵

inherit ITEM;

void create()
{
	set_name("研钵", ({ "yan bo", "bo" }));
	set_weight(600);
	set_max_encumbrance(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只沉甸甸的瓷碗，可以用来磨药。\n");
		set("value", 200);
	}
}

int is_container() { return 1; }

int can_make_medicine() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
