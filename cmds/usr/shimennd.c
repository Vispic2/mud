

#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
mapping q;
	if(mapp(q =  me->query("quest"))){
	write(HIR"你目前有任务在身，请先取消任务或者结束任务后再切换难度！"NOR"\n");
	return 1;
	}
	if(!arg)
	{	
		write(ZJOBLONG + HIW+ZJSIZE(25)+"当前师门难度："+HIM+(me->query("shimen/nan")?me->query("shimen/nan"):""HIM"初级")+NOR+ZJBR+ZJSIZE(25)+HIW+"请选择师门任务的难度"NOR"\n"+ ZJOBACTS2+ZJMENUF(3,3,9,31) + ""+HIG+"初级难度:shimennd chu"ZJSEP""+HIM+"中级难度:shimennd zhong"ZJSEP""+HIR+"高级难度:shimennd gao\n"NOR);
		return 1;	
	}
	
	if(arg=="gao")
	{
	me->set("shimen/gaoji",1);
	me->set("shimen/nan","高级");
	me->set("shimen/zhongji",0);
	write(HIR"开启高级师门难度成功，请小心行事！"NOR"\n");		
	}else
		if(arg=="zhong")
	{
	me->set("shimen/zhongji",1);
	me->set("shimen/gaoji",0);
	me->set("shimen/nan","中级");
	write(HIM"开启中级师门难度成功，请小心行事！"NOR"\n");		
	}else
	if(arg=="chu")
	{
	me->set("shimen/zhongji",0);
	me->set("shimen/gaoji",0);
	me->set("shimen/nan","初级");
	write(HIG"开启初级师门难度成功，请小心行事！"NOR"\n");		
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : shimennd  这个指令可以用来向你的门派的掌门或世家长辈
领取任务，如果不加任何参数则显示出你当前的任务。
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
