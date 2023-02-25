//Dintfield 地狱力场
#include <ansi.h>
string query_name() { return "地狱"ZJBR"力场"; }
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(YEL"「地狱力场」只能对战斗中的对手使用。\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("你没有资格使用这项技能！\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("你的法力太差了！\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1))
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

	if((int)me->query_skill("magic-earth",1)< 700)
	return notify_fail("你的土系魔法太差了！\n");

	msg = YEL "$N"YEL"用手在天空划了一个五芒星，口中喃喃地念著咒文，\n" NOR;
       msg += YEL"$N"YEL"念到 斯科勿，亦多侯坶，盛血的圣杯啊，请来不归的灵魂吧！！！！\n"NOR;
msg += YEL"$N"YEL"念到 黑暗的王子，邪恶的长子，如果你们还是王的话，就听从我的召唤吧 !!\n"NOR;
msg += YEL"$N"YEL"念到 恶魔的肉芽啊，将敌人全部吃尽吧！！！！！！\n"NOR;
       msg += YEL"大地裂开，大量的"HIY"恶魔的肉芽"YEL"把$n"YEL"包围！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-earth", 1);
//对土属性目标无作用
       if ((int)target->query("magicgift")==4)
{
damagic=2500+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);

damagic=2000+damage;
                target->receive_wound("qi", damagic);
}
//对气属性目标强大
else  if ((int)target->query("magicgift")==3)
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
damagic=2000+damage*3;
target->receive_damage("qi", 2000+damage*3);
target->receive_wound("qi", 2000+damage*2);
if (wizardp(me))
tell_object(me, "\n基本杀伤为"+damagic+"点。\n" NOR);
}
target->start_busy(1);
msg += YEL"                                         \n"NOR;
msg += YEL"            ▓  ▓▓▓                    \n"NOR;
msg += YEL" ┏━┓      ▓  ▓          ┏━┓         \n"NOR;
msg += YEL" ┃地┃      ▓▓卐▓▓       ┃场┃          \n"NOR;
msg += YEL" ┗━┛|         ▓  ▓     |┗━┛         \n"NOR;
msg += YEL"      -o-    ▓▓▓  ▓    -o-            \n"NOR;
msg += YEL"  狱  |                    |  场         \n"NOR;
msg += YEL"▓█▆▅▃▂ …    … ▂▃▅▆█▓          \n"NOR;
msg += YEL"                                         \n"NOR;
        msg += HIR"大地的力量出现!!$n的附近成了所有的东西都腐烂坠落，回归大地！！！!!\n"NOR;
        msg += HIR"$n全身被地炎了!!\n"NOR;
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

msg += YEL"                                         \n"NOR;
msg += YEL"            ▓  ▓▓▓                    \n"NOR;
msg += YEL" ┏━┓      ▓  ▓          ┏━┓         \n"NOR;
msg += YEL" ┃地┃      ▓▓卐▓▓       ┃场┃          \n"NOR;
msg += YEL" ┗━┛|         ▓  ▓     |┗━┛         \n"NOR;
msg += YEL"      -o-    ▓▓▓  ▓    -o-            \n"NOR;
msg += YEL"  狱  |                    |  场         \n"NOR;
msg += YEL"▓█▆▅▃▂ …    … ▂▃▅▆█▓          \n"NOR;
msg += YEL"                                         \n"NOR;
        msg += HIR"大地的力量出现!!$n的附近成了所有的东西都腐烂坠落，回归大地！！！!!\n"NOR;
        msg += HIR"$n全身被地炎了!!\n"NOR;
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
