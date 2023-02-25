// copyskill.c
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string skill;
int lvl;
if (! SECURITY_D->valid_grant(me, "(admin)"))
return 0;
if(sscanf(arg,"%s %d",skill,lvl)!=2)
return 1;
me->set_skill(skill,lvl);
write("复制"+skill+",等级"+lvl+"成功！\n");
return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
