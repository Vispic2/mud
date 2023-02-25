#include <ansi.h>
#include <room.h>
inherit ROOM;

string *names = ({
	"西夏卫兵","西夏探子","西夏武士","西夏刺客","西夏高手","副指挥使","指挥使","军主",
});

void create()
{
	set("short", "西夏校场");
	set("long","这里是西夏皇宫外的大校场，是西夏武士的训练之地。");

	set("objects",([
	]));
	set("npcs",([
	]));
	set("exits", ([
		"east" : "/d/lingzhou/beidajie",
	]));
	set("action_list", ([
		"校场挑战" : "tiaozhan",
	]));
	set("no_fight", 1);
    setup();
}
void init()
{
	add_action("tiaozhan", "tiaozhan");
}

int tiaozhan(string arg)
{
	object ling,me,slnpc,slroom;
	int i;
	string msg;

	me = this_player();

	if(!objectp(ling=present("tiaozhan ling",me))){
		tell_object(me,ZJOBLONG"你没有挑战令牌，不能进行挑战！\n");
		return 1;
	}

	if(!arg)
	{
		msg = ZJOBLONG"请选择挑战级别：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(names);i++)
		{
			msg += names[i]+":tiaozhan "+(i+1);
			if(i<(sizeof(names)-1)) msg += ZJSEP;
		}
		tell_object(me,msg+"\n");
		return 1;
	}

	if(atoi(arg)>sizeof(names)||atoi(arg)<1)
		return notify_fail("你想干什么？\n");

	ling->add_amount(-1);
	slroom = new(__DIR__"jiaochang2");
	slroom->set("owner",me->query("id"));
	slroom->set("sllv",atoi(arg));
	slnpc = new(__DIR__"npc/wushi");
	slnpc->init_data(atoi(arg));
	slnpc->move(slroom);
	me->move(slroom);
	slroom->set_heart_beat(1);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
