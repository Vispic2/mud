// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向金牛宫的路上，只见前面可以看到美丽的金牛宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的白羊宫。
LONG);


        set("exits", ([
        "southup"    :       __DIR__"jinniu",
            "westdown"  :       __DIR__"by2jn1",
        ]));

        set("outdoors", "12gong");
        setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/