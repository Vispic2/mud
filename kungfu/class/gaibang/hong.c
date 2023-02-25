#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
	set("long", 
		"他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。\n");
	set("attitude", "peaceful");
	set("str", 37);
	set("int", 31);
	set("con", 33);
	set("dex", 32);
	set("chat_chance", 1);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
	}));
	set("chat_chance_combat", 1);
	set("chat_msg_combat", ({
		(: perform_action, "strike.xianglong" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry", ([
		"天下无狗" : (: ask_me :),
		"打狗棒"  : (: ask_bang :),
	]));
	set("qi", 5200);
	set("max_qi", 5200);
	set("jing", 2700);
	set("max_jing", 2700);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 120);
	set("combat_exp", 2500000);
	set("score", 50000);

	set_skill("force", 270);
	set_skill("jiaohua-neigong", 250);
	set_skill("huntian-qigong", 270);
	set_skill("unarmed", 230);
	set_skill("changquan", 230);
	set_skill("dodge", 240);
	set_skill("xiaoyaoyou", 240);
	set_skill("feiyan-zoubi", 240);
	set_skill("parry", 250);
	set_skill("staff", 270);
	set_skill("strike", 270);
	set_skill("dragon-strike", 270);
	set_skill("jiaohua-bangfa", 250);
	set_skill("dagou-bang", 270);
	set_skill("throwing", 220);
	set_skill("mantianhuayu-zhen", 220);
	set_skill("begging", 200);
	set_skill("checking", 200);
	set_skill("training", 180);
	map_skill("throwing", "mantianhuayu-zhen");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("parry", "changquan");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "dragon-strike");

	prepare_skill("strike", "dragon-strike");

	set("no_teach", ([
		"dragon-strike" : (: try_to_learn_ds :),
		"dagou-bang"    : (: try_to_learn_db :),
	]));

	create_family("丐帮", 17, "帮主");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "staff.wugou" :),
		(: perform_action, "staff.ban" :),
		(: perform_action, "staff.chan" :),
		(: perform_action, "strike.leiting" :),
		(: perform_action, "strike.xiang" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object(__DIR__"yuzhu_zhang")->wield();
}

