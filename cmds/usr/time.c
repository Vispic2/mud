// time.c
#include <getconfig.h>
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    mixed *sj;
    string msg;
    int time = time();
	sj = localtime(time);
    msg=HIY"||----------〖"+LOCAL_MUD_NAME()+"〗时间详情--------||"ZJBR"";
    msg+=HIR"\t\t\t\t会员时间："+CHINESE_D->chinese_time(me->query("zjvip/times"))+ZJBR+"";
    msg+=HIM"\t\t\t\t北京时间："+ctime(time)+""ZJBR"";
    msg+=HIW"\t\t\t\t当前时间："+sj[5]+"年"+sj[4]+"月"+sj[3]+"号"+sj[2]+"时"+sj[1]+"分"+sj[0]+"秒"ZJBR"";
    msg+=HIG"||--------------------------------||";
    write(ZJOBLONG+msg+NOR+"\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time-

这个指令让你(你)知道现在的时辰。

HELP
    );
    return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
