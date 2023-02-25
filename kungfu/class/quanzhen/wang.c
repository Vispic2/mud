// wang.c 王重阳
#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;

string ask_jiuyin();
string ask_duan();
mixed  ask_hua();
mixed  ask_hup();

void create()
{
	set_name("王重阳", ({"wang chongyang", "wang"}));
	set("gender", "男性");
	set("age", 66);
	set("class", "taoist");
	set("nickname",HIW"活死人"NOR);
	set("long", "他就是全真教的开山祖师、首代掌教王重阳王真人。他白须飘"
			"飘，宽袍缓袖，眉目清癯，颇有些仙风道骨的味道。他本来一"
			"腔热血欲报效国家力抗金兵，可惜朝廷腐败，于是心灰意冷，"
			"又从道德经中悟得了天地滋生的大道，手创全真教。");
	set("attitude", "peaceful");
	set("shen_type",1);

	set("str", 32);
	set("int", 35);
	set("con", 33);
	set("dex", 31);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.hua" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "strike.ju" :),
	}));

	set("qi", 6500);
	set("max_qi", 6500);
	set("jing", 3200);
	set("max_jing", 3200);
	set("neili", 7800);
	set("max_neili", 7800);
	set("jiali", 100);
	set("combat_exp", 2850000);

	set_skill("force", 280);
	set_skill("quanzhen-xinfa", 280);
	set_skill("xiantian-gong", 280);
	set_skill("sword", 260);
	set_skill("quanzhen-jian",260);
	set_skill("dodge", 260);
	set_skill("jinyan-gong", 260);
	set_skill("parry", 280);
	set_skill("jinguan-yusuo", 280);
	set_skill("strike", 260);
	set_skill("chongyang-shenzhang", 260);
	set_skill("haotian-zhang", 260);
	set_skill("literate", 200);
	set_skill("finger", 260);
	set_skill("taoism", 300);
	set_skill("finger", 260);
	set_skill("zhongnan-zhi", 260);
	set_skill("sun-finger", 260);
	set_skill("medical", 280);
	set_skill("liandan-shu", 280);

	map_skill("force", "xiantian-gong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "jinguan-yusuo");
	map_skill("finger","sun-finger");
	map_skill("strike", "haotian-zhang");

	prepare_skill("finger", "sun-finger");
	prepare_skill("strike", "haotian-zhang");

	set("no_teach/sun-finger", "一阳指是段家秘传，我不能教你。");

	create_family("全真教", 1, "掌教");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"九阴真经" : (: ask_jiuyin :),
		"段皇爷"   : (: ask_duan :),
		"五气朝元" : (: ask_hup :),
		"一气化三清": (: ask_hua :),
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.hua" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob))
		return;

	if (ob->query_int() < 35)
	{
		command("say 你的悟性还不够，还是先找我那几个徒弟学习吧。");
		return;
	}

	if ((int)ob->query_skill("quanzhen-xinfa", 1) < 100)
	{
		command("say 你的本门内功心法火候不足，只怕难以"
			"领略更高深的武功。");
		return;
	}

	if (ob->query("combat_exp") < 200000)
	{
		command("say 你的实战经验太差，看来难以领略更高深的武功。");
		return;
	}

	if ((int)ob->query("shen") < 100000)
	{
		command("say 行侠仗义是我辈学武人的宗旨，你多做些侠"
			"义之事，我方能收你为徒。\n");
		return;
	}
	command("say 好吧，以你资质，定可传我衣钵，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_jiuyin()
{
	int lvl_force;

	if (this_player()->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(this_player()) +
		"与本教毫无瓜葛，这话从何说起？";

	if ((lvl_force = this_player()->query_skill("force", 1)) < 50)
		return RANK_D->query_respect(this_player()) +
		"的基本内功火候如此之浅，强练真经上的上乘武功有害无益。";

	return "九阴真经是天下武学正宗，我已交给我师弟周伯通保管。";
}

string ask_duan()
{
	return "你问段皇爷做甚么，莫非想与他为难？\n"; 
}

mixed ask_hua()
{
	object me;

	me = this_player();
	if (me->query("can_perform/quanzhen-jian/hua"))
		return "好好练功去吧！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你还是入了我全真派再说吧！";

	if (me->query_skill("xiantian-gong", 1) < 100)
		return "使用一气化三清需要我先天功为基础，你先把基础打好再说。";

	if (me->query_skill("quanzhen-jian", 1) < 100)
		return "你的全真剑法还很不到家，先练好再说。";

	message_vision(HIC "$n" HIC "撕下一角布条，运起内力登时变"
		       "得如同坚铁，伸手刺处，变幻无方，宛若三把长"
		       "剑齐出，看得$N" HIC "目瞪口呆！"NOR"\n",
		       me, this_object());
	command("say 你可曾看出其中的奥秘？");
	tell_object(me, HIG "你通晓了一气化三清的奥妙。"NOR"\n");
	if (me->can_improve_skill("force"))
		me->improve_skill("force", 90000);
	me->set("can_perform/quanzhen-jian/hua", 1);
	me->set("neili", 0);
	return 1;
}

mixed ask_hup()
{
	object me;

	me = this_player();
	if (me->query("can_perform/xiantian-gong/hup"))
		return "你还是好好练功去吧！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你还是入了我全真派再说吧！";

	if (me->query_skill("xiantian-gong", 1) < 200)
		return "你还需要好好锻炼先天功，武道岂能一蹴而就？";

	message_sort("$N口中念念有词道：“听好了，敌强由他强，清风"
		     "拂山岗；敌横... ”$n疑惑道：“这个... 我听着"
		     "怎么有些耳熟？”$N不由得猛醒，忙道：“不好意"
		     "思，背成了九阳神功的口诀了。这个、这个”说着"
		     "从口袋里掏出一本破破烂烂的小册子，翻了半天，"
		     "指着其中一段对$n说道：“看着，是这段没错了。"
		     "”$n看了半天，默记在心中。$N道：“行啦！好好"
		     "练去吧！不要给我们全真教丢脸啊。”\n", this_object(), me);
	tell_object(me, HIG "你通晓了五气朝元的奥妙。"NOR"\n");
	if (me->can_improve_skill("force"))
		me->improve_skill("force", 90000);
	me->set("can_perform/xiantian-gong/hup", 1);
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
