
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short",HIR"[大话色]"NOR);
        set("long", @LONG
第二室
LONG
);

        set("no_fight", 1);
        set("no_magic", 1);
	
      
        set("exits",([
             			"east"  : __DIR__ "pairoom",
        ]));
        set("objects",([
                "/clone/game/dhs":1,
        ]));
        
        setup();
}
/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
