// user.c

#include <origin.h>
#include <user.h>
#include <ansi.h>
#include <command.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;

// 死亡保护
private int die_protect(object ob);
private void cancle_die_protect(object ob);

// 分站使用
static int admin_flag = 0;	      // 是否是特殊的管理员？

// 数据是否完整？
static int user_cracked = 0;	    // RESTORE 时检查数据并设置该标志

static int net_dead;		    // 标志：是否断开了连接
static int last_age_set = 0;	    // 上一次更新AGE的时间
static int user_say = 0;		// 一定时间以内玩家做的say-action
static int user_command = 0;	    // 一定时间以内玩家发送的命令
static int attach_flag = 0;	     // 是否正在和系统联络
int	at_time = 0;		 // 在什么时间计算的
int	ban_to = 0;		  // 在什么时间解禁玩家
string     ban_say_msg = "";	    // 禁止说话的消息

static string my_defeater_id;	   // 上一次打晕你的人ID
static string my_killer_id;	     // 上一次杀你的人的ID
static int    craze = 0;		// 愤怒

#define DEFAULT_PRISON	  "/d/register/prison"

// globals variables
string  prison = 0;
int     time_to_leave = 0;

int	is_stay_in_room()	{ return 1; }
int     is_player()		{ return clonep(); }
string  query_prison()	  { return prison; }
int     query_time_to_leave()   { return time_to_leave; }
int     is_in_prison()	  { return stringp(prison); }
int     is_net_dead()	   { return net_dead || ! interactive(this_object()); }

varargs string calc_sec_id(int raw);

#define MAX_COMMAND_ONE_SECTION	 30
#define MAX_SAY_ONE_SECTION	     4
#define BAN_SAY_PERIOD		  60

int query_current_neili_limit();
int query_neili_limit();
int query_current_jingli_limit();
int query_jingli_limit();
int query_potential_limit();
int query_experience_limit();

int is_user() { return 1; }

// 判断是否具有管理权限：如果是版本发布站点或是通过 PASSWD
// 命令设置过，则具有管理权限。具有该权限的巫师可是使用诸如
// clone、call、log、smash、copyskill等命令。
int is_admin()  { return admin_flag == 1222; }
int set_admin() { if (previous_object() == find_object("/cmds/usr/passwd")) admin_flag = 1222; }

void create()
{
	::create();
	set_name("使用者物件", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "终端机型态设定为 " + term_type + "。\n", this_object());
}

