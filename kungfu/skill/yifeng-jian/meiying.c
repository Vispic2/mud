#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "柔情"ZJBR"媚影"; }
int perform(object me, object target)
{
      int damage, damage2;
        string msg,wn;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"开什么玩笑，没装备剑就想使「柔情媚影」？\n"NOR);
      if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「柔情媚影」只能对战斗中的对手使用。\n");
      if ((int)me->query_skill("yifeng-jian", 1) < 150 )
        return notify_fail(WHT"你的移风剑法不够娴熟，还使不出「柔情媚影」。\n"NOR);
      if ((int)me->query_skill("sword", 1) < 150 )
        return notify_fail(WHT"你连剑都拿不来，还妄想使出「柔情媚影」？\n"NOR);
      if ((int)me->query_skill("force", 1) < 100 )
        return notify_fail(RED"你的内功基础不够，耍不出「柔情媚影」。\n"NOR);
      if ((int)me->query_skill("dodge", 1) < 100 )
        return notify_fail(RED"你的身法不够灵活不够，领悟不到「柔情媚影」。\n"NOR);
      if ((int)me->query("max_neili")<500)
        return notify_fail(RED"你的内力修为不足，无法运足「柔情媚影」的内力。\n"NOR);
      if ((int)me->query("neili")<200)
        {
        return notify_fail(HIC"你现在内力不够，没能将「柔情媚影」使完！\n"NOR);
        }

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
        wn = weapon->name();

        msg = HIC "\n$N" HIC "陡然间姿态万千，身法飘逸，犹如一个婀娜"
              "多姿的女子在随歌漫舞一样。\n但是$N手中" + wn + HIC "却"
              "跟随着身体轻盈地晃动，看似毫无章法，却又像是隐藏着厉"
              "害的招式。\n" NOR;
		if (random(me->query_skill("force"))>target->query_skill("force")/2)
        {
                me->start_busy(2);
                target->start_busy(random(3));
				damage = (int)me->query_skill("yifeng-jian", 1)*5+(int)me->query_skill("force",1)*2;
				damage = damage + random(damage);
				if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
				if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);


				damage2 = (int)me->query_skill("yifeng-jian", 1)*5+(int)me->query_skill("force",1)*2;
				damage2 = damage2 + random(damage2);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);
				msg += HIY"$n看到$N这一剑妙到毫巅，全然无法抵挡，一愣神之间已经被这一剑刺得鲜血飞溅！\n"NOR;
				me->add("neili", -50);
        } else
        {
            me->start_busy(random(3));
                msg += CYN "可是$n" CYN "看出了$N" CYN "这招乃虚招，顿"
                      "时一丝不乱，镇定自若。\n" NOR;
                me->add("neili", -50);
        }
		message_combatd(msg, me, target);
//        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
