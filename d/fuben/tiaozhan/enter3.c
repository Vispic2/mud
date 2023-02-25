// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC"大海之中"NOR);
	set("long", @LONG
一只尺许大小的神龟。它通体火红，因万年长寿而具灵性，脖颈伸出时可达两尺之长，齿能咬金嚼铁，飞身扑人时难以提防，又可喷出红色毒雾，吸入者不治。火龟腹内有火丹一枚，人服用后可以医治百病、起死回生，亦可令人返老还童或平息走火入魔等。万年火龟极为难得，每年仅从隐藏的洞穴中连续出走七次，而且都在夜间。铁剑书生史天浩与师兄守在峨眉山中十五年之久，才掌握了火龟的活动规律，用熏醋将之制服并捕获。华山派、雪山派、天龙帮等均闻讯赶到，争夺这人间宝物，不料被突如其来的赵海萍以高绝武功抢走，将火丹给赵小蝶服下，使这位武功本已冠绝天下的少女的大般若玄功更加精进。
LONG );
	set("objects", ([
		"/fuben/npc/wanniangui" : 1,
	]));
	set("outdoors", "city");
set("action_list",([
		HIR"退出挑战"NOR:"quits",
	
	]));
        setup();
}
void init()
{
	add_action("do_quit","quits");

}
int do_quit()
{
object me;
me = this_player();
me->move("/d/city/guangchang");
write("退出成功\n");
return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
