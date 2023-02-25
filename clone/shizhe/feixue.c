// sunfenger.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
        set_name(HIG "飞靴" NOR, ({ "fei xue" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "穿上此鞋的人会轻功大增，可以瞬移师门！\n");
                set("no_sell", "这是什么东西？\n");
                set("base_value", 2);
                set("yuanbao",1);     
                set("no_sell", 1);
//set("no_get",1);
                set("no_drop",1);
                set("no_give",1);     
                set("base_weight", 1);
                set("base_unit", "把");
                set("yuanbao",1);
        }
        set_amount(1);
        setup();
}

void init()
{
        add_action("do_flyfrxx", "flyfrxx");
}

int do_flyfrxx(string arg)
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

		if (who->query("newbie") && !(who->query("born")))
		{
			tell_object(me,"想死用suicide快点！\n");
			return 1;
		}


	if (who->query("combat_exp") <= 10000)
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

        message_vision(HIM "$N" HIM "你穿上飞靴，顿时法力大增，嗖的一下不见了!"
                       "喝道：“喵~~~~~~！”\n"
                       "只听“唰”的一下，$N" HIM "不见了！"NOR"\n",
                       me);
        message("vision", HIM "忽见天边射来一道绿光，" + me->name() + HIM
                              "潇洒的跳了下来。"NOR"\n", env);
        tell_object(me, HIM "飞靴飞呀飞..."NOR"\n");
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

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
