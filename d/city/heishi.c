// by ranger_游侠
// heishi.c
inherit ROOM;
void create()
{
	set("short", "黑市");
	set("long", "这里是黑市，物品交易的场所。");
	set("exits", ([
		"northwest":__DIR__"guangchang",
	]));
	set("objects", ([
	]));
	set("action_list", ([
	//	"寄售物品" : "jishou",
	//	"物品列表" : "jylist",
		//HIR"回收道具" NOR: "huishou",		
		HIY"购买图纸" NOR: "shoptuzhi",
			HIR"兑换爆竹"NOR : "dui",
	]));
	set("objects",([
                "/adm/npc/qingyangzi":1,
                 "/d/city/npc/shenyi":1, 
			"/clone/shizhe/nianshou" :1,
        ]));
	set("no_fight","1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	setup();
}

void init()
{
	add_action("do_stock", "jishou");
	add_action("do_buy", "jybuy");
	add_action("do_list", "jylist");
	add_action("do_cha", "jychakan");
	add_action("do_unstock", "quhui");
	//add_action("do_huishou", "huishou");
}
int do_stock(string arg)
{
	tell_object(this_player(),SALE_D->do_stock(this_player(),arg)+"\n");
	return 1;
}
int do_buy(string arg)
{
	tell_object(this_player(),SALE_D->do_buy(this_player(),arg)+"\n");
	return 1;
}
int do_cha(string arg)
{
	tell_object(this_player(),SALE_D->do_cha(this_player(),arg)+"\n");
	return 1;
}
int do_list(string arg)
{
//	return notify_fail(OKSAY"集市暂时关闭！\n");
	if(!arg)
		arg = "全部 1";
	tell_object(this_player(),SALE_D->do_list(this_player(),arg)+"\n");
	return 1;
}
int do_unstock(string arg)
{
	tell_object(this_player(),SALE_D->do_unstock(this_player(),arg)+"\n");
	return 1;
}



int jiage(object ob)
{
if (ob->query("yuanbao")>10){
return ob->query("yuanbao")/5;
}else
if (ob->query("yuanbaos")>10){
return ob->query("yuanbaos")/5;
}
return 0;
}
int do_huishou(string arg)
{
    string msg,id_name;
	object me = this_player();
	object obj;
	int amount;
    if (!arg){
	object *pobj;
	pobj = all_inventory(me);
	pobj = filter_array(pobj,(: jiage($1) :));	
	if (!sizeof(pobj)){
	write("你身上没有可以回收的道具\n");
	return 1;	
	}
	msg = ZJOBLONG+ZJSIZE(25)+HIW+"回收简介：可以回收元宝或元宝票道具，回收后奖励均为元宝票。算法：道具价格/5等于回收价格。"ZJBR
	""ZJSIZE(25)+HIR+"注意：道具原价格至少为10否则不可回收。"+NOR+""ZJBR
	HIM"请选择你需要回收的物品："+NOR+"\n"
	ZJOBACTS2+ZJMENUF(1,1,8,25);		
	 foreach (obj in pobj){
	 amount = obj->query_amount()?obj->query_amount():1;
	 msg += sprintf("%d份%s"ZJBR"可回收：%d个元宝票:huishou %s"ZJSEP,amount,obj->query("name"),jiage(obj),obj->query("id"));
     }     
	 msg += "取消:look\n";
	 tell_object(me,msg);
	 return 1;
	}	
	 if (sscanf(arg, "%s==%s", id_name, arg) == 2){	
	 obj = present(id_name,me);
	 amount = to_int(arg);
	 if (amount < 1){
	 write("参数错误，请重新输入。\n");
	 return 1;
	 }	 
	 if (!objectp(obj))
	 return notify_fail("你没有该物品\n");	 
	 if (obj->query_amount()<amount)
	 return notify_fail("你好像没有那么多"+obj->query("name")+"\n");	 
	 log_file("d/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "回收了" + chinese_number(amount) + "个" + obj->query("name") + "\n");
     me->add("yuanbaos",jiage(obj)*amount);
     write(HIM"回收成功，通过本次回收你获得了："+jiage(obj)*amount+"元宝票\n"NOR);
     obj->add_amount(-amount);
     return 1;      
	}	
	if (arg){
	obj = present(arg,me);
	amount = obj->query_amount();	 
    if (amount)
    return notify_fail(INPUTTXT("你有"+amount+"份，请问你要回收多少份"+obj->query("name"),"huishou "+arg+"==$txt#")+"\n");	 	
	me->add("yuanbaos",jiage(obj));
	log_file("d/huishou", ctime(time()) + "  " + me->query("name") + me->query("id") + "回收了一个" + obj->query("name") + "\n");
	write(HIM"回收成功，通过本次回收你获得了："+jiage(obj)+"元宝票\n"NOR);
	destruct(obj);
	return 1;
	}
	return 1;
}




/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
