// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向巨蟹宫的路上，只见前面可以看到美丽的巨蟹宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的双子宫。
LONG);


        set("exits", ([
        "westup"    :       __DIR__"sz2jx2",
            "northdown"  :       __DIR__"shuangzi",
        ]));

        set("outdoors", "12gong");
        setup();
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
