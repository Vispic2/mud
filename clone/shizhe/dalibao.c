
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIY"幸运大礼包"NOR, ({"xingyun bao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"里面似乎有些东西，是什么呢？打开看看吧！\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10000);
//set("no_get",1);
		set("yuanbao", 1200);
        set("no_sell", 1);
        set("no_drop",1);
        set("no_give",1); 
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int i,ob1;

    if (me->is_busy())
            return notify_fail("你正忙着呢。\n");
i=random(51);

if (i<1)
{
ob1 = new("/clone/shizhe/dan_dex");
ob1->move(me);
 message_vision(HIW"$N获得了一颗"HIR"火红仙丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=1 && i<2){
ob1 = new("/clone/shizhe/dan_str");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIG"神力丸"HIW"。"NOR"\n", me, this_object());
}
if (i>=2 && i<3){
ob1 = new("/clone/shizhe/dan_int");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"醍醐仙丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=3 && i<4){
ob1 = new("/clone/shizhe/dan_con");
ob1->move(me);
message_vision(HIW"$N获得了一颗"YEL"洗髓丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=4 && i<8){
ob1 = new("/clone/shizhe/puti-zi");
ob1->move(me);
message_vision(HIW"$N获得了一颗"YEL"菩提子"HIW"。"NOR"\n", me, this_object());
}
if (i>=8 && i<9){
ob1 = new("/clone/shizhe/fushougao");
ob1->move(me);
message_vision(HIW"$N获得了一块"YEL"福寿膏"HIW"。"NOR"\n", me, this_object());
}
if (i>=9 && i<10){
ob1 = new("/clone/shizhe/putao1");
ob1->move(me);
message_vision(HIW"$N获得了一颗"MAG"神奇葡萄"HIW"。"NOR"\n", me, this_object());
}
if (i>=10 && i<13){
ob1 = new("/clone/shizhe/putao");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIG"葡萄"HIW"。"NOR"\n", me, this_object());
}
if (i>=13 && i<15){
ob1 = new("/clone/shizhe/tianling");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIC"天灵丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=15 && i<16){
ob1 = new("/clone/shizhe/tianling2");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"玄灵丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=16 && i<17){
ob1 = new("/clone/shizhe/tiancs");
ob1->move(me);
message_vision(HIW"$N获得了一束"HIW"冰蚕丝"HIW"。"NOR"\n", me, this_object());
}
if (i>=17 && i<18){
ob1 = new("/clone/shizhe/butian");
ob1->move(me);
message_vision(HIW"$N获得了一块"MAG"补天石"HIW"。"NOR"\n", me, this_object());
}
if (i>=18 && i<30){
ob1 = new("/clone/shizhe/qiandai");
ob1->move(me);
message_vision(HIW"$N获得了一个"HIY"钱袋子"HIW"。"NOR"\n", me, this_object());
}
if (i>=30 && i<33){
ob1 = new("/clone/shizhe/tianxiang");
ob1->move(me);
message_vision(HIW"$N获得了一滴"HIG"天香玉露"HIW"。"NOR"\n", me, this_object());
}
if (i>=33 && i<34){
ob1 = new("/clone/shizhe/xuanhuang");
ob1->move(me);
message_vision(HIW"$N获得了一颗"MAG"玄黄紫清丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=34 && i<38){
ob1 = new("/clone/shizhe/jinsha");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"金砂"HIW"。"NOR"\n", me, this_object());
}
if (i>=38 && i<40){
ob1 = new("/clone/shizhe/book_tianfu");
ob1->move(me);
message_vision(HIW"$N获得了一本"MAG"初级天赋书"HIW"。"NOR"\n", me, this_object());
}
if (i>=40 && i<41){
ob1 = new("/clone/shizhe/book_tianfu2");
ob1->move(me);
message_vision(HIW"$N获得了一颗"MAG"高级天赋书"HIW"。"NOR"\n", me, this_object());
}
if (i>=41 && i<42){
ob1 = new("/clone/shizhe/card_name");
ob1->move(me);
message_vision(HIW"$N获得了一张"HIR"改名卡"HIW"。"NOR"\n", me, this_object());
}
if (i>=42 && i<43){
me->add("yuanbao",100);
message_vision(HIR"$N获得了一百个元宝"NOR"\n", me, this_object());
}
if (i>=43 && i<45){
me->add("yuanbao",50);
message_vision(HIR"$N获得了五十个元宝"NOR"\n", me, this_object());
}
if (i>=45 && i<48){
me->add("yuanbao",10);
message_vision(HIR"$N获得了十个元宝"NOR"\n", me, this_object());
}
if (i>=48 && i<49){
ob1 = new("/clone/shizhe/30vip");
message_vision(HIR"$N获得一张VIP月卡"NOR"\n", me, this_object());
}
if (i>=50){
ob1 = new("/clone/shizhe/dan_jiuzhuan");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"九转金丹"HIW"。"NOR"\n", me, this_object());
}			
	add_amount(-1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
