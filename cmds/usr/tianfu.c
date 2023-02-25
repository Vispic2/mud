//by name 天赋进阶


#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
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
if(!arg)
return notify_fail("你想干啥？？？\n");
if(arg=="agile"){
if(me->query("yuanbao") < (1000+(me->query("tianfu/agile")*1000)))  
return notify_fail("你的元宝不够！至少需要："+(1000+(me->query("tianfu/agile")*1000))+"个！\n");
if(me->query("magic_points") < (100000+(me->query("tianfu/agile")*100000)))  
return notify_fail("你的灵慧不够！至少需要："+(100000+(me->query("tianfu/agile")*100000))+"点！\n");
if(me->query("zhuanshi") < (3*me->query("tianfu/agile")))
return notify_fail("你的转世次数不够！至少需要："+(3*me->query("tianfu/agile"))+"次！\n");
me->add("tianfu/agile",1);
write("进阶天赋成功，大幅度增加轻功激发，目前进阶本天赋次数："+me->query("tianfu/agile")+"次。\n");
}else
if(arg=="demon"){
if(me->query("yuanbao") < (1000+(me->query("tianfu/demon")*1000)))  
return notify_fail("你的元宝不够！至少需要："+(1000+(me->query("tianfu/demon")*1000))+"个！\n");
if(me->query("magic_points") < (100000+(me->query("tianfu/demon")*100000)))  
return notify_fail("你的灵慧不够！至少需要："+(100000+(me->query("tianfu/demon")*100000))+"点！\n");
if(me->query("zhuanshi") < (3*me->query("tianfu/demon")))
return notify_fail("你的转世次数不够！至少需要："+(3*me->query("tianfu/demon"))+"次！\n");
me->add("tianfu/demon",1);
write("进阶天赋成功，大幅度减少损害，目前进阶本天赋次数："+me->query("tianfu/demon")+"次。\n");
}else
if(arg=="hatred"){
if(me->query("yuanbao") < (1000+(me->query("tianfu/hatred")*1000)))  
return notify_fail("你的元宝不够！至少需要："+(1000+(me->query("tianfu/hatred")*1000))+"个！\n");
if(me->query("magic_points") < (100000+(me->query("tianfu/hatred")*100000)))  
return notify_fail("你的灵慧不够！至少需要："+(100000+(me->query("tianfu/hatred")*100000))+"点！\n");
if(me->query("zhuanshi") < (3*me->query("tianfu/hatred")))
return notify_fail("你的转世次数不够！至少需要："+(3*me->query("tianfu/hatred"))+"次！\n");
me->add("tianfu/hatred",1);
write("进阶天赋成功，大幅度增加伤害力，目前进阶本天赋次数："+me->query("tianfu/hatred")+"次。\n");
}else
if(arg=="jin"){
if(me->query("yuanbao") < (1000+(me->query("tianfu/jin")*1000)))  
return notify_fail("你的元宝不够！至少需要："+(1000+(me->query("tianfu/jin")*1000))+"个！\n");
if(me->query("magic_points") < (100000+(me->query("tianfu/jin")*100000)))  
return notify_fail("你的灵慧不够！至少需要："+(100000+(me->query("tianfu/jin")*100000))+"点！\n");
if(me->query("zhuanshi") < (3*me->query("tianfu/jin")))
return notify_fail("你的转世次数不够！至少需要："+(3*me->query("tianfu/jin"))+"次！\n");
me->add("tianfu/jin",1);
write("进阶天赋成功，大幅度增加防御力，目前进阶本天赋次数："+me->query("tianfu/jin")+"次。\n");
}else
if(arg=="paishan"){
if(me->query("yuanbao") < (1000+(me->query("tianfu/paishan")*1000)))  
return notify_fail("你的元宝不够！至少需要："+(1000+(me->query("tianfu/paishan")*1000))+"个！\n");
if(me->query("magic_points") < (100000+(me->query("tianfu/paishan")*100000)))  
return notify_fail("你的灵慧不够！至少需要："+(100000+(me->query("tianfu/paishan")*100000))+"点！\n");
if(me->query("zhuanshi") < (3*me->query("tianfu/paishan")))
return notify_fail("你的转世次数不够！至少需要："+(3*me->query("tianfu/paishan"))+"次！\n");
me->add("tianfu/paishan",1);
write("进阶天赋成功，大幅度增加空手伤害，目前进阶本天赋次数："+me->query("tianfu/paishan")+"次。\n");
}else
if(arg=="self"){
if(me->query("yuanbao") < (1000+(me->query("tianfu/self")*1000)))  
return notify_fail("你的元宝不够！至少需要："+(1000+(me->query("tianfu/self")*1000))+"个！\n");
if(me->query("magic_points") < (100000+(me->query("tianfu/self")*100000)))  
return notify_fail("你的灵慧不够！至少需要："+(100000+(me->query("tianfu/self")*100000))+"点！\n");
if(me->query("zhuanshi") < (3*me->query("tianfu/self")))
return notify_fail("你的转世次数不够！至少需要："+(3*me->query("tianfu/self"))+"次！\n");
me->add("tianfu/self",1);
write("进阶天赋成功，进阶次数大于3次可以在战斗中释放，并且增加恢复气血，目前进阶本天赋次数："+me->query("tianfu/self")+"次。\n");
}else{

write("没有这个天赋或暂时没有这个天赋的进阶！\n");

}
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
