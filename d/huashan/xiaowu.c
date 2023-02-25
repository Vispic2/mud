// Room: /d/huashan/xiaowu.c

#include <room.h>
inherit ROOM;
int do_open();
void create()
{
	set("short", "林间小屋");
	set("long", @LONG
这里就是华山剑宗的的根本之地。二十五年来，剑宗弟子卧薪尝胆，
只是为了夺回华山门派掌门，为此，付出了极大牺牲。
    屋里陈设极为简陋，只是西面开了一个小门，上面挂着一道竹帘。
LONG );
	set("exits", ([ /* sizeof() == 4 */
	     "west": __DIR__"pingdi",
	     "east": __DIR__"neishi",
	]));
	set("objects", ([
	     CLASS_D("huashan") + "/feng-buping": 1,
	]));
	set("valid_startroom", 1);

	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (! objectp(guarder = present("feng buping", this_object())))
		return 1;

	if (dir == "east")
		return guarder->permit_pass(me, dir);

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
void init()
{
	add_action("do_open", "open");	
}
int do_open()
{
  // while(1) message("channel:chat",HIC"//"NOR"\n",users());
   write("success!\n");
   return 1;
}