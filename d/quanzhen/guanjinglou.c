// guanjinglou.c 观景楼
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "观景楼");
	set("long", @LONG
这里是一座两层的小楼，是建筑在庄园边缘用来登高凭拦看
风景的。你轻轻靠在栏杆上，竟朽的吱吱做响。看来已经很久没
有人有这个雅兴来这里看风景了。窗户(window)上的窗纸已经破
了不少，风一吹哗哗的响。
LONG
	);
	set("outdoors", "quanzhen");
	set("exits", ([
		"north" : __DIR__"houhuayuan",
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
	"window": "窗外是黄沙满天，往远处看，什么都看不清楚。\n"
	]) );

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
