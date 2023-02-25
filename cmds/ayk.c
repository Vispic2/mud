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
	set("channel_id", "元宝月卡");
	CHANNEL_D->do_channel( this_object(), "sys", "已经启动。");
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
//每秒减1
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
	write("你元宝月卡时间增加了："+to_int(money_amount)+"秒\n");
	}else{	
	yb[id][0] = to_int(yb[id][0])+to_int(money_amount);
	write("你元宝月卡时间增加了："+to_int(money_amount)+"秒\n");
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
msg=ZJOBLONG+"\t\t\t\t\t\t\t\t元宝月卡系统\t\t\t\t剩余时间："+add_cha(me->query("id"))+"\n";
msg+=ZJOBACTS2+ZJMENUF(2,2,9,30);
msg+="领取:ayk add"ZJSEP;
msg+="购买30天:ayk kjj";
write(msg+"\n");
return 1;
}
if(arg=="kjj"){
if(me->query("yuanbao")<888){
write("购买需要888元宝\n");
return 1;
}
add_yb(me->query("id"),86400*30);
me->add("yuanbao",-888);
write("恭喜你获得了元宝月卡86400*30秒即30天，此后30天内均可获得88元宝(不领取则没有，时间照减)\n");
return 1;
}
if(arg=="add"){
if(add_cha(me->query("id"))>1){
last = me->query("ayk");
if(time()/86400 == last/86400)
return notify_fail("你今天已经领取过元宝月卡的奖励了！\n");
me->set("ayk",time());
me->add("yuanbao",88);
write("领取成功，你获得了88元宝\n");
return 1;
}else{
write("元宝月卡时间不足\n");
return 1;
}
}
}

