// card3.c

inherit ITEM;

void create()
{
	set_name("青龙堂令牌", ({"card3"}));
	   if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long",
		"这是日月神教下第三大堂青龙堂令牌,上面刻有一条青龙神。\n");
	set("unit", "块");
	set_weight(10);
}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
