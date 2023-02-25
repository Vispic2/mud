// remove.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_remove(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i;
	int count;

	if (! arg) return notify_fail("你要脱掉什么？\n");

	if (arg == "all")
	{
		inv = all_inventory(me);
		for (count = 0, i = 0; i < sizeof(inv); i++)
		{
			
			count += do_remove(me, inv[i]);
			inv[i]->set_temp("zhuangbei/yes",0);
		}
		if (count)
			write("你脱完了。\n");
		else
			write("你什么都没有脱下来。\n");
		return 1;
	}

	if (! objectp(ob = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
    ob->set_temp("zhuangbei/yes",0);
	if ((string)ob->query("equipped") != "worn")
	{
		inv = all_inventory(me);
		for (count = 0, i = 0; i < sizeof(inv); i++)
		{
			if (! inv[i]->id(arg))
				continue;
inv[i]->set_temp("zhuangbei/yes",0);
			if ((string)inv[i]->query("equipped") != "worn")
				continue;

			ob = inv[i];
			count++;
			break;
		}

		if (! count)
			return notify_fail("你并没有装备这样东西。\n");
	}

	return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
	string str;

	if ((string)ob->query("equipped")!="worn")
		return notify_fail("你并没有装备这样东西。\n");

	switch (ob->unequip())
	{
	case -1:
		return 1;

	case 0:
		return 0;

	default:
		if (! stringp(str = ob->query("remove_msg")))
			switch (ob->query("armor_type"))
			{
			case "cloth":
			case "armor":
			case "surcoat":
			case "boots":
				str = YEL "$N将$n" YEL "脱了下来。"NOR"\n";
				break;
			case "bandage":
				str = YEL "$N将$n" YEL "从伤口处拆了下来。"NOR"\n";
				break;
			default:
				str = YEL "$N卸除$n" YEL "的装备。"NOR"\n";
			}
		if (ob->query_temp("no_wear"))
			str += "脱下" + ob->name() + "以后你觉得舒服多了。\n";
		message_vision(str, me, ob);
		return 1;
	}
}

int help(object me)
{
	write(@HELP
指令格式 : remove all | <物品名称>
 
这个指令让你脱掉身上某件防具.
 
HELP );
	return 1;
}
 

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
