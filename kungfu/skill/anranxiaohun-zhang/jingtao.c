// Code by JHSH

#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
       string query_name() { return "怒海"ZJBR"惊涛"; }
int perform(object me, object target)
{
        object weapon;
        int myexp, targexp, damage, skill, merand, targrand, targneili,time,i;
        string str,*limb,type;
        mapping myfam;
        int tmp_jiali,dmg;
        int num,ap,dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「怒海惊涛」只能对战斗中的对手使用。\n");



//        if( objectp(me->query_temp("weapon")) )
//                return notify_fail("空手才能施展「怒海惊涛」！\n");

    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("你要把玉女心法做为内功才能用。\n");


        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("你的玉女剑法火候太浅。\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("你的玉女身法火候太浅。\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("你的天罗地网火候太浅。\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("你的美女拳火候太浅。\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("你的五展梅火候太浅。\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("你的银索金铃火候太浅。\n");
        if( me->query_skill("anranxiaohun-zhang",1) < 150 )
                return notify_fail("你黯然销魂掌修为太差，不能运用「怒海惊涛」！\n");



        if ( !living(target))
               return notify_fail("现在不没必要用「怒海惊涛」吧！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用「怒海惊涛」！\n");

        ap = me->query_skill("force") + me->query_skill("unarmed") + me->query("jiali");
	dp = target->query_skill("force") + target->query_skill("parry");

        skill=me->query_skill("anranxiaohun-zhang",1);

        message_vision(HIW"\n$N的掌风隐隐带着潮涌之声，掌风鼓荡，竟似有狂潮涌来，这正是神雕大侠当年在海边练出的绝技。 \n\n"NOR,me,target);

	if (ap/2 + random(ap) > dp)
	{
		message_vision(HIR"$n哪里躲避得开，大惊下已经给$N的掌风印上胸口，一口鲜血狂喷而出！\n\n",me,target);
		target->receive_damage("qi",ap/2);
		target->receive_wound("qi",random(ap/2)+200);
                            if (! target->is_busy())
			target->start_busy(3);
	} else
	{
		message_vision(HIY"$n见状不妙，立刻就地一个打滚，虽然姿势难看以及，不过总算避开了$N这一掌。\n\n"NOR,me,target);
	}

        message_vision(HIW"\n$N在掌风达到顶峰之时，跟着“魂不守舍”、“倒行逆施”、“若有所失”，连出三招。\n\n"NOR,me,target);

	if (ap/2 + random(ap/2) > dp)
	{
		message_vision(HIR"$n惊魂未定，正喘气之际，不提防又一阵猛烈的气浪扑面冲来，复遭$N掌风重创！\n\n",me,target);
		target->receive_damage("qi",ap);
		target->receive_wound("qi",random(ap)+200);
                            if (! target->is_busy())
			target->start_busy(3);
	} else
	{
		message_vision(HIY"$n顾不得反击，急身后退三丈，脸颊给$N的掌风扫到，微微发红，不过总算避开了$N这三掌。\n\n"NOR,me,target);
	}

        message_vision(HIW"跟着$N腾身而起，一招“行尸走肉”，闪电般踢出一脚。\n\n"NOR,me);

	if (ap/3 + random(ap/3) > dp)
	{
		message_vision(HIR"$n眼看着这霸气冲天的一脚，已然放弃了抵抗，整个脸部给$N重重踹上，牙齿皆碎，面目血色狰狞！\n\n",me,target);
		target->receive_damage("qi",ap*2);
		target->receive_wound("qi",random(ap*2)+200);
                            if (! target->is_busy())
			target->start_busy(3);
	} else
	{
		message_vision(HIY"$n双足点地，拔天而起，从$N的头顶掠过，脚下劲气呼啸而过，真是险之又险！\n\n"NOR,me,target);
	}

        me->add("neili",-ap/2);
	me->start_busy(3);

        return 1;
}
