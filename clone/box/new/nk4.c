
#include <ansi.h>  
#include <armor.h>

inherit NECK;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"冬雨项链"NOR, ({ "necklace4"}));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("value", 2700);
		set("material", "gold");
		set("armor_prop/armor", 66);
set("armor_prop/constitution",12);
set("armor_prop/karay",13);
	}
	setup();
}	

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
