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
	set_name("不灭体残卷"NOR, ({"bu cj"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "页");
		set("base_weight", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("base_value", 100000);
		set("long","这是不灭体技能的残卷，据说凑足10页可以获得盖世武功。"NOR"\n");
        set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}

int do_effect(object me,string)
{
    object ob;
    if(query_amount() >= 10){
	ob = new("/d/city/books/bu-book");	
    ob->move(me);
    tell_object(me, "你将这些残卷慢慢融合在一起，你获得了："+ob->name()+"\n");
	add_amount(-10);
	}else
	if(query_amount() < 10)
	{
		tell_object(me, "你的残卷数量不够(需要10个)～赶紧多多收集吧！\n");
		return 1;
	}
		return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
