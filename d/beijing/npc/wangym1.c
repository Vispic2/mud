// zhang.c 张天师

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("立德", ({ "li de"}));
	set("age", 40);
	set("gender", "男性");
	set("long", "这是大儒王阳明魂魄幻化的第一不朽。\n");
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 35);
	set("con", 38);
	set("dex", 31);
	set("chongmaidan", 1);
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("max_neili", 8000);
	set("yes_give",1);

//	set_skill("magic", 200);
//	set_skill("taoism", 350);

	set("inquiry", ([
		"极品冲脉丹兑换" : "绑定的下品可以兑换成绑定的极品冲脉丹。5:1不找零。",
		]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}


int accept_object(object who, object ob)
{
	object ob1;
	int i;
	
	if (! ob->query("needle/level"))
	{
		command("say 这玩艺我可没啥兴趣！");
		return 0;
	}
	if (ob->query("needle/level")!=5)
	{
		command("say 这玩艺档次太高我不要！");
		return 0;
	}
	
		if (ob->query_amount()<10)
	{
		command("say 十颗都不到，你好意思拿出手！");
		return 0;
	}
	
	i=ob->query_amount()*ob->query("needle/level")/5/5;
	if(objectp(ob1=present("chongmai dan4-b",who)))
	{
		ob1->add_amount(i);
	}
		else
	{
	ob1=new("/clone/shizhe/dan_chongmai4");
	ob1->set_amount(i);
	ob1->move(who);
	}
	write("立德收下了你的"+ob->query_amount()+"个"+ob->name()+"然后给你了"+i+"个"+ob1->name()+"。\n");	
	ob1->move(who);
	destruct(ob);
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
