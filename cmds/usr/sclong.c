// by name 2021.4.19
//QQ：3468713544
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
    string cishu;
    object sc;
    if(!arg)
    {    
    if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
	if(!(sc=present(me->query("id")+" sc",environment(me))))
	return notify_fail("你的随从不在你跟前，无法改介绍！\n");
    return notify_fail(INPUTTXT("请输入随从描述", "sclong $txt#") + "\n");	
    }
    if(!me->query("scs"))
    return notify_fail("你还没有随从呢！\n");
    if (me->query("balance") < 100000)
	return notify_fail("你钱庄存款不足，不能进行修改描述，需要10量黄金！\n");
    if(!(sc=present(me->query("id")+" sc",environment(me))))
	return notify_fail("你的随从不在你跟前，无法改介绍！\n");
    if (sscanf(arg,"%s",cishu) != 1)     
	return 1;	
    sc->set("long",cishu);
    me->add("balance",-100000);
    write(HIC"更改随从描述完成，扣除你钱庄10量黄金。\n"NOR);
	
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
