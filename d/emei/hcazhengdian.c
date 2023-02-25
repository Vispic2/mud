//Room: hcazhengdian.c 华藏庵正殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","华藏庵正殿");
      set("long",@LONG
这里是峨嵋山金顶华藏庵的正殿。华藏庵规模宏大，殿内青砖铺地，中间
有普贤菩萨像，两旁列有万佛。正前方放一红木供桌，陈列香烛，以供叩拜。
自此左右各有一间侧殿，是接待香客的地方。南面是通往一个大广场，只有峨
嵋弟子才能过去。
LONG);
      set("objects", ([
	   CLASS_D("emei") + "/xin" : 1,
	   __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
	  "out"    : __DIR__"huacangan",
	  "east"   : __DIR__"hcaeast", 
	  "west"   : __DIR__"hcawest", 
	  "south"  : __DIR__"hcaguangchang", 
      ]));
	set("valid_startroom", 1);
      setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (dir != "out" &&
	    objectp(ob = present("jingxin shitai", this_object())))
		return ob->permit_pass(me, dir);
	return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
