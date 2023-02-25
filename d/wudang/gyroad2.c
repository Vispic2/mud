// gytoad2.c 果园小路
// by Java

inherit ROOM;
#include <ansi.h>
int do_zhai(string arg);
void create()
{
	set("short", "果园");
	set("long", @LONG
你轻松地走进果园。园中落英缤纷，两边是桃树林，盛开着粉红的桃花，
红云一片，望不到边。中间却是一株冠盖数亩的大树(tree)，遮住地面好大一
片绿荫。
LONG );
	set("outdoors", "wudang");
	set("item_desc", ([
		"tree" : 
"这是一株人参果树，上面结着人参果，据说摘下吃了对武功进益很有好处。\n"
	]));
	set("exits", ([
		"west" : __DIR__"gyroad1",
	]));
	set("guocount",1);
	setup();
}

void init()
{
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object guo;
	if (! arg || arg == "")
	{
		message_vision("你想摘什么？\n", this_player());
		return 1;
	}
	if (arg == "guo" || arg == "renshen guo")
	{
		if (uptime() < 1800)
		{
			message_vision("人参果未熟呢，$N等一会再来吧。\n",
				       this_player());
			return 1;
		}
		if (query("guocount") > 0 && random(2)==1)
		{
			message_vision("$N从人参果树上摘下一个熟透的" HIR
				       "人参果。"NOR"\n", this_player());
			guo = new(__DIR__"obj/renshenguo");
			guo->move(this_player());
			add("guocount", -1);
			return 1;
		} else
		{
			set("guocount",0);
			message_vision("$N真是好可怜啊？人参果刚被摘走。\n",
				       this_player());
			return 1;	     
		}
	}
	return 0;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
