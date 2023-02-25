

#include <ansi.h>
#define STREAM 1
#define EESUCCESS 1
nosave mapping status = ([]);
nosave string host = "api.btstu.cn";
nosave string addr = "106.53.134.195 80";
object me=this_player();
private void http(int fd)
{
socket_write(fd, status[fd]["http"]);
}
private void socket_shutdown(int fd)
{
tell_object(find_player("name"),"socket_shutdown："+fd+"\n");
socket_close(fd);
}
private void receive_callback(int fd, mixed result)
{
tell_object(find_player("name"),"receive_callback："+result+"\n");
}
private void receive_auth(int fd, mixed result)
{
    string res,text;
    int n = strsrch(result, "{");
        if (n > 0){                
        res = trim(result[n..]);
        text=replace_string(res,"{\"text\":\"","");
        message("channel:chat",HIY+"【一言】"+HIW+replace_string(text,"\"}","")+"\n"NOR,users());       
}
socket_close(fd);
}
private void auth()
{
    int fd;
    int ret;
    string path = "/yan/api.php?charset=utf-8&encode=json";
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");    
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\nHost: " + host + "\r\n\r\n";
    ret = socket_connect(fd, addr, "receive_auth", "http");
    if (ret != EESUCCESS){
        tell_object(me,HIR"API连接失败！\n"NOR);
        socket_close(fd);
    }
}
void create()
{
    auth();
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
