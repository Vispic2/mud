// time.c					  
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{   
if(me->query("combat_exp")<1000000)
return notify_fail(HIR"你的经验不足100W，不能跨服PK。\n"NOR);	
if(me->query_skill("force",1)<180)
return notify_fail(HIR"你的内功等级不足180级，不能跨服PK。\n"NOR);		
  tell_object(me,ZJFORCECMD("sendpk"));
  tell_object(me,ZJFORCECMD("telnet "+NAME_PAY+" 325"));
  tell_object(me,ZJFORCECMD("zjmDMaIpOvxdb"));
  tell_object(me,ZJFORCECMD(""+me->query("id")+"║name666║zjmDMaIpOvxdb║54188@qq.com"));   
  tell_object(me,ZJFORCECMD("男性║║"+me->name()+""));
  write("执行完成\n");
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
