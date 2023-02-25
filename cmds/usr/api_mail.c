#include <ansi.h>
inherit F_CLEAN_UP;
#define STREAM 1
#define EESUCCESS 1
nosave string host = "124.223.83.184";
nosave string addr = "124.223.83.184 80";
nosave mapping status = ([]);
varargs void send_mail();
string id,pass,mail;
object ob;
string data(object ob)
{
object link_ob;
link_ob=ob->query_temp("link_ob");
return link_ob->query("data_id")+"-"+link_ob->query("data_password")+"-"+ob->query("data_email");
}
private void http(int fd)
{
    socket_write(fd, status[fd]["http"]);
}
private void receive_data(int fd, mixed result)
{
    int n = strsrch(result, "{");    
    string res;      
    if (n > 0){
        res = trim(result[n..]);
        tell_object(ob,"注册信息已经发往你的邮箱，状态："+replace_string(res,"{","")+"\n");
     }
    socket_close(fd);
}
private void receive_callback(int fd, mixed result)
{
    socket_close(fd);
}
private void socket_shutdown(int fd)
{
    socket_close(fd);
}
varargs void send_mail(int i,string youxiang)
{
    int fd;
    int ret;
    string path,data=data(ob);   
    if(i==1){
    path="/mobi/email/api.php?email="+youxiang+"&title="+LOCAL_MUD_NAME()+"Mud邀请函&nr="+ob->name()+"("+ob->query("id")+")邀请你加入"+LOCAL_MUD_NAME()+"Mud一起玩耍，如果你同意邀请可以加群：1074716854下载游戏安装包，本次邀请验证码："+ob->query("new_code")+"[请将邀请码告诉邀请人]";    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
    ret = socket_connect(fd, addr, "receive_data", "http");
    if (ret != EESUCCESS) {
    socket_close(fd);
    }
    return;
    }
    if(sscanf(data,"%s-%s-%s",id,pass,mail)==3){
    path="/mobi/email/api.php?email="+mail+"&title=MUD注册信息&nr=恭喜你注册"+LOCAL_MUD_NAME()+"成功，账号："+id+"，密码："+pass+"，邮箱："+mail+"，本次注册验证码："+ob->query("new_code");    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
    ret = socket_connect(fd, addr, "receive_data", "http");
    if (ret != EESUCCESS) {
    socket_close(fd);
    }
    }else{
    return;
    }
}   
int main(object me,string arg)
{
string youxiang;
ob=me;

if(!me->query("born")){
if (strsrch(read_file("/d/register/regmail.txt"),me->query("data_email"))!=-1){	
write("此邮箱已经注册游戏，如需重新注册请删除原账号。\n");
return 1;
}
}	

if(!arg){
send_mail();
return 1;
}
if(!me->query("born"))
return notify_fail("你还没有出生呐？\n");                 
if(me->is_busy())
return notify_fail("你正忙著呢。\n");
if(me->is_fighting())
return notify_fail("你现在正在战斗！\n"); 
if(me->is_ghost()) 
return notify_fail("等你还了阳再说吧。\n");                 
if(me->is_in_prison())   
return notify_fail("你正在做牢呢。\n");
if(me->query("doing") )
return notify_fail("你还想干什么？！\n");
if(is_az(arg[0..0])){
write(HIR"警告：请使用数字邮箱，不能使用英文邮箱，你的ID已被记录！\n"NOR);
me->add("mail-bug",1);
return 1;
}
if(me->query("new_code_time")>time())
return notify_fail("每60秒才能发送一次邀请验证码，距离下次可以发验证码时间："+(me->query("new_code_time")-time())+"秒！！！\n");
if(arg!=ob->query("data_email")){
ob->set("new_code",random(10)+""+random(10)+""+random(10)+""+random(10));
send_mail(1,arg);
ob->set("yq/"+arg,ob->query("new_code"));
me->set("new_code_time",time()+60);
}else{
write("不能邀请自己！\n");
}
return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
