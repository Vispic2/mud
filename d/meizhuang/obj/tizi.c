// tizi.c
inherit ITEM;
void setup()
{}

void init()
{
	add_action("do_climb", "climb");
}

void create()
{
	set_name("梯子", ({"ti zi", "ti"}));
	set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一架长梯，靠在书架的旁边，时常用来"ZJURL("cmds:climb ti zi")+ZJSIZE(15)"爬"NOR"上去拿书架高层的书籍。\n");
		set("unit", "架");
		set("material", "wood");
	}
	setup();
}

int do_climb(string arg)
{
	object me = this_player();
	if (!id(arg))
		return notify_fail("你要往哪儿爬？\n");
	if (this_player()->query_temp("marks/跳1") ) {
		       write("你怎么爬个没完没了？\n");
			return 1;
	}
	else {
	       message("vision",this_player()->name() + "爬上梯子。\n",environment(me), ({me}) );
	       write("你爬上梯子。\n");
		this_player()->set_temp("marks/跳1", 1);
	return 1;
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
