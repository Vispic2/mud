// cubupao.c

inherit EQUIP;

void create()
{
    set_name("粗布袍", ({ "cu bupao","bupao", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("armor_type", "cloth");
	set("value", 100);
	set("armor_prop/dodge", 1);
		set("armor_prop/armor", 1);
	}
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
