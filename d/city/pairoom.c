
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIG"[棋牌室]"NOR);
        set("long", @LONG
这是一间专门让玩家们休息的娱乐场所，当你在为你的角色
辛苦锻  时，别忘了休息是为了走更长远的路，找叁五好友一同
来玩一会吧
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);

        set("exits",([
                
			"east"  : __DIR__ "fxqroom",
			"west"  : __DIR__ "fxqroom1",
			"south" : __DIR__ "fxqroom2",
			"north" : __DIR__ "fxqroom3",
			"down"  : __DIR__"guangchang",

        ]));

        
        setup();
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
