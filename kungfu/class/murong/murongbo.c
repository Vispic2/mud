// murongbo.c 慕容博

#include <ansi.h>
#include "murong.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;
inherit F_COAGENT;

mixed ask_me();
mixed try_learn_sk();

string ask_book1();
string ask_book2();
mixed  ask_martial();

void create()
{
	set_name("慕容博", ({ "murong bo", "murong", "bo" }));
	set("long", @LONG
他是姑苏慕容的传人，可以说是自慕容龙城以下武功最为杰出
之人。不仅能贯通天下百家之长，更是深为精通慕容家绝技。
LONG );
	set("nickname", HIM "以彼之道 还施彼身" NOR);
	set("gender", "男性");
	set("age", 54);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 31);
	set("int", 37);
	set("con", 34);
	set("dex", 33);

	set("qi", 5700);
	set("max_qi", 5700);
	set("jing", 2800);
	set("max_jing", 2800);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jiali", 125);

	set("combat_exp", 2650000);

	// base skill
	set_skill("force", 270);
	set_skill("literate", 220);
	set_skill("unarmed", 260);
	set_skill("cuff", 270);
	set_skill("finger", 270);
	set_skill("strike", 260);
	set_skill("hand", 260);
	set_skill("claw", 260);
	set_skill("club", 260);
	set_skill("sword", 270);
	set_skill("blade", 260);
	set_skill("staff", 260);
	set_skill("dodge", 260);
	set_skill("parry", 270);

	// shaolin skill. No teach
	set_skill("banruo-zhang", 250);
	set_skill("cibei-dao", 250);
	set_skill("damo-jian", 250);
	set_skill("fengyun-shou", 250);
	set_skill("fumo-jian", 250);
	set_skill("hunyuan-yiqi", 250);
	set_skill("shaolin-xinfa", 250);
	set_skill("jingang-quan", 250);
	set_skill("longzhua-gong", 250);
	set_skill("luohan-quan", 250);
	set_skill("nianhua-zhi", 250);
	set_skill("pudu-zhang", 250);
	set_skill("qianye-shou", 250);
	set_skill("sanhua-zhang", 250);
	set_skill("riyue-bian", 250);
	set_skill("shaolin-shenfa", 250);
	set_skill("weituo-gun", 250);
	set_skill("wuchang-zhang", 250);
	set_skill("xiuluo-dao", 250);
	set_skill("yingzhua-gong", 250);
	set_skill("yizhi-chan", 250);
	set_skill("zui-gun", 250);

	// murong skill
	set_skill("zihui-xinfa", 270);
	set_skill("douzhuan-xingyi", 270);
	set_skill("beidou-xianzong", 270);
	set_skill("canhe-zhi", 270);
	set_skill("qixing-quan", 270);
	set_skill("murong-sword", 270);
	set_skill("martial-cognize", 200);

	map_skill("force", "zihui-xinfa");
	map_skill("dodge", "beidou-xianzong");
	map_skill("cuff",  "qixing-quan");
	map_skill("parry", "douzhuan-xingyi");
	map_skill("finger", "canhe-zhi");
	map_skill("sword", "murong-sword");

	prepare_skill("finger", "canhe-zhi");
	prepare_skill("cuff", "qixing-quan");

	set("no_teach", ([
		"banruo-zhang"  : (: try_learn_sk :),
		"cibei-dao"     : (: try_learn_sk :),
		"damo-jian"     : (: try_learn_sk :),
		"fengyun-shou"  : (: try_learn_sk :),
		"fumo-jian"     : (: try_learn_sk :),
		"hunyuan-yiqi"  : (: try_learn_sk :),
		"shaolin-xinfa" : (: try_learn_sk :),
		"jingang-quan"  : (: try_learn_sk :),
		"longzhua-gong" : (: try_learn_sk :),
		"luohan-quan"   : (: try_learn_sk :),
		"nianhua-zhi"   : (: try_learn_sk :),
		"pudu-zhang"    : (: try_learn_sk :),
		"qianye-shou"   : (: try_learn_sk :),
		"sanhua-zhang"  : (: try_learn_sk :),
		"riyue-bian"    : (: try_learn_sk :),
		"shaolin-shenfa": (: try_learn_sk :),
		"weituo-gun"    : (: try_learn_sk :),
		"wuchang-zhang" : (: try_learn_sk :),
		"xiuluo-dao"    : (: try_learn_sk :),
		"yingzhua-gong" : (: try_learn_sk :),
		"yizhi-chan"    : (: try_learn_sk :),
		"zui-gun"       : (: try_learn_sk :),
	]));

	set("inquiry", ([
		"斗转星移" : (: ask_me :),
		"紫徽心法" : (: ask_book1 :),
		"斗转星移" : (: ask_book2 :),
		"武学修养" : (: ask_martial :),
	]));

	set("zihui_count", 1);
	set("douzhuan_count", 1);

	create_family("慕容世家", 15, "传人");
	set("chat_chance", 1);
	set("chat_msg", ({
		"慕容博长叹道：大燕... 大燕啊！\n",
	}));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "finger.ci" :),
		(: perform_action, "finger.lian" :),
		(: perform_action, "finger.zhi" :),
	}));

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
	if(! permit_recruit(ob))
		return;

	if((int)ob->query("combat_exp") < 200000)
	{
		if (random(2))
			command("smile");
		else
			command("pat " + ob->query("id"));

		command("say 你的经验还不够，先和我儿慕容复学习吧！");
		return ;
	}

	command("haha");
	command("pat " + ob->query("id"));
	command("recruit " + ob->query("id"));
	message_vision("慕容博大喜：我们慕容家真是英才迭出，复国有望啊！\n",
		       this_object());
	return;
}

