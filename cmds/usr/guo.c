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
     obj = present("bing fu",me);
     if (!objectp(obj))
	 return notify_fail("如果你能给我兵符我一定会重谢的！\n");
	 destruct(obj);
	 a=new("/clone/book/xianglong");
	 a->move(me);
	write("郭靖接过兵符喜出望外的说到:\n");
	write("谢谢这位小兄弟，以后你的事情就是我郭靖的事情，给这是一本秘籍送给你了！\n");
	write("恭喜获得了："+CYN+"降龙十八掌秘籍一本\n"NOR);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
