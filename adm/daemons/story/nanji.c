// story:nanji.c

#include <ansi.h>

string give_gift();

static mixed *story = ({
	"赤脚大仙：南极仙翁！您生日好。",
	"南极仙翁：呵呵，你好，你好。",
	"赤脚大仙：喏，这是我给你的礼物。",
	"南极仙翁：哈哈！还是你老兄聪明，就知道我喜欢喝酒。",
	"赤脚大仙：过奖过奖，对了，这是斗战胜佛让我转交的礼物。",
	"南极仙翁连忙接过。",
	"南极仙翁看了半天，道：什么破玩艺，黑不溜秋的，看来他做了佛也改不了猴性。",
	"南极仙翁随手把丹药扔了出去。",
	(: give_gift :),
	"南极仙翁：啊？那我快去找找！",
	"赤脚大仙：唉！",
});

void create()
{
	seteuid(getuid());
}

mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
	STORY_D->give_gift("/clone/gift/xisuidan", 1,
			   HIM "\n“啪”的一声一枚黑不溜秋的丹药掉到你面前。"NOR"\n");
	return "赤脚大仙急道：唉！老兄，你误会了！这是斗战胜佛蒙佛主所赐的洗髓丹，妙不可言。";
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
