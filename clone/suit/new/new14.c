// news_pants.c

#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
void create()
{
	set_name(HIG "新丁披风" NOR, ({"new"}));  
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件"+this_object()->query("name")+"，是东方使者特别为新人订做的。\n");
		set("armor_prop/armor", 50);  //防御	
		set("value", 10000);   //价值	 	
		/*
		set("suit",HIG"新丁套装"NOR);  
		set("suit_lvl",1);	    
		set("suit_count",14);	 
	      //套装各部件
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
	    set("suit_mod/surcoat","新丁披风");
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
	       
	       */
	}
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
