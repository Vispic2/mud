#include <ansi.h>

inherit ITEM; 

void create()
{
	set_name (HIY"钱袋子"NOR, ({ "qiandai zi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","这是一个钱袋子，"ZJURL("cmds:open qiandai zi")+ZJSIZE(20)+HIY"打开"NOR"它能够获得一些金钱。\n");
	set("unit","个");
	set("no_sell", 1);
    set("no_drop",1);
    set("no_give",1); 
//set("no_get",1);
	set_weight(100);
	set("value",10000);
	setup();
     }
}


void init()
{
	add_action("do_read","open");
  
}

int do_read(string arg)
{
	object me=this_player();
	object ob1;
	int i,k;
	i=1+random(5);    

	if (!arg)
      		return notify_fail("你要打开什么？\n");
      		
	if (arg!="qiandai zi")
      		return notify_fail("你要打开什么？\n");

        message_vision("$N打开了一个$n。"NOR"\n", me, this_object()); 	

	ob1 = new("/clone/money/gold");
	ob1->set_amount(i);
	ob1->move(me); 

	tell_object(me,YEL"你获得了"+chinese_number(i)+"两黄金!"NOR"\n");
	destruct(this_object());
	return 1;
}	 

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
