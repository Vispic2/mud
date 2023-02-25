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
	set("bilv",3000); //��ɽ���Ԫ������ Ĭ�ϳ�1Ԫ�����ϼ�30Ԫ�� 
	restore();
	set("channel_id", "�ƹ㾫��");
	CHANNEL_D->do_channel( this_object(), "sys", "�ƹ㾫���Ѿ�������");
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
		
		log_file("adms/create", sprintf("%s��%s(%s)�������ƹ��룺%s��\n",cntime(time()),me->query("name"),meid,query("tguser/"+meid+"/code")));
		
		tell_object(me,HIY"����ƹ��봴���ɹ�\n���ס����ƹ��룺"+query("tguser/"+meid+"/code")+""NOR"\n");
		return 1;
	}else{
		tell_object(me,HIR"���Ѿ������ƹ����ˣ�����Ҫ�ٴ����ƹ��롣\n����ƹ����ǣ�"+my_code(me)+""NOR"\n");
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
		
		log_file("adms/chongzhi", sprintf("%s��%s(%s)��ֵ��%dԪ���ϼ�(%s)Ԫ��������Ԫ����%d��\n",cntime(time()),me->query("name"),meid,rmb,shangjia,ybs));
		
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
		
		log_file("adms/lingqu", sprintf("%s��%s(%s)��ȡ��Ԫ��%d����\n",cntime(time()),me->query("name"),meid,ybs));
		
		tell_object(me,HIY"�������ƹ�Ԫ��������ȡ��Ԫ����"+ybs+"����"NOR"\n");
		return 1;
	}else{
		tell_object(me,HIR"����ƹ�Ԫ������û��Ԫ��������ȡ��ɶӴ��"NOR"\n");
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
					
					log_file("adms/tijiao", sprintf("%s��%s(%s)�ύ�ƹ��룺%s���ϼ��ǣ�%s��\n",cntime(time()),me->query("name"),meid,code,shangjia));
					
					tell_object(me,HIY"�ƹ����ύ�ɹ���������ֵ�����˼��ɻ��50%�ķ�����\nע�⣺�ύ�ƹ�������ֻ��һ�Σ�ɾ���ؽ���Ҳ�޷����ύ��Ҳ�޷����ϵͳ������Ԫ����"NOR"\n");						
				}else{	
					tell_object(me,HIR"�㲻���ύ���¼ҵ��ƹ��롣"NOR"\n");				
				}

			}else{
				tell_object(me,HIR"�����ύ�Լ����ƹ��롣"NOR"\n");
			}
		}else{
			tell_object(me,HIR"���ύ���ƹ�����Ч�����ʵ�����ύ��"NOR"\n");
		}
	}else{
		tell_object(me,HIR"���Ѿ��ύ���ƹ����ˣ�һ��idһ��ֻ���ύһ���ƹ��룬������ɾ���ؽ�����Ҳ�޷��ٴ��ύ��"NOR"\n");
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
BY��NAME
QQ��21315491
DATE��2 0 2 2 . 0 2 . 0 3
*/
