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
	set_name("水玉", ({"shui yu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是水玉。\n");
		set("base_unit", "块");
		set("base_weight", 10);
		set("base_value", 10000);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("is_shuiyu", 1);
	}

	set_amount(1);
	setup();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
