//离线任务 
#include <ansi.h>
inherit F_CLEAN_UP;
#define LX_D "/adm/daemons/lixiand"
int main(object me, string arg)
{

	if (!me->query("born"))
	return notify_fail("你还没出生呢。。。\n");
    if(!arg)
    {
     write(ZJOBLONG+HIR+ZJSIZE(25)+"离线任务，后续持续更新！"ZJBR+ZJSIZE(26)+HIY"注意：开启成功后quit会自动开启(不qiut也行)，quit后依旧保持在线随时随地下线不掉线，就算重启服务器你依旧不会掉线，重启后默认一直待在公共闭关室！"ZJBR+HIG+ZJSIZE(22)+"当前状态："+(me->query("guaji")<1?"关闭":"开启")+NOR+"\n"+ZJOBACTS2+ZJMENUF(2,2,9,32)
    "离线师门[开启]:lixian on"ZJSEP
    "离线师门[关闭]:lixian off\n");
	}
    if(arg=="on")
    {
    if (me->query("lixian2") < 1)
	return notify_fail("离线师门限权100元宝，访问商城进行购买。\n");
    me->set("guaji",10);
	me->set("startroom","/d/city/bgs");
	me->set("doings","lixian");
	LX_D->user_closed(me);
    write(HIY"开启离线师门成功，quit即可自动开启"NOR"\n");
    }
    if(arg=="off")
    {
	if (me->query("lixian2") < 1)
	return notify_fail("离线师门限权100元宝，访问商城进行购买。\n");
    me->set("guaji",0);
	me->set("startroom","/d/city/kedian");
	LX_D->user_opened(me);
    write(HIY"关闭离线师门成功，quit即可自动开启"NOR"\n");
    }
    
    return 1;
    
    }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
