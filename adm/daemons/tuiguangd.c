#include <command.h>
 
inherit F_DBASE;
inherit F_SAVE; 
 string cntime(int t)
{
	mixed *r;
	string *months = ({"01","02","03","04","05","06","07","08","09","10","11","12"});
	
	r = localtime(t);
	return sprintf("%d-%s-%02d %02d:%02d:%02d",
		r[5], 
		months[r[4]], 
		r[3], 
		r[2],
		r[1], 
		r[0]);
}
void create() 
{ 
	seteuid(getuid());
	set("bilv",3000); //提成奖励元宝比率 默认充1元奖励上家30元宝 
	restore();
	set("channel_id", "推广精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "推广精灵已经启动。");
}

void remove()
{
	save();
}

void mud_shutdown()
{
	save();
}

string query_save_file() 
{ 
	return DATA_DIR + "tuiguangd"; 
} 

string get_id_focode(string code){
	mapping users;
	string u;
	
	if(mapp(users = query("tguser"))){
		foreach (u in keys(users)){
			if(query("tguser/"+u+"/code") == code){
				return u;
			}
		}
	}
	
	return 0;
}

string get_code(){
	string code;
	code = time()+""+(1000+random(9999));
	return code;
}

string my_code(object me){
	string meid = me->query("id");
	string mycode;
	
	if(stringp(mycode = query("tguser/"+meid+"/code"))){
		return mycode;
	}else{
		return 0;
	}	
}

string my_shangj(object me){
	string meid = me->query("id");
	string mysj;
	
	if(stringp(mysj = query("tguser/"+meid+"/shangjia"))){
		return mysj;
	}else{
		return 0;
	}	
}

int my_yuanbao(object me){
	string meid = me->query("id");
	int yuanbao;
	
	if(yuanbao = query("tguser/"+meid+"/yuanbaoci")){
		return yuanbao;
	}else{
		return 0;
	}	
}

int create_code(object me){
	string meid = me->query("id");
	
	if(!query("tguser/"+meid+"/code")){
		set("tguser/"+meid+"/code",get_code());
		
		save();
		
		log_file("adms/create", sprintf("%s：%s(%s)创建了推广码：%s。\n",cntime(time()),me->query("name"),meid,query("tguser/"+meid+"/code")));
		
		tell_object(me,HIY"你的推广码创建成功\n请记住你的推广码："+query("tguser/"+meid+"/code")+""NOR"\n");
		return 1;
	}else{
		tell_object(me,HIR"你已经有了推广码了，不需要再创建推广码。\n你的推广码是："+my_code(me)+""NOR"\n");
		return 0;
	}
}

int chongzhi(object me,int rmb){
	string shangjia;
	string meid;
	int bl,ybs;
	
	meid = me->query("id");
	
	if(stringp(shangjia = query("tguser/"+meid+"/shangjia"))){
		bl = to_int(query("bilv")/100);
		ybs = to_int(rmb * bl);
		
		add("tguser/"+shangjia+"/yuanbaoci",ybs);
		add("tguser/"+shangjia+"/xiajia/"+meid,ybs);
		
		save();
		
		log_file("adms/chongzhi", sprintf("%s：%s(%s)充值：%d元，上家(%s)元宝池增加元宝：%d。\n",cntime(time()),me->query("name"),meid,rmb,shangjia,ybs));
		
		return 1;
	}
	
	return 0;
}

int lingqu(object me,int rmb){

	string meid;
	int ybs;
	
	meid = me->query("id");
	
	if(ybs = query("tguser/"+meid+"/yuanbaoci")){
		
		set("tguser/"+meid+"/yuanbaoci",0);
		save();
		
		me->add("yuanbao",ybs);
		me->save();
		
		log_file("adms/lingqu", sprintf("%s：%s(%s)领取了元宝%d个。\n",cntime(time()),me->query("name"),meid,ybs));
		
		tell_object(me,HIY"你从你的推广元宝池中领取了元宝："+ybs+"个。"NOR"\n");
		return 1;
	}else{
		tell_object(me,HIR"你的推广元宝池中没有元宝，你领取个啥哟。"NOR"\n");
	}
	
	return 0;
}

int is_xiajia(string meid, string shangjia){
	mapping xiajias;
	string u;
	
	if(mapp(xiajias = query("tguser/"+meid+"/xiajia"))){
		foreach (u in keys(xiajias)){
			if(u == shangjia){
				return 1;
			}
		}
	}
	
	return 0;
}

int tijiao_code(object me, string code){
	string shangjia;
	string meid;
	
	meid = me->query("id");
	
	if(! query("tguser/"+meid+"/shangjia")){
		if(stringp(shangjia = get_id_focode(code))){
			if(shangjia != meid){
				
				if(! is_xiajia(meid, shangjia)){
					set("tguser/"+meid+"/shangjia",shangjia);
					set("tguser/"+shangjia+"/xiajia/"+meid,0);
					save();
					
					//me->add("yuanbao",1000);
					me->save();
					
					log_file("adms/tijiao", sprintf("%s：%s(%s)提交推广码：%s，上家是：%s。\n",cntime(time()),me->query("name"),meid,code,shangjia));
					
					tell_object(me,HIY"推广码提交成功，如果你充值邀请人即可获得50%的返利。\n注意：提交推广码终身只此一次，删档重建后也无法再提交，也无法获得系统奖励的元宝。"NOR"\n");						
				}else{	
					tell_object(me,HIR"你不能提交你下家的推广码。"NOR"\n");				
				}

			}else{
				tell_object(me,HIR"不能提交自己的推广码。"NOR"\n");
			}
		}else{
			tell_object(me,HIR"你提交的推广码无效，请核实后再提交。"NOR"\n");
		}
	}else{
		tell_object(me,HIR"你已经提交过推广码了，一个id一生只能提交一次推广码，即便是删档重建人物也无法再次提交。"NOR"\n");
	}
}

int getallby(object me){
	mapping users;
	string meid,u;
	int lj=0;
	
	meid = me->query("id");
	if(mapp(users = query("tguser/"+meid+"/xiajia"))){
		foreach (u in keys(users)){
			lj += users[u];
		}
	}
	
	return lj;
}

mapping getxj(object me){
	mapping ls;
	string meid;
	
	meid = me->query("id");
	
	if(mapp(ls = query("tguser/"+meid+"/xiajia"))){
		return ls;
	}
	
	return 0;
}

void setbl(int bl){
	object me = this_player(1); 
	 
	if (!wizardp(me))
			return;
		
	set("bilv",bl);
	save();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
