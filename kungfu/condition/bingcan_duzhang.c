#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "bingcan_duzhang"; }

string chinese_name() { return "冰蚕寒毒"; }

string update_msg_others()
{
       return HIW "$N" HIW "惨嚎一声，脸色铁青，全身浮现出一层寒气，不住的颤抖。"NOR"\n";
}

string update_msg_self()
{
	return HIW "你只觉极寒攻心，全身肌肉快要冻结一般。"NOR"\n";
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
