#include <ansi.h> 
#include <combat.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int potential_lv(int exp);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);
int main(object me, string arg)
{
	object ob;
	int craze;
	mapping my;
	string str,strs,skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points;
	
	seteuid(getuid());
	if(!arg) ob = me;
	else if (wizardp(me)) 
	{ 
	     ob = present(arg, environment(me));
	     if (!ob) ob = find_player(arg);
	     if (!ob) ob = find_living(arg);
	     if (!ob) return notify_fail("您要察看谁的状态？\n");
	} 
	else return notify_fail("只有巫师才可以察看别人的状态。\n");
	//if(me->query("jkzt") >= 1)
	//{
	my = ob->query_entire_dbase();
	if (my["max_jing"] < 1 || my["max_qi"] < 1)
	return notify_fail("无法察看" + ob->name(1) + "的状态。\n");
	str = ZJOBLONG;
//str =ZJMAPTXT;
	str += sprintf("姓名：%s ("HIG"%s"NOR") "NOR"",ob->name(),capitalize(ob->query("id")));
	str += (HIY"	Level : "+HIG+ob->query("level")+ZJURL("cmds:uplv -l")+ZJSIZE(26)+HIY"【角色等级】"NOR"\n");
	str += sprintf(HIG"≡"HIY"一一一一一一一一一一一一一一一一一一一一≡"NOR"\n");

     
	str += sprintf(HIR"〖气血〗：%s%d/%d%s(%d%%)"NOR"\n",status_color(my["qi"],my["eff_qi"]),my["qi"],my["eff_qi"],
		status_color(my["eff_qi"],my["max_qi"]),my["eff_qi"]*100/(my["max_qi"]+ob->query_gain_qi()));
	
	str += sprintf(HIR"〖内力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],my["jiali"]);
	str += sprintf(HIR"〖精神〗：%s%d/%d%s(%d%%)"NOR"\n",status_color(my["jing"],my["eff_jing"]),my["jing"],
	my["eff_jing"],status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
	str += sprintf(HIR"〖精力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["jingli"],my["max_jingli"]),
    my["jingli"],my["max_jingli"],my["jiajing"]);
	str += sprintf(CYN"〖食物〗：%s%d/%d[%d%%]"NOR"\n",status_color(my["food"], ob->max_food_capacity()),
	my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
	str += sprintf(CYN"〖饮水〗：%s%d/%d[%d%%]"NOR"\n",status_color(my["water"], ob->max_water_capacity()),
	my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());
	str += sprintf(CYN"〖潜能〗：%s%d/%d(max)"NOR"\n",HIY,(int)ob->query("potential")- (int)ob->query("learned_points"),(int)ob->query_potential_limit() - (int)ob->query("learned_points"));
	str += sprintf(CYN"〖经验〗：%s%d/%d(up)"NOR"\n",HIM,my["combat_exp"],F_LEVEL->level_max_exp(ob));
	str += sprintf(HIG"≡"HIY"一一一一一一一一一一一一一一一一一一一一≡\n");
	
	if (craze = ob->query_craze()){
		if (ob->is_most_craze()){ 
			str += (HIR"【愤　"+HIY"　怒"+NOR+HIR"】");
			str += sprintf("%s", ob->query("character") == "光明磊落" ? MAG"  竖发冲冠  ( burning 燃烧怒气 )"+NOR+"\n"
										    : HIM"  怒火中烧  ( burning 燃烧怒气 )"+NOR+"\n");
		}
		else
		{
			str += sprintf(HIR "【愤　　怒】：%d/%d(+%d)\n",craze, ob->query_max_craze(),
				      ob->query("jianu"));
		}
	} 
      else
	{
		 str += sprintf(MAG "【心平气和】：一一一一一一一一一一一"NOR"\n");
	}
   	 
	str += sprintf(MAG "【实战体会】：%s%d/%d"NOR"\n"MAG"【内精极限】：%s%d/%d"NOR"\n",HIM,my["experience"]- my["learned_experience"],ob->query_experience_limit() - my["learned_experience"] ,HIM,ob->query_neili_limit(),ob->query_jingli_limit());
    str += sprintf(HIG"★"HIY+ZJURL("cmds:uplv -t")+ZJSIZE(20)+"天 赋 点 ""/"HIM+ZJURL("cmds:uplv -s")+ZJSIZE(20)+"技 能 点"HIG"★( "HIY+ob->query("tianfu_point")+"/"HIM+ob->query("skill_point")+HIG" )"NOR"\n");
	str += sprintf(HIG"≡"HIY"一一一一一一一一一一一一一一一一一一一一≡"NOR"\n");
	
	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];
	str += "\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,28);
	// str +=
	// HIG"修改密码"NOR":changepasswd";
	message("vision", "\n"+str+"\n", me);
	
	
	
	/*
	}else
	{		
    my = ob->query_entire_dbase();
	if (my["max_jing"] < 1 || my["max_qi"] < 1)
	return notify_fail("无法察看" + ob->name(1) + "的状态。\n");
    str = ZJOBLONG;
	str += sprintf("姓名：%s ("HIG"%s"NOR") ",ob->name(),capitalize(ob->query("id")));
	str += (HIY"	Level : "+HIG+ob->query("level")+ZJURL("cmds:uplv -l")+ZJSIZE(26)+HIY"\t【角色等级】""\n");
	str += sprintf(HIG"≡"HIY"一一一一一一一一一一一一一一一一一一一一≡\n");
	

	str += sprintf(HIR"〖气血〗：%s%d/%d%s(%d%%)\n",status_color(my["qi"],my["eff_qi"]),my["qi"],my["eff_qi"],
		status_color(my["eff_qi"],my["max_qi"]),my["eff_qi"]*100/(my["max_qi"]+ob->query_gain_qi()));
	
	str += sprintf(HIR"〖内力〗：%s%d/%d(+%d)""\n",status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],my["jiali"]);
	str += sprintf(HIR"〖精神〗：%s%d/%d%s(%d%%)\n",status_color(my["jing"],my["eff_jing"]),my["jing"],
	my["eff_jing"],status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
	str += sprintf(HIR"〖精力〗：%s%d/%d(+%d)""\n",status_color(my["jingli"],my["max_jingli"]),
    my["jingli"],my["max_jingli"],my["jiajing"]);
	str += sprintf(CYN"〖食物〗：%s%d/%d[%d%%]\n",status_color(my["food"], ob->max_food_capacity()),
	my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
	str += sprintf(CYN"〖饮水〗：%s%d/%d[%d%%]\n",status_color(my["water"], ob->max_water_capacity()),
	my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());
	str += sprintf(CYN"〖潜能〗：%s%d/%d(max)""\n",HIY,(int)ob->query("potential")- (int)ob->query("learned_points"),(int)ob->query_potential_limit() - (int)ob->query("learned_points"));
	str += sprintf(CYN"〖经验〗：%s%d/%d(up)""\n",HIM,my["combat_exp"],F_LEVEL->level_max_exp(ob));
	str += sprintf(HIG"≡"HIY"一一一一一一一一一一一一一一一一一一一一≡\n");

	if (craze = ob->query_craze())
	{
		if (ob->is_most_craze())
		{ 
			str += (HIR"【愤　"+HIY"　怒"+NOR+HIR"】");
			str += sprintf("%s", ob->query("character") == "光明磊落" ? MAG"  竖发冲冠  ( burning 燃烧怒气 )"+NOR+"\n"
										    : HIM"  怒火中烧  ( burning 燃烧怒气 )"+NOR+"\n");
		}
		else
		{
			str += sprintf(HIR "【愤　　怒】：%d/%d(+%d)\n",craze, ob->query_max_craze(),
				      ob->query("jianu"));
		}
	} 
      else
	{
		 str += sprintf(MAG "【心平气和】：一一一一一一一一一一一\n");
	}
     
	 
	str += sprintf(MAG "【实战体会】：%s%d/%d\n【内精极限】：%s%d/%d""\n",HIM,my["experience"]- my["learned_experience"],ob->query_experience_limit() - my["learned_experience"] ,HIM,ob->query_neili_limit(),ob->query_jingli_limit());
	str += sprintf(HIG"★"HIY+ZJURL("cmds:uplv -t")+ZJSIZE(20)+"天 赋 点 ""/"HIM+ZJURL("cmds:uplv -s")+ZJSIZE(20)+"技 能 点"HIG"★( "HIY+ob->query("tianfu_point")+"/"HIM+ob->query("skill_point")+HIG" )""\n");
	str += sprintf(HIG"≡"HIY"一一一一一一一一一一一一一一一一一一一一≡\n");
	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
	str = str[0..(strlen(str)-5)];

	str += "\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,28);
	str +=
	HIG"修改密码"NOR":changepasswd";
	message("vision", "\n"+str+"\n", me);
	
	me->set("jkzt",1);
	me->add("combat_exp",1000);
	me->add("potential",1000);
	me->set("food",50);
	me->set("water",50);
	write(HIC"干的不错，你被奖励了一千点经验，一千点潜能！\n");
	write("\n");
	write("\n");	
	write(HIG"你现在又饿又渴，看看在这里能否找到些吃的喝的。\n");
	write("\n");
	write("\n");
	}
	*/
	return 1;
}
string status_color(int current, int max)
{
	int percent;
	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
int potential_lv(int level)
{
	int grade;
	grade =level/5+1;
	return grade;
}


string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 12;

        if( max == 0 ) max = 1;
        n = val * 100 / max / 10;
        eff_n = eff * 100 / max / 10;

        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;

        ret = NOR  + bcolor + fcolor ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += dcolor;
                if( i < n )  ret += "━";
                else ret += HIW"━"NOR;
        }
        ret += fcolor + NOR ;
        return ret;
}
int help(object me)
{
	write(@HELP
指令格式 : hp
	   hp <对象名称>		   (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
