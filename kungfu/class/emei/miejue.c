// miejue.c 灭绝师太
// Modified by That Oct.1997

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

#include <ansi.h>
#include "emei.h"

string ask_for_quit();
mixed ask_hui();

mixed ask_skill1();
mixed ask_skill2();

void create()
{
	set_name("灭绝师太", ({ "miejue shitai","miejue","shitai"}));
	set("long", "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。\n");
	set("gender", "女性");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("no_get", 1);
	set("class", "bonze");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
	}) );
	set("inquiry",([
		"剃度"  : "要剃度找静玄。",
		"出家"  : "要剃度找静玄。",
		"还俗"  : (: ask_for_quit :),
		"绝招"  : (: ask_hui :),
		"绝技"  : (: ask_hui :),
		"回风拂柳" : (: ask_hui :),
		"云海明灯" : (: ask_skill1 :),
		"佛光普照" : (: ask_skill2 :),
	]));

	set("str", 29);
	set("int", 35);
	set("con", 31);
	set("dex", 30);

	set("max_qi", 4500);
	set("max_jing", 2200);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jingli", 1200);
	set("max_jingli", 1200);

	set("combat_exp", 1850000);
	set_skill("persuading", 160);
	set_skill("throwing", 210);
	set_skill("force", 220);
	set_skill("dodge", 200);
	set_skill("finger", 190);
	set_skill("parry", 220);
	set_skill("strike", 190);
	set_skill("sword", 220);
	set_skill("blade", 200);
	set_skill("literate", 120);
	set_skill("mahayana", 220);
	set_skill("buddhism", 210);
	set_skill("jinding-zhang", 190);
	set_skill("tiangang-zhi", 190);
	set_skill("huifeng-jian", 220);
	set_skill("yanxing-dao", 200);
	set_skill("zhutian-bu", 200);
	set_skill("emei-xinfa", 220);
	set_skill("linji-zhuang", 220);
	set_skill("piaoxue-zhang", 220);

	map_skill("force", "linji-zhuang");
	map_skill("finger", "tiangang-zhi");
	map_skill("dodge", "zhutian-bu");
	map_skill("strike", "jinding-zhang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("parry", "huifeng-jian");

	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");

	create_family("峨嵋派", 3, "掌门人");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
		(: perform_action, "sword.hui" :),
		(: perform_action, "finger.lingkong" :),
		(: perform_action, "strike.bashi" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	setup();

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	string name;

	if (! permit_recruit(ob))
		return;

	if ((int)ob->query("shen") < 15000)
	{
		command("say " + RANK_D->query_respect(ob) +
			"，你行侠仗义之事做的太少！实在是太少！");
		return;
	}

	if ((int)ob->query_skill("mahayana", 1) < 100)
	{
		command("say 你大乘佛法的修为还不行，好好感悟感悟！");
		return;
	}

	if ((int)ob->query_skill("emei-xinfa",1) < 100)
	{
		command("say 怎么回事？本门内功心法你怎么学的？好好给我练功去！");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("say 以后你要像为师一样，把天下的恶人统统杀光！");
	command("recruit " + ob->query("id"));

	name = "静" + ob->name(1)[2..<1];
	ob->set_name(name);
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("family/family_name") == "峨嵋派" &&
	    skill == "mahayana")
		return 1;
	return 0;
	
}

string ask_for_quit()
{
	object me;
	me = this_player();

	if (me->query("family/family_name") != "峨嵋派")
		return "你是什么人？跑到这里来捣乱？\n";

	if( (string)me->query("class") != "bonze" )
		return "阿弥陀佛！你本是俗家人，何谈还俗？\n";

	me->set_temp("pending/quit_bonze", 1);
	command("heng");
	command("say 还俗？好！你滚出我们峨嵋派，找别人替你还俗去吧！\n");
	return "你好好的给我安心修炼，以后降妖除魔，别天天满脑子不正经。\n";
}

mixed ask_hui()
{
	object me;

	me = this_player();
	if (me->query("can_perform/huifeng-jian/hui"))
		return "你自己好好多练练，降妖除魔就靠你们这些人了！";

	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_rude(me) +
		       "是哪里来的？快给我滚开！";

	if (me->query_skill("linji-zhuang", 1) < 100)
		return "你的临济十二庄修行太浅，怎能使出这回风拂柳剑法中的精妙之处？";

	if (me->query_skill("huifeng-jian", 1) < 120)
		return "你回风拂柳剑法尚未修炼得精深，哪里能领会其中的微妙之处？";

	if (me->query("shen") < 30000)
		return "哼哼！你行侠仗义的事情做的还大大的不够！不够！";

	message_vision(HIY "$n" HIY "呆呆的望着天空，激动万分，"
		       "口中喃喃道：“我峨嵋派后继有人！后继有人！”\n"
		       "过了半晌，$n" HIY "才回过神来，"
		       HIY "在$N" HIY "耳边秘密的说了些什么。"NOR"\n",
		       me, this_object());
	command("say 听好了！以后对那些妖人不要手软，见一个杀一个，见两个杀一双！");
	tell_object(me, HIG "你学会了回风拂柳剑的绝技。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 160000);

	if (me->can_improve_skill("huifeng-jian"))
		me->improve_skill("huifeng-jian", 160000);
	if (me->can_improve_skill("huifeng-jian"))
		me->improve_skill("huifeng-jian", 160000);
	if (me->can_improve_skill("huifeng-jian"))
		me->improve_skill("huifeng-jian", 160000);
	if (me->can_improve_skill("huifeng-jian"))
		me->improve_skill("huifeng-jian", 160000);
	if (me->can_improve_skill("huifeng-jian"))
		me->improve_skill("huifeng-jian", 160000);

	me->set("can_perform/huifeng-jian/hui", 1);
	return 1;
}

mixed ask_skill1()
{
	object me;

	me = this_player();
	if (me->query("can_perform/piaoxue-zhang/yun"))
		return "这一招我不是已经传授予你了吗？还有什么不懂就自己下去练吧。";

	if (me->query("family/family_name") != query("family/family_name"))
		return "我与阁下素无来往，不知阁下打听这个干嘛？";

	if (me->query("family/master_id") != query("id"))
		return "只有我的弟子才能学习此招，你还是走吧。";

	if (me->query_skill("piaoxue-zhang", 1) < 1)
		return "你连飘雪穿云掌都没学，还谈什么绝招可言？";

	if (me->query_skill("force") < 200)
		return "你的内功修行太浅，尚且学不了这一招。";

	if (me->query("max_neili") < 2000)
		return "你的内力修行太浅，尚且学不了这一招。";

	if (me->query_skill("piaoxue-zhang", 1) < 150)
		return "你的飘雪穿云掌火候未到，尚且学不了这一招。";

	if (me->query("shen") < 40000)
		return "你行侠仗义的事情还做得不够，我暂时还不能传你此招。";

	message_sort(HIY "\n$n" HIY "微微一笑，对$N" HIY "说道：“既然你内"
		     "外功均已达至如此境界，也不枉了我平时的一翻栽培。今日"
		     "我便传你此招，希望日后能将我峨嵋派发扬光大。”说完，"
		     "$n" HIY "将$N" HIY "招至跟前，在$N" HIY "耳旁轻声细说"
		     "良久。"NOR"\n", me, this_object());

	command("nod");
	command("say 刚才我所说的你都记清了吗？记清了就下去练吧。");
	tell_object(me, HIC "你学会了「云海明灯」。"NOR"\n");

	if (me->can_improve_skill("strike"))
		me->improve_skill("strike", 1500000);
	if (me->can_improve_skill("piaoxue-zhang"))
		me->improve_skill("piaoxue-zhang", 1500000);
	me->improve_skill("martial-cognize", 1500000);
	me->set("can_perform/piaoxue-zhang/yun", 1);
	//me->add("gongxian", -1800);
	return 1;
}

mixed ask_skill2()
{
	object me;

	me = this_player();
	if (me->query("can_perform/piaoxue-zhang/zhao"))
		return "这一招我不是已经传授予你了吗？还有什么不懂就自己下去练吧。";

	if (me->query("family/family_name") != query("family/family_name"))
		return "我与阁下素无来往，不知阁下打听这个干嘛？";

	if (me->query("family/master_id") != query("id"))
		return "只有我的弟子才能学习此招，你还是走吧。";

	if (me->query_skill("piaoxue-zhang", 1) < 1)
		return "你连飘雪穿云掌都没学，还谈什么绝招可言？";

	if (me->query_skill("force") < 300)
		return "你的内功修行太浅，尚且学不了这一招。";

	if (me->query("max_neili") < 3500)
		return "你的内力修行太浅，尚且学不了这一招。";

	if (me->query_skill("piaoxue-zhang", 1) < 180)
		return "你的飘雪穿云掌火候未到，尚且学不了这一招。";

	if (me->query("shen") < 40000)
		return "你行侠仗义的事情还做得不够，我暂时还不能传你此招。";

	message_sort(HIY "\n$n" HIY "轻轻拍了拍$N" HIY "的头，说道：“好"
		     "吧，难得你如此有心，今日我就将此招演示一遍，可得看"
		     "好了！”话音刚落，只见$n" HIY "狂提内劲，周身骨骼无"
		     "不噼啪作响，面赤如血，煞是惊人。随即$n" HIY "一声暴"
		     "喝，双掌携着隐隐风雷之势猛力向前拍出，顿时只听“喀"
		     "嚓”一声巨响，前方崖边一颗碗口粗的松树应声而断，断"
		     "枝仍是余势未尽，向前又飞出数丈，这才跌落至山谷之中"
		     "。须臾，便闻山谷下回声四起，在峨嵋群山中回荡了好一"
		     "阵才消失殆尽。$n" HIY "微微一笑，长吁一口气，缓缓收"
		     "回内劲，朝$N" HIY "望去，见$N" HIY "早已看得目瞪口"
		     "呆。"NOR"\n", me, this_object());

	command("say 这招你下去后一定要勤加练习，才能发挥出它的威力。");
	tell_object(me, HIC "你学会了「佛光普照」。"NOR"\n");

	if (me->can_improve_skill("strike"))
		me->improve_skill("strike", 1500000);
	if (me->can_improve_skill("piaoxue-zhang"))
		me->improve_skill("piaoxue-zhang", 1500000);
	me->improve_skill("martial-cognize", 1500000);
	me->set("can_perform/piaoxue-zhang/zhao", 1);
	//me->add("gongxian", -2200);
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