void reset()
{
	int lv;

	if ((int)query("potential") - (int)query("learned_points") < 100)
		add("potential", 1);

	if ((int)query("thief") > 0)
		add("thief", -1);

	if ((int)query("total_hatred") > 0)
		add("total_hatred", -1);

	if ((lv = query_skill("xiantian-gong", 1)) >= 60 ||
	    (lv = query_skill("quanzhen-xinfa", 1)) >= 60)
	{
		if (can_improve_skill("force"))
			improve_skill("force", lv * 20);

		if (query_skill("quanzhen-xinfa", 1) >= 60 &&
		    can_improve_skill("quanzhen-xinfa"))
			improve_skill("quanzhen-xinfa", lv * 10);

		if (query_skill("xiantian-gong", 1) >= 60 &&
		    can_improve_skill("xiantian-gong") &&
		    SKILL_D("xiantian-gong")->valid_learn(this_object()))
			improve_skill("xiantian-gong", lv * 10);
	}
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if (! id) id = getuid();
	if (! stringp(id)) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

// override set function
mixed set(string idx, mixed para)
{
	if (idx == "name" && clonep(this_object()) &&
	    geteuid(this_object()))
	{
		NAME_D->change_name(this_object(), para, 1);
		return para;
	} else
		return ::set(idx, para);
}

int save()
{
	int res;

	if (user_cracked)
		// 数据不完整，不能保存
		return 1;

	if (query_temp("user_setup"))
	{
		save_autoload();
		set("sec_id", calc_sec_id());   // save sec_id
		res = ::save();
		clean_up_autoload();		// To save memory
	} else
	{
		set("sec_id", calc_sec_id());   // save sec_id
		res = ::save();
	}

#if INSTALL_EXAMINE
	EXAMINE_D->examine_player(me);
#endif
	return res;
}

int restore()
{
	int res;
	string sec_id;

	res = ::restore();
	if (res)
	{
		// 数据完整
		user_cracked = 0;

		set("id", getuid(this_object()));
	}

	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	int lastset;
	int age,month;
	int delta;

	if( !(lastset=query("zjvip/last_vip_set"))) lastset=time();
	if(query("zjvip/times")>0)
	{
		add("zjvip/times", lastset - time());
		if(query("zjvip/times")<=0)
		{
			set("zjvip/times", 0);
			tell_object(this_object(),RED"你的VIP会员时间已到期！"NOR"\n");
		}
	}
	else
	{
		set("zjvip/times", 0);
	}
	set("zjvip/last_vip_set",time());

	if (! last_age_set)
	{
		last_age_set = time();
		add("mud_age", 0);
	}

	if ((delta = (time() - last_age_set)) > 100)
		// time too long
		delta = 100;

	if (! environment() || ! environment()->is_chat_room() || ! query("env/halt_age"))		
	{
		// Update age
		add("mud_age", delta);
		if (time_to_leave)
			time_to_leave -= delta;
	}

	last_age_set = time();
	age = query("age_modify") + query("mud_age") / 259200;
	age += 14;
	month = (query("mud_age")%259200)/21600;
	set("month",month);
        if (query("age") != age) {
		set("age", age);
		set("kar", 10+random(21));
		tell_object(this_object(), "时间过得真快，不知不觉你已经" + chinese_number(age) + "岁了，今年的运气不知道怎么样。\n");
	}
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	last_age_set = 0;
	update_age();

	::setup();

	// set the enable flag to enable save
	set_temp("user_setup", 1);

	restore_autoload();

	if (query("doing"))
		CLOSE_D->continue_doing(this_object());
}

void user_dump(int type)
{

	
	if (environment()&&environment()->query("close_room")) return;
    if (environment()&&environment()->query("gg_bgs")) return;	
	switch(type)
	{
	case DUMP_NET_DEAD:
		if (environment())
		{
			tell_room(environment(), query("name") + "断线超过 " + NET_DEAD_TIMEOUT / 60 + " 分钟，自动退出这个世界。\n");
		}
		catch(command("halt"));
		catch(command("quit"));
		if (this_object())
		{
			QUIT_CMD->force_quit(this_object());
		}
		break;

	case DUMP_IDLE:
		if (query_temp("learned_idle_force"))
		{
			message_vision("$N狂笑三声，道：我终于明白了！\n",
				       this_object());
			tell_object(this_object(), "你经过长时间的发"
				    "呆，终于对发呆神功的理解又深了一层！\n");
			improve_skill("idle-force", 360000);
			delete_temp("learned_idle_force");
		} else
			tell_object(this_object(), "对不起，您已经发呆超过 " +
				    IDLE_TIMEOUT / 60 + " 分钟了，请下次再来。\n");
		if (environment())
		{
			tell_room(environment(), "一阵风吹来，将发呆中的" + query("name") +
				   "化为一堆飞灰，消失了。\n", ({this_object()}));
		}
		command("quit");
		if (this_object() && ! query("doing"))
		{
			// command quit failed.
			QUIT_CMD->force_quit(this_object());
		}
		break;
	default:
		return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
private void net_dead()
{
	object link_ob;

	this_object()->remove_interactive();

		

		if (! query("doing")&&!(environment(this_object())&&environment(this_object())->query("close_room")))
		if (! query("doing")&&!(environment(this_object())&&environment(this_object())->query("gg_bgs")))
	
		set_heart_beat(0);

	if (objectp(link_ob = query_temp("link_ob")))
	{
		if (link_ob->query_temp("ip_number"))
		{
			link_ob->set("last_on", time());
			link_ob->set("last_from",link_ob->query_temp("ip_number"));
			link_ob->save();
		}
		destruct(link_ob);
	}

	net_dead = 1;
	if (userp(this_object()) && ! query("doing")&&!(environment(this_object())&&(environment(this_object())->query("close_room")||environment(this_object())->query("gg_bgs"))))
	{
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
		tell_room(environment(), query("name") + "断线了。\n", this_object());
		CHANNEL_D->do_channel(this_object(), "sys", "断线了。");
		remove_all_enemy(1);
	} else
	{
		if (environment())
			message("vision", name() + "离线了。\n",
				environment(), ({ this_object() }));
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	net_dead = 0;
	remove_call_out("user_dump");
	if(!this_object()->query("wiz_start"))
	tell_object(this_object(), "重新连接成功。\n");
}

// skill variable & function
#define MAX_NEILI_IMPROVE       query("con")
#define MAX_JINGLI_IMPROVE      query("con")

int query_neili_limit()
{
	string *skill_names;
	mapping skills;
	int neili_limit;
	int base_lvl, lvl;
	int tmp;
	int i;
	string fam;

	skills = this_object()->query_skills();
	if (! mapp(skills))
		return 0;

	skill_names = keys(skills);

	base_lvl = ((int) skills["force"]) / 2; 
	neili_limit = base_lvl * 10;
	for (i = 0; i < sizeof(skill_names); i++)
	{
		if (file_size(SKILL_D(skill_names[i]) + ".c") == -1)
		{
			// No such skill
			continue;
		}

		if (! SKILL_D(skill_names[i])->valid_enable("force"))
			continue;

		lvl = (int) skills[skill_names[i]];
		tmp = (base_lvl + lvl) * 10;
		tmp += (int) SKILL_D(skill_names[i])->query_neili_improve(this_object());
		if (tmp > neili_limit) neili_limit = tmp;
	}

	neili_limit += neili_limit * query("improve/neili") / 100;
	if (query("breakup"))
	neili_limit += neili_limit * 3 / 10;
	if (query("special_skill/mystery"))
	neili_limit += query("con") * 15;
	fam = query("family/family_name");
	if (query("class") == "bonze" && (fam == "雪山寺" || fam == "少林派" || fam == "峨嵋派" || fam == "血刀门"))
	neili_limit += 800;
	//境界系统加成
	neili_limit+=query("jinjie/neili");
	
	return neili_limit;
}

int query_gain_qi()
{
	int gain_qi,x;
	string xinfa;

	gain_qi = query("gain/max_qi");
	if(query("family/family_name")=="武当派"||query("family/family_name")=="全真教")
		gain_qi += gain_qi/8;

	if(xinfa = query_skill_mapped("force"))
	{
		if ((x = query_skill(xinfa,1)) > 180)
		{
			gain_qi += gain_qi*((x-180)/5) / 100;
		}
	}

		if(query("family/family_name")=="峨嵋派")
		{
	  		if(query_skill_mapped("force") == "linji-zhuang")
	  			gain_qi+=query_skill("linji-zhuang",1)*20; 
		}


	if (query("special_skill/ghost"))
		gain_qi = gain_qi*7/10;
		gain_qi += query_temp("apply/max_qi");//增加临时最大气血
	return gain_qi;
}
int query_gain_damage()
{
	int gain_damage;
	gain_damage= query("gain/damage")+query_temp("gain/damage");
	return gain_damage;
}
int query_gain_break()
{
	int gain_break;
	gain_break= query("gain/break")+query_temp("gain/break");
	return gain_break;
}

int query_gain_armor()
{
	int gain_armor;
	gain_armor= query("gain/armor")+query_temp("gain/armor");
	return gain_armor;
}


int query_current_neili_limit()
{
	int neili;
	string force;
	string fam;

	force = query_skill_mapped("force");
	neili = (int)query_skill("force", 1) / 2 * 10;
	if (stringp(force) && force != "")
	{
		neili += (int)query_skill(force, 1) * 10;
		neili += SKILL_D(force)->query_neili_improve(this_object());
	}    

	neili += neili * query("improve/neili") / 100;
	if (query("breakup"))
		neili += neili * 3 / 10;

	if (query("special_skill/mystery"))
		neili += query("con") * 15;

	fam = query("family/family_name");
	if (query("class") == "bonze" &&
	    (fam == "雪山寺" || fam == "少林派" || fam == "峨嵋派" || fam == "血刀门"))
		neili += 800;

	return neili;
}

int query_jingli_limit()
{
	int limit;

	limit = ((int)query("magic_points") / 30) + query("int") * 20;
	limit += limit * query("improve/jingli") / 100;
	if (query("animaout"))
		limit += limit * 3 / 10;
	//境界系统加成		
	limit+=query("jinjie/jingli");
	
	return limit;
}

int query_current_jingli_limit()
{
	return query_jingli_limit();
}
//悟性提高可以增加潜能极限
int query_potential_limit()
{
	int p;

	if (ultrap(this_object()))//宗师
		p = 2000000;
	else
		p = 1000000;
	return (int)query("learned_points") + p;
}
//实战体会极限-阅历提高可以增加实战体会极限
int query_experience_limit()
{
	int p;

	if (ultrap(this_object()))
	p = 2000000;
	else
	p = 1000000;		
	return (int)query("learned_experience") + p;
}

int improve_potential(int n)
{
	int max;

	max = query_potential_limit() - query("potential");
	if (max <= 0){
		tell_object(this_object(),"潜能已达上限，暂时无法继续提升！\n");
		return 0;
	}
	if (n > max) n = max;
	add("potential", n);
	return n;
}

int improve_experience(int n)
{
	int max;

	max = query_potential_limit() - query("experience");
	if (max <= 0) return 0;
	if (n > max) n = max;
	add("experience", n);
	return n;
}

int can_improve_neili()
{
	return query("improve/neili") < MAX_NEILI_IMPROVE;
}

int can_improve_jingli()
{
	return query("improve/jingli") < MAX_NEILI_IMPROVE;
}

int improve_neili(int n)
{
	int delta;

	if ((delta = query_neili_limit() - query("max_neili")) <= 0)
		return 0;

	if (n > delta) n = delta;
	add("max_neili", n);
	 setup();
	return n;
}

int improve_jingli(int n)
{
	int delta;

	if ((delta = query_jingli_limit() - query("max_jingli")) <= 0)
		return 0;

	if (n > delta) n = delta;
	add("max_jingli", n);
	 setup();
	return n;
}

int accept_fight(object ob)
{
	if (query_temp("pending/fight") == ob)
		return 1;

	tell_object(this_object(), YEL "如果你愿意和对方进行比试，请你也对" +
		    ob->name() + "("+ (string)ob->query("id")+")"+
		    "下一次 fight 指令。"NOR"\n");

	tell_object(ob, YEL "由于对方是由玩家控制的人物，你必须等对方同意才" +
	      "能进行比试。"NOR"\n");

	return 0;
}

int accept_hit(object ob)
{
	if (! die_protect(ob))
		return 0;

	message_vision("$N大喝道：" + ob->name() + "，你要干什么？\n",
		       this_object(), ob);
	return 1;
}

int accept_kill(object ob)
{
	if (is_killing(ob->query("id")))
		return 1;

	if (! die_protect(ob))
		return -1;

	tell_object(this_object(), HIR "如果你要和" + ob->name() +
		"性命相搏，请你也对这个人(" + (string)ob->query("id") +
		")下一次 kill 指令。"NOR"\n");
	return 1;
}

int accept_ansuan(object who)
{
	if (! die_protect(who))
		return 0;

	command(random(2) ? "say 嗯！怎么..." : "say 啊！不好！");
	return 1;
}

int accept_touxi(object who)
{
	if (! die_protect(who))
		return -1;

	switch (random(2))
	{
	case 0:
		message_vision("$N大吃一惊，叫道：“好你个" +
			       RANK_D->query_rude(who) + "！真不要脸！”\n",
			       this_object(), who);
		break;

	default:
		message_vision("$N仓皇之间，不及说话，只得接下$n"
			       "这一招。\n", this_object(), who);
		break;
	}

	return 1;
}

int die_protect(object ob)
{
	object me = this_object();

	// 只有玩家之间才有死亡保护
	if (! userp(me) || ! userp(ob))
		return 1;

	// 在屠人场里不考虑死亡保护
	if (me->query_temp("in_pkd"))
		return 1;

	// 去除攻击者的死亡保护信息
	if (userp(me))
		cancle_die_protect(ob);

	// 被攻击者处于保护时期，本攻击失败
	if (me->query("die_protect/last_dead") + me->query("die_protect/duration") > time()+7200)
	{
		message_vision("$N处于被保护时期，$n不能进行攻击。\n",me, ob);
		return 0;
	}

	return 1;
}

void cancle_die_protect(object ob)
{
	ob->delete("die_protect");
}

int auto_cmd() 
{
	string *sss,str;
	object me;
	int i,max;
	me = this_object();

	if(!me->query("env/sign1")||!stringp(str = me->query("env/sign5"))) return 1;
	sss = explode(str,";");
	max = sizeof(sss);
	if(max>5) max = 5;
	for(i=0;i<max;i++)
	{
		me->force_me(sss[i]);
		
 //   tell_object(me,ZJFORCECMD(sss[i]));
	}
	return 1;
}

int auto_zhandou()
{
	string jb, *list, *mls;
	int i,j;
	object me;

	me = this_object();

	jb = me->query("zdjb/s"+me->query("zdjb/def"));
	if(!stringp(jb)) return 0;
	
	list = explode(jb,";");
	
	for(i=0; i<sizeof(list); i++){
		
		if(! me->is_fighting() || me->is_busy()){
			break;			
		}
		
		mls = explode(list[i],":");
		if(sizeof(mls) == 2){
			for(j=0; j < to_int(mls[1]); j++){
				if(! me->is_fighting() || me->is_busy()){
					break;			
				}			
				me->force_me(mls[0]);			
			}			
		}else{
			me->force_me(mls[0]);			
		}

	}

	me->set_temp("zdjb",0);
	return 1;
}

int reject_command()
{
	int t;

	if (wizardp(this_object()))
		return 0;

	t = time() & 0xFFFFFFFE;
	if (at_time != t)
	{
		at_time = t;
		user_command = 1;
		user_say = 0;
	} else
		user_command++;

	if (user_command > MAX_COMMAND_ONE_SECTION)
	{
		user_command = 0;
		if (! query("born"))
			// not born yet
			return 0;
		return 1;
	}

	return 0;
}

void ban_say_until(int ban_period, string msg)
{
	int t;

	t = time();
	if (ban_to > t)
		ban_to += ban_period;
	else
		ban_to = t + ban_period;
	ban_say_msg = msg;
}

int ban_say(int raw)
{
	int t;

	if (wizardp(this_object()))
		return 0;

	if (is_in_prison())
	{
		notify_fail("你省省吧，好好做你的牢，少折腾。\n");
		return 1;
	}

	t = time() & 0xFFFFFFFE;
	if (ban_to > t)
	{
		notify_fail(ban_say_msg + "，请于" +
			    appromix_time(ban_to - t) + "以后再尝试。\n");
		return 1;
	}

	if (! raw)
		return 0;

	if (at_time != t)
	{
		at_time = t;
		user_say = 1;
		user_command  = 0;
	} else
		user_say++;

	if (user_say > MAX_SAY_ONE_SECTION)
	{
		ban_say_until(BAN_SAY_PERIOD, "系统禁止你送出信息");
		notify_fail(HIR "由于你发布的信息太多，因此系统暂时"
			    "禁止你发出信息。"NOR"\n");
		return 1;
	}

	return 0;
}

void permit_say(int n)
{
	if (ban_to <= time())
		return;

	if (! n)
		ban_to = 0;
	else
		ban_to -= n;

	if (ban_to <= time())
		tell_object(this_object(), "你可以继续发布信息了！\n");
}

// thow the person into prison
void get_into_prison(object ob, string p, int time)
{
	object me;

	me = this_object();
	if (! p) p = prison;
	if (! p) p = DEFAULT_PRISON;

	if (prison && base_name(environment()) == p)
	{
		time_to_leave += time * 60;
		if (ob && time)
			CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
				"听说" + query("name") + "的刑期被" +
				ob->query("name") + "加长了" +
				appromix_time(time * 60) + "。");
		return;
	}

	if (prison && prison == p && base_name(environment()) != prison)
	{
		p->catch_back(me);
		me->set("startroom", prison);
		me->move(prison);
		message_vision("“啪”的一声，$N狠狠的摔倒了地上。\n", me);
		if (living(me))
			me->enable_player();

		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "越狱潜逃，结果被抓"
			"回去了。");

		save();
		return;
	}

	p->catch_ob(me);

	if (ob)
	{
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "被" + ob->query("name") +
			"送进了" + p->short() + HIM "，禁闭" +
			appromix_time(time * 60) + "。");
	}

	me->set("startroom", prison);
	me->move(p);
	prison = p;
	time_to_leave += time * 60;
	save();

	message_vision("“啪”的一声，$N重重的摔倒了地上。\n", me);
	me->set("jing", 1);
	me->set("eff_jing", 1);
	me->set("qi", 1);
	me->set("eff_qi", 1);
	me->set("jingli", 0);
	me->set("neili", 0);
	me->receive_damage("jing", 0);
	if (living(me))
		me->enable_player();
}

// out of prison
void leave_prison(object ob, int time)
{
	object me;

	me = this_object();
	if (time)
	{
		time_to_leave -= time * 60;
		if (time_to_leave > 0)
		{
			if(ob)
				CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor","听说" + query("name") + "的刑期被" +
					ob->query("name") + "缩短了" + appromix_time(time * 60) + "。");
			else
				CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor","听说" + query("name") + "的刑期被缩短了" + appromix_time(time * 60) + "。");
			return;
		}
	}

	time_to_leave = 0;

	if (! prison->free_ob(me))
		return;

	prison = 0;

	if (living(me))
		me->enable_player();
	else
		me->revive();
	save();

	if (ob)
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "被" + ob->name() +
			"提前释放了。");
	else
		CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
			"听说" + query("name") + "已经刑满释放了。");
}

