// hongma.c 枣红马

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(RED"血色马"NOR, ({ "zaohong ma" }));
	set("long","一匹血色骏马，全身火红，无一根杂毛。玩家可以骑上它去指定的地方(ride)。\n");
	set("race", "野兽");
	set("age", 5);
	set("ridable", 1);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
	set("verbs", ({ "bite","hoof" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
	set("chat_chance", 3);
	set("chat_msg", ({
		RED"血色马"NOR"扯了扯缰绳，然后不耐地在地上刨着蹄子。\n",
	}) );

	setup();
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
