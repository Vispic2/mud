// qinfo.c
#include <ansi.h>
inherit F_CLEAN_UP;
string time_len(int n)
{
	return sprintf("%.2d:%.2d:%.2d", n / 3600, (n % 3600) / 60, n % 60);
}


int main(object me, string arg)
{
	mapping total;
	object *obs;
	object qob;
	string str;

	seteuid(getuid());


	total = QUEST_D->query("information");
	if (! mapp(total))
		return notify_fail("当前系统没有任何任务。\n");

	obs = keys(total);
	obs = filter_array(obs, (: objectp($1) :));

	if (! sizeof(obs))
		return notify_fail("当前系统没有任何任务。\n");


	str = WHT "\t\t\t任务名称	                     执行时间                 状  态    "NOR+ZJBR""
	      HIW "──────────────────────────────────"NOR+ZJBR"";
	foreach (qob in obs)
	{
		str += sprintf("\t\t\t%-28s%-26s%s"ZJBR"",
			       qob->name(),
			       time_len(time() - qob->query("start_time")),
			       qob->query_status());
	}
	str += HIW "──────────────────────────────────"NOR+ZJBR""
	       WHT "\t\t\t\t\t\t\t\t\t\t\t\t系统目前共有 " CYN + sizeof(obs) + WHT " 个任务。"NOR"\n";

	write(ZJMAPTXT+str);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : qinfo [<任务名称>]

此指令可查看当前系统有的任务。
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
