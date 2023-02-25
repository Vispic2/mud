//suxin.c「太上忘情」

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <condition.h>

inherit F_DBASE;
inherit F_SSERVER;
string query_name() { return "太上"ZJBR"忘情"; }
string *pfm_type() { return ({ "sword", }); }


int perform(object me, object target)
{
/*      mapping prepare_status;	//配合下面的写法进行更改
        string weapon, op_weapon, op_skill, *pname, msg;
        int my_power, op_power;
		int damage;*/	
        string weapon, op_weapon, op_skill, msg;
        int my_power, op_power;
		int damage,damage1;
	if (userp(me) && ! me->query("can_perform/taisu-jiandian/wangqing"))
                return notify_fail("你未受高人指点还不会使用这招\n");	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「太上忘情」只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword")
		return notify_fail("你没用剑，不能使用「太上忘情」！\n");
	if (target && target->query_temp("apply/shade_vision")) 
		return notify_fail("对方隐身了，你看不到"+target->query("name")+"。\n"); 		
	if( me->query_skill("taisu-force", 1) < 500 )
		return notify_fail("你的太素心经火候未到，无法施展太上忘情！\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");

if (me->query_skill_mapped("sword") != "taisu-jiandian")
                return notify_fail("你没有激发太素剑典，不能使用「红尘十丈」。\n");		if( me->query_skill("taisu-dodge",1) < 500 )
		return notify_fail("你的太素玲珑步修为不足，还不能使用太上忘情！\n");
if( me->query_skill("taisu-force",1) < 500 )
		return notify_fail("你的太素心经修为不足，还不能使用太上忘情！\n");
	if( me->query_skill("taisu-jiandian",1) < 500 )
		return notify_fail("你的太素剑典修为不足，还不能使用太上忘情！\n");
	if( me->query_skill_mapped("force") != "taisu-force" )
		return notify_fail("你所用的并非太素心经，使不了「太上忘情」！\n");
	if ((int)me->query_skill("martial-cognize") < 300)
                return notify_fail("你的武学修养境界不够，难以施展「太上忘情」。\n");if (!(int)me->query("breakup"))
        return notify_fail("你任督二脉未通,无法使用[" HIR "太上忘情" NOR "]\n"); 
	if( me->query("max_neili") < 10000 )
		return notify_fail("你的内力修为不够使用「太上忘情」！\n");
	if( me->query("neili") < 1000 )
		return notify_fail("你的内力不够使用「太上忘情」！\n");
	if( me->query("jingli") < 1000 )
		return notify_fail("你的精力不够使用「太上忘情」！\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");

/*	//2017.4.20阿飞改，这段代码有点问题，先换个简单的写法
        if ( !objectp(op_weapon = target->query_temp("weapon")) ) 
		{
            if ( mapp(prepare_status = target->query_skill_prepare()) ) 
			{
                pname  = keys(prepare_status);
                op_skill = pname[0];
			}
            else op_skill = "unarmed";
        }
        else 
		{
            op_skill = op_weapon->query("skill_type");
	    }
*/	
        if ( !objectp(op_weapon = target->query_temp("weapon")) ) 
		{
			op_skill = "unarmed";
        }
        else 
		{
            op_skill = op_weapon->query("skill_type");
	    }	
		
	message_vision(HBWHT "$N贯通古墓武学，使出了古墓派的绝学之精髓！\n" NOR, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1
        my_power = me->query_skill("taisu-jian",1) + me->query_skill("taisu-jianfa",1) + me->query_skill("taisu-force",1) + me->query_skill("force") + me->query_skill("taisu-dodge",1) + me->query_skill("sword") + me->query("bodyreset");
        op_power = target->query_skill(op_skill) + target->query_skill("dodge",1) + target->query_skill("parry",1) + target->query("bodyreset");
		damage1 = me->query_skill("taisu-jian",1) + me->query_skill("taisu-jianfa",1) + me->query_skill("taisu-force",1) + me->query_skill("sword",1);
		
        message_vision(HIY "\n$N轻喝一声，粉臂一挥随即"+weapon->name()+HIY"脱手飞出！\n" NOR, me, target);
        message_vision(CYN "\n$N说道：让你见识一下太素剑诀真正的秘密！\n" NOR, me, target);
        message_vision(HIY "\n只见"+weapon->name()+HIY"急速旋转，骤然幻化出无数雪花，原来这太素剑诀终极奥义是风花雪月！\n" NOR, me, target);
        message_vision(HIY"$N这招「太上忘情」确实不传之迷，漫天雪花飞舞，好似梦幻一般绚烂，雪花变幻莫测化，片刻便作万道星光冲向$n！\n" NOR, me, target);

		msg = HBGRN"多情却似总无情！\n" NOR;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		msg += HBRED"情到浓时情转薄！\n" NOR;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		msg += HBYEL"情到深处无怨尤！\n" NOR;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		msg += HBCYN"多情自古伤离别！\n" NOR;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		msg += HBMAG"多情自古空余恨！\n" NOR;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
		msg += HBBLU"多情最是波心月！\n" NOR;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_REGULAR);
	message_vision(msg, me, target);
		damage = damage1 + random(damage1);
		target->receive_wound("qi", damage,me);
		target->receive_damage("qi", damage/2,me);
		me->add("neili", -1000);
		me->add("jingli", -200);
		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);


	if(me->query_skill("taisu-jian") > 2000 && me->query_skill("taisu-jianfa") > 2000)	
	{
		damage1 = me->query_skill("taisu-jian",1) + me->query_skill("taisu-jianfa",1) + me->query_skill("taisu-force",1) + me->query_skill("force") + me->query_skill("taisu-dodge",1) + me->query_skill("sword") + me->query("bodyreset")+target->query_str()/10;
		damage = damage1 + random(damage1);
        if ( random(my_power) > op_power/3 ) 
        { 
                if ( objectp(op_weapon)) 
                {
                        message_vision(HIB"\n$N躲闪不及，只好运劲"+op_weapon->name()+"企图挡开飞来的雪花。\n" NOR, me,target);
                        message_vision(WHT"$N猛然觉得虎口大震，手中的"+op_weapon->name()+WHT"被震掉在地上。\n" NOR, me,target);
						op_weapon->add_amount(-1);
						op_weapon->move(environment(me));
                
					message_vision(HIR "\n$N一声惨嚎，被无数雪花穿身而过！\n" NOR, me,target);
					target->receive_wound("qi", damage,me);
					target->receive_damage("qi", damage/2,me);
					me->add("neili", -1000);
					me->add("jingli", -1000);
					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                }
				
                if ( random(me->query_str()) > (target->query_str())/2 ) 
                {
                    message_vision(HIR "\n$N奋力闪躲，结果被太素剑诀戳了几个血洞。\n" NOR, me,target);
					target->receive_wound("qi", damage,me);
					target->receive_damage("qi", damage/2,me);
					me->add("neili", -1000);
					me->add("jingli", -1000);
					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                }
                else 
                {
					message_vision(HIR "\n$N奋力闪躲，结果被太素剑诀划了几道血痕。\n" NOR, me,target);
					target->receive_wound("qi", damage/3,me);
					target->receive_damage("qi", damage/5,me);
					me->add("neili", -1000);
					me->add("jingli", -200);
					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/3 +"，内伤为"+ damage/5 +"。\n" NOR);

                }
        }
        else 
		{  
                message_vision(HIG "\n$N身形连闪，好不容易将此招避过，已吓得浑身冰冷！\n" NOR, me,target);
				me->add("neili", -500);
        }
	}

	if(me->query_skill("taisu-jian") > 3000 && me->query_skill("taisu-jianfa") > 3000)
	{
        msg = HIY "\n太素剑诀反转轻舞，去势尽时一把巨大的"+weapon->name()+HIY"汇聚而生。\n" NOR;
		message_vision(msg,me,target);
		if (me->query("jm/gumu")) damage1 = me->query_skill("taisu-jian",1)*me->query("int",1)*3/2 + me->query_skill("taisu-jianfa",1)*me->query("dex",1)*3/2 + me->query_skill("taisu-force",1)*me->query("int",1)*3/2 + me->query_skill("force") + me->query_skill("taisu-dodge",1)*me->query("dex",1)*3/2 + me->query_skill("sword") + me->query("bodyreset")+target->query_str()+target->query("jing")/150;
		else damage1 = me->query_skill("taisu-jian",1)*me->query("int",1) + me->query_skill("taisu-jianfa",1)*me->query("dex",1) + me->query_skill("taisu-force",1)*me->query("int",1) + me->query_skill("force") + me->query_skill("taisu-dodge",1)*me->query("dex",1)/2 + me->query_skill("sword") + me->query("bodyreset")+target->query_str()/2+target->query("jing")/200;
		damage = damage1 + random(damage1);
		if ( random(me->query_dex(1)) > random( target->query_dex(1) /3 ) )
        {
			message_vision(HIG"\n$N双足一点，接住了"+weapon->name()+"！\n"NOR,me,target);
			target->receive_wound("qi", damage,me);
			target->receive_damage("qi", damage/2,me);
			me->add("neili", -1000);
			me->add("jingli", -200);
			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        }
        else 
		{ 
			weapon->move(environment(me));
            message_vision("\n“当”的一声，"+weapon->name()+"掉在了地上！\n"NOR,me,target);
			me->add("jingli", -200);
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
		tell_object(me, HIM"你呼出一口气，缓缓的将内力收回丹田。\n"NOR);
	}	
}