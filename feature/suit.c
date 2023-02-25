//套装效果的 稚型 实现
//angelus 于 2010年 03/28
//angelus 于 2010年 04/12 最后更改
//  实现思路： 主要应用mpping
/*
	  简单的套装计算   ,, mapping原理很简单，但写起来十分复杂。
*/
#pragma save_binary
#include <tomud.h>
#include <ansi.h>
#include <command.h>

string dis_lvl(int lvl);			  //辅助处理套装等级的显示
string dis_count(int count,int suit_count);	//辅助处理穿着多少显示图象颜色信息
string suit_dis(mapping suit_eff_last,mapping suit_map,mapping suit_lvl,mapping suit_count,mapping suit_skill_last); //显示套装默认效果

mapping sum_eff(object ob,mapping suit_eff);

//主要判断套装函数
mixed suit(object ob,string arg)
{
	//检查身上的各部位参数
	string *armor_type=({"armor/armor","armor/cloth","armor/boots","armor/head","armor/face",
	"armor/wrists","armor/neck","armor/hands","armor/shield","armor/waist","armor/pants",
	"armor/finger","weapon","secondary_weapon",});

	string suit="",str="";   //套装名称
	object obj;		  //装备的物件对象
	mixed map ;  //KEY化统计套装的计数mapping
	mixed map_eff; //KEY化 全部的套装效果mapping
	mixed map_eff_key; //KEY化 去进行 套装效果参数的mapping


	mapping suit_eff=([ ]);  //存储套装全部效果
	mapping suit_count=([ ]);  //存储套装最大部件
	mapping suit_map=([ ]);   //存储计算装备的套件数量
	mapping suit_lvl=([ ]);	 //存储各套装等级

	mapping suit_eff_start=([ ]);  // 处理套装效果的中间辅助mapping
	mapping suit_eff_mid=([ ]);	 //处理套装效果的中间辅助mapping
	mapping suit_eff_last=([ ]);   // 处理后的套装效果

	mapping suit_skill=([ ]); //
	mapping suit_skill_last=([ ]);//
	//50
	int i;  //循环时的变量 //因为有多层循环，所以定义多个参数
	int j;
	int k;

	//计算身上装备的各套装 各自的数量，名称，最大部件数量等，存储在各自mapping 中
	for(i=0;i < sizeof(armor_type);i++)
	{
		if(objectp(obj=ob->query_temp(armor_type[i])))
		{
			if(suit=obj->query("suit"))
			{
				suit_map += ([ suit : suit_map[suit]+1 ]);	 //计算穿着各套装的数量
				suit_eff +=([ suit : obj->query("suit_eff") ])  ;   //返回效果 KEY:mapping
				suit_count +=([ suit : obj->query("suit_count") ])  ;   //套装最大部件数量
				suit_lvl +=([ suit : obj->query("suit_lvl") ])  ;	//套装的等级
				if(obj->query("suit_eff_skill"))
				{
					suit_skill +=([ suit : obj->query("suit_eff_skill") ])  ;  //技能
				}
			}
		}
	}
	//----------处理套装效果----------------------------------------------------------------
	if(sizeof(suit_map))
	{
		map=keys(suit_map); //键值化 suit_map;
		map_eff=keys(suit_eff); //键值化 suit_map;
		for(i=0;i < sizeof(suit_map);i++)	//循环所有穿着的套装
		{
			if(suit_count[map[i]]<=2)
			{
				continue;
			}
			/*
			//装备足够一套的话，给予所有附加效果参数
			if(suit_map[map[i]] == suit_count[map[i]])
			{
				suit_eff_last += ([ map[i] :  suit_eff[ map[i]] ]);
				if(sizeof(suit_skill))
				{
					suit_skill_last += ([ map[i] :  suit_skill[ map[i] ] ]);
				}
			}
			*/
			/*
			//装备够3件的附加效果，规定为《 一个 》附加参数
			if(suit_map[map[i]] < suit_count[map[i]] && suit_map[map[i]] >=3)
			{
				suit_eff_start=([]);   //100
				suit_eff_mid= suit_eff[ map[i] ];
				map_eff_key=keys(suit_eff_mid);
				for(j=0;j < 1;j++)
				{
					suit_eff_start += ([ map_eff_key[j] : suit_eff_mid[ map_eff_key[j] ] ]);
				}
				suit_eff_last += ([ map[i] : suit_eff_start ]);
			}
			
			//装备够5件的附加效果，规定为《 二个 》附加参数
			if(suit_map[map[i]] < suit_count[map[i]] && suit_map[map[i]] >=5)
			{
				suit_eff_start=([]);
				suit_eff_mid= suit_eff[ map[i] ];
				map_eff_key=keys(suit_eff_mid);
				for(j=0;j < 3;j++)
				{
					suit_eff_start += ([ map_eff_key[j] : suit_eff_mid[ map_eff_key[j] ] ]);
				}
				suit_eff_last += ([ map[i] : suit_eff_start ]);
			}
			//装备够7件的附加效果，规定为《 三个 》附加参数
			if(suit_map[map[i]] < suit_count[map[i]] && suit_map[map[i]] >=7)
			{
				suit_eff_start=([]);
				suit_eff_mid= suit_eff[ map[i] ];
				map_eff_key=keys(suit_eff_mid);
				for(j=0;j < 5;j++)
				{   //150
					suit_eff_start += ([ map_eff_key[j] : suit_eff_mid[ map_eff_key[j] ] ]);
				}
				suit_eff_last += ([ map[i] : suit_eff_start ]);
			}
			//装备够9件的附加效果，规定为《 四个 》附加参数
			if(suit_map[map[i]] < suit_count[map[i]] && suit_map[map[i]] >=9)
			{
				suit_eff_start=([]);
				suit_eff_mid= suit_eff[ map[i] ];
				map_eff_key=keys(suit_eff_mid);
				for(j=0;j < 7;j++)
				{
					suit_eff_start += ([ map_eff_key[j] : suit_eff_mid[ map_eff_key[j] ] ]);
				}
				suit_eff_last += ([ map[i] : suit_eff_start ]);
			}
			
			
				//装备够9件的附加效果，规定为《 四个 》附加参数
			if(suit_map[map[i]] < suit_count[map[i]] && suit_map[map[i]] >=12)
			{
				suit_eff_start=([]);
				suit_eff_mid= suit_eff[ map[i] ];
				map_eff_key=keys(suit_eff_mid);
				for(j=0;j < 9;j++)
				{
					suit_eff_start += ([ map_eff_key[j] : suit_eff_mid[ map_eff_key[j] ] ]);
				}
				suit_eff_last += ([ map[i] : suit_eff_start ]);
			}
			
			
			*/

		}
	}
	//-------------------------------------------------------------------------------------

	//返回 穿着套装数量。
	if(arg=="suit_map")
	{
		return suit_map;
	}
	//返回 穿着套装 最大部件数量。
	if(arg=="suit_count")
	{
		return suit_count;
	}
	//返回 穿着套装等级。
	if(arg=="suit_lvl")
	{
		return suit_lvl;
	}
	//返回 穿着套装效果
	if(arg=="suit_eff")
	{
	return suit_eff_last;
	}
	//返回 穿着套装技能效果
	if(arg=="suit_skill")
	{
		return suit_skill_last;
	}
	if(!arg)
	{
		return suit_dis(suit_eff_last,suit_map,suit_lvl,suit_count,suit_skill_last);
	}

}

