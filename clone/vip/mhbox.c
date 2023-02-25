// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM"盲盒"NOR,({"mhbox1"}));
	set_weight(5000);
       
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"里面很多好东西，能开出什么看你的脸咯（小猪佩奇等高级纹身也在里面），"+this_object()->query("name")+",\n使用(openbox wsbox1)"ZJURL("cmds:openbox wsbox1")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
		set("yuanbao", 150);
                set("no_sell", 1);
		set("only_do_effect", 1);
		set("base_weight", 1);
		
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox wsbox1",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj=""; 
   object ob;

   string *box=
({
"/clone/vip/putao",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/putao",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/book_tianfu2",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/putao1",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/jiuzhuan",
"/clone/vip/card_name",
"/clone/vip/card_name",
"/clone/vip/xidian",
"/clone/vip/yanzhi",
"/clone/vip/yanzhi",
"/clone/vip/yanzhi",
"/clone/vip/jiuzhuan",
"/clone/vip/tianjin",
"/clone/tattoo/spc15",
"/clone/tattoo/spc16",
"/clone/tattoo/spc17",
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
       num=random(0)+1;
       ob->set_amount(num);
    }
    
  tell_object(me,""HIM"*****************************************************\n");
  tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIM"*****************************************************"NOR"\n");
    ob->move(me); 
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}