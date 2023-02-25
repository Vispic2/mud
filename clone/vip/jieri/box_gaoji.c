// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM"高级宝箱"NOR,({"box no3"}));
	set_weight(5000);
       
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是商店里出售的"+this_object()->query("name")+",\n使用(openbox boxno3)"ZJURL("cmds:openbox box no3")ZJSIZE(22)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("yuanbao", 10);
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox box no3",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj=""; 
   object ob;
 /*
   * 黄金,退烧药,膏药,伤寒愁,糖果,新手套装,酒袋,鸡腿,秘籍详解,千字文
  */
   string *box=
({
"/clone/money/gold",
"/clone/suit/huashan/ling_boots","/clone/suit/huashan/ling_cloth","/clone/suit/huashan/ling_pants","/clone/suit/huashan/ling_sword",
"/clone/book/advance-blade","/clone/book/advance-club","/clone/book/advance-dagger","/clone/book/advance-dodge",
"/clone/book/advance-force","/clone/book/advance-parry","/clone/book/advance-staff",
"/clone/book/advance-sword","/clone/book/advance-throwing","/clone/book/advance-unarmed","/clone/book/advance-whip",
"/clone/book/lbook1","/clone/book/lbook2","/clone/book/lbook3","/clone/book/lbook4",
"/clone/money/gold",
"/clone/suit/huashan/ling_boots","/clone/suit/huashan/ling_cloth","/clone/suit/huashan/ling_pants","/clone/suit/huashan/ling_sword",
"/clone/book/advance-blade","/clone/book/advance-club","/clone/book/advance-dagger","/clone/book/advance-dodge",
"/clone/book/advance-force","/clone/book/advance-parry","/clone/book/advance-staff",
"/clone/book/advance-sword","/clone/book/advance-throwing","/clone/book/advance-unarmed","/clone/book/advance-whip",
"/clone/book/lbook1","/clone/book/lbook2","/clone/book/lbook3","/clone/book/lbook4",
"/clone/money/gold",
"/clone/suit/huashan/ling_boots","/clone/suit/huashan/ling_cloth","/clone/suit/huashan/ling_pants","/clone/suit/huashan/ling_sword",
"/clone/book/advance-blade","/clone/book/advance-club","/clone/book/advance-dagger","/clone/book/advance-dodge",
"/clone/book/advance-force","/clone/book/advance-parry","/clone/book/advance-staff",
"/clone/book/advance-sword","/clone/book/advance-throwing","/clone/book/advance-unarmed","/clone/book/advance-whip",
"/clone/book/lbook1","/clone/book/lbook2","/clone/book/lbook3","/clone/book/lbook4",
"/clone/money/gold",
"/clone/suit/huashan/ling_boots","/clone/suit/huashan/ling_cloth","/clone/suit/huashan/ling_pants","/clone/suit/huashan/ling_sword",
"/clone/book/advance-blade","/clone/book/advance-club","/clone/book/advance-dagger","/clone/book/advance-dodge",
"/clone/book/advance-force","/clone/book/advance-parry","/clone/book/advance-staff",
"/clone/book/advance-sword","/clone/book/advance-throwing","/clone/book/advance-unarmed","/clone/book/advance-whip",
"/clone/book/lbook1","/clone/book/lbook2","/clone/book/lbook3","/clone/book/lbook4",
"/clone/vip/putao",
"/clone/vip/unknowdan",
"/clone/vip/shenliwan",
"/clone/vip/xiandan",
"/clone/vip/xisuidan",
"/clone/vip/avipcard",
"/clone/book/mengzi",
});
  
	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
	message_vision(HIM"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵紫色光华！"NOR"\n",me);
	i=random((int)sizeof(box));
    
	ob = new(box[i]); 
   
    if(ob->query("base_value"))
    {
       num=random(5)+1;
       ob->set_amount(num);
    }
    
  tell_object(me,""HIM"*****************************************************\n");
  tell_object(me,""HIR"恭喜"NOR"：你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIM"*****************************************************"NOR"\n");
    ob->move(me); 
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}