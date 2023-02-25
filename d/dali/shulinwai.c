//Room: /d/dali/shulinwai.c
//Date: June. 29 1998 by Java

inherit ROOM;
int xiangyangsss(string arg);
void create()
{
	set("short","树林外");
	set("long",@LONG
你来到了一片黑森森的树林面前，放眼望去，密密麻麻的都是
树木，而且荆棘丛生，隐约可见有些小路东盘西曲。你仔细观察，
发现这显然是个人造的迷宫。其中暗合五行八卦，奇门遁甲，端的
非同小可，千万不要冒然进去。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"heilongling",
//	    "south"      : __DIR__"migongshulin",
	]));
	set("action_list", ([
		""HIW"灵脉山洞"NOR :"di",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("xiangyangsss","xingyangsss");
	add_action("xiangyangsss","di");
}

int xiangyangsss(string arg)
{
	object me = this_player();
    object ob = this_object();
	if (!this_object()->query("open"))
	return notify_fail("灵脉山洞活动开放时间未到，每天开放时间(10：10-10：40) 30分钟后结束。\n");	

	
	me->move("/fuben/sc/qilin1");
	tell_object(me,"冲啊！\n");    		
	return 1;
}

int start_sc()
{
	object me;
	set("open",1);
	call_out("clear_sc",1800);
	return 1;
}
int clear_sc()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	set("open",0);
	files = list_dirs("/fuben/sc/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/sc/"+files[i];
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
							tell_object(inv[j],"灵脉山洞活动结束，你已被带回扬州客栈！\n");
							inv[j]->move("/d/city/kedian");
						}
					}
				}
			}
		}
	}
	message("channel:chat",HIY"【活动】："+HIW+"  《灵脉山洞》活动已结束！\n"NOR,users());
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
