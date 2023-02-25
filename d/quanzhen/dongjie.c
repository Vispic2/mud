// dongjie.c 东街
// By Lgg,1998.10

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long", @LONG
这里是武功镇的东街，往东走就是武功东门了。武功镇是个小
城镇，不算繁华，街上的行人也很稀少。北面是一家客栈，客栈门
口挂着半副‘鸡鸣早看天’的对联，上联已经被撕掉了。南面是一
座大宅院，朱红大门上布满铜钉。从这里往西走，就是武功镇的中
心了。
LONG
	);
	set("outdoors", "wugong");
	set("exits", ([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"zhongxin",
		"north" : __DIR__"kedian1",
		"south" : __DIR__"fu-damen",
	]));
	set("objects", ([
		__DIR__"npc/seller" : 1,
	]));
	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