int accept_object(object who, object ob)
{
	int r;
	int lv;
	string by;
	object me;
	string hid;
	object hob;

	if (r = ::accept_object(who, ob))
		return r;

	me = this_object();

	if (! ob->query("food_supply"))
	{
		command("say 你给我这个干啥？");
		return -1;
	}

	if (! intp(lv = ob->query("level")) ||
	    lv < 1 || ! stringp(by = ob->query("by")))
	{
		command("say 这东西看上去也没啥特别的，你自个留着吧。");
		return -1;
	}

	if (lv < 100)
	{
		message_vision("$N看了看" + ob->name() + "，嗅了嗅，皱眉道：“这... "
			       "你还是自个留着吧！”\n", me);
		return -1;
	}

	if (lv < 180)
	{
		message_vision("$N嗅了嗅$n递过来的" + ob->name() + "，说道：“味道好"
			       "像不错，不过好像还是稍微欠那么一点儿火候嘛！”\n", me, who);
		return -1;
	}

	message_vision("$N嗅了嗅$n递过来的" + ob->name() + "，尝了几口，直咂舌头，叹"
		       "道：“好... 好极了！”\n", me, who);
	destruct(ob);
	if (! who->id(by))
	{
		message_vision("$N又道：“可惜呀！可惜！不知道这是谁做"
			       "的，有空你可得给我引见引见！”\n", me);
		return 1;
	}

	if (who->query("gender") != "女性")
	{
		message_vision("$N望了望$n，笑道：“想不到你一个大老爷们手艺"
			       "也不错，难得！难得！”\n", me, who);
		return 1;
	}

	if (! stringp(hid = who->query("couple/id")))
	{
		message_vision("$N看了看$n，笑道：“" + RANK_D->query_repsect(who) +
			       "，如今有婆家了没有，可要我介绍？”\n", me, who);
		return 1;
	}

	if (who->query("static/marry") > 1)
	{
		message_vision("$N咂了一会儿，道：“可惜你和你丈夫的关系已经不纯洁了，不然我"
			       "倒是可以传他两手功夫，算是报答。”\n", me);
		return 1;
	}

	if (! objectp(hob = find_player(hid)))
	{
		message_vision("$N咂了一会儿，道：“可惜你那位不在，不然我"
			       "倒是可以传他两手功夫，算是报答。”\n", me);
		return 1;
	}

	message_vision("$N嘻嘻一笑，道：“很好，老叫话没什么值钱的，什么时"
		       "候你那位来了，我教他两手掌法吧！”\n", me, who);
	hob->set("can_learn/hong/dragon-strike", 1);
	hob->set("can_learn/hong/staff", 1);
	who->set("can_learn/hong/xiaoyaoyou", 1);
	who->set("can_learn/hong/staff", 1);
	tell_object(who, HIG + me->name() + HIG "答应传授" +
			 hob->name(1) + "降龙十八掌法和基本杖法作为报答。"NOR"\n");
	tell_object(who, HIG + me->name() + HIG "答应传授" +
			 who->name(1) + "逍遥游和基本杖法作为报答。"NOR"\n");
	return 1;
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("gender") != "男性") 
	{
		if (skill != "xiaoyaoyou" && skill != "staff")
		{
			command("say 你想我学这个干什么？我什么时候说过教你了？"); 
			return -1; 
		}

	} else
	{
		if (skill != "dragon-strike" && skill != "strike" && 
		    skill != "staff")
		{
			command("say 你想我学这个干什么？我什么时候说过教你了？"); 
			return -1; 
		}
	}

	if (! me->query("can_learn/hong/" + skill))
	{
		command("say 嘿嘿... 找我学武功... 还是免了吧，老叫花不收徒。"); 
		return -1;
	}
	return 1;
}

int try_to_learn_db()
{
	object me;

	me = this_player();
	if (me->query("can_learn/hong/dagou-bang"))
		return 0;

	if (me->query("beggarlvl") < 9)
	{
		command("say 也不看看你是什么辈分，居然想学打狗棒法？");
		return -1;
	}
	if (me->query("shen") < -1000)
	{
		command("say 你中邪魔外道如此之深，还妄想学习神功？");
		return -1;
	}
	command("sigh");
	command("say 打狗棒法本来只传历代帮主，但是现在江湖多争乱，你"
		"也是本帮高手，却也学之无妨。");
	me->set("can_learn/hong/dagou-bang", 1);
	return 0;
}

int try_to_learn_ds()
{
	object me;
	object sob;
	int i;
	int flag;
	string *sub_skills;

	me = this_player();
	if (! me->query("can_learn/hong/dragon-strike") &&
	    me->query("beggarlvl") < 9)
	{
		command("say 你要学降龙十八掌？哈哈，等你升到本帮长老再说吧！");
		return -1;
	}

	if (me->query("shen") < -1000)
	{
		command("say 虽然我们丐帮不算什么大侠，不过你中邪魔外"
			"道太深，还妄想学习神功？");
		return -1;
	}

	sob = find_object(SKILL_D("dragon-strike"));
	if (! sob) sob = load_object(SKILL_D("dragon-strike"));
	if (! sob->valid_learn(me))
		return 0;
	if (me->query_skill("dragon-strike", 1))
	{
		command("say 你不是已经会了么？自己好好练吧。");
		return -1;
	}

	sub_skills = keys(sob->query_sub_skills());
	flag = 0;
	for (i = 0; i < sizeof(sub_skills); i++)
	{
		if (me->query_skill(sub_skills[i], 1) >= 10)
			continue;
		me->set_skill(sub_skills[i], 10);
		if (! flag)
		{
			flag = 1;
			command("say 好！我就将十八路掌法传授与你，"
				"你要好好练习，他日必能融会贯通！");
		}
		write(HIC "你对" + to_chinese(sub_skills[i]) + "有了一"
		      "些领悟。"NOR"\n");
	}

	if (! flag)
	{
		command("say 不是说了待到你融会贯通再来向我讨教吗？");
		return -1;
	}

	command("say 很好，现在你好好用功，把这十八路掌法融会贯通，合"
		"而为一再说吧。");
	notify_fail("好好努力，苦下功夫吧。\n");
	return -1;
}

