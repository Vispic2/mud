//寒江雪

#include <ansi.h>
int main(object me, string arg)
{



 if(arg=="longshe1")
 {
 me->set("longshe",0);
 write(HIM"开启显示NPC描述成功。\n"NOR);
 }
 if(arg=="longshe0")
 {
 me->set("longshe",1);
write(HIM"关闭显示NPC描述成功。\n"NOR);
 }
 
 if(arg=="longshe11")
 {
 me->set("longshezb",1);
 write(HIM"关闭显示装备成功。\n"NOR);
 }
 if(arg=="longshe00")
 {
 me->set("longshezb",0);
write(HIM"开启显示装备成功。\n"NOR);
 }

	return 1;	
	
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
