// chenhu.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("陈浒", ({ "chen hu", "chen" }));
	set("title","金牛武馆教习");
	set("long", "陈老爷子在武馆也忙了几十年了，仍勇于提携后生。\n");
	set("gender", "男性");
	set("age", 65);
	 set("icon","00723");
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("cuff", 80);
	set_skill("staff", 80);
	set_skill("club", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();
}

int recognize_apprentice(object ob)
{
	if (! (int)ob->query_temp("marks/jinniu_paied") == 1) return 0;
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
