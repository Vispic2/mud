//zeroring 绝对零冰冻

#include <ansi.h>
string query_name() { return "绝对"ZJBR"零冰冻"; }
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIW"「绝对零冰冻」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1))
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

	if((int)me->query_skill("magic-water",1)< 700)
	return notify_fail("你的水系魔法太差了！\n");

	msg = HIW "$N"HIW"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += HIW"$N"HIW"念到  冥王啊，将至高无上的强大力量注入我体内的死之冷风中去吧!!\n"NOR;
msg += HIW"$N"HIW"念到 让我散发出冰雪的威力！！\n"NOR;
msg += HIW"$N"HIW"念到 拉开生的华丽的帷幕，展现死神的姿态！！！！！！ 极零烈冻波！！\n"NOR;
       msg += HIW"在血红的天空中，一条"HIW"冰龙"HIW"向$n"HIW"冲去！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-water", 1);
//对水属性目标无作用
       if ((int)target->query("magicgift")==2)
{
damagic=2500+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);

damagic=3000+damage;
                target->receive_wound("qi", damagic);
}
//对火属性目标强大
else  if ((int)target->query("magicgift")==1)
{
damagic=6500+damage*8;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
damagic=6500+damage*4;
                target->receive_wound("qi", damagic);
}
else
{
damagic=3000+damage*3;
target->receive_damage("qi", 3000+damage*3);
target->receive_wound("qi", 3000+damage*2);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
target->start_busy(1);
msg += HIW"    \n"NOR;
msg += HIW"………………………………………………   \n"NOR;
msg += HIW"°∴   ★绝对★．°· ．·°∴°∴．   \n"NOR;
msg += HIW"°．° ．·   ∴ ☆零☆ °．°°．．   \n"NOR;
msg += HIW"．·°∴°．°．∴·°°★冰冻★  ∴   \n"NOR;
msg += HIW"………………………………………………   \n"NOR;
msg += HIW"    \n"NOR;
        msg += HIW"冻土啊，冰河啊，狂舞吧！!!$n的附近成了冰的地狱!!\n"NOR;
        msg += HIW"$n全身被冻土冰河笼罩了!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
damagic=1500+damage;
                target->receive_damage("qi", damagic);
damagic=1000+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
msg += HIW"    \n"NOR;
msg += HIW"………………………………………………   \n"NOR;
msg += HIW"°∴   ★绝对★．°· ．·°∴°∴．   \n"NOR;
msg += HIW"°．° ．·   ∴ ☆零☆ °．°°．．   \n"NOR;
msg += HIW"．·°∴°．°．∴·°°★冰冻★  ∴   \n"NOR;
msg += HIW"………………………………………………   \n"NOR;
msg += HIW"    \n"NOR;
        msg += HIW"冻土啊，冰河啊，狂舞吧！!!$n的附近成了冰的地狱!!\n"NOR;
        msg += HIW"$p使出全力，抵抗寒气，但还是给冻土冰河笼罩了。\n"NOR;
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

                me->start_busy(4);
                me->add("neili", -2000);
        return 1;
}
