// update /cmds/usr/jiahaoyou.c
#include <ansi.h>

int main(object me, string arg)
{
	object obj,obj2;
	string name,name2,com,id,meid;
	
	if(!arg){
		return 0;
	}
	
	if (sscanf(arg, "%s %s", com, id) == 2){
			meid = me->query("id");
			if(com == "kbox"){//先给自己弹框
				
				obj = find_player(id);
				if(obj){
					name = obj->name();
					if(me->query("myhaoyou/"+id) == 1){
						tell_object(me,ZJOBLONG"对【"+name+"】的操作。\n"+ZJOBACTS2+ZJMENUF(2,2,9,30)"私聊:send_siliao fabox "+id+" test"+ZJSEP+"查看:look "+id+ZJSEP+"解除好友关系:jiahaoyou jcbox "+id+ZJSEP+"禁收他的信息:jiahaoyou jybox "+id+"\n");
					}else{
						tell_object(me,ZJOBLONG"对【"+name+"】的操作。\n"+ZJOBACTS2+ZJMENUF(2,2,9,30)"私聊:send_siliao fabox "+id+" test"+ZJSEP+"查看:look "+id+ZJSEP+"解除好友关系:jiahaoyou jcbox "+id+ZJSEP+"恢复接收他的信息:jiahaoyou unjinyan "+id+"\n");
					}
				}
			}
			else if(com == "ibox"){//先给自己弹框
				
				obj = find_player(id);
				if(obj){
					name = obj->name();
					tell_object(me,ZJOBLONG"你想申请与【"+name+"】成为好友吗？\n"+ZJOBACTS2+ZJMENUF(2,2,9,30)"发出申请:jiahaoyou fa "+id+ZJSEP+"取消:aaxxa\n");
				}
			}				
			else if(com == "jcbox"){//先给自己弹框
				
				obj = find_player(id);
				if(obj){
					name = obj->name();
					tell_object(me,ZJOBLONG"你真的要与【"+name+"】解除好友关系吗？\n"+ZJOBACTS2+ZJMENUF(2,2,9,30)"狠心解除:jiahaoyou jiechu "+id+ZJSEP+"取消:aaxxa\n");
				}
			}				
			else if(com == "jybox"){//先给自己弹框
				
				obj = find_player(id);
				if(obj){
					name = obj->name();
					tell_object(me,ZJOBLONG"你真的不想收【"+name+"】给你发的信息吗？\n"+ZJOBACTS2+ZJMENUF(2,2,9,30)"狠心禁言:jiahaoyou jinyan "+id+ZJSEP+"取消:aaxxa\n");
				}
			}
			else if(com == "fa"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();
					name2 = me->name();
					
					tell_object(me,HIY"【"+name+"】"NOR"已收到你发送的好友申请\n");
					
					tell_object(obj,ZJURL("cmds:jiahaoyou fazj "+meid)HIY"【"+name2+"】"NOR""NOR"申请加你为好友\n");
					
					tell_object(obj,ZJOBLONG"【"+name2+"】想加你为好友，你接受吗？\n"+ ZJOBACTS2+ZJMENUF(2,2,9,30)"接受:jiahaoyou yes "+meid+ZJSEP"拒绝:jiahaoyou no "+meid+"\n");
				}
			}
			else if(com == "fazj"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();
					
					tell_object(me,ZJOBLONG"【"+name+"】想加你为好友，你接受吗？\n"+ ZJOBACTS2+ZJMENUF(2,2,9,30)"接受:jiahaoyou yes "+id+ZJSEP"拒绝:jiahaoyou no "+meid+"\n");
				}
			}
			else if(com == "yes"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();
					name2 = me->name();
					
					obj->set("myhaoyou/"+meid,1);
					me->set("myhaoyou/"+id,1);
					
					tell_object(obj,HIY"【"+name2+"】"NOR"已同意和你成为好友了\n");
					tell_object(me,"你已同意和"HIY"【"+name+"】"NOR"成为好友\n");
				}
				
			}
			else if(com == "no"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();
					name2 = me->name();
					
					obj->delete("myhaoyou/"+meid);
					me->delete("myhaoyou/"+id);
					
					tell_object(obj,HIY"【"+name2+"】"NOR"已拒绝和你成为好友\n");
					tell_object(me,"你拒绝和"HIY"【"+name+"】"NOR"成为好友\n");
				}			
			}
			else if(com == "jiechu"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();
					name2 = me->name();
					
					obj->delete("myhaoyou/"+meid);
					me->delete("myhaoyou/"+id);
					
					tell_object(obj,HIY"【"+name2+"】"NOR"已解除和你的好友关系\n");
					tell_object(me,"你解除了和"HIY"【"+name+"】"NOR"的好友关系\n");
				}			
			}
			else if(com == "jinyan"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();

					me->set("myhaoyou/"+id,2);
					
					tell_object(me,"你禁收"HIY"【"+name+"】"NOR"给你发的信息了\n");
				}			
			}
			else if(com == "unjinyan"){
				obj = find_player(id);
				
				if(obj){
					name = obj->name();
					name2 = me->name();

					me->set("myhaoyou/"+id,1);
					
					tell_object(obj,HIY"【"+name2+"】"NOR"已恢复接收你的信息了\n");
					tell_object(me,"你恢复了"HIY"【"+name+"】"NOR"给你发的信息了\n");
				}			
			}
			else if(com == "sousy"){

				me->set("liaotype",0);
				tell_object(me,"你已设置为"HIY"【收所有人信息】"NOR"\n");
			}
			else if(com == "jinhy"){

				me->set("liaotype",1);
				tell_object(me,"你已设置为"HIY"【仅收好友信息】"NOR"\n");
			}
			else if(com == "jinsy"){

				me->set("liaotype",2);
				tell_object(me,"你已设置为"HIY"【禁收所有信息】"NOR"\n");
			}
			
		

	}
	
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
