// work.c modified by snow
#include <ansi.h>
inherit ROOM;

int cot;
void create()
{
	set("short", "谷物加工厂");
	set("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一
个一看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以
看到许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG
	);
	set("no_sleep_room",1);
	set("gj",1);
	set("no_fight",1);	
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"【告示】": "现在正人手紧缺，急需雇佣一批短工来干活。赶紧work，开始工作吧！\n"
		ZJOBACTS2"开始打工:work auto\n",
	]) );
	set("no_magic", 1);
	setup();
}
void init()
{
	add_action("do_work", "work");
	if (!wizardp(this_user()))
	add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","fly","scribe","surrender"}));
}
int discmds()
{
	tell_object(this_player(),"还是老老实实工作吧？！\n");
	return 1;
}
int do_work(string arg)
{
	int time;
	object me;
	me = this_player();

	time = 100/(int)me->query("str");
	if (time <15) time = 15;

//	if (me->query("combat_exp") > 5000000)
//		return notify_fail("让你干这活，也太屈就你了吧。\n");

	if (me->query_temp("job/step"))
		return notify_fail("赶紧干活吧，谁叫你穷呢！\n");

	if ((int)me->query("jing")<30 || (int)me->query("qi")<30) return notify_fail("你快累死了，要钱不要命了吗？\n");

	if (cot>=3) {
		write("老板嘿嘿一笑：我这里人手已经够了，做义工可没工钱的哟！\n");
		me->start_busy(4);
		return 1;
	}

	if ((int)me->query("jing")<10 || (int)me->query("qi")<10)
	{
		message_vision("$N开始辛苦地工作......\n", me);
		write("你突然感到头晕眼花。。。。。。\n");
		tell_room(environment(me), RED+me->name() +"脸色看起来不大对头，斗大的汗珠从脸上滑了下来。\n哎,又是一个要钱不要命的..!"NOR"\n", ({me}));
		me->unconcious();
		return 1;
	 }

	if(arg&&arg=="auto")
	{
		tell_object(me,ZJEXIT"northwest:"RED"停止工作"NOR":halt\n");
		me->set_temp("pending/auto_work",1);
	}

	message_vision("$N开始辛苦地工作......\n", me);
	cot++;
	me->set_temp("job/step", 1);
	me->start_busy((: call_other, __FILE__, "working" :),
			(: call_other, __FILE__, "halt_working" :));
	return 1;
}

void auto_work(object me)
{
	if(!me||!me->query_temp("pending/auto_work"))
		return;
	if(me->is_busy())
		call_out("auto_work",1,me);
	else if( (int)me->query("jing") < 50)
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < 50)
			{
				tell_object(me,"精神不佳，等待恢复中。。。\n");
				call_out("auto_work",10,me);
			}
			else
			{
				call_out("auto_work",1,me);
			}
		}
		else
		{
			tell_object(me,"精神不佳，等待恢复中。。。\n");
			call_out("auto_work",10,me);
		}
	}
	else if( (int)me->query("qi") < 50)
	{
		if (SKILL_D("force/recover")->exert(me, me))
		{
			if( (int)me->query("qi") < 50)
			{
				tell_object(me,"气血不足，等待恢复中。。。\n");
				call_out("auto_work",10,me);
			}
			else
			{
				call_out("auto_work",1,me);
			}
		}
		else
		{
			tell_object(me,"气血不足，等待恢复中。。。\n");
			call_out("auto_work",10,me);
		}
	}
	else
	{
		tell_object(me,"托管中，继续工作。。。。。。\n");
		tell_object(me,ZJFORCECMD("work auto"));
	}
}

int working(object me)
{
	object ob;
	int num,exp,pot;
	string msg;
	int finish;

	if(!me->query_temp("job/step"))
		me->set_temp("job/step", 1);
/*
	if(!living(me))
	{
		me->delete_temp("job/step");
		return 0;
	}*/

	finish = 0;
	me->receive_damage("qi", 5);
	me->receive_damage("jing", 5);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "你先对谷物除去壳皮。";
		break;
	case 2:
		msg = "然后放入磨盘。";
		break;
	case 3:
		msg = "开始一点一点的碾磨。";
		break;
	case 4:
		msg = "你磨呀磨。";
		break;
	case 5:
		msg = "。。。。。。";
		break;
	case 6:
		msg = "干得腰都要直不起来了。";
		break;
	case 7:
		msg = "你把磨成粉的谷物盛入一只袋子。";
		break;
	default:
		msg = "把袋子背到墙角放好。";
		finish = 1;
		break;
	}
	msg += "\n";

	msg = replace_string(msg, "$N", "你");
	tell_object(me, msg);

	if (finish)
	{
		if( random(me->query_temp("work_times"))>999 && random(me->query("kar"))>50)
		{
			message("vision",YEL"〖谷物加工厂〗"YEL": "HIW+ZJSIZE(22)+me->name()+NOR+YEL"由于工作勤劳，获得了老板的嘉奖!"NOR"\n",users()); 		
			message_vision("老板对$N说：嗯，做的不错，这是给你的奖励！\n",me);
			ob = new("/clone/money/gold"); 			
			ob->set_amount(5);	
			ob->move(me);
			me->add("combat_exp",1000);
			me->add("potential",800);
			tell_object(me,HIY"你得到了" + chinese_number(5) + "两黄金。\n"
				"你得到了" + chinese_number(1000) + "点经验。\n"
				"你得到了" + chinese_number(800) + "点潜能。"NOR"\n");

			me->delete_temp("work_times");
			me->set_temp("working",0);
			cot--;
			me->delete_temp("job/step");
			if(me->query_temp("pending/auto_work"))
			{
				call_out("auto_work",1,me);
			}
			return 0;
		}

		message_vision("$N终于把周围的谷物都加工完毕，可人也累的半死。\n", me);
		exp=20+random(80);
//		me->add("combat_exp",exp);

	if (me->query("zjvip/times") >0)
	{
pot=30+random(45);
}
else
       pot=30+random(30);

		me->add("potential",pot);
                me->add_temp("work_times",1);

		ob = new("/clone/money/silver");	
		num=1+random(2);
		ob->set_amount(num);
		ob->move(me);
if (me->query("zjvip/times") >0)
{
		message_vision("老板对$N说：这是你的工钱，因为你是vip会员，所以获得10点加成。\n", me);
}
else
message_vision("老板冷冷对$N说：这是你的工钱。\n", me);
		tell_object(me,HIW"你得到了" + chinese_number(num) + "两银子。\n"
			HIM"你得到了" + chinese_number(pot) + "点潜能。\n"
			HIY"你已经连续工作了"+ chinese_number(me->query_temp("work_times")) +"次。"NOR"\n");
		me->set_temp("working",0);
		cot--;
		me->delete_temp("job/step");
		if(me->query_temp("pending/auto_work"))
		{
			call_out("auto_work",5,me);
		}
		return 0;
	}
	me->add_temp("job/step", 1);
	return 1;
}

int halt_working(object me)
{
	message_vision("$N放下手中的谷物，叫到：累死了，真不是人干的活儿！\n", me);
	tell_object(me,ZJEXITRM"northwest\n");
	me->delete_temp("pending/auto_work");
	me->delete_temp("job/step");
	me->delete_temp("work_times");
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("job/step")){
		me->delete_temp("work_times");
	        me->delete_temp("job/step");
		tell_object(me,GRN"你偷偷溜出了谷物加工厂。"NOR"\n");
	}
	return ::valid_leave(me, dir);
}
void reset()
{
	cot=0;
	::reset();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
