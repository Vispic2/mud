//BY Name
//QQ：21315491
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
nosave string group = "1074716854";
nosave mapping status = ([]);
nosave string session;
private void verify();
private void websocket();
void msg(string msg);


varargs int control(mixed a,mixed b,mixed c,mixed d);
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
        string target,type1; //@的目标 是否是at的类型
        res = trim(result[n..]);
        json = json_decode(res);
        //tell_object(find_player("name"),sprintf("%O\n",json));
/*
        string res;
        int n = strsrch(result, "{");
        if (n > 0){
        mixed json;
        mapping sender, messageChain;
        string type,err;                
        res = trim(result[n..]);
        json=json_decode(res),      
        */                             
     //   json = json["data"];
        sender = json["sender"];  //qq名字
        type = json["type"];       //判断是图片还是文字还是表情等
        messageChain = json["messageChain"][1]; //发生信息
        target=json["messageChain"][1]["target"];
        type1=json["messageChain"][1]["type"];
        //tell_object(find_player("name"),sprintf("%O\n",));
        if (type == "GroupMessage"){
            string msg ="[其它类型消息]";
            if (messageChain["type"] == "Plain"){
                msg = messageChain["text"];
            }
            else if (messageChain["type"] == "Face"){
                msg = "[表情]" + messageChain["name"];
            } 
           /* if(type1=="At")
            control(sender["memberName"],msg,sender["id"],target);
            else
            */
            control(sender["memberName"],msg,sender["id"]);
       }
  }
}



