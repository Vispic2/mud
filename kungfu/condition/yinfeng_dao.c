#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "yinfeng_dao"; }

string chinese_name() { return "阴风刮骨之扰"; }

string update_msg_others()
{
       return HIW "$N惨嚎一声，只觉全身肌肉就像要撕裂开一般，豆大的汗珠不住的滴下。"NOR"\n";
}

string update_msg_self()
{
	return HIW "你感到一股切骨奇寒由伤口处升起，看来是中了阴风刀内劲的干扰！"NOR"\n";
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
