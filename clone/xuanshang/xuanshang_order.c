inherit ITEM;

#define XUANSHANGD "/adm/daemons/xuanshangd"

void create()
{
	set_name("悬赏令", ({"xuanshang ling"}));
	set("long", "悬赏令。\n");

	set("unit", "张");
	setup();
}

string query_autoload() { return query("xuanshang_name") + "|" + query("xuanshang_id"); }


void destruct_this_order(string xuanshang_id)
{
	mapping xuanshang;

	if (!sizeof(xuanshang = XUANSHANGD->get_xuanshang()))
	{
		destruct(this_object());
	}

	if (undefinedp(xuanshang[xuanshang_id]))
	{
		destruct(this_object());
	}
}

void autoload(string param)
{
	string xuanshang_id;
	string xuanshang_name;

	if (sscanf(param, "%s|%s", xuanshang_name, xuanshang_id) != 2)
	{
		destruct(this_object());
		return ;
	}

	call_out("destruct_this_order", 1, xuanshang_id);

    set_name(xuanshang_name + "悬赏令", ({ xuanshang_id + "-order" }));
    set("xuanshang_name", xuanshang_name);
    set("xuanshang_id", xuanshang_id);
}

void destruct_all_order()
{
	object * order;
	object temp;

	order = filter_array(children(base_name(this_object())), (: $1->query("xuanshang_id") == this_object()->query("xuanshang_id") :));
	if (sizeof(order))
	{
		foreach(temp in order)
		{
			if (temp == this_object())
				continue;

			destruct(temp);
		}
		destruct(this_object());
	}
}

void finish_xuanshang(object killer, object victim)
{
	mapping xuanshang = XUANSHANGD->get_xuanshang();
	int money;

	if (!sizeof(xuanshang) || undefinedp(xuanshang[victim->query("id")]))
	{
		call_out("destruct_all_order", 1);
		return ;
	}

	if (!money = xuanshang[victim->query("id")][1])
	{
		tell_object(killer, "获取奖金出错，请联系管理员处理。\n");
		call_out("destruct_all_order", 1);
		return ;
	}

	log_file("adms/finish", ctime(time()) + killer->query("name") + "(" + killer->query("id") + ")完成击杀" + victim->query("name") + "(" + 
		victim->query("id") + ")任务，奖金" + money + "两黄金。\n");
	tell_object(killer, "你完成了击杀" + victim->query("name") + "的悬赏任务，获得了" + money + "两黄金。\n");
	killer->add("balance", money * 10000);
	XUANSHANGD->delete_xuanshang(victim->query("id"));
	call_out("destruct_all_order", 1);
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
