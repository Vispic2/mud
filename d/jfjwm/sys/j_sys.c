//edit by xajha
//2020.03.12
//适合多人的镜像房间创建器

#include <ansi.h>

#include <localtime.h>
#include "/d/jfjwm/sys/j.h"							//房间的数组

#define jfjwm_JMEM      "/d/jfjwm/sys/jmem"			//内存管理器
#define JKILLER_NPC     "/d/jfjwm/npc/dizhi"		//普通怪物
#define MAX_KILLER_INDEX 25							//npc的基本个数
#define CU_TIME 3600								//副本持续时间


//全局变量
int make_room_index;//副本的最大数量
mapping rooms = ([]);

//函数声明
int jfjwm(object leader, object *team,int zd,int xs);
int make_jkiller(object me,int bs,int rs,int zd);
void lian_room();
int delete_map();
void go_fuben(object me, object start_room, object jmem, object *team,int npcsl);

//函数：查询现有量镜像数量
int query_room_amount() { return make_room_index; }

//NPC调用，创造镜像世界
int jfjwm(object leader, object *team,int zd,int xs)//多人
{
	object maps,jmem,start_room;
	int size,j,index,npcsl;
	string fileName;
	 
	//创建内存
	if(!jmem = new(jfjwm_JMEM)){
		write("调用内存管理器失败");
		return 0;
	}

	//制造世界
	size = sizeof(room_maps);//读取个数
	for(j=0;j<size;j++)//开始循环制作房间
	{
		maps = new(room_maps[j]);//制作房间
		if(maps)
		{
			maps->set_temp("quest_ob",1);
			maps->set_temp("no_flyto",1);
			sscanf(room_maps[j],"/d/jfjwm/room/%s",fileName);
			rooms[fileName] = maps;
			jmem->set(sprintf("maps/%d",j),maps);
			
			if(maps->query("short") == "入口")//如果这个房间的short是入口，那么作为初始房间
			{
				start_room = maps;
				//tell_object(leader,"已找到开始房间。\n");
			}
			index ++;
		}
	}
	
	if(index < size || !start_room)
	{
		tell_object(leader,"Error: 中级副本JOB制造失败，请联系巫师。\n");
		delete_map();
		destruct(jmem);
		leader->enable_player();
		return 0;
	}else{
		make_room_index ++;
		
		lian_room();
		
		if(sizeof(team)){
			npcsl=make_jkiller(leader,xs,sizeof(team),zd);
		}else{
			npcsl=make_jkiller(leader,xs,1,zd);
		}
		
		go_fuben(leader,start_room,jmem,team,npcsl);//直接进入副本
	}
	return 1;
}

void lian_room()
{
	object map;
	mapping room_exits,exit;
	string fileName,*dirs,*roomkey;
	int i,j,size1,size2;

	if(sizeof(roomkey = keys(rooms))){
		
		size1 = sizeof(roomkey);
		for(i=0;i<size1;i++){
			
			map = rooms[roomkey[i]];
			
			room_exits = map->query("exits");
			exit = room_exits;
			
			dirs = keys(room_exits);
			size2 = sizeof(dirs);
			
			for(j=0;j<size2;j++)
			{
				fileName = room_exits[dirs[j]];
				//sscanf(file,"/d/jfjwm/room/%s",fileName);
				exit[dirs[j]] = "/"+rooms[fileName];
			}
			map->set("exits",exit);			
		}
	}
	
}

//传送至副本
void go_fuben(object me, object start_room, object jmem, object *team,int npcsl)
{
	object ob;
	string *list=({});
	
	if(team){
		foreach (ob in team)
		{
			ob->move(start_room);
			tell_object(ob,HIY"【天之下】这位英雄你已经来到了精武演练副本中,共有"+npcsl+"个弟子，只有"+to_int(CU_TIME/60)+"分钟时限，请抓紧时间。\n"NOR); //广告
			list += ({ ob->query("id") });
		}
		jmem->startbeat(list,time()+CU_TIME);  //启动心跳
	}else{
		me->move(start_room);
		tell_object(me,HIY"【天之下】这位英雄你已经来到了精武演练副本中，共有"+npcsl+"个弟子，只有"+to_int(CU_TIME/60)+"分钟时限，请抓紧时间。\n"NOR); //广告
		jmem->startbeat(({ me->query("id") }),time()+CU_TIME);  //启动心跳
	}	
}

varargs int make_jkiller(object me,int xs,int rs,int zd)//制作怪
{
	int i,fou;

	object killer,rand_map;
	string *roomkey;

	i = MAX_KILLER_INDEX + rs*5;

	while(i--)
	{
		if(killer = new(JKILLER_NPC))
		{

			roomkey = keys(rooms);
			
			//rand_map = rooms[roomkey[random(size)]];  //随机地图
			
			rand_map = rooms[element_of(roomkey)];  //随机地图专用随机函数

			killer->set_martial(random(21));
			killer->do_copy_player(me,xs);
			//killer->set("auto_perform",1);//自动绝招
			
			if(zd) killer->set("zd",1);
			
			killer->move(rand_map);
			fou++;
		}
	}
	
	return fou;
}


//删除虚拟地图
int delete_map()
{
	int i,size;
	object map;
	string *roomkey;
	
	roomkey = keys(rooms);
	
	size = sizeof(roomkey);

	for(i=0;i<size;i++)
	{
		if(!(map = rooms[roomkey[i]])) continue;
		destruct(map);
	}
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
