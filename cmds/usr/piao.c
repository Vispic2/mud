// piao.c   by lonely
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
     object obj;// where = environment(me);
   int mekar;
    seteuid(getuid());
    if(!(environment(me)->query("piao_room")))
        return notify_fail("这里不是丽春院二楼，你想干嘛？\n");

    if (!arg || !objectp(obj = present(arg, environment(me))))
         return notify_fail("你现在很冲动，可是一点辙都没有。\n");

        if ( !me->query_temp("rent_paid"))
             return notify_fail("你没付钱就想嫖呀？再不走当心我打断你的狗腿！\n");
             
    if (me->query("gender") =="无性")
         return notify_fail("你连那个工具都没有，还想干好事？\n");

    if (me->query("gender") =="女性")
        return notify_fail("哇！现在女人也想嫖男人了，太可怕了！\n");

if (me->is_busy())
   return notify_fail("你现在正忙着呢。\n");

    if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
        return notify_fail("你现在精不够！\n");

      if (me->query("age") < 17)
          return notify_fail("你连十七岁都没到，就学坏啊！\n");

    if (obj==me) return notify_fail("你自慰呀？\n");

    if (obj->query("gender") != "女性")
         return notify_fail("不对吧。他好象不是女人吧。\n");

    if (obj->query("age") < 16)
        return notify_fail("强奸幼女可是死罪，你想清楚了哦！\n");

    if( (int)obj->query("jing")<50 )
      return notify_fail("对方现在精神涣散，没有办法和你......\n");
      
      if (obj->is_busy())
         return notify_fail("对方现在正忙着招待别人呢，没有时间理你了！\n");

    if (!obj->query_condition("prostitute"))
           return notify_fail("对方可不属于妓院的人！\n");
    if (!obj->is_character()) return notify_fail("哇，死的东西都不放过！\n");

    if (!living(obj) )
         return notify_fail(obj->name() + "现在被别人嫖了。好可怜！\n");

    if( !wizardp(me) && wizardp(obj) )
         return notify_fail("嫖巫师？你不怕杀档？\n");

    if( me->is_fighting() )
         return notify_fail("一边打架一边色迷迷？你真是活腻了！\n");

    if( obj->is_fighting() ) 
         return notify_fail(obj->name() + "正在打架，你不怕被阉？\n");
     message_vision("\n$N向$n含情脉脉的看着,掏出了一大把金票向$n提出了要求,想...... \n", me,obj);

          mekar=me->query("kar");   // by lonely
     if(random(21)>mekar)
      {      
      tell_object(me, HIR "玩了！这次惨了！！\n" NOR);      
      message_vision("$N满脸不屑，突然从身后拿出一把剪刀向$n的下身......\n\n", obj, me);   
       message_vision("不幸的事情发生了......\n", obj, me);
       message_vision("$n惨叫一生，昏了过去........\n", obj, me);
       shout( RED"\n谣言：有人嫖妓未遂，被阉了！\n"NOR);
       this_player()->set("gender","无性");
       this_player()->set("class", "eunach");
       this_player()->unconcious();
      }
    else 
    {  
     message_vision("\n$n羞涩地看了$N一眼，涨红了脸，微微地点了点头。\n", me,obj);
     message_vision("\n$N温柔地抱起$n，$n的身体在$N怀里轻轻颤动了一下。\n$n用热唇轻轻的给了$N一吻。\n", me,obj); 
     message_vision(BOLD "$N脱下自己的衣带，光着身子钻进被窝。\n" NOR, me);
     message_vision(BOLD "$N轻轻解开$n的衣带，露出了洁白的肌肤。\n" NOR, me,obj);
     message_vision("$N紧紧抱住了$n，$n觉得一片温馨。\n", me ,obj); 
     message_vision("$N吻遍了$n的每一寸肌肤!\n", me,obj);
     message_vision("$N抚摸着$n柔柔的身体!\n", me,obj);
     message_vision( HIM "  月光穿过窗户，轻撒在床前....... \n" NOR,me,obj);
      shout( RED"\n谣言：有人在光天化日下进入妓院嫖妓了！\n"NOR);
      me->set("qi",20);
      me->set("neili",20);
      me->add("combat_exp",2);
      me->add("shen",-1000);
      me->add_temp("rent_paid",-1);
        this_player()->set("combat_exp",this_player()->query("combat_exp")-1000);
      me->start_busy(5);
      obj-> start_busy(5);
      obj->add("jing",-50);
    }
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : piao <某人> | 丽春院专用

HELP
    );
    return 1;
}





/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
