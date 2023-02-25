//edit by rock
//2008.10.16
//镜像房间内存

#include <ansi.h>
inherit ITEM;

#include "/test/j.h"

#define SYSTEAM "/test/j_sys"

void create() { set_name("镜像房间内存",({ "jmem"})); }

//心跳(小心准备 误差为30秒)
varargs void heart(int open)
{
	int i,size,index=0,leave_user=0;
	object me,player,*players = ({ }),*team = ({ });
	mapping userId;
	string str;

	me = this_object();

	userId = me->query("user_id");
	size = sizeof(userId);
	for(i=0;i<size;i++)
	{
		str = userId[sprintf("%d",i)];
		if(!str || !stringp(str))
		{
			leave_user++;
			continue;
		}
		player = find_player(str);

		if((!player || (!environment(player)->is_jfb()) && !open))
		{
			me->set(sprintf("user_id/%d",i),0);
			continue;
		}
		if(player) team += ({ player });
	}

	//玩家离开副本
	if(leave_user >= size)
	{
		if(me->delete_map())
		{
			destruct(me);
			return;
		}
	}
	if(me->query("make_jboss") > 980 && !me->query("make_npc5"))
	{
		SYSTEAM->make_jkiller(team,0);
		me->set("make_npc5",1);
	}
	else if(me->query("make_jboss") > 750 && !me->query("make_npc4"))
	{
		SYSTEAM->make_jkiller(team,0);
		me->set("make_npc4",1);
	}
	else if(me->query("make_jboss") > 550 && !me->query("make_npc3"))
	{
		SYSTEAM->make_jkiller(team,0);
		me->set("make_npc3",1);
	}
	else if(me->query("make_jboss") > 350 && !me->query("make_npc2"))
	{
		SYSTEAM->make_jkiller(team,0);
		me->set("make_npc2",1);
	}
	else if(me->query("make_jboss") > 150 && !me->query("make_npc1"))
	{
		SYSTEAM->make_jkiller(team,0);
		me->set("make_npc1",1);
	}

	if(me->query("make_jboss") >= 1000 && !me->query("send_jboss"))
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,BLINK+HIR"请各位小心。\n"NOR);
			players += ({ player });
		}
		SYSTEAM->make_jkiller(players,1);
		me->set("send_jboss",1);
	}

	//已到副本生存期限
	if(me->query("jfbb_time") <= time())
	{
		for(i=0;i<size;i++)
		{
			str = userId[sprintf("%d",i)];
			if(!str || !stringp(str)) continue;
			player = find_player(str);
			tell_object(player,BLINK+HIG"心魔镜像已经瓦解。\n"NOR);
		}
		if(me->delete_map())
		{
			destruct(me);
			return;
		}
	}

	call_out("heart",30);
}

//删除虚拟地图
int delete_map()
{
	int i,size,j,size2;
	mapping maps;
	object me,map,*objs;

	me = this_object();
	maps = (mapping)me->query("maps");
	size = sizeof(maps);


	for(i=0;i<size;i++)
	{
		if(!map = (object)maps[sprintf("%d",i)] || !clonep(map)) continue;
		if(!objs = all_inventory(map) || !arrayp(objs)) continue;
		
		//找出房间内的物品,并且删除之
		size2 = sizeof(objs);
		for(j=0;j<size2;j++)
		{
			if(!objectp(objs[j])) continue;
			if(userp(environment(objs[j]))) continue;//不能删除玩家身上的物品
			//如果是玩家,移动到安全的地方
	if(userp(objs[j]))
			{
				tell_object(objs[j],HIY"挑战开始.....................\n"NOR);
			objs[j]->move("/d/city/kedian");
				continue;
			}
			destruct(objs[j]);
		}
		destruct(map);
	}
	return 1;
}

//连通地图
varargs int len_1()
{
	object me,map;
	mapping room_exits,maps,exit;
	string fileName,mapfile,file,*dirs,temp,temp1,name;
	int i,size,j,size2,size3;
	
	me = this_object();
	maps = me->query("maps");
	size = sizeof(maps);

		for(i=0;i<size;i++)
		{
			map = maps[sprintf("%d",i)];
	
			if(!clonep(map)) continue;   //物件载入失败<注意危险,如果list不对,玩家有可能走到正本.这里只为防止报错>
	
			room_exits = map->query("exits");

			dirs = keys(room_exits);
			size2 = sizeof(dirs);
			for(j=0;j<size2;j++)
			{
				file = room_exits[dirs[j]];
				sscanf(file,"/test/room/%s",fileName);

				mapfile = sprintf("/%O",me->query(fileName));

				if(strsrch(mapfile,"#") == -1 || !fileName || !stringp(fileName))
				{
					mapfile = sprintf("/%O",map);
				}
				exit = room_exits; exit[dirs[j]] = mapfile;

	
			}
			map->set("exits",exit);
		}

	
}

void quest_over()
{
	call_out("quest_over_1",60);
}

void quest_over_1()
{
	int size,i;
	mapping userId;
	
	object me = this_object();
	
	userId = me->query("user_id");
	size = sizeof(userId);
	for(i=0;i<size;i++)
	{
		me->set(sprintf("user_id/%d",i),0);
	}

}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
