// literateb4.c 论语
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"论语"NOR, ({ "literateb4", "shu4", "book4"}));
        set_weight(300);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "本");
            set("long","一本孔夫子的《论语》。\n");
            set("value", 4000);
//            set("value", 600000);
            set("material", "paper");
            set("skill", ([
                "name": "literate",    // name of the skill
                "exp_required": 10000,    // minimum combat experience required
                "jing_cost":    10,    // jing cost every time study this
                "difficulty":   25,    // the base int to learn this skill
                "max_skill":   119,    // the maximum level you can learn to
                "min_skill":   110,    // minimun level required
            ]) );
        }
}
int query_autoload()
{
        return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
