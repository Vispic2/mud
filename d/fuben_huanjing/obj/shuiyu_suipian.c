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
	set_name("水玉碎片", ({"shuiyu suipian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是水玉碎片。\n");
		set("base_unit", "片");
		set("base_weight", 10);
		set("base_value", 10000);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("only_do_effect", 1);
	}

	set_amount(1);
	setup();
}

int do_effect(object me)
{
	object ob;

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	if (query_amount() < 10)
		return notify_fail("你的碎片不足哦。\n");

	if (objectp(ob = new(__DIR__"shuiyu")))
	{
		ob->move(me);
		write("你合成了碎片，获得了一块水玉。\n");
		add_amount(-10);
	}
	else
	{
		return notify_fail("合成出错，请联系管理员处理。\n");
	}

	return 1;

}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
