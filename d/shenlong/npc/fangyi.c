// fangyi.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("方怡", ({"fang yi", "fang","yi"}));
	set("title",HIY"神龙教"HIR"赤龙使"NOR"座下弟子");
	set("long",
		"她原来是沐王府家将，现在是神龙教赤龙门女弟子，长得活泼可爱。\n"
	);

	set("gender", "女性");
	set("attitude", "peaceful");

	set("age", 10 + random(10));
	set("shen_type", -1);
	set("str", 25 + random(10));
	set("dex", 25 + random(10));
	set("max_qi", 200);
	set("max_jing", 150);
	set("neili", 200);
	set("max_neili", 200);
	set("jiaji", 5 + random(5));
	set("combat_exp", 20000 + random(10000));

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shedao-qigong", 30);
	map_skill("sword","shedao-qigong");

	setup();
	carry_object("/d/shenlong/obj/xionghuang")->wield();
	carry_object("/d/city/obj/duanjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 5);
}

#include "sldizi.h"

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
