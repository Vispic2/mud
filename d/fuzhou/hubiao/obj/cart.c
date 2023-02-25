#include <ansi.h>
#include <room.h>
inherit ITEM;

object me,jf;
int checkteam();
void destructing(object);

void create()
{
	set_name(HIR"镖车"NOR, ({ "biao che", "silver cart", "cart", "che"}) );
	set_weight(300000);
	set("no_get", 1);
	set("no_get_from", 1);
	set_max_encumbrance(80000);
	set("unit", "辆");
	set("long", "一辆黑漆漆的镖车，上面插着福威镖局的镖旗。\n");
	set("closed", 1);
	set("value", 2000);
	set("location",1);
}

string long()
{
	string *dirs,str;
	object room,env;
	mapping exits;
	int i;

	str = replace_string(this_object()->query("long"),"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]==ZJBR)
		str = str[0..(strlen(str)-5)];
	str = ZJOBLONG+str+"\n";
	str += ZJOBACTS2+ZJMENUF(2,2,10,30);
	str += "劫镖:open cart"ZJSEP"关门:close cart"ZJSEP;
	str +="交镖:finish";
	if (this_player()->query_temp("protecting") == this_object())
	{
		env = environment(this_object());
		if (mapp(exits = env->query("exits")))
		{
			dirs = keys(exits);
			dirs -= ({ 0 });
			for (i=0;i<sizeof(dirs);i++)
			{
				if(!room=find_object(exits[dirs[i]]))  room=load_object(exits[dirs[i]]);
				if(room)  str+=sprintf(ZJSEP"推往%s:driver %s",room->query("short")+"-"+dirs[i],dirs[i]);
			}
		}
	}
	write(str+"\n");
	return "";
}

int is_container() {return 1;}

void init()
{
	add_action("do_open","open");
	add_action("do_close","close");
	if (this_player()->query_temp("protecting") != this_object())
		return;
	add_action("do_driver", ({"driver", "tui", "dr"}));
	add_action("do_finish", "finish");
}

int do_close(string arg)
{
	object ob=this_object();
	me = this_player();
	if(arg != "cart" && arg != "silver cart")
		return notify_fail("你要关上什么？\n");
	message_vision("$N把$n门关上了。\n", me, ob);
	ob->set("closed",1);
	return 1;
}

int do_open(string arg)
{
	object cart;
	object *obj;
	int i,zd=0;

	if(arg != "cart" && arg != "silver cart")
		return notify_fail("你要打开什么？\n");
	me = this_player();
	cart = this_object();
	set("closed",0);
	if(!checkteam())
		return 1;

	if( me->query("combat_exp") < 500000 )
		return notify_fail("就凭你这点经验，还想学别人抢镖车？\n");

	if ( environment(me)->query("no_fight"))
		return notify_fail("这里动手不太好吧？\n");

	message_vision("$N将$n盖打开。\n", me, this_object());

	if( me->query_temp("protecting") && me->query_temp("protecting") == cart){
		return notify_fail("想监守自盗？这样不好吧！\n");
	}
	obj = all_inventory(environment(me));
	for(i=0; i<sizeof(obj); i++) {
		if (obj[i]!=me && obj[i]->query_temp("protecting")==cart) {
			me->kill_ob(obj[i]);
			obj[i]->kill_ob(me);
		}
	}
	return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}

int do_driver(string arg)
{
	object *obj, *team;
	int i, j, maxexp=0;
	string dir, roomfile, newroomfile;
	object cart, room, newroom, maxplayer;
	string dirname;

	me = this_player();
	cart = this_object();
/*
	if (me->query_temp("protecting") != cart)
		return notify_fail("你又没参加这次护镖，瞎忙活什么啊？\n");
*/
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你现在忙得很，不能指挥镖车前进。\n");

	if (query_temp("busy/"+me->query("id")))
		return notify_fail("你推那么快，想把镖车弄散架吗？\n");

	if(!checkteam())
		return 1;

	team = me->query_team();
	if (sizeof(team)==0) team=({me});
/*
	if (sizeof(team) != 0 && (team[0]!=me))
		return notify_fail("只有队伍首领才能指挥镖队前进。\n");
*/
	for(i=0;i<sizeof(team);i++){
		if(team[i]->query("combat_exp") > maxexp) {
			maxexp=team[i]->query("combat_exp");
			maxplayer=team[i];
		}
	}
	room = environment(cart);
	roomfile = file_name(room);

	obj = all_inventory(room);
	for(j = 0; j < sizeof(obj); j++)
		if(obj[j]->query("hubiao_jiefei") && obj[j]->query_temp("target") == cart) break;
	if( j < sizeof(obj))
		return notify_fail("劫匪尚未除去，你想往哪里走？！\n");
	switch(arg) {
		case "e":	dir="east";		dirname="东面";		break;
		case "w":	dir="west";		dirname="西面";		break;
		case "n":	dir="north";		dirname="北面";		break;
		case "s":	dir="south";		dirname="南面";		break;
		case "ne":	dir="northeast";	dirname="东北";		break;
		case "nw":	dir="northwest";	dirname="西北";		break;
		case "se":	dir="southeast";	dirname="东南";		break;
		case "sw":	dir="southwest";	dirname="西南";		break;
		case "u":	dir="up";		dirname="上面";		break;
		case "up":	dir="up";		dirname="上面";		break;
		case "d":	dir="down";		dirname="下面";		break;
		case "down":	dir="down";		dirname="下面";		break;
		case "nu":	dir="northup";		dirname="北边";		break;
		case "eu":	dir="eastup";		dirname="东边";		break;
		case "su":	dir="southup";		dirname="南边";		break;
		case "wu":	dir="westup";		dirname="西边";		break;
		case "nd":	dir="northdown";	dirname="北边";		break;
		case "ed":	dir="eastdown";		dirname="东边";		break;
		case "sd":	dir="southdown";	dirname="南边";		break;
		case "wd":	dir="westdown";		dirname="西边";		break;
		case "enter":	dir="enter";		dirname="里面";		break;
		case "out":	dir="out";		dirname="外面";		break;
		default:	dir=arg;		dirname="一边";		break;
	}
	if(!room || !room->query("exits/"+dir))
		return notify_fail("你要往哪里去？\n");

	newroomfile=room->query("exits/"+dir);
	if (room->query_door(dir, "status") & DOOR_CLOSED)
		return notify_fail("你必须先把" + room->query_door(dir, "name") + "打开！\n");

	if(!objectp(newroom=find_object(newroomfile))) newroom=load_object(newroomfile);

	message_vision(HIW"镖车在$N的护卫下缓缓地往"+dirname+"的"+newroom->query("short")+HIW"离去了。"NOR"\n", me);

	move(newroom);
	tell_object(me,ZJFORCECMD(dir));
	// 计算时间
	i = uptime();
	if (query("last_time")) add("total_time", i-query("last_time"));
	set("last_time", i);
	if (query("fei_time")) add("total_time", query("fei_time")-i+5);
	delete("fei_time");
	if (sizeof(newroom->query("exits")) == 1)
		set("fei_time", i);

	if ( query("address" + base_name(newroom)+".c"))
		add("hehe", 1);

	add("step", 1);
	set("address" + base_name(newroom)+".c", 1);

//	me->start_busy(random(3) + 2);
	dir = "busy/"+me->query("id");
	set_temp(dir, 1);
	call_out("delete_temp", 4 + random(3), dir);
	tell_room(newroom, HIW"镖车在镖队的护卫下缓缓地行进过来了。"NOR"\n");

	remove_call_out("fail");
	remove_call_out("check");
	remove_call_out("check2");

	if (!query_temp("safe")) {
		set_temp("safe", 1);
		set_temp("s_time", 1);
		call_out("delete_temp", 5+random(4), "s_time");
	}
	if (!newroom->query("no_fight") && !query_temp("s_time") && random(10) < 6) {
		call_out("delete_temp", 15, "safe");
		set_temp("s_time", 1);
		set("fei_time", i);

		jf = new(__DIR__"cateran");
		jf->set_temp("target", cart); //要抢劫的目标
		jf->set_temp("team_member", maxplayer->query_team());
		jf->do_copy(maxplayer);

		jf->move(newroom);
		add("cateran", 1);
		tell_room(newroom,HIR"突然跳出个劫匪！"NOR"\n");
		tell_room(newroom,HIR+jf->query("name")+"恶狠狠地说道：乖孙子，留下钱财好好孝敬你爷爷吧。"NOR"\n");
/*
		for(i=0; i<sizeof(obj); i++){
			if(userp(obj[i]) && obj[i]->query_temp("protecting") == cart){
				obj[i]->fight_ob(jf);
				jf->kill_ob(obj[i]);
			}
		}
*/
		call_out("check", 1, me);
	} else {
		call_out("fail", 300, cart);
	}
	return 1;
}

int do_finish(string arg)
{
	object cart, gold, where, target,dan;
	object* obj,* team;
	int i, j;

	me = this_player();
	cart = this_object();
/*
	if (me->query_temp("protecting") != cart)
		return notify_fail("你又没参加这次护镖，瞎忙活什么啊？\n");
*/
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if (!checkteam())
		return 1;

//	if (sizeof(team)==0) team=({me});

	team=me->query_team();

	if (sizeof(team) != 0 && (team[0]!=me))
		return notify_fail("只有队伍首领才能决定护镖是否已经结束。\n");

	where = environment(me);
	obj = all_inventory(where);

	for(j=0; j<sizeof(obj); j++) {
		if(obj[j]->query("hubiao_jiefei")
		&& objectp(obj[j]->query_temp("target",1))
		&& obj[j]->query_temp("target",1)==cart)
			break;
	}
	if(j < sizeof(obj))
		return notify_fail("劫匪还在，本次任务尚未完成！\n");

	for(j=0; j < sizeof(team); j++){
		if(!present(team[j]) || team[j]->query_temp("protecting") != cart)
			break;
	}

	if( me->query_temp("hubiao/where") != file_name(where))
		return notify_fail("你现在还没有到达目的地！\n");

	if( j < sizeof(team))
		return notify_fail("你的队员尚未到齐！\n");

	if (! present(target = me->query_temp("hubiao/target"), where))
		return notify_fail("咦？把镖交给谁啊？\n");

	j = 0;
	for (i=0; i<sizeof(team); i++)
		if (team[i]->query_temp("protecting") == cart)
			j++;

	if (j > 0) {
		int jl, exp, exp1, times, time, tui_time, step, hehe, cateran;

		time = uptime()-me->query_temp("hubiao/biao_time");
		tui_time = query("total_time");
		step = query("step");		// 实际路程
		hehe = query("hehe");		// 多走的路
		cateran = query("cateran");	// 劫匪人数
		i = (step - hehe)/4;
		exp += i * 18;
		if (cateran > i) exp = i * 80 + (cateran - i) * 20;
		else exp = cateran * 80;
		exp1 = exp;
		exp -= hehe * hehe * 4;	// 多走的惩罚
		times = -10 + step * 5;

		if (tui_time > times) exp -= (tui_time - times) * 3;
		else exp += times - tui_time;

		if (step < 1) step = 1;

		if (exp < 100)
			exp = 100 +random(50);

		i = time * 85 / 36;		// 提高上限至 8.5K / hour 2002.11.07 By River@SJ
		if (exp > i)
			exp = i + random(exp-i);

		if (exp < 500 )  // 下限保证
			exp = 500;

		exp *= 2;
		exp /= j;

		if (wizardp(me))
			tell_object(me, sprintf("time = %d, times = %d, j = %d, step = %d \n", time, times, j, time/step));

		for (i=0; i < sizeof(team); i++)
		if (team[i]->query_temp("protecting")==cart) {
			jl = 2000+random(1001);
			//jl = team[i]->add_exp_combat(jl,target,"护镖");
			j = jl/9;
			team[i]->add_busy(1);	
			team[i]->add("combat_exp",jl);		
			team[i]->add("potential", j);
			team[i]->add("balance", 500000);
if (team[i]->query_condition("db_exp")) {
        team[i]->add("combat_exp", jl);
	tell_object(team[i],HIY"由于精英之书的作用，你额外获得了"+chinese_number(jl)+"点经验！"NOR"\n");}
			team[i]->set("job_name", "福州护镖");
			team[i]->clear_condition("job_busy");

			gold = new("/clone/money/gold");
			gold->set_amount(5);
			if (gold && !(gold->move(team[i])))
				gold->move(environment(team[i]));
			if (target && random(100)>40) {
			      dan = new("/clone/vip/dan_chongmai2");
                        dan->move(team[i]);
				tell_object(team[i], CYN + target->query("name") + "对你表示衷心的感谢，并赠送给你一颗冲脉丹[中品]。"NOR"\n");
			/*//log_files("job/hubiao_rewards", sprintf("%s，%s%s护镖完成奖励一颗冲脉丹[中]，经验%d，潜能%d，现在经验%d。\n",
				ctime(time()),
				team[i]->query("name"),
				"("+capitalize(team[i]->query("id"))+")",
				jl,
				j,
				team[i]->query("combat_exp")));
				*/
                        }
                  else if (target) tell_object(team[i], CYN + target->query("name") + "对你表示衷心的感谢。"NOR"\n");

			tell_object(team[i],HIY"你被奖励了"+chinese_number(jl)+"点经验，"+chinese_number(j)+"点潜能，"+chinese_number(5)+"两黄金！"NOR"\n");

			/*//log_files("job/hubiao", sprintf("%8s%-10s护镖任务奖励经验%4d，潜能%3d，现在经验%d。\n",
				team[i]->query("name"),
				"("+capitalize(team[i]->query("id"))+")",
				jl,
				j,
				team[i]->query("combat_exp")), team[i]
			);
			*/
			write_file("/log/job/Hubiao", sprintf("%8s%-10s护镖奖励经验%4d,潜能%3d,现在经验%d,应得%d,步数%d,费时%d,劫匪%d,推时%d/%d,走错%d)。\n",
				team[i]->query("name"),
				"("+capitalize(team[i]->query("id"))+")",
				jl,
				j,
				team[i]->query("combat_exp"),
				exp1,
				step,
				time,
				cateran,
				times,
				query("total_time"),
				hehe)
			);
		}
	}
	for(i=0; i<sizeof(obj); i++) {
		if(obj[i]->query_temp("protecting")==cart && userp(obj[i])) {
			obj[i]->delete_temp("protecting");
		}
	}
	me->dismiss_team();
	if ( target)
		destruct(target);
	CHANNEL_D->do_channel( this_object(), "rumor",sprintf("%s率镖队顺利到达%s！", me->name(1), query("arrive")));
	destructing(cart);
	return 1;
}

void check(object me)
{
	object cart;
	object* obj,* team;
	int j;

	cart=this_object();
	obj = all_inventory(environment(cart));
	if(!checkteam())
		return;
	team=(query_temp("team1"))->query_team();
	for(j=0; j<sizeof(obj); j++) {
		if(obj[j]->query("hubiao_jiefei")
		&& objectp(obj[j]->query_temp("target",1))
		&& obj[j]->query_temp("target",1)==cart)
			break;
	}
	if(j >= sizeof(obj)) {
		remove_call_out("fail");
		call_out("fail", 300, cart);
		return;
	}
	for(j=0;j<sizeof(team);j++) {
		if(present(team[j], environment(cart))
		 && team[j]->query_temp("protecting")==cart)
			break;
	}
	if( j >= sizeof(team)) {
		call_out("check2", 30, me);
	}
	else {
		remove_call_out("check");
		call_out("check", 1, me);
	}
}

void check2(object me)
{
	object cart;
	object* obj,* team;
	int j;

	cart=this_object();
	obj = all_inventory(environment(cart));
	if(!checkteam())
		return;
	team = (query_temp("team1"))->query_team();
	for( j=0; j < sizeof(obj); j++) {
		if(obj[j]->query("hubiao_jiefei")
		&& objectp(obj[j]->query_temp("target",1))
		&& obj[j]->query_temp("target",1)==cart)
			break;
	}
	if( j >= sizeof(obj)) {
		remove_call_out("fail");
		call_out("fail", 60, cart);
		return;
	}
	for(j = 0; j < sizeof(team);j++) {
		if( present(team[j], environment(cart))
		 && team[j]->query_temp("protecting")==cart)
			break;
	}
	if( j >= sizeof(team)){
		for(j=0; j<sizeof(team); j++) {
			team[j]->dismiss_team();
			if (team[j]->query_temp("protecting")==cart)
				team[j]->delete_temp("protecting");
	 	        //log_files("job/hubiao",sprintf("%8s%-10s护镖任务失败，现在经验%d。\n",
				//team[j]->name(1),"("+capitalize(team[j]->query("id"))+")", team[j]->query("combat_exp")), team[j]);
			tell_object(team[j],HIR"由于你护镖失败，交给镖局的五十两黄金被用来赔偿了。"NOR"\n");
		}
		tell_room(environment(cart),HIR"劫匪嘿嘿一笑，道：今天又捞了一票。话毕推着镖车走了。"NOR"\n");
		CHANNEL_D->do_channel( this_object(), "rumor", sprintf("%s的镖车被劫匪劫走了！", query("teamhead")));
		destructing(cart);
	}
	else {
		remove_call_out("check");
		call_out("check", 1, me);
	}
}

void destructing(object ob)
{
	object * obj;
	int i;
	object cart=this_object();

	obj = all_inventory(environment(cart));
	for(i=0; i<sizeof(obj); i++) {
		if((obj[i]->query("biaotou")|| obj[i]->query("id")=="biao shi")
		   && obj[i]->query_temp("protecting") == cart){
			destruct(obj[i]);
		}
		else if(obj[i]->query("hubiao_jiefei")
			&& objectp(obj[i]->query_temp("target",1))
			&& obj[i]->query_temp("target",1) == cart)
			destruct(obj[i]);
	}
	destruct(cart);
}

void fail(object ob)
{
	object cart;
	object * team;
	int j;

	cart = this_object();
	if (query_temp("team1")) {
 		team=(query_temp("team1"))->query_team();
		for(j=0; j<sizeof(team); j++) {
			team[j]->dismiss_team();
			if (team[j]->query_temp("protecting")==cart)
				team[j]->delete_temp("protecting");
	 	      //  //log_files("job/hubiao",sprintf("%8s%-10s护镖任务失败，现在经验%d。\n",
				//team[j]->name(1),"("+capitalize(team[j]->query("id"))+")", team[j]->query("combat_exp")),team[j]);
			tell_object(team[j],HIR"由于你护镖失败，交给镖局的五十两黄金被用来赔偿了。"NOR"\n");
		}
		CHANNEL_D->do_channel( this_object(), "rumor",sprintf("%s及其镖队护镖失败！", query("teamhead")));
	}
	destructing(cart);
}

int checkteam()
{
	int teams,deathcs;
	object cart,me;
	object* team,* team2;
	int j, fail=0;

	cart=this_object();
	teams = query_temp("teams",1);
	team2 = ({cart});
	if( teams > 0) {
		me=query_temp("team1",1);
		if(!objectp(me))
			fail=1;
		else
			team2+=({me});
	}
	if(teams > 1) {
		me=query_temp("team2",1);
		if(!objectp(me))
			fail=1;
		else
			team2+=({me});
	}
	if(teams > 2) {
		me=query_temp("team3",1);
		if(!objectp(me))
			fail=1;
		else
			team2+=({me});
	}
	if (teams > 3) {
		me=query_temp("team4",1);
		if(!objectp(me))
			fail=1;
		else
			team2+=({me});
	}
	team2-=({cart});
	if (!fail) {
		team=team2[0]->query_team();
		if (sizeof(team)==0) team=({team2[0]});
		for(j=0;j<teams;j++) {
			deathcs=team2[j]->query_temp("death",1);
			if(deathcs < team2[j]->query("death_count"))	break;
			else if(member_array(team2[j], team)==-1)	break;
			else if(team2[j]->is_ghost())			break;
			else if(!team2[j]->is_character())		break;
		}
		if(j < teams)
			fail = 1;
	}

	if (!fail) {
		if (query("target"))
			return 1;
		message("team", "接镖人等得不耐烦，已经离开了。\n", team2);
	}

	for(j=0; j<sizeof(team2); j++){
		team2[j]->dismiss_team();
		if (team2[j]->query_temp("protecting")==cart)
			team2[j]->delete_temp("protecting");
	      //  //log_files("job/hubiao",sprintf("%8s%-10s护镖任务失败，现在经验%d。\n",
			//team2[j]->name(1),"("+capitalize(team2[j]->query("id"))+")", team2[j]->query("combat_exp")), team2[j]);
		tell_object(team2[j],HIR"由于你护镖失败，交给镖局的五十两黄金被用来赔偿了。"NOR"\n");
	}

	if (fail)
		CHANNEL_D->do_channel( this_object(), "rumor",sprintf("%s的镖车被劫匪劫走了！", query("teamhead")));
	else
		CHANNEL_D->do_channel( this_object(), "rumor",sprintf("%s的镖队没能及时达到目的地！", query("teamhead")));
	destructing(cart);
	return 0;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
