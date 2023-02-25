inherit NPC;

void create()
{
	set_name("鱼精", ({"yu jing"}));
	set("long", "这是一只鱼精。\n");
	set("combat_exp", 100000);

	setup();
}

void die()
{
	object who;
	string id = query("player_id");
	object gift;
    
    if (!id || !(who = find_player(id)))
    {
        ::die();
    }
    
	if (random(10) == 3)
	{
		if (objectp(gift = new(__DIR__"obj/shuiyu")))
		{
			gift->move(who);
			tell_object(who, "你获得了一块水玉。\n");
		}
		else
		{
			tell_object(who, "击杀鱼精获得水玉出错，请联系管理员处理。\n");
		}
	}
	else
	{
		if (objectp(gift = new(__DIR__"obj/shuiyu_suipian")))
		{
			gift->move(who);
			tell_object(who, "你获得了一块水玉碎片。\n");
		}
		else
		{
			tell_object(who, "击杀鱼精获得水玉碎片出错，请联系管理员处理。\n");
		}
	}

	::die();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
