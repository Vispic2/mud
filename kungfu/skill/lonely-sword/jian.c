#include <ansi.h>

string name() { return BLK HBWHT "剑心通明" NOR; }
string query_name() { return "剑心"ZJBR"通明"; }
inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        object weapon;
        string msg;
        int skill;

        if (me->query_skill_mapped("sword") != "lonely-sword")
                return notify_fail("你还没有激发独孤九剑。\n");

	

        if ((int)me->query_skill("lonely-sword", 1) < 800)
                return notify_fail("你的独孤九剑等级不够，难以施展" + name() + "。\n");

     if ((int)me->query_skill("sword-cognize", 1) < 450)
                return notify_fail("你的剑道修养不够，难以施展" + name() + "。\n");   if( me->query_temp("dugu_sword") )
                return notify_fail("你已经运起" + name() + "了。\n");

        if( !objectp(weapon=me->query_temp("weapon")) )
                return notify_fail("你所使用的武器不对！\n");

        if( weapon->query("skill_type") != "sword" )
                return notify_fail("你所使用的武器不对！\n");

        if( me->query("neili")<2500 )
                return notify_fail("你此时的内力不足，难以施展" + name() + "。\n");

        msg = BLK HBWHT "$N" BLK HBWHT "凝神聚气，挥洒手中兵器，进入无招无我，剑心通明境界！\n\n" NOR;

        message_combatd(msg, me, target);

        if (me->is_fighting())
                me->start_busy(1);

        skill = me->query_skill("lonely-sword", 1);

        me->add_temp("apply/damage", skill*5);
        me->set_temp("dugu_sword", 1);

        me->start_call_out((: call_other,  __FILE__, "remove_effect", me, skill * 5 :), 180);

        me->add("neili", -200);
        return 1;
}

void remove_effect(object me, int amount)
{
        if( me->query_temp("dugu_sword") )
        {
                me->add_temp("apply/damage", -1*amount);
                me->delete_temp("dugu_sword");
                tell_object(me, "你的" + name() + "运行完毕，将内力收回丹田。\n");
        }
}
