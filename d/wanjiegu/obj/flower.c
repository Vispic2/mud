// flower.c

inherit ITEM;

void create()
{
	set_name("绝情花", ({ "flower" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一朵散发着刺鼻味的野花。\n");
		set("unit", "一朵");
		set("value", 0);
	}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
