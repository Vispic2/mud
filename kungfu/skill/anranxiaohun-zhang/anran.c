#include <ansi.h>

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string *pictures = ({"心惊肉跳","杞人忧天","无中生有","拖泥带水","徘徊空谷","力不从心","行尸走肉", "庸人自扰" });
string query_name() { return "黯然"; }
void remove_effect(object me, int amount);

int perform(object me, object target)
{
      string picture;
        int skill;
      int i, j, z;
     i = me->query_skill("anranxiaohun-zhang", 1)/5;
     j = me->query_skill("yunv-xinfa", 1)/3;
     z = me->query_skill("anranxiaohun-zhang",1)/2;
     picture = pictures[random(sizeof(pictures))];
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("黯然只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使掌才能使用！\n");

        if( (int)me->query("max_neili") < 1500 )
		return notify_fail("你内力不雄厚不能使用黯然。\n");

        if( (int)me->query_temp("liuyun") )
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");
    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("你要把玉女心法做为内功才能用。\n");

        if( (int)me->query_temp("qzj_tong") )
                return notify_fail("你已经在运同归剑了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

        if((int)me->query_temp("tzzf") )
                return notify_fail("你已经在掌刀的运功中。\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n");
       if(me->query_temp("zhuihun/lpf"))
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n");

       if(me->query_temp("anran"))
// updated 消魂->黯然 (by xbd)
       return notify_fail("你现在正在使用「黯然」绝技。\n");

        if( (int)me->query("jing")  < 200 )
		return notify_fail("你的精不够。\n");

        if( (int)me->query("neili")  < 600 )
		return notify_fail("你现在没有足够的内力使用。\n");

        if( (int)me->query_skill("anranxiaohun-zhang", 1) < 150 )
		return notify_fail("你的火侯还没到，无法领悟出黯然伤敌。\n");

       if (me->query("eff_qi")+1000 >=me->query("max_qi"))
        return notify_fail("以你现在的心境难以使用发挥出黯然绝技。\n");

       if(me->query_skill("yunv-xinfa", 1) < 200 )
// updated 消魂->黯然 (by xbd)
                return notify_fail("你的玉女心经修为不够，无法使用「黯然」绝技。\n");


        if (me->query("neili") < 800)
        return notify_fail("你的内力不够。\n");
        if (me->query("jing") < 800)
        return notify_fail("你的精力不够。\n");

        skill = me->query_skill("anranxiaohun-zhang") / 2;
        me->add("neili", -(me->query_skill("unarmed")+100));
        me->add("jing", -300);
        message_vision(YEL "$N使出黯然消魂，威力大增，势不可当！源源不绝的掌力排山倒海般地压向$n！\n" NOR, me, target);
        message_vision(HIY"$N心想今日身陷绝境已然无幸,不由万念俱灰,一股凄然之意自心而升.没精打采的挥袖卷出，拍出一掌"+picture+",
但见掌风激荡,恍恍惚惚，隐隐约约！刹时黯然销魂掌威力顿增,势不可挡.\n"NOR,me,target);
        me->add_temp("apply/str", i);
        me->add_temp("apply/attack", j);
        me->set_temp("anran", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
      int i, j, z;
     i = me->query_skill("anranxiaohun-zhang", 1)/5;
     j = me->query_skill("yunv-xinfa", 1)/3;
     z = me->query_skill("anranxiaohun-zhang",1)/2;
    me->add_temp("apply/str", -i);
    me->add_temp("apply/attack", -j);
        me->delete_temp("anran");
// updated 消魂->黯然 (by xbd)
    tell_object(me, HIR"你「黯然」绝技运行完毕，气回丹田.\n" NOR);
        message_vision(YEL "\n$N的掌风威力也恢复寻常了。\n" NOR, me);

}
