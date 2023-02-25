//by name qq:3468713544 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","垃圾场"NOR);
	set("long","这里是垃圾场");
	set("channel_id", "公益活动");
	set("exits", ([
		"south" : "/fuben/jlj/ljc9",
		"west" : "/fuben/jlj/ljc5",
		"east" : "/fuben/jlj/ljc1",
		"north" : "/d/city/lajichang",
	]));
	set("action_list", ([
		""HIY"公益活动"NOR :"jlj",
	]));
	setup();
}
void init()
{
add_action("moveto","jlj");
}
int moveto()
{
	object me = this_player();

	if (!this_object()->query("open"))
	return notify_fail("你错过了扬州公益活动捡垃圾的时间(08:00-08:10)，只好等下一次活动了。\n");
	me->move("/fuben/jlj/ljc1");
	tell_object(me,"以传送至垃圾场。\n");
	return 1;
}
int start_jlj()
{
	shout(HIY "【捡垃圾】" NOR+HIW"扬州垃圾场"+HIR+"《公益活动》"+HIY+"开放，速去捡垃圾维护扬州环境！\n"NOR);
	set("open",1);
	call_out("clear_jlj",635);
	return 1;
}
int clear_jlj()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;

	files = list_dirs("/fuben/jlj/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/fuben/jlj/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],HIW"扬州公益活动捡垃圾已经结束，已将你传送至扬州客店\n"HIR"注意！\n注意！\n注意！！！\n部分道具需要quit重新上线才能使用!\n部分道具需要quit重新上线才能使用！！\n部分道具需要quit重新上线才能使用！！！\n"NOR);
							inv[j]->move("/d/city/kedian");
						}else{
							destruct(inv[j]);
						}
					}
				}
			}
		}
	}
	this_object()->delete("open");
	CHANNEL_D->do_channel(this_object(), "chat", "扬州公益活动捡垃圾活动已结束。");
	return 1;
}

int valid_leave(object me, string dir)
{
    if(!this_object()->query("open") && dir == "south"||!this_object()->query("open") && dir == "west"||!this_object()->query("open") && dir == "east")
	return notify_fail("扬州公益活动每天08：00-08：30开始结束。\n"NOR);
	return ::valid_leave(me, dir);
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
