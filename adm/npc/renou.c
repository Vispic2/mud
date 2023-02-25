
#include <ansi.h>
int qilin_xiao();
inherit NPC;
void create()
{
	set_name(HIM "测试人偶"NOR, ({"ren"}) );
	set("long",  HIW"这是巫师大人做出来的人偶，提供玩家们测试技能。"NOR);
	set("gender", "男性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 1);
	set("int", 1);
	set("con", 1);
	set("dex", 1);
	set("qi", 888888888);
	set("max_qi", 888888888);
	set("max_jing", 888888888);
	set("neili", 888888888);
	set("max_neili", 888888888);
	set("combat_exp",888888888);
 set("chat_chance_combat", 90);
 set("chat_msg_combat", ({
                (: qilin_xiao :)
 }));
	setup();      
 carry_object("/clone/cloth/cloth")->wear();
 }               		
                		
int qilin_xiao()
{
        call_out("qilinyan", 1);
        return 1;
}

int qilinyan()
{
        int i;
        int dam;
        object *inv;
        inv = all_inventory(environment(this_object()));
        if (random(20) <= 5)
        {
        set("qi", 888888888);
        set("max_jing", 888888888);            
        message_vision( HIM"\n测试人偶恢复了血气。"+NOR+"\n",this_object());   
        }
        
        return 1;
}

 void die()
{
       ::die();
}
 
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
