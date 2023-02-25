// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;
//修改宠物描述
int main(object me,string arg)
{
    string cishu;
    object pet;
    if(!arg)
    {    
    if(!me->query("pets"))
    return notify_fail("你还没有宠物呢！\n");
	if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("你的宠物不在你跟前，无法改介绍！\n");
    return notify_fail(INPUTTXT("请输入", "petlong $txt#") + "\n");	
    }
    if(!me->query("pets"))
    return notify_fail("你还没有宠物呢！\n");
    if (me->query("balance") < 100000)
	return notify_fail("你钱庄存款不足，不能进行修改描述，需要10量黄金！\n");
    if(!(pet=present(me->query("id")+" pet",environment(me))))
	return notify_fail("你的宠物不在你跟前，无法改介绍！\n");
    if (sscanf(arg,"%s",cishu) != 1)     
	return 1;	
    pet->set("long",cishu);
    me->add("balance",-100000);
    write(HIC"更改完成\n"NOR);
	
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
