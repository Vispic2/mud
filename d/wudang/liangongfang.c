// liangongfang.c 练功房
// by Xiang

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团，几位武当弟子正盘膝坐在上
面打坐。
LONG );
	set("exits", ([
		"west" : __DIR__"donglang2",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 3
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
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
		return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一把竹剑就够啦。\n");
	return ::valid_leave(me, dir);
}


/*
BY：NAME
QQ：21315491
DATE：2 0 2 2 . 0 2 . 0 3
*/
