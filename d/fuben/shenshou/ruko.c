#include <ansi.h>
#include <room.h>
inherit ROOM;

string *names = ({
	""HIG"神兽玄武",""HIR"神兽朱雀",""HIW"神兽白虎",""HIC"神兽青龙",""HIY"神兽之首麒麟"NOR"",
});

void create()
{
	set("short", ""HIR"神兽"HIC"试炼"NOR);
	set("long",HIY"这里是去往五神兽的巢穴！。"NOR);

	set("objects",([
	]));
	set("npcs",([
	]));
	set("exits", ([
		"south" : "/d/city/shilianzhidi",
	]));
	set("action_list", ([
	""HIY"神兽"HIR"试炼"NOR"" : "tiaozhan",
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

	if(!objectp(ling=present("shenshou ling",me))){
		tell_object(me,ZJOBLONG"你没有神兽令牌，不能进行挑战！\n");
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
	slroom = new(__DIR__"shilian");
	slroom->set("owner",me->query("id"));
	slroom->set("sllv",atoi(arg));
	slnpc = new(__DIR__"npc/shenshou");
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
