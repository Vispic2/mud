// bingqif.c
inherit ROOM;
void create()
{
	set("short", "打铁屋");
	set("long", @LONG
这里是树林深处的一间小石屋，看来是打造兵器的，屋子中有个大火炉
好烫的呢，屋中还有一张石几，上面放在一些已经打造好的兵器。
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao2",
	]));
	set("no_clean_up", 0);
	set("objects", ([
	       __DIR__"obj/blade": 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "blade") j++;
	}
	if (j > 1)
		return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一口钢刀就够啦。\n");
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
