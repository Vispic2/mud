//edit by xajha
//2020.03.12
//适合多人镜像房间的内存管理器

#include <ansi.h>
inherit ITEM;

int check_map();
int delete_map();

void create() { 
	set_name("多人镜像房间内存",({"jmem"}));
}

int clean_up()
{
	return 1;
}

void startbeat(string *list, int time){
	set("list",list);
	set("jstime", time);	
	set_heart_beat(30);
}

//心跳(小心准备 误差为30秒)
void heart_beat()
{
	int s=0;
	int rs;
	string sj;
	object me;
	string *wjlist,wjid;
	
	rs=check_map();
	
	//检查副本里面还有没有人
	if(!rs){
		
		s = delete_map();
		if(s>0)
		{			
			if(sizeof(wjlist = query("list"))>0){
				foreach (wjid in wjlist){
					if(me = find_player(wjid)){
						tell_object(me,"你的精武演练副本已经没有人了，副本已经销毁。\n");		
					}
				}
			}
			destruct(this_object());
			return;
		}		
	}	
	
	s=0;
	
	//已到副本生存期限
	if(query("jstime") <= time())
	{
		s = delete_map();
		if(s>0)
		{			
			if(sizeof(wjlist = query("list"))>0){
				foreach (wjid in wjlist){
					if(me = find_player(wjid)){
						tell_object(me,"你的精武演练副本时间已到，你的副本也已经销毁了。\n");		
						tell_object(me,"副本中"+s+"个场景已经销毁了。\n");
					}
				}
			}			
			
			destruct(this_object());
			return;
		}
	}else{
		if(sizeof(wjlist = query("list"))>0){
			sj = to_int((query("jstime") - time())/60)+" 分钟";
			foreach (wjid in wjlist){
				if(me = find_player(wjid)){
					tell_object(me,ZJTMPSAY"精武演练副本时间还剩：" + sj +"\n");
					tell_object(me,"精武演练副本时间还剩：" + sj + "\n");
				}
			}
		}
	}
}

//删除虚拟地图
int delete_map()
{
	int i,size,j,size2,sou=0;
	mapping maps;
	object map,*objs;

	maps = (mapping)query("maps");
	size = sizeof(maps);

	for(i=0;i<size;i++)
	{
		if(!map = (object)maps[sprintf("%d",i)] || !clonep(map)) continue;
		
		if(objs = all_inventory(map)){		
			
			size2 = sizeof(objs);
			for(j=0;j<size2;j++) //找出房间内的物品,并且删除之
			{
				if(!objectp(objs[j])) continue;
				if(playerp(environment(objs[j]))) continue; //不能删除玩家身上的物品
				
				if(playerp(objs[j])) //如果是玩家,移动到安全的地方
				{
					tell_object(objs[j],HIY"精武演练副本已关闭!!!!。\n"NOR);
					objs[j]->move("/d/city/kedian");
					continue;
				}
				destruct(objs[j]);
			}
		
		}
		destruct(map);
		sou++;
	}
	return sou;
}

//检查虚拟地图还有没有玩家
int check_map()
{
	int i,size,j,size2,sou;
	object map,*objs;
	string *roomkey;
	mapping maps;
	
	maps = (mapping)query("maps");
	roomkey = keys(maps);
	
	size = sizeof(roomkey);
	
	if(!size) return 0;
	
	sou=0;
	
	for(i=0;i<size;i++)
	{
		if(!(map = maps[roomkey[i]])) continue;
		
		if(!(objs = all_inventory(map))) continue;
		
		size2 = sizeof(objs);
		for(j=0;j<size2;j++)
		{
			if(playerp(objs[j]))
			{
				sou++;
				continue;
			}

		}

	}
	return sou;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
