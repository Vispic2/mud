// update /cmds/usr/myhy.c

#include <ansi.h>

void more_str(string tab, string str, int line, int page)
{
	int i,j,all;
	string show,*text;

	show = tab;
	text = explode(str,"\n");
	all = sizeof(text)/line;
	if(sizeof(text)%line) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*line;
	i = page*line;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;

	show += sprintf("私聊范围："ZJURL("cmds:jiahaoyou sousy as sd")+HIY"【收所有】"NOR""NOR" "+ZJURL("cmds:jiahaoyou jinhy as sd")+HIY"【仅好友】"NOR""NOR" "+ZJURL("cmds:jiahaoyou jinsy as sd")+HIY"【禁所有】"NOR""NOR""ZJBR"你的在线好友(%d/%d页)：\n",page,all);
	show += ZJOBACTS2+ZJMENUF(2,2,9,32);
	show += "上一页:myhy "+(page-1)+ZJSEP"下一页:myhy "+(page+1)+ZJSEP;
	show += implode(text[j..i], ZJSEP);
	write(show+"\n");
}

mixed main(object me, string arg, int remote)
{
	string str;
	object obj;
	int page,i;
	string *lists,jin;
	mapping list;
	int ppl_cnt,wiz_cnt;

	str="";
	i=0;

	wiz_cnt = 0;
	ppl_cnt = 0;
	if(remote && sizeof(arg)<2) arg="";

	if( !arg )
	{
		page = 1;
	}
	else if(sscanf(arg,"%d",page)!=1)
	{
		page = 1;
	}

	list = me->query("myhaoyou");
	
	if(!list){
		tell_object(me,HIY"你还没有好友，请先加个好友试试。"NOR"\n");	
		return 0;
	}
	
	if(sizeof(lists=keys(list)))
	{
		for(i=0;i<sizeof(lists);i++)
		{
			obj = find_player(lists[i]);
			if(obj && !obj->query_temp("apply/name")){
				jin = "";
				if(list[lists[i]] == 2){
					jin = HIR" 【禁言】"NOR;
				}
				str += sprintf("%s"ZJBR+HIY"%s"NOR":jiahaoyou kbox %s\n",obj->query("title"),obj->query("name")+jin, obj->query("id"));
				ppl_cnt ++;
				wiz_cnt ++;				
				
			}
		}
	}
	
	more_str(ZJOBLONG, str, 10, page);
	return 1;		   
}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
