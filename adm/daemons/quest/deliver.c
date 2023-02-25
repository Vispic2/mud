// 玩家任务守护进程：deliver.c

#include <ansi.h>

string *ob_list = ({
	"/clone/questob/rice",
	"/clone/questob/cloth",
	"/clone/questob/spice",
	"/clone/questob/bait",
	"/clone/questob/wood",
	"/clone/questob/metal",
	"/clone/questob/farm",
	"/clone/questob/silver",
	"/clone/questob/gold",
});

void startup();

// 任务对象创建
void create()
{
	seteuid(getuid());
	if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
	object qob;     // 任务物件
	string name;    // 要送的货物
	int amount;     // 送货的数量

	if (sizeof(children("/clone/quest/deliver")) > 30)
		// 系统中最多20个送货的任务
		return;

	name = ob_list[random(sizeof(ob_list))];
	amount = 1;

	qob = new("/clone/quest/deliver");
	qob->init_quest(name, amount);

	CHANNEL_D->do_channel(find_object(QUEST_D),"sys", "进程(DELIVER)利用" + get_object(name)->name() + HIR "创建了一个任务。"NOR"");
}

private void heart_beat()
{
	if (! find_object(QUEST_D))
		return;

	// 如果可以，每次心跳产生三个QUEST
	start_quest();
	start_quest();
	start_quest();
}

// 任务守护进程唤醒这个进程
void startup()
{
	// 启动
	if (! find_object(QUEST_D))
		return;

	if (! query_heart_beat())
		CHANNEL_D->do_channel(find_object(QUEST_D),"sys", "进程(DELIVER)启动了。");

	// 平均每1分钟产生一个任务
	set_heart_beat(50 + random(10));
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
