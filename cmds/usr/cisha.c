//by name 2021.5.28
//qq 3468713544 
//刺杀任务
#include <ansi.h>
inherit F_CLEAN_UP;
#define PH "/adm/daemons/paohuand"
int main(object me, string arg)
{
if(!arg){
PH->main(me,"main");
}else{
PH->main(me,arg);
}
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
