// ZhouDian.c
// pal 1997.05.11

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
#include <ansi.h>
#include "tangzhu.h"

void create()
{
	set_name("周颠", ({ "zhou dian", "zhou", "dian", }));
	set("long",
	"他是一位疯疯颠颠的老者，身穿一件白布长袍。\n"
	"他总是慌慌张张的，先天下之急而急。\n"
	);

	set("title", HIG "明教" NOR "五散人");
	set("nickname", "没事不颠有事颠");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "scholar");

	set("age", 46);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("cuff", 150);
	set_skill("strike", 150);
	set_skill("literate", 100);

	set_skill("shenghuo-xinfa", 150);
	set_skill("lingxu-bu", 150);
	set_skill("shenghuo-quan", 150);
	set_skill("guangming-zhang", 150);
	set_skill("liehuo-jian", 150);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "lingxu-bu");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "shenghuo-quan");

	prepare_skill("cuff", "shenghuo-quan");
	prepare_skill("strike", "guangming-zhang");

	prepare_skill("cuff", "jingang-quan");
	create_family("明教", 36, "五散人");

	set("can_apprentice", 2);
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
