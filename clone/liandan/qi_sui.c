inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void create()
{
	set_name(HIR"持续回气碎片"NOR, ({"qi sui"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "块");
		set("base_weight", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("base_value", 1000);
		set("long","这是持续回血碎片。\n"HIR"注意：10个碎片合成为初级20个为中级30个为高级。"NOR"\n");
        set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}

int do_effect(object me,string)
{
    object ob;
    if(query_amount() > 30){
	ob = new("/clone/liandan/qi_3");	
    ob->move(me);
    tell_object(me, "你将这些碎片慢慢融合在一起，你获得了："+ob->name()+"\n");
	add_amount(-30);
	}else
    if(query_amount() > 20){
	ob = new("/clone/liandan/qi_2");	
    ob->move(me);
    tell_object(me, "你将这些碎片慢慢融合在一起，你获得了："+ob->name()+"\n");
	add_amount(-20);
	}else
    if(query_amount() > 10){
	ob = new("/clone/liandan/qi_1");	
    ob->move(me);
    tell_object(me, "你将这些碎片慢慢融合在一起，你获得了："+ob->name()+"\n");
	add_amount(-10);
	}else
	if(query_amount() < 10)
	{
		tell_object(me, "你的碎片数量不够哦(至少需要10个)～赶紧多多收集吧！\n");
		return 1;
	}
		return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
