// card2.c

inherit ITEM;

void create()
{
	set_name("白虎堂令牌", ({"card2"}));
	   if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long",
		"这是日月神教下第二大堂白虎堂令牌,上面刻有一只白虎神。\n");
	set("unit", "块");
	set_weight(10);
}
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
