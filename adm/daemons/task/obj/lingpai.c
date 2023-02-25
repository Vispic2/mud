//TASK物品
//瞎三笨制作


#include <ansi.h>

#define  SET_TASK   "/adm/daemons/task/set_task"

inherit ITEM;


void create()
{
        set_name(HIR "天地会令牌" NOR, ({ "lingpai"}));
        if (clonep())
                destruct(this_object());
        else {
                set("unit", "个");
                set("owner_id", "chen jinnan");
                set("owner", "陈近南");

                set("value",10);
                set("no_sell",1);
                set("no_put",1);
        }
        setup();
}

void init()
{
	add_action("do_give","give");
}


int do_give(string arg)

{

	object me,ob;

	ob = this_object();
	me = this_player();

    return call_other(SET_TASK, "do_return", ob, me, arg);

}

string long()
{
        return "这是" + query("owner") + "的" + query("name") +
               "(" + query("id") + ")。\n";

}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
