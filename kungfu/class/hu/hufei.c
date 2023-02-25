// hufei.c

#include <ansi.h>;

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

mixed ask_silver();
string ask_me();
string ask_book();
string ask_hujia_book();
mixed ask_skill();

void create()
{
	set_name("胡斐", ({"hu fei", "hu", "fei"}));
	set("gender", "男性");
	set("nickname", "雪山飞"HIG"狐"NOR);
	set("age", 25);
	set("long", @LONG
他就是胡一刀之子，因其武功高强神出鬼没。在江湖上人送外号「雪山飞狐」。
他身穿一件白色长衫，腰间别着一把看起来很旧的刀。满腮虬髯，根根如铁，
一头浓发，却不结辫。
LONG);
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 10);
	set("chat_msg", ({
		"胡斐叹了口气道：“不知什么时候还能再见到若兰姑娘。\n",
		"胡斐切齿恨道：“阎基老贼暗中下毒，我必手刃此獠！”\n",
	}));

	set("qi", 4200);
	set("max_qi", 4200);
	set("jing", 2100);
	set("max_jing", 2100);
	set("neili", 5800);
	set("max_neili", 5800);
	set("jiali", 80);
	set("combat_exp", 2300000);
	set("score", 20000);

	set_skill("force", 210);	    // 基本内功
	set_skill("lengyue-shengong", 210); // 冷月神功
	set_skill("blade", 240);	    // 基本刀法
	set_skill("hujia-daofa", 240);      // 胡家刀法
	set_skill("dodge", 240);	    // 基本躲闪
	set_skill("taxue-wuhen", 240);      // 踏雪无痕
	set_skill("sixiang-bufa", 240);     // 四象步法
	set_skill("parry", 220);	    // 基本招架
	set_skill("throwing", 240);	 // 基本暗器
	set_skill("mantian-xing", 240);     // 满天星
	set_skill("strike", 180);	   // 基本掌法
	set_skill("tianchang-zhang", 180);  // 天长掌法
	set_skill("cuff", 180);	     // 基本拳法
	set_skill("hujia-quan", 180);       // 胡家拳法

	map_skill("force", "lengyue-shengong");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "sixiang-bufa");
	map_skill("parry", "hujia-daofa");
	map_skill("throwing", "mantian-xing");
	map_skill("strike", "tianchang-zhang");
	map_skill("cuff", "hujia-quan");

	prepare_skill("strike", "tianchang-zhang");
	prepare_skill("cuff",   "hujia-quan");

	create_family("关外胡家", 7, "传人");

	set("inquiry",([
		"宝刀":     (: ask_me :),
		"胡家刀谱": (: ask_book :),
		"刀谱总诀": (: ask_hujia_book :),
		"银两" :    (: ask_silver :),
		"开天辟地": (: ask_skill :),
	     ]));

	set("baodao_count", 1);
	set("book_count", 1);
	set("hujia_book_count", 1);

	set_temp("apply/damage", 120);
	set_temp("apply/armor", 200);
	set_temp("apply/attack", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.bafang" :),
		(: perform_action, "blade.po" :),
		(: perform_action, "cuff.kuai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set("silver_count", 4);

	setup();
	carry_object("/d/guanwai/obj/lengyue")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

string ask_me()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "先入我门来再谈这些事。\n";
	}

	if ((int)me->query("shen") < 0)
	{
		command("sigh");
		return "你怎能走上邪路？败坏我胡家一世声名。\n";
	}

	if ((int)me->query("combat_exp") < 100000)
		return "以你目前的本领还不配使用闯王宝刀。\n";

	if ((int)me->query("shen") < 100000)
		return "以你目前的作为还不配使用闯王宝刀。\n";

	if ((int)query("baodao_count") > 0)
	{       
		add("baodao_count", -1);
		ob = new ("/d/guanwai/obj/cwbdao");
		ob->move(me);
		return " 好吧，这把闯王宝刀你先拿去用，希望你好好利用它。\n";
	} else
		return "你来晚了，现在这把刀已不在此处。\n";
}

string ask_book()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "先入我门来再谈这些事。\n";
	}

	if ((int)me->query("shen") < 0)
	{
		command("sigh");
		return "你怎能走上邪路？败坏我胡家一世声名。\n";
	}

	if ((int)me->query("combat_exp") < 5000)
		return "你先好好学习武功，刀谱我自然会交给你。\n";

	if ((int)query("book_count") > 0)
	{       
		add("book_count", -1);
		ob = new ("/clone/book/blade-book");
		ob->move(me);
		return " 好吧，这本胡家刀谱你拿去用心研读吧。\n";
	} else
		return "你来晚了，现在刀谱已不在此处。\n";
}

