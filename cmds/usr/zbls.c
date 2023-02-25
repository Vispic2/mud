
#include <ansi.h>

int main(object me, string arg)
{
	string pops,com1,com2;	
	object *obs;
	int i;
	
	if(arg){
		
		if(sscanf(arg,"%s %s",com1,com2)==2){
			if(com1 == "wield" || com1 == "wear" || com1 == "unwield" || com1 == "remove"){
				me->force_me(com1 + " " + com2);
				me->force_me("arm");
			}
			return 1;
		}
		
		pops = ZJOBLONG"请选择要装备的物品：\n" + ZJOBACTS2+ZJMENUF(2,2,8,30);
		
		obs = all_inventory(me);
		if(sizeof(obs)){			
			
			if(arg == "wuqi"){
				for(i = 0; i < sizeof(obs); i++){
					if(me->query_temp("weapon")==obs[i] && stringp(obs[i]->query("skill_type")) && !obs[i]->query("no_wield") && obs[i]->query("consistence")){
						pops += obs[i]->query("name")+" (已装备)"+ZJBR+"攻击力："+obs[i]->query("weapon_prop/damage")+":look "+file_name(obs[i]) + ZJSEP;
						pops += "放下  "+obs[i]->query("name")+":zbls unwield " +file_name(obs[i]) + ZJSEP;
					}
				}

				for(i = 0; i < sizeof(obs); i++){
					if(me->query_temp("weapon")!=obs[i] && stringp(obs[i]->query("skill_type")) && !obs[i]->query("no_wield") && obs[i]->query("consistence")){
						pops += obs[i]->query("name")+ZJBR+"攻击力："+obs[i]->query("weapon_prop/damage")+":zbls wield " +file_name(obs[i]) + ZJSEP;
					}
				}
				
			}else{
				for(i = 0; i < sizeof(obs); i++){
					if(me->query_temp("armor/"+arg)==obs[i] && obs[i]->query("armor_type") == arg && obs[i]->query("consistence")){
						pops += obs[i]->query("name")+" (已装备)"+ZJBR+"防御力："+obs[i]->query("armor_prop/armor")+":look " +file_name(obs[i]) + ZJSEP;
						pops += "脱下  "+obs[i]->query("name")+":zbls remove " +file_name(obs[i]) + ZJSEP;
					}
				}

				for(i = 0; i < sizeof(obs); i++){
					if(me->query_temp("armor/"+arg)!=obs[i] && obs[i]->query("armor_type") == arg && obs[i]->query("consistence")){
						pops += obs[i]->query("name")+ZJBR+"防御力："+obs[i]->query("armor_prop/armor")+":zbls wear " +file_name(obs[i]) + ZJSEP;
					}
				}				
			}					

		}
		
		pops += "返  回:arm\n";
		write(pops);
		return 1;		
	}
	
	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
