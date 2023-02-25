// clear.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target;
	object obj;
	object *obs;
	string ob_name;
	int remove_flag;

	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	seteuid(getuid(me));

	if (! arg) return notify_fail("指令格式 : clear [-u] <物件之名"
				      "称或档名> | <玩家ID> <分项>\n" );

	if (sscanf(arg, "-u %s", arg) == 1)
	{
		if (sscanf(arg, "%s %s", target, arg) != 2)
		{
			write("你必须指明清除用户的什么数据。\n");
			return 1;
		}

		// clear the user data
		write ("清除用户(" + target + ")的数据：" +
		       UPDATE_D->clear_user_data(target, arg));
		return 1;
	}

	if (arg == "-u")
	{
		help(me);
		return 1;
	}

	// check the remove flag
	remove_flag = sscanf(arg, "-remove %s", arg);
	
	target = arg;
	obj = find_object(target);
	if ((! obj  || userp(obj)) && file_size(target + ".c") >0 )
		catch(obj = load_object(target));
	if (! obj || userp(obj)) obj = present(target, me);
	if (! obj || userp(obj)) obj = present(target, environment(me));
	if (! obj || userp(obj)) obj = find_object(resolve_path(me->query("cwd"), target));
	if (! obj || userp(obj)) catch(obj = load_object(resolve_path(me->query("cwd"), target)));
	if (obj && ! userp(obj))
	{
		message_vision(sprintf("$N将物件<%O>连同存盘记录一起"
				       "彻底的摧毁了。\n", obj), me);
		if (! clonep(obj))
		{
			obs = filter_array(all_inventory(obj), (: userp :));
			obs->move(VOID_OB, 1);
		} else
			obs = 0;

		target = base_name(obj);

		if (! DBASE_D->clear_object(obj))
			write ("你没有能够成功的摧毁物件和记录。\n");
		else
		{
			if (remove_flag)
			{
				seteuid(getuid());
				if (rm(target + ".c") == 1)
					write("文件 " + target + ".c 已经成功删除。\n");
				else
					write("删除文件 " + target + ".c 失败。\n");
			} else
			if (arrayp(obs) && sizeof(obs))
				obs->move(target, 1);
			write("Ok.\n");
		}
	} else
	{
		write("你试图从数据库中清除条目(" + target + ")的记录。\n");
		if (! DBASE_D->clear_object(target))
			write ("你没有能够成功的清除记录。\n");
		else
			write("Ok.\n");
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : clear -u <玩家ID> <分项>
		 [-remove] <物件之名称或档名>

利用此一指令可将一个物件(object)连同它的存盘记录一起清除，注
意：这里的存盘记录指的是数据保存在 DBASE_D 中的那些对象， 如
果记录是保存成单独的文件，则它们的存盘记录不会受到任何影响，
这个命令是提供给巫师对受到损伤的对象进行数据修复时使用的。

如果使用参数 -u，则表示是要清除一个玩家对 MUD 中的对象数据，
比如说住房的信息就可以通过该命令清除。即将指定的玩家的住房拆
毁。

分项包括：all      所有数据
	  balance  存款
	  board    留言版
	  couple   婚配
	  item     道具
	  name     姓名
	  room     房屋
	  brothers 结义
	  league   联盟
	  title    称号

如果使用了 -remove 参数， 表示清除物件的存盘记录以后删除这个
文件。这个参数需要谨慎使用。

参考资料： dest，query
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
