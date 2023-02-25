#include <ansi.h>
#include <getconfig.h>
inherit F_SAVE;
inherit F_DBASE;
mapping ch=([]);
mapping paiming=([]);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "挑战排行榜");
	CHANNEL_D->do_channel( this_object(), "sys", "挑战排行榜已经启动。");
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
//星期天清除称号
ch = ([]);
foreach(ob in users()){
if(!check_ch(ob)&&check_ch(ob)!=""){
inv = all_inventory(ob);
if(!sizeof(inv)) { continue; }
for(int i=0;i<sizeof(inv);i++){
if(inv[i]->name()=="刺杀令"){
tell_object(ob,"你的刺杀令消失了\n");
destruct(inv[i]);
}
}
}
}
}

//每星期天早上8点1分11秒发奖励 此时玩家必须在线才能获得奖励
if(sj[0]==11&&sj[1]==1&&sj[2]==8&&sj[6]==0){
foreach(ob in users()){
if(ob->query("mcs")==1){
obj=new("/clone/heishu");
obj->move(ob);
set_ch("霸主",ob->query("id"));
tell_object(ob,"恭喜你在排名第1名，因此你获得了：刺杀令，霸主称号。\n");
//奖励第一名
}
if(ob->query("mcs")==2){
//奖励第二名
}
if(ob->query("mcs")==3){
//奖励第三名
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
for(i=9;i>=1;i--){set("mc/"+i,"空位");}
write("执行删除完成\n");
save();
return 1;
}
if(!arg){
msg=ZJOBLONG+ZJSIZE(22)+"\t\t\t\t\t\t\t\t\t\t\t\t"+HIW+ZJSIZE(22)+"〖挑战排行榜系统〗"+NOR+ZJBR;
msg+=ZJSIZE(22)+"名次\t\t\t\t\t\t玩家"+NOR+ZJBR;
for(i=0;i<sizeof(keys(query("mc")));i++){
if(query("mc")[keys(query("mc"))[i]]=="空位"){
msg+=ZJSIZE(25)+"第："+keys(query("mc"))[i]+"名\t\t"+query("mc")[keys(query("mc"))[i]]+"\t\t\t"+ZJSIZE(22)+HIR+ZJURL("cmds:a1 up "+keys(query("mc"))[i])+"挑战"NOR+ZJBR;
}else{
sscanf(query("mc")[keys(query("mc"))[i]],"%s-%s-%d",name,id,mc);
msg+=ZJSIZE(25)+"第："+keys(query("mc"))[i]+"名\t\t玩家："+name+" ("+id+")\t\t\t"+ZJSIZE(22)+HIR+ZJURL("cmds:a1 kill "+id+" "+keys(query("mc"))[i])+"挑战"NOR+ZJBR;
}
}
msg+="\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,9,30);
msg+="刷新:a1"ZJSEP;
write(msg+"\n");
save();
}else{
if(sscanf(arg,"%s %s %d",cmd,id,mc)==3){
if(me->query("id")==id){
write("你挑战自己干嘛？\n");
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
write("指令："+cmd+" ID："+id+" 名次："+mc+"\n");
return 1;
}
sscanf(arg,"%s %d",cmd,mc);
//防止出现排名0，排名每人只能占一个位。
if(!nullp(me->query("mcs"))) set("mc/"+me->query("mcs"),"空位");
set("mc/"+mc,me->name()+"-"+me->query("id")+"-"+mc);
me->set("mcs",mc);
write("恭喜你登上挑战榜第："+mc+"名\n");
save();
return 1;
}
return 1;
}

