//by name
#include <ansi.h>
inherit F_SAVE;
inherit F_DBASE;
mapping invitation;
#define YQ_D "/cmds/usr/ainvitationd.c"
int main(object me,string arg)
{
string mail,code;
if(!arg)
return notify_fail(INPUTTXT("1.请输入被邀请者QQ邮箱"ZJBR"2.请输入被邀请者QQ邮箱 + 邀请码  ["+HIC+ZJSIZE(23)+ZJURL("cmds:help yqxt")+"帮助说明"NOR"]","ainvitationd $txt#")+"\n");	
if(sscanf(arg,"%s %s",mail,code)==2){

if(is_az(mail[0..0])){
write(HIR"警告：请使用数字邮箱，不能使用英文邮箱，你的ID已被记录！\n"NOR);
me->add("mail-bug",1);
return 1;
}
if(me->query("yq/"+mail)==code){
if(me->query("data_email")==mail){
write("不能邀请自己！\n");
return 1;
}
if(strsrch(read_file(__DIR__+"ainvitationd.txt"),mail)!=-1){
write("此邮箱已经被他人邀请过了！\n");
return 1;
}

YQ_D->add_invitation(me->query("id"),mail);
YQ_D->save();
write("匹配成功，请等待"+mail+"邮箱注册玩家上线，游玩1分钟你即可获得大量奖励！\n");
}else{
write("你输入的邮箱与邀请码不匹配，请检查后重试！\n");
}
return 1;
}
me->force_me("api_mail "+arg);
return 1;
}
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "邀请系统");
	CHANNEL_D->do_channel( this_object(), "sys", "邀请系统已经启动。");
	if( !restore()&&!mapp(invitation) )
	invitation = ([]);
	set_heart_beat(2);
	write_file(__DIR__+"ainvitationd.txt","");
}
string query_save_file() { return DATA_DIR + "invitationd"; }
mapping get_invitation() { return invitation; }
int add_invitation(string player_id, string mail){
	object player;
	string name;
	player = find_player(player_id);
	if(!player) return 1;
	name=player->query("id");
	if (undefinedp(invitation[name]))
		invitation += ([ name : ({ mail, }), ]);
	else
		invitation[name] += ({mail,});
	save();
	return 1; 
}
int delete_invitation(string player_id){
	map_delete(invitation, player_id);
	save();
	return 1;
}
void remove(){
    save();
}
int heart_beat()
{
int yuanbao;
string name,data,mail;
mapping db;
object p,ob,*obs;
db=invitation;
foreach(name in keys(db)){
foreach(data in db[name]){
foreach(ob in users()){
mail=ob->query("data_email");
if(mail==data){
if(find_player(name)){
if(strsrch(read_file(__DIR__+"ainvitationd.txt"),data)==-1){
write_file(__DIR__+"ainvitationd.txt","邀请者="+find_player(name)->query("id")+" 被邀请者="+ob->query("id")+" 邀请者邮箱="+find_player(name)->query("data_email")+" 被邀请者邮箱="+data+"\n"); //被邀请过的邮箱
find_player(name)->add("yqrs",1); ///累计邀请人数
//yuanbao=5000*find_player(name)->query("yqrs");
//if(yuanbao>=50000) yuanbao=50000;
yuanbao=1000;
if(find_player(name)->query("yqrs")==3){
p = new("/clone/vip/putao1");
p->set_amount(10);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai1");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
}
if(find_player(name)->query("yqrs")==5){
p = new("/clone/vip/putao1");
p->set_amount(20);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai1");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai2");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
}
if(find_player(name)->query("yqrs")==15){
p = new("/clone/vip/putao1");
p->set_amount(50);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai1");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai2");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai3");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
}
if(find_player(name)->query("yqrs")==30){
p = new("/clone/vip/putao1");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai1");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai2");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai3");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
p = new("/clone/vip/dan_chongmai4");
p->set_amount(100);
write(YEL"恭喜您：获得了"+p->short()+"。"NOR"\n");
p->move(find_player(name));
}
find_player(name)->add("yuanbao",yuanbao);
tell_object(find_player(name),HIG"你邀请的玩家上线，此邮箱第一次被邀请加上你已累计邀请了"+find_player(name)->query("yqrs")+"位玩家因此你获得了："+yuanbao+" 个元宝！\n"NOR);
//tell_object(find_player(name),HIG"你邀请的玩家上线，此邮箱第一次被邀请加上你已累计邀请了"+find_player(name)->query("yqrs")+"位玩家因此你获得了："+yuanbao+" 个元宝！\n"NOR);
delete_invitation(name);
}else{
tell_object(find_player(name),HIR"你邀请的玩家上线，但是此邮箱曾经被别人邀请过了所以不获得任何奖励！\n"NOR);
delete_invitation(name);
}
}
}
}
}
}
//YQ_D->save();
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
