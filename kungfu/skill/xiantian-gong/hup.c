// hup.c 五气朝元

#include <ansi.h>

inherit F_CLEAN_UP;

string query_name() { return "五气"ZJBR"朝元"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
	string msg;
	mapping my;
	int rp;
	int neili_cost;
	if(!(me->query("xiantian-gong_cd")<time()))
	return notify_fail("你的"+query_name()+"CD中，还有"+(me->query("xiantian-gong_cd")-time())+"秒。\n");
	if (userp(me) && ! me->query("can_perform/xiantian-gong/hup"))
		return notify_fail("你还没有通晓五气朝元的奥秘.。\n");

	if ((int)me->query_skill("xiantian-gong", 1) < 200)
		return notify_fail("你的先天功不够深厚，无法使用五气朝元。\n");

	if ((int)me->query("neili") < 200) 
		return notify_fail("你现在的真气不够。\n");

	my = me->query_entire_dbase();
	if ((rp = (my["max_qi"] - my["eff_qi"])) < 1)
		return (SKILL_D("force") + "/recover")->exert(me, target);

	if (rp >= my["max_qi"] / 10)
		rp = my["max_qi"] / 10;

	skill = me->query_skill("force");
	msg = HIY "$N" HIY "缓缓吐出一口气，脸色渐渐的变得平和。"NOR"\n";
	message_combatd(msg, me);

	neili_cost = rp + 100;
	if (neili_cost > my["neili"])
	{
		neili_cost = my["neili"];
		rp = neili_cost - 100;
	}
	me->receive_curing("qi", rp);
	me->receive_heal("qi", rp * 3 / 2);
	me->receive_curing("jing", rp);
	me->receive_heal("jing", rp * 3 / 2);
	me->add("neili", -neili_cost);

	me->set("xiantian-gong_cd",time()+4);
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
