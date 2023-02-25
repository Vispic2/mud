// Room: /city/beimen.c
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC"汪洋大海"NOR);
	set("long", @LONG
一种巨形怪物。据说自宇宙初造，浑沌初开之时，此物便已生活在江洋大海之中，极有灵性。九爪孽龙长逾两丈，顶背有长列巨刺，坚逾钢铁，犀得无比；全身生有黑色鳞甲，大如蒲扇；刀枪不入；腹下呈灰白状；蹄爪之间常排泄奇腥粘液，山野小虫，触之即死；口吐白烟，腥咸热辣，毒烈无比。但它亦有三处致命的弱点，即左右眼和舌根。若同时击伤此三处，可致之于死地。九爪孽龙盘踞长江口外花鸟山，时常悠游于东海之中，商旅闻之丧胆。或有人上花鸟山欲除之，往反为所害。四海神龙付出了惨重代价，方得到双剑乾坤燕公来之助而除之。
LONG );
	set("objects", ([
		"/fuben/npc/jiuzhualong" : 1,
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
