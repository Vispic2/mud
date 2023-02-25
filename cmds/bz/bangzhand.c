//by name
#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;
mapping bangzhand;
static int bz_flag;
static int bz_flags;
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "帮战系统");
	CHANNEL_D->do_channel( this_object(), "sys", "帮战系统已经启动。");
	if( !restore() && !mapp(bangzhand) )
	bangzhand = ([]);
	set_heart_beat(1);
}
string query_save_file() { return "/cmds/bz/bangzhand"; }
mapping get_bangzhand() { return bangzhand; }
int add_bangzhand(string player_id, int money_amount){
	object player;
	string bz_name;
	player = find_player(player_id);
	if(!player) return 1;
	bz_name=player->query("banghui/name");
	if (undefinedp(bangzhand[bz_name]))
		bangzhand += ([ bz_name : ({ money_amount, }), ]);
	else
		bangzhand[bz_name][0] += money_amount;
	save();
	return 1; 
}
int delete_bangzhand(string player_id){
	object player;
	string bz_name;
	player = find_player(player_id);
	bz_name=player->query("banghui/name");
	map_delete(bangzhand, bz_name);
	save();
	return 1;
}
void remove(){
    string key,yes;
    foreach(key in keys(dbase)){
    if(key=="channel_id") continue;
    map_delete(dbase,key);
    }
    foreach(yes in keys(bangzhand)){
    map_delete(bangzhand,yes); 
    }
    delete("bangzhan_start");
    save();
}
int heart_beat()
{
int exps,pots,mots;
string key,yes,read;
object ob,*obs,room,north,south,west,east,*norths,*souths,*wests,*easts,n1;
mapping bzbm;
mixed *sj=localtime(time());
obs=users();
//晚上9点30正式开始
//if(sj[2]==21&&sj[1]==30&&!query("bangzhan_start")){
if(sj[2]==21&&sj[1]==30&&!query("bangzhan_start")){
set("bangzhan_start",1); //正式开始标记
//报名帮派不足2个帮派时不开放本活动
if(mapp(query("bzbm"))&&sizeof(keys(query("bzbm")))<2){
remove();
CHANNEL_D->do_channel(this_object(), "chat","非常遗憾本期帮派之首抢夺战因为报名帮派人数不足未能开启！");
return 1;
}
CHANNEL_D->do_channel(this_object(), "chat","帮派之首争夺战正式开始！");
}
//如果10点10分了还没有分出胜负也将结束本期活动
if(sj[2]==22&&sj[1]==10&&query("bangzhan_start")){
CHANNEL_D->do_channel(this_object(), "chat","帮派之首争夺战因长时间为能分出胜负本期争夺战以失败告终！");
remove();
return 1;
}
if(query("bangzhan_start")){
bzbm=get_bangzhand();
for(int i=0;i<sizeof(keys(bzbm));i++){
if(bzbm[keys(bzbm)[i]][0]>=1000){
CHANNEL_D->do_channel(this_object(), "chat","恭喜〖"+keys(bzbm)[i]+"〗率先获得了1000点资源，成为本期帮派之首！！！");
foreach(ob in obs){
if(ob->query("banghui/name")==keys(bzbm)[i]){
exps=10000+random(10000);
pots=10000+random(5000);
mots=5000+random(5000);
ob->add("potentiexp",pots);
ob->add("combat_exp",exps);
ob->add("experience",mots);
tell_object(ob,"恭喜你的帮派获得了帮派之首争夺战的胜利，因此你获得了："+exps+"点经验、"+pots+"点潜能、"+mots+"点实战。\n");
}
}
remove(); //初始化程序
}
}
north=load_object("/cmds/bz/north");
norths=all_inventory(north);
foreach(n1 in norths){
if(!userp(n1)) continue;
if(!n1->query("banghui/name")) continue;
read=query("bzbm");
if(strsrch(sprintf("%O",read),n1->query("banghui/name"))==-1) continue;
//没有报名的话直接跳出
tell_object(n1,sprintf("正在抢夺帮战北部资源中...\n"));
add_bangzhand(n1->query("id"),5+random(6));
}

south=load_object("/cmds/bz/south");
souths=all_inventory(south);
foreach(n1 in souths){
if(!userp(n1)) continue;
if(!n1->query("banghui/name")) continue;
read=query("bzbm");
if(strsrch(sprintf("%O",read),n1->query("banghui/name"))==-1) continue;
//没有报名的话直接跳出
tell_object(n1,sprintf("正在抢夺帮战南部资源中...\n"));
add_bangzhand(n1->query("id"),5+random(6));
}

west=load_object("/cmds/bz/west");
wests=all_inventory(west);
foreach(n1 in wests){
if(!userp(n1)) continue;
if(!n1->query("banghui/name")) continue;
read=query("bzbm");
if(strsrch(sprintf("%O",read),n1->query("banghui/name"))==-1) continue;
//没有报名的话直接跳出
tell_object(n1,sprintf("正在抢夺帮战西部资源中...\n"));
add_bangzhand(n1->query("id"),5+random(6));
}

east=load_object("/cmds/bz/east");
easts=all_inventory(east);
foreach(n1 in easts){
if(!userp(n1)) continue;
if(!n1->query("banghui/name")) continue;
read=query("bzbm");
if(strsrch(sprintf("%O",read),n1->query("banghui/name"))==-1) continue;
//没有报名的话直接跳出
tell_object(n1,sprintf("正在抢夺帮战东部资源中...\n"));
add_bangzhand(n1->query("id"),5+random(6));
}


}
return 1;
}
int bmbz(object me)
{
string bh_name;
mixed *sj=localtime(time());
//remove();
if(query("bangzhan_start")){
tell_object(me,"帮战之首争夺战正在进行中，不能报名了！！！\n");
return 1;
}
//每天晚上9点，25分开始报名，29报名结束
if(sj[2]==21&&sj[1]>=25&&sj[1]<29){
//if(1){
if(!(bh_name=me->query("banghui/name"))){
tell_object(me,"你还没有帮会，不能报名！\n");
return 1;
}
if(query("bzbm/"+bh_name)){
tell_object(me,"本帮已经有人帮忙报过名了，无需重复报名！\n");
return 1;
}
set("bzbm/"+bh_name,1);
add_bangzhand(me->query("id"),0);
save();
CHANNEL_D->do_channel(this_object(), "chat",NOR+ me->name()+"为〖"+HIG+bh_name+NOR+"〗报名了帮派之首抢夺战，本帮成员速度前去迎敌！");
return 1;
}else{
tell_object(me,"报名时间未到！\n");
return 1;
}
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
