#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "逆流而上");
	set("long","千尺瀑内蕴含奇异之力，使人修炼速度加快，每上升一尺修炼速度便快一分，只是越往上面难度越大。");

	set("sllv",1);
	set("objects",([
	]));
	set("exits", ([
		"south" : __DIR__"qianchipu",
	]));
	set("action_list", ([
		"结束挑战" : "slover",
	]));
	set("cost", 1);
	setup();
}

void init()
{
       add_action("slover", "slover");
       add_action("slover1", "slover1");
}

int slover()
{
	write(ZJOBLONG"你确定要结束本轮冲击么？\n"ZJOBACTS2"确定:slover1\n");
	return 1;
}
	
int slover1()
{
	object slroom;
	object me = this_player();

	slroom = this_object();

	tell_object(me,sprintf(ZJOBLONG"本次试炼结束！$br#试炼等级：%d\n",me->query("qianchi")));
	////log_files("qianchi", sprintf("%s：%s完成%d级千尺瀑试炼，经验值=%d。\n",ctime(time()),me->query("id"),me->query("qianchi"),me->query("combat_exp")));
	this_player()->delete("qianchi");
	this_player()->move("/d/fuben/qianchipu/qianchipu");
	this_player()->remove_all_killer();
	destruct(slroom);
	return 1;
}

void nextlv(int delay)
{
	add("sllv",1);
	call_out("nextlv2",delay);
}

int nextlv2()
{
	object slnpc;
	string *slnpcs;

	slnpcs = ({
		__DIR__"npc/sldz",
	});
	slnpc = new(slnpcs[random(sizeof(slnpcs))]);
	slnpc->set("name",query("sllv")+"级弟子");
	slnpc->move(this_object());
	return 1;
}

int valid_leave(object me, string dir)
{
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
