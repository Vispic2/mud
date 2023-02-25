#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
int nc;
string path,*text=({});
string dh,lj,read,dir,del_lj,del_nc,del_ncs,del_read,*dirs,*tion=({});
if(!wizardp(me)) return 1;
if(arg=="stat"){
foreach(path in deep_path_list("/")){
if(strsrch(path,".c")==-1) continue;
if(strsrch(path,"/d")!=-1) continue;
text+=({"路径："+path+" 内存："+file_size(path)+"\n"});
}
write_file("/adm/daemons/hmrd.txt",implode(text,""),1);
write("获取文件路径，文件名成功！\n");
return 1;
}
if(arg=="jc"){
if(!file_size("/adm/daemons/hmrd.txt")) return 1;
read=read_file("/adm/daemons/hmrd.txt");
dirs=explode(read,"\n");
foreach(dir in dirs){
sscanf(dir,"路径：%s 内存：%d",lj,nc);
if(file_size(lj)!=nc)
tion+=({"路径："+lj+" 内存由："+nc+" 变成了："+file_size(lj)});
}
foreach(dh in tion){
sscanf(dh,"路径：%s 内存由：%s 变成了：%s",del_lj,del_nc,del_ncs);
tell_object(me,"路径："+del_lj+" 内存："+file_size(del_lj)+"\n");
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
