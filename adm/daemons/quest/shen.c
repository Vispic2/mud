// 玩家任务守护进程：shen.c

#include <ansi.h>

void startup();

// 任务对象创建
void create()
{
	seteuid(getuid());
	if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
	object qob;
	string qob_name;
	string *ob_names;

	if (sizeof(children("/clone/quest/shen")) > 10)
		// 系统中最多10个杀人加神的任务
		return;

	qob = new("/clone/quest/shen");
	qob->init_quest();
	CHANNEL_D->do_channel(find_object(QUEST_D),
			      "sys", "进程(SHEN)"
			      HIR "创建了一个任务。"NOR"");
}

private void heart_beat()
{
	if (! find_object(QUEST_D))
		return;

	// 如果可以，每次心跳产生一个QUEST
	start_quest();
}

// 任务守护进程唤醒这个进程
void startup()
{
	// 启动
	if (! find_object(QUEST_D))
		return;

	if (! query_heart_beat())
		CHANNEL_D->do_channel(find_object(QUEST_D),
				      "sys", "进程(SHEN)启动了。");

	// 平均每四分钟产生一个任务
	set_heart_beat(110 + random(20));
}

// 停止这个任务进程
void stop()
{
	set_heart_beat(0);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
