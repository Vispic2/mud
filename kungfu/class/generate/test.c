// person used in quest

// 更新的内容：
// void die()   - 任务 npc 死亡时给任务玩家准备远程任务

#include <ansi.h>

inherit CLASS_D("generate") + "/chinese";

int  accept_object(object who, object ob);

void random_move();
int  leave();
int  is_stay_in_room()	{ return 1; }

void create()
{
	::create();
	set("gender", "男性" );
	set("age", 30 + random(30));
	set("long", "");
	set("attitude", "friendly");
	set("chat_chance", 30);
	set("chat_msg", ({ (: random_move :) }));
	set("chat_chance_combat", 120);
	set("scale", 150);
	set("no_get", 1);

	set_temp("apply/armor", 100);
	set_temp("apply/damage", 15);
	set_temp("born_time", time());
	set_temp("dest_time", 900 + time());

	add_money("silver", 10 + random(20));

	if (clonep()) keep_heart_beat();
}

void set_from_me(object me)
{
	int exp;
	mapping my;

	NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
	my = query_entire_dbase();

	if (my["max_qi"] > 5000)
		my["max_qi"] = 5000;

	if (my["max_jing"] < my["max_qi"] / 2)
		my["max_jing"] = my["max_qi"] / 2;

	if (my["max_jing"] > 3000)
		my["max_jing"] = 3000;

	my["eff_jing"] = my["max_jing"];
	my["jing"] = my["max_jing"];
	my["eff_qi"] = my["max_qi"];
	my["qi"] = my["max_qi"];
	my["quest_count"] = me->query("quest_count");

	exp = me->query("combat_exp") * 11 / 10;
	if (exp > query("combat_exp"))
		set("combat_exp", exp);

	if (my["combat_exp"] > 200000 && random(100) < 5)
	{
		// 经验 > 200K，5%几率出现多个敌人
		set_temp("multi-enemy", 1);
	}

	if (my["combat_exp"] > 800000){
		my["jiali"] = query_skill("force") / 3;
	}
	else{
		my["jiali"] = query_skill("force") / 6;
	}

	if (query("place") == "西域")
		set_temp("dest_time", 1800 + time());
	else
		set_temp("dest_time", 900 + time());
}

void kill_ob(object ob)
{
	int lvl;

	if (! is_busy())
		exert_function("powerup");

	if (ob->query("quest/id") != query("id"))
	{
		::kill_ob(ob);
		return;
	}

	if (lvl = query_temp("multi-enemy"))
	{
		// 出现多个敌人
		delete_temp("multi-enemy");
		call_out("do_help_me", 1 + random(2), ob);
	}
	::kill_ob(ob);
}

void do_help_me(object ob)
{
	if (! objectp(ob) || environment(ob) != environment() ||
	    ! living(ob))
		return;

	switch (random(3))
	{
	case 0:
		message_vision(HIW "\n$N" HIW "大声喝道：“好一个" +
			       ob->name(1) +
			       HIW "！各位，不要再等了，快出来帮" +
			       RANK_D->query_self(this_object()) +
			       "一把！”"NOR"\n", this_object(), ob);
		break;

	case 1:
		message_vision(HIW "\n$N" HIW "忽然撮舌吹"
			       "哨，你听了不禁微微一愣。"NOR"\n",
			       this_object());
		break;

	case 2:
		message_vision(HIW "\n$N" HIW "一声长啸，声音"
			       "绵泊不绝，远远的传了开去。"NOR"\n",
			       this_object());
		break;
	}

	call_out("do_continue_help", 1 + random(4), ob);
}

