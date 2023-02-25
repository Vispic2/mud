#include <room.h>
inherit ROOM;
#define OUTROOM "/d/fuben/qianchipu/qianchipu"

#define LUNJIAN_DAY		3
#define LUNJIAN_HOUR		21
#define LUNJIAN_PRE		9
#define LUNJIAN_TURN		10
#define LUNJIAN_USER_MIN	2
#define OUT_TIME			300
#define MIN_SKILL			200

string *total = ({});
int turn = 0;
mapping allusers = ([]);
int stime;

private void init_player(object me);
private void message_competition(string msg);
private void auto_check();
private void restore_status(object me);
int check_win(object me);
int check_out(object me);

void create()
{
	set("short", HIY"武林大会"NOR);
	set("long", "这里是武林大会比武现场，谁是武林第一人呢。");
	set("exits", ([
		"west" : OUTROOM,
	]));
	set("no_fight",1);
	//set("no_fly",1);
	set("objects",([
	]));
	set("action_list",([
//	"正在战斗" : "in_the_room",
		"武林大会":"jjsign",
	//	"称号奖励":"lunjiangift",
	//	"积分兑换":"ljshop",
	]));
	setup();
}

void init()
{
//	add_action("ljshop","ljshop");
	add_action("jjsign","jjsign");
//	add_action("lunjiangift","lunjiangift");
	//	add_action("in_the_room", "in_the_room");
}

int in_the_room()
{
    object *rooms = children("/d/lunjians/jingji");
    object room, *players;
    string str = "";
    
    foreach(room in rooms)
    {
        players = filter_array(all_inventory(room), (: ($1)->is_player() :));
        if (sizeof(players) == 2)
            str += players[0]->query("name") + " VS " + players[1]->query("name") + ZJBR;
    }
    if (str && str != "")
    {
        write(ZJOBLONG + "现在正在比赛的人有：" + ZJBR + str + "\n");
    }
    else
    {
        write(ZJOBLONG + "现在无人战斗。\n");
    }
    return 1;
}

int ljshop(string arg)
{
	string *list,str,file,price;
	int i,yuanbao,value;
	object me,ob;
	int amount;
	mapping goods,times;

	me = this_player();
	goods = ([
	    "/clone/shizhe/wujueling":100,
        "/cloen/shizhe/dan_jiuzhuan":10,
    	"/clone/shizhe/putao1":5,
        "/clone/shizhe/putao":1,
         "/clone/shizhe/jinsha":1,
         "/clone/shizhe/fushougao":1,
     	"/clone/shizhe/dan_chongmai1":1,
     	"/clone/shizhe/dan_chongmai2":2,
     	"/clone/shizhe/dan_chongmai3":3,
     	"/clone/shizhe/dan_chongmai4":5,
        
	]);
	times = ([
		"/clone/lunjian/wujueling":10000,
	]);
	list = keys(goods);
	if (! arg)
	{
		str = ZJOBLONG"你目前有"+me->query("lunjian/potsss")+"论剑积分，请选择您想兑换的道具：\n"ZJOBACTS2+ZJMENUF(3,3,8,32);
		for(i=0;i<sizeof(list);i++)
		{
			file = list[i];
			if(!goods[file]||file_size(file+".c")<0) continue;
			yuanbao = goods[file];
			price = yuanbao+"积分";
			str += sprintf("%s"ZJBR"%s:ljshop look %s"ZJSEP,file->query("name"),price,file);
		}
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"look %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];
		price = yuanbao+"积分";
		str = ZJOBLONG+"【"+file->query("name")+"】　　价格："+price+NOR+ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		if(times[file])
			str += HIR"此物品每个玩家限兑换"+times[file]+"次"NOR ZJBR;
		str += file->long();
		str += ZJOBACTS2+ZJMENUF(3,3,10,28);
		str += "兑换:ljshop buy "+file+"\n";
		tell_object(me,str+"\n");
		return 1;
	}
	else if (sscanf(arg,"buy %s",file)==1)
	{
		if(file_size(file+".c")<0||!goods[file])
			return notify_fail(HIM"兑换列表中没有这个道具！！"NOR"\n");

		yuanbao = goods[file];

		if(times[file])
		{
			if(me->query("lunjian/duihuan/"+file->query("id")) >= times[file])
				return notify_fail(HIM"此物品每个玩家只能兑换"+times[file]+"次！！"NOR"\n");
			me->add("lunjian/duihuan/"+file->query("id"),1);
		}
		if(me->query("lunjian/potsss") < yuanbao)
			return notify_fail(HIM"你的兑换积分不足，多参加参加论剑活动把！！"NOR"\n");
		me->add("lunjian/potsss",-yuanbao);
		ob = new(file);
	//	log_ufile(me,"pay/lunjian", "兑换了"+ob->short()+"。\n");
		tell_object(me,"你成功兑换到了"+ob->short()+"。"NOR"\n");
		ob->move(me);
		return 1;
	}
	else
		return notify_fail(HIM"你想干什么？？"NOR"\n");

	return 1;
}

