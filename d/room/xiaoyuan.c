// xiaoyuan.c

inherit ROOM;

static mapping room_type = ([
	"dule"    : "独乐居",
	"caihong" : "彩虹居",
	"panlong" : "盘龙居",
]);

void create()
{
	object ob;

	set("short", "小院");
	set("long", @LONG
这里是一个不大的院子，到处摆放着木料砖瓦。院中坐着一个人，丰
神飘洒，颇具宗匠之风。四周围着几个弟子，专心致志的在老师听课。院
角的一棵树上挂着一个牌子，上书：代建各种房屋，有意者敬请与鲁班洽
谈。
LONG );
	set("exits", ([
		"west"  : "/d/shaolin/yidao2",
		"dule"  : __DIR__"dule/xiaoyuan",
		"caihong" : __DIR__"caihong/xiaoyuan",
		"panlong" : __DIR__"panlong/dayuan",
	]));

	set("outdoors", "city");

	set("objects", ([
		__DIR__"npc/jinlin" : 1,
	]));

	set("no_fight", 1);
	set("no_sleep_room", 1);

	setup();
	"/adm/npc/luban"->come_here();
}

string query_room_id(string arg)
{
	if (arg && ! undefinedp(room_type[arg]))
		return room_type[arg];

	return 0;
}

void reset()
{
	::reset();
	"/adm/npc/luban"->come_here();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
