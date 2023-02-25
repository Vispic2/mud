// beihai.c

#include <ansi.h>

inherit NPC;

void random_move();
void random_attack();

void create()
{
	set_name("孙悟空", ({ "sun wukong", "sun" }));
	set("title", HIY "斗战胜佛" NOR);
	set("gender", "男性");
	set("age", 3000);
	set("long", @LONG
一团黄色的光芒中隐隐然透出一人，细看却不能捕捉他的身形。
LONG );
	set("combat_exp", 100000000);
	set("score", 10000000);
	set("shen_type", 0);
	set("attitude", "friendly");
	set("max_neili", 60000);
	set("neili", 60000);
	set("max_jing", 60000);
	set("jing", 60000);
	set("max_qi", 60000);
	set("qi", 60000);
	set("jingli", 60000);
	set("max_jingli", 60000);

	set("str", 200);
	set("int", 200);
	set("con", 200);
	set("dex", 200);

	set_skill("unarmed", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);
	set_skill("force", 2000);

	set("jiali", 0);

	set_temp("apply/unarmed_damage", 800);
	set_temp("apply/armor", 3000);

	if (clonep(this_object()))
	{
		set("chat_chance", 30);
		set("chat_msg", ({ (: random_move :) }));
		set("chat_chance_combat", 120);
		set("chat_msg_combat", ({ (: random_attack :) }));
		set("born_time", time());
		keep_heart_beat();
	}

	setup();
}

mapping *actions = ({
([      "action": "$N微一躬身，$w带着刺耳的吱吱声，擦地扫向$n的脚踝",
	"damage_type":"挫伤"
]),
([      "action": "$N右手托住$w，左掌一击，只见$w倒向$n的肩头",
	"damage_type":"挫伤"
]),
([      "action": "$N举起$w乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
	"damage_type":"挫伤"
]),
([      "action": "$N举起$w，突然猛地一棒打向$n的$l",
	"damage_type":"挫伤"
]),
([      "action": "$N将$w一端指向$n，飞速刺向$n",
	"damage_type":"刺伤"
]),
([      "action": "$N全身僵直，蹦跳着持杖前行，冷不防举起$w拦腰向$n劈去",
	"damage_type":"挫伤"
]),
([      "action": "$N假意将$w摔落地上，待$n行来，一脚勾起，击向$n的$l",
	"damage_type":"挫伤"
]),
([      "action": "$N一个翻滚，身下$w往横里打出，挥向$n的裆部",
	"damage_type":"挫伤"
]),
([      "action": "$N身不动，脚不移，$w却直飞半空，不偏不倚地砸向$n的$l",
	"damage_type":"挫伤"
]),
([      "action": "$N高举$w，身形如鬼魅般飘出，对准$n的天灵盖一棒打下",
	"damage_type":"挫伤"
]),
([      "action": "$N将$w舞成千百根相似，根根砸向$n全身各处要害",
	"damage_type":"挫伤"
]),
});

mapping query_action()
{
	mapping action;

	action = actions[random(sizeof(actions))];
	action["action"] = replace_string(action["action"], "$w",
					  HIY "金箍棒" NOR);
	return action;
}

void fight_ob(object ob)
{
	if (is_fighting(ob))
		return;


	message_vision(HIY "$N" HIY "哈哈一笑，对着$n就是一棒！"NOR"\n",
		       this_object(), ob);

	::fight_ob(ob);
	if (! is_killing(ob->query("id")))
		kill_ob(ob);
}

int attack()
{
	object ob, *obs;
	string msg;

	obs = ({ });
	clean_up_enemy();

	foreach (ob in query_enemy())
	{
		if (ob->query("combat_exp") > 1000000)
			continue;

		obs += ({ ob });
	}

	if (sizeof(obs))
	{
		msg = HIY "$N" HIY "飞起一脚将" +
		      implode(obs->name(), HIY "、") +
		      HIY "踢到一边，喝道：“滚开！”"NOR"\n";
		message_sort(msg, this_object(), ob);
		obs->unconcious();
		obs -= ({ 0 });
		foreach (ob in obs)
		{
			remove_enemy(ob);
			remove_killer(ob);
			ob->remove_enemy(this_object());
			ob->remove_killer(this_object());
		}
	}

	return ::attack();
}

