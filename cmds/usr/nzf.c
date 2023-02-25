//by 俗尘
/*练体境，突破要求。一万内力。加成：内极限加一半。
练气境，突破要求，五千精。加成：精极限加一半。
筑基境，突破要求，一万五内力，七千五精。加成：内精翻倍
金丹境，突破要求，三万内，武学500级。加成：先天全属性加十点。
元婴境，突破要求，内力五万。突破后内力全失去。加成：内力极限翻倍。
合体境，突破要求，击杀心魔直接突破。加成：血量提升一万。
渡劫境，突破要求，内力十万，精力两万。加成：先天全属性加二十。
人仙境，突破要求，进入渡劫谷遭雷劈。加成：内力转法力比例1：1000。
*/

//建议不要弄什么修仙
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{  string str;
     if(!arg)
	{
		str = ZJOBLONG"内转法系统：\n";
		str += ZJOBACTS2+ZJMENUF(1,1,8,28);
		str +=
		HIG"内力转法力(1000：10固定)"NOR":nzf 1000"ZJSEP	
                                  HIG"法力转内力(10：800固定)"NOR":nzf -1000"ZJSEP	
		HIR"返回"NOR":look";		
		message("vision", str+"\n", me);
	}else
	 if(arg=="1000") 
	{	  
    if (me->query("rx") < 1)
	return notify_fail(HIR"你还没有突破人仙境不能内转法！\n"NOR);	
    if (me->query("max_neili") < 1000)
	return notify_fail(HIR"你的内力不足1000不能内转法！\n"NOR);	
	me->add("max_fali",10);
	me->add("max_neili",-1000);
	write(HIY"恭喜置换成功！当前内力：["+me->query("max_neili")+"]点，当前法力：["+me->query("max_fali")+"]点。\n"NOR);
    }
   else
	 if(arg=="-1000")
	{
	if (me->query("rx") < 1)
	return notify_fail(HIR"你还没有突破人仙境不能法转内！\n"NOR);	
    if (me->query("max_fali") < 10)
	return notify_fail(HIR"你的法力不足10不能法转内！\n"NOR);	
	me->add("max_neili",800);
	me->add("max_fali",-10);
    write(HIY"恭喜置换成功！当前内力：["+me->query("max_neili")+"]点，当前法力：["+me->query("max_fali")+"]点。\n"NOR);
   }
	return 1;
}

int help(object me)
{
	write(@HELP
内转法指令格式 : nzf 1000是内力转法力比例1000比10。
法转内指令格式 : nzf -1000是法力转内力比例10比800。
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
