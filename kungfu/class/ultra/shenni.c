// shenni 南海神尼

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "宗师"
#define OPINION_TYPE    HIY "内家功夫" NOR 
#define MY_OPINION      "force"

string  *my_opinions = ({ "force" });

// 该头文件必须在这里嵌入
#include "ultra.h"

void create()
{
	set_name("南海神尼", ({ "nanhai shenni", "shenni", "nanhai" }) );
	set("title", HIG "大宗师" NOR);
	set("gender", "女性");
	set("age", 91);
	set("long", "这是一位青衫老尼，看不出有什么不同。\n");
	set("attitude", "peaceful");
	set("class", "bonze");
	set("str", 30);
	set("int", 37);
	set("con", 39);
	set("dex", 33);

	set("max_qi", 9999);
	set("max_jing", 9999);
	set("neili", 9999);
	set("max_neili", 9999);
	set("jiali", 70);

	set("combat_exp", 50000000);

	set("inquiry", ([
		"弹指神通" : "那是我碧海神功关于指法方面的变化，当年我到东海，曾经传授给一人。",
		"评价"     : (: ask_opinion :),
		"武学修养" : "好好提高自己的武学修养(martial-cognize)，到时候什么武功都如小儿科！",
	]));

	set_skill("strike", 500);
	set_skill("finger", 500);
	set_skill("parry", 500);
	set_skill("dodge", 500);
	set_skill("force", 500);
	set_skill("staff", 500);
	set_skill("bluesea-force", 500);
	set_skill("martial-cognize", 500);
	set_skill("literate", 220);

	map_skill("parry", "bluesea-force");
	map_skill("force", "bluesea-force");
	map_skill("dodge", "bluesea-force");
	map_skill("finger", "bluesea-force");
	map_skill("strike", "bluesea-force");
	map_skill("staff", "bluesea-force");

	prepare_skill("finger", "bluesea-force");
	prepare_skill("strike", "bluesea-force");

	set("opinion/ultra",  1);
	set("opinion/master", 1);

	set("rank_info/self", "本座");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
		(: exert_function, "recover" :),
		(: perform_action, "staff.zhan" :),
		(: perform_action, "staff.lu" :),
		(: perform_action, "staff.jue" :),
		(: perform_action, "staff.zhu" :),
		(: perform_action, "staff.nan" :),
		(: perform_action, "strike.xuan" :),
		(: perform_action, "strike.bo" :),
	}));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/zhubang")->wield();

	set("startroom", "/d/xiakedao/zhuwu2");
	check_clone();
}

void init()
{
	object me;

	if (! interactive(me = this_player()))
		return;

	me->delete_temp("want_opinion");
	if (ultrap(me))
		message_vision("$N眉角微微一动。\n", this_object(), me);
}

mixed ask_opinion()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("combat_exp") < 200000)
		return "哼！你这点武功也出来丢人现眼？";

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
		return "不必了，你内功方面的修为已经称得上是宗师了！要是和贫尼过上几招也不错。";

	if (is_fighting(me))
		return "哈哈，废什么话，打赢了我，你自己给自己评价吧！";

	if (me->is_fighting())
		return "你等会儿吧！待我赶走他们。";

	if (objectp(ob = query_temp("opinion")))
	{
		if (ob == me)
		{
			command("say 你着什么急？不要烦我。");
			return 1;
		}

		message_vision("$N颇为恼怒的对$n道：“没看我正忙着吗？”\n",this_object(), me);
		return 1;
	}

	switch(me->query_temp("want_opinion/shenni"))
	{
	case 0:
		command("say 好吧，咱们过一招，比拚一下内力。");
		break;
	case 1:
		command("say 你准备好没有？好了就来吧。");
		break;
	case 2:
		message_vision(CYN "$N" CYN "皱眉对$n" CYN
			       "道：“我看你这人是够罗嗦的。”"NOR"\n",
			       this_object(), me);
		break;
	case 3:
		command("say 快给我闭上你的鸟嘴！");
		return 1;
	}

	me->add_temp("want_opinion/shenni", 1);
	return 1;
}

