#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	mapping skl;
	string *sname;
	int k,i;
	if(arg)
	{
	k=0;
	skl = me->query_skills();
	if(sizeof(skl)<1)
	{
	tell_object(me,ZJOBLONG+"你没有相关("+arg+")类型的技能！\n");
	return 1;
	}
	sname = keys(skl);		
	msg="以下技能为"+arg+"类型：\n";
	msg+=ZJOBACTS2+ZJMENUF(2,2,9,35);
	for (i = 0; i < sizeof(sname); i++)
	{
   if(arg=="all"){
	k+=1;					
	msg +=""YEL"〖"+to_chinese(sname[i])+"〗"ZJBR""HIC"『等级』"NOR""+skl[sname[i]]+"级:yanjiu "+sname[i]+""ZJSEP;	
	}	
	else
    if (SKILL_D(sname[i])->type() ==arg||SKILL_D(sname[i])->valid_enable(arg)||sname[i]==arg)
	{
	k+=1;
	msg +=""YEL"〖"+to_chinese(sname[i])+"〗"ZJBR""HIC"『等级』"NOR""+skl[sname[i]]+"级:yanjiu "+sname[i]+""ZJSEP;
	}
	}
	if(k>0){			
	msg +="返回:skills"ZJSEP;		
	msg=ZJOBLONG+msg;
    msg+="\n";
    write(msg);	
	} else{
	tell_object(me,ZJOBLONG+"你没有相关("+arg+")类型的技能！\n");
	}
	}

return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
