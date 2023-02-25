//inventory.c

#include <ansi.h>
#include <net/httpd.h>
#include <net/socket.h>
inherit F_CLEAN_UP;
private void send_to_remote();
int fd;
string str;
object ob;
int main(object me, string arg)
{
	int ret,a;
	string addr;
	int i;
	string l;
	string *fk=({
	     "fuck","你娘","你妈",
        "母狗","婊子","鸡婆","妓女",
      	"屁眼","智障","鸡巴","阴道",
      	"死妈","孤儿","废物","操你妈",
      "孙子","狗生","脑残","你妈死了",
      "强奸","弱智","艹","傻逼","狗比",
      "狗逼","你配吗","弟弟","垃圾",
      "辣鸡","腊鸡","拉级","日你妈",
	});
 
    addr=""+NAME_PAY+" "+KFPORT;	
	ob=me;
		if (!me->query("born"))
			return notify_fail("你还没出生呢。。。\n");
    if(!arg){
	write(INPUTTXT("请输入跨服聊天内容：","send $txt#")"\n"); 
	return 1;
	}
	foreach (l in fk){
	if (strsrch(arg,l) != -1)
	{
	write(HIR"你触犯了敏感词已经记入系统，多次触犯讲面临惩罚。"NOR"\n");
	arg="不要说敏感词哦";
	me->add("send/zang",1);
	}
	}
	fd = socket_create(STREAM,"telnet_read_callback","telnet_close_callback" );
	ret = socket_connect(fd,addr,"telnet_read_callback","telnet_write_callback");	
	if (ret!=EESUCCESS){
	tell_object(me,HIR"连接错误，代码："+ret+""NOR"\n");			
	socket_close(fd);
	return 1;
	}
   arg+="bynamekuafu";
   str=CYN+me->query("name")+"("+me->query("id")+")："+arg;        
   //me->force_me("send1 "+arg+"");  
}

void telnet_write_callback(int fd)
{
	if (strlen(str))
	send_to_remote();
}

private void send_to_remote()
{
	string *strs;   
	switch (socket_write(fd, str))
	{
	case EESUCCESS:
	case EECALLBACK: 
    strs = explode(str,"bynamekuafu");
	message("channel:chat",HIM+ZJSIZE(24)+"【跨服】"+NOR+ZJSIZE(27)+strs[0]+"\n"NOR,users());		
	socket_close(fd);
	return;
	case EEWOULDBLOCK: 
	call_out("send_to_remote",3);
	return;
	default:
	tell_object(ob,HIR"发送跨服聊天消息失败！"NOR"\n");	
	socket_close(fd);
	return;
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
