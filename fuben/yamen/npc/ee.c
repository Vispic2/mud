//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;
void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));

	set_name("马匪",({"ma fei"}));
	set("gender", "男性");
	set("long", "十分强壮的马匪，经常到扬州城内打家劫舍");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl);
	set("neili", lvl);
	set("eff_qi", lvl);
	set("max_qi", lvl);
	set("qi", lvl);
	set("max_jing", lvl);
	set("jing", lvl);
	set("max_jingli", lvl);
    set("eff_jingli", lvl);
 	set("jingli", lvl);
		
	set_skill("force", sklv);
    set_skill("hamagong", sklv);	
	set_skill("dodge", sklv);
	set_skill("unarmed", sklv);
	set_skill("parry", sklv);
	
	map_skill("force", "hamagong");
	map_skill("dodge", "hamagong");
	map_skill("unarmed", "hamagong");
	map_skill("parry", "hamagong");		
	setup();
}

void die()
{
	object me, ob = this_object();
	
	me = ob->query_last_damage_from();
/*	if (userp(me) && me->query("fuben/huanjing/ask_job"))  {
		me->add("fuben/huanjing/kill_1", 1);
		tell_object(me, "你已经杀了"+me->query("fuben/huanjing/kill_1", 1)+"个"+name()+NOR"\n");
	}*/
	return ::die();
}
void unconcious()
{
	die();
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