varargs void die(object killer)
{
	if (prison)
	{
		set_temp("die_reason", "惨死在监狱中");
		clear_condition(0);
		receive_damage("qi", 0);
		if (living(this_object()))
			enable_player();
	}
	
	::die(killer);
	save();
}

void update_in_prison()
{
	object me;

	me = this_object();
	me->set("qi", 0);
	me->set("jing", 0);
	me->set("neili", 0);

	if (! living(me))
		return;

	if (time_to_leave > 0)
	{
		if (environment() && base_name(environment()) != prison)
		{
			// escape from prison?
			get_into_prison(0, 0, 0);
		}
		return;
	}

	leave_prison(0, 0);
}

int is_attach_system()
{
	return attach_flag;
}

// start attaching
int attach_system()
{
	attach_flag = 1;
}

// stop, deatched
int detach_system()
{
	attach_flag = 0;
}

string command_verb()
{
	return query_verb();
}

#define CRAZE_LIMIT_1   10000    // for 光明磊落
#define CRAZE_LIMIT_2   7000    // for 心狠手辣
#define CRAZE_LIMIT_3   5000		// for 狡黠
#define CRAZE_LIMIT_4   4000		// for 阴险

// 愤怒气息
int query_craze() { return craze; }

// 最大的愤怒气息
int query_max_craze()
{
	switch (query("character"))
	{
	case "光明磊落" :
		return CRAZE_LIMIT_1;

	case "心狠手辣" :
		return CRAZE_LIMIT_2;
		
	case "狡黠多变" :
		return CRAZE_LIMIT_3;
		
	case "阴险奸诈" :
		return CRAZE_LIMIT_4;
				
	default:
		return 0;
	}
}

// 现在是否处于最愤怒的状态
int is_most_craze()
{
	return (craze > 0) && (craze >= query_max_craze());
}

// 因为被打倒而震怒
void craze_of_defeated(string defeater_id)
{
	my_defeater_id = defeater_id;
}

// 因为被击毙而震怒
void craze_of_die(string killer_id)
{
	my_killer_id = killer_id;
	craze = query_max_craze();
}

// 愤怒的攻击对手后调用这个函数清除对象
void craze_defeated(string enemy_id)
{
	if (enemy_id == my_defeater_id)
		my_defeater_id = 0;

	if (enemy_id == my_killer_id)
		my_killer_id = 0;
}

// 是否憎恨某人
int is_hating(string enemy_id)
{
	if (enemy_id == my_defeater_id ||
	    enemy_id == my_killer_id)
		return 1;

	return 0;
}

