// letter.c 回执

inherit ITEM;

int is_letter() { return 1; }

void create()
{
	set_name("信件", ({ "letter" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一封信！\n");
		set("value", 0);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
