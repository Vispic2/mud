// he.c 静和师太
// Modified by That Oct.1997

#include <command.h>
#include <ansi.h>
#include "tobebonze.h"

inherit NPC;

void create()
{
	set_name("静和师太", ({ "jinghe shitai","jinghe","shitai"}));
	set("long", "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
	set("gender", "女性");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 25);
	set("int", 19);
	set("con", 24);
	set("dex", 22);

	set("max_qi", 2200);
	set("max_jing", 1100);
	set("neili", 2700);
	set("max_neili", 2700);

	set("combat_exp", 190000);
	set_skill("persuading", 80);
	set_skill("throwing", 70);
	set_skill("force", 120);
	set_skill("dodge", 100);
	set_skill("finger", 90);
	set_skill("parry", 100);
	set_skill("strike", 100);
	set_skill("blade", 120);
	set_skill("literate", 100);
	set_skill("mahayana", 100);
	set_skill("jinding-zhang", 90);
	set_skill("tiangang-zhi", 100);
	set_skill("yanxing-dao", 120);
	set_skill("zhutian-bu", 100);
	set_skill("emei-xinfa", 120);
	set_skill("linji-zhuang", 120);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	command ("say 阿弥陀佛！贫尼不收弟子。\n");
	return;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