void do_continue_help(object ob)
{
	int n;
	object *obs;

	if (! objectp(ob) || environment(ob) != environment())
		return;

	n = random(3) + 1;
	ob->set_temp("quest/help_count", n);
	message("vision", HIR "说时迟，那时快！突然转出" +
			  chinese_number(n) +
			  "个人，一起冲上前来，看来是早"
			  "有防备！"NOR"\n", environment());

	// 生成帮手
	obs = allocate(n);
	while (n--)
	{
		obs[n] = new(CLASS_D("generate") + "/killed.c");
		NPC_D->set_from_me(obs[n], ob, 100);
		obs[n]->delete_temp("multi-enemy");
		obs[n]->set_temp("help_who", this_object());
		obs[n]->set_temp("is_helper", 1);
	}

	// 参与战斗 */
	set_temp("help_ob", obs);
	set_temp("help_count", sizeof(obs));
	obs->move(environment());
	obs->set_leader(this_object());
	obs->kill_ob(ob);
}

int filter_to_bonus(object ob, object aob)
{
	if (! playerp(ob) || ! living(ob) ||
	    ! ob->is_killing(query("id")))
		// 必须是玩家并且参与屠杀我(NPC)
		return 0;

	// 协助的对象一致
	return (aob == ob->query_temp("quest/assist"));
}

// remove
void remove()
{
	object qob;

	if (objectp(qob = query_temp("quest_ob")))
		// 这个人已经消失了，取消相关联的任务
		destruct(qob);

	::remove();
}

// 随即重新放置
void random_place(string msg)
{
	object old_env;
	object qob;
	string *not_place;
	string new_place;
	int limit;
	int qcount;

	// 如果原先创建了任务，就直接修改信息
	if (objectp(qob = query_temp("quest_ob")))
		qob->set("introduce", msg);
	else
		qob = new("/clone/quest/avoid");

	// 随即选择另外一个地方放置NPC
	old_env = environment();
	not_place = ({ query("place") });
	if (query("combat_exp") < 500000)
		not_place += ({ "大理一带" });
	if (query("combat_exp") < 800000)
		not_place += ({ "西域" });
	NPC_D->place_npc(this_object(), not_place);

	// 根据格式化消息生成结果
	msg = replace_string(msg, "$N", name(1));

	qcount = query("quest_count");
	if ((qcount < 100 || qcount >= 900) && random(10) ||
	    (qcount >= 100 && qcount < 900) && random(50))
	{
		new_place = query("place");
		if (new_place == "西域")
			limit = 1800;
		else
			limit = 900;
	} else
	{
		new_place = "很远的地方";
		limit = 1200;
	}
	set_temp("dest_time", limit + time());
	msg = replace_string(msg, "PLACE",  new_place);

	// 初始化并记录这个任务
	qob->set("introduce", msg);
	qob->init_quest(name(1), old_env);
	set_temp("quest_ob", qob);
}

