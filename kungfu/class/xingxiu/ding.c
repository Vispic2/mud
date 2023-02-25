// ding.c 丁春秋

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_COAGENT;
inherit F_QUESTER;

#include "xingxiu.h"

string ask_me();
string ask_du1();
string ask_du2();
string ask_xiangliao();
mixed  ask_duo();

void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", "星宿老怪");
	set("long", @LONG
他就是星宿派开山祖师、令正派人士深恶痛绝的星宿老怪丁春秋。
可是他看起来形貌清奇，仙风道骨。
LONG );
	set("gender", "男性");
	set("age", 60);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 5400);
	set("max_jing", 2700);
	set("neili", 6300);
	set("max_neili", 6300);
	set("jiali", 100);
	set("combat_exp", 1850000);

	set_skill("force", 220);
	set_skill("huagong-dafa", 220);
	set_skill("guixi-gong", 200);
	set_skill("throwing", 210);
	set_skill("feixing-shu", 210);
	set_skill("dodge", 180);
	set_skill("zhaixinggong", 180);
	set_skill("strike", 185);
	set_skill("chousui-zhang", 185);
	set_skill("claw", 180);
	set_skill("sanyin-wugongzhao", 180);
	set_skill("whip", 180);
	set_skill("chanhun-suo", 180);
	set_skill("parry", 185);
	set_skill("staff", 190);
	set_skill("poison", 255);
	set_skill("tianshan-zhang", 190);
	set_skill("literate", 120);
	set_skill("medical", 265);
	set_skill("xingxiu-qishu", 265);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("whip", "chanhun-suo");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);
	set("xiangliao_count", random(10) + 5);

	set("inquiry", ([
		"毒经"     : (: ask_me :),
		"星宿毒经" : (: ask_me :),
		"碧磷针"   : (: ask_du1 :),
		"香料"     : (: ask_xiangliao :),
		"夺魂"     : (: ask_duo :),
		"夺魂绝迹" : (: ask_duo :),
		"绝招"     : (: ask_duo :),
		"三笑逍遥散" : (: ask_du2 :),
		"逍遥三笑散" : (: ask_du2 :),
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "staff.fugu" :),
		(: perform_action, "staff.xue" :),
		(: perform_action, "strike.biyan" :),
		(: perform_action, "strike.huolang" :),
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.huoyan" :),
		(: perform_action, "claw.zhua" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));

	create_family("星宿派", 1, "开山祖师");
	set("class", "taoist");

	set_temp("apply/damage", 180);
	set_temp("apply/armor", 400);
	set_temp("apply/attack", 250);
	set_temp("apply/dodge", 250);
	set_temp("apply/parry", 250);

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
}

void init()
{
	object me;

	me = this_player();

	if (! interactive(me))
		return;

	if (living(this_object()) && present("shenmu wangding", me))
	{
		command("say 好家伙，原来你偷了我的神木王鼎！受死吧！");
		kill_ob(me);
		return;
	}

	add_action("do_flatter", "flatter");
}

void attempt_apprentice(object me)
{

	if( me->query("family/family_name") &&
	    me->query("family/family_name") != "星宿派" )
	{
		command("say 你已有名师指点，为何还要来本派"
			"莫非你要判师不成？");
		return 0;
	}
	if ((int)me->query("shen") > -1000)
	{
		command("say 老仙我越看你越象白道派来卧底的。");
		return;
	}

	if ((int)me->query("combat_exp") < 100000)
	{
		command("say 你这点微末道行如何能学到老仙的神妙功夫。");
		return;
	}

	if ((int)me->query_skill("poison", 1) < 100)
	{
		command("say 你毒技都没学明白，还有脸来见我？");
		return;
	}

	if( me->query_temp("pending/flatter"))
	{
		command("say 你如此不把老仙放在眼里，老仙怎会收你？");
		return;
	} else
	{
		command("say 我星宿老仙比起古往今来的圣人怎么样啊？");
		message_vision("星宿老怪微闭双眼，手捻长须，一副等人拍马(flatter)的样子。\n",
		this_player());
		me->set_temp("pending/flatter", 1);
	}
}

int do_flatter(string arg)
{
	if (! this_player()->query_temp("pending/flatter"))
		return 0;

	if (! arg) return notify_fail("你说老仙什么？\n");
	this_player()->set_temp("pending/flatter", 0);
	message_vision("$N大声说道：" + arg + "\n", this_player());
	if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0
	 || strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今无比") >=0 )) {
		command("smile");
		command("say 这还差不多。\n");
	//	welcome(this_player());
		command("recruit " + this_player()->query("id"));
	} else
	{
		command("say 你如此不把我放在眼里，我怎能收你？");
	}
	return 1;
}

// 星宿老仙，德配天地，威震寰宇，古今无比
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "好吧，这本「星宿毒经」你拿回去好好钻研。";
}

string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison", 1) < 50)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("zhen_count") < 1)
		return "你来晚了，碧磷针都发完了。";
	add("zhen_count", -1);
	ob = new("/d/xingxiu/obj/bilinzhen");
	ob->move(this_player());
	return "好吧，那你就先用这些针吧。";
}

string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query_skill("poison", 1)<100)
		return "你的毒技火候未到，用不了这种东西。";
	if (query("san_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	add("san_count", -1);
	ob = new("/d/xingxiu/obj/sanxiaosan");
	ob->move(this_player());
	return "好吧，这包毒药你拿回去善加利用吧。";
}

string ask_xiangliao()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (is_busy() || is_fighting())
		return "等会儿，没看我这正忙着呢么？";
	if (this_player()->query_skill("poison", 1) < 40)
		return "你的毒技火候太差，还是练练再说吧！";
	if (query("xiangliao_count") < 1)
		return "你来晚了，现在没什么剩下的香料了，你还是去仓库找找看吧！";
	add("xiangliao_count", -1);
	ob = new("/clone/misc/xiangliao");
	ob->set_amount(random(50) + 100);
	ob->move(this_player());
	start_busy(2);
	return "好吧，这些香料你拿去慢慢用吧。";
}

void reset()
{
	set("xiangliao_count", random(10) + 5);
}

void unconcious()
{
	die();
}

mixed ask_duo()
{
	object me;
	int n;
	string msg;

	me = this_player();
	if (me->query("family/family_name") != query("family/family_name"))
		return "别惹老仙我，滚开。";

	if (me->query("can_perform/chanhun-suo/duo"))
		return "你这废物快去练功去，不要忘了老仙我是怎么教育你们的。";

	if (me->query_skill("chanhun-suo", 1) < 100)
		return "你把缠魂索法好好给我练好，别给老仙我丢脸。";

	message_sort("$N点点头，对$n道：“要想发挥这照的妙处，嘿嘿，你得"
		     "有天蚕丝编就的丝索。”说罢，$N掏出一根细细的长丝，"
		     "又道：“看到了？其中的奥妙可全在这里，如此如此，这"
		     "般这般。”$n拼命点头，媚笑道：“师傅真是古往今来天"
		     "下第一，招招都是出人意表。”\n", this_object(), me);
	me->set("can_perform/chanhun-suo/duo", 1);
	tell_object(me, HIG "你通晓了夺魂绝迹的奥妙。"NOR"\n");
	if (me->can_improve_skill("whip"))
		me->improve_skill("whip", 90000);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