int calc_level(object me, string skill)
{
	int lvl;
	string sp;

	lvl = me->query_skill(skill, 1) / 2;
	sp = me->query_skill_mapped(skill);
	if (! sp) return lvl;

	lvl += me->query_skill(sp, 1);
	if (me->query("max_neili") > 4000) lvl += 20;
	return lvl;
}

void do_congration(object me)
{
	command("chat 不错，不错，真是不错。");
}

int accept_hit(object me)
{
	command("heng");
	command("say 好你个" + RANK_D->query_rude(me) + "，你找死找到这来了！");
	kill_ob(me);
	return 1;
}

int accept_fight(object me)
{
	object weapon;

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
	{
		message_vision("$N对$n道：“很好，你也算是宗师高手了，"
			       "来吧！咱们比划一下！”\n",
			       this_object(), me);
		return 1;
	}

	if (! me->query_temp("want_opinion/shenni"))
	{
		command("say 你干什么要和我动手？");
		return 0;
	}

	command("look " + me->query("id"));

	COMBAT_D->do_attack(this_object(), me, 0);

	if (me->query("qi") <= 0)
	{
		message_vision("\n$N摇摇头对$n道：“你现在的武功"
			       "还差得远，连我一招都接不住！”\n",
			       this_object(), me);
		return notify_fail("看来要好好的修炼功夫了。\n");
	}

	message_combatd("$N右掌伸出，正和$n手掌相对，两人同时运起内力，"
		       "不一会儿只见二人头上生起腾腾雾气。忽然$N手掌"
		       "一撤、收回功力，没有一点阻滞，不禁让$n大为愕然。\n",
		       this_object(), me);
	if (me->query("neili") < 3000)
	{
		message_vision("$N摇摇头对$n道：“适才你内力不足，我难"
			       "以衡量，待你将内力修炼好了再来吧！”\n",
			       this_object(), me);
		return notify_fail("看来还是回去锻炼一下内力吧！\n");
	}
	me->set("neili", 0);
	

	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	me->delete_temp("want_opinion");
	message_vision("\n$N一摆手道：“好了，待我想想。”\n",
		       this_object(), me);
	return notify_fail("看来不能心急，还得等一会儿。\n");
}

int accept_kill(object me)
{
	if (me->query("combat_exp") < 500000)
	{
		message_vision("$N大怒道：“无名小辈捣什么"
			       "乱？给我滚！”说罢一掌把$n劈倒在地。\n",
			       this_object(), me);
		me->unconcious();
		return -1;
	}
	command("sigh");
	command("say 很好！近年还真没有遇到什么敢和我较量的高手！");
	return 1;
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("character") != "心狠手辣")
	{
		command("say 你这人生性不够毒辣，下不了狠心，"
			"我没有兴趣教你！");
		return -1;
	}

	if (skill == "martial-cognize")
		return 1;

	if (! ultrap(me))
	{
		command("say 想学我的碧海神功？你还不够资格，"
			"等你成了大宗师再说吧！");
		return -1;
	}

	if (me->query_skill(skill, 1) >= 180)
	{
		command("say 够了！我就教你到这里吧，武功还是"
			"要靠自己多研究才是！");
		return -1;
	}

	if (skill != "bluesea-force")
		return 1;

	if (me->query_temp("can_learn/shenni/bluesea-force"))
		return 1;

	me->set_temp("can_learn/dugu/bluesea-force", 1);
	command("nod");
	command("say 不错，我教你我的绝学碧海神功，能不能学，"
		"就看你的造化了！");
	return 1;
}

void unconcious()
{
	message("vision", "\n"HIR + name() + "脸色一变，吐了一口鲜"
		"血，身形一闪，消逝不见。"NOR"\n", environment());
	command("chat 罢！罢！罢！贫尼去也！");
	destruct(this_object());
}

void die()
{
	message("vision", "\n"HIR + name() + "大叫一声，狂吐了一口鲜"
		"血，身形一闪，就此不见。"NOR"\n", environment());
	command("chat 贫尼去也！");
	destruct(this_object());
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
