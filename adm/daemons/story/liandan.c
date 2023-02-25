// story:liandan 炼丹

#include <ansi.h>

int give_gift();

static mixed *story = ({
	"两个童子拼命的煽火，只见炼丹炉中的火愈来愈旺。",
	"太上老君口中念念有词：疾！",
	"两个童子连忙开炉，一颗亮晶晶的仙丹腾空而起。",
	"太上老君金刚琢一抖，将仙丹圈下。",
	"太上老君举着仙丹看了半天，叹道：不知道这仙丹能不能发挥作用。",
	"太上老君：清风！来，你要不要试试这颗仙丹？",
	"清风忙不迭的摇头：师傅！我就算了吧。",
	"太上老君：明月？",
	"明月慌忙道：我，我，我已经吃错药了！",
	"太上老君长叹一声，道：还是丢下去给凡人试试吧。",
	(: give_gift :),
});

void create()
{
	seteuid(getuid());
}

mixed query_story_message(int step)
{
	return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
	STORY_D->give_gift("/clone/vip/dan_dex", 1,
			   HIM "\n“啪”的一声一颗仙丹掉到你面前。"NOR"\n");
	return 1;
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
