
inherit ROOM;
int qilinsss(string arg);
void create()
{
	set("short",HIR"凌云窟"NOR);
	set("long",@LONG
这里便是凌云窟了！
LONG);
	set("outdoors", "chengdu");
	set("exits",([ 
	 
	    "west"  : __DIR__"shilu1",
	    
	]));
	set("action_list", ([
		""HIR"麒麟洞"NOR :"qilinsss",
	]));
	
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("qilinsss","qilinsss");
	add_action("qilinsss","di");
}

int qilinsss(string arg)
{
	object me = this_player();
    object ob = this_object();
   	   string msg;
    if (me->query("combat_exp", 1)<1000000 )
	return notify_fail("你这么点经验怎么敢来这里？这不是找死吗？(需要100w经验)\n");
	if (!this_object()->query("open"))
	return notify_fail("麒麟洞活动开放时间未到，每天开放时间(17：10-17：40) 30分钟后结束。\n");	
	if (!arg)
 {
		msg = ZJOBLONG+
		      "请选择进入层次，强度一样：\n";
		msg += ZJOBACTS2+ZJMENUF(1,1,9,30);
		msg += "第一层:di 1";
		msg += ZJSEP"第二层:di 2";	
		msg += ZJSEP"第三层:di 3";		
			write(msg + "\n");		
	}else
	if(arg=="1")
	{
	me->move("/fuben/qilin/qilin1");
	tell_object(me,"你选择了麒麟洞第一层，请小心行事！\n");    
	
	}else
	if(arg=="2")
	{
	me->move("/fuben/qilin1/qilin1");
	tell_object(me,"你选择了麒麟洞第二层，请小心行事！\n");    
	
	}
	if(arg=="3")
	{
	me->move("/fuben/qilin2/qilin1");
	tell_object(me,"你选择了麒麟洞第三层，请小心行事！\n");    
	
	}
	return 1;
}
int start_qilin()
{
	object me;
	set("open",1);
	call_out("clear_qilin",1800);
	call_out("clear_qilin1",1800);
	call_out("clear_qilin2",1800);
	call_out("clear_qilin3",1800);
	return 1;
}
int clear_qilin()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	set("open",0);
	files = list_dirs("/fuben/qilin/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/qilin/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],"麒麟洞活动结束，你已被带回扬州客栈！\n");
							inv[j]->move("/d/city/kedian");
						}
					}
				}
			}
		}
	}
	message("channel:chat",HIY"【活动】："+HIY+"  《麒麟洞》活动已结束！\n"NOR,users());
	return 1;
}
int clear_qilin1()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	set("open",0);
	files = list_dirs("/fuben/qilin1/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/qilin1/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],"麒麟洞活动结束，你已被带回扬州客栈！\n");
							inv[j]->move("/d/city/kedian");
						}
					}
				}
			}
		}
	}
//	message("channel:chat",HIY"【活动】："+HIY+"  《麒麟洞》活动已结束！\n"NOR,users());
	return 1;
}
int clear_qilin2()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	set("open",0);
	files = list_dirs("/fuben/qilin2/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/qilin2/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],"麒麟洞活动结束，你已被带回扬州客栈！\n");
							inv[j]->move("/d/city/kedian");
						}
					}
				}
			}
		}
	}
//	message("channel:chat",HIY"【活动】："+HIY+"  《麒麟洞》活动已结束！\n"NOR,users());
	return 1;
}
int clear_qilin3()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	set("open",0);
	files = list_dirs("/fuben/room/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/room/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],"麒麟洞活动结束，你已被带回扬州客栈！\n");
							inv[j]->move("/d/city/kedian");
						}
					}
				}
			}
		}
	}
//	message("channel:chat",HIY"【活动】："+HIY+"  《麒麟洞》活动已结束！\n"NOR,users());
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
