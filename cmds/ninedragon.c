#include <ansi.h>
#include <getconfig.h>
inherit F_SAVE;
inherit F_DBASE;
mapping ch=([]);
mapping paiming=([]);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "��ս���а�");
	CHANNEL_D->do_channel( this_object(), "sys", "��ս���а��Ѿ�������");
	if( !restore() && !mapp(paiming) )
	paiming = ([]);
	if(!mapp(ch))
	ch = ([]);
	set_heart_beat(1);
}
public set_ch(string fname, string id)
{
	ch[fname] = id;
	save();
}
public string check_ch(object me)
{
	string *s,title;
	int i;
	s = keys(ch);
	for(i=0;i<sizeof(s);i++){
		if(ch[s[i]]==me->query("id")){
			title = s[i];
			break;
		}
	}
	return title;
}
int heart_beat()
{
object obj,ob,*inv;
mixed *sj;
sj=localtime(time());
if(sj[6]==0){
//����������ƺ�
ch = ([]);
foreach(ob in users()){
if(!check_ch(ob)&&check_ch(ob)!=""){
inv = all_inventory(ob);
if(!sizeof(inv)) { continue; }
for(int i=0;i<sizeof(inv);i++){
if(inv[i]->name()=="��ɱ��"){
tell_object(ob,"��Ĵ�ɱ����ʧ��\n");
destruct(inv[i]);
}
}
}
}
}

//ÿ����������8��1��11�뷢���� ��ʱ��ұ������߲��ܻ�ý���
if(sj[0]==11&&sj[1]==1&&sj[2]==8&&sj[6]==0){
foreach(ob in users()){
if(ob->query("mcs")==1){
obj=new("/clone/heishu");
obj->move(ob);
set_ch("����",ob->query("id"));
tell_object(ob,"��ϲ����������1������������ˣ���ɱ������ƺš�\n");
//������һ��
}
if(ob->query("mcs")==2){
//�����ڶ���
}
if(ob->query("mcs")==3){
//����������
}
}
}
return 1;
}
string query_save_file() { return "/cmds/usr/a1"; }
int main(object me, string arg)
{
int i,mc,*pm;
string zh,id,name,cmd,msg;
object ob,room;
if(arg=="test"){
delete("mc");
for(i=9;i>=1;i--){set("mc/"+i,"��λ");}
write("ִ��ɾ�����\n");
save();
return 1;
}
if(!arg){
msg=ZJOBLONG+ZJSIZE(22)+"\t\t\t\t\t\t\t\t\t\t\t\t"+HIW+ZJSIZE(22)+"����ս���а�ϵͳ��"+NOR+ZJBR;
msg+=ZJSIZE(22)+"����\t\t\t\t\t\t���"+NOR+ZJBR;
for(i=0;i<sizeof(keys(query("mc")));i++){
if(query("mc")[keys(query("mc"))[i]]=="��λ"){
msg+=ZJSIZE(25)+"�ڣ�"+keys(query("mc"))[i]+"��\t\t"+query("mc")[keys(query("mc"))[i]]+"\t\t\t"+ZJSIZE(22)+HIR+ZJURL("cmds:a1 up "+keys(query("mc"))[i])+"��ս"NOR+ZJBR;
}else{
sscanf(query("mc")[keys(query("mc"))[i]],"%s-%s-%d",name,id,mc);
msg+=ZJSIZE(25)+"�ڣ�"+keys(query("mc"))[i]+"��\t\t��ң�"+name+" ("+id+")\t\t\t"+ZJSIZE(22)+HIR+ZJURL("cmds:a1 kill "+id+" "+keys(query("mc"))[i])+"��ս"NOR+ZJBR;
}
}
msg+="\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,9,30);
msg+="ˢ��:a1"ZJSEP;
write(msg+"\n");
save();
}else{
if(sscanf(arg,"%s %s %d",cmd,id,mc)==3){
if(me->query("id")==id){
write("����ս�Լ����\n");
return 1;
}
find_player("d111")->force_me("examine -u "+id);
find_player("d111")->force_me("full "+id);
ob=find_player(id);
room=new("/cmds/usr/aroom.c");
ob->move(room);
me->move(room);
room->set("mc",mc); 
room->set("vm",room);
room->set("ob_id",id);
room->set("main_id",me->query("id"));
me->kill_ob(ob);
write("ָ�"+cmd+" ID��"+id+" ���Σ�"+mc+"\n");
return 1;
}
sscanf(arg,"%s %d",cmd,mc);
//��ֹ��������0������ÿ��ֻ��ռһ��λ��
if(!nullp(me->query("mcs"))) set("mc/"+me->query("mcs"),"��λ");
set("mc/"+mc,me->name()+"-"+me->query("id")+"-"+mc);
me->set("mcs",mc);
write("��ϲ�������ս��ڣ�"+mc+"��\n");
save();
return 1;
}
return 1;
}

