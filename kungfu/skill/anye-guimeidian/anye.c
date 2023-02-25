// anye 「暗夜鬼魅」
//任何仙武基本只有一招大招。但写法都很复杂。仙武求精不求杂 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "暗夜"ZJBR"鬼魅"; }
string *order = ( {"关元穴", "檀中穴", "肩井穴", "太阳穴", "气海穴", "百汇穴","腹结穴","涌泉穴","大椎穴"});
int perform(object me, object target)
{
	string msg;
	int extra,ap,dp,damage;
	int i,attack_time;
	object weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target ||	!target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。\n");
	if( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword" )
		return notify_fail("你手中没有装备剑类武器！\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( (int)me->query("max_neili") < 1000  )
		return notify_fail("你的内力修为不够。\n");
	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("max_jingli") < 3000  )
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够。\n");
	if( (int)me->query_skill("martial-cognize", 1) < 300 )
		return notify_fail("你的武学修养!不能贯通使用！\n");
	if((int)me->query_skill("anye-guimeidian", 1) < 500 )
		return notify_fail("你的暗夜鬼魅不够高!不能贯通使用！\n");
		//和九阴九阳以及九阳神功冲突
	if( (int)me->query_skill("jiuyinjiuyang", 1) || (int)me->query_skill("jiuyang-shengong", 1))
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");
	if( me->query_skill_mapped("sword") != "anye-guimeidian" )
		return notify_fail("你没有使用暗夜鬼魅，不能使用「暗夜鬼魅」。\n");
	if (!(int)me->query("breakup"))
        return notify_fail("你任督二脉未通,无法使用「暗夜鬼魅]\n"NOR); 
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");	
	
	msg = HBWHT "$N贯通日月神教武学，使出了日月神教的绝学之精髓！\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法
	call_out("del_cooldown", 5, me);	//CD写法1	
	ap = me->query("bodyreset") + me->query_skill("anye-guimeidian", 1) + me->query_skill("martial-cognize", 1) + me->query_skill("force") + me->query_skill("sword");
	dp = target->query("bodyreset") + target->query_skill("dodge") + target->query_skill("parry");	
	extra = me->query_skill("anye-guimeidian",1) ;
	attack_time = extra/60;
	if (attack_time > 10) attack_time = 10;
	me->add_temp("apply/attack", extra*2);
	me->add_temp("apply/damage", extra*2);
	msg = HBBLU  "$N忽然化身为二，幻出左右两个身影高速滑向$n，手中$w幻化不定，招招紧逼$n的$l!" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HBYEL "$N的人影忽然变成了好几个！一个接一个刺向$n。\n" NOR;
	message_vision(msg, me, target);
	for(i=0; i<attack_time; i++)
	{
		msg = HIW "$n身旁出现人影，向$n的"+HIY+(order[random(7)])+NOR+HIW+"刺了过去！\n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
	}
	i = attack_time;
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*2);
	me->add("neili",-1000);
	
if((int)me->query_skill("anye-guimeidian", 1) > 2000 && (int)me->query_skill("martial-cognize", 1) > 2000)	
{
	msg=HBRED"\n\n只见$N双目一滞，面上闪过一阵异彩，身法突然加快，如影随形，蹂身而上！\n"NOR;
	msg+=HBWHT"随着一声凄厉的长啸，$N手中宝剑绽开朵朵剑花，猛地罩向$n全身各处命门大穴！\n"NOR;
	message_vision(msg, me, target);
	if(random(ap)>dp/3)
	{		
		damage = me->query_skill("anye-guimeidian",1)*5+me->query_skill("sword-cognize",1)*5+me->query_skill("martial-cognize",1)*5+me->query_skill("sword",1)+me->query_skill("dodge")+me->query_skill("force");	
		damage=damage+random(damage);
		if(damage<1000)    damage=1000;
		msg =MAG"$n惊叫一声，"+HBYEL+(order[random(7)])+NOR+MAG+"部位血花飞溅,\n"NOR;
		switch(random(2))
		{
		case 1:
		{
			msg+=RED"$n“哇”地一口鲜血从口中喷出！\n"NOR;
			break;
		}
		default:
			msg+=CYN"$n身形一震, 一股鲜血从口中喷出,直喷向$N,但见$N头一歪,轻松的躲了过去！！\n"NOR;
		}
		message_vision(msg, me, target);
		switch(random(2))
		{
		case 1:
		{	
			target->add("neili",-damage);
			target->receive_wound("qi",damage,me);
			target->receive_damage("qi",damage,me);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HBGRN"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage +"，杀内力"+ damage +"。\n" NOR);
			break;
		}
		default:
		{
			target->add("jingli",-damage);
			target->receive_wound("jing",damage,me);
			target->receive_damage("jing",damage,me);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HBGRN"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage +"，杀内力"+ damage +"。\n" NOR);
		}
		}
		me->add("neili",-1000);
		me->add("jingli",-1000);
	}
	else
	{
		msg=CYN"$p冷笑一声，身形虚晃几下闪了开去！\n"NOR;
		message_vision(msg, me, target);
	}
}
if((int)me->query_skill("anye-guimeidian", 1) > 3000 && (int)me->query_skill("martial-cognize", 1) > 3000)	
{
	message_vision(RED"\n$N猛地纵起，向$n扑去，手指一弹，细针飞了出去，插向$n右目。\n\n"NOR, me, target);
	if(random(ap) > dp/3)
	{
		message_vision(HIR"\n$n猝不及防，大叫一声，右眼中针！\n"NOR, me, target);
		tell_object(target, HIY "你感觉细针正插在自己的瞳仁之中，如果这针直贯入脑，便有性命之忧！\n" NOR);
		me->add("neili", -300);
		if (me->query("jm/riyue")) damage = me->query_skill("anye-guimeidian",1)*me->query("int",1)*3/2 + me->query_skill("sword-cognize",1)*me->query("int",1)*3/2 + me->query_skill("martial-cognize",1)*me->query("dex",1)*3/2 + me->query_skill("kuihua-feiying",1)*me->query("dex",1)*3/2 + me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force") + me->query_dex();
		else damage = me->query_skill("anye-guimeidian",1)*me->query("int",1) + me->query_skill("sword-cognize",1)*me->query("int",1) + me->query_skill("parry",1)*me->query("dex",1) + me->query_skill("kuihua-feiying",1)*me->query("dex",1) + me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force") + me->query_dex()/2;
		damage=damage+random(damage);
		target->add("neili",-damage*2);
		target->add("jingli",-damage*2);
		target->receive_damage("jing", damage/3,me);
		target->receive_damage("qi", damage/3,me);
		target->receive_wound("jing", damage,me);
		target->receive_wound("qi", damage,me);
		me->add("neili",-1000);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HBRED"该绝招对敌人气血的外伤为"+ damage/3 +"，内伤为"+ damage +"，精神的外伤为"+ damage/3 +"，内伤为"+ damage +"，杀内力"+ damage*2 +"，杀精力"+ damage*2 +"。\n" NOR);
	}
	else
	{
		message_vision(HIY"\n可是$n看破了$N的企图，飞身闪了开去。\n"NOR, me, target);
	}
}
	me->start_busy(1);
	return 1;
}

void del_cooldown(object me)	//CD写法1
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("cooldown") )	
	{
		me->delete_temp("cooldown");
		tell_object(me, HBRED"你呼出一口气，缓缓的将内力收回丹田。\n"NOR);
	}	
}