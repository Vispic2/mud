// baibao.c
// by ranger_游侠

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping baowus;

void create()
{
	set_name(HIW"储物袋"NOR, ({ "chuwu dai" }) );
	set("long",HIW"一个神奇的袋子，可以存取许多宝贝。"NOR"\n");
	set("unit", "个");
	set("no_put", 1);
	set("no_get", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	seteuid(getuid());
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) ) return 0;

	return sprintf(DATA_DIR"baibao/%c/%s", id[0], id);
}

int set_owner(string id)
{
	set("owner_id", id);
	return 1;
}

void init()
{
	if(!query("owner_id"))
	{
		set_owner(this_player()->query("id"));
	}

	if(this_player()->query("id")==query("owner_id"))
	{
		add_action("do_cunbao","baocun");
		add_action("do_qubao","tiqu");
		add_action("do_chabao","dlist");
		restore();
	}
}

int do_cunbao(string arg)
{
	object me,ob;
	string *item_nb,nb;
	int i,snum;
	mapping info=([]);

	me = this_player();
	if(!arg)
		return notify_fail("你要向储物袋中存什么宝贝？\n");

	if(!objectp(ob=present(arg,me)))
		return notify_fail("你身上没有这种宝贝吧？\n");

//特殊物品不能保存
	if (ob->query("unique") || ! clonep(ob) )
	{
		tell_object(me, ob->name() + "不能放入储物袋。\n");
		return 1;
	}

//装备中物品不能保存
	switch((string)ob->query("equipped")) 
	{
	case "worn":
		tell_object(me, ob->name() + "必须先脱下来才能存放。\n");
		return 1;
	case "wielded":
		tell_object(me, ob->name() + "必须先解除装备才能存放。\n");
		return 1;
	}

//内含物品的容器物品不能保存
	if (sizeof(all_inventory(ob))) 
	{
		tell_object(me, "请你先把" + ob->query("name") + "里面的东西先拿出来。\n");
		return 1;
	}


//这里可以加入更多不能保存物品的判断
//////尸体，活物，等等。。。

	if(!clonep(ob)
	||ob->query("unique")
	||ob->query("treasure")
	||ob->query("owner")
	||ob->query("no_put")
	||ob->query("u_times")
	||ob->query("quest")
	||ob->is_corpse()
	||ob->query("food_remaining")
	||ob->query("liquid")
	||ob->query("material")=="meat"
	||ob->query("money_id")
	||ob->is_character()
	||(stringp(ob->query("owner")) && ob->query("owner")!="0")
	||ob->query("credit")
	) return notify_fail("这个东西不能存入储物袋。\n");

	snum = 20 + me->query("zjvip/all_pay")/10 + me->query("combat_exp")/50000;
        if (snum>100) snum=100;

	if (mapp(baowus)&&(sizeof(keys(baowus))>=snum))
		return notify_fail("你的储物袋已经放不下更多物品了，赶紧整理一下吧。\n");

	info["short"] = ob->query("name");
	info["id"] = ob->parse_command_id_list();
	info["file"] = base_name(ob);
	info["data"] = save_variable(ob->query_entire_dbase());
	if(ob->query_amount()) info["amount"] = ob->query_amount();

	if( !mapp(baowus)) baowus = ([]);
	if( baowus == ([]))
	{
		baowus["1"] = info;
		destruct(ob);
		save();
	}
	else
	{
		item_nb = sort_array( keys(baowus), (: strcmp :) );
		for(i=1; i<(sizeof(item_nb)+2); i++) {
			nb = sprintf("%d",i);
			if(undefinedp(baowus[nb]))
			{
				baowus[nb] = info;
		tell_object(me,"你把"+ob->query("name") + "存入储物袋！\n");
				destruct(ob);
				save();
				break;
			}
		}
	}
	if(objectp(ob))
		tell_object(me,"物品存入失败！\n");
	else
		tell_object(me,"物品存入成功！\n");
	return 1;
}

int do_qubao(string arg)
{
	object me,ob;
	string *item_nb;
	int i;

	me = this_player();

	if( !mapp(baowus) || baowus==([]))
		return notify_fail("你的储物袋中没什么东西可取的。\n");
	if(!arg)
		return notify_fail("你要从储物袋中取出什么宝贝？\n");

	if(undefinedp(baowus[arg]))
		return notify_fail("你的储物袋中没没有这个编号的物品。\n");

	ob = new(baowus[arg]["file"]);

	ob->set_entire_dbase(restore_variable(baowus[arg]["data"]));
	ob->set_name(baowus[arg]["short"],baowus[arg]["id"]);
	if(baowus[arg]["amount"]) ob->set_amount(baowus[arg]["amount"]);

	if(ob->move(me))
	{
		map_delete(baowus, arg);
		save();
		tell_object(me,"你把"+ob->query("name")+"从储物袋中取出！\n");
		tell_object(me,"物品取出成功！\n");
	}
	else
		tell_object(me,"宝物取出失败！\n");

	return 1;
}

int do_chabao(string arg)
{
	object me;
	string *item_nb;
	string msg, ob_name;

	me = this_player();

	msg = ZJOBLONG"这是一个神奇的袋子，可以存取好多东西。"ZJBR;
	if( !mapp(baowus) )
	{
		msg += "你目前没有存放任何物品在储物袋里。\n";
		return  notify_fail(msg);     
	}
	item_nb = sort_array( keys(baowus), (: strcmp :) );

	if( sizeof(item_nb)<1 )
	{
		msg += "你目前没有存放任何物品在储物袋里。\n";
		return  notify_fail(msg);     
	}

	msg += HIW"目前你储物袋的物品有："ZJBR
		  "一一一一一一一一一一一一一一一一一一一一一一一"NOR"\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	for (int i = 0; i < sizeof(item_nb); i++) 
	{
		ob_name = baowus[item_nb[i]]["short"];
		if(baowus[item_nb[i]]["amount"])
			ob_name += "["+baowus[item_nb[i]]["amount"]+"]";
		msg += sprintf("[%3s] %s:%s"ZJSEP, item_nb[i], ob_name,"tiqu "+item_nb[i]);
	}
	write(msg+"\n");
	return 1;
}	

string long()
{
	object me;
	string *item_nb;
	string msg, msg2,ob_name;

	me = this_player();

	msg = ZJOBLONG"这是一个神奇的袋子，可以存取好多东西。"ZJBR;
	if( !mapp(baowus) )
	{
		msg += "你目前没有存放任何物品在储物袋里。\n";
		write(msg+"\n");
		return  "";     
	}
	item_nb = sort_array( keys(baowus), (: strcmp :) );

	if( sizeof(item_nb)<1 )
	{
		msg += "你目前没有存放任何物品在储物袋里。\n";
		write(msg+"\n");
		return  "";     
	}

	msg += HIW"目前你储物袋的物品有："ZJBR
		  "一一一一一一一一一一一一一一一一一一一一一一一"NOR"\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	for (int i = 0; i < sizeof(item_nb); i++) 
	{
		ob_name = baowus[item_nb[i]]["short"]; 
		if(baowus[item_nb[i]]["amount"])
			ob_name += "["+baowus[item_nb[i]]["amount"]+"]";
		msg += sprintf("[%3s] %s:%s"ZJSEP, item_nb[i], ob_name,"tiqu "+item_nb[i]);
	}
	write(msg+"\n");
	return "";
}	

int query_autoload() { return 1; }

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
