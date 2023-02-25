// 地裂震

#include <ansi.h>
string query_name() { return "地裂震"; }
inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 1100)
	return notify_fail("你的法力太差了！\n");

        msg = HIR"   轰◢◢◣◣隆  \n"NOR;
        msg += YEL"\n$n所在的地方裂开了!!"YEL"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-earth", 1);
//对土属性目标无作用
       if ((int)target->query("magicgift")==4)
{
damagic=800+damage;
                target->receive_damage("qi", damagic);
damagic=800+damage;
                target->receive_wound("qi", damagic);
}
//对气属性目标强大
else  if ((int)target->query("magicgift")==3)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIR"$n"HIR"的附近成了熔岩的海洋!!\n"NOR;
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"$n"HIG"飞身跃起，逃过了一难。\n"NOR;
		message_combatd(msg, me, target);
        }

if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
me->add("neili",-450);
if (wizardp(me))
tell_object(me, "基本杀伤为"+damagic+"点。\n" NOR);

	return 1;

}
int perform(object me, object target)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(YEL"「地裂震」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1))
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

	if((int)me->query_skill("magic-earth",1)< 400)
	return notify_fail("你的土系魔法太差了！\n");


	msg = YEL "$N"YEL"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += YEL"$N"YEL"念到 斯科勿，亦多侯坶，盛血的圣杯啊，请来不归的灵魂吧！！！！\n"NOR;
       msg += YEL"$N"YEL"念到 饿鬼界的奴博希由啊，请用你那伟大的力量来溶化一切腐败之物吧！！！！\n"NOR;
       msg += YEL"$N"YEL"念到  大地爆发吧 ! 熔岩爆发吧 !！！!\n"NOR;
       msg += YEL"$n"YEL"所处的地方的大地裂开，熔岩爆发！\n"NOR;
       msg += HIR"    「地裂震」 \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
	return 1;
}


