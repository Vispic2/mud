// daodejing-i.c

inherit ITEM;

void create()
{
	set_name( "道德经「上卷」", ({ "jing", "daode jing" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册道德经「上卷」，由体道第一始至去用第四十止。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":    20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	49,	// the maximum level you can learn
		]) );
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
