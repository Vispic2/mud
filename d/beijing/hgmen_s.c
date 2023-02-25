inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "皇宫正门");
	set("long", @LONG
这里便是皇宫的正门，丈高的朱红大门敞开着，门上金色的铆钉闪闪发光。
大门两旁站着两排神情严肃的卫兵，不停的打量着过往的行人。灿烂的阳光直
射在巍峨雄伟的古城墙上，使得城墙上方“紫禁城”三个烁金大字显得格外的
耀眼。从南方的金水桥可以穿越护城河到达繁华的天安门广场。
LONG NOR);
	set("exits", ([
		"south" : __DIR__"qiao",
		"north" : __DIR__"hg",
	]));
	set("objects", ([
		__DIR__"npc/bing2" : 2,
		__DIR__"npc/yuqian1" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("guan bing", environment(me))) && dir == "north")
		return notify_fail(CYN "御前侍卫伸手拦住你朗声说道：皇宫重"
				   "地，岂容寻常百姓出入。"NOR"\n");
	return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
