//TEST指令 by name
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string id;
string dir,*dirs;
string user,*users;
dirs=get_dir("/data/user/");
foreach(dir in dirs){
users=get_dir("/data/user/"+dir+"/");
foreach(user in users){
id=replace_string(user,".o","");
write("执行结果："+id+"\n");
me->force_me("examine -u "+id);
}
}
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
