// shuisheng 水笙
#include <ansi.h>
inherit NPC;

void greeting(object me);

void create()
{
	set_name("水笙", ({ "shui sheng","shuisheng"}));
	set("long", "她轻妆淡抹，眉目之中深深的透露哀思。\n");
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 25);

	setup();
	carry_object("/clone/cloth/cloth.c")->wear();
}

void init()
{
	object me;

	::init();
	me = this_player();
	if (! objectp(me) || ! userp(me))
		return;

	remove_call_out("greeting");
	call_out("greeting", 0, me);
}

void greeting(object me)
{
	if (! objectp(me) || environment(me) != environment(this_object()))
		return;

	if (! stringp(me->query("character")))
	{
		command("tell " + me->query("id") + " 你还没有选择品质，快去附近四处看看选选吧。
"HIW"往东走，是光明磊落，对应的宗师武功是九阴神功，要求高臂力；
"HIY"往南走，是狡黠多变，对应的宗师武功是不败神功，要求高悟性；
"MAG"往东走，是阴险奸诈，对应的宗师武功是葵花魔功，要求高身法；
"YEL"往东走，是心狠手辣，对应的宗师武功是南海玄功，要求高根骨。"NOR"
"HIG"详情你可以参阅 游戏指南 技能介绍 武学总纲下篇 。
新人们请注意出生后先仔细看更新公告，与游戏指南，新手指南！");
		return;
	}

	if (! wizardp(me))
	{
		command("tell " + me->query("id") + " 咦，你怎么跑到这里来了？");
		if (! stringp(me->query("born")))
		{
			message_vision("$N被昏昏沉沉的扔了出去。\n", me);
			me->delete("born");
			me->move("/d/register/yanluodian");
			message_vision("啪的一声，$N被扔到了地上。\n", me);
			return;
		}

		message_vision("$N被昏昏沉沉的扔了出去。\b", me);
		me->move(VOID_OB);
		message_vision("啪的一声，$N被扔到了地上。\n", me);
		return;
	}

	command("look " + me->query("id"));
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
