//room: /d/btshan/zhailou.c
inherit ROOM;

void init();
int cut(string);

void create()
{
  set("short","树林");
  set("long","这里是一片茂密的树林(wood)。旁边立着一张木牌(pai)。\n");
  set("exits",([
	"west" : __DIR__"shulin1",
//      "nothwest" :
//      "northeast" :
      "south" : __DIR__"shanlu1",
     ]));
  set("outdoors", "baituo");
  set("no_clean_up", 0);
  set_temp("times" , 1);
  set("item_desc", ([
      "pai" : "保护树林  适量砍伐\n",
      "wood" :"一片可砍伐的树林。\n",
      ]) );
  setup();
}

void init()
{
 add_action("do_cut","cut");
}

int do_cut(string arg)
{
 object me=this_player();
 object ob;
 if (!arg||arg!="wood")
  return notify_fail("你要砍什么？\n");
 if (present("chai dao",me))
  return notify_fail("没有柴刀怎么砍柴？\n");
 if (query_temp("times")==0)
  return notify_fail("请适量砍伐！\n");
 if(me->query("qi")<20)
  return notify_fail("你的气太虚弱，不能砍柴！\n");
 ob=new(__DIR__"obj/chai");
 ob->move(environment(me));
 me->add("qi",-20);
 add_temp("times",-1);
 message_vision("$N砍了一捆柴，累得够呛。\n" , me);
 return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
