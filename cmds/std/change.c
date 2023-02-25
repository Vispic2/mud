// whistle.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string file;

	if (! arg)
		return notify_fail("你要铠化什么？\n");
			
	if (me->is_busy() || me->query("doing"))  
		return notify_fail("你现在正忙呢，等你有空了再说吧。\n");
 
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢，你想干什么？！\n"); 
			       
	if (me->is_ghost())
		return notify_fail("等你还了阳再召唤吧。\n");

	if (! stringp(file = me->query("can_whistle/" + arg)))
		return notify_fail("你不知道如何召唤这个魔幻兽。\n");
	if (environment(me)->query("no_magic") || environment(me)->query("no_fly")) 
		return notify_fail("你发现这里有点古怪，你的魔幻兽好象不能进来！\n");    
	
	if (file_size(file + ".c") < 0)
		return notify_fail("你不知道如何召唤这个魔幻兽。\n");

	if (! objectp(ob = present(arg, environment(me))))
			return notify_fail("你得首先把你的魔幻兽召唤到身旁来。\n");
		
		if (ob->query("owner") != me->query("id"))
			return notify_fail("你的魔幻兽并不在你的身旁。\n");
				
		if (! living(ob)) return notify_fail("你的魔幻兽目前处于昏迷状态呢。\n");

		message_vision("$N举起右手在面前极速画了一个圆，大喊"
			"一声，“$n，铠化！”\n", me, ob);
		
		if (! ob->receive_change(me))
		{
			message_vision("然而什么也没有发生 :)\n", me);			
			return 1;
		} 
		
	}
	
int help(object me)
{
	write(@HELP
指令格式 : whistle <魔幻兽ID>

此指令可让你把你的魔幻兽呼唤过来，当然你得有一定的精力施展才行。
HELP );
	return 1;
}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
