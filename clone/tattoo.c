#include <ansi.h>
inherit ITEM;

string long();

void create()
{
        set_name(NOR + WHT "精忠报国" NOR, ({ "tattoo paper", "tattoo", "paper" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一张古旧的图片，上面绘着些纹样。");
                set("unit", "张");
                set("material", "paper");
                set("value", 100000);                        
                set("tattoo_long", "精忠报国四个大字");   
                set("can_tattoo", ({ "脸部", "胸口", "后背", "左臂", "右臂", "臀部", })); 
                set("tattoo_type", ({ "膂力", "悟性", "根骨", "身法","容貌", }));
                set("str", 1);                     
                set("int", 1);                    
                set("con", 1);
                set("dex", 1);
                set("per", 1);             
        
        }
}

string long()
{
        string msg;
        

        if (query("can_tattoo"))
        {
        msg = WHT "这是一张" + name() + NOR + WHT "，图中描着" +HIR+ query("tattoo_long") + NOR+"。你可以让纹身师傅参照着图样在你的" + replace_string(implode(query("can_tattoo"),"、"),"\n","") + "上刺青，以提高你的" + replace_string(implode(query("tattoo_type"),"、"),"\n","") + "。";
        }
         else
         msg = "这是一张古旧的图片，上面绘着些纹样。";
        
        //return sort_string(msg, 54);
        return msg+"\n";
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
