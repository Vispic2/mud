#include <ansi.h>

inherit "/clone/tattoo";

void create()
{
        set_name(NOR + HIR "朱雀图腾" NOR, ({ "zhuque tu", "zhuque", "tu" }));
            set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一张古旧的图片，上面绘着些纹样。");
                set("unit", "张");
                set("value", 10000);
                set("tuzhi", 50);
                set("material", "paper");
                set("tattoo_long", "神兽朱雀的纹样");
                set("can_tattoo", ({ "胸口", "脸部", "臀部", "后背", "左臂", "右臂" }));
                set("tattoo_type", ({ "身法" }));
                set("tattoo_dex", 1);
                
        }
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