//默认显示套装数量和效果
string suit_dis(mapping suit_eff_last,mapping suit_map,mapping suit_lvl,mapping suit_count,mapping suit_skill_last)
{
	int i,k;
	string str="";
	mixed map ;  //KEY化统计套装的计数mapping
	mixed map_eff_dis;  //KEY化 取出具体套装的效果
	mixed map_eff_str;  //KEY化 去取出整理后套装效果100
	mixed map_skill_last; //
	mixed map_skill_str;  //

	mapping suit_eff_string=([ ]);  //显示套装效果时中间辅助mapping
	mapping suit_skill_dis=([ ]); //
	if(sizeof(suit_map))
	{
		map=keys(suit_map);	 //键值化 suit_map;
		for(i=0;i<sizeof(suit_map);i++)
		{
			str+= sprintf(HIM"│"NOR"<%s>  %s\n│【等级】:%s \n",map[i],dis_count(suit_map[map[i]],suit_count[map[i]]),dis_lvl((int)suit_lvl[map[i]]));
		}
		if(sizeof(suit_eff_last))
		{
			map_eff_dis=keys(suit_eff_last);
			for(i=0;i < sizeof(suit_eff_last);i++)
			{
				suit_eff_string=suit_eff_last[map_eff_dis[i]];
				map_eff_str=keys(suit_eff_string);
				str+=HIM"│"NOR"<"+map_eff_dis[i]+"> "HIM"『 "NOR;
				for(k=0;k < sizeof(suit_eff_string);k++)
				{
					if(k==4)
					{
						str+=HIM"』"NOR"\n"+HIM+HIM"│"NOR"	 "HIM"  『 "NOR;
					}
					str+=to_chinese(map_eff_str[k])+HIG" ↑"NOR+ suit_eff_string[map_eff_str[k]]+"  ";
				}
				str+=HIM"』"NOR"\n";
			}
		}
		if(sizeof(suit_skill_last))
		{
			map_skill_last=keys(suit_skill_last);
			for(i=0;i<sizeof(suit_skill_last);i++)
			{
				suit_skill_dis=suit_skill_last[map_skill_last[i]];
				map_skill_str=keys(suit_skill_dis);
				str+=HIM"│"NOR"<"+map_skill_last[i]+"> "HIC"『 "NOR;
				for(k=0;k < sizeof(suit_skill_dis);k++)
				{
					str+=to_chinese(map_skill_str[k])+HIG" ↑"NOR+ suit_skill_dis[map_skill_str[k]]+" ";
				}
				str+=HIC"』"NOR"\n";
			}
		}
		return str;
	}
	else return HIM"│"NOR"  套装：---- "HIR" 注：(附加技能生效必须人物先学会)"NOR"\n";
}

