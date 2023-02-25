// color.c (Simba 13.sept.97)

#include <ansi.h>

inherit F_CLEAN_UP;
//击杀蒙古兵，得兵符给郭靖，得秘籍不知道为什么npc用不了present，所以直接写成指令里，反正都一样能实现效果没bug就行
int main(object me,string arg)
{
     object obj;
     object a;
     if (! me->query("born"))
		return notify_fail("你还没有出生呐？\n");                 
        if (me->is_busy())
        return notify_fail("你正忙著呢。\n");
        if (me->is_fighting())
        return notify_fail("你现在正在战斗！\n"); 
        if (me->is_ghost()) 
        return notify_fail("等你还了阳再说吧。\n");                 
        if (me->is_in_prison())   
        return notify_fail("你正在做牢呢。\n");
        if( me->query("doing") )
        return notify_fail("你还想干什么？！\n");
     obj = present("nianshou jiao",me);
     if (!objectp(obj))
	 return notify_fail(HIY"你身上没有年兽角不能兑换爆竹！"NOR"\n");
	destruct(obj);
	a=new("/clone/shizhe/baozhu");
    a->move(me);
    a=new("/clone/shizhe/baozhu");
    a->move(me);
    a=new("/clone/shizhe/baozhu");
    a->move(me);
	write(HIY"你使用一个年兽角兑换了3个爆竹"NOR"\n");
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
