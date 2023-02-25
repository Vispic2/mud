inherit F_DBASE;
#include <localtime.h>

#define NPC_ROOM 20

int start();
object *get_room_arr();
void remove_npc();
void *query_npc();

string zhangmen, enemy;
object *npc_arr = ({});

mapping family_dir = ([
//	CLASS_D("wudang/zhang")   : "/d/wudang",
//	CLASS_D("gaibang/hong")  : "/d/gaibang",
//	CLASS_D("murong/murongfu")   : "/d/morong/",
//by name 修复报错，原因本lib路径不对
	CLASS_D("shaolin/xuan-ci")  : "/d/shaolin/",
	CLASS_D("quanzhen/wang") : "/d/quanzhen/",
	CLASS_D("huashan/yue-buqun")  : "/d/huashan/",
	CLASS_D("duan/duanzm")     : "/d/dali/",
	CLASS_D("xueshan/jiumozhi")  : "/d/xueshan/",
	CLASS_D("lingjiu/xuzhu")  : "/d/lingjiu/",
	CLASS_D("emei/miejue")     : "/d/emei/",
	CLASS_D("taohua/huang")   : "/d/taohua/",
	CLASS_D("shenlong/hong") : "/d/shenlong/",
	CLASS_D("gumu/longnv")     : "/d/gumu/",
	CLASS_D("xingxiu/ding")  : "/d/xingxiu/",
	CLASS_D("xiaoyao/xiaoyaozi")  : "/d/xiaoyao/",
	CLASS_D("xuedao/laozu")   : "/d/xuedao/",	
	CLASS_D("ouyang/ouyangfeng")   : "/d/baituo/",	
	CLASS_D("hu/hufei")       : "/d/guanwai/",
]);

int start()
{
	int npc_count = 0;
	string err,*room_file, *enemy_arr;
	string path;
	object room, npc,shab;
	
	mapping exit;

	if (sizeof(npc_arr))	
	npc_arr = ({});
	
	zhangmen = keys(family_dir)[random(sizeof(family_dir))];
	
	room_file = list_dirs(family_dir[zhangmen] + "*.c");
	enemy_arr = keys(family_dir);
	enemy_arr -= ({zhangmen});
	enemy = enemy_arr[random(sizeof(enemy_arr))]->query("family/family_name");
	while (npc_count < NPC_ROOM)
	{
/*
err=catch(call_other(path=family_dir[zhangmen] + room_file[random(sizeof(room_file))], "???"));
if(err){
write_file("/cmds/usr/a1_err.txt","mpz:"+path+"\n");
return 1;
}
*/
if(!sizeof(room_file)) return 1;

path=family_dir[zhangmen] + 
room_file[random(sizeof(room_file))];


		room = load_object(family_dir[zhangmen] + room_file[random(sizeof(room_file))]);
		if (!objectp(room))	continue;		
		exit = room->query("exits");
		if (!room->query("short") || !mapp(exit) || !sizeof(exit) || room->query("no_fight"))
			continue;
		else
		{
			npc = new("/adm/daemons/dshuodong/mpz/npc");
			npc->move(room);
			npc->set_name(RED"" + enemy + "弟子"NOR"", ({"mp_npc"}));
			npc->set("family/family_name", enemy);
			npc_arr += ({npc});
			++npc_count;
		}
	}
	
    //log_files("menpairuqin", ctime(time()) + "门派入侵选定" + load_object(zhangmen)->query("family/family_name") + "敌对为：" + enemy + "。1234\n");
	CHANNEL_D->do_channel(load_object(zhangmen), "chat", enemy + "的弟子真是太嚣张了，已经打上山门了！\n");
	QQ_D->msg("【门派】"+no_color(enemy)+"的弟子真是太嚣张了，已经打上山门了！");
	//log_files("menpairuqin", ctime(time()) + "门派入侵选定" + load_object(zhangmen)->query("family/family_name") + "敌对为：" + enemy + "。\n");
	
	return 1;
}

void remove_npc()
{
	object temp;
	
	remove_call_out("remove_npc");
	foreach(temp in npc_arr)
	{
		if (!find_object(file_name(temp)))	continue;
		temp->force_me("say 溜了溜了。\n");
		destruct(temp);
	}
	npc_arr = ({});
}

object *query_npc()
{
	return npc_arr;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
