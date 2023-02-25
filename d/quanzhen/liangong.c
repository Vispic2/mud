// liangong.c 练功房
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是全真教弟子练功的房间。这座房间形状甚是奇特，前窄
後宽，成为梯形，东边半圆，西边却作三角形状，原来这是全真教
独有的练功室，前窄练掌，後宽使指，东圆研剑，西角发镖。房间
中央立着几个练功用的木人，吊着几个沙袋(bag)和纸册(paper)。
LONG );

	set("exits", ([
		"south" : __DIR__"houtang2",
		"north" : __DIR__"chanfang2",
	]));
	set("item_desc", ([
		"paper" : "这是一摞厚厚的牛皮纸册，用铁钉钉在墙上。好象可以
用来练掌法的，打打(da paper)试试看。\n",
		"bag"   : "这是一个大沙袋，看起来非常结实。好象是用来练指法
的，你可以打打(chi bag)看。\n",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 4,
	]));
	set("for_family", "全真教");
	setup();
}

void init()
{
      add_action("do_strike", "da");
      add_action("do_finger", "chi");
}

int do_finger()
{
      object me;
      int qi_cost, c_skill;

      me = this_player();
      c_skill=me->query_skill("finger", 1);

      message_vision("$N伸指狠狠地点向沙袋，觉得指尖微微有些痛。\n", me);
      qi_cost = 25;

      if (me->query("qi") > qi_cost)
      {
	   if (me->can_improve_skill("finger") && c_skill < 100)
		me->improve_skill("finger", 1 + random(me->query("str")));
	   me->receive_damage("qi", qi_cost);
      }
      return 1;
}

int do_strike()
{
      object me;
      int qi_cost, c_skill;

      me = this_player();
      c_skill = me->query_skill("strike", 1);

      message_vision("$N蹲了一个马步，挥掌击向牛皮纸册。\n", me);
      qi_cost = 25;

      if (me->query("qi") > qi_cost)
      {
	   if (me->can_improve_skill("strike") && c_skill < 100)
		me->improve_skill("strike", 1 + random(me->query("str")));
	   me->receive_damage("qi", qi_cost);
      }
      return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
