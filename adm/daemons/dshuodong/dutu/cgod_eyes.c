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
	set_name(HIW"顶级宝石碎片"NOR, ({"suipian"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "块");
		set("base_weight", 1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("base_value", 80000);
		set("long","顶级碎片，可以用来合成五大宝石。\n");
        set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}

int do_effect(object me)
{
    object ob;
    
	if(query_amount() < 100)
	{
		tell_object(me, "你的碎片数量不够哦～赶紧多多收集吧！\n");
		return 1;
	}
	else if (me->query("max_neili") < 500)
	{
	    write("你的内力不足500，无法合成。\n");
	    return 1;
	}
	else if(random(2))
	{	
		ob = new("/clone/baoshi/god_eyes"+random(5)+"");
		if (objectp(ob))
		    ob->move(me);
		else
		{
		    write("出错，请联系管理员处理。\n");
		    return 1;
		}
		me->add("max_neili", -500);
		tell_object(me, "你将碎片拼凑成上"+ob->name()+"的形状，注入内力，碎片亮起微光，碎片慢慢融合在一起。\n");
		add_amount(-100);
		return 1;
	}
	
    me->add("max_neili", -500);
	tell_object(me, "你往碎片中注入内力，可惜合成失败，碎片化作点点荧光消散在空中。\n");
	add_amount(-100);
	return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
