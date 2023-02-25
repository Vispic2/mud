// jiyin3.c

inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
	set_name("「九阴真经」残本", ({ "jiuyin zhenjing3" }));
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一本手抄本，上面记录了一些武功秘诀。\n");
		set("value", 0);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
			"name":	"force",
			"exp_required": 100000,
			"jing_cost" : 45,
			"difficulty": 30,
			"max_skill" : 149,
			"min_skill" : 100
		]) );
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
