// Room: /d/mingjiao/shanlu3.c
inherit ROOM;

void create()
{
	set("short", "悬天崖");
	set("long", @LONG
这里山路陡峭，仅有一人多宽，路左是峭壁高耸，路右紧临万
丈深渊，实在是一夫当关、万夫莫开的险要之处。继续上攀，就要
到达明教五行旗了。紧挨路右，天然生有一块巨石，高近三丈，名
为“悬天石”，常有侠客于上远观云海。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup"   : __DIR__"shanlu4",
		"up"	: __DIR__"xuantianshi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
}

int valid_leave(object me, string dir)
{
    if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")    
    {
	return notify_fail("你使劲儿一蹦，离石顶还有数丈远就掉了下来，摔的鼻青脸肿，看来得多练练轻功了。\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")    
    {
	return notify_fail("你奋力一跃，却离石顶还有一丈多远，看来得多练练轻功了，免得白费力气。\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")    
    {
	return notify_fail("你纵身而起，离石顶只差一点点了，再加把劲，回去多练练轻功。\n");
    }

    return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