int valid_leave(object me, string dir)
{
	if(allusers[me->query("id")])
	{
		tell_object(me,"你离开了武林大会，如果下一轮比赛不在场的话你将失去一次晋级机会。\n");
	}
	return ::valid_leave(me, dir);
}

int lunjiangift()
{
	object me;
	string str;
	
	me = this_player();
	str = FAMILY_D->bouns_lunjian_leader(me);
	tell_object(me,str);
	return 1;
}

int jjsign()
{
	int now = time();
	object me = this_player();

	if(localtime(now)[6]!=LUNJIAN_DAY||localtime(now)[2]!=LUNJIAN_HOUR||localtime(now)[1]>LUNJIAN_PRE)
		return notify_fail(ZJOBLONG"报名时间：周三晚"+LUNJIAN_HOUR+":00-"+LUNJIAN_HOUR+":10。\n");

	if (me->query("combat_exp")<200000)
		return notify_fail("你经验尚浅(20w)，还是把功夫练好再来吧。\n");

	if (me->query_skill("force")<180)
		return notify_fail("武林大会论剑起码要有180内功激发，你还是把功夫练好再来吧。\n");

	if (allusers[me->query("id")])
		return notify_fail("你已经报过名了，目前报名人数："+sizeof(allusers)+"。\n");

	if (query("iplist/"+me->query("id")))
		return notify_fail("同一个ip地址只能参加一个玩家。\n");

	allusers[me->query("id")]=1;
	set("iplist/"+me->query("id"),1);
	tell_object(me,"报名成功，请在此稍后，"+LUNJIAN_HOUR+"点10分自动进入竞技场中。\n");
	set_heart_beat(1);
	return 1;
}

int sort_total(string user1,string user2)
{
	return (int)allusers[user2]-(int)allusers[user1];
}

