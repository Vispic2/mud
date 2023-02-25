// whistle.c
//解除幻兽铠化 by寒江雪
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string file;
if (!arg)
	return notify_fail("你要解除什么o。\n");
		if (environment(me)->query("no_magic") || environment(me)->query("no_fly")) 
		return notify_fail("你发现这里有点古怪，你的魔幻兽好象不能进来！\n");    
		if (me->is_in_prison())   
		return notify_fail("你正在做牢呢，你想干什么？！\n"); 
			       
	if (me->is_ghost())
		return notify_fail("等你还了阳再召唤吧。\n");
	 if (! objectp(ob = present(arg, me)))
			return notify_fail("你身上并没有任何铠化的魔幻兽o。\n");
				       
		if (ob != me->query_temp("is_changing"))
			return notify_fail("你身上并没有任何铠化的魔幻兽。\n");  

		if (ob->query("owner") != me->query("id"))
			return notify_fail("你身上并没有任何铠化的魔幻兽。\n");
					
		if (! living(ob)) return notify_fail("你的魔幻兽目前处于昏迷状态呢。\n");

		message_vision("$N集中心智，在心中慢慢的呼道：“$n，解除铠化。”\n", me, ob);
		
		if (! ob->receive_recover(me))
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
