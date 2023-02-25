// liu.c
// 流花掠影 liu

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "流花"ZJBR"掠影"; }
int perform(object me, object target)
{
        int skill;
	string msg;
	int ap, dp;
	int count;
	int i;
        object weapon;


		if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

        if (userp(me) && ! me->query("can_perform/wuzhan-mei/liu")) 
                return notify_fail("你还没有受过高人指点，无法施展「流花掠影」。\n"); 
                
        if((skill = me->query_skill("wuzhan-mei",1)) < 100)
                return notify_fail("你的五展梅剑法不够纯熟，无法使用『流花掠影』。\n");

        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("『流花掠影』只能对战斗中的对手使用。\n");

        if(me->query("neili") < 400 )
                return notify_fail("你目前的内力不足，无法施展『流花掠影』。\n");

        if(!(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "wuzhan-mei")
                return notify_fail("你必须在使用剑时才能使出『流花掠影』。\n");


		msg = HIY "$N" HIY "手中乱抖，幻出一片青光，施展出唐门绝学『流花掠影』。"NOR"\n";
		ap = me->query_skill("sword");
		dp = target->query_skill("parry");

		if (ap / 2 + random(ap * 2) > dp)
		{
			msg += HIC "结果$p" HIC "被$P" HIC
			       "攻了个措手不及，连连后退不暇！"NOR"\n";
			count = ap / 2;
			me->add_temp("apply/attack", count);

		} else
		{
			msg += HIC "$n" HIC "见$N" HIC "这几剑并无破绽，不敢大意，小心应付。"NOR"\n";
			count = 0;
		}
		
		message_combatd(msg, me, target);
		me->add("neili", -200);

		for (i = 0; i < 4; i++)
		{
			if (! me->is_fighting(target))
				break;
			COMBAT_D->do_attack(me, target, weapon, 0);
		}

		me->add_temp("apply/attack", -count);
		me->start_busy(1 + random(3));

		return 1;
/*
        for(int i=0;i<4;i++)
        {
                // COMBAT_D->do_attack(me,target,TYPE_QUICK);
                COMBAT_D->do_damage(me,target, WEAPON_ATTACK, damage, 50);
        }
        
        if(random(target->query("force")) < me->query("force")/2)
        {
                target->apply_condition("weapon_bleeding", 5+random(3));
        }
        

        me->start_busy(3);
        return 1;*/
}


/*
BY：NAME
QQ：3468713544
DATE：2 0 2 2 . 0 2 . 0 3
*/
