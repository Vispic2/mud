
#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "兵器耐久石" NOR, ({ "nj shi", "njs" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "耐久石(nj id)可以将自造兵器进行加固。\n" NOR);
                set("unit", "颗");
                set("yuanbao", 10);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "nj");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid,namejia;
        int jiapoint,cgl;

        if (! arg)
                return notify_fail("你要往什么道具上使用兵器耐久石？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("你只能在兵器上使用兵器耐久石。\n");

     ob->add("consistence",100);
     tell_object(me, HIC "你感受到" + ob->name() + HIC"变的更坚韧了。\n" NOR);
        

        destruct(this_object());
        return 1;
}