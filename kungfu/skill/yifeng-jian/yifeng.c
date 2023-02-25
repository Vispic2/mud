#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "移动起"ZJBR"云飞扬"; }
int perform(object me, object target)
{
        object weapon;
object ob;
        string msg;
        int i, attack_time;

        me->clean_up_enemy();
    ob = me->select_opponent();
if (me->is_fighting())
{
if  (environment(me)!=environment(ob) )
     return notify_fail("对方已经不在了。\n");
}

        if( !target ) target = offensive_target(me);

        if ( me->query("gender") != "女性")
        return notify_fail("你体态生硬，无从领会「移风起栖云飞扬」的精髓。\n");

//        if ( !wizardp(this_player()) && (me->query("family/family_name") != "移花宫"))
//                return notify_fail("你不是移花宫弟子不能使用冥雨神功.\n
//                                    移风剑法博大精深, 非移花宫弟子不传, 真不知道你是怎么学会的!\n
//                                    要是让两位宫主知道了你可惨了.\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「移风起栖云飞扬」只能在战斗中使用。\n");

   if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if((int)me->query_dex() < 25)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

     if(me->query_skill_mapped("sword") != "yifeng-jian")
             return notify_fail("你的移风剑法没激发在剑法上吧? \n");

        if((int)me->query_skill("mingyu-shengong",1) < 100)
                return notify_fail("你的冥雨神功的修为不够, 不能使用这一绝技 !\n");

        if((int)me->query_skill("dodge") < 100)
                return notify_fail("你的轻功修为不够, 不能使用移风起栖云飞扬！\n");

        if((int)me->query_skill("sword") < 120)
                return notify_fail("你的剑法修为不够， 目前不能使用移风起栖云飞扬! \n");

     if (me->query_temp("perform")>time()) return notify_fail("你上一招未使完！\n");

       // if (! living(target))
               // return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

        msg = HIM "$N嫣然一笑，使出移风剑法的绝技「"BLINK HIW"移风起栖云飞扬"NOR HIM"」，手中" + weapon->name() +HIM"
              化为无数花瓣飞舞！$n呆呆地看着无数剑气刺向自己……\n"NOR;

    message_vision(msg, me, ob);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -50);
    me->set_temp("perform",time()+3);
    me->set_temp("perform_yifeng",1);
    /*
     for(i = 0; i < 6; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg",HIR"花瓣从中剑光舞\n"NOR);
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
            */
    
    for(i = 0; i < 6; i++){
    	me->set_temp("action_msg",HIR"花瓣从中剑光舞\n"NOR);
    	 if (!weapon->query("equipped")) break;
    	 COMBAT_D->do_attack(me, ob,weapon, 0);
    	             
    }
          
    me->delete_temp("perform_yifeng");
    me->delete_temp("secondly_weapon");
    return 1;
}



/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