void attempt_apprentice(object ob)
{
	if (ob->query("detach/丐帮"))
	{
		command("say 早知今日，何必当初！");
		return;
	}

	if (ob->query("betrayer"))
	{
		command("say 小子！再要罗嗦我可就要替你师傅教训教训你了！");
		return;
	}

	if (ob->query("family/family_name") != "丐帮")
	{
		command("say 嘿！你既然已经有了名师指点，还找我老叫花干什么？");
		return;
	}

	if (ob->query_str() < 40 && ob->query_int() < 42 && ob->query_con() < 40)
	{
		command("say 我说你这人体格也不行，脑筋也不灵光，还能和我学什么？");
	        tell_object(ob, "东方明向你千里传音：洪七公收徒要求并不高，臂力或者根骨任意一项达到40，亦或悟性达到42。\n");
		return;
	}

	if ((int)ob->query_skill("force") < 200)
	{
		command("sigh");
		command("say 你的内功火候太差了，先好好练练再来找我。");
		return;
	}

	if ((int)ob->query("max_neili") < 1000)
	{
		command("shake");
		command("say 就你那点内力哪里学得了什么上乘武功？");
		return;
	}
	command("recruit " + ob->query("id"));

	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/dagou-bang/wugou"))
		return "好好给我练功去，缠着我干什么？";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你一边去。";

	if (me->query_skill("dagou-bang", 1) < 150)
		return "你的打狗棒法学得怎么样啊？我看还差得远呢！";

	message_vision(HIG "$n" HIG "随手抄起地上一根啃剩下的鸡"
		       "骨头，手腕一抖，化作流星攻向$N" HIG "。\n$P"
		       HIG "只见眼前" HIY "星光" HIG "点点，似有无数招一齐"
		       "杀至，当场惊呆！"NOR"\n",
		       me, this_object());
	command("say 你看懂了没有？");
	tell_object(me, HIG "你学会了天下无狗。"NOR"\n");
	if (me->can_improve_skill("staff"))
		me->improve_skill("staff", 120000);
	me->set("can_perform/dagou-bang/wugou", 1);
	return 1;
}

mixed ask_bang()
{
	object me;
	object ob;
	object owner;

	me = this_player();

	if (me->query("family/family_name") != "丐帮")
		return "绿玉杖是我们丐帮镇帮之宝，你打听它干什么？";

	if (me->query("family/master_id") != query("id"))
		return "只有我的弟子才能用绿玉杖，你还是请回吧。";

	ob = find_object(LVYU_ZHANG);
	if (! ob) ob = load_object(LVYU_ZHANG);
	owner = environment(ob);
	while (owner)
	{
		if (owner->is_character() || ! environment(owner))
			break;
		owner = environment(owner);
	}

	if (owner == me)
		return "绿玉杖不是在你的手中么，怎么反而来找我呢？";

	if (objectp(owner) && owner != this_object())
	{
		if (! owner->is_character())
			return "我已经把绿玉杖已经借出去了。";

		if (owner->query("family/master_id") == query("id"))
			return "绿玉杖现在在" + owner->query("name") +
			       "手中，你要想用就去找他吧。";
		else
			return "绿玉杖现在落在" + owner->query("name") +
			       "手中，你去把它找回来吧。";
	}

	ob->move(this_object());
	message_vision("$N点点头道：“好，你用这绿玉杖要多作一些行"
		       "侠仗义的事情！”\n", this_object(), me);
	command("give lvyu zhang to " + me->query("id"));
	ob->start_borrowing();
	return 1;
}

void unconcious()
{
	die();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
