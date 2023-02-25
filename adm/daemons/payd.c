//by name 收费MUD
#include <ansi.h>
inherit F_DBASE;
inherit F_SAVE;
void create()
{
	seteuid(getuid());
	set("channel_id", "收费精灵");
	CHANNEL_D->do_channel( this_object(), "sys", "NAME收费精灵系统开始运行。");
    set_heart_beat(0);
}
void heart_beat()
{
    object ob,*obs=users();
    foreach(ob in obs){
        if(!ob->query("paymd/times")){
            ob->move("/d/mud");
            continue;
        }
        if((ob->query("paymd/times")<86400/4)&&(random(100)==1)){
        tell_object(ob,"你的MUD游玩时间仅剩："+CHANNEL_D->chinese_time(ob->query("paymd/times"))+"，请立即购买游玩时间！");
        }
        ob->add("paymd/times",-1);
    }
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
