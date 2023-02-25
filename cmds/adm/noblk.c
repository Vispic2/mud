// channel block command..

#include <getconfig.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	
	if (! SECURITY_D->valid_grant(me, "(admin)") && !me->query("game_manager"))
		return 0;

	if (! arg)
		return notify_fail("指令格式: noblk <player id>\n");
    
	ob = UPDATE_D->global_find_player(arg);
	if (! ob)
		return notify_fail(LOCAL_MUD_NAME() + "并没有这个人！\n");

	if (wiz_level(ob) > 0)
	{
		UPDATE_D->global_destruct_player(ob);
		return notify_fail("你不能关闭巫师的频道。\n");
	}

	if (ob->query("chblk_on"))
	{
		UPDATE_D->global_destruct_player(ob);
		return notify_fail("这个人的频道已经被关闭了。\n");
	}

	ob->set("chblk_on", 1);
	ob->set("chblk_by", geteuid(me));
	write("你关闭了" + ob->name(1) + "的频道。\n");
	tell_object(ob, me->name(1) + "关闭了你的频道。\n");

	UPDATE_D->global_destruct_player(ob, 1);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : noblk <玩家>

此命令将关闭某个玩家的频道。

HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
