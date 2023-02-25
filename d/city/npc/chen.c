// chen.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
string do_answer();
void create()
{
	set_name("陈有德", ({ "chen youde", "chen" }));
	set("long", "陈有德是扬州武馆馆长。\n");
	set("gender", "男性");
	set("age", 45);
	set("icon","00723");
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("claw", 80);
	set_skill("hand", 80);
	set_skill("strike", 80);
	set_skill("finger", 80);
	set_skill("cuff", 80);
	set_skill("blade", 80);
	set_skill("club", 80);
	set_skill("staff", 80);
	set_skill("sword", 80);
	set_skill("throwing", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	 set("inquiry", ([
		"〖指南〗" : (: do_answer :),
	      
			]));
	set("vendor_goods", ({
		"/clone/book/basic-sword",
		"/clone/book/basic-blade",
		"/clone/book/basic-dagger",
		"/clone/book/basic-unarmed",
		"/clone/book/basic-dodge",
		"/clone/book/basic-parry",
		"/clone/book/basic-force",
		"/clone/book/basic-staff",
		"/clone/book/basic-whip",
       		"/clone/book/basic-club",
		"/clone/book/basic-throwing",
	}));
	
	setup();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int accept_object(object who, object ob)
{
	if (who->query("combat_exp") >= 350000)
	{
		message_vision("陈有德望着$N说：你的武功应该"
			       "历练江湖才能再长进，不能埋没在这里了。\n", who);
		return 0;
	}

	if (ob->query("money_id") && ob->value() >= 500)
	{
		who->set_temp("marks/yangzhou_paied",1);
		message_vision("陈有德对$N说：好！这位" + RANK_D->query_respect(who) + 
			       "想学什么呢？\n" , who);
		return 1;
	} else
		message_vision("陈有德皱眉对$N说：钱我不在乎"
			       "。可你也给的也太少了点儿吧？\n", who);
	return 0;
}

int recognize_apprentice(object ob)
{
	if (! (int)ob->query_temp("marks/yangzhou_paied") == 1)
		return 0;

	return 1;
}
string do_answer()
{
  string str="";    
write(HIY"「扬州武馆」"NOR"所传授基本武功\n");
 printf(HIC"≡"HIY"─────────────────────────────"HIC"≡"NOR"\n");
str+="  １）基本轻功 (dodge)	    ８）  基本拳法 (cuff) \n";
str+="  ２）基本内功 (force)	    ９）  基本刀法 (blade) \n";
str+="  ３）基本招架 (parry)	    １０）基本棒法 (stick) \n";
str+="  ４）基本爪法 (claw)	     １１）基本棍法 (club) \n";
str+="  ５）基本手法 (hand)	     １２）基本杖法 (staff) \n";
str+="  ６）基本掌法 (strike)	   １３）基本剑法 (sword) \n";
str+="  ７）基本指法 (finger)	   １４）基本暗器 (throwing) \n";
    write(str);
    write(HIG"\n  学习命令是: xue 师傅名 武功技能   <需要钱钱,至少5两> "NOR"\n");
 printf(HIC"≡"HIY"─────────────────────────────"HIC"≡"NOR"\n");

     return "你想要学些什么呢？";
}
/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
