#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"心魔"NOR, ({ "xin mo" }));
        set("long", "这是一个心魔。\n");
        set("title", HIB "(鬼气)" NOR);

        set("str", 100);
        set("con", 100);
        set("dex", 100);
        set("int", 100);
        set("max_jing", 10000);
        set("max_neili", 10000);
        set("max_jingli", 10000);
        set("chat_chance_combat", 100);
        set("combat_exp", 100000000);
        set("bellicosity", 5 );

        setup();
}

void die()
{
        object me,ob,obj,env;
        env = environment(this_object());
        obj = new("/clone/vip/putao");
        obj->move(env, 1);
        obj = new("/clone/shizhe/xm");
        obj->move(env, 1);   
        message_vision("\n$N化作一滩淤血，消失了。\n", this_object());
        ::die();
} 
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
