//by name 2021.4.16
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
int i;
string msg,*skill,skills,*name;
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
msg = YEL"本MUD目前所有技能："NOR"\n";
//dd="";
msg+=ZJOBACTS2+ZJMENUF(2,2,7,34);
skill=get_dir("/kungfu/skill/");
foreach(skills in skill){
if(is_chinese(to_chinese(skills))){  //判断是不是技能，通过判断他有没有中文名字。
name = explode(skills,".c");   
//dd+="\""+skills+"\",";
msg+="技能名 "+to_chinese(name[0])+""ZJBR"技能ID "+skills+":chaski "+skills+""ZJSEP;
 }
}
 //efun::write(dd);
msg=ZJOBLONG+msg;
msg+="\n";
write(msg);
me->start_busy(10);
return 1;
}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
