//by name
//在文件末尾追加注释
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string text,dz;
string *dir,path,lj;
dz="/";
if(arg=="start"){
text="\n\/\*\nBY：NAME\nQQ：3468713544\nDATE：2 0 2 2 . 0 2 . 0 3\n\*\/\n";
dir=deep_path_list(dz);
foreach(path in dir ){
if(strsrch(path,".c")!=-1){
write_file(path,text);
}
}
}
if(arg=="delete"){
text="\n\/\*\nBY：NAME\nQQ：3468713544\nDATE：2 0 2 2 . 0 2 . 0 3\n\*\/\n";
dir=deep_path_list(dz);
foreach(path in dir ){
if(strsrch(path,".c")!=-1){
write_file(path,replace_string(read_file(path),text,""),1);
}
}
}
/*else{
if(sscanf(arg,"%s %s",lj,text)==2) return 1;
dir=deep_path_list(lj);
foreach(path in dir ){
if(strsrch(path,".c")!=-1){
write_file(path,text);
}
}
}
*/
write("执行完成...\n");
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
