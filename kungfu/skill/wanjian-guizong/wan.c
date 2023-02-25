// feilong.c 万剑归宗「万剑归宗」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return HIR"万剑"+ZJBR+HIY"归宗"NOR; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int ap, i,sss,dp;

//	if (! target) 
//	target = offensive_target(me);


        if (! target){
                me->clean_up_enemy();
                target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("「万剑归宗」只能在战斗中对对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("不拿剑怎么使用「万剑归宗」？\n");

	if ((int)me->query_skill("wanjian-guizong", 1) < 300)
		return notify_fail("你万剑归宗不够娴熟，使不出「万剑归宗」。(需要300级)\n");

	if ((int)me->query_skill("force") < 300 )
		return notify_fail("你内功火候不够，使不出「万剑归宗」。(需要300级)\n");

	if ((int)me->query("neili") < 30000)
		return notify_fail("你现在真气不够，无法将「万剑归宗」使完(需要3万内)！\n");

	if (me->query_skill_mapped("sword") != "wanjian-guizong")
		return notify_fail("你没有激发万剑归宗，无法使用「万剑归宗」。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIY"心念电闪一提内力，将武器腾空顿时化为数千束极光，运劲于臂，呼" "的一声向$n" HIC "射了出去！"NOR"\n";

	ap = me->query_skill("sword");
	dp = target->query_skill("dodge");
	
    sss=1+random(30);
    for (i = 0; i <= sss; i++){
    if (! me->is_fighting(target))
	break;
	if (random(3) == 0 && ! target->is_busy())
	target->start_busy(1);
	COMBAT_D->do_attack(me, target, weapon, 0);
	}
	
	damage = ( me->query("max_qi") + ap ) / 2;
	damage += random(damage)/2;	
	msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 150,  HIR "$n" HIR "疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃"   "拦腰而过，鲜血飞溅，皮肉卷起！"NOR"\n");
	
	
	message_combatd(msg, me, target);

	


	me->add("neili", -1000+(sss*50));	
	me->start_busy(10+(sss/10));	
	return 1;
}

/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
