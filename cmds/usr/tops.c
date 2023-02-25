// who.c
#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
#include <tomud.h>
#define ENGLISH_MUD_NAME INTERMUD_MUD_NAME
inherit F_CLEAN_UP;
nosave int busy=0;
void create() { seteuid(getuid()); }
int sort_exp(string user1,string user2)
{
	return (int)TOP_D->query_user(user2+"/combat_exp")-(int)TOP_D->query_user(user1+"/combat_exp");
}

int sort_gold(string user1,string user2)
{
	return (int)TOP_D->query_user(user2+"/gold")-(int)TOP_D->query_user(user1+"/gold");
}

int sort_pay(string user1,string user2)
{
	return (int)TOP_D->query_user(user2+"/all_pay")-(int)TOP_D->query_user(user1+"/all_pay");
}

int sort_per(string user1,string user2)
{
	return (int)TOP_D->query_user(user2+"/per")-(int)TOP_D->query_user(user1+"/per");
}

int sort_PKS(string user1,string user2)
{
	return (int)TOP_D->query_user(user2+"/PKS")-(int)TOP_D->query_user(user1+"/PKS");
}

int sort_shimen(string user1,string user2)
{
	int m1=0,m2=0;
	if(user1 == "player")
		m1 = TOP_D->query_user(user1+"/shimen")/7;
	else
		m1 = TOP_D->query_user(user1+"/shimen");

	if(user2 == "player")
		m2 = TOP_D->query_user(user2+"/shimen")/7;
	else
		m2 = TOP_D->query_user(user2+"/shimen");

	return m2-m1;
}

