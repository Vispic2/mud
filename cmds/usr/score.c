 // score.c
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
int shuxing(object ob,string arg);
string bar_string = "■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□";
string blank_string3 = "□□□□□□□□□□□□";
string blank_string2 = "　　　　　　　　　　　　";
mapping oprank = ([
	"宗师"     : HIW "宗师境界  ",
	"登峰造极" : HIY "★★★★☆",
	"超凡脱俗" : HIY "★★★★  ",
	"臻至化境" : HIR "★★★☆  ",
	"炉火纯青" : HIR "★★★    ",
	"已有大成" : HIC "★★☆    ",
	"非同凡响" : HIC "★★      ",
	"出类拔萃" : HIG "★☆      ",
	"身手不凡" : HIG "★	",
	"已有小成" : HIM "☆	",
]);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my,mci;
	int age, rmb, month,i;
	string line, str, race, skill_type,*skill_str;
	object weapon;
	int attack_points, dodge_points, parry_points;
    int lvl, comexp,x;
    int qis,jings;
    string msg;
    int len = 0;
    int time;
    time = time();
     comexp = me->query("combat_exp");
     for(x=0;comexp>(x/10)*x*x;x++)
     lvl = x+1;
	seteuid(getuid(me));
	if (! arg)
		ob = me;

    	else if (wizardp(me))
  	   {
		ob = present(arg, environment(me));
		if (! ob || ! ob->is_character()) ob = find_player(arg);
		if (! ob || ! ob->is_character()) ob = find_living(arg);
		if (! ob || ! ob->is_character())
		return notify_fail("你要察看谁的状态？\n");
     	} else
		return notify_fail("只有巫师能察看别人的状态。\n");

    	my = ob->query_entire_dbase();
    	mci = my["combat"];
    	if (! mci) mci = ([ ]);

	    if (playerp(ob) && (! stringp(my["born"]) || ! my["born"]))
		return notify_fail("还没有出生呐，察看什么？\n");

	    if (my["max_jing"] < 1 || my["max_qi"] < 1)
		return notify_fail("无法察看" + ob->name(1) + "的状态。\n");
	    line=ZJOBLONG;
	    //line=ZJMAPTXT;
        line += sprintf(  "%s"  "%s"ZJBR"", RANK_D->query_rank(ob), ob->short(1) );
        ob->update_age();
        line += sprintf( YEL "━━━━━━━━━━━━━━━━━━━━━━━"NOR"\n"  );  


			
		line += sprintf( YEL  "【种族】" HIW"%-26.8s     "NOR"\n"  , ob->query("race"));		
        line += sprintf( YEL  "【性别】" HIW"%-26.8s     "NOR"\n"  , ob->query("gender"));		
        line += sprintf( YEL  "【性格】" HIW"%-28.28s    "NOR"\n"  , ob->query("character")?ob->query("character"):"暂无性格");
              if (my["born_family"] && my["born_family"] != "没有")
		{
			line += YEL "【家族】"HIG + my["born_family"]+NOR" \n";
		}
		else
		 if (stringp(my["born"]) && my["born"])
		{
			line += YEL "【人氏】" HIG+ my["born"] +NOR" \n";
		}
		else
		{
			line += HIG " 暂无人氏";
		}	
        line += sprintf( YEL  "【门派】" HIG "%-18.8s"NOR"\n" ,ob->query("family/family_name")?ob->query("family/family_name"):"暂无门派" );
        line += sprintf( YEL  "【师承】" HIG"%-18.18s"NOR"\n" ,  ob->query("family/master_name")?ob->query("family/master_name"):"暂无师傅" );
        line +=sprintf(  YEL  "【帮派】" HIG"%-18.18s"NOR"\n",ob->query("banghui/names")?ob->query("banghui/name"):"暂无帮会");
        line +=sprintf(  YEL  "【坐骑】" HIG"%-18.18s"NOR"\n",ob->query("huanshou")?ob->query("beast/beast_name"):"暂无坐骑");        
        line +=sprintf(  YEL  "【随从】" HIG"%-18.18s"NOR"\n",ob->query("scs")?ob->query("namesuicong"):"暂无随从");
        line +=sprintf(  YEL  "【宠物】" HIG"%-18.18s"NOR"\n",ob->query("petname")?ob->query("petname"):"暂无宠物");
                

        if (playerp(ob))
        {
                age = ob->query("age");
                month = ob->query("mud_age");
                if (age >= 60)
                {
                        month -= (age - 60) * 86400 * 4;
                        month = (month - 118 * 86400) / 7200 / 4 + 1;
                } else
                if (age >= 30)
                {
                        month -= (age - 30) * 86400 * 3;
                        month = (month - 28 * 86400) / 7200 / 3 + 1;
                } else
                if (age >= 18)
                {
                        month -= (age - 18) * 86400 * 2;
                        month = (month - 4 * 86400) / 7200 / 2 + 1;
                } else
                {
                        month -= (age - 14) * 86400;
                        month = month / 7200 + 1;
                }              
                if (month > 12 || month < 1)
                        month = 1;        
        line += sprintf( YEL "【年龄】"MAG  "%-24s     "NOR"\n", chinese_number(age) + "岁" +chinese_number(month) + "个月");
        line += sprintf( YEL "【生辰】"MAG  "%-28.28s  "NOR"\n", CHINESE_D->chinese_date(ob->query("birthday")));
        
        
        skill_str=keys(ob->query("special_skill"));
		line +=YEL"【天赋】"NOR;
		for(i=0; i<sizeof(skill_str); i++){
		line +=HIC"【"+ZJSIZE(25)+ZJURL("cmds:special "+skill_str[i]+"")+SPECIAL_D(skill_str[i])->name()+HIC"】"NOR"";
		 }
        } 
  ///////
        line += sprintf( YEL "\n┣━━━━━━━━━━━━━━━━━━━━━┫"NOR"\n" );   
        if(ob->query("zjvip/level"))
        {
        line += HIY "【会员等级】"+ob->query("zjvip/level")+ ""NOR"\n";
        }else
        {
        line += HIY "【会员等级】无"NOR"\n";
        }
        if ((int)ob->query("zhuanshi") > 0)
        {
		line += HIY "【转世次数】" + (ob->query("zhuanshi")) + ""NOR"\n";  		
		}else{
		line += HIY "【转世次数】无"NOR"\n";
		}
		/*
	    if(ob->query("zjvip/all_pay") <1)
	    {
        line += sprintf( HIY "【充值贡献】%s"NOR"\n",ob->query("zjvip/all_pay")?ob->query("zjvip/all_pay"):"暂无贡献");        
        }else{
        line += sprintf( HIY "【充值贡献】%d"NOR"\n",ob->query("zjvip/all_pay")?ob->query("zjvip/all_pay"):"暂无贡献");
        }*/
        if ((int)ob->query("yuanbao") > 0)
        {
		line += HIY "【目前元宝】" + (ob->query("yuanbao")) + ""NOR"\n";
        }else
        {
        line += HIY "【目前元宝】暂无元宝"NOR"\n";
        }
		if ((int)ob->query("balance") > 0)
		{
		line += HIY "【目前存款】" + MONEY_D->money_str((int)ob->query("balance")) + ""NOR"\n";
		}
		else
		{
		line += HIY "【目前存款】暂无存款"NOR"\n";
		}		
			if ((int)ob->query("zjvip/times") > 0)
		{
			line += HIY "【会员时间】"+CHINESE_D->short_time(ob->query("zjvip/times"))+ ""NOR"\n";
		}
             line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );   
             
             line += sprintf( HIY "【膂力】：" HIW "%4d |%4d "NOR+ HIY "【悟性】：" HIW "%2d |%4d" NOR "  \n"  ,ob->query("str"),ob->query_str(), ob->query("int"),ob->query_int());

             line += sprintf( HIY "【根骨】：" HIW "%4d |%4d "NOR+ HIY "【身法】：" HIW "%2d |%4d" NOR "  \n"  , ob->query("con"),ob->query_con(), ob->query("dex"),ob->query_dex());
             
             if(me->query("max_qi") >1&&me->query("jing") >1&&me->query("max_neili") >1)
             {
		     line += sprintf( NOR+HIC "【气血】：%s   "NOR"\n",tribar_graph(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) );
             line += sprintf( NOR+HIC "【内力】：%s   "NOR"\n",tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
             line += sprintf( NOR+HIC "【精神】：%s   "NOR"\n",tribar_graph(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])));
             line += sprintf( NOR+HIC "【食物】：%s   "NOR"\n",tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), HIC));
             line += sprintf( NOR+HIC "【饮水】：%s   "NOR"\n",tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), HIC));
             }
             
             
     ///////        
             
            
	         line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫"NOR"\n" );	        
             
	   
	   if(playerp(ob))
	{
	
	line += HIG "【练体境】"NOR"" ;
		if (ob->query("lt"))
			line += HIC "○"NOR"" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 1")+ZJSIZE(27)+"突  破"NOR"           ";
				
      line += HIG "【练气境】"NOR"" ;
		if (ob->query("lq"))
			line += HIC "○"NOR"\n" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 2")+ZJSIZE(27)+"突  破"NOR"\n";
				
			line += HIC "【筑基境】"NOR"" ;
		if (ob->query("zj"))
			line += HIC "○"NOR"" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 3")+ZJSIZE(27)+"突  破"NOR"           ";
				
		line += HIC "【金丹境】"NOR"" ;
		if (ob->query("jd"))
			line += HIC "○"NOR"\n" ;
		else
		line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 4")+ZJSIZE(27)+"突  破"NOR"\n";
			
		line += HIY "【元婴境】"NOR"" ;
		if (ob->query("yy"))
			line += HIC "○"NOR"" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 5")+ZJSIZE(27)+"突  破"NOR"           ";
			
			
			line += HIY "【合体境】"NOR"" ;
		if (ob->query("ht"))
			line += HIC "○"NOR"\n" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 6")+ZJSIZE(27)+"突  破"NOR"\n";
			
			
			line += HIW "【渡劫境】"NOR"" ;
		if (ob->query("dj"))
			line += HIC "○"NOR"" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 7")+ZJSIZE(27)+"突  破"NOR"           ";
			
			
			line += HIW "【人仙境】"NOR"" ;
		if (ob->query("rx"))
			line += HIC "○"NOR"\n" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:jinjie 8")+ZJSIZE(27)+"突  破"NOR"\n";
			
	
	
    	line += HIY"【任督二脉】"NOR"" ;
		if (my["breakup"])
			line += HIC "○"NOR"" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:breakup")+ZJSIZE(27)+"突  破"NOR"       ";

		line += HIY "【元婴出世】"NOR"" ;
		if (my["animaout"])
			line += HIC "○"NOR"\n" ;
		else
		
			line += HIR "" NOR+HIY+ZJURL("cmds:animaout")+ZJSIZE(27)+"突  破"NOR"\n";
			
		line += HIY "【生死玄关】"NOR"" ;
		if (ob->query("zhuanshi"))
			line += HIC "○"NOR"" ;
		else
			line += HIR "" NOR+HIY+ZJURL("cmds:recall zhuanshi")+ZJSIZE(27)+"突  破"NOR"       ";
		line += HIY "【转世重生】"NOR"" ;
		if (ob->query("zhuanshi"))
			line += HIC "○"NOR"\n" ;
		else 
		line += HIR "" NOR+HIY+ZJURL("cmds:recall zhuanshi")+ZJSIZE(27)+"突  破"NOR"\n";
}
					
		line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫"NOR"\n" );   	
   if (playerp(ob))
	{
		string op;
		

		line += HIY "【拳脚功夫】"NOR"" ;
		if (op = ob->query("opinion/unarmed"))
			line += oprank[op] + "	";
		else
			line += CYN "暂无评价	 ";

		line += NOR HIY "【兵器运用】"NOR"" ;
		if (op = ob->query("opinion/weapon"))
			line += oprank[op] + "	";
		else
			line += CYN "暂无评价";

		line += NOR HIY "\n【内家功夫】"NOR"" ;
		if (op = ob->query("opinion/force"))
			line += oprank[op] + "	";
		else
			line += CYN "暂无评价   ";

		line += NOR HIY "【轻身功夫】"NOR"" ;
		if (op = ob->query("opinion/dodge"))
			line += oprank[op] + "	";
		else
			line += CYN "暂无评价";	
	}	
	//line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );
	    line += sprintf( YEL "" MAG "\n【杀生次数】" NOR HIR"    %d位"NOR,
                (int)mci["MKS"] + (int)mci["PKS"]);
        line += sprintf( YEL "" MAG "       【杀死玩家】" NOR HIR"           %d位\n"NOR,
                (int)mci["PKS"]);
        line += sprintf( YEL "" MAG "【有意杀害】" NOR HIR"    %d位"NOR,
                (int)mci["WPK"]);

        line += sprintf( YEL "" MAG "       【击晕玩家】" NOR HIR"           %d位\n"NOR,
                (int)mci["DPS"]);
        line += sprintf( YEL "" MAG "【正派人士】" NOR HIR"    %d位"NOR,
                (int)mci["DPS_GOOD"]);
        line += sprintf( YEL "" MAG "       【邪派人士】" NOR HIR"           %d位"NOR,
                (int)mci["DPS_BAD"]);
        line += YEL "\n" NOR;

        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );
	if (playerp(ob))
	{
		
	line += sprintf(HIC"【阅   历】  %7d   "NOR"\t",my["score"]);
	line += sprintf(HIC"【贡   献】%7d"NOR"\n",my["gongxian"]);
	line += sprintf(HIC"【威   望】  %7d   "NOR"\t",my["weiwang"]);
	line += sprintf(HIC"【灵   慧】%s%7d"NOR"\n",my["magic_points"] < 100 ? HIC : HIC, (my["magic_points"] - my["magic_learned"]));
	}
		
	if (my["shen"] >= 0)
		line += sprintf(HIM "【正   气】  %7d     "NOR"\t" NOR, my["shen"]);
	else
		line += sprintf(HIM "【邪   气】  %7d     "NOR"\t" NOR, -ob->query("shen"));
