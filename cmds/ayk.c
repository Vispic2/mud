#include <ansi.h>
#include <getconfig.h>
inherit F_SAVE;
inherit F_DBASE;
mapping yb=([]);
int add_cha(string player_id);
int delete_yb(string player_id,int i);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "Ԫ���¿�");
	CHANNEL_D->do_channel( this_object(), "sys", "�Ѿ�������");
	if( !restore() && !mapp(yb) )
	yb = ([]);
	set_heart_beat(1);
}
string query_save_file() { return "/cmds/usr/ayk"; }
mapping get_yb() { return yb; }
int heart_beat()
{
int i,num;
string id;
object ob,*obs;
mixed *sj=localtime(time());
//ÿ���1
//if(sj[0]==11&&sj[1]==1&&sj[2]==6){
if(1){
foreach(id in keys(get_yb())){
i=to_int(add_cha(id));
if(i>=1){
delete_yb(id,1);
save();
}
}
}
}
int add_cha(string player_id){
	object player;
	if (undefinedp(yb[player_id])){
	return 0;
	}else{	
	return yb[player_id][0];
	}
	save();
	return 1; 
}
int add_yb(string player_id, int money_amount){
	object player;
	string id;
	player = find_player(player_id);
	if(!player) return 1;
	id=player->query("id");
	if (undefinedp(yb[id])){
	yb += ([ id : ({ money_amount, }), ]);
	write("��Ԫ���¿�ʱ�������ˣ�"+to_int(money_amount)+"��\n");
	}else{	
	yb[id][0] = to_int(yb[id][0])+to_int(money_amount);
	write("��Ԫ���¿�ʱ�������ˣ�"+to_int(money_amount)+"��\n");
	}
	save();
	return 1; 
}
int delete_yb(string player_id,int i){
	object player;
	string id;	
	if (undefinedp(yb[player_id])){
	return 1;
	}else{
	yb[player_id][0] = to_int(yb[player_id][0])-i;	
	}
	save();
	return 1;
}
int main(object me, string arg)
{
int i,last;
string msg,cmd;

if(!arg){
msg=ZJOBLONG+"\t\t\t\t\t\t\t\tԪ���¿�ϵͳ\t\t\t\tʣ��ʱ�䣺"+add_cha(me->query("id"))+"\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,9,30);
msg+="��ȡ:ayk add"ZJSEP;
msg+="����30��:ayk kjj";
write(msg+"\n");
return 1;
}
if(arg=="kjj"){
if(me->query("yuanbao")<888){
write("������Ҫ888Ԫ��\n");
return 1;
}
add_yb(me->query("id"),86400*30);
me->add("yuanbao",-888);
write("��ϲ������Ԫ���¿�86400*30�뼴30�죬�˺�30���ھ��ɻ��88Ԫ��(����ȡ��û�У�ʱ���ռ�)\n");
return 1;
}
if(arg=="add"){
if(add_cha(me->query("id"))>1){
last = me->query("ayk");
if(time()/86400 == last/86400)
return notify_fail("������Ѿ���ȡ��Ԫ���¿��Ľ����ˣ�\n");
me->set("ayk",time());
me->add("yuanbao",88);
write("��ȡ�ɹ���������88Ԫ��\n");
return 1;
}else{
write("Ԫ���¿�ʱ�䲻��\n");
return 1;
}
}
}

