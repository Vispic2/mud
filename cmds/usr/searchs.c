#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string msg;
msg=ZJOBLONG+"请选择要执行的操作：\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,9,31);
msg+="尚存宝物:wabao"ZJSEP;
msg+="挖宝探索:search"; 
write(msg+"\n");
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
