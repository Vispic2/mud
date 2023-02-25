#include <ansi.h>
#include <net/httpd.h>
#include <net/socket.h>
inherit F_DBASE;
int fd;
int ret;

protected void create()
{ 
	seteuid( geteuid() );
	set("channel_id", "跨服聊天精灵");
	CHANNEL_D->do_channel(this_object(), "sys", "跨服聊天服务已经启动。");
	call_out("setup", 1);
}
protected void setup()
{
    int port=JTKFPORT;
	if ((fd = socket_create(STREAM, "read_callback", "close_callback")) < 0)
	{
	CHANNEL_D->do_channel(this_object(), "sys", "跨服聊天服务创建失败。");
	return;
	}
	if (socket_bind(fd, port) < 0) {
	socket_close(fd);
	CHANNEL_D->do_channel(this_object(), "sys", "跨服聊天服务绑定失败。");
	return;
	}
	if (socket_listen(fd, "listen_callback") < 0) {
	socket_close(fd);
	CHANNEL_D->do_channel(this_object(), "sys", "跨服聊天服务监听失败。");
	}else{
	CHANNEL_D->do_channel(this_object(), "sys", "跨服聊天服务监听成功。");
	}
}

int listen_callback(int s)
{
	ret = socket_accept(fd, "read_callback", "write_callback");
}

int read_callback(int s,string chatMsg)
{
string *chatMsgs;
 if(strsrch(chatMsg, "bynamekuafu")!=-1){  //关键词如果没有就不发送，防止有人捣乱 
 chatMsgs = explode(chatMsg,"bynamekuafu");   //然后去除这个验证词 by name
 message("channel:chat",HIW+ZJSIZE(26)+"【别服】"+NOR+chatMsgs[0]+"\n",users());		
 }	
       
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
