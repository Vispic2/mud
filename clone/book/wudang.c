#include <ansi.h>
#include <medical.h>

inherit MEDICAL_BOOK;

void create()
{
	set_name(WHT "「武当药理」" NOR, ({ "wudang yaoli", "yaoli", "book", "shu" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", WHT "一本陈旧的书册，封面用草书写有「武当药理」四字。"NOR"\n");
		set("material", "paper");
		set("value", 1);
		set("no_sell", "嘿，这本破书也能卖钱？");
		set("skill", ([
			"name" : "liandan-shu",
			"jing_cost" : 40,
			"difficulty" : 50,
			"max_skill" : 149,
			"min_skill" : 50,
		]));

		set("can_make", ([
			"liuhe"    : 80,	 // 六合返精散
			"qingxin"  : 100,	// 清心定神散
			"zhending" : 150,	// 固元镇定散
			"dieda"    : 80,	 // 跌打伤愈膏
			"huojin"   : 100,	// 活筋舒血丸
			"tongmai"  : 150,	// 贯气通脉丹
			"jiedu"    : 100,	// 牛黄解毒丸
			"baihu"    : 200,	// 白虎夺命丹
			"baola"    : 220,	// 三黄宝腊丹
		]));
	}
	setup();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
