// holyword破魔圣言

#include <ansi.h>
string query_name() { return "破魔"ZJBR"圣言"; }
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

        msg = HIY"↘↓↙←↖↗↘↙\n"NOR;
        msg += HIY"一道圣光照向$n"HIY"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-light", 1);

//对光属性目标无作用
       if ((int)target->query("magicgift")==6)
{
damagic=530+damage;
                target->receive_damage("qi", damagic);
damagic=530+damage;
                target->receive_wound("qi", damagic);
}
//对黑暗属性目标强大
else  if ((int)target->query("magicgift")==5)
{
damagic=1680+damage*6;
                target->receive_damage("qi", damagic);
damagic=1680+damage*3;
                target->receive_wound("qi", damagic);
}
else
{
damagic=960+damage*2;
target->receive_damage("qi", 960+damage*2);
target->receive_wound("qi", 960+damage);
}
	if(target->is_ghost()==1
	&& !userp(target)) {
		message_vision(RED "$N"RED"惨叫了一声，化为了灰烬！\n" NOR, target);
		target->die();
		return 1;
	}

        msg += YEL"$n"YEL"的附近圣光普照!!$n觉的全身要溶化了了!!\n"NOR;
                if (!target->is_busy())
                target->start_busy(3);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"$n"HIY"使用了魔法防护，逃过了一劫!\n"NOR;
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
                return notify_fail(HIY"「破魔圣言」只能对战斗中的对手使用。\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1))
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

	if((int)me->query_skill("magic-light",1)< 550)
	return notify_fail("你的光明魔法太差了！\n");


	msg = HIY "$N"HIY"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += HIY"$N"HIY"念到 服从于我的念咒者啊，现在听从我的咒语，消除你们的骨，与血，与肉，的痛吧！！！\n"NOR;
       msg += HIY"$N"HIY"念到 世界上所有不幸的生灵，所有邪恶堕落的灵魂！\n"NOR;
       msg += HIY"$N"HIY"念到 请随著净化之光，将世界与世界结合。\n"NOR;
       msg += HIY"$N"HIY"念到 回到你们原本所属之处吧！！！！！！\n"NOR;
       msg += HIY"天空突然射下了圣光，$n"HIY"所处的地方被圣光照耀!!\n"NOR;
       msg += HIY"  「破魔圣言」 \n"NOR;
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


