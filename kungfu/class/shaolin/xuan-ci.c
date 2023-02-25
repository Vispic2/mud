// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#define	IS_XUAN_CI	1

#include "xuan.h"

void create()
{
	set_name("玄慈大师", ({
		"xuanci dashi",
		"xuanci",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
	);

	set("nickname", "少林寺方丈");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 2800);
	set("max_jing", 1400);
	set("neili", 3800);
	set("max_neili", 3800);
	set("jiali", 50);
	set("combat_exp", 1450000);
	set("score", 500000);

	set_skill("force", 170);
	set_skill("hunyuan-yiqi", 170);
	set_skill("dodge", 160);
	set_skill("shaolin-shenfa", 160);
	set_skill("finger", 170);
	set_skill("strike", 170);
	set_skill("hand", 160);
	set_skill("claw", 160);
	set_skill("parry", 160);
	set_skill("nianhua-zhi", 170);
	set_skill("sanhua-zhang", 170);
	set_skill("fengyun-shou", 160);
	set_skill("longzhua-gong", 160);
	set_skill("buddhism", 160);
	set_skill("literate", 160);
	set_skill("medical", 180);
	set_skill("shaolin-yishu", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("少林派", 36, "弟子");

	setup();

	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
