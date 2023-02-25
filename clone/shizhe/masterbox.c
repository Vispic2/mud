#include <ansi.h>

inherit ITEM; 

void create()
{
	set_name (HIY"出师礼盒"NOR, ({ "master box"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","这是一个由檀木制成的出师礼盒，蕴含着一位师傅对徒弟殷切的关怀，"ZJURL("cmds:open master box")+ZJSIZE(20)+HIY"打开"NOR"它能够获得很多珍贵的礼物。\n");
	set("unit","个");
	set_weight(100);
	set("value",10000);
    set("no_give",1);
    set("no_drop",1);     
    set("no_sell",1);
//set("no_get",1);
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
	    
	if (!arg)
      		return notify_fail("你要开什么？\n");
      		
	if (arg!="master box")
      		return notify_fail("你要开什么礼盒？\n");
      		
        message_vision(HIY"$N打开了一个$n，
"HIW"$N获得了一串"HIG"葡萄"HIW"，
$N获得了一串"HIG"葡萄"HIW"，
$N获得了一串"HIG"葡萄"HIW"，
$N获得了一串"HIG"葡萄"HIW"，
$N获得了一串"HIG"葡萄"HIW"，
$N获得了三滴"HIG"天香玉露"HIW"，
$N获得了一串"MAG"神奇葡萄"HIW"，
$N增加了7天的会员时间"HIW"，
$N获得了一百两"HIY"黄金"HIW"，"NOR"\n", me, this_object()); 	

     ob1 = new("/clone/shizhe/putao");
     ob1->move(me);
     ob1 = new("/clone/shizhe/putao");
     ob1->move(me);
     ob1 = new("/clone/shizhe/putao");
     ob1->move(me);
     ob1 = new("/clone/shizhe/putao");
     ob1->move(me);
     ob1 = new("/clone/shizhe/putao");
     ob1->move(me);
     ob1 = new("/clone/shizhe/putao1");
     ob1->move(me);
     ob1 = new("/clone/shizhe/tianxiang");
     ob1->move(me);
     ob1 = new("/clone/shizhe/tianxiang");
     ob1->move(me);
     ob1 = new("/clone/shizhe/tianxiang");
     ob1->move(me);
	 ob1 = new("/clone/money/gold");
     ob1->set_amount(100);
     ob1->move(me); 
	 me->add("zjvip/times",86400*7);
	 
i=random(100);
if (i<25){
ob1 = new("/clone/shizhe/dan_dex");
ob1->move(me);
 message_vision(HIW"$N获得了一颗"HIR"火红仙丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=25 && i<50){
ob1 = new("/clone/shizhe/dan_str");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIG"神力丸"HIW"。"NOR"\n", me, this_object());
}
if (i>=50 && i<75){
ob1 = new("/clone/shizhe/dan_int");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"醍醐仙丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=75 && i<98){
ob1 = new("/clone/shizhe/dan_con");
ob1->move(me);
message_vision(HIW"$N获得了一颗"YEL"洗髓丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=98){
ob1 = new("/clone/shizhe/dan_jiuzhuan");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"九转金丹"HIW"。"NOR"\n", me, this_object());
}




	destruct(this_object());
	return 1;
}	 

int query_autoload() { return 1; }
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