private void auto_check()
{
	object tmp1,tmp2,*inv,*rooms,ob;
	string name,msg;
	string *us,room;
	int i,hp1,hp2,jing1,jing2,force1,force2;

	rooms = children("/d/lunjians/jingji");
	if(!sizeof(rooms))
	{
		total = sort_array(keys(allusers),(: sort_total :));
		us = filter_array(total, (: find_player($1)&&present(find_player($1),$(this_object())) :));
		if(sizeof(us)<1 || turn >= LUNJIAN_TURN)
		{
			if(allusers[total[0]]<2)
			{
				msg = "听说武林大会死的死、逃的逃，未能决出【无双至尊】！";
				message_competition(msg);
			}
			else
			{
				if(ob = find_player(total[0]))
					name = ob->query("name");
				else
					name = TOP_D->get_name(total[0]);
				msg = "武林大会圆满结束，" + name + "获得【武林盟主】的称号！";
		//		FAMILY_D->set_lunjians_leader("武林盟主",total[0]);
				message_competition(msg);

		

				for(i=0;i<sizeof(total);i++)
				{
					if(i==0)
					{
						if(ob = find_player(total[0]))
						{
						   ob->add("combat_exp",300000);
							ob->add("yuanbao",1000);
							tell_object(ob,"你在本次武林大会中获得官方奖励300000，1000元宝。\n");
					
						}
					}
					else if(i>0 && i<5)
					{
						if(ob = find_player(total[i]))
						{
						   ob->add("combat_exp",200000);
							ob->add("yuanbao",500);
							tell_object(ob,"你在本次武林大会中获得官方奖励200000，500元宝。\n");
						}
					}
					else
					{
						if(ob = find_player(total[i]))
						{
						   ob->add("combat_exp",100000);
							ob->add("potential",10000);
							tell_object(ob,"你在本次武林大会中获得官方奖励100000，10000潜能\n");					
						}
					}
				}

				set_heart_beat(0);
				delete("pre_start");
				delete("start");
			}
			allusers = ([]);
			turn = 0;
			return;
		}
		while(sizeof(us)>1)
		{
			tmp1 = find_player(us[0]);
			us -= ({ tmp1->query("id") });
			tmp2 = find_player(us[0]);
			us -= ({ tmp2->query("id") });
			init_player(tmp1);
			init_player(tmp2);
			room = new("/d/lunjians/jingji");
			tmp1->move(room);
			tmp2->move(room);
			tmp1->kill_ob(tmp2);
			tmp2->kill_ob(tmp1);
		}
		if(sizeof(us))
		{
			ob = find_player(us[0]);
			ob->add("lunjian/potsss",1);
			allusers[us[0]] += 1;
			tell_object(ob,"\n你在本轮竞技中幸运轮空，自动晋级，请等待下一轮匹配。\n");
			tell_object(ob,"论剑积分+1！\n。\n");
		}
		stime = time();
		turn++;
		return;
	}
	for (i = 0; i < sizeof(rooms); i++)
	{
		inv = filter_array(all_inventory(rooms[i]),(: playerp($1) :));
		if(!sizeof(inv))
			destruct(rooms[i]);
		else if(sizeof(inv)==1)
		{
			allusers[inv[0]->query("id")]++;
			inv[0]->add("lunjian/potsss",1);	   
			check_win(inv[0]);
		}
		else if(sizeof(inv)==2)
		{
			if(time() - stime > OUT_TIME)
			{
				hp1 = inv[0]->query("qi")*100/(inv[0]->query("max_qi")+inv[0]->query_temp("apply/maxqi")+inv[0]->query_gain_qi());
				hp2 = inv[1]->query("qi")*100/(inv[1]->query("max_qi")+inv[1]->query_temp("apply/maxqi")+inv[1]->query_gain_qi());
				jing1 = inv[0]->query("jing")*100/(inv[0]->query_temp("apply/maxjing")+inv[0]->query("max_jing"));
				jing2 = inv[1]->query("jing")*100/(inv[1]->query_temp("apply/maxjing")+inv[1]->query("max_jing"));
				if(hp1>jing1) hp1 = jing1;
				if(hp2>jing2) hp2 = jing2;

				if(hp1>hp2)
				{
					allusers[inv[0]->query("id")]++;
					inv[0]->add("lunjian/potsss",1);	
					check_win(inv[0]);
					check_out(inv[1]);
				}
				else {
					allusers[inv[1]->query("id")]++;
					inv[1]->add("lunjian/potsss",1);						
					check_win(inv[1]);
					check_out(inv[0]);
				}
			}
		}
	}
}

private void init_player(object me)
{
	tell_object(me, HIY "你来到了武林大会的比武场..."NOR"\n");
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/want", me->query_want());
	me->set_temp("in_pkd", 1);

	me->set("backup/condition", me->query_condition());
	me->clear_condition();
}

