// jinlin.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("金临", ({ "jinlin", "jin" }) );
	set("gender", "男性" );
	set("age", 18);
	set("long", "这是一位垂髫童子，是鲁班手下五行童子之一。\n");
	set("title", HIC "南方丙丁" NOR CYN "◎" HIR "火" NOR);
	set("nickname", HIY "五行童子" NOR);
	set("attitude", "friendly");
	set("inquiry", ([
		"#3-宝石转换" : "把你不满意的五方上帝宝石给我，我随机给你换一颗。一次转换消耗一百两黄金，直接钱庄划账。如果转换的还是你原有的宝石，那只能说明你点子背，麻烦多来几次。",
		]));
	set_skill("certosina", 500);	    // 镶嵌技艺		
	setup();
}



int accept_ask()
{
	message_vision("$N半答不理的说：有啥事问我师傅去，别烦我。\n",
		       this_object());
	return 1;
}

int accept_object(object who, object ob)
{
	int i;
	
	if (ob->query("id")!="god eyes")
	{
		command("say 这玩艺我可没啥兴趣！");
		return 0;
	}

	
	if (who->query("balance")<1000000)
	{
		command("say 钱庄余额不足！");
		return 0;
	}
	
	if (ob->query_amount()>1)
	{
		command("say 一颗一颗来，别着急！");
		return 0;
	}
	
	
	write("金临收下了你的1颗"+ob->name()+"");	
	destruct(ob);
	
	ob=new("/clone/gift/god_eyes"+random(5)+"");	
	ob->set_amount(1);
	ob->move(who);
	who->add("balance",-1000000);
	write("然后给你了1颗"+ob->name()+",并随后从你账上划去100两黄金。\n");	
	
	return 1;
}

int recognize_apprentice(object ob)
{
	return 1;
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
