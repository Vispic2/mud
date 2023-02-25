// tie@fengyun
string query_name() { return "火之矢"; }
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
        int damage,damagic;

	if( !target ) target = offensive_target(me);

	        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(RED"「火之矢」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 1000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1))
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

	if((int)me->query_skill("magic-fire",1)< 250)
	return notify_fail("你的火系魔法太差了！\n");


	extra = me->query_skill("spells",1) / 40;
	extra += me->query_skill("magic-fire",1) /40;
 	if (extra> 33) extra = 33;
        i = extra/4;
        msg = RED "$N"RED"口中高吟了一段了咒文.$N"RED"的上空形成了"+chinese_number(i)+"道火之矢.\n"NOR;
        msg += HIB"$N"HIB"念到 在漆黑的黑暗中燃烧的地狱之火啊，化为我的剑消灭敌人！！！！\n"NOR;
        msg += RED"$N"RED"扬起了手,所有的"HIR"火之矢"NOR","RED"全部对准了$n"RED"发射而去!\n"NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = HIC"    第"+chinese_number(i+1)+"道"HIR"火之矢!\n"NOR;
        msg += RED"     → "NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("magic-fire", 1);
//对火属性目标无作用
       if ((int)target->query("magicgift")==1)
{
damagic=150+damage;
                target->receive_damage("qi", damagic);
damagic=125+damage;
                target->receive_wound("qi", damagic);
}

else  if ((int)target->query("magicgift")==2)
{
damagic=850+damage*3;
                target->receive_damage("qi", damagic);
damagic=850+damage;
                target->receive_wound("qi", damagic);
}
else
{
damagic=200+damage;
target->receive_damage("qi", 200+damage);
target->receive_wound("qi", 200+damage/2);
}

        msg += HIR"\n  $n"HIR"没法躲避，被火之矢炸得飞了起来！\n"NOR;
		message_combatd(msg, me, target);
        } else
        {
        msg += RED"\n  $p"RED"飞身跃起，结果火之矢在$p"RED"身下爆炸。\n"NOR;
		message_combatd(msg, me, target);
        }

	}
	i = extra/4;
		COMBAT_D->report_status(target);
if (wizardp(me))
tell_object(me, "基本杀伤为"+damagic+"点。\n" NOR);
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
	me->add("neili", - 120 * i);
	me->start_busy(3);
	return 1;
}

