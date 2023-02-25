// shield.c 牛皮盾
#include <ansi.h>   
#include <armor.h>
 
inherit SHIELD;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	set_name((order[random(13)])+"阴蛇之盾"NOR, ({ "shield8"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "面");
		set("value", 1700);
		set("armor_prop/armor", 64);
		set("armor_prop/defense", 17);
set("armor_prop/strength",3);
	}
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
