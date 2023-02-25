// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "轮回丹" NOR, ({ "lunhui dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一暗红的丹药，使用后可以从新拜师学艺，并且不清除技能。"+HIR+"注意：使用后经验掉到500万，武学修养掉到180级。\n"NOR);
		set("unit", "粒");
		set("value", 20000);
		set("yuanbao", 800);
	    set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一粒"+this_object()->query("name")+""HIM"，获得了一次重新选择师门的机会！");
	me->delete("family");
	me->delete("title");
	me->delete("class");
me->delete("quest");
		me->set("combat_exp",5000000);
		me->set_skill("martial-cognize",180);		
		
	me->add("lunhui",1);	
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
