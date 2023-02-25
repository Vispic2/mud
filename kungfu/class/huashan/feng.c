// feng.c 风清扬

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

// 九剑
mapping po_type = ([ "破剑式" : ({ "sword" }),
		     "破刀式" : ({ "blade" }),
		     "破枪式" : ({ "staff" }),
		     "破鞭式" : ({ "hammer", "club", "dagger" }),
		     "破索式" : ({ "whip" }),
		     "破掌式" : ({ "unarmed", "finger", "claw",
				   "strike", "hand", "cuff" }),
		     "破箭式" : ({ "throwing" }),
		     "破气式" : ({ "force" }), ]);

int check_skill(string skill);
mixed teach_lonely_sword();

void create()
{
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "华山第十二代剑宗长老");
	set("long", @LONG
这便是当年名震江湖的华山名宿风清扬。他身著青袍，神气抑郁脸如金
纸。身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的
剑气之争一直难以忘怀。
LONG );
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 5500);
	set("max_qi", 5500);
	set("jing", 2600);
	set("max_jing", 2600);
	set("neili", 6800);
	set("max_neili", 6800);
	set("no_get", 1);
	set("jiali", 100);

	set("combat_exp", 2750000);
	set("score", 200000);

	set_skill("cuff", 240);
	set_skill("force", 250);
	set_skill("blade", 270);
	set_skill("dodge", 250);
	set_skill("parry", 270);
	set_skill("sword", 280);
	set_skill("strike", 240);
	set_skill("huashan-xinfa", 250);
	set_skill("zixia-shengong", 250);
	set_skill("poyu-quan", 240);
	set_skill("fanliangyi-dao", 270);
	set_skill("huashan-sword", 280);
	set_skill("hunyuan-zhang", 240);
	set_skill("lonely-sword", 280);
	set_skill("feiyan-huixiang", 250);
	set_skill("literate", 150);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

	create_family("华山前辈", 0, "高人");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.po" :),
		(: perform_action, "cuff.leidong" :),
		(: perform_action, "cuff.poshi" :),
		(: perform_action, "cuff.feng" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set("no_teach", ([
		"lonely-sword"   : (: teach_lonely_sword :),
	]));

	set_temp("apply/attack", 220);
	set_temp("apply/defense", 220);
	set_temp("apply/damage", 200);
	set_temp("apply/unarmed_damage", 200);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

mixed teach_lonely_sword()
{
	object me;

	me = this_player();
	if (me->query_skill("lonely-sword", 1) > 90)
	{
		if (me->query_temp("feng_has_told"))
		{
			command("say 你自己好好练吧！");
			return -1;
		}

		command("pat " + me->query("id"));
		command("say 你的独孤九剑也算是有些成就了，这剑法要靠"
			"自己勤练，以后你自己多加钻研吧！");
		me->set_temp("feng_has_told", 1);
		return -1;
	}

	if (me->query_temp("learnd_lonely_sword"))
		return 0;

	me->set_temp("learnd_lonely_sword", 1);
	command("say 很好，这门剑法重在剑意，不在招式，你要学习它切不"
		"可拘泥于形式。");
	return 0;
}

void attempt_apprentice(object ob)
{
	if (ob->query("family/family_name") == "华山派" ||
	    ob->query("family/family_name") == "华山剑宗")
	{
		command("say 走开！华山的弟子我一概不见。");
		return;
	}

	command("say 我不收徒，你另请高明吧。");
}

int check_skill(string skill)
{
	if (skill != "sword" && skill != "lonely-sword")
	{
		command("say 嘿嘿，我只懂剑法，你想学就学，不想学就算了。");
		return -1;
	}
	return 1;
}

int recognize_apprentice(object ob, string skill)
{
	if (ob->query("can_learn/feng/lonely-sword"))
		return check_skill(skill);

	if (ob->query("can_learn/feng/sword") &&
	    skill != "lonely-sword")
	{
		if (skill == "sword") return 1;
		command("say 教你点基本剑法是看得起你，少跟我罗嗦！");
		return -1;
	}
/*
	if (ob->query_temp("have_asked_feng"))
	{
		command("say 还不快滚！");
		return -1;
	}
*/
	if (ob->query("character") == "阴险奸诈" ||
	    ob->query("character") == "心狠手辣")
	{
		command("heng");
		command("say 不想死的就给我滚！");
		ob->set_temp("have_asked_feng", 1);
		return -1;
	}

	if (ob->query("shen") < -1000)
	{
		command("say 好一个邪魔外道，我风清扬没兴趣和你这"
			"种人打交道，你走吧。");
		ob->set_temp("have_asked_feng", 1);
		return -1;
	}

	if (ob->query("shen") > 10000)
	{
		command("haha");
		command("say 大侠你自己上路吧，老朽我不识时务，高攀"
			"不上你，得罪了。");
		ob->set_temp("have_asked_feng", 1);
		return -1;
	}

	if (ob->query("int") < 24)
	{
		message_vision("$N冷笑了两声。\n", this_object());
		command("say 你这个呆头鹅，忒笨了点，走吧。");
		ob->set_temp("have_asked_feng", 1);
		return -1;
	}

	if (ob->query("int") < 30)
	{
		command("look " + ob->query("id"));
		command("say 你倒是不算笨，有点小聪明，不过... 嘿嘿，"
			"还是差得远啊。");
		ob->set_temp("have_asked_feng", 1);
		return -1;
	}

	if (ob->query_skill("sword", 1) < 60)
	{
		command("say 我倒是有心教你点东西，不过你的对剑法的理"
			"解也未免太差了。");
		return -1;
	}

	if (ob->query("int") < 34)
	{
		if (skill == "sword")
		{
			command("say 好吧，我就教你一点关于剑法的知识。");
			ob->set("can_learn/feng/sword", 1);
			return 1;
		}

		if (skill != "lonely-sword")
		{
			command("say 我只会剑法，要学其它的本事找别的师傅去吧！");
			return -1;
		}

		command("sigh");
		command("say 你这人算是聪明，可是我怎么觉得你还是差那"
			"么一点点呢？独孤九剑你不合适学。");
		return -1;
	}

	if (check_skill(skill) == -1)
		return -1;

	command("nod");
	command("say 虽然我不收徒，不过看你天资实在不错，就传你一点剑"
		"法吧。");
	command("say 我先传你总诀式，其他破剑式、破刀式、破枪式、破鞭式、破索式、破掌式、破"
		"箭式、破气式我随后一一分解与你听。");
	ob->set("can_learn/feng/lonely-sword", 1);
	return 1;
}

int accept_ask(object me, string topic)
{
	string *learned, *try_to;

	if (! topic || undefinedp(try_to = po_type[topic]))
		return 0;

	if (! (int)me->query_skill("lonely-sword", 1))
	{
		command("say 你会"ZJURL("cmds:learn feng lonely-sword 100")"独孤九剑"NOR"么？就向我问这个？");
		return 1;
	}

	learned = me->query("can_perform/lonely-sword");
	if (! arrayp(learned))
		learned = ({ });
	if (member_array(try_to[0], learned) != -1)
	{
		command("say 你可以向我请教这几个招式：
"ZJURL("cmds:ask feng qingyang about 破剑式")"破剑式"NOR"、"ZJURL("cmds:ask feng qingyang about 破刀式")"破刀式"NOR"、"ZJURL("cmds:ask feng qingyang about 破枪式")"破枪式"NOR"、"ZJURL("cmds:ask feng qingyang about 破鞭式")"破鞭式"NOR"、
"ZJURL("cmds:ask feng qingyang about 破索式")"破索式"NOR"、"ZJURL("cmds:ask feng qingyang about 破掌式")"破掌式"NOR"、"ZJURL("cmds:ask feng qingyang about 破箭式")"破箭式"NOR"、"ZJURL("cmds:ask feng qingyang about 破气式")"破气式"NOR"，
这个" + topic + "你不是已经用了么？还来问我干什么？");
		return 1;
	}

	command("say 好吧，" + topic + "的要诀你要听仔细了。");
	if (me->query("potential") - me->query("learned_points") < 10)
	{
		me->set("learned_points", me->query("potential"));
		tell_object(me, "你觉得有点迷糊，没听太懂，看来是自己的潜能不够。\n");
		return 1;
	}

	me->add("learned_points", 10);
	if (random(2))
	{
		write("你听了一会儿，有了点心得。\n");
		return 1;
	}

	learned -= try_to;
	learned += try_to;
	me->set("can_perform/lonely-sword", learned);
	tell_object(me, HIG "你学会了" + topic + "。\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 360000);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
