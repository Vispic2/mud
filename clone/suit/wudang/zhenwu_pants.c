// zhenwu_pants.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

string do_wear();

void create()
{
	set_name(HIR "⑤真武裙甲" NOR, ({"zhenwu pants"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是神器级[真武除邪]的护腿\n");
		set("material", "pants");    //类型
		set("armor_prop/armor", 40);  //防御
		set("armor_prop/warm", 1);   //保暖   地狱中的，这个没有用
		set("value", 10000000);   //价值
		set("material", "crimson gold");  //原料
		set("wear_msg", (: do_wear :));  //装备信息
		set("icon","05083");
		  set("suit_point",500);
	//---------------------------------------------------------------
	      //套装参数
		 set("suit",HIR"真武除邪"NOR);  //套装名称
		set("suit_lvl",5);	     //套装等级
		set("suit_count",6);	   //套装部件数量
	      //套装各部件
		set("suit_mod/arrmor","真武法袍");
		set("suit_mod/finger","真武戒指");
		set("suit_mod/sword","真武除邪剑");
		set("suit_mod/hands","真武手套");
		set("suit_mod/head","真武头冠");
		set("suit_mod/neck","真武护符");
		set("suit_mod/pants","真武裙甲");			     
	    //套装全部附加天赋效果  //身法第一，根骨第二，悟性，臂力
		set("suit_eff/dex",3);      //两件
		set("suit_eff/con",4);      // 五件 
		set("suit_eff/int",5);      //三件  
		set("suit_eff/str",6);      //    一套  
	       //套装全部附加技能效果   
		set("suit_eff_skill/taiji-jian",10);   //一套
		set("suit_eff_skill/taiji-quan",10); 
		set("suit_eff_skill/taoism",10);	   
       //---------------------------------------------------------------
	}
	setup();
}

string do_wear()
{
	object me;
	string msg;
	int per;

	me = this_player();
	per = me->query("per");
	if (me->query("gender") == "女性")
	{
		if (per >= 30)
			msg = HIC "$N" HIC "轻轻将一件$n" HIC "绑在腰上，神态曼妙之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，绑在腰上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "绑在腰上，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "绑在腰上。\n";
	} else
	{
		if (per >= 30)
			msg = HIC "$N" HIC "随手一挥，将$n" HIC "绑在腰上，姿势潇洒之极。\n";
		else if (per >= 25)
			msg = HIG "$N" HIG "把$n" HIG "展开，绑在腰上。\n";
		else if (per >= 20)
			msg = YEL "$N" YEL "把$n" YEL "绑在腰上，扯了扯衣角，缩了缩脖子。\n";
		else    msg = YEL "$N" YEL "毛手毛脚的把$n" YEL "绑在腰上，甚是猥琐。\n";
	}
	return msg;
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
