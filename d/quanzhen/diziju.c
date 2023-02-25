// diziju.c 弟子居
inherit ROOM;
int do_pull(string arg);

void create()
{
	set("short", "弟子居");
	set("long", @LONG
这里是全真教弟子居住的房间。房间很大，整齐地铺着一排一排
的床，床上被褥都折叠得整整齐齐，但是一个人都没有，也许所有的
弟子都去练功去了。靠墙的地方有一个柜子(cabinet)。
LONG
	);
	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"jingxiushi",
	]));
	set("item_desc", ([
	    "【柜子】": "一个柜子，也许是堆放衣物用的。\n"
			ZJOBACTS2"推开:pull cabinet\n",
	]) );
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_pull","pull");
}

int do_pull(string arg)
{
	object me=this_player();

	if( !arg || arg != "cabinet" ) {
		return notify_fail("你要拉开什么？\n");
	}

	message_vision("$N使劲把柜子拉开，现出一个洞口。原来这里是密室的入口。\n", this_player());
	set("exits/down", __DIR__"mishi");
	remove_call_out("close");
	call_out("close", 8, this_object());

	return 1;
}

void close(object room)
{
	message("vision","柜子又吱吱地回到原地，把入口挡住了。\n", room);
	room->delete("exits/down");
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
