//chufang1.c
inherit ROOM;
void create()
{
  set("short","厨房");
  set("long", @LONG
你走在一条阴暗的林间小道上，两旁是阴森森的树林。一阵
这是风雷堂的厨房，一位美丽侍女满脸堆笑。整个房间菜香
胭脂香迷漫。墙上贴着一张醒目的启事(note)。
LONG  );
  set("exits",([
      "east" : __DIR__"grass2",
  ]));
  set("item_desc",([
      "note" : "人是铁，饭是钢，一顿不吃饿得慌。\n",
  ]));

  set("objects",([
      __DIR__"npc/shinu" : 1,
      __DIR__"obj/tea" : random(6),
      __DIR__"obj/sherou"  : random(4),
  ]));
//  set("no_clean_up", 0);
  setup();
}
int valid_leave(object me, string dir)
{
	if (( present("tea", me)||present("she rou", me))
	&&objectp(present("shi nu", environment(me))) )
	return notify_fail
	("侍女美目一挑，你还是在这儿吃完吧。\n");
	return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