//计算套装显示等级
string dis_lvl(int lvl)
{
	int i;
	string lvl_solid= "★";
	string lvl_hollow= "☆" ;
	string dis_str="";

	if(lvl)
	{
		for(i=0;i<lvl;i++)
		{
			dis_str+=lvl_solid;
		}
		for(i=0;i < (5-lvl);i++)
		{
			dis_str+=lvl_hollow;
		}
	}
	switch (lvl)
	{
		case 1 : dis_str=HIG+dis_str+NOR;  break;   //一绿
		case 2 : dis_str=HIB+dis_str+NOR;  break;   //二蓝
		case 3 : dis_str=HIM+dis_str+NOR;  break;   //三紫
		case 4 : dis_str=HIY+dis_str+NOR;  break;   //四黄
		case 5 : dis_str=HIR+dis_str+NOR;  break;   //五红
	}
	return dis_str;
}
//穿着件数显示
string dis_count(int count,int suit_count)
{
	string return_dis="";
	int i;
	string count_dis="◆";
	string suit_count_dis="◇";

	for(i=0;i<count;i++)
	{
		return_dis+=count_dis;
	}
	for(i=0;i<suit_count-count;i++)
	{
		return_dis+=suit_count_dis;
	}
	switch (count)
	{
		case 1 : return_dis=return_dis;  break;
		case 2 : return_dis=HIG+return_dis+NOR+HIG;  break;
		case 3 : return_dis=HIC+return_dis+NOR+HIC;  break;
		case 4 : return_dis=HIB+return_dis+NOR+HIB;  break;
		case 5 : return_dis=HIR+return_dis+NOR+HIR;  break;
		case 6 : return_dis=HIM+return_dis+NOR+HIM;  break;
		case 7 : return_dis=HIY+return_dis+NOR+HIY;  break;
		case 8 : return_dis=YEL+return_dis+NOR+YEL;  break;
	}
	return_dis+=" 【"+count+"/"+suit_count+"】";
	return return_dis;
}

//将maping结构简单化，将所有参数总结起来。
mapping sum_eff(object ob,mapping suit_eff)
{
	int i,k;
	mixed map_key;
	mixed map_str_key;
	mapping sum_suit_eff=([]);
	mapping eff=([]);
	mapping eff_str=([]);

	eff=suit_eff;
	map_key=keys(eff);

	for(i=0;i<sizeof(eff);i++)
	{
		eff_str=eff[map_key[i]];
		map_str_key=keys(eff_str);
		for(k=0;k<sizeof(eff_str);k++)
		{
			if( undefinedp(sum_suit_eff[map_str_key[k]]) )
				sum_suit_eff[map_str_key[k]] = eff_str[map_str_key[k]];   //则添加进sum_suit_eff中
			else
				sum_suit_eff[map_str_key[k]] += eff_str[map_str_key[k]];  //能找到，就合并数据
		}
	}
	return sum_suit_eff;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