mixed try_learn_sk()
{
	object me;

	me = this_player();
	if (me->query_temp("has_asked/murongbo"))
		return "你还是安心学本门功夫吧。";

	command("shake");
	command("say 据说少林的武功学了对身体有害，你就不要学了。");
	me->set_temp("has_asked/murongbo", 1);
	return -1;
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/douzhuan-xingyi/yi"))
		return "你还不快去练功去？光复大燕不是靠嘴上说的！";

	if (me->query("family/family_name") != query("family/family_name"))
		return "你是什么人？有何居心？";

	if (me->query_skill("douzhuan-xingyi", 1) < 100)
		return "斗转星移是我们慕容家的绝学，你练好没有？";

	message_vision(HIY "$n" HIY "看看$N" HIY "，示意$N"
		       HIY "攻自己一招，$N" HIY "疑疑惑惑的"
		       "拍出一掌，只见$n" HIY "伸手轻轻一擦，"
		       HIY "$N的招式方向\n忽然大变，反而攻向自"
		       "己！蓬的一声这一掌结结实实的打在了$P"
		       HIY "自己的肩头！"NOR"\n",
		       me, this_object());
	command("nod");
	command("say 这其中的奥妙乃是用巧妙的招式配合我"
		"慕容家的紫徽心法，你要好好体会，去吧！");
	tell_object(me, HIG "你学会了斗转星移。"NOR"\n");
	if (me->can_improve_skill("douzhuan-xingyi"))
		me->improve_skill("douzhuan-xingyi", 90000);
	if (me->can_improve_skill("zihui-xinfa"))
		me->improve_skill("zihui-xinfa", 90000);
	me->set("can_perform/douzhuan-xingyi/yi", 1);
	return 1;
}

string ask_book1()
{
	mapping fam; 
	object ob;
	object me;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) + 
		       "与我慕容家素无来往，不知此话从何谈起？";

	if (me->query_skill("zihui-xinfa", 1) < 100)
		return "你的紫徽心法水平还不够，还用不着这本秘籍。";

	if (query("zihui_count") < 1)
		return "你来晚了，紫徽秘籍我已经借出去了。";

	add("zihui_count", -1);
	ob = new("/clone/book/zihui-book");
	ob->move(me, 1);
	return "好吧，这本紫徽心法你拿去好好研读！";
}

string ask_book2()
{
	object ob;
	object me;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(this_player()) + 
		       "与我慕容家素无来往，不知此话从何谈起？";

	if (me->query_skill("douzhuan-xingyi", 1) < 100)
		return "你的斗转星移练的还不到家，我还不能给你这本秘籍。";

	if (query("douzhuan_count") < 1)
		return "你来晚了，秘籍我已经借出去了。";

	add("douzhuan_count", -1);
	ob = new("/clone/book/douzhuan-book");
	ob->move(me, 1);
	return "这本斗转星移你可以收好了。";
}

mixed ask_martial()
{
	object ob;
	object me;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return RANK_D->query_respect(me) +
		       "，武道漫漫，自己要勤加修炼啊！";

	if (me->query("combat_exp") < 200000)
		return "你这点武功也来向我求教武学奥妙？好好给我练功去！";

	if (me->query_skill("martial-cognize", 1) < 50)
		return "你毫无武学修养根基，我如何与你谈其中奥妙？";

	if (me->query_skill("martial-cognize", 1) >= 200)
		return "你武学了解得已经不少了，我是没什么好再教你的了。";

	if (me->query_temp("last_ask/murongbo/martial") + 240 > time())
		return "改日再谈吧，今天你要多想想，好好体会体会。";

	message_vision("$N看看$n，道：“好吧，我就与你谈谈我慕容家在武学方面的心得。”\n",
		       this_object(), me);
	if (me->query("potential") - me->query("learned_points") < 100)
	{
		tell_object(me, "你听得迷迷糊糊的，没听出个所以然，看来是潜能不够。\n");
		return 1;
	}

	me->add("learned_points", 100);
	tell_object(me, HIG "你听的心中豁然开朗，通晓了不少武学的奥妙。"NOR"\n");
	me->set_temp("last_ask/murongbo/martial", time());
	me->improve_skill("martial-cognize", 2000 + random(1000));
	return 1;
}

void reset()
{
	set("zihui_count", 1);
	set("douzhuan_count", 1);
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
