// sunfenger.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name("飞剑", ({ "fei jian" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是神奇的蜀山千里追魂剑，可以瞬间飞往(fly)其他人身边。\n");
                set("no_sell", "这是什么东西？\n");
                set("base_value", 10000);
                set("base_weight", 10);
				set("yuanbao", 1);
                set("base_unit", "把");
        }
        set_amount(1);
        setup();
}

void init()
{
        add_action("do_flyto", "flyto");
}

int do_flyto(string arg)
{
        object me;
        object who;
        object env;

        if (! query_amount())
                return 0;
        me = this_player();
        if (! arg)
                return notify_fail("你想飞到谁的身边？\n");

        who = find_player(arg);
        if (! objectp(who)) who = find_living(arg);
        if (! objectp(who))
                return notify_fail("没有这个人啊！\n");

        if (! objectp(env = environment(who)))
                return notify_fail("这个人不知道在那里耶！\n");

		if (me->is_ghost())
			return notify_fail("等你还了阳再说吧。\n");

		if (! wizardp(me) && wizardp(who))
			return notify_fail("你想被踢吗。\n");

		if (! wizardp(me) && userp(who))
			return notify_fail("你不能飞到玩家身上。\n");

        if (env == environment(me))
                return notify_fail("你在原地乱蹦哒的啥？\n");
			
		if (who->query("qianchipu2") && !(who->query("born")))
			tell_object(me,"想死用suicide快点！\n");

		if (who->query("newbie") && !(who->query("born")))
		{
			tell_object(me,"想死用suicide快点！\n");
			return 1;
		}


	if (who->query("combat_exp") <= 100000)
	{
		tell_object(me,"不能飞新手！\n");
		return 1;
	}

	if (environment(who)->query("no_magic"))
		return notify_fail("你到不了那地方。\n");

	if (me->is_busy())
		return notify_fail("等你忙完了再说。\n");

	if (me->query("doing"))
		return notify_fail("等你计划完了再说。\n");

        message_vision(HIM "$N" HIM "掐起御剑诀，跳上飞剑，"
                       "喝道：“喵~~~~~~！”\n"
                       "只听“唰”的一下，$N" HIM "不见了！"NOR"\n",
                       me);
        message("vision", HIM "忽见天边射来一道飞剑，" + me->name() + HIM
                              "潇洒的跳了下来。"NOR"\n", env);
        tell_object(me, HIM "飞剑飞呀飞..."NOR"\n");
        me->move(env);

        add_amount(-1);
        return 1;
}

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
        int amt;

        if (sscanf(param, "%d", amt) == 1)
                set_amount(amt);
}