string ask_hujia_book()
{
	object ob, me;

	me = this_player();
	if (me->query("family/family_name") !=
	    query("family/family_name"))
	{
		command("shake");
		return "先入我门来再谈这些事。\n";
	}

	if ((int)me->query("shen") < 0)
	{
		command("sigh");
		return "你怎能走上邪路？败坏我胡家一世声名。\n";
	}

	if ((int)me->query("combat_exp") < 50000)
		return "你的武功太差，先练好武功再说。\n";

	if ((int)me->query_skill("blade", 1) < 40)
		return "你先在刀法上好好下下功夫，然后再研读刀谱总诀不迟。\n";

	if ((int)me->query_skill("hujia-daofa", 1) < 40)
		return "你先在胡家刀法上好好下下功夫，然后再研读刀谱总诀不迟。\n";

	if ((int)query("hujia_book_count") > 0)
	{
		add("hujia_book_count", -1);
		ob = new ("/clone/book/hujia-book");
		ob->move(me);
		return " 好吧，这本刀谱总诀你拿去用心研读吧。\n";
	} else
		return "你来晚了，现在刀谱总诀已不在此处。\n";
}

void attempt_apprentice(object ob)
{
	object me;

	me = this_object();
	if (ob->name(1) == "胡一刀" || ob->name(1) == "胡壹刀")
	{
		message_vision("$N大怒：我操！你想做我的老子啊？\n", me);
		return;
	}

	if (ob->name(1) == "胡斐")
	{
		message_vision("$N大怒：他奶奶的！你咋也起这个名字？\n", me);
		return;
	}
/*
	if (ob->query("born_family") != "关外胡家")
	{
		message_vision("$N对$n道：你不是我们胡家的人，我怎能收你为徒？\n",
			       me, ob);
		return;
	}
*/
	if (ob->query("detach/关外胡家") ||
	    ob->query("betrayer/times"))
	{
		message_vision("$N摇摇头对$n说：你反复无常，我不能收你为徒！\n",
			       me, ob);
		return;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != me->query("family/family_name"))
	{
		message_vision("$N对$n道：你虽然是胡家的人，但你"
			       "入了其他门派，我不能收你为徒！\n",
			       me, ob);
		return;
	}

	message_vision("$N感叹道：我们胡家还要靠你们来发扬光大啦！\n",
		       me, ob);
	command("recruit " + ob->query("id"));
	return;
}

mixed ask_skill()
{
	object me;

	me = this_player();

	if (me->query("can_perform/hujia-daofa/pi"))
		return "俺不是已经教过你了吗？还多说什么？";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你又不是俺胡家的，还和我罗嗦什么？";

	if (me->query_skill("hujia-daofa", 1) < 1)
		return "你连胡家刀法都未曾学过，哪里来绝招？";

	if (me->query("shen") < 30000)
		return "你侠义正事做得不够，这招我先不忙传你。";

	if (me->query_skill("force") < 250)
		return "你的内功火候不足，学不成这招。";

	if (me->query_skill("hujia-daofa", 1) < 180)
		return "你的胡家刀法火候未到，还得多练习练习。";

	message_vision(HIY "$n" HIY "凝视了$N" HIY "半天，缓缓地点了"
		       "点头，颇为赞许道：“想不到今日\n你的刀法能有"
		       "如此造诣，假以时日，你必当超过为师。今日我就"
		       "传\n你这套开天辟地势，希望日后你能够有所作为"
		       "。”$n" HIY "顿了顿，又\n接着对$N" HIY "说道"
		       "：“我胡家刀法之所以厉害，不外乎刀势凌厉。须"
		       "知\n以主欺客，不如以客犯主；嫩胜于老，迟胜于"
		       "急。胡家刀法常用到\n的缠、滑、绞、擦、抽、截"
		       "等刀势就远强于一般刀法中展、抹、钩、\n剁、砍"
		       "、劈等刀势。而这开天辟地势的变化却又不止于此"
		       "，让我慢\n慢给你说来……”如此这般，过了良久"
		       "……良久……"NOR"\n", me, this_object());

	command("nod");
	command("say 刚才我所说的全是要点，需牢记在心。");
	command("say 你下来后一定要勤加练习，才能将这势用得纯熟。");
	tell_object(me, HIC "你学会了「开天辟地势」。"NOR"\n");

	if (me->can_improve_skill("force"))
		me->improve_skill("force", 1500000);
	if (me->can_improve_skill("dodge"))
		me->improve_skill("dodge", 1500000);
	if (me->can_improve_skill("parry"))
		me->improve_skill("parry", 1500000);
	if (me->can_improve_skill("blade"))
		me->improve_skill("blade", 1500000);
	if (me->can_improve_skill("hujia-daofa"))
		me->improve_skill("hujia-daofa", 1500000);
	me->improve_skill("martial-cognize", 1500000);
	me->set("can_perform/hujia-daofa/pi", 1);
	return 1;
}

mixed ask_silver()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("born_family") != "关外胡家")
		return "干哈啊？想要钱自己去挣，你问我是咋回事啊？";

	if (me->query("age") > 14)
		return "你年纪也不小了，怎么也不努力？";

	if (time() - me->query_temp("last_get_from_hu") < 1200)
		return "我不是刚给过你一点银两么？你怎么就给花了？";

	if (query("silver_count") < 1)
		return "我这儿也没有了，你只好自己想办法吧！";

	ob = new("/clone/money/silver");
	ob->set_amount(2);
	me->set_temp("last_get_from_hu", time());
	add("silver_count", -1);
	message_vision("$N拿出一些银两递给$n，道：“这点钱"
		       "你拿去做盘缠吧，不要浪费了！”\n",
		       this_object(), me);
	ob->move(me, 1);
	return 1;
}

void reset()
{
	set("silver_count", 4);
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
