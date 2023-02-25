#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "千尺瀑");
	set("long","千尺瀑内蕴含奇异之力，使人修炼速度加快，每上升一尺修炼速度便快一分，只是越往上面难度越大。");

	set("objects",([
	]));
	set("npcs",([
	]));
	set("exits", ([
		"south" : "/d/huashan/qianchi",
		"north" : "/d/lunjian/enter",
			"east" : "/d/lunjians/enter",
	]));
	set("action_list", ([
		"逆流而上" : "niliu",
	]));
	set("no_fight", 1);
    setup();
}
void init()
{
	add_action("niliu", "niliu");
}

int niliu()
{
	object me,slnpc,slroom,*slrooms;
	mixed last,now;
	mapping fam;
	int lvl,i;
	string *slnpcs;
	now = localtime(time());
	me = this_player();

	if(me->query("combat_exp")<800000){
		tell_object(me,"你的实战经验太低，不能在这里试炼！\n");
		return 1;
	}
	if(me->query_condition("killer")){
		tell_object(me,"你正在被通缉，不能在这里试炼！\n");
		return 1;
	}

	if(me->query("last_qianchi")) last = localtime(me->query("last_qianchi"));
	else last = localtime(0);
	if(now[7]==last[7]&&!this_player()->query("qianchi")){
		tell_object(me,ZJOBLONG"你本次冲击已结束，请明天再来！\n");
		return 1;
	}
	slrooms = children("/d/fuben/qianchipu/qianchipu2");
	for (i = 0; i < sizeof(slrooms); i++) {
		if(slrooms[i]->query("owner")==me->query("id"))
			slroom = slrooms[i];
	}
	if(!slroom)
	{
		slroom = new("/d/fuben/qianchipu/qianchipu2");
		slroom->set("owner",me->query("id"));
		if(!me->query("qianchi")){
			lvl = to_int(pow(to_float(me->query("combat_exp")*10),0.333333333))/10;
			if(lvl<1) lvl = 1;
			me->set("qianchi",lvl);
			me->set("last_qianchi",time());
		}
		slroom->set("sllv",me->query("qianchi"));
		slnpcs = ({
			__DIR__"npc/sldz",
		});
		slnpc = new(slnpcs[random(sizeof(slnpcs))]);
		slnpc->set("name",me->query("qianchi")+"级弟子");
	}
	this_player()->move(slroom);
	if(objectp(slnpc))
		slnpc->move(slroom);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
