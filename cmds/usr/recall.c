// recall.c
// created by lonely@nitan2
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string file;  
           
        if (!arg) 
        {                 
        if(wizardp(me))
        {
        write(HIW"巫师没有限制使用\n"NOR);
        }else
        {
     if (time()< (me->query("b/b")+3))
		return notify_fail("限制3秒用一次！！！\n");
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
        }                               
        file = "/d/city/kedian";                             
        tell_object(me, HIM"你从天而降，看了看四周原来到了宝昌客栈。\n"NOR);
        me->move(file);
        me->set("b/b",time());
          }
          if(arg=="zhuanshi")
          {
          
                  if(wizardp(me))
        {
        write(HIW"巫师没有限制使用\n"NOR);
        }else
        {
       if (time()< (me->query("b/b")+10))
		return notify_fail("限制10秒用一次！！！\n");
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
        }                               
        file = "/d/huashan/shandian";                             
        tell_object(me, HIM"你从天而降，看了看四周原来到了华山之巅。\n"NOR);
        me->move(file);
        me->set("b/bbbb",time());
       }
         
              
          
                return 1;
        }                                            





/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
