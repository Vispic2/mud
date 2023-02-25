
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
	set_name(HIY"师门奖励"NOR, ({"shi mens"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW"这是扫荡师门概率获得的奖励！\n"NOR);
		set("unit", "个");
		set("base_unit", "个");
//set("no_get",1);
		set("base_weight", 1);
		set("base_value", 1);
		set("yuanbao", 1);
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
i=random(100);

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
if (i>=4 && i<20){
ob1 = new("/clone/shizhe/puti-zi");
ob1->move(me);
message_vision(HIW"$N获得了一颗"YEL"菩提子"HIW"。"NOR"\n", me, this_object());
}
if (i>=20 && i<28){
ob1 = new("/clone/shizhe/fushougao");
ob1->move(me);
message_vision(HIW"$N获得了一块"YEL"福寿膏"HIW"。"NOR"\n", me, this_object());
}
if (i>=28 && i<29){
ob1 = new("/clone/shizhe/putao1");
ob1->move(me);
message_vision(HIW"$N获得了一颗"MAG"神奇葡萄"HIW"。"NOR"\n", me, this_object());
}
if (i>=29 && i<38){
ob1 = new("/clone/shizhe/putao");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIG"葡萄"HIW"。"NOR"\n", me, this_object());
}
if (i>=38 && i<45){
ob1 = new("/clone/shizhe/tianling");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIC"天灵丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=45 && i<46){
ob1 = new("/clone/shizhe/tianling2");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"玄灵丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=46 && i<47){
ob1 = new("/clone/shizhe/tiancs");
ob1->move(me);
message_vision(HIW"$N获得了一束"HIW"冰蚕丝"HIW"。"NOR"\n", me, this_object());
}
if (i>=47 && i<48){
ob1 = new("/clone/shizhe/butian");
ob1->move(me);
message_vision(HIW"$N获得了一块"MAG"补天石"HIW"。"NOR"\n", me, this_object());
}
if (i>=48 && i<60){
ob1 = new("/clone/shizhe/qiandai");
ob1->move(me);
message_vision(HIW"$N获得了一个"HIY"钱袋子"HIW"。"NOR"\n", me, this_object());
}
if (i>=60 && i<68){
ob1 = new("/clone/shizhe/tianxiang");
ob1->move(me);
message_vision(HIW"$N获得了一滴"HIG"天香玉露"HIW"。"NOR"\n", me, this_object());
}
if (i>=68 && i<69){
ob1 = new("/clone/shizhe/xuanhuang");
ob1->move(me);
message_vision(HIW"$N获得了一颗"MAG"玄黄紫清丹"HIW"。"NOR"\n", me, this_object());
}
if (i>=69 && i<78){
ob1 = new("/clone/shizhe/jinsha");
ob1->move(me);
message_vision(HIW"$N获得了一颗"HIY"金砂"HIW"。"NOR"\n", me, this_object());
}
if (i>=78 && i<80){
ob1 = new("/clone/shizhe/book_tianfu");
ob1->move(me);
message_vision(HIW"$N获得了一本"MAG"初级天赋书"HIW"。"NOR"\n", me, this_object());
}
if (i>=80 && i<81){
ob1 = new("/clone/shizhe/book_tianfu2");
ob1->move(me);
message_vision(HIW"$N获得了一颗"MAG"高级天赋书"HIW"。"NOR"\n", me, this_object());
}
if (i>=81 && i<82){
ob1 = new("/clone/shizhe/card_name");
ob1->move(me);
message_vision(HIW"$N获得了一张"HIR"改名卡"HIW"。"NOR"\n", me, this_object());
}
if (i>=82 && i<83){
ob1 = new("/clone/shizhe/30vip");
message_vision(HIR"$N获得一张VIP月卡"NOR"\n", me, this_object());
}
if (i>=83 && i<90){
ob1 = new("/clone/shizhe/dan_chongmai1");
message_vision(HIR"$N获得一颗下品冲脉丹"NOR"\n", me, this_object());
}
if (i>=91 && i<94){
ob1 = new("/clone/shizhe/dan_chongmai2");
message_vision(HIR"$N获得一颗中品冲脉丹"NOR"\n", me, this_object());
}
if (i>=94 && i<96){
ob1 = new("/clone/shizhe/dan_chongmai3");
message_vision(HIR"$N获得一颗上品冲脉丹"NOR"\n", me, this_object());
}
if (i>=96 && i<97){
ob1 = new("/clone/shizhe/dan_chongmai4");
message_vision(HIR"$N获得一颗极品冲脉丹"NOR"\n", me, this_object());
}
if (i == 98){
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
