inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
一条昏暗潮湿的地道，地道很长，两边点着两根不太明亮的火把，
而且画得相当难看，你加快脚步，想知道地道的尽头是什么地方。 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "west" : "room9",
                "south" : "room4",
                "north" : "room16",
                "east" : "room11",
        ]));
        set("no_update", 1); 
		set("no_flyto",1);
		set_temp("quest_ob",1);

        setup();
}
//是镜像
int is_jfb() { return 1; }


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
