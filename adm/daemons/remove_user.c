#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SAVE;
//string id,*ids=({});
//int logind(object me);
public int reg_user(object me, string arg);
public int create_user(object me,string *ids,int i,string arg);
varargs int create_user_set(object me,string id,string key,mixed data,int i);
void create()
{
	seteuid(ROOT_UID);
	set("channel_id", "删档精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "删档精灵已经启动。");
	//set_heart_beat(1);
}
/*
int heart_beat()
{
int time;
object ob,me=this_object();
logind(me);
if(!sizeof(ids)) return 1;
foreach(id in ids){
ob=find_player(id);
if(!ob) return 1;
time=time()-ob->query("shangxian_time"); //这个标记每51秒在线的玩家都会刷新一次值为time()
if(ob->query("shangxian_time")<1000) return 1;
tell_object(find_player("name"),"执行结果:"+ob->name()+" TIME:"+time+"\n");
if(ob->query("balance")<1000000){ //钱庄存款大于1000金,不执行删档
if(ob->query("combat_exp")<50000){
    if(time>84600*5){
        //经验小于5w,且离线时间超过5天,执行删档
        tell_object(find_player("name"),"名字:"+ob->name()+" TIME:"+time+"\n");
        destruct(ob);
        UPDATE_D->remove_user(id); //调用updated里已经有的删档文件
        }
    }else
if(ob->query("combat_exp")<500000){
    if(time>84600*180){
        //经验小于50w,且离线时间超过180天,执行删档
        tell_object(find_player("name"),"执行结果:"+ob->name()+" TIME:"+time+"\n");
        destruct(ob);
        UPDATE_D->remove_user(id); //调用updated里已经有的删档文件
    }
}
}
if(ob)
destruct(ob);
}
ids=({});
return 1;
}

int logind(object me)
{
string id;
string dir,*dirs;
string user,*users;
dirs=get_dir("/data/user/");
foreach(dir in dirs){
users=get_dir("/data/user/"+dir+"/");
foreach(user in users){
id=replace_string(user,".o","");
if(!find_player(id)){  //只要离线的玩家,在线的玩家直接跳过
ids+=({id});
find_player("name")->force_me("examine -u "+id);
}
}
}
return 1;
}*/
public int reg_user(object me)
{
int i;
string id,path,*dirs,*ids=({});
foreach(path in get_dir("/data/login/")){
dirs=get_dir("/data/login/"+path+"/");
for(i=0;i<sizeof(dirs);i++){
create_user(me,dirs,i);
}
}
return 1;
}
public int create_user(object me,string *ids,int i)
{
object login_ob,user_ob;
login_ob = new(LOGIN_OB);
login_ob->set("id", replace_string(ids[i],".o",""));
login_ob->restore();
user_ob = find_player(replace_string(ids[i],".o",""));
if(user_ob) return 1;
user_ob = LOGIN_D->make_body(login_ob);
user_ob->restore();
user_ob->setup();
user_ob->move(environment(me));
user_ob->save();
destruct(login_ob);
destruct(user_ob);
return 1;
}


varargs int create_user_set(object me,string id,string key,mixed data,int i)
{
object login_ob,user_ob;
login_ob = new(LOGIN_OB);
login_ob->set("id", id);
login_ob->restore();
if(user_ob = find_player(id)) return 1;
user_ob = LOGIN_D->make_body(login_ob);
user_ob->restore();
user_ob->setup();
if(key)
user_ob->set(key,data);
user_ob->save();
destruct(login_ob);
if(i)
user_ob->move(environment(me));
else
destruct(user_ob);
return 1;
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
