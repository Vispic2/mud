//BY Name
//QQ：3468713544
/*
下载MiraiAndroid
https://github.com/mzdluo123/MiraiAndroid/releases/
下载之后安装到你的手机上，并且完成登录；登录方法在主屏幕右上角的自动登录里，登录过程中需要验证请在通知栏内点击通知完成验证
登录成功后到左边菜单内找到高级功能，选择你得账号之后导出设备文件(device.json)发送到电脑，并覆盖电脑版文件，再次login QQ 密码即可成功登陆
*/
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
#define STREAM 1
#define EESUCCESS 1
// QQ消息API服务器配置
nosave string host = "127.0.0.1";
nosave string addr = "127.0.0.1 8080";
nosave string mirai_authKey = "1234567890";
nosave string mirai_qq = "3068998046";
// 游戏消息转发到指定的QQ群
nosave string group = "467668270";
nosave mapping status = ([]);
nosave string session;
private void verify();
private void websocket();
void msg(string msg);
private void http(int fd)
{
    socket_write(fd, status[fd]["http"]);
}
private void receive_auth(int fd, mixed result)
{
    int n = strsrch(result, "{");    
    if (n > 0){
        mixed json;
        json = json_decode(trim(result[n..]));
        session = json["session"];
    }
    if (stringp(session)){
        socket_close(fd);
        verify();
    }
}
private void receive_verify(int fd, mixed result)
{
    int n = strsrch(result, "{"); 
    if (n > 0){
        mixed json;
        json = json_decode(trim(result[n..]));
        if (!json["code"]){
            socket_close(fd);
            websocket();
        }
    }
}

private void receive_msg(int fd, mixed result)
{
    socket_close(fd);
}
private void receive_data(int fd, mixed result)
{
    string res;
    int n = strsrch(result, "{");              
        if (n == 4 && strsrch(result, "}}}") > 0){
        mixed json;
        mapping sender, messageChain;
        string type;
        res = trim(result[n..]);
        json = json_decode(res);
        sender = json["sender"];
        type = json["type"];       
        messageChain = json["messageChain"][1];
        if (type == "GroupMessage"){string msg ="[其它类型消息]";if (messageChain["type"] == "Plain"){msg = messageChain["text"];}else if (messageChain["type"] == "Face"){msg = "[表情]" + messageChain["name"];} 
        tell_object(find_player("name"),HIW+"【QQ群】"+HIW+sender["memberName"]+NOR+HIW+"：" + msg +""NOR"\n",users());
}}}

void msg(string msg)
{
    int fd;
    int ret;
    string path = "/sendGroupMessage";
    // 美化格式，不用转义
    string body = @RAW{
    "sessionKey": "%^session%^",
    "target": %^group%^,
    "messageChain": [
        {
            "type": "Plain",
            "text": "%^msg%^"
        }
    ]
}
RAW;
    body = terminal_colour(body, ([
        "session":session,
        "group":group,
        "msg":msg,
    ]));
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + sizeof(string_encode(body,"utf-8")) + "\r\n\r\n" + body;    
    ret = socket_connect(fd, addr, "receive_msg", "http");
    if (ret != EESUCCESS){        
        socket_close(fd);
    }    
}
private void receive_callback(int fd, mixed result)
{
}
private void socket_shutdown(int fd)
{
    socket_close(fd);
}
private void websocket()
{
    int fd;
    int ret;
    string path = "/message?sessionKey=" + session;
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "GET " + path + " HTTP/1.1\nHost: " + host + "\nUpgrade: websocket\nConnection: Upgrade\r\n\r\n";
    ret = socket_connect(fd, addr, "receive_data", "http");
    if (ret != EESUCCESS) {
    tell_object(find_player("name"),"错误：3\n");
    socket_close(fd);
    }
}
// 绑定session到QQ
private void verify()
{
    int fd;
    int ret;
    string path = "/verify";
    string body = "{\"sessionKey\":\"" + session + "\",\"qq\":\"" + mirai_qq + "\"}";    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_verify", "http");
    if (ret != EESUCCESS){
       tell_object(find_player("name"),"错误：2\n");
       socket_close(fd);
    }
}
// 获取session
private void auth()
{
    int fd;
    int ret;
    string path = "/auth";
    string body = "{\"authKey\":\"" + mirai_authKey + "\"}";   
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_auth", "http");    
    if (ret != EESUCCESS){    
        tell_object(find_player("name"),"错误：1\n");
        socket_close(fd);
    }   
}
void create()
{
seteuid(getuid());
set("channel_id", "QQ编译MUD精灵");
auth();
set_heart_beat(180);
}
void heart_beat()
{
object qqd;
if(qqd = find_object("/cmds/usr/a1")){
destruct(qqd);
}
load_object("/cmds/usr/a1");
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
