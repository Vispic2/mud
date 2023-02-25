// niutou.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("通臂猿猴", ({ "monkey king" }) );
	set("title", HIY "神猴大将军" NOR);
	set("gender", "男性");
	set("age", 28);
	set("long", "他就是与孙悟空齐名的神猴大将军！通臂猿猴");
	set("combat_exp", 100000000);
	set("shen_type", 0);
	set("attitude", "heroism");
	set("max_neili", 200000);
	set("neili", 200000);
	set("max_jing", 200000);
	set("jing", 200000);
	set("max_qi", 500000);
	set("qi", 500000);
	set("jingli", 200000);
	set("max_jingli", 200000);

	set("str", 350);
	set("int", 100);
	set("con", 100);
	set("dex", 250);

	set_skill("unarmed", 3500);
	set_skill("sword", 3500);
	set_skill("parry", 3500);
	set_skill("dodge", 3500);
	set_skill("force", 3500);

	set("jiali", 500);

	set_temp("apply/attack", 400);
	set_temp("apply/unarmed_damage", 600);
	set_temp("apply/armor", 1800);

	if (clonep(this_object()))
	{
		set("chat_chance", 40);
		set("chat_msg", ({ (: random_move :) }));
		set("born_time", time());
		keep_heart_beat();
	}

	setup();
}

void fight_ob(object ob)
{
	if (is_fighting(ob))
		return;

	message_vision(HIR "$N" HIR "眼中金光闪烁，眸中"
		       "尽是怒火"NOR"\n", this_object(), ob);

	::fight_ob(ob);
	if (! is_killing(ob->query("id")))
		kill_ob(ob);
}

int accept_fight(object ob)
{
	message_vision("$N怒吼一声，眸中射出一道金光\n",
		       this_object(), ob);
	kill_ob(ob);
	return -1;
}

int accept_kill(object ob)
{
	return 1;
}

int accept_hit(object ob)
{
	return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
	ob->receive_damage("jing", me->query("str") * 2, me); 
        me->receive_wound("jing", me->query("str") * 2, me);
	return HIR "$N" HIR "顿时气血翻涌头昏脑胀$n"
	       HIR "身子往后一倒，眼神迷离不定。"NOR"\n";
}

void unconcious()
{
	die();
}

void die()
{
	object ob;

	ob = new("/clone/baoshi/tianjing");
	command("chat 噗！好啊！你...你很好！我记住你了！");
	message_sort(HIW "$N" HIW "吐一口鲜血，身子往后一倾，只听啪嗒一声"
		     "轻响，$N" HIW "掉下了一" + ob->query("unit") +
		     ob->name() + HIR "。\n", this_object());
	ob->move(environment());
	destruct(this_object());
}

void random_move()
{
	if (time() - query("born_time") > 1800)
	{
		message_vision("$N一眨眼就不见了人影。\n", this_object());
		CHANNEL_D->do_channel(this_object(), "rumor",
			"听说" + name() + HIM "没找到孙悟空"
			"反被一凡人杀了威风，现已回万妖国养伤去了。" NOR);
		destruct(this_object());
		return;
	}
	NPC_D->random_move(this_object());
}
