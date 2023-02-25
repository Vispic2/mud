//by name 2021.5.27
//qq 21315491
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
void create()
{
	//seteuid(ROOT_UID);
	seteuid(getuid());
	set("channel_id", "仆役奖励系统");
	CHANNEL_D->do_channel( this_object(), "sys", "仆役奖励系统开始运行。");
    set_heart_beat(3);
    call_out("jiazai",1);
}

void jiazai()
{
object s,room,*rooms;
rooms=get_dir("/d/kuangchang/");
foreach(room in rooms){
if(s = find_object("/d/kuangchang/"+room)){
destruct(s);
}
load_object("/d/kuangchang/"+room);
}
}
void heart_beat()
{
object *ob,*obs,ob1,obs1;
ob=users();
obs=objects();

foreach(ob1 in ob){
if(ob1->query("puyi_shulin")){
if(random(10)==5)
ob1->add("mucai_sl",ob1->query("puyi_shulin")*1);
}
if(ob1->query("puyi_guwu")){
if(random(10)==5)
ob1->add("liangshi_sl",ob1->query("puyi_guwu")*1);
}
if(ob1->query("puyi_shiliao")){
if(random(10)==5)
ob1->add("shiliao_sl",ob1->query("puyi_shiliao")*1);
}
if(ob1->query("puyi_tieliao")){
if(random(10)==5)
ob1->add("tieliao_sl",ob1->query("puyi_tieliao")*1);
}
}
//玩家下线仆役也自动下线
/*
foreach(obs1 in obs){
if(!obs1->query("puyi")) continue;
if(obs1->query("owner")==0) continue;
if(!find_player(""+obs1->query("owner")+"")){
destruct(obs1);
}
}
*/
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
