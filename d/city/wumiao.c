// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }
int ask_character(string arg);
void create()
{
	set("short", "武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭
毕敬地上香礼拜。旁边似乎有一道侧门。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("action_list", ([
		HIG"每日签到" NOR: "getreward -daysign",	          
		HIY"功德箱"NOR : "gong",		
	   
	]));
	set("objects", ([
	
"/adm/daemons/task/npc/zixu" :1,
	  
	]));
	set("exits", ([
		"east" : __DIR__"beidajie2",
		"north"   : __DIR__"wumiao2",
        "up"   : __DIR__"shilianzhidi",
        "south"   : __DIR__"mingrt",
		"northwest": "/d/wizard/guest_room",
	]));
	create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("do_sign","gong");
	add_action("discmds",({"walk","zdsm","recall","recalle","research","yanjiu","jiqu","derive","suicide","jobto","myshop","study","inventory","sleep","kill","fight","hit","conjure","expell","perform","prcatice","exercise","respirate"}));
}
int discmds()
{
	tell_object(this_player(),"小心点，别在这里卡了BUG！\n");
	return 1;
}


int valid_leave(object me, string dir)
{		
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}

int do_sign(string arg)
{
	int last;
	string msg;
	object me;
	object obj;
	me=this_player();
	last = me->query("last_day_signsss");	
	if (!arg)
    {
		msg = ZJOBLONG+
	    "这是一个小庙常见的功德箱，专门用来接受善男信女们的行善和祈福(每天22点前开放)。\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "日行一善:gong r"ZJSEP
		"祈福:gong q";						
	}else
	if(arg=="q")
	{
	msg = ZJOBLONG+"祈福：\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	msg += "祈福:gong qq";		
   }else
   if(arg=="r")
   {   	
   	msg = ZJOBLONG+"日行一善需要捐赠50元宝，你确定要捐赠吗？\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	msg += "日行一善:gong rr";		
   }else
   if(arg=="rr")
   {
   if(me->query("yuanbao")< 50)
	return notify_fail("你的元宝不够哦。\n");	
   
   if(time()/86400 == last/86400)
	return notify_fail("你今天已经行善过了。\n");	
	me->set("last_day_signsss",time());
	obj=new("/clone/shizhe/putao1");
	obj->move(me);
	me->add("yuanbao",-50);
	write("行善成功，你获得了："+obj->name()+"\n");
	}else
   
   if(arg=="qq"){
	if(time()/86400 == last/86400)
	return notify_fail("你今天已经祈福过了。\n");	
	me->set("last_day_signsss",time());
	obj=new("/clone/shizhe/putao");
	obj->move(me);
	write("祈福成功，你获得了："+obj->name()+"\n");
	}
    write(msg+"\n");
	return 1;
}

int mrrw(string arg)
{
	object me=this_player();
	string type;
	string msg="", line="";
if (!arg)
 {
		msg = ZJOBLONG+
		      "目前游戏中的日常任务如下[更新中]：\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "武馆训练["+me->query("fuben/wuguan/mun")+"/5]:qqq wuguan";
		msg += ZJSEP"伏击金兵["+me->query("fuben/jinbing/mun")+"/5]:qqq jinbing";	
		msg += ZJSEP"单骑破元["+me->query("fuben/poyuan/mun")+"/5]:qqq poyuan";		
		msg += ZJSEP"十三皇陵["+me->query("fuben/huangling/mun")+"/5]:qqq huangling";						
	}
	else if(arg=="wuguan"){
	msg = ZJOBLONG+"扬州武馆[武馆训练]："ZJBR
	                  "————————————————"ZJBR
                      "新手专属副本"ZJBR
                      "初入江湖难免行走困难，武馆是新人学艺初始的好地方，江湖之路从武馆学艺开始。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq wuguan2";	
	}
	else if(arg=="wuguan2"){ 
	me->move("d/city/wuguan/qianting");	
	}
	else if(arg=="jinbing"){
	msg = ZJOBLONG+"关外宁远镇[伏击金兵]："ZJBR
	                  "————————————————"ZJBR
                      "金国一直对我中原贼心不死，经常派密探进入关内刺探军情，阻击密探可获得丰厚奖励。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq jinbing2";	
	}
	else if(arg=="jinbing2"){ 
	me->move("d/guanwai/ningyuan");	
	}	
	else if(arg=="poyuan"){
	msg = ZJOBLONG+"襄阳城北草地[单骑破元]："ZJBR
	                  "————————————————"ZJBR
                      "元兵在我襄阳城外虎视眈眈，一旦玄武门被攻破，元兵将直入中原腹地，再无可挡，各方英雄豪杰当用尽自己一生本事灭杀元兵。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:qqq poyuan2";	
	}
	else if(arg=="poyuan2"){ 
	me->move("d/xiangyang/caodi3");	
	}		
	else if(arg=="huangling"){ 
	me->move("d/beijing/huangling");	
	}			
	write(msg + "\n");			
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
