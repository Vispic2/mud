// updateall.c
#include <ansi.h>

int dtoin(string date){
	string *da;
	string ins;
	
	da = explode(date,"-");
	
	ins = da[0];
	
	if (to_int(da[1])<10)
	{
		ins += "0"+da[1];
	}else{
		ins += da[1];
	}
	
	if (to_int(da[2])<10)
	{
		ins += "0"+da[2];
	}else{
		ins += da[2];
	}

	return atoi(ins);
}

int sort_da(string d1,string d2)
{
	return dtoin(d2)-dtoin(d1);
}

string getlogfile(string rq,string id){
	return "/backup/"+rq+"/login/" + id[0..0] + "/" + id + ".o";
}

string getuserfile(string rq, string id){
	return "/backup/"+rq+"/user/" + id[0..0] + "/" + id + ".o";
}

string getbaibaofile(string rq, string id){
	return "/backup/"+rq+"/baibao/" + id[0..0] + "/" + id + ".o";
}
string getniepanfile(string rq, string id){
	return "/backup/"+rq+"/niepan/" + id[0..0] + "/" + id + ".o";
}


int checkf(string rq, string id){
	string file;
	
	file = getuserfile(rq, id);
	
	if(file_size(file) > -1)
		return 1;
	
	return 0;
}

void kickout_player(object me, object ob)
{
	object link_ob;

	tell_object(me, HIG"回档操作，你把" + ob->query("name") + "强制退出了游戏！\n"NOR);
	tell_object(ob, HIR"巫师回档操作，你被退出了游戏，请重新登录！\n"NOR);
	
	
	seteuid(ROOT_UID);

	if (objectp(link_ob = ob->query_temp("link_ob")))
	{
		destruct(link_ob);
	}

	destruct(ob);
	seteuid(getuid());
}

int main(object me, string arg)
{
	object pl;
	string *all_file, pops, rq, id, wjq,wjqbaibao,wjqniepan,msg;
	int i,sz;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;
		
	if(!arg)
		return notify_fail("你要回档的id是？\n");
	
	if(sscanf(arg,"%s %s", rq, id) == 2){
		log_file("cmds/adm/huidang", sprintf("%s %-9s操作回档 %s到%s\n",log_time(), geteuid(me),  id, rq));
		wjq = getuserfile(rq, id);
		wjqbaibao = getbaibaofile(rq, id);
		wjqniepan = getniepanfile(rq, id);
		if(file_size(wjq) > -1){
			
			pl = find_player(id);
			if(objectp(pl)){
				kickout_player(me,pl);				
			}
			msg=HIC"玩家【"+id+"】回档情况如下:\n"NOR;
			msg+=HIW"日期:"+rq+"\n"NOR;
		
			
			if( !cp(wjq,"/data/user/" + id[0..0] + "/" + id + ".o")){
					msg+=HIR"USER存盘文件拷贝失败，回档失败。\n"NOR;
			}
			
			wjq = getlogfile(rq, id);
			if(file_size(wjq) > -1){
				cp(wjq,"/data/login/" + id[0..0] + "/" + id + ".o");
			}
			
			if(file_size(wjqbaibao) > -1){	
			if(! cp(wjqbaibao,"/data/baibao/" + id[0..0] + "/" + id + ".o")){
				msg+=HIR"储物袋备份文件不存在，拷贝失败。\n"NOR;
			}
			msg+=HIG"储物袋文件回档成功。\n"NOR;
		}
		
			msg+=HIG"user及login文件回档成功。\n"NOR;
		}else{
			msg+=HIR"id [ "+id+" ]没找到 [ "+rq+" ] 的备份档案，回档失败。\n"NOR;
		}
				write(msg);		
	}else{
		all_file = list_dirs("/backup/");
		all_file = filter_array(all_file, (: checkf :),arg); 
		all_file = sort_array(all_file, (: sort_da :) );
		
		if(!sizeof(all_file))
			return notify_fail("没有找到 [ " + arg + " ] 的备份档案文件。\n");	
		
		pops= ZJOBLONG"你正在给账号 [ "+arg+" ] 进行回档操作"+ZJBR+"请选择要回档的日期（谨慎操作 不可恢复）：\n";
		pops+=ZJOBACTS2+ZJMENUF(2,2,9,28);
		
		sz = sizeof(all_file);
		for(i=0;i<sz;i++)
		{		
			if(i == sz-1){
				pops += all_file[i]+":huidang " + all_file[i] + " " + arg + "\n"; 
			}else{
				pops += all_file[i]+":huidang " + all_file[i] + " " + arg + ZJSEP; 
			}
		}	
		write(pops);		
	}
	
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
