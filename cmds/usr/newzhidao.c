// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
  
    
if(!me->query("jkzt"))
return notify_fail(HIG"你来到陌生的地方，前途未卜，请先用命令检查身体状态，点击常用指令->健康状态(hp1)。"NOR"\n");
if(!me->query("heshui"))
return notify_fail(HIG"你现在又饿又渴，根据小溪的提示让自己吃饱喝足。注：找新人指导NPC要也可以。\n");
if(!me->query("shulin1"))
return notify_fail(HIG"去四周逛逛看看有没有别的出口，如果没有就回来。\n");
if(!me->query("shulin2"))
return notify_fail(HIG"去四周逛逛看看有没有别的出口，如果没有就回来。\n");
if(!me->query("shulin3"))
return notify_fail(HIG"去四周逛逛看看有没有别的出口，如果没有就回来。\n");
if(!me->query("newxidian") ||!me->query("newtianfu"))
return notify_fail(HIG"去洗心池，洗点跟洗天赋，然后去爬山坡直到立刻未明谷为止。\n");
if(!me->query("lxsz"))
return notify_fail(HIG"拿着刻有""柳秀山庄""的葫芦去柳秀山庄一问究竟，注：到未明谷点击山坡爬上去。\n");
if(!me->query("youkun"))
return notify_fail(HIG"去找游鲲翼问葫芦。\n");
if(!me->query("youkuns"))
return notify_fail(HIG"去车马行雇车开始闯荡江湖。\n");
		
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
