//by admin 

#include <ansi.h>
inherit ROOM;
int do_look(string arg);
void create()
{
	set("short","未明谷");

		set("exits", ([
		"west" : __DIR__"shulin1",
			"east" : __DIR__"shulin2",
				"south" : __DIR__"qingshi",
	]));
	set("objects", ([
	"/d/newtt/obj/hulu" :1,
	"/d/newtt/obj/yeguo" :1,
	"/d/newtt/obj/wizard" :1,
	]));
		set("action_list", ([
		//""HIM"新手指导"NOR :"newzhidao",
		""HIR"洗心池"NOR"" :"zs",
	]));
	set("item_desc", ([
		"小溪" : ""HIY"这是一条清澈的小溪，也许你可以拿起地上的葫芦，或者找指导师要，研究下用来盛溪水喝。"NOR"\n",		
		"山坡" : ""HIY"这是一段陡峭的山坡，应该可以向上攀爬出去。\n"
		ZJOBACTS2"爬出去:enter\n",
	]));
	set("long","山谷中绿树成荫，却不见有多么明媚的花开于此，但你仍然能闻见远远飘来的花香。耳边听到了溪水叮咚的声音，原来不远处有一条蜿蜒的小溪，岸边似乎散落这一些物品。在山谷的北侧有条陡峭的山坡隐隐约约可以通往外界！");
	setup();
}

void init()
{

	add_action("zhuanshi","zs");
	add_action("do_look","enter");
//	add_action("o","get");
//	set_heart_beat(1);
}
/*
void o()
{
int d;
string n;
object obj;
object me=this_player();
object w=environment(me);
object *h=all_inventory(w);
foreach (n in h){
obj = present("hu lu",n);
if (!objectp(obj)){
d=new("/d/newtt/obj/hulu");
d->move(w);
}
obj = present("ye guo",n);
if (!objectp(obj)){
d=new("/d/newtt/obj/yeguo");
d->move(w);
    }
  }
 
}*/

/*
write(HIG"你来到陌生的地方，前途未卜，请先用命令检查身体状态，点击常用指令->健康状态。"NOR"\n");
  write(HIG"你现在又饿又渴，根据小溪的提示让自己吃饱喝足。"NOR"\n");
    write(HIG"去四周逛逛看看有没有别的出口，如果没有就回来。"NOR"\n");
       write(HIG"去洗心池，洗点跟洗天赋，然后就去爬山坡。"NOR"\n");
       */
int zhuanshi(object me)
{
me=this_player();
if(!me->query("jkzt"))
return notify_fail("你来到陌生的地方，前途未卜，请先用命令检查身体状态，点击常用指令->健康状态。\n");
if(!me->query("heshui"))
return notify_fail("你现在又饿又渴，根据小溪的提示让自己吃饱喝足。\n");
if(!me->query("shulin1"))
return notify_fail("去四周逛逛看看有没有别的出口，如果没有就回来。\n");
if(!me->query("shulin2"))
return notify_fail("去四周逛逛看看有没有别的出口，如果没有就回来。\n");
if(!me->query("shulin3"))
return notify_fail("去四周逛逛看看有没有别的出口，如果没有就回来。\n");
me->move("/d/newtt/new1");
me->start_busy(1);
//write("你来到了！\n");
return 1;
}


int do_look(string arg)
{
	object me = this_player(), inv;
//	inv = present("kuihua baodian", me);
if (! objectp(me))
		return;
	
		if (! me->query("newxidian"))
		return notify_fail("先去洗心池，洗点再来！\n");
if (! me->query("newtianfu"))
		return notify_fail("先去洗心池，选好天赋再来！\n");
		if (! me->query("tianxings"))
		return notify_fail("先去洗心池，选好天性再来！\n");
		//	message_vision(HIR"你用力的向上爬着。"NOR"\n");
		write(HIR"你用力的向上爬着。"NOR"\n");
			//remove_call_out("do_talk1");
			call_out("do_talk1", 1, me);			
			return 1;			 
}

void do_talk1(object me)
{
	if (! objectp(me))
		return;

	write(HIR"你用力的向上爬着。"NOR"\n");
//	remove_call_out("do_talk2");
	call_out("do_talk2", 1, me);
}

void do_talk2(object me)
{
	if (! objectp(me))
		return;

	

	write(HIR"你用力的向上爬着。"NOR"\n");
//	remove_call_out("do_talk20");
	call_out("do_talk20", 1, me);
}


void do_talk20(object me)
{
	object book;
	
//me=this_player();
	if (! objectp(me))
		return;
	write(HIR"你来到了缓坡。"NOR"\n");
	
	if(me->query("huanpo") < 1)
	{
	    me->add("combat_exp",1000);
    	me->add("potential",1000);
    	me->set("huanpo",1);
	    write(HIC"干的不错，你被奖励了一千点经验，1千点潜能！"NOR"\n");
	    }
	    
	me->move("/d/newtt/huanpo");
}



int valid_leave(object me, string dir)
{

	if (! me->query("registered"))
	{
		me->set("registered",1);
	}
	if (dir == "west" &&me->query("heshui")<1|| dir == "south"&&me->query("heshui")<1||dir == "east" && me->query("heshui")<1)
	return notify_fail(HIY"请跟随新手指导的提示！"NOR"\n");
	
	return ::valid_leave(me, dir);
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
