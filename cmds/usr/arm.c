//arm.c

#include <ansi.h>
#include <tomud.h>
#include <combat.h>
inherit F_CLEAN_UP;

string name_temp(object ob,string type);

int main(object me, string arg)
{
	int i;
	object ob;
	mapping prepare;
	int attack_points, dodge_points, parry_points,islook;
	object weapon,second_weapon;
	string line,tmp,wp1,wp2,skill_type;
	if(arg=="suit"){

		line = HIY"一一一一一一一一一套装信息一一一一一一一一一一"NOR+ZJBR;    
		line += replace_string(me->suit(me),"\n","");   

		line += ZJBR+HIY"一一一一一一一一一一一一一一一一一一一一一一一"NOR;    
	write(ZJOBLONG+line+"\n");
	return 1;
	}
	
	if (arg)
	{
		ob = find_player(arg);
		if (! ob) ob = find_living(arg);
		if (! ob) ob = present(arg, environment(me));
		if (! wizardp(me) && (! ob || me->query("couple/child") != ob->query("id"))) 
		{
		      islook=0;   //不是巫师或孩子不能看具体攻击防御数值
		}
		else
		{
		      islook=1;       //可以查看全部数值
		}
		if(!ob)
		{
		     return notify_fail("你要察看谁的装备？\n"); 
		}
	}

	if (! ob)
	{
		ob = me;
	      islook=1;       //可以查看全部数值
	}
	if( ob==me && me->is_ghost() ) 
		return notify_fail("这些身外之物，生不带来，死不带去，还是算了吧！\n");

	line="";
	tmp=ZJOBACTS2+ZJMENUF(2,2,10,30);
	
	//wp1="无:null"ZJSEP;
	if(ob == me){
		wp1=WHT"无 (选择)"NOR":zbls wuqi"+ZJSEP;
	}else{
		wp1=WHT"无"NOR":null"+ZJSEP;
	}
	
	wp2="无:null"ZJSEP;

	weapon= ob->query_temp("weapon");
	second_weapon= ob->query_temp("secondary_weapon");
	if(weapon)
	{ 
		if(ob == me){
			wp1=weapon->query("name")+":zbls wuqi"+ZJSEP;
		}else{
			wp1=weapon->query("name")+":look "+file_name(weapon)+ZJSEP;
		}
	}
	if(second_weapon)
	{
		  wp2=second_weapon->query("name")+":look "+file_name(weapon);
	}

	//line += HIY+" ["+ob->name()+"] 装备了下列物品：      "NOR"\n";		
	
	line += BBLU+" ["+ob->query("name")+"] 装备了下列物品：\n";
	line += sprintf(HIY"一一一一一一一一一一一一一一一一一一一一一一一"NOR"\n");  
	if(islook)
	{
		prepare = me->query_skill_prepare();
		if( objectp(weapon = ob->query_temp("weapon")) )
			skill_type = weapon->query("skill_type");
		else if (prepare&&sizeof(prepare)>0)  skill_type = (keys(prepare))[0];
		else 
			skill_type = "unarmed";

		attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
		parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
		dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
		line += sprintf("│ 战斗攻击力： " HIW "%8d  "NOR" 战斗防御力： " HIW "%8d "NOR"\n",
		attack_points  + 1, (dodge_points + (weapon? parry_points: (parry_points/10)))  + 1);
		if(weapon)
                                line += sprintf("│ 兵器伤害力： " HIC "%8d  "NOR" 装备防护力： "HIC"%8d"NOR"\n", ob->query_temp("apply/damage"),(ob->query_temp("apply/armor")+ob->query_temp("apply/armor1")) );
                                else
                                line += sprintf("│ 兵器伤害力： " HIC "%8d  "NOR" 装备防护力： "HIC"%8d"NOR"\n", ob->query_temp("apply/damage"),(ob->query_temp("apply/armor")+ob->query_temp("apply/armor1")) );
		line += sprintf("│ 真气加伤害： " HIC "%8d  "NOR" 空手伤害力： "HIC"%8d"NOR"\n",(ob->query_gain_damage()+ob->query_gain_damages()), (ob->query_temp("apply/unarmed_damage")));
		line += sprintf(HIY"一一一一一一一一一一一一一一一一一一一一一一一"NOR);  
	} 	
	
	tmp += "[穿戴所有]:wear all"ZJSEP"[脱下所有]:remove all"ZJSEP;
	tmp += sprintf("[头部]：%s[右手]：%s",name_temp(ob,"armor/head"), wp1);
	tmp += sprintf("[护甲]：%s[颈部]：%s", name_temp(ob,"armor/armor"), name_temp(ob,"armor/neck"));
//	tmp += sprintf("[颈部]：%s[外套]：%s", name_temp(ob,"armor/neck"), name_temp(ob,"armor/surcoat"));
	tmp += sprintf("[衣服]：%s[手部]：%s", name_temp(ob,"armor/cloth"), name_temp(ob,"armor/hands"));		
	tmp += sprintf("[腰部]：%s[护腕]：%s",name_temp(ob,"armor/waist"), name_temp(ob,"armor/wrists"));	
	tmp += sprintf("[裤子]：%s[戒指]：%s", name_temp(ob,"armor/pants"),name_temp(ob,"armor/finger"));
	tmp += sprintf("[鞋子]：%s[盾牌]：%s",name_temp(ob,"armor/boots"), name_temp(ob,"armor/shield"));
	tmp += "[召唤装备]:summon"ZJSEP"[套装信息]:arm suit"ZJSEP;
	line = replace_string(line,"\n",ZJBR)+"\n";
	line += tmp;	
	write(ZJOBLONG+line+"\n");
 
	return 1;
}
string name_temp(object ob,string type)
{
	string name,type2;
	object obj;
	
	type2 = replace_string(type,"armor/","");
	
	if( objectp(obj=ob->query_temp(type)) ) 
	{
		//name = obj->query("name")+":look "+file_name(obj)+ZJSEP;
		if(ob == this_player()){
			name = obj->query("name")+":zbls "+type2+ZJSEP;
		}else{
			name = obj->query("name")+":look "+file_name(obj)+ZJSEP;
		}				
	}
	else
	{
		if(ob == this_player()){
			name = WHT"无 (选择)"NOR":zbls "+type2+ZJSEP;
		}else{
			name = WHT"无"NOR":null"+ZJSEP;
		}
	}
	return name;
}

int help (object me)
{
	write(@HELP
指令格式: arm
 
可列出你(你)目前身上所携带的所有物品。
 
 
HELP );
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