// 晕倒的时候有机会逃走
void unconcious()
{
	object *obs;
	object ob;
	mapping my;
	string msg;
	string quester;

	if (! query_temp("is_helper") && ! query_temp("help_ob"))
	{
		if (random(100) < 10)
		{
			// 10%几率逃走
			switch (random(8))
			{
			case 0:
				msg = "$N狂叫一声，狂吐几口鲜血，眼"
				      "看就已不支，忽然一道黑影窜出"
				      "，接连攻出数招，逼退$n，只在"
				      "这么一瞬间，此人已经扶起$N，"
				      "遁逃而走，竟然未留半点痕迹。\n";
				break;
			case 1:
				msg = "$N摇摇欲坠，眼看就要跌倒，忽"
				      "然口中喷出一口鲜血，$n连忙侧"
				      "身一避，就在此时，$N奋然振作"
				      "精神，提气一纵，竟然飘出十数"
				      "丈之远，令人目瞪口呆！只见$N"
				      "刹间变做一个黑影，渐渐消失。\n";
				break;
			case 2:
				msg = "在$n一阵狂攻之下，$N只有招架"
				      "之功，哪里还有还手之力？眼看"
				      "就要命丧$n之手，$N忽然招式一"
				      "变，精妙无方，竟是世上罕见！"
				      "$n略一疏神，已被$N连环数招逼"
				      "退，只见$N迈开大步，逃遁而走。\n";
				break;
			case 3:
				msg = "$N深吸一口气，神色略微好了一"
				      "些，忽然迸发出惊天动地的一声"
				      "大吼，震得$n发耳欲聩！只这一"
				      "下，$N身形一转，飘然退去，竟"
				      "让$n措手不及，追赶不上！\n";
				break;
			case 4:
				msg = "$n连连进击，眼看便要得手，接"
				      "连数招，让$N已是避无可避，退"
				      "无可退！$N神色仓皇，急切"
				      "间猛地咬中舌尖，“噗”的吐出"
				      "！$n只见眼前一阵红雾，待得雾"
				      "散去，哪里还有$N的影子？\n";
				break;
			case 5:
				msg = "$N再退一步，却慢了小许，腿上"
				      "早中招！一声惨呼，人已跌倒。"
				      "$n见状赶上前去，忽然眼前星光"
				      "闪闪，仓皇下急退，只听有人哈"
				      "哈大笑道：“$N莫慌，我来也！"
				      "”说罢又是一撒手，数十根银针"
				      "飞出，待得$n抵挡两下，那人早"
				      "扶起$N遁去了。\n";
				break;
			case 6:
				msg = "$N晃了两下，忽然跌倒。$n收住"
				      "招式，笑道：“$N，你... ”话"
				      "音未落，忽见$N蓦的窜起，一招"
				      "直奔$n的要害，$n大吃一惊！慌"
				      "忙招架，只觉得内息紊乱，几欲"
				      "呕吐！$N也不追击，只是急奔而"
				      "走，$n连运几口气，去了胸前烦"
				      "闷，却已不见$N的踪影。\n";
				break;
			default:
				msg = "$N身负重伤，已然不敌，悲愤间"
				      "只放声疾呼，一时震得$n耳鼓欲"
				      "破，攻势少缓。$N猛然见到有机"
				      "可乘，哪里肯放过，连出数招，"
				      "杀出一条血路，就此不见。\n";
				break;
			}

			clean_up_enemy();
			obs = query_enemy();
			if (sizeof(obs) > 0) ob = obs[0]; else ob = 0;
			if (! objectp(ob))
				msg = replace_string(msg, "$n", "众人");
			message_sort("\n" + msg, this_object(), ob);

			// 解除NPC的中毒状态
			clear_condition(0);

			// 恢复NPC的力气
			my = query_entire_dbase();
			my["eff_jing"] = my["max_jing"];
			my["jing"]     = my["max_jing"];
			my["eff_qi"]   = my["max_qi"] * 2 / 3;
			my["qi"]       = my["eff_qi"];
			my["neili"]    = my["max_neili"] * 2;
			if (! intp(query_temp("escape_times")))
				set_temp("escape_times", 1);
			else
				add_temp("escape_times", 1);

			// 登记一个任务，以便玩家可以追踪他的行迹
			switch (random(9))
			{
			case 0:
				msg = "听说$N被人打伤逃走，据说是躲到PLACE去了。";
				break;
			case 1:
				msg = "听说$N和人动手，差点被打死，不过最"
				      "后还是侥幸逃走了，好像去了PLACE。";
				break;
			case 2:
				msg = "听说那$N和人一场血战，最后还是全身"
				      "而退，好像是去了PLACE吧。";
				break;
			case 3:
				msg = "$N听说是在PLACE啊，不过前一阵好像来过这里的。";
				break;
			case 4:
				msg = "听说$N被人打死了吧？咦？不过听人说"
				      "在PLACE也见过他呀！";
				break;
			case 5:
				msg = "这事我也不太清楚，不过听说他好像在PLACE。";
				break;
			case 6:
				msg = "你找他干啥？他不是在PLACE么？";
				break;
			case 7:
				msg = "前两天他还来过我们这儿呢，现在应该"
				      "是去了PLACE吧。";
				break;
			default:
				msg = "$N呀，有人说在PLACE看到过他，好像还受伤了。";
				break;
			}

			random_place(msg);
			remove_all_enemy(1);
			return;
		}
	}

	if (stringp(quester = query_temp("quester")))
	{
		// 如果找到领取该quest的人
		if (objectp(ob = find_player(quester)))
			ob->set_temp("quest/escape_times", query_temp("escape_times"));
	}
	::unconcious();
}

