// summon command.

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string str;
	int i;

	if (wiz_level(me) < 1 ||
	    ! SECURITY_D->valid_grant(me, "(admin)"))
		return "/cmds/usr/summon"->main(me, arg);;

	if (! arg)
		return notify_fail("指令格式: Summon <player id> | <object>\n");

	if (sscanf(arg, ".%s", arg) ||
	    sscanf(arg, ". %s", arg))
		return "/cmds/usr/summon"->main(me, arg);

	str = arg;
	ob = find_player(str);
	//if (! ob)
	// ob = MESSAGE_D->find_user(str);
	if (objectp(ob) && ! me->visible(ob))
		ob = 0;
	if (! ob) ob = find_object(str);
	if (! ob)
	{
		str = resolve_path(me->query("cwd"), str);
		if (! sscanf(str, "%*s.c")) str += ".c";
		ob = find_object(str);
	}
	if (! ob)
		return "/cmds/usr/summon"->main(me, arg);

	if (wiz_level(ob) > wiz_level(me))
		return notify_fail("找踢啊。\n");

	if (environment(ob) == environment(me))
		return notify_fail("咦... 不就在你面前吗？\n");

	if (environment(ob) == me)
		return notify_fail("咦... 不就在你身上吗？\n");

	// moving
	tell_room(environment(ob), HIM "天空中伸出一只大手把"+
		  (string)ob->query("name") + HIM "抓了起来, 然後不见了。"NOR"\n", ob);
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	tell_object(me, HIM "你把" + ob->name() + HIM "抓到你的面前。"NOR"\n");
	tell_object(ob, HIM ".... 醒来时发现是" + me->name() + HIM
		    "把你弄过来的。"NOR"\n");
	tell_room(environment(me), HIM + ob->name() + HIM "突然出现" +
		  "在你眼前。"NOR"\n", ({ me, ob }));

	ob->move(environment(me));
      ob->set("startroom", "/d/city/kedian");

	// ok ..
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : summon <某人> | <物品> | .<物品>

此指令可让你(你)将某人或物品抓到你面前。

如果玩家 ID 和物品重名，可以在前面加注 . 表示指明物品。

该命令在可以被授权使用的信息包括：noneuser, user、all。
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