// 提升愤怒，返回提升的有效值
int improve_craze(int amount)
{
	int limit;

	if (amount < 0)
		error("error: improve_craze amount to be less than 0\n");

	limit = query_max_craze();
	craze += amount;
	if (craze > limit)
	{
		amount += limit - craze;
		craze = limit;
	}
	return amount;
}

// 消耗愤怒，返回消耗的有效值
int cost_craze(int n)
{
	if (n < 0)
		error("error: improve_craze amount to be less than 0\n");

	if (n > craze)
	{
		n = craze;
		craze = 0;
	} else
		craze -= n;
	return n;
}

// 编辑文件
void edit_file(string file)
{
	ed(file);
}

int is_vip()
{
	return query("zjvip/times")>0;
}

// 是否是结拜兄弟？
int is_brother(mixed ob)
{
	string id;

	if (stringp(ob))
		id = ob;
	else
	if (objectp(ob))
		id = ob->query("id");
	else
		return 0;

	// 是否是普通结拜兄弟
	if (query("brothers/" + id))
		return 1;

	// 是否是结盟的兄弟
	return 0;
}

// 计算完整性数据和
string calc_sec_id(int raw)
{
	mapping my;
	string *list;
	string key;
	int sum;
	string str;
	int i;

	sum = 0;

	// 累计所有的数据
	if (mapp(my = query_entire_dbase()))
	{
		foreach (key in keys(my) - ({ "sec_id" }))
		{
			sum += sizeof(key);
			if (intp(my[key]))
				sum += my[key];
			else
				sum += sizeof(my[key]);
		}
	}
	
	// 累计所有的武功技能
	
	if (mapp(my = query_skills()))
	{
		foreach (key in keys(my))
		{
			sum += sizeof(key);
			if (intp(my[key]))
				sum += my[key];
			else
				sum += sizeof(my[key]);
		}
	}
	// 累计所有携带的物品
	if (arrayp(list = query_autoload_info()))
	{
		foreach (key in list)
		{
			sum += sizeof(key);
			if (stringp(key))
				for (i = 0; i < strlen(key); i++) sum += key[i];
		}
	}

	// 转化成字符串
	str = sprintf("%d", sum);
	str[0] = (sum % 26) + 'a';

	if (! raw) str = crypt(str, 0);
	return str;
}

string query_info()
{
	string msg;
	int dexp, dpot, dmar, dage, dquest, dt;

	if (wiz_level(this_object()) > 0)
		return 0;

	msg = "";
	if (query("chblk_on"))
	{
		if (stringp(query("chblk_by")))
			msg += "频道已经被 " + query("chblk_by") + " 关闭。\n";
		else
			msg += "频道被关闭中。\n";
	}

	dexp = query("combat_exp") - query("last_examine/combat_exp");
	dpot = query("potential") - query("last_examine/potential");
	dmar = query("experience") - query("last_examine/experience");
	dage = query("mud_age") - query("last_examine/mud_age");
	dquest = query("all_quest") - query("last_examine/all_quest");
	dt = time() - query("last_examine/time");
	if (dquest < 0) dquest += 1000;

	if (dt > 60)
	{
		msg += sprintf("自上次检查 %s 以来：\n"
			       "连线时间增加了 %s。\n"
			       "师门任务完成了 %d 个。\n"
			       "平均每分钟获得经验速度：%d\n"
			       "平均每分钟获得潜能速度：%d\n"
			       "平均每分钟获得体会速度：%d\n",
			       appromix_time(dt),
			       appromix_time(dage),
			       dquest,
			       dexp * 60 / dt, dpot * 60 / dt, dmar * 60 /dt);
	}

	return msg;
}