// 当任务的NPC死亡的时候，检查是否可以进行奖励某些玩家。奖励
// 的对象：帮助任务者完成这个任务的所有人， 当然首先要求杀的
// 这个人是任务的完成对象，其次就是在这个场景中对该NPC下了杀
// 命令，并且协助了任务的完成者的玩家。

// 当任务 NPC 死亡后，同时询问玩家是否愿意立即领取奖励，若同
// 意则不必 cut head，并且不必返回师门，立即开始下一个任务。
void die(object killer)
{
	object *obs;	    // 场景中所有可以奖励的
	object dob;	     // 打晕这个NPC的人
	object hob;	     // 协助者
	object aob;	     // 被协助者
	int qlevel;	     // 本次任务的等级
	int lvl;		// NPC的等级
	int scale;	      // NPC呼叫的帮手和逃跑的次数
	int n;		  // 可以奖励的人的数目
	int exp;		// 需要瓜分的经验
	int pot;		// 需要瓜分的潜能
	int weiwang;	    // 需要瓜分的威望
	int score;	      // 需要瓜分的阅历
	int extra_exp;	  // 打晕的人的额外经验
	int extra_pot;	  // 打晕的人的额外潜能
	string quester;	 // 需要完成这个任务的玩家ID
	object qob;	     // 需要完成这个任务的玩家对象
	string msg;	     // 描述信息
	mapping quest;	  // 任务

	// 找到杀了我(NPC)或是打晕我的人
	if (! objectp(dob = killer))
		dob = query_defeated_by();

	if (objectp(dob) && dob->query_temp("owner"))
		dob = dob->query_temp("owner");

	while (1)
	{
		// 记录：此任务已经终止
		if (stringp(quester = query_temp("quester")))
		{
			qob = UPDATE_D->global_find_player(quester);
			if (qob->query("quest/id") == query("id"))
				qob->set("quest/notice", "die");
			UPDATE_D->global_destruct_player(qob, 1);
		}

		if (dob && dob->query("quest/id") == query("id"))
			// 我自己打死的
			break;

		if (dob) aob = dob->query_temp("quest/assist");
		if (aob && aob->query("quest/id") == query("id"))
			// 我协助别人杀死的
			break;

		// 非任务所有者或是任务所有者协助的人杀死，则记录之。
		CHANNEL_D->do_channel(this_object(), "rumor",
				      sprintf("听说%s被人杀死了。", name()));
		/*log_files("kungfu/killed_die", sprintf("%s %s(%s) died at %s because %s.\n",
						      log_time(), name(), query("id"),
						      environment()->short(),
						      dob ? sprintf("%s(%s)", dob->name(1), dob->query("id")) : "none"));
*/
		break;
	}

	if (! aob) aob = dob;

	if (! aob)
	{
		// 没有找到 QUEST 的属主
		::die();
		return;
	}

	// 察看目前正在杀我的人，是否也有值得奖励的
	obs = all_inventory(environment());
	obs = filter_array(obs, (: filter_to_bonus :), aob);

	if ((n = sizeof(obs)) > 0)
	{
		// 查找打晕我的人：不是杀死我的人
		dob = query_defeated_by();

		// 奖励多少呢？总共奖励供所有的人分，最后每
		// 人加上一点随机量，其中打晕这个人的玩家获
		// 得额外的一些奖励。
		lvl = NPC_D->check_level(this_object());
		exp = 15 + random(10) + lvl;
		pot = 9 + random(5) + lvl;
		weiwang = 8 + random(6) + lvl / 2;
		score = 9 + random(6) + lvl / 2;

		// 根据这个任务的等级进行奖励调整
		switch (aob->query("quest/level"))
		{
		case 1:
			break;
		case 2:
			exp += exp / 2;
			pot += pot / 2;
			weiwang += weiwang / 2;
			score += score / 2;
			break;
		case 3:
			exp += exp;
			pot += pot;
			weiwang += weiwang;
			score += score;
			break;
		default:
			exp = exp / 2 + 1;
			pot = pot / 2 + 1;
			weiwang = weiwang / 2 + 1;
			score = score / 2 + 1;
			break;
		}

		// 如果NPC呼叫了帮手，则可以获得额外经验
		if ((scale = sizeof(query_temp("help_count") +
		     query_temp("escape_times") * 2)) > 0)
		{
			exp += exp * scale / 2;
			pot += pot * scale / 2;
		}

		// 所有人均分经验：为什么除以n + 2？这是因为
		// 打晕我的人分两份经验，所以是n + 1，再加上
		// 领任务的这个人算1，那么就是n + 2。
		exp = exp / (n + 2) + 1;
		pot = pot / (n + 2) + 1;
		weiwang = weiwang / (n + 2) + 1;
		score = score / (n + 2) + 1;

		// 计算打晕我的额外奖励
		if (objectp(dob) && member_array(dob, obs) != -1)
		{
			extra_exp = 1 + random(exp);
			extra_pot = 1 + random(pot);
			if (dob->query("combat_exp") < query("combat_exp") / 2)
			{
				// 出手的人武功比较低，获得的额外奖励多
				extra_exp *= 2;
				extra_pot *= 2;
			} else
			if (dob->query("combat_exp") > query("combat_exp") * 2)
			{
				// 出手的人武功太高，获得的额外奖励少
				extra_exp /= 2;
				extra_pot /= 2;
			}
		}

		// 进行奖励
		foreach (hob in obs)
		{
			// 调用延迟奖励，为什么这么调用？很简单，
			// 因为我希望玩家在看到NPC死了以后才能够
			// 看到奖励。
			QUEST_D->delay_bonus(hob, 
				([ "exp" : exp + random(4) +
					   ((hob == dob) ? extra_exp : 0),
				   "pot" : pot + random(3) +
					   ((hob == dob) ? extra_pot : 0),
				   "weiwang" : weiwang + random(3),
				   "score"   : score + random(3),
				   "prompt"  : "击毙" + name() + "之后" ]));
		}
	}

	// 无需要完成这个任务的玩家？或者无法生成远程任务，
	// 那么就正常死亡
	// 如果不是自己杀死的，不允许发送远程任务
	if (! qob ||
	    quester != dob->query("id") ||
	    ! mapp(quest = QUEST_D->prepare_quest(qob)))
	{
		::die();
		return;
	}

	// 人物正常完成
	qob->set("quest/finished", 1);

	// 使用书信分配任务
	QUEST_D->remote_assign_quest(qob, quest);

	// 正常死亡
	::die();
}

