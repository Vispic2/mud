// zhang.c 张天师

#include <ansi.h>

inherit NPC;
string ask_me();
//#include "/kungfu/skill/xuewei.c"//新加
void create()
{
	set_name("王阳明", ({ "wang yangming", "wang" }));
	set("age", 58);
	set("title", HIR"真三不朽"NOR);
	set("gender", "男性");
	set("long", "这是传说中的”三不朽“立德立言立功占全了的五百年来第一人大儒王阳明。\n");
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 35);
	set("con", 38);
	set("dex", 31);
	set("per", 71);
	set("yes_give",1);
	set("chongmaidan", 1);
	//set("needle/level",1);
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("max_neili", 8000);

	set_skill("magic", 200);
	set_skill("taoism", 350);

	set("inquiry", ([
		"#3-冲脉丹兑换" : "绑定的极冲上冲中冲全部兑换成绑定的下冲。按照比例童叟无欺。",
		//"#2-龙元兑换" : ""HIR"200片龙元碎片兑换完整龙元一枚，直接给我就行。"NOR"",
		//"#1-服用凤血" : (: ask_me :),
		]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	 object ob;
        ::init();
	remove_call_out ("says");
	call_out("says", 5+random(5), this_object());
	add_action("do_decidea", "decidea");
}


int accept_object(object who, object ob)
{
	object ob1;
	int i;
	//冲脉丹和龙元兑换
	if (! ob->query("needle/level"))
	{
		command("say 这玩艺我可没啥兴趣！");
		return 0;
	}
	
	if(ob->query("needle/level"))
	{
		if (ob->query("needle/level")<10)
		{
			command("say 这玩艺档次太低！");
			return 0;
		}
	
		i=ob->query_amount()*ob->query("needle/level")/5;
		if(objectp(ob1=present("chongmai dan1-b",who)))
		{
			ob1->add_amount(i);
		}
		else
		{
			ob1=new("/clone/shizhe/dan_chongmai1");
			ob1->set_amount(i);
			ob1->move(who);
		}
		write("王阳明收下了你的"+ob->query_amount()+"个"+ob->name()+"然后给你了"+i+"个"+ob1->name()+"。\n");	
		ob1->move(who);
		destruct(ob);
	}
	
	
	return 1;
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
