// /jiaowenqi.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("焦文期", ({ "jiao wenqi", "jiao" }));
	set("long",@LONG
他是关外六魔中的三魔焦文期。背上一把铁琵琶，是武林中少见的奇门兵器。
LONG );
	set("nickname", HIC "关外三魔" NOR);
	set("gender", "男性");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 50);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 1200);
	set("max_jing", 500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("combat_exp", 170000);
	set("score", 20000);

	set_skill("force", 80);
	set_skill("xiaowuxiang", 50);
	set_skill("dodge", 50);
	set_skill("shenkong-xing", 60);
	set_skill("unarmed", 90);
	set_skill("yujiamu-quan", 40);
	set_skill("parry", 60);
	set_skill("hammer", 100);
	set_skill("riyue-lun", 100);

	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "riyue-lun");
	map_skill("hammer", "riyue-lun");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object(__DIR__"obj/tiepipa")->wield();
	add_money("silver",40);
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
