// jiushi.c 万剑穿心

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
string query_name() { return "万剑"ZJBR"穿心"; }
inherit F_SSERVER;

int perform(object me, object target)
{
    int damage , zhao,damage2;
    string msg;
    object weapon;
    int extra,skill;
    int i,ap,dp;


    if (!target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使「万剑穿心」？\n"NOR);
skill=(int)me->query_skill("lonely-sword", 1);
//      

    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「万剑穿心」只能对战斗中的对手使用。\n");

        
    if ((int)me->query_skill("lonely-sword", 1) < 300 )
        return notify_fail(WHT"你独孤九剑不够娴熟，使不出「万剑穿心」。\n"NOR);
 
if ((int)me->query_skill("huashan-sword", 1) < 300 )
        return notify_fail(WHT"你华山剑法不够娴熟，使不出「万剑穿心」。\n"NOR);

 if ((int)me->query_skill("kuangfeng-jian", 1) < 300 )
        return notify_fail(WHT"你狂风剑法不够娴熟，使不出「万剑穿心」。\n"NOR);
if ((int)me->query_skill("sword-cognize", 1) < 200 )
        return notify_fail(WHT"你剑道修养不够娴熟，使不出「万剑穿心」。\n"NOR);


    if ((int)me->query("neili")<1300)
    {
        return notify_fail(HIC"你现在内力不够，没能将「万剑穿心」使完！\n"NOR);
    }

	extra = me->query_skill("lonely-sword",1) / 1;
	extra += me->query_skill("zixia-shengong",1) /1;
if (extra >=200) extra =2000;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
        msg = HIW "$N剑气冲霄，使出「"HIG"万剑穿心"HIW"」绝技，身法陡然加快，猛地连出9招！\n"NOR;
        message_vision(msg, me, target);
        me->add("neili", -500);
        
        msg = HIC"第一剑！「"HIG"独孤九剑"HIY"==那一剑的惊艳=="HIC"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIW"第二剑！「"HIG"独孤九剑"HIC"==那一剑的浪漫=="HIW"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIY"第三剑！「"HIG"独孤九剑"HIW"==那一剑的凄然=="HIY"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIR"第四剑！「"HIG"独孤九剑"BBLU+HIW"==那一剑的风情=="NOR+HIR"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = BLU"第五剑！"HIB"「"HIG"独孤九剑"HIR"==那一剑的灿烂=="BLU"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIG"第六剑！「"HIG"独孤九剑"RED"==那一剑的潇洒=="HIG"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = CYN"第七剑！「"HIG"独孤九剑"HIY"==那一剑的哀愁=="NOR+CYN"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIW+BLK"\n第八剑！「"HIG"独孤九剑"HIB"==那一剑的寂寞=="HIW+BLK"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = MAG"第九剑！"HIR"「"HIG"独孤九剑"HIY"之"U+HIG"九"HIW"天"HIY"御"HIW+BLK"剑"HIR"术"NOR+HIR"」"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
        me->start_busy(3);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

       msg = HIW "$N" HIW "施出独孤九剑「破气式」，手中" + weapon->name() +
              HIW "中攻直进，遥指$n" HIW "的气海要穴。\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("parry");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (ap * 2 / 2 + random(ap * 2 / 2) > dp)
        {
                damage = me->query_skill("sword");
target->add("qi",-damage*10);
target->add("eff_qi",-damage*10);
target->start_busy(3);
                        msg +=HIR "$n" HIR "被$N" HIR "一剑划过气门，登感一阵"
                "锥心的刺痛，全身真气源源而泻！\n" NOR;

        } else
        {
                msg += CYN "可$n" CYN "深知$N" CYN "这招的厉"
                       "害，当即向后横移数尺，躲闪开来。\n" NOR;
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

	       switch (random(3))
        {
        case 0:
                msg = HIY "$N" HIY "随手一剑指向$n" HIY "，落点正是$n"
                      HIY "破绽所在，神剑之威，当真人所难测。\n" NOR;
                break;

        case 1:
                msg = HIY "$N" HIY "剑招大开大阖，看似杂乱无章，但招"
                      "招皆击$n" HIY "攻势中破绽，有如神助。\n" NOR;
                break;

        default:
                msg = HIY "$N" HIY "反手横剑刺向$n" HIY "，这似有招似"
                      "无招的一剑竟然威力奇大，令人匪夷所思。\n" NOR;
                break;
        }

        ap = me->query_skill("sword");
        dp = target->query_skill("parry") +
             target->query_skill("lonely-sword");

        if (ap * 2 / 2 + random(ap * 2 / 2) > dp)
        {
                damage = me->query_skill("sword");
target->add("qi",-damage*10);
target->add("eff_qi",-damage*10);
target->start_busy(3);
                        msg +=HIR "$n" HIR "全然无法领会$N" HIR "剑"
                                           "招中的奥妙，一个疏神，登遭重创！\n" NOR;

                me->start_busy(2);
        } else
        {
                msg += CYN "可$n" CYN "淡然处之，并没将$N"
                       CYN "此招放在心上，随手架开，不漏半点破绽。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

if (skill > 300)

{

	   message_vision("\n
"BLK HBWHT"$N的人与剑已开始有了动作，一种极缓慢，极优美的动作，就像是风那么自然\n
"BLK HBWHT"$N的瞳孔在收缩，"+weapon->name()+""BLK HBWHT"已慢慢的刺了出来\n
"BLK HBWHT"从最不可思议的部位刺了出来，刺出时忽然又有了最不可思议的变化\n
"BLK HBWHT"世上根本没有人能破这一剑，绝对没有任何人能谁想去破这一剑，就是去送死\n\n"NOR,me,target);
  if(random(2)==0)
 {

   message_vision(BLK HBWHT"血花耀眼又灿烂，灿烂的婉如流星，流星一现即逝，血花也很快的洒下\n"NOR, me,target);
damage=target->query("max_qi")/2;
damage2=target->query("max_jing")/2;

if (damage >=200000) damage=200000;
	if (damage2 >=200000) damage2=200000;
        target->add("neili",-damage);
        target->receive_wound("qi",damage);
        target->receive_wound("jing",damage2);
        me->add("neili",-250);
  }
else
	{
 message_vision(HIC"$n 心守一处，看清了$N的攻势，不徐不疾的避了开来！\n"NOR,me,target);
	}

}


    return 1;
}
