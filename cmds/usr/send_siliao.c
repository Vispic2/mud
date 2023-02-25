// updateall.c
#include <ansi.h>

string getanliu(string id);

int main(object me, string arg)
{
	object obj;
	string name,com,id,meid,msg;
	
	if(!arg){
		return 0;
	}
	
	if (me->query("chblk_on"))
	{
	tell_object(me,"你目前处于禁言状态，无法私聊！\n");	
	return 1;
	}



	if (sscanf(arg, "%s %s %s", com, id, msg) == 3){
			meid = me->query("id");
			obj = find_player(id);
			
			if(obj){
				
				if(com == "do"){
					name = obj->name();

					if(obj->query("chblk_on") ){
						tell_object(me,"发送失败："HIY"【"+name+"】"NOR"目前处于禁言状态，无法接受私聊\n");		
						return 0;
					}


					if(obj->query("liaotype") == 2){
						tell_object(me,"发送失败："HIY"【"+name+"】"NOR"已经关闭了私聊频道\n");		
						return 0;
					}
					
					if(obj->query("liaotype") == 1 && !obj->query("myhaoyou/"+meid)){
						tell_object(me,"发送失败："HIY"【"+name+"】"NOR"只接收好友的信息，而你们还不是好友\n");		
						return 0;
					}
					if(obj->query("myhaoyou/"+meid) == 2){
						tell_object(me,"发送失败："HIY"【"+name+"】"NOR"已设置禁收你的信息，看来你们有误会了\n");		
						return 0;
					}
					
					name = me->name();
					tell_object(obj,ZJURL("cmds:send_siliao cabox "+meid+" "+msg)+HIY"【"+name+"】"NOR""NOR"对你说："+msg+"\n");
					tell_object(obj,INPUTTXT(HIY"【"+name+"】"NOR"对你说："ZJBR""ZJSIZE(22)+msg+""NOR"","send_siliao do "+meid+" "+" $txt#")+"\n"+getanliu(meid));
				
					name = obj->name();
					tell_object(me,"你对"+ZJURL("cmds:send_siliao fabox "+id+" test")+HIY"【"+name+"】"NOR""NOR"说："+msg+"\n");	
					//增加日志记录
		//			//log_files("channel/liao", sprintf("%s，%s(%s)对%s(%s)说：%s。\n",cntime(time()),me->query("name"),me->query("id"),name,id,msg));
//				//log_files("cmds/hb", sprintf("%s：%s(%s)发送了红包，金额："+a+"，包数："+b+"。\n",ctime(time()),me->query("name"),me->query("id")));
	
				}else if(com == "cabox"){
					name = obj->name();
					tell_object(me,INPUTTXT(HIY"【"+name+"】"NOR"对你说："ZJBR""ZJSIZE(22)+msg+""NOR"","send_siliao do "+id+" "+" $txt#")+"\n"+getanliu(id));
				}else if(com == "fabox"){
					name = obj->name();
					tell_object(me,INPUTTXT(ZJSIZE(22)"对【"+name+"】说点什么？"NOR"","send_siliao do "+id+" "+" $txt#")+"\n"+getanliu(id));				
				}
			
		
			}else{
				tell_object(me,"没找到人。\n");
			}
	}
	
	return 1;
}

string getanliu(string id){
	int i;
	string str,*anl;
	anl = ({"我知道了","我没时间","我来找你","我马上过来","我要下了","你在干啥","你在哪里","你要过来吗","你好久下线",});
	str = "";
	for(i=0;i<sizeof(anl);i++){
		if(i == sizeof(anl)-1){
			str += anl[i]+":send_siliao do "+id+" "+anl[i]+"\n";
		}else{
			str += anl[i]+":send_siliao do "+id+" "+anl[i]+ZJSEP;
		}
		
	}
	return ZJOBACTS2+ZJMENUF(3,3,12,30)+str;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
