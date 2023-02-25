
#include <ansi.h>

inherit F_SSERVER;

#define JUNLIN "「" HIY "君临天下" NOR "」"
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i, ap, dp;
        object weapon;
        
        if (! target) target = offensive_target(me);

        
      
                
        if (! target || ! me->is_fighting(target))
                return notify_fail(JUNLIN "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" JUNLIN "。\n");

        if (me->query_skill_mapped("sword") != "tianzi-jianfa") 
                return notify_fail("你没有激发天子剑法，难以施展" JUNLIN "。\n");
        
        if ((int)me->query("neili") < 800)
                return notify_fail("你的真气不够，无法施展" JUNLIN "！\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("你的内力修为还不足以使出" JUNLIN "。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你的内功火候不够，难以施展" JUNLIN "！\n");

        if ((lvl = (int)me->query_skill("tianzi-jianfa", 1)) < 240)
                return notify_fail("你的天子剑法还不够熟练，无法使用" JUNLIN "！\n");             
                         
        
        if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "只见$N" HIY "手中兵刃" 
              HIY"似乎化作一条金龙，向$n直刺去，\n顿显君临天下之霸气。\n" NOR;

        message_sort(msg, me, target);
        me->add("neili", -300);
        ap = me->query_skill("tianzi-jianfa, 1");
        dp = target->query_skill("dodge", 1);
       
        if (ap / 3 + random(ap) > dp)
                  count = ap / 8;
  
        else count = 0;

        me->add_temp("apply/attack", count);

        for (i = 0; i < 15; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, i * 2);
        }
        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(5));
        return 1;
}