private void message_competition(string msg)
{
	CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

private void restore_status(object me)
{
	mapping my;
	mapping cnd;
	string *ks;
	int i;

	me->delete_temp("in_pkd");
	me->delete_override("unconcious");
	me->delete_override("die");
	me->delete_override("quit");
	me->remove_all_enemy(1);
	me->remove_all_killer();
	me->clear_condition();
	me->receive_damage("qi", 0);
	me->apply_killer(me->query_temp("backup/killer"));
	me->apply_want(me->query_temp("backup/want"));

	cnd = me->query("backup/condition");
	me->delete("backup/condition");
	me->delete_temp("block_msg/all");
	if (! mapp(cnd)) return;
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = me->query_temp("apply/maxjing")+my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = me->query_temp("apply/maxqi")+my["max_qi"]+me->query_gain_qi();
	my["neili"]  = me->query_temp("apply/maxnei")+my["max_neili"];
}

void heart_beat()
{
	int i,now = time();
	object tmp1,tmp2,room,*inv;
	string msg;

	room = this_object();

	if(!query("pre_start")&&localtime(now)[1]==LUNJIAN_PRE)
	{
		set("pre_start",1);
		FAMILY_D->clear_lunjian();
		tell_room(this_object(),"1分钟后将进入竞技场，请做好准备。。。\n");
	}
	else if(!query("start")&&localtime(now)[1]==(LUNJIAN_PRE+1))
	{
		set("start",1);
		delete("iplist");
		stime = time();
		inv = filter_array(all_inventory(this_object()), (: playerp($1)&&$(allusers)[$1->query("id")] :));
		if(sizeof(inv)<LUNJIAN_USER_MIN)
		{
			msg = "听说本次武林大会参与人数太少，活动未能成功进行！";
			message_competition(msg);
			delete("pre_start");
			delete("start");
			set_heart_beat(0);
			return;
		}
		while(sizeof(inv)>1)
		{
			tmp1 = inv[random(sizeof(inv))];
			inv -= ({ tmp1 });
			tmp2 = inv[random(sizeof(inv))];
			inv -= ({ tmp2 });
			init_player(tmp1);
			init_player(tmp2);
			room = new("/d/lunjians/jingji");
			tmp1->move(room);
			tmp2->move(room);
			tmp1->kill_ob(tmp2);
			tmp2->kill_ob(tmp1);
		}
		if(sizeof(inv))
		{
			allusers[inv[0]->query("id")] += 1;
			tell_object(inv[0],"你在本轮竞技中幸运轮空，自动晋级，请等待下一轮匹配。\n");
		}
	}
	else if(localtime(now)[1]>LUNJIAN_PRE)
	{
		auto_check();
	}
}

int check_quit(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);

	tell_object(me, "你逃出了竞技场。\n");

	me->move(this_object());
	message("vision", "只见" + me->name() + "慌里慌张的跑了出来。\n",environment(me), ({ me }));
	return 1;
}

int check_out(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n你觉得眼前一阵模糊...这下完了！"NOR"\n");

	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);
	me->move(this_object());
	message("vision", "一个黑影倏的窜了出来，随即就是“啪”的一声，就见" + me->name() +"摔倒了地上，一副半死不活的样子。\n", environment(me), ({ me }));
	tell_object(me, "半昏半迷中，你觉得被人拎了起来，又重重的摔倒了地上。\n");
	if (! living(me))
		me->revive();
	return 1;
}

int check_win(object me)
{
	object ob;
	mapping my;
	string msg;

	my = me->query_entire_dbase();
	my["jing"]   = my["eff_jing"]   = my["max_jing"];
	my["jingli"] = my["eff_jingli"] = my["max_jingli"];
	my["qi"]     = my["eff_qi"]     = my["max_qi"]+me->query_gain_qi();
	my["neili"]  = my["max_neili"];

	tell_object(me, HIR "\n你在本轮论剑中获胜晋级！"NOR"\n");
	tell_object(me, HIR "\n论剑积分+1！"NOR"\n");
	if(me->is_busy())
		me->interrupt_me(me,me->query_busy());

	restore_status(me);
	me->move(this_object());

	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
