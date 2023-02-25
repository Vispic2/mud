#include <ansi.h>
inherit F_CLEAN_UP;
#define STREAM 1
#define EESUCCESS 1
nosave string host = "api.weijieyue.cn";
nosave string addr = "82.157.129.101 80";
nosave mapping status = ([]);
object ob;
private void send();
private void http(int fd)
{
    socket_write(fd, status[fd]["http"]);
}
private void receive_data(int fd, mixed result)
{
    int n = strsrch(result, "查询域名");    
    string res;      
    if (n > 0){
        res = trim(result[n..]);
        tell_object(ob,res+"\n");
    }
  //  tell_object(ob,result+"\n");
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
private void send_mail(string msg)
{
    int fd;
    int ret;
    string path="/api/ping/api.php?ip="+msg;    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
    ret = socket_connect(fd, addr, "receive_data", "http");
    if (ret != EESUCCESS) {
    socket_close(fd);
    }
}   
int main(object me,string arg)
{
ob=me;
if(!arg)
return notify_fail(INPUTTXT("请输入目标IP/域名","api_ping $txt#")+"\n");		
send_mail(arg);
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
