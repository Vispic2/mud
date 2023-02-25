#include <ansi.h>
#include <getconfig.h>
inherit F_SAVE;
inherit F_DBASE;
mapping yb=([]);
int add_cha(string player_id);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "存元宝");
	CHANNEL_D->do_channel( this_object(), "sys", "已经启动。");
	if( !restore() && !mapp(yb) )
	yb = ([]);
	set_heart_beat(1);
}
string query_save_file() { return "/cmds/usr/ayb"; }
mapping get_yb() { return yb; }
int heart_beat()
{
int i,num;
string id;
object ob,*obs;
mixed *sj=localtime(time());
//每天早上6点 1分钟 11秒开始算利息，不在线也有利息。
if(sj[0]==11&&sj[1]==1&&sj[2]==6){
//if(1){
foreach(id in keys(get_yb())){
i=to_int(add_cha(id));
if(i>=500){
num=i/500;
yb[id][0] = to_int(yb[id][0])+to_int(num);
//玩家在线则通知
if(find_player(id)){
tell_object(find_player(id),"元宝账上有："+i+"个元宝，因此你获得利息："+num+"个元宝，你现在有元宝："+find_player(id)->query("yuanbao")+"\n");
}
save();
i=0;
num=0;
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
	write("你存入了："+to_int(money_amount)+"个元宝，目前账上有："+to_int(yb[id][0])+"个元宝\n");
	}else{	
	yb[id][0] = to_int(yb[id][0])+to_int(money_amount);
	write("你存入了："+to_int(money_amount)+"个元宝，目前账上有："+to_int(yb[id][0])+"个元宝\n");
	}
	save();
	return 1; 
}
int delete_yb(string player_id,int i){
	object player;
	string id;
	player = find_player(player_id);
	if(!player) return 1;
	id=player->query("id");	
	if (undefinedp(yb[id])){
	tell_object(player,"你里面没有元宝，你取个啥？\n");
	return 1;
	}else{
	if(to_int(yb[id][0])<to_int(i)){
	write("账上只有："+to_int(yb[id][0])+"个元宝，取不出来这么多！\n");
	return 1;
	}	
	yb[id][0] = to_int(yb[id][0])-to_int(i);
	player->add("yuanbao",to_int(i));
	tell_object(player,"你取出了："+to_int(i)+"个元宝，目前账上还有："+to_int(yb[id][0])+"\n");
	}
	save();
	return 1;
}
int main(object me, string arg)
{
int i;
string msg,cmd;
if(arg=="test"){
//add_yb("bbbb",500);
yb += ([ "dddd" : ({ "500", }), ]);
write("执行成功\n");
save();
}
if(!arg){
msg=ZJOBLONG+"\t\t\t\t\t\t\t\t存元宝系统\t\t\t\t账上元宝："+add_cha(me->query("id"))+"个\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,9,30);
msg+="存元宝:ayb cun"ZJSEP;
msg+="取元宝:ayb delete";
msg+="\n";
write(msg+"\n");
}else{
if(arg=="cun"){
return notify_fail(INPUTTXT("存多少元宝？","ayb cun $txt#")+"\n");
}
if(arg=="delete"){
return notify_fail(INPUTTXT("取多少元宝？","ayb delete $txt#")+"\n");
}
if(sscanf(arg,"%s %s",cmd,i)==2){
if(cmd=="cun"){
if(me->query("yuanbao")<to_int(i)){
write("你身上没有这么多元宝。\n");
return 1;
}
me->add("yuanbao",-to_int(i));
add_yb(me->query("id"),i);
return 1;
}
if(cmd=="delete"){
delete_yb(me->query("id"),i);
return 1;
}
}
return 1;
}
return 1;
}

