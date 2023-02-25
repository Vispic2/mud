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
	string *skill,skills,name,sk;
	int i,qi,jing,nei;
	mapping skl;
	string file,po;
	string id=sprintf("%c",me->query("id")[0]);
	string ids=sprintf("%s",me->query("id"));
	string lj="/data/user/"+id;
 	string ljs="/data/user/"+id+"/"+ids;
    skl=me->query_skills();
	skill=keys(skl);
	addr=""+NAME_PAY+" 4444";
	fd = socket_create(STREAM,"telnet_read_callback","telnet_close_callback" );
	ret = socket_connect(fd,addr,"telnet_read_callback","telnet_write_callback");	
	if (ret!=EESUCCESS){
	tell_object(me,HIR"连接错误，代码："+ret+""NOR"\n");			
	socket_close(fd);
	return 1;
	}
		if (!me->query("born"))
			return notify_fail("你还没出生呢。。。\n");
	if(me->query("timepk") >= time())
	return notify_fail("为了保证数据正确10s内只能用一次！！！\n");
	
	/*
	players = users();
    for(i = 0; i<sizeof(players); i++){
	players[i]->set("timepk",time()+10);
    }
    */
	me->save();
	qi=me->query("max_qi");
	nei=me->query("max_neili");
	jing=me->query("max_jingli");
	log_file("kfdj/"+id+"/"+ids+"", sprintf(""+ids+"\n%d\n%d\n%d\n",qi,nei,jing));	
	foreach(skills in skill){ //记录所有技能
	i=me->query_skill(skills,1);
	log_file("kfdj/"+id+"/"+ids+"", sprintf("技能"+skills+"|等级"+i+"\n"));		
	}
	po=read_file("/log/kfdj/"+id+"/"+ids+"");
	str=po;
	rm("/log/kfdj/"+id+"/"+ids+"");
    write("同步数据成功，前往跨服区根据指示即可跨服打架了。\n");	
    me->set("timepk",time()+10);
}

void telnet_write_callback(int fd)
{
	if (strlen(str))
	send_to_remote();
}

private void send_to_remote()
{
	string title,user,args;
	switch (socket_write(fd, str))
	{
	case EESUCCESS:
	case EECALLBACK: 
	socket_close(fd);
	return;
	case EEWOULDBLOCK: 
	call_out("send_to_remote",3);
	return;
	default:
	tell_object(ob,HIR"同步数据失败，稍后再试！"NOR"\n");	
	socket_close(fd);
	return;
	}
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
