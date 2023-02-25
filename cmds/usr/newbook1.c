//by name 2022.3.05
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
string str,zl_name,zl_help,zl_read;
string a_id,a_name,a_read,*a_arr;
write_file("/cmds/usr/newbook.txt","");
a_read=read_file("/cmds/usr/newbook.txt");
if(!arg){
str=ZJOBLONG"-------------机器人(全部)-------------\n";
str+=ZJOBACTS2+ZJMENUF(2,2,5,45);
str+="添加指令:newbook1 add"ZJSEP;
str+="删除指令:newbook2"ZJSEP;
str+="全部指令:newbook1"ZJSEP;
str+="我的指令:newbook1 me"ZJSEP;
a_arr=explode(a_read,"\n");
for(int i=0;i<sizeof(a_arr);i++){
if(sscanf(a_arr[i],"%s %s $&%s %s %s$&",a_name,a_id,zl_name,zl_help,zl_read)==5){
str+="共享："+a_name+"("+a_id+")"+ZJBR+"名称："+zl_name+ZJBR+"指令："+zl_read+ZJBR+"介绍："+zl_help+":set sign5 "+zl_read+ZJSEP;
}
}
//徐凤年 name $&测试 一二三四五六七八九十 look$&
write(str+"\n");
return 1;
}else{
if(arg=="me"){
str=ZJOBLONG"------------机器人(红色代表自己)---------\n";
str+=ZJOBACTS2+ZJMENUF(2,2,5,45);
str+="添加指令:newbook1 add"ZJSEP;
str+="删除指令:newbook2"ZJSEP;
str+="全部指令:newbook1"ZJSEP;
str+="我的指令:newbook1 me"ZJSEP;
a_arr=explode(a_read,"\n");
for(int i=0;i<sizeof(a_arr);i++){
if(sscanf(a_arr[i],"%s %s $&%s %s %s$&",a_name,a_id,zl_name,zl_help,zl_read)==5){
if(a_id==me->query("id"))
str+=HIR"共享："+a_name+"("+a_id+")"+ZJBR+"名称："+zl_name+ZJBR+"指令："+zl_read+ZJBR+"介绍："+zl_help+NOR+":"+zl_read+ZJSEP;
else
str+=NOR"共享："+a_name+"("+a_id+")"+ZJBR+"名称："+zl_name+ZJBR+"指令："+zl_read+ZJBR+"介绍："+zl_help+":"+zl_read+ZJSEP;
}
}
//徐凤年 name $&测试 一二三四五六七八九十 look$&
write(str+"\n");
return 1;
}
write(INPUTTXT("添加共享的指令"ZJBR"格式：$&指令名称 指令介绍 指令内容$&"ZJBR"实例：$&测试 用于测试的一个指令 test$&"ZJBR"注意：前面以及结尾需要用$&符合","newbook1 $txt#")+"\n");		
if(strsrch(arg,"$&")!=-1){
if(sscanf(arg,"$&%s %s %s$&",zl_name,zl_help,zl_read)==3){
if(arg[0..1]!="$&"||arg[strlen(arg)-2..strlen(arg)]!="$&"||strlen(arg)<=5){
write("输入格式错误1，请看实例！\n");
return 1;
}
if(strlen(zl_name)<=1||strlen(zl_name)>=7){
write("指令名称不能少于2个且大于6个字。\n");
return 1;
}
if(strlen(zl_help)<=9||strlen(zl_help)>=31){
write("指令介绍不能少于10个且大于30个字。\n");
return 1;
}
if(strlen(zl_read)<=2||strlen(zl_help)>=51){
write("共享指令不能少于3个且大于50个字。\n");
return 1;
}
if(strsrch(a_read,zl_name)!=-1){
write("共享指令名字重复，"+zl_name+"请重新设定！\n");
return 1;
}
write("共享指令成功："+arg+"\n");
write_file("/cmds/usr/newbook.txt",me->name()+" "+me->query("id")+" "+arg+"\n");
return 1;
}else{
write("输入格式错误1，请看实例！\n");
return 1;
}
return 1;
}
return 1;
}
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
