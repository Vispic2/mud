// freezing.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "freezing"; }

string chinese_name() { return "冰蚕寒毒"; }

string update_msg_others()
{
	switch (random(3))
	{
	case 0:
		return HIW "$N" HIW "的身子突然一晃，脸色变得苍白，牙齿不住的打颤。"NOR"\n";

	case 1:
		return HIW "$N" HIW "微微哼了一声，显是痛苦异常。"NOR"\n";

	default:
		return HIW "$N" HIW "呻咛了一下，脸上犹如蒙上一层白霜。"NOR"\n";
	}
}

string update_msg_self()
{
	return HIG "忽然浑身一阵寒冷，浑身几乎冻僵！"NOR"\n";
}

string die_reason()
{
	return "寒毒发作，冻僵倒毙";
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
