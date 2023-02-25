// ylbian.c

inherit ITEM;

void create()
{
	set_name(CYN"降龙十八掌秘籍"NOR, ({ "xianglong book", "book" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本降龙十八掌秘籍。\n");
		set("value", 5000); 
		 set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
		set("material", "paper");
		set("skill", ([
			"name": "dragon-strike",  //name of the skill
			"jing_cost": 50,// jing cost every time study this			
			"max_skill":	180,	// the maximum level you can learn你能学到的最高水平
			
		]) );
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