int accept_fight(object ob)
{
	if (ob->query("combat_exp") < 3000000)
	{
		message_vision("$N懒得理$n。\n",
			       this_object(), ob);
		return 0;
	}

	message_vision("$N喜道：“好好！我老孙多年没动筋骨了！"
		       "今日就和你玩玩”\n", this_object(), ob);
	return 1;
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
	me->set("neili", me->query("max_neili"));
	if (playerp(ob) && ! ob->query("breakup"))
	{
		ob->set("qi", -1);
		ob->set("eff_qi", -1);
		return HIR "$N" HIR "一棒正打在$n" HIR
		       "身上，只见$n" HIR "立刻被压垮在地！"NOR"\n";
	}

	ob->receive_wound("qi", 400 + random(400), me);
	switch (random(3))
	{
	case 0:
		return HIY "$N" HIY "一棒打在$n" HIY "身上，"
		       HIY "$n" HIY "登时觉得浑身“轰”的一下，"
		       "几乎失去知觉！"NOR"\n";
	case 1:
		return HIY "$N" HIY "一棒打下，$n" HIY "只觉得"
		       "天灵盖“嗡”的一下，几乎不省人事！"NOR"\n";

	default:
		return HIY "$N" HIY "一棒将$n" HIY "打了个东倒西歪，"
		       "立足不稳！"NOR"\n";
	}
}

void unconcious()
{
	die();
}

void die()
{
	string *ob_list = ({
		"/clone/gift/diamond",
		"/clone/gift/agate",
		"/clone/gift/crystal",
		"/clone/gift/jade",
	});
	object ob;

	ob = new(ob_list[random(sizeof(ob_list))]);

	command("chat 哈哈！我老孙久不履足人间，不曾想还有这等人物！"
		"今日到此，改日再玩！");
	message_sort(HIY "$N" HIY "捏了一个口诀，忽然腾云而去，只看得你"
		     "目瞪口呆，须臾，只见天上慢慢飘下一朵云彩。"NOR"\n",
		     this_object());
	ob->move(environment());
	destruct(this_object());
}

void random_move()
{
	if (time() - query("born_time") > 7200)
	{
		message_vision("$N急急忙忙的走了。\n", this_object());
		CHANNEL_D->do_channel(this_object(), "rumor",
			"听说" + name() + HIM "赴蟠桃会去了。" NOR);
		destruct(this_object());
		return;
	}
	NPC_D->random_move(this_object());
}

void random_attack()
{
	object ob;

	set("qi", query("eff_qi"));
	set("jing", query("eff_jing"));
	if (query("qi") < query("max_qi") * 3 / 5 ||
	    query("jing") < query("max_jing") * 3 / 5)
	{
		if (query_temp("recover_times") >= 3)
		{
			die();
			return;
		}

		message_combatd(HIM "$N" HIM "施展九龙化伤术，体力得到了完全恢复！"NOR"\n",
				this_object());
		add_temp("recover_times", 1);
		set("eff_qi", query("max_qi"));
		set("qi", query("max_qi"));
		set("eff_jing", query("max_jing"));
		set("jing", query("max_jing"));
		return;
	}

	clean_up_enemy();
	ob = select_opponent();
	if (! objectp(ob))
		return;

	switch (random(10))
	{
	case 0:
		message_combatd(HIY "$N抓下一把毫毛嚼烂，“噗”的吹了一口气，"
				"登时化作千百个小猴子，手持金箍棒\n"
				"团团围了上来就是一阵乱打！"NOR"\n",
				this_object());
		set_temp("apply/name", ({ "小猴子" }));
		attack();
		attack();
		attack();
		attack();
		attack();
		attack();
		attack();
		attack();
		attack();
		attack();
		attack();
		delete_temp("apply/name");
		break;

	case 1:
		message_combatd(HIY "$N" HIY "哈哈一笑，手中的金箍棒忽然变得"
				"巨大无比，对着$n" HIY "直压下去！\n只见$n"
				"登时被打了个筋斗，滚出数十步！"NOR"\n",
				this_object(), ob);
		ob->receive_damage("qi", 1000 + random(1000), this_object());
		ob->receive_wound("qi", 700 + random(700), this_object());
		ob->interrupt_busy(ob, 10 + random(10));
		break;

	case 2:
		if (ob->is_busy())
			break;
		message_combatd(HIY "$N" HIY "对$n" HIY "喝道：“定！”只见"
				"$n" HIY "眼睛一瞪，变得呆若木鸡！"NOR"\n",
				this_object(), ob);
		ob->start_busy(50 + random(50));
		break;
	}
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
