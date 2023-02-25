// Room: /d/xiangyang/northgate2.c
inherit ROOM;
#include <ansi.h>;
int xiangyangsss(string arg);
void create()
{
	set("short", "玄武外门");
	set("long", 
"这里是襄阳城的北城门，只见城门上方是三个大字。"HIB"

		      玄武门
"NOR"\n"
"近年来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵
们正在盘查要离襄阳城的人。两边是很大的草地。\n"
 );
	set("outdoors", "xiangyang");

	set("exits", ([
		"south"  : __DIR__"northgate1",
		"north"  : __DIR__"caodi3",
		"east"   : __DIR__"caodi1",
		"west"   : __DIR__"caodi2",
	]));
		set("action_list", ([
		""HIC"守卫襄阳"NOR :"di",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
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
	return notify_fail("守卫襄阳活动开放时间未到，每天开放时间(19：10-19：40) 30分钟后结束。\n");	

	
	me->move("/fuben/xiangyang/qilin1");
	tell_object(me,"守卫襄阳，人人有责！\n");    		
	return 1;
}
int start_xiangyang()
{
	object me;
	set("open",1);
	call_out("clear_xiangyang",1800);
	return 1;
}
int clear_xiangyang()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;
	set("open",0);
	files = list_dirs("/fuben/xiangyang/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/xiangyang/"+files[i];
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
							tell_object(inv[j],"守卫襄阳活动结束，你已被带回扬州客栈！\n");
							inv[j]->move("/d/city/kedian");
						}
					}
				}
			}
		}
	}
	message("channel:chat",HIY"【活动】："+HIY+"  《守卫襄阳》活动已结束！\n"NOR,users());
	return 1;
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