private void receive_test(int fd, mixed result)
{
    int n = strsrch(result, "{"); 
    debug_message(result);
    if (n > 0){
        mixed json;
        json = json_decode(trim(result[n..]));
    }
}
//全员禁言
int muteAll()
{
    int fd;
    int ret;
    string path = "/muteAll";
    string body = "{\"sessionKey\":\""+session+"\",\"target\":\""+group+"\"}";   
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_test", "http");
}
//解除全员禁言
int unmuteAll()
{
    int fd;
    int ret;
    string path = "/unmuteAll";
    string body = "{\"sessionKey\":\""+session+"\",\"target\":\""+group+"\"}";   
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_test", "http");
}
//戳一戳
int sendNudge(mixed qq)
{
    int fd;
    int ret;
    string path = "/sendNudge";
    string body = "{\"sessionKey\":\""+session+"\",\"target\":\""+qq+"\",\"subject\":\""+group+"\",\"kind\":\"Group\"}";   
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_test", "http");
}
//指定禁言
int mute(mixed qq,mixed time)
{
    int fd;
    int ret;
    string path = "/mute";
    string body = "{\"sessionKey\":\""+session+"\",\"target\":\""+group+"\",\"memberId\":\""+qq+"\",\"time\":\"1800\"}";    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_test", "http");
}
//解除指定禁言
int unmute(mixed qq)
{
    int fd;
    int ret;
    string path = "/unmute";
    string body = "{\"sessionKey\":\""+session+"\",\"target\":\""+group+"\",\"memberId\":\""+qq+"\"}";    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_test", "http");
}
//指定踢人
int kick(mixed qq)
{
    int fd;
    int ret;
    string path = "/kick";
    string body = "{\"sessionKey\":\""+session+"\",\"target\":\""+group+"\",\"memberId\":\""+qq+"\"}";    
    fd = socket_create(STREAM, "receive_callback", "socket_shutdown");
    status[fd] = ([]);
    status[fd]["http"] = "POST " + path + " HTTP/1.1\nHost: " + host + "\nContent-Type: application/json\nContent-Length: " + strlen(body) + "\r\n\r\n" + body;
    ret = socket_connect(fd, addr, "receive_test", "http");
}
/*
949462650
/kick
{
    "sessionKey": "YourSessionKey",
    "target": 123456789,
    "memberId": 987654321,
    "msg": "您已被移出群聊"
}
名字	可选	类型	举例	说明
sessionKey	false	String	"YourSessionKey"	你的session key
target	false	Long	123456789	指定群的群号
memberId	false	Long	987654321	指定群员QQ号
msg	true	String	""	信息
*/
varargs int control(mixed a,mixed b,mixed c,mixed d)
{
    //a=QQ名字 b=发送信息 c=QQ号
    int i,cs,qq,time;
    string name,text,str,wg,wgc,sq;
    mixed ttt;
    name=a;text=b;qq=c;
    sq="/adm/daemons/miraid_sq.txt";
    //msg("a="+name+" b="+text+" c="+c+" d="+d);    
    write_file(sq,"");
    if(text=="QQ功能菜单"){
            msg("群管机器人v1.0\n1.群管菜单\n2.游戏菜单(未开发)");
            return 1;
        }
     if(qq==21315491||(strsrch(read_file(sq),""+qq+"")!=-1)){       
       if(sscanf(text,"%s %s %d",str,wgc,cs)==3&&str=="发送"){         
            for(i=1;i<=cs;i++){
            msg(wgc);
            }
            msg("发送:"+wgc+" "+i+"次成功!");
            return 1;
        }
        //授权 
        if(sscanf(text,"%s %d",str,qq)==2&&str=="授权"){
        write_file(sq,qq+"\n");
        msg("授权:"+qq+"成功!");
        return 1;
        }
        if(sscanf(text,"%s %d",str,qq)==2&&str=="取消授权"){
        write_file(sq,replace_string(read_file(sq),""+qq+"\n",""),1);
        msg("取消授权:"+qq+"成功!");
        return 1;
        }
        
        if(text=="群管菜单"){
            msg("群管机器人v1.0\n1.全员禁言\n2.解除全员禁言\n3.禁言 + QQ +时间\n4.解除禁言\n5.踢人 + QQ\n6.戳一戳 + QQ\n7.查|添|删违规词 + 违规词");
            return 1;
        }
        if(text=="查看违规词"){
            wgc="";
            foreach(wg in explode(read_file(__DIR__+"mirai.txt"),"\n")){
                if(strlen(wg)>=1)
                wgc+=wg+"\n";
            }
            msg("当前系统违规词:\n"+wgc);
            return 1;
        }
        if(sscanf(text,"%s %s",str,wgc)==2&&str=="删除违规词"){
            write_file(__DIR__+"mirai.txt",replace_string(read_file(__DIR__+"mirai.txt"),wgc,""),1);
            msg("删除违规词:"+wgc+"成功!");
            return 1;
        }
        if(sscanf(text,"%s %s",str,wgc)==2&&str=="添加违规词"){
            write_file(__DIR__+"mirai.txt",read_file(__DIR__+"mirai.txt")+"\n"+wgc,1);
            msg("添加违规词:"+wgc+"成功!");
            return 1;
        }
        if(text=="全员禁言"){
             muteAll();
             msg("开启全员禁言成功!");
             return 1;
         }
        if(text=="解除全员禁言"){
            unmuteAll();
            msg("解除全员禁言成功!");
            return 1;
        }
        if(sscanf(text,"%s %s",str,qq)==2&&str=="戳一戳"){
            sendNudge(qq);
            msg("戳一戳:"+qq+"成功!");
            return 1;
        }
        if(sscanf(text,"%s %d %d",str,qq,time)==3&&str=="禁言"){
            msg("禁言:"+qq+"成功\n禁言时间:"+time+"秒!");
            mute(qq,time);
            return 1;
        }
        if(sscanf(text,"%s %d",str,qq)==2&&str=="解除禁言"){
            msg("解除禁言:"+qq+"成功!");
            unmute(qq);
            return 1;
        }
        if(sscanf(text,"%s %d",str,qq)==2&&str=="踢人"){
        if(c==21315491){
            msg("踢人:"+qq+"成功!");
            kick(qq);
            return 1;
           }else{
           msg("踢人失败，只有群主能踢人!");
           return 1;
           }
        }
        /*
        foreach(wg in explode(read_file(__DIR__+"mirai.txt"),"\n")){
        if(strsrch(text,wg)!=-1&&strlen(wg)>=1){
        msg("触犯违规词，警告一次！");
        return 1;
      }
     } 
     */
     }
     
     foreach(wg in explode(read_file(__DIR__+"mirai.txt"),"\n")){
        if(strsrch(text,wg)!=-1&&strlen(wg)>=1){
        find_player("name")->add("mirai/"+qq,1);
        if(find_player("name")->query("mirai/"+qq)>3){
        mute(qq,3600);
        }     
        if(find_player("name")->query("mirai/"+qq)>6){
        kick(qq);
        }   
        msg("QQ:"+qq+"\n当前违规次数："+find_player("name")->query("mirai/"+qq)+" 次\n触犯违规词，警告一次！\n3次禁言30分钟 6次移除本群！");
        return 1;
      }
     }
     return 1;
}



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
set("channel_id", "机器人精灵");
auth();
set_heart_beat(180);
}
void heart_beat()
{
object qqd;
if(qqd = find_object("/adm/daemons/miraid")){
destruct(qqd);
}
load_object("/adm/daemons/miraid");
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
