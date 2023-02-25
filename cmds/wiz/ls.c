//by name 文件管理
#include <ansi.h>
inherit F_CLEAN_UP;
/*
int main(object me, string arg)
{ 

int i;
string cd,str,dir,path,*dirs,file,*files=({});
if(!wizardp(me)) return 1;
if(!arg){
arg="/";
path="/";
}else
path=arg;
if(sscanf(arg,"%s %s",file,cd)==2){
if(cd=="菜单")
write(ZJOBLONG+"请选择你要对"+file+"文件进行的操作：\n"+ZJOBACTS2+ZJMENUF(2,2,9,31)+"编译文件:update "+file+ZJSEP"删除文件:ls "+file+" 删除"ZJSEP"复制物品:clone "+file+ZJSEP"查看文件:ls "+file+" 查看\n");
if(cd=="删除"){
i=rm(file);
write("删除操作："+(i?"完成":"失败")+"\n");
}
if(cd=="查看"){
if(file_size(file)>(1024*1))
return notify_fail("文件内容大于1KB，请前往服务器查看相应文件...\n");
me->start_more(read_file(file));
}
return 1;
}
str=ZJOBLONG+"MUD文件管理"ZJBR"当前目录："+path+((sizeof(explode(path,"/"))>=1)?ZJBR+WHT+ZJURL("cmds:ls "+replace_string(path,explode(path,"/")[sizeof(explode(path,"/"))-1]+"/",""))+"返回上一层"NOR"":"")+"\n";
str+=ZJOBACTS2+ZJMENUF(1,1,9,31);
if(!sizeof(get_dir(path))) str+="空文件夹:look";
foreach(dir in get_dir(path)){
if(file_size(path+dir)==-2)
str+="目录：["+dir+"]:ls "+(path+dir)+"/"+ZJSEP;
else
files+=({"文件：["+dir+"]  内存："+(file_size(path+dir)<1024?file_size(path+dir)+"B":(file_size(path+dir)/1024)+"KB")+":ls "+(path+dir)+" 菜单"+ZJSEP});
}
foreach(file in files)
str+=file;
write(str+"\n");
return 1;

}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
