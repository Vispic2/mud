// recover cmds
// updated by doing
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	mapping my;
 
string file;
int fulls;
	seteuid(getuid(me));
 
	if (! arg)
		ob = me;
	else
	{
		ob = present(arg, environment(me));
		if (! ob) ob = find_player(arg);
		if (! ob) ob = find_living(arg);
	}

//	if (me->query("can_whistle/"+arg)) 
 //   if(!arg&&me->query("can_whistle/"+arg))
//	return notify_fail("你要恢复谁的状态？\n");
 if(time()<me->query("fulls")+300)
 return notify_fail("5分钟才可以恢复一次幻兽状态。\n");
		if (! stringp(file = me->query("can_whistle/" + arg)))
		return notify_fail("你没有这只幻兽。\n");

	if (file_size(file + ".c") < 0)
		return notify_fail("你没有这只幻兽。\n");
	
	my = ob->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+ob->query_gain_qi();
	my["neili"]  = my["max_neili"];
		my["fali"]  = my["max_fali"];
	//my["food"]   = ob->max_food_capacity();
//	my["water"]  = ob->max_water_capacity();

	message_vision(HIY "$N" HIY "伸手一指，$n" HIY "立刻精神焕发，神采奕奕。"NOR"\n",me, ob);
		if (! living(ob))
		 ob->revive();
		if (ob->is_ghost())
		 ob->reincarnate();
		ob->clear_condition();
   me->set("fulls",time());
	return 1;
}
 
int help()
{
	write(@HELP
指令格式 : recover <对象名称>
 
这个指令可以恢复你(你)或指定对象(含怪物)的精, 气, 内力等数值。
 
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
