
#include <ansi.h>
 
inherit F_CLEAN_UP;

string status_color(int current, int max);
 
int main(object me,string arg)
{
	object ob,*tar;
	mapping my,yours;
	string sp;
	string *sss,str;
	int i,max;
	int exp;
	int n,x;
	string name;
	int puyi;
	seteuid(getuid(me));
	ob = me;
 
	my = ob->query_entire_dbase();
	name=my["name"];
	exp=my["combat_exp"]/10000;
	tar = me->query_enemy();
	n=random(sizeof(tar));
	if (sizeof(tar)!=0&&objectp(tar[n]))
	yours = tar[n]->query_entire_dbase();
	
	//聚灵宝阵加成
	puyi=me->query("puyi_baozhen")*2;
	if(random(3)==1&&me->query("puyi_baozhen")){
	me->add("combat_exp",puyi);
	me->add("potential",puyi);
	me->add("balance",puyi);
	}
	

	if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
		return notify_fail("还没有出生呐，察看什么？\n");

	if (my["max_jing"] < 1 || my["max_qi"] < 1)
		return notify_fail("无法察看" + ob->name(1) + "的状态。\n");

	if (sizeof(tar)!=0&&me->is_fighting())		
		{			
		if(me->query("web"))
		sp  = ZJHPTXT+ZJMENUF(6,6,25,40) +sprintf("我：%s:100/100:%s",my["name"],"#333333");
		else
		sp  = "\n"+ZJHPTXT+ZJMENUF(6,6,25,40) +sprintf("我：%s:100/100:%s",my["name"],"#333333");		
		sp += "║"+ sprintf("气血.%d:%d/%d/%d:%s",my["qi"],my["qi"],my["eff_qi"],my["max_qi"],"#99FF0000");
		sp += "║" + sprintf("内力.%d:%d/%d/%d:%s",my["neili"],my["neili"],my["max_neili"],ob->query_neili_limit(),"#990066FF");
		sp += "║" + sprintf("精神.%d:%d/%d/%d:%s",my["jing"],my["jing"],my["eff_jing"],my["max_jing"],"#99990000");
		sp += "║" + sprintf("精力.%d:%d/%d/%d:%s",my["jingli"],my["jingli"],my["max_jingli"],ob->query_current_jingli_limit(),"#990066CC");			
			if (intp(me->query_busy()))
			sp += "║" + sprintf("忙乱.%d:%d/1:%s",me->query_busy(),1,"#BB3F51B5");
			else
			sp += "║"+sprintf("%s:100/100:%s","忙乱：+∞","#BB3F51B5");			
	
		
		for(x=0;x<sizeof(tar);x++)
		{
		if(!objectp(tar[x])||!tar[x]->is_fighting())	
		continue;			
			yours = tar[x]->query_entire_dbase();
			sp += "║" +sprintf("敌：%s:100/100:%s",yours["name"],"#000000");
			
		if(yours["max_qi"]>9999999)
		sp += "║" + sprintf("血(万).%d:%d/%d/%d:%s",yours["qi"]/10000,yours["qi"]/10000,yours["eff_qi"]/10000,yours["max_qi"]/10000,"#99FF0000");		
		else	
		sp += "║" + sprintf("气血.%d:%d/%d/%d:%s",yours["qi"],yours["qi"],yours["eff_qi"],yours["max_qi"],"#99FF0000");
		
		if(yours["max_neili"]>9999999)
		sp += "║" + sprintf("内(万).%d:%d/%d/%d:%s",yours["neili"]/10000,yours["neili"]/10000,yours["max_neili"]/10000,ob->query_neili_limit()/10000,"#990066FF");
		else
		sp += "║" + sprintf("内力.%d:%d/%d/%d:%s",yours["neili"],yours["neili"],yours["max_neili"],ob->query_neili_limit(),"#990066FF");
	
		if(yours["max_jing"]>9999999)
		sp += "║" + sprintf("精(万).%d:%d/%d/%d:%s",yours["jing"]/10000,yours["jing"]/10000,yours["eff_jing"]/10000,yours["max_jing"]/10000,"#99990000");
		else
		sp += "║" + sprintf("精神.%d:%d/%d/%d:%s",yours["jing"],yours["jing"],yours["eff_jing"],yours["max_jing"],"#99990000");
		
		sp += "║" + sprintf("精力.%d:%d/%d/%d:%s",yours["jingli"],yours["jingli"],yours["max_jingli"],ob->query_current_jingli_limit(),"#990066CC");	
			if (intp(tar[x]->query_busy()))
			sp += "║" + sprintf("忙乱.%d:%d/1:%s",tar[x]->query_busy(),1,"#BB3F51B5");
			else
			sp += "║"+sprintf("%s:100/100:%s","忙乱：+∞","#BB3F51B5");				
		}
			
			sp += "\n";
		tell_object(me, sp);
			return 1;
			}
		else
		{		
			//1姓名
		if(me->query("web"))
		sp  = ZJHPTXT+ZJMENUF(5,5,25,40)+sprintf("姓名：%s:100/100:%s",name,"#336666");		
		else
		sp  = "\n"+ZJHPTXT+ZJMENUF(5,5,25,40)+sprintf("姓名：%s:100/100:%s",name,"#336666");		
		sp += "║" + sprintf("气血.%d:%d/%d/%d:%s:%s",my["qi"],my["qi"],my["eff_qi"],my["max_qi"],"#99FF0000","exert recover");
		//3精神
		sp += "║" + sprintf("精神.%d:%d/%d/%d:%s:%s",my["jing"],my["jing"],my["eff_jing"],my["max_jing"],"#99990000","exert regenerate");//FFFFCC//
		//4潜能
		sp += "║" + sprintf("潜能.%d:%d/%d/%d:%s",my["potential"]-my["learned_points"],my["potential"]-my["learned_points"],ob->query_potential_limit(),ob->query_potential_limit(),"#99669900");//FF00FF
		//5经验
		if(exp>10000)
		sp += "║" + sprintf("经验(万).%d:%d/%d:%s:%s",exp,exp,F_LEVEL->level_max_exp(ob)/10000,"#996633FF","abandon exp");
		else
		sp += "║" + sprintf("经验.%d:%d/%d:%s:%s",my["combat_exp"],my["combat_exp"],my["combat_exp"],"#996633FF","abandon exp");		
		//二行1怒气
		sp += "║" + sprintf("怒气.%d:%d/%d:%s:%s",ob->query_craze(),ob->query_craze(),ob->query_max_craze(),"#99990000","berserk");		
		//二行2内力
		sp += "║" + sprintf("内力.%d:%d/%d/%d:%s",my["neili"],my["neili"],my["max_neili"],ob->query_current_neili_limit(),"#990066FF");		
		//二行3精力
		sp += "║" + sprintf("精力.%d:%d/%d/%d:%s",my["jingli"],my["jingli"],my["max_jingli"],ob->query_current_jingli_limit(),"#990066CC");			
		//三行4/5食物
		sp += "║" + sprintf("食物.%d:%d/%d:%s",my["food"],my["food"],ob->max_food_capacity(),"#99FF6600");	
		sp += "║" + sprintf("饮水.%d:%d/%d:%s",my["water"],my["water"],ob->max_water_capacity(),"#99CCCC66");
		sp += "\n";
		tell_object(me, sp);
	return 1;
	}
	
	
	
	
}

int help(object me)
{
	write(@HELP
指令格式 : hp
	  hp <对象名称>		  (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP );
    return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