int accept_fight(object ob)
{
	command("say 好！咱们就比划比划！");
	kill_ob(ob);
	return 1;
}

int accept_hit(object ob)
{
	command("say 你死去吧！");
	kill_ob(ob);
	return 1;
}

int accept_kill(object ob)
{
	command("say 哼！找死！");
	return 1;
}

void random_move()
{
	if (query_temp("is_helper"))
	{
		// is a helper
		if (! environment())
		{
			// not in environment? unavaliable npc.
			destruct(this_object());
			return;
		}

		if (! query_temp("help_who"))
		{
			// owner is killed. destruct this helper
			if (! living(this_object()))
				message_vision("$N缓缓的醒了过来。\n",
					       this_object());
			
			message_vision("$N看看四周，急匆匆的逃走了。\n",
				       this_object());
			destruct(this_object());
			return;
		}

		// move with owner
		return;
	}

	if (time() > query_temp("dest_time"))
	{
		message_vision("$N急急忙忙的走了。\n", this_object());
		CHANNEL_D->do_channel(this_object(), "rumor",
				      sprintf("听说%s隐居到了深山老泽，从此不再出没在世间。", name()));
				      /*
		log_files("kungfu/killed_die", sprintf("%s %s(%s) vanished because timeout(%d:%d).\n",
						      log_time(), (string)name(), (string)query("id"),
						      time() - query_temp("born_time"),
						      query_temp("dest_time") - query_temp("born_time")));
						      */
		destruct(this_object());
		return;
	}
	NPC_D->random_move(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
