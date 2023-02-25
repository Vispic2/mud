#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(CYN "倚天剑" NOR, ({ "yitian sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", HIY "这便与天下至尊的屠龙宝刀并称的倚天剑。\n相传让刀剑对砍(duikan)可以得到旷世的武林秘籍。"NOR"\n");
		set("no_sell", "这样东西不能卖。\n");
		set("no_give", 1);
		set("no_put", 1);
		set("rigidity",8000);   
		 set("icon","05060");   
		set("material", "steel");
		set("wield_msg", HIW "只听“嗖”的一声破空声响，号称天下第一神兵的倚天剑已被$N握在手中。"NOR"\n");
		set("unwield_msg", HIW "$N将倚天剑插回腰间，天地又渐渐放出光芒。"NOR"\n");
	}
	init_sword(210);
	setup();
}
void init()
{
	object me = this_player();

	if (!query("clone") && me)
	{
		CHANNEL_D->do_channel( this_object(), "rumor",sprintf("听说%s获得了武林至宝%s！", me->name(1), this_object()->name()));
		set("clone", time());
		call_out("move_ob2", 7200);
	}
}
void move_ob2()
{
	object ob;
	object me;
	
	me = environment();
	if (! objectp(me))
		return;

	while (objectp(environment(me)) && ! playerp(me))
		me = environment(me);
		
	if (playerp(me)) {
		if (me->is_fighting())
		{
			call_out("move_ob1", 3);
			return;
		}
		if (ob = present("yitian sword", me)) {
			message_vision("只见$n化作一道光芒，从$N身上飞出，倏忽不见了！\n", me, ob);
			CHANNEL_D->do_channel( this_object(), "rumor",sprintf("听说武林至宝%s从%s身上消失了！", ob->name(), me->name(1)));
		}
	}
	destruct(ob);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	dam = (int) me->query("dex");
	victim->add("neili", -dam * 10);

	if (victim->query("neili") < 0) 
	victim->set("neili", 0); 

	return HIW "倚天剑携着飕飕刺骨风声，直直刺向$n，$n只感到全身的内力竟一丝丝随着剑锋涌出。"NOR"\n";
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
