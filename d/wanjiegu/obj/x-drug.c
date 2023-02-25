// x-drug.c

inherit ITEM;

void create()
{
	set_name("阴阳合和散", ({ "x-drug" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一种强烈的春药。\n");
		set("unit", "包");
		set("value", 0);
	}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
