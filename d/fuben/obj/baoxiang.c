//baoxiang.c

#include <ansi.h>
inherit ITEM;
//必出物品随机列表
string *random_ob = ({
    "/clone/money/gold",
});
//随机爆出
string *random_item = ({
    "/clone/shizhe/jinsha",
});

void create()
{
	set_name(CYN"小宝箱" NOR, ({ "bao xiang" }));
	set("long", "一口小箱子，可以"+ZJURL("cmds:open_1 bao xiang")+ZJSIZE(22)+"打开"NOR+"来看看。\n");
	set("unit", "口");
	set("value", 10);
	set("no_get", "箱子仿佛生了根一样，你使出吃奶的力气也搬不动。");
	set("action_list", ([
		"打开" : "open_1 bao xiang",
	]));
	set_weight(1000000);
	
	setup();
}
void init()
{
	add_action("do_open_1", "open_1");
}
int do_open_1(string arg)
{
	string id2 = random_ob[random(sizeof(random_ob))];//必出物品列表
	string id = random_item[random(sizeof(random_item))];//随机出物品列表
	object ob, obj;
	object me = this_player();
	object player;
	int i,num;
	object oba, obb, obc;
	int ok = 0;
	object *obs = all_inventory(environment(this_object()));
	
	if (!arg || arg != "bao xiang")
		return notify_fail("你想打开什么？！\n");
	
	oba = present("tu fei", environment(me));
	obb = present("tufei tou", environment(me));
	obc = present("han fei", environment(me));
	
	foreach(player in obs) {
		if (userp(player))
		{
			if (oba) {
				oba->kill_ob(player);
				player->kill_ob(oba);
				tell_object(player, oba->name()+"对你大吼道：活得不耐烦了？敢在大爷面前偷东西！\n");
				ok = 1;
			}
			if (obb) {
				obb->kill_ob(player);
				player->kill_ob(obb);
				tell_object(player, obb->name()+"对你大吼道：想在我这里偷东西？我看你是找死！\n");
				ok = 1;
			}
			if (obc) {
				obc->kill_ob(player);
				player->kill_ob(obc);
				tell_object(player, obc->name()+"对你“嘿嘿！”一笑，你看得毛骨悚然！\n");
				ok = 1;
			}
		}
	}
	if (ok > 0)
		return 1;
	message_vision( "$N打开了" + name() + "。"NOR"\n", me);
	
	if (!query("open_1")) {
		switch (random(10))
		{
			case 0 : 
			case 5 :
			case 9 :
			ob = new(id);
			break;
		}
		if (ob && ob->move(me))
		tell_object(me, "恭喜你获得了"+ob->name()+"。"NOR"\n");
		
		//id2=黄金   id=金砂
		    obj = new(id2);
            num=1+random(20);
            obj->set_amount(num);
		    if (obj->move(me))
			tell_object(me, "恭喜你获得了"+chinese_number(num) + obj->query("unit")+ obj->name()+"。\n");		
	     	set("open_1", 1);
	} else 
		tell_object(me, "这口箱子里的东西已经被人拿光了。"NOR"\n");
	
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
