//by name 2022.3.05
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me,string arg)
{
string str,zl_name,zl_help,zl_read;
string a_id,a_name,a_read,*a_arr;
write_file("/cmds/usr/newbook.txt","");
a_read=read_file("/cmds/usr/newbook.txt");
a_arr=explode(a_read,"\n");
if(!sizeof(a_arr)){
write("暂时没有共享指令，赶紧去共享一个吧！\n");
return 1;
}
if(!arg){
str=ZJOBLONG"-------删除机器人(红色代表可删)-------\n";
str+=ZJOBACTS2+ZJMENUF(2,2,5,45);
for(int i=0;i<sizeof(a_arr);i++){
if(sscanf(a_arr[i],"%s %s $&%s %s %s$&",a_name,a_id,zl_name,zl_help,zl_read)==5){
if(a_id==me->query("id"))
str+=HIR"共享："+a_name+"("+a_id+")"+ZJBR+"名称："+zl_name+ZJBR+"指令："+zl_read+ZJBR+"介绍："+zl_help+NOR":newbook2 "+a_name+" "+a_id+" $&"+zl_name+" "+zl_help+" "+zl_read+"$&"+ZJSEP;
else
str+=NOR"共享："+a_name+"("+a_id+")"+ZJBR+"名称："+zl_name+ZJBR+"指令："+zl_read+ZJBR+"介绍："+zl_help+":newbook1"+zl_name+ZJSEP;
}
}
write(str+"\n");
return 1;
}else{
if(sscanf(arg,"%s %s $&%s %s %s$&",a_name,a_id,zl_name,zl_help,zl_read)==5){
if(a_id!=me->query("id")) return 1;
write_file("/cmds/usr/newbook.txt",replace_string(a_read,arg+"\n",""),1);
write("删除共享指令："+zl_name+"成功！\n");
return 1;
}else{
write("删除格式错误。\n");
return 1;
}
}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/





/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
