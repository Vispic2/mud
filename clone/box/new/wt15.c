// huwan.c 护腕

#include <ansi.h>
#include <armor.h>

inherit WRISTS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});   
void create()
{
	set_name( (order[random(13)])+"登龙护腕"NOR, ({ "wrists15"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		
		set("value", 2800);
		set("material", "cloth");
		set("armor_prop/armor", 69);
set("armor_prop/strength",17);
set("armor_prop/damage", 15);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
