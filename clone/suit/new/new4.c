// new_sowrd.c

#include <armor.h>
inherit HANDS;
void create()
{
	set_name(HIG "新丁拳套" NOR, ({ "new"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄精工制成的"+this_object()->query("name")+"，是东方使者特别为新手定做的!\n");
		set("value", 10000);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
		set("armor_prop/unarmed_damage", 80);   
	//    set("armor_prop/damage", 80);     	
	     
		set("suit",HIG"新丁套装"NOR); 
		set("suit_lvl",5);	    
		set("suit_count",12);	  
		
	    set("armor_prop/unarmed_damage", 80);   
	    set("armor_prop/damage", 80);     	  
	  //      set("suit_mod/surcoat","新丁披风");	
		set("suit_mod/cloth","新丁长衫");
		set("suit_mod/boots","新丁快靴");
		set("suit_mod/pants","新丁长裤");
		set("suit_mod/sword","新丁长剑");
		set("suit_mod/blade","新丁大刀");
		set("suit_mod/head","新丁头盔");	
		set("suit_mod/armor","新丁战甲");    
		set("suit_mod/waist","新丁腰带");  	
		set("suit_mod/wrists","新丁护腕");
		set("suit_mod/finger","新丁戒指");
		set("suit_mod/shield","新丁盾牌");
	    set("suit_mod/hands","新丁拳套");	
    set("suit_mod/neck","新丁护颈");

	       set("suit_eff_skill/hammer",66);
	       set("suit_eff_skill/club",66);
	       set("suit_eff_skill/parry",66);
	       set("suit_eff_skill/whip",66);
	       set("suit_eff_skill/staff",66);
	       set("suit_eff_skill/hand",66);
	       set("suit_eff_skill/unarmed",66);
	       set("suit_eff_skill/force",66);
		   set("suit_eff_skill/dodge",66);   
	       set("suit_eff_skill/sword",66);
	       set("suit_eff_skill/blade",66);
	       set("suit_eff_skill/cuff",66);
	       set("suit_eff_skill/strike",66);
	       set("suit_eff_skill/finger",66);
	       set("suit_eff_skill/claw",66);
	       
	}
//	init_hands(100); //伤害
	setup();
}
int query_autoload()
{
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
