//#pragma optimize
//#pragma save_binary
#include <ansi.h>
#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/override.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
#include "/adm/simul_efun/user.c"
// This must be after gender.c
#include "/adm/simul_efun/message.c"
// This is the utilitis
#include "/adm/simul_efun/util.c"
//兼容NT 2021.4.14 by name
//#include "/adm/simul_efun/compatibility.c"

#include "/adm/simul_efun/json.c"
void create()
{
	seteuid(getuid());
	write("simul_efun loaded successfully.\n");
}
//递归
string *deep_path_list(string root)
{
    string file, *list = ({});
    foreach (file in get_dir(root))
    {
        if (file_size(root + file) == -2)
            list += deep_path_list(root + file + "/");
        else
            list += ({root + file});
    }
    return list;
}
//筛选一个数组
mixed filtering(mixed *arr,mixed f)
{
mixed i,*arrs=({});
foreach(i in arr){
if(i==f) continue;
arrs+=({i});
}
return arrs;
}
//string path=random_room();
//if(path!="0")
//write(path+"\n");
//by name 随机房间路径 "0"为错误 路径为正确
mixed random_room()
{
string a="/d/",lj,dir,path,*as=({}),*paths=({});
foreach(path in get_dir(a)){
if(file_size(a+path)==-2)
as+=({a+path});
}
foreach(dir in deep_path_list(as[random(sizeof(as)-1)]+"/")){
if(!find_object(dir)) continue;
if(!mapp(load_object(dir)->query("exits"))) continue;
paths+=({dir});
}
if(sizeof(paths)>10){ //房间数组小于10大概率不是城市
lj=paths[random(sizeof(paths)-1)];
return lj;
}else{
return 0;
}
return 1;
}