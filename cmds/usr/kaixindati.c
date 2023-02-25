#include <ansi.h>
inherit F_CLEAN_UP;
int sf=0;
int main(object me, string arg)
{
	string wj, quest, key_n, key_str, *choose, level, msg;
	int i,hang,shengyu,cishu;
    string *zimu=({"A","B","C","D","E","F",});
    if(me->query_temp("kxcd/start_time")<1)		
    return notify_fail(HIR"答题时间没有到哦，每天18.10开始答题！\n"NOR);

    cishu=me->query_temp("kxcd/cishu");  //总共20题
    if(!arg){				
	if(cishu<=6){
	wj="/u/kxcddi.c";
	}else
	if(cishu>6&&cishu<=17){	
	wj="/u/kxcdzhong"+random(4);
	wj+=".c";
	}else
	if(cishu>17){
	wj="/u/kxcdgao.c";
	}
	hang=file_length(wj);
	arg = read_file(wj,random((hang-1000)),1);	
	choose = allocate(6);	
	sscanf(arg, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n", quest, key_n, key_str, choose[0],choose[1],choose[2], choose[3], choose[4], choose[5],  level);
	arg = "\n开心答题系统：  (剩余题数"+(20-cishu)+")\n";//问题先拿出来
	arg += quest+"\n";
    for (i=0;i<6;i++){
	if (sizeof(choose[i])>0){
	arg +=ZJURL("cmds:kaixindati "+(i+1))+ZJSIZE(11)+  HIY+"("+(zimu[i])+")"HIY+"、"+HIW+choose[i]+"\n";	//加上点击随后设置
	}
	}	
	msg=arg;
	msg=ZJOBLONG+HIW+msg+"\n"NOR;
	msg=replace_string(msg,"\n",ZJBR);
	write(msg+"\n");	
	if(cishu>=20){			
    me->delete_temp("kxcd");
    tell_object(me,HIG"本次答题活动结束，欢迎下次继续参与。\n"NOR);		
    return 1;
    }
	me->set_temp("kxcd/本题时间",time());
 	me->set_temp("kxcd/答案",key_n);	
 	me->add_temp("kxcd/cishu",1);	 	 
 	}else{
    if(me->query_temp("kxcd/start_time")<1)		
    return notify_fail(HIR"答题时间没有到哦，每天18.10开始答题！\n"NOR);
 	shengyu=time()-me->query_temp("kxcd/本题时间"); //30秒内必须做出选择
	if(shengyu>=30){	
	shengyu=0;		
    //me->add_temp("kxcd/cishu",1);	
    me->delete_temp("kxcd/连对");	
    me->set_temp("kxcd/start_time",0);
    write(HIR"回答超时，请等待下一题。\n"NOR);	
  	call_out("jixu",3, me);
    return 1;
    }	
	if(arg == me->query_temp("kxcd/答案")){
	//me->add_temp("kxcd/cishu",1);	
	me->add_temp("kxcd/连对",1);	
	me->set_temp("kxcd/start_time",0);
	me->add("potential",500*me->query_temp("kxcd/连对"));	
	write (HIG"回答正确，你获得了："+500*me->query_temp("kxcd/连对")+"点潜能，"+me->query_temp("kxcd/连对")+"连续答对。\n"NOR);	
 	call_out("jixu", 3, me);
	return 1;
	}else{    
    //me->add_temp("kxcd/cishu",1);	
    me->delete_temp("kxcd/连对");	
    me->set_temp("kxcd/start_time",0);
    write (HIR"回答错误，请等待下一题。\n"NOR);	
 	call_out("jixu", 3, me);
    return 1;
    }		
	return 1;
    }	    
    return 1;
}
void jixu(object me)
{
int cishu;
if(!me)
return;
cishu=me->query_temp("kxcd/cishu");
if(cishu>=20){			
me->delete_temp("kxcd");
tell_object(me,HIG"本次答题活动结束，欢迎下次继续参与。\n"NOR);		
return;
}
me->set_temp("kxcd/start_time",1);
tell_object(me,ZJFORCECMD("kaixindati"));
return;
}


/*
void check_kaixindati()
{
    mixed *sj= localtime(time());
    object player;
	if(sj[1]==10&&sj[2]==18){	
	set("channel_id", "唐伯虎");
	CHANNEL_D->do_channel( this_object(), "chat", HIY"潜能如江海，君能几瓢饮？科举闯关答题时间到了。"+NOR"。");
    set("channel_id", "活动NPC系统");		 
	foreach(player in users()){
    if (!player->query("env/dati")) continue;            
    player->set_temp("kxcd/start_time",1);	
    player->delete_temp("kxcd");
    tell_object(player,ZJFORCECMD("kaixindati"));
     } 	
   }
}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
