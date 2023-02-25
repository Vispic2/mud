// version.c

#include <getconfig.h>
#include <version.h>

inherit F_CLEAN_UP;

void show_version();

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	int ver;

	if (arg == "stop" || arg == "cancel")
	{
		if (! SECURITY_D->valid_grant(me, "(admin)"))
			return 0;

		if (VERSION_D->clear_syn_info())
			write("清除了版本精灵正在的同步信息。\n");
		else
			write("目前版本精灵没有任何同步信息。\n");

		return 1;
	}

	if (arg == "sync" || arg == "SYNC")
	{
		if (! SECURITY_D->valid_grant(me, "(arch)"))
		{
			write("你没有权限同步" + LOCAL_MUD_NAME() +
			      "的版本。\n");
			return 1;
		}

		if (arg == "sync" &&
		    intp(ver = VERSION_D->query("VERSION_NO")) &&
		    time() > ver && time() - ver < 86400)
		{
			write("这个版本是最近一天生成的，你现在没有必要再同步。\n");
			return 1;
		}

		return VERSION_D->synchronize_version();
	}

	if (arg && sscanf(arg, "get %s", arg))
	{
		if (! SECURITY_D->valid_grant(me, "(admin)"))
		{
			write("你没有权限读取服务器上的文件。\n");
			return 1;
		}

		return VERSION_D->fetch_file(arg);
	}

	show_version();

	return 1;
}

void show_version()
{
	int ver;
	mapping si;
	int i;
	string k;
	int percent;

	if (! VERSION_D->is_version_ok())
	{
		write("目前版本正在同步中。\n");
		return;
	}

	if (! intp(ver = VERSION_D->query("VERSION_NO")) || ! ver)
	{
		write(sprintf("%s目前运行的版本不祥。\n",
			      LOCAL_MUD_NAME()));
		return;
	}

	write(sprintf("%s目前运行的版本是：%O[%s 生成]\n",
		      LOCAL_MUD_NAME(), ver, ctime(ver)));
	if (wiz_level(this_player()) > wiz_level("(arch)") &&
	    VERSION_D->is_release_server())
	{
		si = VERSION_D->query_socket_info();
		if (! mapp(si) || sizeof(si) < 1)
			write("目前没有其它站点在版本版本。\n");
		else
		{
			write("目前有 " + sizeof(si) + " 个站点在同步版本中。\n");
			i = 1;
			foreach (k in keys(si))
			{
				if (si[k][FILE_SIZE] < 1)
					percent = 100;
				else
					percent = si[k][FILE_POS] * 100 / si[k][FILE_SIZE];
	
				if (percent > 100)
					percent = 100;

				write(sprintf("%d. %s  正在传送：%s(%d%%)\n",
					      i, si[k][SUB_SITES],
					      stringp(si[k][FILE_NAME]) ? si[k][FILE_NAME] : "未知文件",
					      percent));
			}
			// 显示下一个同步信息
		}
	}
}

int help(object me)
{
	write(@HELP
指令格式 : version [sync] | get <file>
 
这个指令会显示游戏目前所用的 MudLib 版本。如果指明了sync参数，
则系统将尝试同步最新的版本。注意：在运行中同步是不可靠的，因
为系统不能自动的更新已经载入内存的对象，只有等所有内存中的对
象更新以后，版本才真正的同步了。因此同步完版本最好是重新启动
MUD 或是手工更新(update)那些不同的地方。

使用 version get <file> 可以读取服务器上 /version/  路径下面
的某个文件。
 
HELP );
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
