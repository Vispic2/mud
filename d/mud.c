//by name
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIY "MUD收费站" NOR);
	set("long", "这是是MUD收费站，来到这里说明你该充值了，请前往购买游玩时间！\n");
	set("item_desc", ([
		"【牌子】" : "这是是MUD收费站，来到这里说明你该充值了，请前往购买游玩时间！\n"
		ZJOBACTS2+ZJMENUF(2,3,9,28)"兑换时间:paym_zh",
	]));             
	setup();
}
void init()
{
	if (!wizardp(this_player()))
	{
		add_action("discmds",({"walk","zdsm","use","eat","fly"}));
	}
}
int discmds()
{
	tell_object(this_player(),"不能在这里使用该指令！\n");
	return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
