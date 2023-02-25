//by name 提取文件+合并文件
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string to,is,dir,read,text,*dirs,*reads,*texts=({});
if(!wizardp(me)) return 1;
if(arg=="hb"){
foreach(dir in deep_path_list("/cmds/usr/hb/")){
texts+=({read_file(dir)});
}
write_file("/cmds/usr/extract_hb.txt",implode(texts,""),1);
write("合并文件成功\n");
return 1;
}
foreach(dir in deep_path_list(arg)){
if(strsrch(dir,".c")==-1) continue;
if(file_size(dir)<100) continue;
read=read_file(dir);
reads=explode(read,"");
foreach(to in reads){
if(is_chinese(to)||to=="，"||to==","||to=="。"||to=="!"||to=="！"){
texts+=({to});
}
}
}
write("执行完成\n");
write_file("/cmds/usr/extract_"+replace_string(arg,"/","")+".txt",replace_string(replace_string(replace_string(implode(texts,""),"。","\n"),"！","\n"),"!","\n"),1);
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