line += sprintf(NOR + HIM "【戾   气】%7d"NOR"\t\n"    , my["total_hatred"]);

line += HIM "【容   貌】   ("+ob->query_per()+"/"+ob->query("per")+") 【福   源】    ("+ob->query("kar")+"/"+ob->query("kar")+")"NOR"\n";

	if ((int)mci["dietimes"])
	{
		line += sprintf(HIR "  你到目前为止总共到黑白无常那里串门%s次。"NOR"\n", chinese_number(mci["dietimes"]));
		line += sprintf(HIR "  上次遇害是%s。"NOR"\n", ob->query("combat/last_die"));
		line += "";
	} 
	else
	if (playerp(ob))

		line += HIC "\n  你到目前为止尚无死亡记录。"NOR"\n";
		

   if (ob->query("birthday"))
	line += HIG "  注册时间："+CHINESE_D->chinese_date(ob->query("birthday"),2)+NOR+"\n";
	   line += YEL "┗━━━━━━━━━━━━━━━【个人档案】━┛\n" NOR;
       line += sprintf( HIW "   现在的时间是" + ctime( time ) + ""NOR);
	line = replace_string(line,"\n",ZJBR);
	if(line[(strlen(line)-4)..(strlen(line)-1)]=="$br#")
		line = line[0..(strlen(line)-5)];
	line += "\n";
	write(line);
	
	
	//write_file("/cmds/usr/score.txt",line,1);
	return 1;
}


string status_color(int current, int max)
{
	int percent;

	if (max) percent = current * 100 / max;
	else percent = 100;

	if (percent > 100) return HIG;
	if (percent >= 90) return HIG;
	if (percent >= 60) return HIC;
	if (percent >= 30) return HIY;
	if (percent >= 10) return HIR;
	return RED;
}


string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*12/max)*2-1]
                + ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
        return BLU + blank_string3[0..(23-a)] + NOR;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
