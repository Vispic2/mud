//by system_2
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int i;
 
 ob = me->select_opponent();

    if( !me->is_fighting() )
        return notify_fail("「舞」字决只能在战斗时使用。\n");
     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 1200 )
        return notify_fail("你的真气不够！\n");
if ( (string)me->query("family/family_name") != "逍遥派") 
     return notify_fail("只有逍遥弟子才能使用该招。\n");
          if(me->query_skill_mapped("dodge") != "lingbo-weibu") 
               return notify_fail("你的凌波微步没激发在轻功上吧? \n");

    if( (int)me->query_skill("sword") < 100 ||
        me->query_skill_mapped("sword") != "zuixin-sword")
        return notify_fail("你的「逍遥醉心剑」还不够精纯，无法使用「舞」字决n");
msg = HIG "$N一声清啸，剑法忽变，带出一条无比绚丽的剑芒，刹那间剑芒陡涨，如天河倒泻一般洒向"+ob->name()+"!\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    me->add("neili", -1000);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_wu",1);
    for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIC"剑势未缓\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_wu");
    me->delete_temp("secondly_weapon");
    return 1;
}


