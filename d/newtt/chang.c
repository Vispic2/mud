//by admin 

#include <ansi.h>
inherit ROOM;
int close_gate();
int do_open();
int valid_leave();
string look_gate();
void create()
{
	set("short","长廊");
set("long", @LONG
这里是长廊
LONG );
		set("exits", ([
		"north" : __DIR__"liu",
	]));
	set("objects", ([
	"/d/newtt/obj/y" :3,
//	"/d/newtt/obj/yeguo" :20,
	]));
		set("item_desc",([
	"【大门】"	:    (: look_gate :),
    ]));
	setup();
}





void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"shanzhuang")) )
	room = load_object(__DIR__"shanzhuang");
    if(objectp(room))
    {
	delete("exits/norths");
	message("vision", "乒地一声，里面有人把大门关上了。\n",
	    this_object());
	room->delete("exits/souths");
	if (!objectp(present("qingguan", room)))
	    message("vision", "大门关了起来。\n", room);
	else
	    message("vision", "大门关了起来。\n", room);
    }
    else message("vision", "ERROR: gate not found(close).\n", room);
    return 1;
}

int do_knock(string arg)
{
    object room;

    if (query("exits/norths"))
	return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "gate" && arg != "north"))
	return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"shanzhuang")) )
	room = load_object(__DIR__"shanzhuang");
    if(objectp(room))
    {
	set("exits/norths", __DIR__"shanzhuang");
	message_vision("$N轻轻地敲了敲门，应声打开大门，他用锐利的目光上上下下打量着$N。\n",this_player());
	room->set("exits/souths", __FILE__);
	message("vision", "外面传来一阵敲门声，壮年应声上前把大门开。\n", room);
	remove_call_out("close_gate");
	call_out("close_gate", 5);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
    if (dir != "north")
	return ::valid_leave(me, dir);

    if (! ::valid_leave(me, dir))
	return 0;


	write("请进请进！\n");
	return 1;
    

}

string look_gate()
{
    return "一扇"HIR"红漆大门"NOR"上面有两个"HIY"金环"NOR"在阳光的照耀下格外耀眼。\n"ZJOBACTS2"敲门:knock gate\n";
}

































































































































































































































/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