/*
int query_gain_damage()
{
	string myclass;
	int gain_damage,xiuyang;
	object weapon;
	int lx;
	weapon = query_temp("weapon");
	myclass=query("family/family_name");
	
	xiuyang=query("xiuyang");
	
	gain_damage= (query_skill("tiangang-bati",1)/6)+(query_skill("wanjian-guizong",1)/6)+(query_skill("yinyang-jiuzhuan",1)/6)+(query_skill("rulai-shenzhang",1)/6)+(query_skill("yuan-blade",1)/6)+(query_skill("zuixian-wangyue",1)/6)+(query_skill("lieyan-jue",1)/8)+(query_skill("ruijin-jue",1)/8)+(query_skill("chunyang-jue",1)/8);

	if(myclass=="少林派")
		{
		 if( query_skill_mapped("sword") == "damo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
		 gain_damage+=query_skill("hunyuan-yiqi",1)/10+xiuyang/5+query("con");
		 if( query_skill_mapped("whip") == "riyue-bian" &&objectp(weapon)&&(string)weapon->query("skill_type") == "whip"	)
		 gain_damage+=query_skill("hunyuan-yiqi",1)/10+query("con");		
		}	
	if(myclass=="武当派")
		{
		 if( query_skill_mapped("sword") == "taiji-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword" )
	 	 gain_damage+=query_skill("taiji-shengong",1)/10+xiuyang/10+query("con");		 
		}		
	
	 if(myclass=="峨嵋派")
		{
		 if( query_skill_mapped("sword") == "huifeng-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword" )
		 		gain_damage+=query_skill("linji-zhuang",1)/10+xiuyang/10+query("con");	 
		}		
	  if(myclass=="华山剑宗") {
	    if( query_skill_mapped("force") == "huashan-xinfa")
		 	gain_damage+=query_skill("sword-cognize",1)/5+query("int");	
	   }
	   if(myclass=="华山派") {
	    if( query_skill_mapped("force") == "zixia-shengong")
		 	gain_damage+=query_skill("sword-cognize",1)/5+query("int");	
		 	if(query_skill_mapped("sword") == "huashan-sword"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")	 
		 	gain_damage+=query_skill("zixia-shengong",1)/10+query("int")+xiuyang/10;	
	   }
	   if(myclass=="丐帮") {
	    if( query_skill_mapped("force") == "huntian-qigong")
		 	gain_damage+=xiuyang/5+query("con");	
		 	if(query_skill_mapped("staff") == "dagou-bang"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "staff")	 
		 	gain_damage+=query_skill("huntian-qigong",1)/10+query("int")+xiuyang/10;	
	   }
	    if(myclass=="桃花岛")
		{
			 if( query_skill_mapped("force") == "bibo-shengong")
			 	gain_damage+=xiuyang/5+query("int");
		 }     	
	   
	    if(myclass=="星宿派")
		{
			if(query_skill_mapped("staff") == "tianshan-zhang"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "staff")	 
		 	gain_damage+=query_skill("freezing-force",1)/10+query("str")+xiuyang/10;	
		 }   
		 if(myclass=="逍遥派")
		{
			if(query_skill_mapped("force") == "beiming-shengong")	 
		 	gain_damage+=query("int")+xiuyang/5;	
			if(query_skill_mapped("blade") == "ruyi-dao"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "blade")	 
		 	gain_damage+=query_skill("beiming-shengong",1)/10+query("int")+xiuyang/10;	
		 }  
		 
		  if(myclass=="古墓派")
		{
			if(query_skill_mapped("force") == "surge-force")	 
		 	gain_damage+=query("con")+xiuyang/5;	
			if(query_skill_mapped("sword") == "xuantie-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")	 
		 	gain_damage+=query_skill("surge-force",1)/10+query("con")+xiuyang/10;	
		 } 
		 
		  if(myclass=="全真教")
		{
			if(query_skill_mapped("sword") == "quanzhen-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")	 
		 	gain_damage+=query_skill("xuantian-gong",1)/10+query("con")+xiuyang/10;	
		 } 
		 
		  if(myclass=="神龙教")
		{
		 if( query_skill_mapped("force") == "shenlong-xinfa")
			 	gain_damage+=query("dex")+xiuyang/5;		
		 if( query_skill_mapped("hand") == "shenlong-bashi"&&query_skill_prepared("hand") == "shenlong-bashi" )
	   	  gain_damage+=query("dex")+xiuyang/10+query_skill("shenlong-xinfa",1)/10;  		
		 }     	    
		  if(myclass=="雪山寺")
		{
		   if( query_skill_mapped("force") == "longxiang-gong"
			&& query_skill_mapped("dodge") == "shenkong-xing"
			&& (query_skill_mapped("parry") == "riyue-lun")
			&& (query_skill_mapped("hammer") == "riyue-lun"&&objectp(weapon)&&(string)weapon->query("skill_type") == "hammer")	)
		    lx=query_skill("longxiang-gong",1)/2;
		    if(lx>650) lx=650;
		    gain_damage+=xiuyang/10+lx;  	
		 }    
		   if(myclass=="血刀门")
		{
			if(query_skill_mapped("blade") == "xue-dao"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "blade")	 
		 	gain_damage+=query_skill("xuehai-mogong",1)/10+query("str")+xiuyang/10;	
		 }
		 if(myclass=="灵鹫宫")
		{
		 if( query_skill_mapped("force") == "bahuang-gong")
			 	gain_damage+=query("dex")+xiuyang/5;
		 }
		  if(myclass=="欧阳世家")
		{
		 if( query_skill_mapped("force") == "hamagong")
			 gain_damage+=query("str")+xiuyang/5;  
			if(query_skill_mapped("staff") == "lingshe-zhangfa"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "staff")	 
		 	gain_damage+=query_skill("hamagong",1)/10+query("str")+xiuyang/10;	  
		 }       	
		  if(myclass=="关外胡家")
		{
		 if( query_skill_mapped("force") == "lengyue-shengong")
				gain_damage+=(query("str")+query("int"))/2+xiuyang/5;
			if(query_skill_mapped("blade") == "daojian-guizhen"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "blade")	 
		 	gain_damage+=query_skill("lengyue-shengong",1)/10+(query("str")+query("int"))/2+xiuyang/10;	  
		 }   
		 if(myclass=="慕容世家")
		{
		 if( query_skill_mapped("force") == "zihui-xinfa")
			 	gain_damage+=query("con")+xiuyang/5;
			if(query_skill_mapped("sword") == "murong-sword"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")	 
		 	gain_damage+=query_skill("zihui-xinfa",1)/5+query("con")+xiuyang/10;	   
		 }   
		   if(myclass=="段氏皇族")
		{
		 if( query_skill_mapped("force") == "kurong-changong")
			 gain_damage+=query("int")+xiuyang/5;
		  if( query_skill_mapped("finger") == "six-finger"&&query_skill_prepared("finger") == "six-finger" )
	   	    gain_damage+=query_skill("kurong-changong",1)/10+xiuyang/10+query("int");  	 
		 }      
		if(myclass=="明教")
		{
		 if(query_skill_mapped("force") == "jiuyang-shengong")
		 {
		 	if( query_skill_mapped("claw") == "sougu-yingzhua"
		 	&&query_skill_prepared("claw") == "sougu-yingzhua" 
		 	) 	
		 	  	gain_damage+=query_skill("jiuyang-shengong",1)/10+xiuyang/10+query("int");
		 }	
		 if(query_skill_mapped("force") == "shenghuo-shengong")
		 {
		 	if( query_skill_mapped("force") == "shenghuo-shengong")
			 gain_damage+=query("int")+xiuyang/5;
		 	if(query_skill_mapped("sword") == "shenghuo-ling"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")
		 	    gain_damage+=query_skill("shenghuo-shengong",1)/5+xiuyang/10+query("int");  	
		 } 
		}  
		 if(myclass=="日月神教")
		{
		 if(query_skill_mapped("force") == "kuihua-shengong")
		 {
		 	gain_damage+=xiuyang/5+query("dex");		 
		 }	
		 if(query_skill_mapped("force") == "xixing-dafa")
		 {
		 	gain_damage+=xiuyang/5+query("con");
		 	if(query_skill_mapped("sword") == "tianmo-jian"
		 	&&objectp(weapon)
		 	&&((string)weapon->query("skill_type") == "sword"||(string)weapon->query("skill_type") == "pin"))
		 	 gain_damage+=query_skill("xixing-dafa",1)/10+xiuyang/10+query("con");  	
		 }
		 }  
		 if(myclass=="昆仑派")
		{
			if( query_skill_mapped("force") == "liangyi-shengong")
			 gain_damage+=query("int")+xiuyang/5;
		  if(query_skill_mapped("sword") == "qiankun-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")
		 	 gain_damage+=query_skill("liangyi-shengong",1)/10+xiuyang/10+query("int");  	
		 }       
		
		   gain_damage+=query("gain/damage")+query_temp("apply/gain_damage"); //增加临时基础伤害                         	    
	return gain_damage;
}
int query_gain_break()
{
	string myclass;
	int xiuyang;
	int gain_break;
	object weapon;
	weapon = query_temp("weapon");
	xiuyang=query("xiuyang");
	gain_break= query("gain/break")+query_temp("gain/break");
	myclass=query("family/family_name");
		if(myclass=="少林派")
		{
		 	if( query_skill_mapped("force") == "hunyuan-yiqi"
			&& query_skill_mapped("dodge") == "shaolin-shenfa"
			&& query_skill_mapped("parry") == "jingang-buhuaiti"
			&&(   (query_skill_mapped("sword") == "damo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(query_skill_mapped("whip") == "riyue-bian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "whip")	 
					||(query_skill_mapped("strike") == "yipai-liangsan"&&query_skill_prepared("strike") == "yipai-liangsan" ))	
			)
			  gain_break+=xiuyang/5; 
		}	
	  if(myclass=="武当派")
		{
	    if( query_skill_mapped("force") == "taiji-shengong"
			&& query_skill_mapped("dodge") == "tiyunzong"
			&& (query_skill_mapped("parry") == "taiji-quan"||query_skill_mapped("parry") == "taiji-jian")
			&&(   (query_skill_mapped("sword") == "taiji-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(query_skill_mapped("unarmed") == "taiji-quan"&&query_skill_prepared("unarmed") == "taiji-quan" ))	 	
		 	)
		     gain_break+=xiuyang/5;
		   		 
		} 
	  if(myclass=="峨嵋派") {
	    if( query_skill_mapped("force") == "linji-zhuang"
			&& query_skill_mapped("dodge") == "zhutian-bu"
			&& (query_skill_mapped("parry") == "piaoxue-zhang"||query_skill_mapped("parry") == "huifeng-jian")
			&&(   (query_skill_mapped("sword") == "huifeng-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(query_skill_mapped("strike") == "piaoxue-zhang"&&query_skill_prepared("strike") == "piaoxue-zhang" ))	 	
		 	)
		 	gain_break+=xiuyang/5;		
	   }
		if(myclass=="华山剑宗") {
	    if(query_skill_mapped("sword") == "lonely-sword"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")	 
		 	gain_break+=query_skill("huashan-xinfa",1)/10+query("int")+xiuyang/10;
		 	
		 	if( query_skill_mapped("force") == "huashan-xinfa"
			&& query_skill_mapped("dodge") == "huashan-shenfa"
			&& (query_skill_mapped("parry") == "lonely-sword")
			&& (query_skill_mapped("sword") == "lonely-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		  gain_break+=xiuyang/5; 		   		
	   }	
	   if(myclass=="华山派") {
	    if( query_skill_mapped("force") == "zixia-shengong"
			&& query_skill_mapped("dodge") == "feiyan-huixiang"
			&& (query_skill_mapped("parry") == "huashan-sword")
			&& (query_skill_mapped("sword") == "huashan-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		  gain_break+=xiuyang/5; 		   		
	   }	
	   if(myclass=="丐帮") {
	   	 if( query_skill_mapped("strike") == "dragon-strike"&&query_skill_prepared("strike") == "dragon-strike" )
	   	    gain_break+=query_skill("huntian-qigong",1)/10+xiuyang/10+query("str");
	     if( query_skill_mapped("force") == "huntian-qigong"
			&& query_skill_mapped("dodge") == "xiaoyaoyou"
			&& (query_skill_mapped("parry") == "dagou-bang"||query_skill_mapped("parry") == "dragon-strike")
			&& ((query_skill_mapped("staff") == "dagou-bang"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(query_skill_mapped("strike") == "dragon-strike"&&query_skill_prepared("strike") == "dragon-strike" ))	 	)
		      gain_break+=xiuyang/5; 		   		
	   }	
	    if(myclass=="桃花岛")
		{
			if( query_skill_mapped("force") == "bibo-shengong"
			&& query_skill_mapped("dodge") == "anying-fuxiang"
			&& (query_skill_mapped("parry") == "yuxiao-jian")
			&& (query_skill_mapped("sword") == "yuxiao-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		    gain_break+=xiuyang/5;	
		 }     	
	   
	    if(myclass=="星宿派")
		{
			if( query_skill_mapped("strike") == "chousui-zhang"
		 	&&query_skill_prepared("strike") == "chousui-zhang" 
		 	)
				gain_break+=xiuyang/10+query("str")+query_skill("freezing-force",1)/10;		 	
		  if( query_skill_mapped("force") == "freezing-force"
			&& query_skill_mapped("dodge") == "zhaixinggong"
			&& (query_skill_mapped("parry") == "tianshan-zhang"||query_skill_mapped("parry") == "chousui-zhang")
			&& (query_skill_mapped("staff") == "tianshan-zhang"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff"))
			 gain_break+=xiuyang/5;
		 }     	    
	   
	   if(myclass=="逍遥派")
		{
			if( query_skill_mapped("hand") == "zhemei-shou"
		 	&&query_skill_prepared("hand") == "zhemei-shou")
		 	gain_break+=xiuyang/10+query("int")+query_skill("beiming-shengong",1)/10;	
		 	if( query_skill_mapped("force") == "beiming-shengong"
			&& query_skill_mapped("dodge") == "lingbo-weibu"
			&& (query_skill_mapped("parry") == "shemei-shou"||query_skill_mapped("parry") == "ruyi-dao")
			&& ((query_skill_mapped("blade") == "ruyi-dao"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")
			     ||(query_skill_mapped("hand") == "zhemei-shou"&&query_skill_prepared("hand") == "zhemei-shou" ))	 	)
		    gain_break+=xiuyang/5;
		 }       	
	   
	   if(myclass=="古墓派")
		{
			if( query_skill_mapped("unarmed") == "sad-strike"
		 	&&query_skill_prepared("unarmed") == "sad-strike")
		 	gain_break+=xiuyang/10+query("con")+query_skill("surge-force",1)/10;	
		 	if( query_skill_mapped("force") == "surge-force"
			&& query_skill_mapped("dodge") == "yunv-shenfa"
			&& (query_skill_mapped("parry") == "sad-strike"||query_skill_mapped("parry") == "xuantie-jian")
			&& ((query_skill_mapped("sword") == "xuantie-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
			     ||(query_skill_mapped("unarmed") == "sad-strike"&&query_skill_prepared("unarmed") == "sad-strike" ))	 	)
		   gain_break+=xiuyang/5;
		 }       	
	    if(myclass=="全真教")
		{
			 if( query_skill_mapped("force") == "xiantian-gong"
			&& query_skill_mapped("dodge") == "jinyan-gong"
			&& (query_skill_mapped("parry") == "jinguan-yusuo")
			&& (query_skill_mapped("sword") == "quanzhen-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   gain_break+=xiuyang/5;
		 }    
		 
		  if(myclass=="神龙教")
		{
			 if( query_skill_mapped("force") == "shenlong-xinfa"
			&& query_skill_mapped("dodge") == "yixingbu"
			&& (query_skill_mapped("parry") == "shenlong-bashi"||query_skill_mapped("parry") == "huagu-mianzhang")
			&& ((query_skill_mapped("strike") == "huagu-mianzhang"&&query_skill_prepared("strike") == "huagu-mianzhang" )
			     ||(query_skill_mapped("hand") == "shenlong-bashi"&&query_skill_prepared("hand") == "shenlong-bashi" ))	 	)
		  gain_break+=xiuyang/5;
		 }     	    	
		 
		  if(myclass=="雪山寺")
		{
				 if(query_skill_mapped("hammer") == "riyue-lun"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "hammer")	 
		 	gain_break+=query_skill("longxiang-gong",1)/10+query("str")+xiuyang/10;			
			  if( query_skill_mapped("force") == "longxiang-gong"
			&& query_skill_mapped("dodge") == "shenkong-xing"
			&& (query_skill_mapped("parry") == "riyue-lun")
			&& (query_skill_mapped("hammer") == "riyue-lun"&&objectp(weapon)&&(string)weapon->query("skill_type") == "hammer")	)
		    gain_break+=xiuyang/5;	
		 }       	
		 if(myclass=="血刀门")
		{
		 if( query_skill_mapped("force") == "xuehai-mogong")
			 	gain_break+=xiuyang/5+query("str");
			   if( query_skill_mapped("force") == "xuehai-mogong"
			&& query_skill_mapped("dodge") == "shenkong-xing"
			&& (query_skill_mapped("parry") == "xue-dao")
			&& (query_skill_mapped("blade") == "xue-dao"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")	)
		   gain_break+=xiuyang/5;
		 } 
		if(myclass=="灵鹫宫")
		{
		 //if( query_skill_mapped("force") == "xuehai-mogong")
			 //	gain_armor+=query_skill("force")/2;
			    if(query_skill_mapped("force") == "bahuang-gong"
			&& query_skill_mapped("dodge") == "yueying-wubu"
			&& (query_skill_mapped("parry") == "tianyu-qijian")
			&& (query_skill_mapped("sword") == "tianyu-qijian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   gain_break+=xiuyang/5;
		 }       
		  if(myclass=="欧阳世家")
		{
		 if( query_skill_mapped("unarmed") == "hamagong"
		 	&&query_skill_prepared("unarmed") == "hamagong")
		 	gain_break+=xiuyang/10+query("str")+query_skill("hamagong",1)/10;	
			   if( query_skill_mapped("force") == "hamagong"
			&& query_skill_mapped("dodge") == "chanchu-bufa"
			&& (query_skill_mapped("parry") == "hamagong"||query_skill_mapped("parry") == "lingshe-zhangfa")
			&& ((query_skill_mapped("staff") == "lingshe-zhangfa"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(query_skill_mapped("unarmed") == "hamagong"&&query_skill_prepared("unarmed") == "hamagong" ))	 	)
		  gain_break+=xiuyang/5;
		 }       
		 if(myclass=="关外胡家")
		{
		   if(query_skill_mapped("force") == "lengyue-shengong"
			&& query_skill_mapped("dodge") == "sixiang-bufa"
			&& (query_skill_mapped("parry") == "daojian-guizhen")
			&& (query_skill_mapped("blade") == "daojian-guizhen"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")	)
		   gain_break+=xiuyang/5;
		 } 
		  if(myclass=="慕容世家")
		{
		  if( query_skill_mapped("force") == "zihui-xinfa"
			&& query_skill_mapped("dodge") == "beidou-xianzong"
			&& (query_skill_mapped("parry") == "douzhuan-xingyi")
			&& (query_skill_mapped("sword") == "murong-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   gain_break+=xiuyang/5;
		 }        
		  if(myclass=="段氏皇族")
		{
			 if( query_skill_mapped("force") == "kurong-changong"
			&& query_skill_mapped("dodge") == "tiannan-step"
			&& query_skill_mapped("parry") == "six-finger"
			&& query_skill_mapped("finger") == "six-finger"&&query_skill_prepared("finger") == "six-finger"	)
		    gain_break+=xiuyang/5;
		 }       
		 if(myclass=="明教")
		{
		 if(query_skill_mapped("force") == "jiuyang-shengong")
		 {
		 	if(query_skill_mapped("force") == "jiuyang-shengong"
			&& query_skill_mapped("dodge") == "bianfu-bu"
			&& query_skill_mapped("parry") == "qiankun-danuoyi"
			&& ((query_skill_mapped("claw") == "sougu-yingzhua"&&query_skill_prepared("claw") == "sougu-yingzhua" )
			     ||(query_skill_mapped("unarmed") == "jiuyang-shengong"&&query_skill_prepared("unarmed") == "jiuyang-shengong" ))	 	)
		    	gain_break+=xiuyang/5;
		 }	
		 if(query_skill_mapped("force") == "shenghuo-shengong")
		 {
		 	if(query_skill_mapped("force") == "shenghuo-shengong"
			&& query_skill_mapped("dodge") == "shenghuo-bu"
			&& query_skill_mapped("parry") == "qiankun-danuoyi"
			&& (query_skill_mapped("sword") == "shenghuo-ling"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		      gain_break+=xiuyang/5;
		 }
		 }   
		 if(myclass=="日月神教")
		{
		 if(query_skill_mapped("force") == "kuihua-shengong")
		 {
		 	if(query_skill_mapped("sword") == "kuihua-shengong"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")
		 	gain_break+=xiuyang/10+query("dex")+query_skill("kuihua-shengong",1)/10;	
		 	if( query_skill_mapped("force") == "kuihua-shengong"
			&& query_skill_mapped("dodge") == "kuihua-shengong"
			&& query_skill_mapped("parry") == "kuihua-shengong"
			&& (query_skill_mapped("sword") == "kuihua-shengong"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)  
		 	gain_break+=xiuyang/5;
		 }	
		 if(query_skill_mapped("force") == "xixing-dafa")
		 {
		 	if( query_skill_mapped("force") == "xixing-dafa"
			&& query_skill_mapped("dodge") == "piaomiao-shenfa"
			&& query_skill_mapped("parry") == "tianmo-jian"
			&& (query_skill_mapped("sword") == "tianmo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		 	gain_break+=xiuyang/5;
		 }
		 }    
		 if(myclass=="昆仑派")
		{
		  if( query_skill_mapped("force") == "liangyi-shengong"
			&& query_skill_mapped("dodge") == "chuanyun-bu"
			&& (query_skill_mapped("parry") == "qiankun-jian")
			&& (query_skill_mapped("sword") == "qiankun-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		  gain_break+=xiuyang/10;
		 }                   
		          	 
	return gain_break;
}

int query_gain_armor()
{
	string myclass;
	int xiuyang;
	int gain_armor;
	object weapon;
	weapon = query_temp("weapon");
	xiuyang=query("xiuyang");
	gain_armor= query("gain/armor")+query_temp("gain/armor");
	
	myclass=query("family/family_name");
		if(myclass=="少林派")
		{
		 if( query_skill_mapped("force") == "hunyuan-yiqi" )
		 		gain_armor+=query_skill("force")/2;
		if( query_skill_mapped("force") == "hunyuan-yiqi"
			&& query_skill_mapped("dodge") == "shaolin-shenfa"
			&& query_skill_mapped("parry") == "jingang-buhuaiti"
			&&(   (query_skill_mapped("sword") == "damo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(query_skill_mapped("whip") == "riyue-bian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "whip")	 
					||(query_skill_mapped("strike") == "yipai-liangsan"&&query_skill_prepared("strike") == "yipai-liangsan" ))	
			)
			  gain_armor+=xiuyang/5; 
		}	
		if(myclass=="武当派")
		{
	  if( query_skill_mapped("unarmed") == "taiji-quan"
		 	&&query_skill_prepared("unarmed") == "taiji-quan" 
		 	)
		 	{
		 		gain_armor+=query_skill("taiji-shengong",1)/10+xiuyang/10+query("con");   	 	
		  }
		   if( query_skill_mapped("force") == "taiji-shengong"
			&& query_skill_mapped("dodge") == "tiyunzong"
			&& (query_skill_mapped("parry") == "taiji-quan"||query_skill_mapped("parry") == "taiji-jian")
			&&(   (query_skill_mapped("sword") == "taiji-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(query_skill_mapped("unarmed") == "taiji-quan"&&query_skill_prepared("unarmed") == "taiji-quan" ))	 	
		 	)
		     gain_armor+=xiuyang/5;
		   		 
		}

		if(myclass=="峨嵋派")
		{
	  		if(query_skill_mapped("force") == "linji-zhuang")
	  			gain_armor+=query_skill("force")/2;
		    if( query_skill_mapped("force") == "linji-zhuang"
			&& query_skill_mapped("dodge") == "zhutian-bu"
			&& (query_skill_mapped("parry") == "piaoxue-zhang"||query_skill_mapped("parry") == "huifeng-jian")
			&&(   (query_skill_mapped("sword") == "huifeng-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
					||(query_skill_mapped("strike") == "piaoxue-zhang"&&query_skill_prepared("strike") == "piaoxue-zhang" ))	 	
		 	)		
		     gain_armor+=xiuyang/5; 		 
		}
		if(myclass=="华山剑宗")
		{
		 if( query_skill_mapped("force") == "huashan-xinfa" )
		 		gain_armor+=query_skill("force")/2;
		  if( query_skill_mapped("force") == "huashan-xinfa"
			&& query_skill_mapped("dodge") == "huashan-shenfa"
			&& (query_skill_mapped("parry") == "lonely-sword")
			&& (query_skill_mapped("sword") == "lonely-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword"))	
		    gain_armor+=xiuyang/5;	
		}			
		if(myclass=="华山派")
		{
		 if( query_skill_mapped("force") == "zixia-shengong" )
		 		gain_armor+=query_skill("force")/2;
		  if( query_skill_mapped("force") == "zixia-shengong"
			&& query_skill_mapped("dodge") == "feiyan-huixiang"
			&& (query_skill_mapped("parry") == "huashan-sword")
			&& (query_skill_mapped("sword") == "huashan-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword"))	
		    gain_armor+=xiuyang/5;	
		}		
		if(myclass=="丐帮")
		{
		   if( query_skill_mapped("force") == "huntian-qigong"
			&& query_skill_mapped("dodge") == "xiaoyaoyou"
			&& (query_skill_mapped("parry") == "dagou-bang"||query_skill_mapped("parry") == "dragon-strike")
			&& ((query_skill_mapped("staff") == "dagou-bang"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(query_skill_mapped("strike") == "dragon-strike"&&query_skill_prepared("strike") == "dragon-strike" ))	 	)
		    gain_armor+=xiuyang/5;	
		 }     
		 
		 if(myclass=="桃花岛")
		{
			 if( query_skill_mapped("force") == "bibo-shengong")
			 	gain_armor+=query_skill("force")/2;
			 if(query_skill_mapped("sword") == "yuxiao-jian"
		 	&&objectp(weapon)
		 	&&(string)weapon->query("skill_type") == "sword")	 
		 	gain_armor+=query_skill("bibo-shengong",1)/10+query("int")+xiuyang/10;	
			 	
		  if( query_skill_mapped("force") == "bibo-shengong"
			&& query_skill_mapped("dodge") == "anying-fuxiang"
			&& (query_skill_mapped("parry") == "yuxiao-jian")
			&& (query_skill_mapped("sword") == "yuxiao-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		    gain_armor+=xiuyang/5;	
		 } 
		 
		  if(myclass=="星宿派")
		{
			 if( query_skill_mapped("force") == "freezing-force")
			 	gain_armor+=query_skill("force")/2;
						 	
		  if( query_skill_mapped("force") == "freezing-force"
			&& query_skill_mapped("dodge") == "zhaixinggong"
			&& (query_skill_mapped("parry") == "tianshan-zhang"||query_skill_mapped("parry") == "chousui-zhang")
			&& (query_skill_mapped("staff") == "tianshan-zhang"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff"))
			 gain_armor+=xiuyang/5;	
		 }   
		 
		 if(myclass=="逍遥派")
		{
			if( query_skill_mapped("force") == "beiming-shengong"
			&& query_skill_mapped("dodge") == "lingbo-weibu"
			&& (query_skill_mapped("parry") == "shemei-shou"||query_skill_mapped("parry") == "ruyi-dao")
			&& ((query_skill_mapped("blade") == "ruyi-dao"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")
			     ||(query_skill_mapped("hand") == "zhemei-shou"&&query_skill_prepared("hand") == "zhemei-shou" ))	 	)
		    gain_armor+=xiuyang/5;	
		 }
		   	 
		 if(myclass=="古墓派")
		{
		 	if( query_skill_mapped("force") == "surge-force"
			&& query_skill_mapped("dodge") == "yunv-shenfa"
			&& (query_skill_mapped("parry") == "sad-strike"||query_skill_mapped("parry") == "xuantie-jian")
			&& ((query_skill_mapped("sword") == "xuantie-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")
			     ||(query_skill_mapped("unarmed") == "sad-strike"&&query_skill_prepared("unarmed") == "sad-strike" ))	 	)
		  gain_armor+=xiuyang/5;	
		 }         	 
		 
		  if(myclass=="全真教")
		{
			 if( query_skill_mapped("force") == "xiantian-gong"
			&& query_skill_mapped("dodge") == "jinyan-gong"
			&& (query_skill_mapped("parry") == "jinguan-yusuo")
			&& (query_skill_mapped("sword") == "quanzhen-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   gain_armor+=xiuyang/5;	
		 }      
		  
		 if(myclass=="神龙教")
		{
		 if( query_skill_mapped("force") == "shenlong-xinfa")
			 	gain_armor+=query_skill("force")/2;
			 if( query_skill_mapped("force") == "shenlong-xinfa"
			&& query_skill_mapped("dodge") == "yixingbu"
			&& (query_skill_mapped("parry") == "shenlong-bashi"||query_skill_mapped("parry") == "huagu-mianzhang")
			&& ((query_skill_mapped("strike") == "huagu-mianzhang"&&query_skill_prepared("strike") == "huagu-mianzhang" )
			     ||(query_skill_mapped("hand") == "shenlong-bashi"&&query_skill_prepared("hand") == "shenlong-bashi" ))	 	)
		  gain_armor+=xiuyang/5;	
		 }  
		 
		  if(myclass=="雪山寺")
		{
		 if( query_skill_mapped("force") == "longxiang-gong")
			 	gain_armor+=xiuyang/5+query("str");
			  if( query_skill_mapped("force") == "longxiang-gong"
			&& query_skill_mapped("dodge") == "shenkong-xing"
			&& (query_skill_mapped("parry") == "riyue-lun")
			&& (query_skill_mapped("hammer") == "riyue-lun"&&objectp(weapon)&&(string)weapon->query("skill_type") == "hammer")	)
		    gain_armor+=xiuyang/5;	
		 } 
		  if(myclass=="血刀门")
		{
		 if( query_skill_mapped("force") == "xuehai-mogong")
			 	gain_armor+=query_skill("force")/2;
			   if( query_skill_mapped("force") == "xuehai-mogong"
			&& query_skill_mapped("dodge") == "shenkong-xing"
			&& (query_skill_mapped("parry") == "xue-dao")
			&& (query_skill_mapped("blade") == "xue-dao"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")	)
		   gain_armor+=xiuyang/5;	
		 }       
		  if(myclass=="灵鹫宫")
		{
		 //if( query_skill_mapped("force") == "xuehai-mogong")
			 //	gain_armor+=query_skill("force")/2;
			    if(query_skill_mapped("force") == "bahuang-gong"
			&& query_skill_mapped("dodge") == "yueying-wubu"
			&& (query_skill_mapped("parry") == "tianyu-qijian")
			&& (query_skill_mapped("sword") == "tianyu-qijian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		   gain_armor+=xiuyang/5;	
		 }      
		  if(myclass=="欧阳世家")
		{
		 if( query_skill_mapped("force") == "hamagong")
			 	gain_armor+=query_skill("force")/2;
			   if( query_skill_mapped("force") == "hamagong"
			&& query_skill_mapped("dodge") == "chanchu-bufa"
			&& (query_skill_mapped("parry") == "hamagong"||query_skill_mapped("parry") == "lingshe-zhangfa")
			&& ((query_skill_mapped("staff") == "lingshe-zhangfa"&&objectp(weapon)&&(string)weapon->query("skill_type") == "staff")
			     ||(query_skill_mapped("unarmed") == "hamagong"&&query_skill_prepared("unarmed") == "hamagong" ))	 	)
		   gain_armor+=xiuyang/5;	
		 }  
		   if(myclass=="关外胡家")
		{
		 if( query_skill_mapped("force") == "lengyue-shengong")
			 	gain_armor+=query_skill("force")/2;
			  if(query_skill_mapped("force") == "lengyue-shengong"
			&& query_skill_mapped("dodge") == "sixiang-bufa"
			&& (query_skill_mapped("parry") == "daojian-guizhen")
			&& (query_skill_mapped("blade") == "daojian-guizhen"&&objectp(weapon)&&(string)weapon->query("skill_type") == "blade")	)
		   gain_armor+=xiuyang/5;	
		 } 
		 if(myclass=="慕容世家")
		{
		 if( query_skill_mapped("force") == "zihui-xinfa")
			 	gain_armor+=query_skill("force")/2;
			 if( query_skill_mapped("force") == "zihui-xinfa"
			&& query_skill_mapped("dodge") == "beidou-xianzong"
			&& (query_skill_mapped("parry") == "douzhuan-xingyi")
			&& (query_skill_mapped("sword") == "murong-sword"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		  gain_armor+=xiuyang/5;	
		 }           	      	
		  if(myclass=="段氏皇族")
		{
		 if( query_skill_mapped("force") == "kurong-changong")
			 	gain_armor+=query_skill("force")/2;
			 if( query_skill_mapped("force") == "kurong-changong"
			&& query_skill_mapped("dodge") == "tiannan-step"
			&& query_skill_mapped("parry") == "six-finger"
			&& query_skill_mapped("finger") == "six-finger"&&query_skill_prepared("finger") == "six-finger"	)
		   gain_armor+=xiuyang/5;	
		 }       
		  if(myclass=="明教")
		{
		 if(query_skill_mapped("force") == "jiuyang-shengong")
		 {
		 	if( query_skill_mapped("force") == "jiuyang-shengong")
			 	gain_armor+=xiuyang/5+query("int");
			if( query_skill_mapped("unarmed") == "jiuyang-shengong"
		 	&&query_skill_prepared("unarmed") == "jiuyang-shengong" 
		 	) 	
		 	  	gain_armor+=xiuyang/10+query("int")+query_skill("jiuyang-shengong",1)/10;
		 	if(query_skill_mapped("force") == "jiuyang-shengong"
			&& query_skill_mapped("dodge") == "bianfu-bu"
			&& query_skill_mapped("parry") == "qiankun-danuoyi"
			&& ((query_skill_mapped("claw") == "sougu-yingzhua"&&query_skill_prepared("claw") == "sougu-yingzhua" )
			     ||(query_skill_mapped("unarmed") == "jiuyang-shengong"&&query_skill_prepared("unarmed") == "jiuyang-shengong" ))	 	)
		    	gain_armor+=xiuyang/5;
		 }	
		 if(query_skill_mapped("force") == "shenghuo-shengong")
		 {
		 	if(query_skill_mapped("force") == "shenghuo-shengong"
			&& query_skill_mapped("dodge") == "shenghuo-bu"
			&& query_skill_mapped("parry") == "qiankun-danuoyi"
			&& (query_skill_mapped("sword") == "shenghuo-ling"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		      gain_armor+=xiuyang/5;
		 }
		 } 
		 if(myclass=="日月神教")
		{
		 if(query_skill_mapped("force") == "kuihua-shengong")
		 {
		 	if( query_skill_mapped("force") == "kuihua-shengong"
			&& query_skill_mapped("dodge") == "kuihua-shengong"
			&& query_skill_mapped("parry") == "kuihua-shengong"
			&& (query_skill_mapped("sword") == "kuihua-shengong"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)  
		 	gain_armor+=xiuyang/5;
		 }	
		 if(query_skill_mapped("force") == "xixing-dafa")
		 {
		 	if( query_skill_mapped("force") == "xixing-dafa"
			&& query_skill_mapped("dodge") == "piaomiao-shenfa"
			&& query_skill_mapped("parry") == "tianmo-jian"
			&& (query_skill_mapped("sword") == "tianmo-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		 	gain_armor+=xiuyang/5;
		 }
		 }    
		 if(myclass=="昆仑派")
		{
		  if( query_skill_mapped("force") == "liangyi-shengong"
			&& query_skill_mapped("dodge") == "chuanyun-bu"
			&& (query_skill_mapped("parry") == "qiankun-jian")
			&& (query_skill_mapped("sword") == "qiankun-jian"&&objectp(weapon)&&(string)weapon->query("skill_type") == "sword")	)
		  gain_armor+=xiuyang/10;
		 }                    	      	    	
	return gain_armor;
}
*/
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
