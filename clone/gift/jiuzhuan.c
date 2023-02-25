// jiuzhuan.c 九转金丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "九转金丹" NOR, ({ "jiuzhuan jindan", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一颗金色的仙丹，传说是太上老君"
			    "精心修炼的灵丹妙药。\n");
		set("value", 1500000);
		set("unit", "颗");
		set("no_give",1);
		set("no_drop",1);
		set("no_get",1);
            set("no_sell",1);
		set("only_do_effect", 1);
		set("suit_point",300);
	}
}

int do_effect(object me)
{
	int effect;
	 mapping my;

	////log_files("static/using", sprintf("%s(%s) eat 九转金丹 at %s.\n",
		// me->name(1), me->query("id"), ctime(time())));

	effect = 0;
	message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
		       "。\n", me);
	if (me->query("gift/xiandan") < 4 && random(2))
	{
		effect++;
		write(HIM "你觉得自己的头脑更清醒了。"NOR"\n");
		me->add("gift/xiandan", 1);
		me->add("int", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用九转金丹成功，《先天悟性》增加了！！！"NOR"\n");
	}

	if (me->query("gift/unknowdan") < 4 && random(2))
	{
		effect++;
		write(HIR "你觉得自己的腿脚更灵活了。"NOR"\n");
		me->add("gift/unknowdan", 1);
		me->add("dex", 1);
		 write("\n "+HIR+"恭喜你："+NOR+HIG+"服用九转金丹成功，《先天身法》增加了！！！"NOR"\n");
	}

	if (me->query("gift/xisuidan") < 4 && random(2) &&
	    me->query("gender") != "无性")
	{
		effect++;
		write(HIC "你觉得自己的内息更通畅了。"NOR"\n");
		me->add("gift/xisuidan", 1);
		me->add("con", 1);
		 write("\n "+HIR+"恭喜你："+NOR+HIG+"服用九转金丹成功，《先天体质》增加了！！！"NOR"\n");
	}

	if (me->query("gift/shenliwan") < 4 && random(2))
	{
		effect++;
		write(HIG "你觉得自己的膂力更强健了。"NOR"\n");
		me->add("gift/shenliwan", 1);
		me->add("str", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用九转金丹成功，《先天臂力》增加了！！！"NOR"\n");
	}
	write(HIM "冥冥中你有所感悟。只觉得灵台一片空明，纯净无比。"NOR"\n");
	me->add("magic_points", 1000 + random(1000));
	 my = me->query_entire_dbase();
	my["eff_jing"] = my["max_jing"];
	my["jing"] = my["max_jing"];
	my["eff_qi"] = my["max_qi"];
	my["qi"] = my["max_qi"];
	if (my["jingli"] < my["max_jingli"])
		my["jingli"] = my["max_jingli"];
	if (my["neili"] < my["max_neili"])
		my["neili"] = my["max_neili"];
	 write(HIY "一阵畅快之后，你觉得浑身是劲！"NOR"\n");
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