mixed main(object me, string arg, int remote)
{
	string *list,*text,*texts=({}),str,read;
	object *ob;
	int page,i,j,all,k,m;
	string type,name;
	string *all_users;
    int mc=0;
	if(!arg)
	{
		if (SECURITY_D->valid_grant(me, "(admin)"))
			write(ZJOBLONG"请选择排行类型：\n"ZJOBACTS2+ZJMENUF(4,4,9,30)+"修为榜:tops 修为"ZJSEP"战力榜:topz"ZJSEP"魔力榜:moli"ZJSEP"容貌榜:tops 容貌"ZJSEP
			"财富榜:tops 财富"ZJSEP"杀手榜:tops 杀气"ZJSEP"师门榜:tops 师门"ZJSEP"赞助榜:tops 赞助\n");
		else
			write(ZJOBLONG"请选择排行类型：\n"ZJOBACTS2+ZJMENUF(4,4,9,30)+"修为榜:tops 修为"ZJSEP"战力榜:topz"ZJSEP"魔力榜:moli"ZJSEP"容貌榜:tops 容貌"ZJSEP
			"财富榜:tops 财富"ZJSEP"杀手榜:tops 杀气"ZJSEP"师门榜:tops 师门\n");
	return 1;
	}
	else if( sscanf(arg,"%s %d",type,page)!=2 )
	{
		type = arg;
		page = 1;
	}

	if(type!="修为"&&type!="容貌"&&type!="财富"&&type!="杀气"&&type!="师门"&&type!="赞助")
		return notify_fail("暂无"+type+"类排行！！！\n");

	all_users = TOP_D->all_users();
	if(!all_users)
		return notify_fail("暂无排行数据！！！\n");
	k = 0;
	if(type=="财富")
	{
		reset_eval_cost();
		all_users = filter_array(all_users,(: TOP_D->query_user($1+"/gold")>10 :));
		if(!sizeof(all_users))
			return notify_fail("暂无"+type+"排行数据！！！\n");
		all_users = sort_array(all_users, (: sort_gold :) );
		text = ({});
		for(i=0;i<sizeof(all_users);i++)
		{
			text += ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+"财富："+TOP_D->query_user(all_users[i]+"/gold")+NOR":look "+all_users[i] });
		}
	}
	else if(type=="赞助")
	{
		reset_eval_cost();
		if (! SECURITY_D->valid_grant(me, "(admin)"))
			return notify_fail("你无权查看赞助排行！\n");

		all_users = filter_array(all_users,(: TOP_D->query_user($1+"/all_pay")>10 :));
		if(!sizeof(all_users))
			return notify_fail("暂无"+type+"排行数据！！！\n");
		all_users = sort_array(all_users, (: sort_pay :) );
		text = ({});
		for(i=0;i<sizeof(all_users);i++)
		{
			text += ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+"赞助："+TOP_D->query_user(all_users[i]+"/all_pay")+NOR":look "+all_users[i] });
		}
	}
	else if(type=="容貌")
	{
		reset_eval_cost();
		all_users = filter_array(all_users,(: TOP_D->query_user($1+"/per")>10 :));
		if(!sizeof(all_users))
			return notify_fail("暂无"+type+"排行数据！！！\n");
		all_users = sort_array(all_users, (: sort_per :) );
		text = ({});
		for(i=0;i<sizeof(all_users);i++)
		{
			text += ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+"评价："+TOP_D->query_user(all_users[i]+"/per")+NOR":look "+all_users[i] });
		}
	}
	else if(type=="杀气")
	{
		reset_eval_cost();
		all_users = filter_array(all_users,(: TOP_D->query_user($1+"/PKS")>10 :));
		if(!sizeof(all_users))
			return notify_fail("暂无"+type+"排行数据！！！\n");
		all_users = sort_array(all_users, (: sort_PKS :) );
		text = ({});
		for(i=0;i<sizeof(all_users);i++)
		{
			text += ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+"杀气："+TOP_D->query_user(all_users[i]+"/PKS")+NOR":look "+all_users[i] });
		}
	}
	else if(type=="师门")
	{
		reset_eval_cost();
		all_users = filter_array(all_users,(: TOP_D->query_user($1+"/shimen")>10 :));
		if(!sizeof(all_users))
			return notify_fail("暂无"+type+"排行数据！！！\n");
		all_users = sort_array(all_users, (: sort_shimen :) );
		text = ({});
		for(i=0;i<sizeof(all_users);i++)
		{
			if(all_users[i]=="player")
				m = TOP_D->query_user(all_users[i]+"/shimen")/7;
			else
				m = TOP_D->query_user(all_users[i]+"/shimen");
			text += ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+"本周："+m+NOR":look "+all_users[i] });
		}
	}
	else
	{
		reset_eval_cost();
		all_users = filter_array(all_users,(: TOP_D->query_user($1+"/combat_exp")>100000 :));
		if(!sizeof(all_users))
			return notify_fail("暂无"+type+"排行数据！！！\n");
		all_users = sort_array(all_users, (: sort_exp :) );
		text = ({});
		for(i=0;i<sizeof(all_users);i++)
		{
		    mc+=1;
		    if(mc<=10){
		    texts+= ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+TOP_D->query_user(all_users[i]+"/combat_exp")+NOR":look "+all_users[i] });
		    if(mc==10){		    
		    write_file("/cmds/usr/top_exp.txt",no_color(implode(texts,"\n"))+"\n",1);
		    }else{
		    write_file("/cmds/usr/top_exp.txt",no_color(implode(texts,"\n"))+"\n",1);
		
		    		    }		    
		    }		   		    
			text += ({ GRN"第"+(i+1)+"名 - "+TOP_D->get_name(all_users[i])+NOR+ZJBR+YEL+TOP_D->query_user(all_users[i]+"/combat_exp")+NOR":look "+all_users[i] });
		}
	}
	str = ZJOBLONG+LOCAL_MUD_NAME()+HIG+type+NOR"排行榜：\n";
	str += ZJOBACTS2+ZJMENUF(2,2,10,30);
	all = sizeof(text)/10;
	if(sizeof(text)%10) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*10;
	i = page*10;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	if(all>1)
		str += "上一页:tops "+type+" "+(page-1)+ZJSEP"下一页:tops "+type+" "+(page+1)+ZJSEP;
	str += implode(text[j..i], ZJSEP);
	tell_object(me,str+"\n");
	return 1;		   
}

int help(object me)
{
write(@HELP
玩家排行榜
HELP
	);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
